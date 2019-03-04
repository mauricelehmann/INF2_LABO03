/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : partie.h
 Auteur(s)   : Maurice Lehmann,Ahmed Farouk Ferchichi, Florian Schaufelberger
 Date        : 01.03.2019

 But         : TODO

 Compilateur : MinGW-g++
 -----------------------------------------------------------------------------------
*/
#ifndef PARTIE
#define PARTIE
#include "joueur.h"
class Partie{
    friend class Joueur;
public:
    Partie(); //Florian
    void tour(); //Florian
    void initialiserPartie(); //Florian
    void distribuerCartes(); //Farouk
    bool detecterFinDePartie(); //Farouk
private:
    std::vector<Carte> pioche;
    std::vector<Joueur> joueurs;
    unsigned int nombreDeTours;
};

#endif //PARTIE
