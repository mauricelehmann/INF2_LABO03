/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : joueur.cpp
 Auteur(s)   : Maurice Lehmann,Ahmed Farouk Ferchichi, Florian Schaufelberger
 Date        : 01.03.2019

 But         : Définitions des méthodes de la classe Joueur

 Compilateur : MinGW-g++
 -----------------------------------------------------------------------------------
*/

#include "joueur.h"

using namespace std;

/**
 * Constructeur de class Joueur
 * @param nom nom du joueur
 */
Joueur::Joueur(const string& nom, const bool& estIntelligent ):nom(nom),estIntelligent(estIntelligent){
    //On initialise les points à zéro
    points = 0;
}
/**
 * Ajoute une carte dans la main du joueur, venant de la pioche
 * @param pioche vecteur de carte
 */
void Joueur::piocher(vector<Carte>& pioche){

  cout << getNom() << " prend une carte dans la pioche (";
  pioche.back().afficherCarte();
  cout <<")" << endl;

   //On met la dernière carte de la pioche dans la main du joueur
   cartesEnMain.push_back(pioche.at(pioche.size() - 1));
   //On enlève la carte de la pioche
   pioche.pop_back();
}
/**
 * Detecte si le joueur à une famille complète dans la main
 * Si oui, on transfère les cartes de la main à la table
 */
void Joueur::detecterFamille(){
    //On cherche les différentes familles dans la main
    vector<unsigned short> famillesDansLaMain;
    for(Carte carte : cartesEnMain){
        //Si la famille de la carte n'est pas dans la familleDansLaMain, on l'ajoute
        if(find(famillesDansLaMain.begin(), famillesDansLaMain.end(), carte.getFamille()) == famillesDansLaMain.end()) {
            famillesDansLaMain.push_back(carte.getFamille());
        }
    }
    //On connais maintenant les familles à chercher
    unsigned short compteur = 0;
    for(unsigned short famille : famillesDansLaMain ){
        //On compte le nombre de carte de la meme famille que le joueur a dans la main
        for(Carte carte : cartesEnMain){
            if(carte.getFamille() == famille){
                compteur++;
            }
        }
        //Si on a tous les membres de la famille
        if(compteur == (NB_CARTES_PAR_FAMILLES + 1) ){
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
/**
 * Ajoute une carte dans la main du joueur
 * @param carte Carte à ajouter
 */
void Joueur::ajouterCarte(const Carte& carte){
   cartesEnMain.push_back(carte);
}
/**
 * Affiche la main du joueur
 */
void Joueur::afficherMain() const{
   for(Carte carte : cartesEnMain ){
      carte.afficherCarte();
      std::cout << " ";
   }
}
/**
 * Affiche les familles du joueur sur table
 */
void Joueur::afficherFamillesSurTable() const{
    for(Carte carte : famillesSurTable ){
       carte.afficherCarte();
       cout << " ";
    }
}
/**
 * Enlève une carte de la main du joueur
 * @param carte Carte à enlever
 */
void Joueur::donnerCarte(const int& carte) {
    cartesEnMain.erase(cartesEnMain.begin() + carte);
}
/**
 * Ajoute une carte dans la main du joueur
 * @param carte Carte à ajouter
 */
void Joueur::recevoirCarte(Carte& carte) {
  cartesEnMain.push_back(carte);
}
/**
 * Retourne vecteur de cartes en main du joueur
 * @return vector<Carte> cartes en main
 */
vector<Carte> Joueur::getCartesEnMain() const {
  return cartesEnMain;
}
/**
 * Retourne le nom du joueur
 * @return string, nom du joueur
 */
string Joueur::getNom() const {
  return nom;
}
/**
 * Incrémente le nombre du point du joueur
 */
void Joueur::incrementerPoints(){
<<<<<<< HEAD
   //Le "+1" parce que NB_CARTES_PAR_FAMILLES commence de 0 à n
   points += (famillesSurTable.size() / (NB_CARTES_PAR_FAMILLES + 1) ) ;
}
/**
 * Choisi une ou plusieurs cartes pertinente à demander à l'adversaire
 * @return vecteur de carte a demander
 */
vector<Carte> Joueur::choisirCarteIntelligent(){

    vector<Carte> cartesADemander ;
    vector<unsigned> compteurFamille(NOMBRE_FAMILLES,0);

    //On compte le nombre de carte de la meme famille il y a
    for( Carte carte : cartesEnMain ){
        compteurFamille.at(carte.getFamille()) += 1;
    }
    //On détérmine qui est le plus grand, l'incice nous permet de retrouver la famille
    size_t plusDeMembre = 0 ;
    size_t plusGrandeFamille;
    for( size_t famille = 1 ; famille <= NOMBRE_FAMILLES ; famille ++){
        if(compteurFamille.at(famille - 1) > plusDeMembre){
            plusDeMembre = compteurFamille.at(famille - 1);
            plusGrandeFamille = famille - 1;
        }
    }
    //On ajoute les carte à demander
    for(char membre = 'A'; membre <= CARTES_PAR_FAMILLES; membre++) {
        Carte carteADemander(plusGrandeFamille,membre);
        if(find(cartesEnMain.begin(), cartesEnMain.end(), carteADemander) == cartesEnMain.end()){
            cartesADemander.push_back(carteADemander);
        }
    }
    return cartesADemander;
}
=======
  // on rajoute +1 car NB_CARTES_PAR_FAMILLES va de 0 à n
   points += (famillesSurTable.size() / (NB_CARTES_PAR_FAMILLES + 1) );
}
>>>>>>> 0c4d224f9ba2cb29c60ad17b906080a03ae89595
