#include <iostream>
#include "Couleur.hpp"

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
