#ifndef PLATEAU_HPP
#define PLATEAU_HPP

#include <array>
#include "Jeton.hpp"
#include "Taille.hpp"


class Plateau
{
	private: 
		/* Plateau de jeu */
		std::array<std::array<Jeton,LIGNE>,COLONNE> _Plateau ; 
		/* Tableau contenant le nombre de jeton pour chaque colonne */
		std::array<int,COLONNE> _nbJeton ;
		
	public:
		/*Constructor :Remplit le plateau de jeton vide */
		Plateau();
		/*Affichage du Plateau de jeu (console) */
		void afficherPlateau() const;
		
		
};

#endif
