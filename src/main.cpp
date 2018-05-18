#include <iostream>
#include "Plateau.hpp"
#include "Joueur.hpp"
int main()
{
	Plateau p;
	p.ajouterJeton(3,ROUGE);
	p.ajouterJeton(3,JAUNE);
	p.ajouterJeton(3,ROUGE);
	p.ajouterJeton(3,JAUNE);
		p.ajouterJeton(3,ROUGE);
	p.ajouterJeton(3,JAUNE);
		p.ajouterJeton(3,ROUGE);
	p.ajouterJeton(3,JAUNE);
		p.ajouterJeton(3,ROUGE);
	p.ajouterJeton(3,JAUNE);
	
		p.ajouterJeton(3,ROUGE);
	p.ajouterJeton(3,JAUNE);
		p.ajouterJeton(3,ROUGE);
	p.ajouterJeton(3,JAUNE);
	p.afficherPlateau();


	return 0;
}
