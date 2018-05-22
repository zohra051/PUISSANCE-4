/*HARRAT Zohra, DENIS Jimmy */

#include <iostream>
#include "Couleur.hpp"

/*bel affichage de la couleur*/
std::string afficherCouleur(Couleur c)
{
	switch(c){
			case LIBRE : return "Libre";
				break;
			case ROUGE : return"Rouge";
				break;
			case JAUNE : return "Jaune";
				break;
			case PERSONNE : return "Personne";
				break;
			}
}



/* Opérateur sortie */
std::ostream& operator<<(std::ostream& os,const Couleur& couleur)
{
		switch(couleur){
			case LIBRE : os<<'.';
				break;
			case ROUGE : os<<'R';
				break;
			case JAUNE : os<<'J';
				break;
			case PERSONNE : os<<'X';
				break;
			}
		return os;

}

/*Opérateur entrée */
std::istream& operator>>(std::istream& is,Couleur& couleur)
{
	char chr = is.get();
	switch (chr) {
		case 'R' : couleur = ROUGE;
			break;
		case 'J' : couleur = JAUNE;
			break;
		case 'X' : couleur = PERSONNE;
			break;
		default: couleur = LIBRE;
	}
	return is;

}
