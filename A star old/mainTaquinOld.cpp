#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "taquin.h"



int main () {

    Liste *queue = creerListe(CROISSANT, NULL, comparerCout);
    Liste *noeuds_visites = creerListe(NULL, NULL, NULL);
    struct Noeud* noeud_array = (Noeud*) malloc(30 * sizeof(struct Noeud));
    // try
    // struct Noeud* noeud_array = (struct Noeud*) malloc(30 * sizeof(struct Noeud));
    int curr_index = 0;

    int* position = (int*) malloc(sizeof(int)*2);

    char config_init[3][3] = {{'1', '2', '3'}, 
                        {'_', '4', '6'}, 
                        {'7', '5', '8'}
                        };
    char but[3][3] = {{'1', '2', '3'}, 
                        {'4', '5', '6'}, 
                        {'7', '8', '_'}
                        };
    char config_permut[3][3];






// HERE HERE HERE HERE HERE *****
    // Noeud* racine = (Noeud*) malloc(sizeof(Noeud));
    // racine->config = config_init;
    // racine->parent = NULL;
    // racine->niveau = 0;
    // racine->fval = f(racine, but);
    // printf("Configuration initiale :");
    // afficher_taquin(racine->config);
    // afficher_noeud(racine);

    // insererEnOrdre(queue, racine);

    // while(!listeVide(queue)){
        
   
    //     Noeud* noeud = (Noeud*) malloc(sizeof(Noeud));
    //     noeud = (Noeud*) extraireEnTeteDeListe(queue);
        
    //     printf("******** NOEUD CHOISI *********\n");
    //     afficher_noeud(noeud);
    //     insererEnTeteDeListe(noeuds_visites, noeud);

    //     // test but
    //     if(testBut(noeud->config, but)){
    //         printf("******** SLAYED *********\n");
    //         return 0;
    //     }
    //     // si pas but
    //     // trouver la position du vide
    //     position = trouver(noeud->config, '_');
    //     int x1 = position[0], y1 = position[1], x2, y2;
    //     // creer des permutations
    //     int permut[4][2] = {{x1, y1-1}, {x1, y1+1}, {x1-1, y1}, {x1+1, y1}};

    //     printf("******** LISTE DE FILS *********\n");

    //     // generer les fils
    //     for(int i = 0; i<4; i++){
    //         // construire de nouvelles configurations 
    //         // a partir des permutations possibles
    //         x2 = permut[i][0]; y2 = permut[i][1];
    //         if((x2 >= 0) && (x2 < 3) && (y2 >=0) && (y2 < 3)){
    //             Noeud* fils = (Noeud*) malloc(sizeof(Noeud));
    //             copier(noeud->config, fils->config);
    //             //copier(noeud->config, config_permut);
    //             permuter(fils->config, x1, y1, x2, y2);            
    //             //permuter(config_permut, x1, y1, x2, y2);            
    //             //fils->config = config_permut;
    //             fils->niveau = noeud->niveau + 1;
    //             fils->parent = noeud;
    //             fils->fval = f(fils, but);
    //             afficher_noeud(fils);
    //             //inserer fils dans queue
    //             insererEnOrdre(queue, fils);
    //         }

    //     }
    // }
    // detruireListe(queue);
    // detruireListe(noeuds_visites);


    return 0;
}