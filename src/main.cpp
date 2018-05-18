#include <iostream>
#include "Plateau.hpp"
#include "Joueur.hpp"
int main()
{
	Plateau p;
	p.afficherPlateau();
	Joueur j("Zohra");
	j.afficherJoueur();
	return 0;
}
