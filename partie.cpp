/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : partie.cpp
 Auteur(s)   : Maurice Lehmann,Ahmed Farouk Ferchichi,Florian, Florian Schaufelberger
 Date        : 01.03.2019

 But         : Définition des méthodes de la classe Partie

 Compilateur : MinGW-g++
 -----------------------------------------------------------------------------------
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "partie.h"
#include "joueur.h"
#include "constantesGlobales.h"

using namespace std;

/**
 * Constructeur de la classe Partie
 */
Partie::Partie() {
	initPioche();
    //On crée les 4 joueurs
    for(unsigned j = 0 ; j < NOMBRE_JOUEURS ; j++){
        joueurs.push_back(Joueur(NOMS_JOUEURS[j]));
    }
}
/**
 * Initialise la partie :
 * - vide la main des joueurs,
 * - vide les cartes sur table
 * - rempli la pioche et la mélange
 */
void Partie::initialiserPartie(){
    //On enleve les cartes des mains des joueurs
    for(Joueur& j : joueurs ){
        j.cartesEnMain.clear();
	    //On enleve les cartes sur la table
        j.famillesSurTable.clear();
    }
    //On crée & initialise la pioche
    initPioche();

    distribuerCartes();
}
/**
 * Initialise la pioche : la rempli et la mélange
 */
void Partie::initPioche(){
    if(!pioche.empty()){
        pioche.clear();
    }
    for(unsigned i = 1; i <= NOMBRE_FAMILLES; ++i ) {
		for(unsigned short j = 'A'; j <= CARTES_PAR_FAMILLES; ++j ){
			pioche.push_back(Carte(i, j));
		}
	}
}
/**
 * Affiche le début d'un tour
 */
void Partie::afficherDebutTour() {
	for(unsigned i = 0; i  < NOMBRE_JOUEURS; ++i) {
		cout << joueurs[i].getNom() << " : ";
		joueurs[i].afficherMain();
		cout << endl;
	}
	afficherPioche();
	cout << endl;
}
/**
 * Effectue toutes les actions entre joueurs pendant un tour
 * @return false si aucun joueurs ne peut jouer et que la pioche est vide
 */
bool Partie::tour() {

    srand(time(NULL));
	size_t joueurAdverse = 0;
	bool carteTrouvee;

	afficherCartesJoueurs();
	afficherPioche();

	for(int joueur = 0; joueur < NOMBRE_JOUEURS; joueur++) {
        //On controle que la partie ne doive pas s'arrêter
        //càd si encore des joueurs on des cartes et si la pioche n'est pas vide
        if(detecterFinDePartie()){
            return false;
        }
        //On cherche un joueur adverse
        //Il doit avoir des cartes en main et ne pas être le joueur lui-même
        do{
            joueurAdverse = (rand() % NOMBRE_JOUEURS);
        }while(joueurs[joueurAdverse].getCartesEnMain().size() == 0 && joueur == joueurAdverse );
        //Le joueur demande une carte au joueur adverse
        //Si il peut lui donner la carte, on recommence le processus
        //Sinon, le joueur pioche
        do{
            if(joueurs[joueur].getCartesEnMain().size() != 0 && joueurs[joueurAdverse].getCartesEnMain().size() != 0) {
                carteTrouvee = demanderCarte(joueurs[joueur], joueurs[joueurAdverse]);
                joueurs[joueur].detecterFamille();
              } else {
                carteTrouvee = false;
              }
        }while(carteTrouvee);
        //On contrôle que la pioche ne sois pas vide, sinon le joueur ne pioche pas
        if(pioche.size() != 0) {
          joueurs[joueur].piocher(pioche);
        }
    }
}
/**
 * Affiche le contenu de la pioche
 */
void Partie::afficherPioche() const {
    cout << "Pioche: ";
    for(Carte carte : pioche ){
        carte.afficherCarte();
        cout << " ";
    }
    cout << endl;
}
/**
 * Affiche la main et les familles sur table des joueurs
 */
