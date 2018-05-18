#ifndef JEU_HPP
#define JEU_HPP

#include "Joueur.hpp"
#include "Plateau.hpp"

class Jeu 
{
	private:
		/*Joueur 1*/
		Joueur joueur1;
		/*Joueur 2*/
		Joueur joueur2;
		/*Platea du jeu*/
		Plateau plateau;
	public:
		/*Constructor*/
		Jeu();
		/*Début de partie*/
		void commencerPartie();
};


#endif
