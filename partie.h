/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : partie.h
 Auteur(s)   : Maurice Lehmann,Farouk Ferchichi, Florian Schaufelberger
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
    void tour();
    void initialiserPartie();
    void distribuerCartes();
    bool detecterFinDePartie();
    void reinitialiserPartie();
private:
    std::vector<Carte> pioche;
    std::vector<Joueur> joueurs;
    unsigned int nombreDeTours;
};

#endif //PARTIE
