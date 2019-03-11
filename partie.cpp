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


using namespace std;
Partie::Partie() {
	for(int i = 1; i <= NOMBRE_FAMILLES; ++i ) {
		for(int j = 'A'; j <= CARTES_PAR_FAMILLES; ++j ){
			pioche.push_back(Carte(i, j));
		}
	}
}

void Partie::tour() {
	srand(time(NULL));
	int j;
	bool found;
	for(int i = 0; i < NOMBRE_JOUEURS; ++i) {
		while(j == i) {
			j = rand() % NOMBRE_JOUEURS - 1;
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

bool Partie::demanderCarte(Joueur j1, Joueur j2){
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

  int randomCarte = rand() % carteADemander.size();

  for(int i = 0; i < cartesEnMainJ2.size(); ++i) {
  	if(cartesEnMainJ2[i] == carteADemander[randomCarte]) {
  		j2.donnerCarte(i);
  		j1.recevoirCarte(carteADemander[randomCarte]);
  		return true;
  	}
  }
  return false;
}
