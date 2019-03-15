/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : carte.h
 Auteur(s)   : Maurice Lehmann,Ahmed Farouk Ferchichi, Florian Schaufelberger
 Date        : 01.03.2019

 But         : Déclaration de la classe Carte

 Compilateur : MinGW-g++
 -----------------------------------------------------------------------------------
*/
#ifndef CARTE_H
#define CARTE_H

/**
 * Class Carte , objet représentant une carte à jouer
 * @param famille Famille de la carte
 * @param membre  Membre de la famille
 */
class Carte{

public:
   /**
    * Constructeur de la classe Carte
    * @param famille Famille de la carte
    * @param membre  Membre de la famille de la carte
    */
   Carte(const unsigned short& famille, const char& membre);
   /**
    * Surcharge de l'opérateur ==
    * On compare le membre ET la famille d'une carte
    * @return true si la carte est la même
    */
   bool operator == (const Carte&);
   /**
    * Retourne la famille de la carte
    * @return unsigned short , famille de la carte
    */
   unsigned short getFamille();
   /**
    * Retourne le membre de la carte
    * @return char , membre de la carte
    */
   char getMembre();
   /**
    * Affiche le membre et la famille de la carte
    */
   void afficherCarte();
private:
   unsigned short famille;
   char membre;
};
#endif //CARTE
