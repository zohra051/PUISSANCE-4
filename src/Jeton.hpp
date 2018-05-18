#ifndef JETON_HPP
#define JETON_HPP

#include "Couleur.hpp"

class Jeton
{
	private:
		/*Couleur du jeton*/
		Couleur _Couleur; 
		
	public:
		/*Constructor : Jeton par défaut mis à LIBRE*/
		Jeton();
		/*Retourne la couleur du jeton*/
		Couleur getCouleurJeton() const;
		/*Change la précédente couleur*/
		void setCouleurJeton(Couleur couleur);
		
		/* Opérateur sortie */
		friend std::ostream& operator<<(std::ostream& os,const Jeton& jeton);
		/*Opérateur entrée */
		friend std::istream& operator>>(std::istream& is,Jeton& jeton); 
	
};



#endif
