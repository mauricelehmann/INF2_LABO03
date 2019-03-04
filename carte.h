/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : carte.h
 Auteur(s)   : Maurice Lehmann,Farouk Ferchichi, Florian Schaufelberger
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
   Carte(const unsigned short& famille, const unsigned short& membre)
   :famille(famille),membre(membre){}
private:
   unsigned short famille;
   unsigned short membre; //Ou char , à choix...
};
#endif //CARTE
