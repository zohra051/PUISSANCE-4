#ifndef JOUEUR_HPP
#define JOUEUR_HPP
#include <string>
#include "Couleur.hpp"

class Joueur
{
	private:
		/*Coordonnée du joueur*/
		std::string _prenom;
		/*Couleur du joueur*/
		Couleur _Couleur;
		/*Un boolean qui vérifie si c'est notre tour de jeu */
		bool _isMyTurn;
		
	public:
		/*Constructor : Par défaut prénom ANONYMOUS, la couleur PERSONNE , isMyTurn false */
		Joueur();
		/*Constructor : Par défaut on attribut Prenom */
		Joueur(std::string prenom);
		/*Retourne le prénom du joueur*/
		std::string getPrenom() const;
		/*Retourne la couleur du joueur*/
		Couleur getCouleur() const;
		/*Modifie la couleur du joueur*/
		void setCouleur(Couleur couleur);
		/*Retourne true si c'est notre tour*/
		bool getisMyTurn() const;
		/*Modifie le tour du joueur*/
		void setisMyTurn();
		/*affichage du joueur*/
		void afficherJoueur();
		
	
};


#endif
