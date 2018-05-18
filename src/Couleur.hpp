
/* LIBRE: Emplacement de jeton libre
 * ROUGE: Le joueur Rouge
 * JAUNE: Le joueur Jaune
 * PERSONNE: Si égalité, personne ne perd */
enum Couleur : char {LIBRE,ROUGE,JAUNE,PERSONNE};

/* Opérateur sortie */
std::ostream& operator<<(std::ostream& os,const Couleur& couleur);
/*Opérateur entrée */
std::istream& operator>>(std::istream& is,Couleur& couleur); 
