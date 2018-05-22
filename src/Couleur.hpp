//HARRAT Zohra, DENIS Jimmy

#ifndef COULEUR_HPP
#define COULEUR_HPP
#include <string>

/*!
 * \file Couleur.hpp
 * \author HARRAT-Zohra DENIS-Jimmy
 * \brief Enumération des couleurs
 *
 * Cette énumération permet de définir la couleur de chaque joueur
 */

 /*! \enum Couleur
  * \brief Couleur des joueurs
  *
  * Couleur donne les constantes pour différencier les joueurs
  */
enum Couleur : char {
					 LIBRE, /*!< La case n'est pas occupé */
					 ROUGE, /*!< Le joueur rouge */
					 JAUNE, /*!< Le joueur jaune */
					 PERSONNE /*!< Personne n'a gagner : égalité */
					 };

/*! \brief Afficher en toute lettre la couleur
 *  \param[in] c Couleur que l'on doit afficher
 * 	\result Affiche LIBRE, ROUGE, JAUNE ou PERSONNE
 */
std::string afficherCouleur(Couleur c);

/*! \brief Opérateur de sortie
 *  \param[out] couleur Couleur que l'on doit afficher
 *  \result Affiche ., R, J ou X
 */
std::ostream& operator<<(std::ostream& os,const Couleur& couleur);

/*! \brief Opérateur d'entré
 *  \param[in] couleur couleur pour lequel on doit entrer des valeurs
 *  \result La couleur est modifié
 *
 *  . pour LIBRE \n
 *  R pour ROUGE \n
 *  J pour JAUNE \n
 *  X pour PERSONNE \n
 */
std::istream& operator>>(std::istream& is,Couleur& couleur);

#endif
