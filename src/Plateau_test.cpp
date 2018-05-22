#include <CppUTest/CommandLineTestRunner.h>
#include "Plateau.hpp"
#include <sstream>

TEST_GROUP(GroupPlateau) { };

/*Test ajouter Jeton*/
TEST(GroupPlateau, TestPlateau_1) 
{
	Plateau p;
	Couleur c=ROUGE;
	p.ajouterJeton(3,c);
	CHECK_EQUAL(p.getJetonPlateau(3,LIGNE-1).getCouleurJeton(),ROUGE);
}

/*Test ajouter 2 Jeton*/
TEST(GroupPlateau, TestPlateau_2) 
{
	Plateau p;
	Couleur c=ROUGE;
	Couleur j=JAUNE;
	p.ajouterJeton(3,c);
	p.ajouterJeton(3,j);
	CHECK_EQUAL(p.getJetonPlateau(3,LIGNE-1).getCouleurJeton(),ROUGE);
	CHECK_EQUAL(p.getJetonPlateau(3,LIGNE-2).getCouleurJeton(),JAUNE);
}


/*Test ajouter TROP Jeton*/
TEST(GroupPlateau, TestPlateau_3) 
{
	Plateau p;
	Couleur c=ROUGE;
	Couleur j=JAUNE;
	try{
			p.ajouterJeton(3,c);
			p.ajouterJeton(3,j);
			p.ajouterJeton(3,c);
			p.ajouterJeton(3,j);
			p.ajouterJeton(3,c);
			p.ajouterJeton(3,j);
			p.ajouterJeton(3,c);
			p.ajouterJeton(3,j);
			FAIL("N'a pas lancée d'exception!");
		}
		catch (std::string& e)
		{
			CHECK_EQUAL(e,"PAS DE PLACE !");
		}
		

}

/*Test indice incorecte Jeton*/
TEST(GroupPlateau, TestPlateau_4) 
{
	Plateau p;
	Couleur c=ROUGE;
	Couleur j=JAUNE;
	try{
			p.ajouterJeton(-1,c);
			p.ajouterJeton(122,j);
			FAIL("N'a pas lancée d'exception!");
		}
		catch (std::string& e)
		{
			CHECK_EQUAL(e,"INDICE INCORECTE!");
		}
		

}


/*Test si le tableau est bien plein */
TEST(GroupPlateau, TestPlateau_5)
{
	Plateau p;
	for(int i=0;i<COLONNE;i++)
	{
		for(int j=0;j<LIGNE;j++)
		{
			p.ajouterJeton(i,ROUGE);
		}
	}
	CHECK_EQUAL(p.isPlein(),true);
	
}

/*Test si le tableau est bien vide */
TEST(GroupPlateau, TestPlateau_6)
{
	Plateau p;
	CHECK_EQUAL(p.isPlein(),false);
}

/* Return false si 4 jeton NE SONT PAS aligné sur une Ligne */
TEST(GroupPlateau, TestPlateau_7)
{
	Plateau p;
	
	p.ajouterJeton(0,ROUGE);
	p.ajouterJeton(1,ROUGE);
	p.ajouterJeton(2,JAUNE);
	p.ajouterJeton(3,ROUGE);
	p.ajouterJeton(4,ROUGE);
	
	CHECK_EQUAL(p.parcourtLigne(0,LIGNE-1,p.getJetonPlateau(0,LIGNE-1)),false);	
	
}

/* Return True si 4 jeton aligné sur une Ligne */
TEST(GroupPlateau, TestPlateau_8)
{
	Plateau p;
	
	p.ajouterJeton(0,ROUGE);
	p.ajouterJeton(1,ROUGE);
	p.ajouterJeton(2,ROUGE);
	p.ajouterJeton(3,ROUGE);
	p.ajouterJeton(4,ROUGE);
	
	CHECK_EQUAL(p.parcourtLigne(0,LIGNE-1,p.getJetonPlateau(0,LIGNE-1)),true);	
	
}

