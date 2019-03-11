/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : partie.cpp
 Auteur(s)   : Maurice Lehmann,Ahmed Farouk Ferchichi,Florian, Florian Schaufelberger
 Date        : 01.03.2019

 But         : TODO

 Compilateur : MinGW-g++
 -----------------------------------------------------------------------------------
*/
#include <iostream>
#include <cstdlib>
#include "partie.h"
#include "joueur.h"
#include "constantesGlobales.h"

using namespace std;

Partie::Partie() {
    //On crée les 4 joueurs
    for(unsigned j = 0 ; j < NOMBRE_JOUEURS ; j++){
        joueurs.push_back(Joueur(NOMS_JOUEURS[j]));
    }
}
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

void Partie::afficherDebutTour() {
	for(unsigned i = 0; i  < NOMBRE_JOUEURS; ++i) {
		cout << joueurs[i].getNom() << " : ";
		joueurs[i].afficherMain();
		cout << endl;
	}
	afficherPioche();
	cout << endl;
}

void Partie::tour() {

	srand(time(nullptr));
	int test = NOMBRE_JOUEURS - 1;
	int j = rand() % test;
	bool found;
	vector<Joueur> joueurDisponible;
	afficherDebutTour();

	for(int i = 0; i < NOMBRE_JOUEURS; ++i) {
		if(joueurs[i].getCartesEnMain().size() != 0) {
			joueurDisponible.push_back(joueurs[i]);
		}

		while(j == i) {
			j = rand() % test;
		}

		do{
			found = demanderCarte(joueurs[i], joueurs[j]);

		}
		while(found);

		if(pioche.size() != 0) {
			joueurs[i].piocher(pioche);
		}

		joueurs[i].detecterFamille();
	}
}

void Partie::afficherPioche() const {
    cout << "Pioche: ";
    for(Carte carte : pioche ){
        carte.afficherCarte();
    }
    cout << endl;
}

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

bool Partie::demanderCarte(Joueur& j1, Joueur& j2){

  srand (time(NULL));

  vector<unsigned short> familleEnMain;
  vector<Carte> cartesEnMainJ1 = j1.getCartesEnMain();
  vector<Carte> cartesEnMainJ2 = j2.getCartesEnMain();
  vector<Carte> carteADemander;

  for(Carte carte : cartesEnMainJ1) {
    for(char i = 'A'; i <= CARTES_PAR_FAMILLES; ++i) {
      Carte carteTemp(carte.getFamille(), i);

      if(find(cartesEnMainJ1.begin(), cartesEnMainJ1.end(), carteTemp) == cartesEnMainJ1.end())
        carteADemander.push_back(carteTemp);
    }
  }

  size_t randomCarte = rand() % carteADemander.size() - 1;

  cout << j1.getNom() << " demande à " << j2.getNom() << " la carte ";
  carteADemander[randomCarte].afficherCarte();
  cout << endl;

  for(size_t i = 0; i < cartesEnMainJ2.size(); ++i) {
  	if(cartesEnMainJ2[i] == carteADemander[randomCarte]) {
  		j2.donnerCarte(i);
  		j1.recevoirCarte(carteADemander[randomCarte]);
  		cout << "et " << j2.getNom() << " donne la carte à " << j1.getNom() << endl;
  		return true;
  	}
  }

  cout << "mais " << j2.getNom() << " ne l'a pas" << endl;
  return false;
}

void Partie::distribuerCartes(){
    // on rajoute un élément à la fin du vecteur pour que "shuffle"
    //pioche.push_back(Carte(0,'X'));
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    // on mélange les cartes
    shuffle (pioche.begin(), pioche.end(), default_random_engine(seed));
    //on enléve le dernier élément
    //pioche.pop_back();
    for(size_t i = 0; i < CARTES_PAR_JOUEURS*NOMBRE_JOUEURS; i++) {
        joueurs.at(i%NOMBRE_JOUEURS).cartesEnMain.push_back(pioche.at(i));
    }
}

bool Partie::detecterFinDePartie() {
	size_t cartesEnMain;

	for(Joueur joueur : joueurs) {
		cartesEnMain += joueur.getCartesEnMain().size();
	}

	if(cartesEnMain == 0 && pioche.size() == 0){
		return true;
	}
	return false;
}


vector<Joueur> Partie::getJoueurs() {
	return joueurs;
}
