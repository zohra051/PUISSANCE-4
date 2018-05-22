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

/* Verification si 4 jeton aligné sur une LIGNE */
bool Plateau::parcourtLigne(int x, int y,Jeton jeton)
{
	/*verification si l'on à besoin de parcourir à droite ou non */
	bool verifDroite=true;
	/*verification si l'on à besoin de parcourir à gauche ou non */
	bool verifGauche=true;
	/* Compteur pour les 4 jetons */
	int cpt=1;
	for(int i = 1;(verifDroite == true || verifGauche == true);i++)
	{	
		/* si 4 jeton sont aligné ou non 
		 * si oui, verifier parti gauche et droite opur trouver des jetons de la même couleur
		 * sinon return true, pour signifier qu'il y a bien 4 jeton aligné
		 */
		if(cpt < 4)
		{
			/*DROITE*/
			if(verifDroite == true && (x+i)<COLONNE && (_Plateau[x+i][y].getCouleurJeton() == jeton.getCouleurJeton())) /* Verifi si la couleur du jeton x est bien celle de notre jeton */
				cpt++;
			else
				verifDroite = false;
			/*GAUCHE*/
			if(verifGauche == true && (x-i)>0 && (_Plateau[x-i][y].getCouleurJeton() == jeton.getCouleurJeton())) /* Verifi si la couleur du jeton x est bien celle de notre jeton */
				cpt++;
			else
				verifGauche = false;
			
		}
		else
			return true;
	}
	return false;
	
}	

/* Verification si 4 jeton aligné sur une COLONNE*/
bool Plateau::parcourtColonne(int x, int y,Jeton jeton)
{
	/*verification si l'on à besoin de parcourir à droite ou non */
	bool verifDroite=true;
	/*verification si l'on à besoin de parcourir à gauche ou non */
	bool verifGauche=true;
	/* Compteur pour les 4 jetons */
	int cpt=1;
	for(int i = 1;(verifDroite == true || verifGauche == true);i++)
	{	
		/* si 4 jeton sont aligné ou non 
		 * si oui, verifier parti gauche et droite opur trouver des jetons de la même couleur
		 * sinon return true, pour signifier qu'il y a bien 4 jeton aligné
		 */
		if(cpt < 4)
		{
			/*DROITE*/
			if(verifDroite == true && (y+i)<LIGNE && (_Plateau[x][y+i].getCouleurJeton() == jeton.getCouleurJeton())) /* Verifi si la couleur du jeton x est bien celle de notre jeton */
				cpt++;
			else
				verifDroite = false;
			/*GAUCHE*/
			if(verifGauche == true && (y-i)>0 && (_Plateau[x][y-i].getCouleurJeton() == jeton.getCouleurJeton())) /* Verifi si la couleur du jeton x est bien celle de notre jeton */
				cpt++;
			else
				verifGauche = false;
			
		}
		else
			return true;
	}
	return false;
	
}	

/* Verification si 4 jeton aligné sur une DIAGONALE Droite*/
bool Plateau::parcourtDiagonaleD(int x, int y,Jeton jeton)
{
	/*verification si l'on à besoin de parcourir à droite ou non */
	bool verifDroite=true;
	/*verification si l'on à besoin de parcourir à gauche ou non */
	bool verifGauche=true;
	/* Compteur pour les 4 jetons */
	int cpt=1;
	for(int i = 1;(verifDroite == true || verifGauche == true);i++)
	{	
		/* si 4 jeton sont aligné ou non 
		 * si oui, verifier parti gauche et droite opur trouver des jetons de la même couleur
		 * sinon return true, pour signifier qu'il y a bien 4 jeton aligné
		 */
		if(cpt < 4)
		{
			/*DROITE*/
			if(verifDroite == true && (x+i<COLONNE && y-i>0 ) && (_Plateau[x+i][y-i].getCouleurJeton() == jeton.getCouleurJeton())) /* Verifi si la couleur du jeton x est bien celle de notre jeton */
				cpt++;
			else
				verifDroite = false;
			/*GAUCHE*/
			if(verifGauche == true && (x-i>0 && y+i<LIGNE) && (_Plateau[x-i][y+i].getCouleurJeton() == jeton.getCouleurJeton())) /* Verifi si la couleur du jeton x est bien celle de notre jeton */
				cpt++;
			else
				verifGauche = false;
			
		}
		else
			return true;
	}
	return false;
	
}	

/* Verification si 4 jeton aligné sur une DIAGONALE GAUCHE*/
bool Plateau::parcourtDiagonaleG(int x, int y,Jeton jeton)
{
	/*verification si l'on à besoin de parcourir à droite ou non */
	bool verifDroite=true;
	/*verification si l'on à besoin de parcourir à gauche ou non */
	bool verifGauche=true;
	/* Compteur pour les 4 jetons */
	int cpt=1;
	for(int i = 1;(verifDroite == true || verifGauche == true);i++)
	{	
		/* si 4 jeton sont aligné ou non 
		 * si oui, verifier parti gauche et droite opur trouver des jetons de la même couleur
		 * sinon return true, pour signifier qu'il y a bien 4 jeton aligné
		 */
		if(cpt < 4)
		{
			/*DROITE*/
			if(verifDroite == true && (y+i<COLONNE && x+i<LIGNE ) && (_Plateau[x+i][y+i].getCouleurJeton() == jeton.getCouleurJeton())) /* Verifi si la couleur du jeton x est bien celle de notre jeton */
				cpt++;
			else
				verifDroite = false;
			/*GAUCHE*/
			if(verifGauche == true && (y-i>0 && x-i>0) && (_Plateau[x-i][y-i].getCouleurJeton() == jeton.getCouleurJeton())) /* Verifi si la couleur du jeton x est bien celle de notre jeton */
				cpt++;
			else
				verifGauche = false;
			
		}
		else
			return true;
	}
	return false;
	
}	

/* Fonction si le joueur est gagnant */
bool Plateau::isWinner(int x, int y, Jeton jeton)
{
	if(parcourtLigne(x,y,jeton) == true)
		return true;
	if(parcourtColonne(x,y,jeton) == true)
		return true;
	if(parcourtDiagonaleD(x,y,jeton) == true)
		return true;
	if(parcourtDiagonaleG(x,y,jeton) == true)
		return true;
	return false;	
}


/*Verifier s'il y a un gagnant, et annoncer le perdant, et si aucun : egalite. */
Couleur Plateau::verificationGagnant(int place,Jeton jeton)
{
	if(isPlein() == true)
		return PERSONNE;
	else
	{
			if(isWinner(place,LIGNE-_nbJeton[place],jeton) == true)
				return jeton.getCouleurJeton();
			else
				return LIBRE;
	}
}
