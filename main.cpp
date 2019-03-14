/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : main.cpp
 Auteur(s)   : Maurice Lehmann,Ahmed Farouk Ferchichi, Florian Schaufelberger
 Date        : 01.03.2019

 But         : Crée une instance de la classe Partie et effectue plusieurs partie
               avec la même équipe de joueurs

 Compilateur : MinGW-g++
 -----------------------------------------------------------------------------------
*/

#include <cstdlib>
#include "joueur.h"
#include "carte.h"
#include "partie.h"

using namespace std;

int main(){


	Partie p1 = Partie();
	unsigned counter = 1;
	cout << "Début de la partie de 7 familles" << endl;

	p1.initialiserPartie();
/*
	for(int i = 0; i < 20; ++i) {
		cout << "***Tour " << counter << "***" << endl;
		p1.tour();
		counter++;
	}
*/
	while(p1.tour()) {
		cout << "***Tour " << counter << "***" << endl;
		counter++;
	}
	p1.afficherCartesJoueurs();

    return EXIT_SUCCESS;
}
