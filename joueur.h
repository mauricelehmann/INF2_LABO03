/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : joueur.h
 Auteur(s)   : Maurice Lehmann,Ahmed Farouk Ferchichi, Florian Schaufelberger
 Date        : 01.03.2019

 But         : Déclaration de la classe Joueur

 Compilateur : MinGW-g++
 -----------------------------------------------------------------------------------
*/
#ifndef JOUEUR_H
#define JOUEUR_H

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <cstdlib>

#include "constantesGlobales.h"
#include "carte.h"

/**
 * Classe Joueur
 * @param nom Nom du joueur
 */
class Joueur{
    //La classe Partie à besoin d'avoir un accès attribut privé du joueur
    friend class Partie;
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
    * Affiche les familles du joueur sur table
    */
   void afficherFamillesSurTable() const;
   /**
    * Enlève une carte de la main du joueur
    * @param carte Carte à enlever
    */
   void donnerCarte(const int& carte);
   /**
    * Ajoute une carte dans la main du joueur
    * @param carte Carte à ajouter
    */
   void recevoirCarte(Carte& carte);
   /**
    * Retourne vecteur de cartes en main du joueur
    * @return vector<Carte> cartes en main
    */
   std::vector<Carte> getCartesEnMain() const;
   /**
    * Retourne le nom du joueur
    * @return string, nom du joueur
    */
   std::string getNom() const;
   /**
    * Incrémente le nombre total de points du joueur
    */
   void incrementerPoints();
private:
   std::string nom;
   std::vector<Carte> cartesEnMain;
   std::vector<Carte> famillesSurTable;
   unsigned int points;
};
#endif //JOUEUR
