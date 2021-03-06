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
    size_t nbPartie = 1;


    //Run sur 100 parties :
    for (int i = 0; i < nbPartie ; i++) {

        srand(time(0));
        unsigned nbTours = 1;

        cout << "Debut de la partie de 7 familles" << endl;
        p1.initialiserPartie();
    	while(!p1.detecterFinDePartie()) {
                cout << "***Tour " << nbTours << "***" << endl;
                p1.tour();
                nbTours++;
                //On controle que la partie ne doive pas s'arrêter
                //càd si encore des joueurs on des cartes et si la pioche n'est pas vide
	    }
        p1.calculerPointsJoueurs();
        p1.afficherCartesJoueurs();
        cout << "\nLa partie est finie!" << "\nNombre de tours: " << nbTours << endl;
    }

    p1.afficherPointsJoueurs(nbPartie);

    return EXIT_SUCCESS;
}
