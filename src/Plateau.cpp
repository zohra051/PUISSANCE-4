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

/*Retourne THE jeton sur le plateau */
Jeton Plateau::getJetonPlateau(int colonne,int ligne)
{
	return _Plateau[colonne][ligne];
}

/*Affichage du Plateau de jeu (console) */
void Plateau::afficherPlateau() const
{
	std::cout<<"\t\t_________________________________________________"<<std::endl;
	std::cout<<"\t\t";
	for(int i=0;i<COLONNE;i++)
	{
		std::cout<<"| ["<<i<<"] |";
		
	}
		std::cout<<std::endl;
	std::cout<<"\t\t_________________________________________________"<<std::endl;

	for(int i=0;i<LIGNE;++i)
	{
		std::cout<<"\t\t";
		for(auto l:_Plateau)
		{
			std::cout<<"|  "<<l[i]<<"  |";
		}	
		std::cout<<std::endl;
	}	
	std::cout<<"\t\t_________________________________________________"<<std::endl;
}

/*Ajouter un jeton sur le plateau*/
void Plateau::ajouterJeton(int place,Couleur couleur)
{
	if(_nbJeton[place] < LIGNE) 
	{
		if(place>=0 && place<=COLONNE-1)
		{
			_Plateau[place][LIGNE-_nbJeton[place]-1].setCouleurJeton(couleur);
			_nbJeton[place]++;
		}
		else
		{
			throw std::string("INDICE INCORECTE!");
		}
	}
	else 
	{
		throw std::string("PAS DE PLACE !");		
	}
}

/*Tableau isPlein ou non*/
bool Plateau::isPlein()
{
	for(int i=0;i<_nbJeton.size();i++)
	{
		if(_nbJeton[i] < LIGNE)
			return false;
	}
	return true;
}
