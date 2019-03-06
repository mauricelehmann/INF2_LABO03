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

   /////////////////Test de MAURICE ////////////////////////
   int nbFamille = 7;
   char nbMembre = 'D';
   vector<Carte> pioche ;
   //On crée la pioche
   for(size_t famille = 1 ; famille <= nbFamille ; famille++){
      for(char membre = 'A' ; membre <= nbMembre ; membre++){
         pioche.push_back(Carte(famille,membre));
      }
   }
   
   cout << endl;
   Joueur j1("Maurice");
   j1.piocher(pioche);   
   j1.piocher(pioche);
   j1.piocher(pioche);
   j1.piocher(pioche);
   j1.piocher(pioche);
   j1.piocher(pioche);
   
   j1.afficherMain();
   cout << endl;
   //////////////END TEST DE MAURICE //////////////////////
    return EXIT_SUCCESS;
}
