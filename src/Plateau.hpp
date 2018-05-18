#ifndef PLATEAU_HPP
#define PLATEAU_HPP

#include <array>
#include "Jeton.hpp"
#include "Taille.hpp"
#include "Couleur.hpp"


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
		/*Retourne THE jeton sur le plateau */
		Jeton getJetonPlateau(int colonne,int ligne);
		/*Affichage du Plateau de jeu (console) */
		void afficherPlateau() const;
		/*Ajouter un jeton sur le plateau*/
		void ajouterJeton(int place,Couleur couleur);
		/*Tableau isPlein ou non*/
		bool isPlein();
		
		
		
};

#endif
