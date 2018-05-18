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


