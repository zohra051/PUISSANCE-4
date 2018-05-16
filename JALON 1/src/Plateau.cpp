#include <iostream>
#include "Plateau.hpp"
#include "Jeton.hpp"
void afficherPlateau()
{
	for(int i=0;i<plateau.size();i++)
	{	
		for(int j=0;j<plateau[i].size();j++)
		{
			std::cout<<plateau[i][j].getCouleurJeton();
		}
	}
}


  
