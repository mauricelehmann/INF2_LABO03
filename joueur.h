/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : joueur.h
 Auteur(s)   : Maurice Lehmann,Ahmed Farouk Ferchichi, Florian Schaufelberger
 Date        : 01.03.2019

 But         : TODO

 Compilateur : MinGW-g++
 -----------------------------------------------------------------------------------
*/
#ifndef JOUEUR
#define JOUEUR
#include <vector>
#include <string>
#include "carte.h"

class Joueur{
public:
   //Constructeur //TODO
   Joueur();
   void piocher();
   void demanderCarte();
   void detecterFamille();
private:
   std::string nom;
   std::vector<Carte> cartesEnMain;
   std::vector<Carte> famillesSurTable;
   unsigned int points;
};
#endif //JOUEUR
