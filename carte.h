/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : carte.h
 Auteur(s)   : Maurice Lehmann,Ahmed Farouk Ferchichi, Florian Schaufelberger
 Date        : 01.03.2019

 But         : TODO

 Compilateur : MinGW-g++
 -----------------------------------------------------------------------------------
*/
#ifndef CARTE
#define CARTE

class Carte{
public:
   //Constructeur
   Carte(const unsigned short& famille, const char& membre);
   unsigned short getFamille();
   char getMembre();
private:
   unsigned short famille;
   char membre;
};
#endif //CARTE
