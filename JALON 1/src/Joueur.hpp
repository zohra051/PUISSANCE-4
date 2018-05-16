#ifndef JOUEUR_HPP_
#define JOUEUR_HPP_

#include <iostream>


enum Couleur : char {LIBRE, ROUGE, JAUNE, PERSONNE};

/*Opérateur de Sortie : Affichage */
std::ostream & operator<<(std::ostream & os, Couleur couleur);
/*Opérateur d'Entrée : Saisie */
std::istream & operator>>(std::istream & is, Couleur & couleur);

/*Affichage du joueur*/
std::string formaterJoueur(Couleur couleur);

#endif

