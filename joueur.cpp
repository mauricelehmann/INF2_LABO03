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
#include <iostream>
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
    //On cherche les différentes familles dans la main
    vector<unsigned short> famillesDansLaMain;
    for(Carte carte : cartesEnMain){
        //Si la famille de la carte n'est pas dans la familleDansLaMain, on l'ajoute
        if(find(famillesDansLaMain.begin(), famillesDansLaMain.end(), carte.getFamille()) == famillesDansLaMain.end()) {
            famillesDansLaMain.push_back(carte.getFamille());
        }
    }
    //TODO : Utiliser count_if() ? Essayé, par réussi...
    //On connais maintenant les familles à chercher
    unsigned short compteur = 0;
    for(unsigned short famille : famillesDansLaMain ){
        //On compte le nombre de carte de la meme famille que le joueur a dans la main
        for(Carte carte : cartesEnMain){
            if(carte.getFamille() == famille){
                compteur++;
            }
        }
        //TODO CHANGER CETTE CONSTANTE CHAR EN INT!
        //Si on a tous les membres de la famille
        if(compteur == (CARTES_PAR_FAMILLES - 'A' + 1) ){
            //On pose cette famille sur la table
            for(vector<Carte>::iterator itCarte = cartesEnMain.begin() ; itCarte != cartesEnMain.end() ; itCarte++){
                if((*itCarte).getFamille() == famille){
                    famillesSurTable.push_back((*itCarte));
                    cartesEnMain.erase(itCarte);
                    itCarte--;
                }
            }
        }
        compteur = 0;
    }
}


void Joueur::ajouterCarte(const Carte& carte){
   cartesEnMain.push_back(carte);
}


void Joueur::afficherMain() const{
   for(Carte carte : cartesEnMain ){
      carte.afficherCarte();
   }
}


void Joueur::afficherFamillesSurTable() const{
    for(Carte carte : famillesSurTable ){
       carte.afficherCarte();
    }
}
