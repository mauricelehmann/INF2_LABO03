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



#include "partie.h"
#include "joueur.h"
#include "constantesGlobales.h"
#include <iostream>

using namespace std;
Partie::Partie() {
	for(int i = 1; i <= NOMBRE_FAMILLES; ++i ) {
		for(int j = 'A'; j <= CARTES_PAR_FAMILLES; ++j ){
			pioche.push_back(Carte(i, j));
		}
	}
}

void Partie::tour() {
	for(int i = 0; i < NOMBRE_JOUEURS; ++i) {
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
    std::cout << "Pioche: ";
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