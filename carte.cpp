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

Carte::Carte(const unsigned short& famille, const char& membre)
:famille(famille),membre(membre){}

//Getter
unsigned short Carte::getFamille(){
    return famille;
}
char Carte::getMembre(){
    return membre;
}
void Carte::afficherCarte(){
    cout << famille << membre;
}
