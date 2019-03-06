/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : joueur.cpp
 Auteur(s)   : Maurice Lehmann,Ahmed Farouk Ferchichi, Florian Schaufelberger
 Date        : 01.03.2019

 But         : TODO

 Compilateur : MinGW-g++
 -----------------------------------------------------------------------------------
*/
#include "joueur.h"
<<<<<<< HEAD
using namespace std;

Joueur::Joueur(const string& nom):nom(nom){
    //On initialise les points à zéro
    points = 0;
}
void Joueur::piocher(vector<Carte>& pioche){
   //On met la dernière carte de la pioche dans la main du joueur
   cartesEnMain.push_back(pioche.at(pioche.size() - 1));
   //On enlève la carte de la pioche
   pioche.pop_back();
}
void Joueur::demanderCarte(){

}
void Joueur::detecterFamille(){
   size_t compteur = 0;
   for(Carte carte : cartesEnMain ){
       
   }
}
void Joueur::ajouterCarte(const Carte& carte){
   cartesEnMain.push_back(carte);
}
void Joueur::afficherMain(){
   for(Carte carte : cartesEnMain ){
      carte.afficherCarte();
   }
}
=======
>>>>>>> ec795d5592c3f800bb7a8c94c5f621aaa3fff402
