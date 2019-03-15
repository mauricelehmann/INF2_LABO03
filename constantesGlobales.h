/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : constantesGlobales.h
 Auteur(s)   : Maurice Lehmann,Ahmed Farouk Ferchichi, Florian Schaufelberger
 Date        : 01.03.2019

 But         : Définition des constantes globales du jeu des 7 familles

 Compilateur : MinGW-g++
 -----------------------------------------------------------------------------------
*/
#ifndef CONSTANTES_GLOBALES_H
#define CONSTANTES_GLOBALES_H

#include <vector>
#include <string>

const unsigned NOMBRE_FAMILLES = 7;
const char CARTES_PAR_FAMILLES = 'D';
const unsigned NB_CARTES_PAR_FAMILLES = (CARTES_PAR_FAMILLES - 'A');
const unsigned NOMBRE_JOUEURS = 5;
const std::vector<std::string> NOMS_JOUEURS = {"Alice","Bobby","Carol","Danny", "Antoine"};
const unsigned CARTES_PAR_JOUEURS = 5;

#endif
