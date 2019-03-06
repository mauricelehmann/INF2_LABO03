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
#include "constantesGlobales.h"
#include "carte.h"

class Joueur{
public:
   //Constructeur
   Joueur(const std::string& nom);
   void piocher(std::vector<Carte>& pioche);
   void demanderCarte();
   void detecterFamille();
   void ajouterCarte(const Carte& carte);
   void afficherMain() const;
   void afficherFamillesSurTable() const;
private:
   std::string nom;
   std::vector<Carte> cartesEnMain;
   std::vector<Carte> famillesSurTable;
   unsigned int points;
};
#endif //JOUEUR
