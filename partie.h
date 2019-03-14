/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : partie.h
 Auteur(s)   : Maurice Lehmann,Ahmed Farouk Ferchichi, Florian Schaufelberger
 Date        : 01.03.2019

 But         : Déclaration de la classe Partie

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
public:
    /**
     * Constructeur de la classe Partie
     */
    Partie();
    /**
     * Initialise la partie :
     * - vide la main des joueurs,
     * - vide les cartes sur table
     * - rempli la pioche et la mélange
     */
    void initialiserPartie();
    /**
     * Initialise la pioche : la rempli et la mélange
     */
    void initPioche();
    /**
     * Affiche le début d'un tour
     */
    void afficherDebutTour();
    /**
     * Effectue toutes les actions entre joueurs pendant un tour
     * @return false si aucun joueurs ne peut jouer et que la pioche est vide
     */
    bool tour();
    /**
     * Affiche le contenu de la pioche
     */
    void afficherPioche() const ;
    /**
     * Distribue les cartes aux joueurs
     * Les cartes viennent du dessus de la pioche mélangée
     */
    void distribuerCartes();
    /**
     * Detecte la fin d'une partie : si la pioche est vide et que les joueurs ne peuvent plus jouer
     * @return True si fin de partie, sinon false
     */
    bool detecterFinDePartie();
    /**
     * Demande une carte pour un joueur 1 à un joueur 2
     * @param  j1 Joueur demandant la carte
     * @param  j2 Joueur donnant la carte
     * @return True si j2 peut donner la carte, sinon false
     */
    bool demanderCarte(Joueur& j1, Joueur& j2);
    /**
     * Affiche la main et les familles sur table des joueurs
     */
    void afficherCartesJoueurs() const ;
    /**
     * Retourne le vecteur<Joueur> des joueurs de la partie
     * @return vecteur<Joueur>
     */
    std::vector<Joueur> getJoueurs();

private:
    std::vector<Carte> pioche;
    std::vector<Joueur> joueurs;
    unsigned int nombreDeTours;
};

#endif //PARTIE
