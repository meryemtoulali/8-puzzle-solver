#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "taquin.h"

int count_explores = 0;

int main () {

    Liste *queue = creerListe(CROISSANT, NULL, comparer_cout);
    Liste *noeuds_visites = creerListe(NULL, NULL, comparer_noeud);

    int* position = (int*) malloc(sizeof(int)*2);

    // la configuration initiale et le but sont
    // définis dans taquin.cpp

    Noeud* racine = creer_noeud();
    injecter(config_init, racine->config);
    racine->parent = NULL;
    racine->niveau = 0;
    racine->fval = f(racine, but);

    printf("\n************* A* *************\n\n");

    printf("Configuration initiale :\n");
    afficher_noeud(racine);

    insererEnOrdre(queue, racine);
    count_explores += 1;

    printf("\n********* Exploration *********\n\n");

    while(!listeVide(queue)){

        Noeud* noeud = creer_noeud();
        noeud = (Noeud*) extraireEnTeteDeListe(queue);
        
        //printf("******** NOEUD CHOISI *********\n");
        //afficher_noeud(noeud);
        insererEnTeteDeListe(noeuds_visites, noeud);

        // test but
        if(test_but(noeud->config, but)){
            printf("But trouvé !\n");
            break;
        }
        // si pas but
        // trouver la position du vide
        position = trouver(noeud->config, '_');
        int x1 = position[0], y1 = position[1], x2, y2;
        // creer des permutations
        int permut[4][2] = {{x1, y1-1}, {x1, y1+1}, {x1-1, y1}, {x1+1, y1}};

        //printf("******** LISTE DE FILS *********\n");

        // generer les fils
        for(int i = 0; i<4; i++){
            // construire de nouvelles configurations 
            // a partir des permutations possibles
            x2 = permut[i][0]; y2 = permut[i][1];
            if((x2 >= 0) && (x2 < 3) && (y2 >=0) && (y2 < 3)){
                count_explores += 1;
                Noeud* fils = creer_noeud();
                copier(noeud->config, fils->config);
                permuter(fils->config, x1, y1, x2, y2);

                fils->niveau = noeud->niveau + 1;
                fils->parent = noeud;
                fils->fval = f(fils, but);
                //afficher_noeud(fils);
                //inserer fils dans queue
                insererEnOrdre(queue, fils); 
            }
        }
    }
    
    printf("\n%d noeuds explorés.\n", count_explores);
    
    reconstruire_chemin(noeuds_visites);
    
    detruireListe(queue);

    return 0;
}