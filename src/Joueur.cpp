#include <iostream>
#include "Joueur.hpp"

/*Constructor : Par défaut prénom ANONYMOUS, la couleur PERSONNE , isMyTurn false */
Joueur::Joueur():
_prenom("ANONYMOUS"),_Couleur(PERSONNE),_isMyTurn(false)
{}


/*Constructor : Par défaut on attribut ANONYMOUS */
Joueur::Joueur(std::string prenom):
_prenom(prenom),_Couleur(PERSONNE),_isMyTurn(false)
{}

/*Retourne le prénom du joueur*/
std::string Joueur::getPrenom() const
{
	return _prenom;
}

/*Retourne la couleur du joueur*/
Couleur Joueur::getCouleur() const
{
	return _Couleur;
}

/*Modifie la couleur du joueur*/
void Joueur::setCouleur(Couleur couleur)
{
	_Couleur=couleur;
}

/*Retourne true si c'est notre tour*/
bool Joueur::getisMyTurn() const
{
	return _isMyTurn;
}


/*Modifie le tour du joueur*/
void Joueur::setisMyTurn()
{
	if( _isMyTurn == true)
		_isMyTurn=false;
	else
		_isMyTurn=true;
}

/*Affichage du joueur*/
void Joueur::afficherJoueur()
{
	std::cout<<"JOUEUR: "<<_prenom<<std::endl<<"COULEUR: "<<afficherCouleur(_Couleur)<<std::endl;
}
