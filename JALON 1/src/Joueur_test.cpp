#include <CppUTest/CommandLineTestRunner.h>

#include "Joueur.hpp"

#include <sstream>
using namespace std;

TEST_GROUP(GroupJoueur) { };

TEST(GroupJoueur, Joueur_1) {
  // test flux sortie
  ostringstream oss;
  oss << LIBRE;
  CHECK_EQUAL(".", oss.str());
  oss << ROUGE;
  CHECK_EQUAL(".R", oss.str());
  oss << JAUNE;
  CHECK_EQUAL(".RJ", oss.str());
}

TEST(GroupJoueur, Joueur_2) {
  // test flux entree
  istringstream iss(".RJ");
  Joueur joueur;
  iss >> joueur;
  CHECK_EQUAL(LIBRE, joueur);
  iss >> joueur;
  CHECK_EQUAL(ROUGE, joueur);
  iss >> joueur;
  CHECK_EQUAL(JAUNE, joueur);
}

