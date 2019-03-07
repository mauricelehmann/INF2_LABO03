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
   /**
    * Constructeur de class Joueur
    * @param nom nom du joueur
    */
   Joueur(const std::string& nom);
   /**
    * Ajoute une carte dans la main du joueur, venant de la pioche
    * @param pioche vecteur de carte
    */
   void piocher(std::vector<Carte>& pioche);
   /**
    * Demande une carte à un autre joueur
    */
   void demanderCarte();
   /**
    * Detecte si le joueur à une famille complète dans la main
    * Si oui, on transfère les cartes de la main à la table
    */
   void detecterFamille();
   /**
    * Ajoute une carte dans la main du joueur
    * @param carte Carte à ajouter
    */
   void ajouterCarte(const Carte& carte);
   /**
    * Affiche la main du joueur
    */
   void afficherMain() const;
   /**
    * Affiche les familles sur table
    */
   void afficherFamillesSurTable() const;
private:
   std::string nom;
   std::vector<Carte> cartesEnMain;
   std::vector<Carte> famillesSurTable;
   unsigned int points;
};
#endif //JOUEUR