/* Return false si 4 jeton ne sont pas aligné sur une Colonne */
TEST(GroupPlateau, TestPlateau_9)
{
	Plateau p;
	
	p.ajouterJeton(1,ROUGE);
	p.ajouterJeton(1,ROUGE);
	p.ajouterJeton(1,JAUNE);
	p.ajouterJeton(1,ROUGE);
	p.ajouterJeton(1,ROUGE);
	
	CHECK_EQUAL(p.parcourtColonne(1,LIGNE-1,p.getJetonPlateau(1,LIGNE-1)),false);	
	
}

/* Return True si 4 jeton aligné sur une Colonne */
TEST(GroupPlateau, TestPlateau_10)
{
	Plateau p;
	
	p.ajouterJeton(1,ROUGE);
	p.ajouterJeton(1,ROUGE);
	p.ajouterJeton(1,ROUGE);
	p.ajouterJeton(1,ROUGE);
	p.ajouterJeton(1,ROUGE);
	
	CHECK_EQUAL(p.parcourtColonne(1,LIGNE-1,p.getJetonPlateau(1,LIGNE-1)),true);	
	
}
	
/* Return false si 4 jeton ne sont pas aligné sur une DIAGONALE DROITE */
TEST(GroupPlateau, TestPlateau_11)
{
	Plateau p;
	
	p.ajouterJeton(1,ROUGE);
	p.ajouterJeton(2,JAUNE);
	p.ajouterJeton(2,ROUGE);
	p.ajouterJeton(3,JAUNE);
	p.ajouterJeton(3,JAUNE);
	p.ajouterJeton(3,JAUNE);
	p.ajouterJeton(4,JAUNE);
	p.ajouterJeton(4,JAUNE);
	p.ajouterJeton(4,JAUNE);
	p.ajouterJeton(4,ROUGE);
	
	CHECK_EQUAL(p.parcourtDiagonaleD(1,LIGNE-1,p.getJetonPlateau(1,LIGNE-1)),false);	
	
}

/* Return true si 4 jeton aligné sur une DIAGONALE DROITE */
TEST(GroupPlateau, TestPlateau_12)
{
	Plateau p;
	
	p.ajouterJeton(1,ROUGE);
	p.ajouterJeton(2,JAUNE);
	p.ajouterJeton(2,ROUGE);
	p.ajouterJeton(3,JAUNE);
	p.ajouterJeton(3,JAUNE);
	p.ajouterJeton(3,ROUGE);
	p.ajouterJeton(4,JAUNE);
	p.ajouterJeton(4,JAUNE);
	p.ajouterJeton(4,JAUNE);
	p.ajouterJeton(4,ROUGE);
	
	CHECK_EQUAL(p.parcourtDiagonaleD(1,LIGNE-1,p.getJetonPlateau(1,LIGNE-1)),true);	
	
}
	
/* Return false si 4 jeton ne sont pas aligné sur une DIAGONALE GAUCHE */
TEST(GroupPlateau, TestPlateau_13)
{
	Plateau p;
	
	p.ajouterJeton(4,ROUGE);
	p.ajouterJeton(3,JAUNE);
	p.ajouterJeton(3,ROUGE);
	p.ajouterJeton(2,JAUNE);
	p.ajouterJeton(2,JAUNE);
	p.ajouterJeton(2,JAUNE);
	p.ajouterJeton(1,JAUNE);
	p.ajouterJeton(1,JAUNE);
	p.ajouterJeton(1,JAUNE);
	p.ajouterJeton(1,ROUGE);
	
	CHECK_EQUAL(p.parcourtDiagonaleG(4,LIGNE-1,p.getJetonPlateau(4,LIGNE-1)),false);	
	
}

/* Return true si 4 jeton aligné sur une DIAGONALE GAUCHE */
TEST(GroupPlateau, TestPlateau_14)
{
	Plateau p;
	
	p.ajouterJeton(4,ROUGE);
	p.ajouterJeton(3,JAUNE);
	p.ajouterJeton(3,ROUGE);
	p.ajouterJeton(2,JAUNE);
	p.ajouterJeton(2,JAUNE);
	p.ajouterJeton(2,ROUGE);
	p.ajouterJeton(1,JAUNE);
	p.ajouterJeton(1,JAUNE);
	p.ajouterJeton(1,JAUNE);
	p.ajouterJeton(1,ROUGE);
	
	CHECK_EQUAL(p.parcourtDiagonaleG(4,LIGNE-1,p.getJetonPlateau(4,LIGNE-1)),true);	
}
	
