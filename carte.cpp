/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : carte.cpp
 Auteur(s)   : Maurice Lehmann,Ahmed Farouk Ferchichi, Florian Schaufelberger
 Date        : 01.03.2019

 But         : TODO

 Compilateur : MinGW-g++
 -----------------------------------------------------------------------------------
*/
#include "carte.h"
using namespace std;

/**
 * Constructeur de la classe Carte
 * @param famille Famille de la carte
 * @param membre  Membre de la famille de la carte
 */
Carte::Carte(const unsigned short& famille, const char& membre)
:famille(famille),membre(membre){}
/**
 * Surcharge de l'opérateur ==
 * On compare le membre ET la famille d'une carte
 * @return true si la carte est la même
 */
bool Carte::operator == (const Carte& rhs) {
	return(membre == rhs.membre && famille == rhs.famille);
}
/**
 * Retourne la famille de la carte
 * @return unsigned short , famille de la carte
 */
unsigned short Carte::getFamille(){
    return famille;
}
/**
 * Retourne le membre de la carte
 * @return char , membre de la carte
 */
char Carte::getMembre(){
    return membre;
}
/**
 * Affiche le membre et la famille de la carte
 */
void Carte::afficherCarte(){
    cout << famille << membre;
}
