//HARRAT Jimmy, DENIS Jimmy

#include "Jeu.hpp"
#include <iostream>
/*Constructor*/
Jeu::Jeu():
joueur1(Joueur()),joueur2(Joueur()),plateau(Plateau())
{}


/*Début de partie*/
void Jeu::commencerPartie()
{
	std::string entrer;
	int sortie;
	std::cout<<"Joueur 1 : ";
	std::cin>>entrer;
	joueur1.setPrenom(entrer);

	std::cout<<"Joueur 2 : ";
	std::cin>>entrer;
	joueur2.setPrenom(entrer);

	std::cout<<std::endl;

	joueur1.setCouleur(ROUGE);
	joueur2.setCouleur(JAUNE);


	while(!plateau.isPlein())
	{
		//est-ce que le joueur a jouer ?
		bool flag = false;
		while(flag == false)
		{
			try
			{
				plateau.afficherPlateau();
				std::cout<<std::endl;
				std::cout<<joueur1.getPrenom()<<": Choisir position du jeton : ";
				std::cin>>sortie;
				plateau.ajouterJeton(sortie,joueur1.getCouleur());
				flag = true;
			}
			catch (std::string& e)
			{
				std::cout<<e<<std::endl;
			}
			std::cout<<std::endl;
		}

		flag = false;
		while(flag == false)
		{
			try
			{
				plateau.afficherPlateau();
				std::cout<<std::endl;
				std::cout<<joueur2.getPrenom()<<": Choisir position du jeton : ";
				std::cin>>sortie;
				plateau.ajouterJeton(sortie,joueur2.getCouleur());
				flag = true;
			}
			catch (std::string& e)
			{
				std::cout<<e<<std::endl;
			}
			std::cout<<std::endl;
		}
	}


}
