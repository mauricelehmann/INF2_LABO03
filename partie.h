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
#include <algorithm>
#include <random>
#include <vector>
#include <chrono>

class Partie{
    friend class Joueur;
public:
    Partie(); //Florian
    void initPioche();
    void afficherDebutTour();
    bool tour(); //Florian
    void initialiserPartie(); //Florian
    void distribuerCartes(); //Farouk bonjour
    bool detecterFinDePartie(); //Farouk

   bool demanderCarte(Joueur& j1, Joueur& j2);

    //Methode d'affichage
    void afficherPioche() const ;
    void afficherCartesJoueurs() const ;
    std::vector<Joueur> getJoueurs();

private:
    std::vector<Carte> pioche;
    std::vector<Joueur> joueurs;
    unsigned int nombreDeTours;
};

#endif //PARTIE
