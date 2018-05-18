#include <CppUTest/CommandLineTestRunner.h>
#include "Jeton.hpp"
#include <sstream>

TEST_GROUP(GroupJeton) { };

/* Test si le jeton est Libre */
TEST(GroupJeton, TestJeton_1) 
{
	Jeton jeton;
	std::ostringstream oss;
	oss << jeton;
	CHECK_EQUAL(oss.str(),".");

}

/*Test si le joueur est Rouge */
TEST(GroupJeton, TestJeton_2) 
{
	Jeton jeton;
	Couleur couleur = ROUGE;
	jeton.setCouleur(couleur);
	std::ostringstream oss;
	oss << jeton;
	CHECK_EQUAL(oss.str(),"R");

}

/*Test si le joueur est Jaune */
TEST(GroupJeton, TestJeton_3) 
{
Jeton jeton;
	Couleur couleur = JAUNE;
	jeton.setCouleur(couleur);
	std::ostringstream oss;
	oss << jeton;
	CHECK_EQUAL(oss.str(),"J");

}

/*Test s'il y a aucun gagnant */
TEST(GroupJeton, TestJeton_4) 
{
	Jeton jeton;
	Couleur couleur = PERSONNE;
	jeton.setCouleur(couleur);
	std::ostringstream oss;
	oss << jeton;
	CHECK_EQUAL(oss.str(),"X");

}
