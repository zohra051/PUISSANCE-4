#include <CppUTest/CommandLineTestRunner.h>
#include "Joueur.hpp"
#include <sstream>

TEST_GROUP(GroupJoueur) { };

/*Test Constructeur sans paramètre */
TEST(GroupJoueur, TestJoueur_1) 
{
	Joueur J1;
	CHECK_EQUAL(J1.getPrenom(),"ANONYMOUS");
	CHECK_EQUAL(J1.getCouleur(),PERSONNE);
	CHECK_EQUAL(J1.getisMyTurn(),false);

}

/*Test Constructeur avec prénom*/
TEST(GroupJoueur, TestJoueur_2) 
{
	Joueur J1("Jimmy");
	
	CHECK_EQUAL(J1.getPrenom(),"Jimmy");
	CHECK_EQUAL(J1.getCouleur(),PERSONNE);
	CHECK_EQUAL(J1.getisMyTurn(),false);

}

/*Test du changement de tour*/
TEST(GroupJoueur, TestJoueur_3) 
{
	Joueur J1;
	J1.setisMyTurn();
	CHECK_EQUAL(J1.getisMyTurn(),true);
	J1.setisMyTurn();
	CHECK_EQUAL(J1.getisMyTurn(),false);
	

}

