#include "Joueur.hpp"

/* ---------------------AFFICHAGE SI BESOIN---------------------*/
/* Opérateur de Sortie : 
 * Si le joueur ROUGE , affiche R
 * Si le joueur JAUNE, affiche J
 * Di personne ne gagne ( PERSONNE ), affiche X
 * par défault, afficher '.' si LIBRE.*/
  
std::ostream & operator<<(std::ostream & os, Joueur joueur) {
  switch (joueur) {
    case ROUGE : os << 'R'; break;
    case JAUNE : os << 'J'; break;
    case PERSONNE : os << 'X'; break;
    default: os << '.';
  }
  return os;
}

/*Opérateur d'Entrée :
 * Attribut ROUGE à Joueur si 'R' saisi
 * Attribut JAUNE à Joueur si 'J' saisi
 * Attribut PERSONNE à Joueur si 'X' saisi
 * Attribut LIBRE si autre. */
 
std::istream & operator>>(std::istream & is, Joueur & joueur) {
  char chr = is.get();
  switch (chr) {
    case 'R' : joueur = ROUGE; break;
    case 'J' : joueur = JAUNE; break;
    case 'X' : joueur = PERSONNE; break;
    default: joueur = LIBRE;
  }
  return is;
}

/* -----------AFFICHAGE GENERAL-----------------*/
/*Formateur Joueur:
 * Si le joueur ROUGE , affiche ROUGE
 * Si le joueur JAUNE, affiche JAUNE
 * Di personne ne gagne ( PERSONNE ), affiche PERSONNE
 * par défault, afficher INCONNU si LIBRE.*/

std::string formaterJoueur(Joueur joueur) {
  switch (joueur) {
    case ROUGE : return "Rouge";
    case JAUNE : return "Jaune";
    case PERSONNE : return "Personne";
    default : return "Inconnu";
  }
}

