/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : joueur.h
 Auteur(s)   : Maurice Lehmann,Farouk Ferchichi,Florian, Florian Schaufelberger
 Date        : 01.03.2019

 But         : TODO

 Compilateur : MinGW-g++
 -----------------------------------------------------------------------------------
*/
#ifndef JOUEUR
#define JOUEUR
#include <vector>
#include "carte.h"

class Joueur{
public:
   //Constructeur //TODO
   Joueur(){}
   std::vector<Carte> famillesSurTable;
private:
   std::vector<Carte> cartesEnMain;
};
#endif //JOUEUR
