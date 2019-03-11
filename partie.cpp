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

#include "partie.h"
#include "joueur.h"
#include "constantesGlobales.h"

using namespace std;

Partie::Partie() {
    //On crée & initialise la pioche
	for(unsigned i = 1; i <= NOMBRE_FAMILLES; ++i ) {
		for(int j = 'A'; j <= CARTES_PAR_FAMILLES; ++j ){
			pioche.push_back(Carte(i, j));
		}
	}
}

void Partie::tour() {
	for(unsigned i = 0; i < NOMBRE_JOUEURS; ++i) {
		do{
			joueurs[i].demanderCarte();
		}
		while(joueurs[i].demanderCarte());

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
}
void Partie::afficherCartesJoueurs() const {
    for(Joueur joueur : joueurs){
        cout << joueur.getNom() << " : ";
        joueur.afficherMain();
        cout << " [";
        joueur.afficherFamillesSurTable();
        cout << "]";
    }
}

void Partie::distribuerCartes(){
    // on rajoute un élément à la fin du vecteur pour que "shuffle"
    pioche.push_back(Carte(0,'F'));
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    // on mélange les cartes
    shuffle (pioche.begin(), pioche.end(), default_random_engine(seed));
    //on enléve le dérnier élément
    pioche.pop_back();
    for(size_t i = 0; i < CARTES_PAR_JOUEURS*NOMBRE_JOUEURS; i++) {
        joueurs.at(i%NOMBRE_JOUEURS).cartesEnMain.push_back(pioche.at(i));
    }

}
