#ifndef JETON_HPP
#define JETON_HPP


class Jeton
{
	private:
		Joueur couleur;
		Jeton[8] voisin;
		
	public:
		Jeton();
		Jeton(Joueur coul);
		Joueur getCouleurJeton();
		void getVoisin();
		Jeton ajouterVoisin(Jeton jeton);
};
/*
Jeton:
-Couleur
-Voisin : Tableau
getCouleur();
getVoisin();
ajouterVoisin();*/


#endif
