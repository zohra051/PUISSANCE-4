#include <iostream>
#include "Plateau.hpp"

/*Constructor :Remplit le plateau de jeton vide */
Plateau::Plateau()
{
	/* Parcourt du plateau */
	for(auto c:_Plateau)
	{
		/* A chaque Colonne, on le remplis de Jeton */
		c.fill(Jeton());
	}
	
	_nbJeton.fill(0);
}
/*Affichage du Plateau de jeu (console) */
void Plateau::afficherPlateau() const
{
	for(int i=0;i<LIGNE;++i)
	{
		
		for(auto l:_Plateau)
		{
			std::cout<<l[i];
		}	
		std::cout<<std::endl;
	}	
}
