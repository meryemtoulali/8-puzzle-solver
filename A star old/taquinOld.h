#include "Code_Liste\liste.h"

struct Noeud{
    //char(* config)[3];        //configuration du taquin a l'etat du noeud
    //char config[3][3];
    char **config;
    int niveau;               //profondeur ou nbr d'etapes pour atteindre le noeud
    int fval;                 //cout f = h + g
    struct Noeud* parent;     //parent du noeud, pour reconstruire le chemin
};

void   afficher_taquin   (char(*config)[3]);

void   afficher_noeud    (Noeud* noeud);

int    comparerCout      (Objet* n1, Objet* n2);

int    h                 (char(*config)[3], char(*but)[3]);

int    f                 (Noeud* noeud, char (*but)[3]);

booleen testBut(char(*config)[3], char(*but)[3]);

int*   trouver           (char(*config)[3], char x);

void   permuter          (char(*config)[3], int x1, int y1, int x2, int y2);

void   copier            (char src[3][3], char dest [3][3]);

