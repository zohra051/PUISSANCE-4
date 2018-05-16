//JulienDehos

PUISSANCE 4 en réseau.

Jalon 1 : moteur de jeu.

Déroulement d'une partie de jeu:

Attribution des couleurs de jetons.
Joueur 1 choisis la position de son jeton.
Le jeton 'tombe' en bas de la colonne. (ne choisis pas sa position)
    Vérifiction si puissance 4?
Passe la main au joueur 2.
Même processus pour le joueur 2.

Jeton:
-Couleur
-Voisin : Tableau
getCouleur();
getVoisin();
ajouterVoisin();

Plateau: utilisation de jeton
-Plateau : Tableau 2D
-Pile : Array
ajouterJeton();
positionJeton();
afficherPlateau();
verificationJeton();
verification();
    gagnant/perdant/egalite

Joueur:
-Couleur
-Tour : flag
placerJeton();
getCouleur();
setCouleur();
notreTour();
abandonner();


Jeu:
-Joueur : 2
-Plateau 
lancerPartie();
declarerGagnant();


backlog : 
fonctionalite
diaagramme classe
issues : docs,test

