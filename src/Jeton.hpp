//HARRAT Zohra, DENIS Jimmy

/*! \file Jeton.hpp
 *  \author HARRAT-Zohra DENIS-Jimmy
 *  \brief classe Jeton
 *
 * 	Classe représentant un jeton dans la grille de jeu
 */
#ifndef JETON_HPP
#define JETON_HPP

#include "Couleur.hpp"

/*! \class Jeton
 *  \brief représentation d'un jeton
 *
 *  Un jeton possède une couleur et se trouve dans la grille du Plateau de jeu
 */
class Jeton
{
	private:

		Couleur _Couleur; /*!< Couleur du jeton */

	public:
		/*! \brief Constructeur
		 *  \result Créer un Jeton de Couleur Vide
		 *  Constructeur par défaut
		 */
		Jeton();

		/*! \brief Accesseur de couleur
		 *  \return Retourne la Couleur du Jeton
		 */
		Couleur getCouleurJeton() const;

		/*! \brief Modificateur de la couleur
		 */
		void setCouleurJeton(Couleur couleur);

		/* Opérateur sortie */
		friend std::ostream& operator<<(std::ostream& os,const Jeton& jeton);
		/*Opérateur entrée */
		friend std::istream& operator>>(std::istream& is,Jeton& jeton);

};



#endif