/* Return false si le joueur n'est pas gagant */
TEST(GroupPlateau, TestPlateau_15)
{
	Plateau p;
	
	p.ajouterJeton(1,ROUGE);
	p.ajouterJeton(2,JAUNE);
	p.ajouterJeton(2,ROUGE);
	p.ajouterJeton(3,JAUNE);
	p.ajouterJeton(3,JAUNE);
	p.ajouterJeton(3,JAUNE);
	p.ajouterJeton(4,JAUNE);
	p.ajouterJeton(4,JAUNE);
	p.ajouterJeton(4,JAUNE);
	p.ajouterJeton(4,ROUGE);
	
	CHECK_EQUAL(p.isWinner(3,LIGNE-3,p.getJetonPlateau(3,LIGNE-3)),false);	
	
}

/* Return true si le joueur est gagnant */
TEST(GroupPlateau, TestPlateau_16)
{
	Plateau p;
	
	p.ajouterJeton(1,ROUGE);
	p.ajouterJeton(2,JAUNE);
	p.ajouterJeton(2,ROUGE);
	p.ajouterJeton(3,JAUNE);
	p.ajouterJeton(3,JAUNE);
	p.ajouterJeton(3,ROUGE);
	p.ajouterJeton(4,JAUNE);
	p.ajouterJeton(4,JAUNE);
	p.ajouterJeton(4,JAUNE);
	p.ajouterJeton(4,ROUGE);
	
	
	CHECK_EQUAL(p.isWinner(3,LIGNE-3,p.getJetonPlateau(3,LIGNE-3)),true);	
}	

/* Return LIBRE si pas de gagnant */
TEST(GroupPlateau, TestPlateau_17)
{
	Plateau p;
	
	p.ajouterJeton(1,ROUGE);
	p.ajouterJeton(2,JAUNE);
	p.ajouterJeton(2,ROUGE);
	p.ajouterJeton(3,JAUNE);
	p.ajouterJeton(3,JAUNE);
	p.ajouterJeton(3,JAUNE);
	p.ajouterJeton(4,JAUNE);
	p.ajouterJeton(4,JAUNE);
	p.ajouterJeton(4,JAUNE);
	p.ajouterJeton(4,ROUGE);
	
	CHECK_EQUAL(p.verificationGagnant(3,p.getJetonPlateau(3,LIGNE-3)),LIBRE);	
	
}

/* Return la couleur du joueur gagnant si gagant */
TEST(GroupPlateau, TestPlateau_18)
{
	Plateau p;
	
	p.ajouterJeton(1,ROUGE);
	p.ajouterJeton(2,JAUNE);
	p.ajouterJeton(2,ROUGE);
	p.ajouterJeton(3,JAUNE);
	p.ajouterJeton(3,JAUNE);
	p.ajouterJeton(3,ROUGE);
	p.ajouterJeton(4,JAUNE);
	p.ajouterJeton(4,JAUNE);
	p.ajouterJeton(4,JAUNE);
	p.ajouterJeton(4,ROUGE);
	
	
	CHECK_EQUAL(p.verificationGagnant(1,p.getJetonPlateau(1,LIGNE-1)),p.getJetonPlateau(1,LIGNE-1).getCouleurJeton());	
}
	
/* Return PERSONNE si Egalite */
TEST(GroupPlateau, TestPlateau_19)
{	
	Plateau p;
	for(int i=0;i<COLONNE;i++)
	{
		for(int j=0;j<LIGNE;j++)
		{
			p.ajouterJeton(i,ROUGE);
		}
	}
	
	CHECK_EQUAL(p.verificationGagnant(4,p.getJetonPlateau(4,LIGNE-1)),PERSONNE);	
}
	
	
	
	
	
	
	
	
