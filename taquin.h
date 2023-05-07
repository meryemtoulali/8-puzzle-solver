#include "Code_Liste\liste.h"

extern char config_init[3][3];
extern char but[3][3];

struct Noeud{
    //char(* config)[3];        
    //char config[3][3];
    char **config;            //configuration du taquin a l'etat du noeud
    int niveau;               //profondeur ou nbr d'etapes pour atteindre le noeud
    int fval;                 //cout f = h + g
    struct Noeud* parent;     //parent du noeud, pour reconstruire le chemin
};

struct Noeud* creer_noeud();

void   afficher_taquin   (char** config);

void   afficher_noeud    (Noeud* noeud);

booleen comparer_noeud   (Objet* n1, Objet* n2);

int    comparer_cout     (Objet* n1, Objet* n2);

int    h                 (char(*config)[3], char(*but)[3]);

int    f                 (Noeud* noeud, char (*but)[3]);

booleen test_but         (char** config, char(*but)[3]);

int*   trouver           (char** config, char x);

void   permuter          (char** config, int x1, int y1, int x2, int y2);

void   injecter          (char (*src)[3], char** dest);

void   copier            (char** src, char** dest);

void   reconstruire_chemin(Liste* noeuds_visites);

