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
		/* Verification si 4 jeton aligné sur une Ligne */
		bool parcourtLigne(int x, int y, Jeton jeton);
		/* Verification si 4 jeton aligné sur une Colonne */
		bool parcourtColonne(int x, int y, Jeton jeton);
		/* Verification si 4 jeton aligné sur une Diagonale de droite (bas vers haut) */
		bool parcourtDiagonaleD(int x, int y, Jeton jeton);
		/* Verification si 4 jeton aligné sur une Diagonale de gauche (haut vers bas) */
		bool parcourtDiagonaleG(int x, int y, Jeton jeton);
		/* Fonction si le joueur est gagnant */
		bool isWinner(int x, int y, Jeton jeton);
		/*Verifier s'il y a un gagnant, et annoncer le perdant, et si aucun : egalite. */
		Couleur verificationGagnant(int place, Jeton jeton); 
		
		
		
};

#endif
