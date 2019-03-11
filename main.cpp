/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : main.cpp
 Auteur(s)   : Maurice Lehmann,Ahmed Farouk Ferchichi, Florian Schaufelberger
 Date        : 01.03.2019

 But         : TODO

 Compilateur : MinGW-g++
 -----------------------------------------------------------------------------------
*/

#include <cstdlib>
#include "joueur.h"
#include "carte.h"
#include "partie.h"

using namespace std;

int main(){

    //Constantes global
    //nombreDeMembre = 4
    //nombreDeFamille = 10

    //Initialiser class Partie : avec n joueurs
    //Partie Partie1( [joueur1,joueur2,joueur3], nombreDeFamille, nombreDeMembre)

	Partie p1 = Partie();
/*
	int counter = 1;
	cout << "Début de la partie de 7 familles" << endl;
	do {
		cout << " *** Tour "<< counter <<" ***" << endl;
		for(int i = 0; i < NOMBRE_JOUEURS ; ++i) {
			cout << p1.getJoueurs()[i].getNom() << " : ";
			p1.getJoueurs()[i].afficherMain();
		}

		p1.afficherPioche();

	}while(p1.tour());
*/
    return EXIT_SUCCESS;
}