void Partie::afficherCartesJoueurs() const {
    for(Joueur joueur : joueurs){
        cout << joueur.getNom() << " : ";
        joueur.afficherMain();
        cout << " [";
        joueur.afficherFamillesSurTable();
        cout << "]";
        cout << endl;
    }
}
/**
 * Detecte la fin d'une partie : si la pioche est vide et que les joueurs ne peuvent plus jouer
 * @return True si fin de partie, sinon false
 */
bool Partie::detecterFinDePartie() {
    size_t jouerSansCartes = 0;
    for(int joueur = 0; joueur < NOMBRE_JOUEURS; joueur++) {
        if(joueurs[joueur].getCartesEnMain().size() == 0){
            jouerSansCartes++;
        }
    }
    if(jouerSansCartes == NOMBRE_JOUEURS && pioche.size() == 0) {
        return true;
    }
    return false;
}
/**
 * Demande une carte pour un joueur 1 à un joueur 2
 * @param  j1 Joueur demandant la carte
 * @param  j2 Joueur donnant la carte
 * @return True si j2 peut donner la carte, sinon false
 */
bool Partie::demanderCarte(Joueur& j1, Joueur& j2){

    vector<unsigned short> familleEnMain;
    vector<Carte> cartesEnMainJ1 = j1.getCartesEnMain();
    vector<Carte> cartesEnMainJ2 = j2.getCartesEnMain();
    vector<Carte> carteADemander;

    //On regarde cartes il est possible de demander
    for(Carte carte : cartesEnMainJ1) {
        for(char i = 'A'; i <= CARTES_PAR_FAMILLES; ++i) {
            Carte carteTemp(carte.getFamille(), i);
            if(find(cartesEnMainJ1.begin(), cartesEnMainJ1.end(), carteTemp) == cartesEnMainJ1.end())
                carteADemander.push_back(carteTemp);
        }
    }

    //On en choisi une au hasard
    size_t randomCarte = (rand() % carteADemander.size());

    //On affiche la transaction
    cout << j1.getNom() << " demande à " << j2.getNom() << " la carte ";
    carteADemander[randomCarte].afficherCarte();
    cout << endl;

    //Le joueur demande une nouvelle carte tant que le joueur adverse peut le faire
    for(size_t i = 0; i < cartesEnMainJ2.size(); ++i) {
    	if(cartesEnMainJ2[i] == carteADemander[randomCarte]) {
    		j1.ajouterCarte(carteADemander[randomCarte]);
    		j2.donnerCarte(i);
    		cout << "et " << j2.getNom() << " donne la carte à " << j1.getNom() << endl;
    		return true;
    	}
    }

    cout << "mais " << j2.getNom() << " ne l'a pas" << endl;
    return false;
}
/**
 * Distribue les cartes aux joueurs
 * Les cartes viennent du dessus de la pioche mélangée
 */
void Partie::distribuerCartes(){

    //on melange la pioche
    random_shuffle(pioche.begin(), pioche.end());

    //test si il y a assez de carte par rapports aux nombre de joueurs et de carte par main
    if(CARTES_PAR_JOUEURS*NOMBRE_JOUEURS > NOMBRE_FAMILLES * CARTES_PAR_FAMILLES) {
    	cout << "Trop de joueurs et de carte par joueurs par rapport aux carte" << endl;
    	return;
    }

    //On distribue les cartes
    for(size_t i = 0; i < CARTES_PAR_JOUEURS*NOMBRE_JOUEURS; i++) {
        joueurs.at(i%NOMBRE_JOUEURS).cartesEnMain.push_back(pioche.back());
    	pioche.pop_back();
    }
}
/**
 * Retourne le vecteur<Joueur> des joueurs de la partie
 * @return vecteur<Joueur>
 */
vector<Joueur> Partie::getJoueurs() {
	return joueurs;
}
