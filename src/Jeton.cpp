#include <iostream>
#include "Jeton.hpp"

/*Constructor : Jeton par défaut mis à LIBRE*/
Jeton::Jeton():
_Couleur(LIBRE)
{}

/*Retourne la couleur du jeton*/
Couleur Jeton::getCouleur() const
{
	return _Couleur;
}

/*Change la précédente couleur*/
void Jeton::setCouleur(Couleur couleur)
{
	_Couleur=couleur;
}

/* Opérateur sortie */
std::ostream& operator<<(std::ostream& os,const Jeton& jeton)
{
	os << jeton._Couleur;
	return os;
}


/*Opérateur entrée */
std::istream& operator>>(std::istream& is,Jeton& jeton)
{
	is >> jeton._Couleur;
	return is;
}
