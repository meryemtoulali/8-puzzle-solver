#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "taquin.h"

struct Noeud* creerNoeud() {
  struct Noeud* noeud = (struct Noeud*)malloc(sizeof(struct Noeud));

  // allocate space for the 2D char array
  noeud->config = (char**)malloc(3 * sizeof(char*));
  for (int i = 0; i < 3; i++) {
    noeud->config[i] = (char*)malloc(3 * sizeof(char));
  }

  return noeud;
}

int main () {

    Liste *queue = creerListe(CROISSANT, NULL, comparerCout);
    Liste *noeuds_visites = creerListe(NULL, NULL, comparer_noeud);
    struct Noeud* noeud_array = (Noeud*) malloc(30 * sizeof(struct Noeud));
    // try
    // struct Noeud* noeud_array = (struct Noeud*) malloc(30 * sizeof(struct Noeud));
    //int curr_index = 0;

    int* position = (int*) malloc(sizeof(int)*2);

    char config_init[3][3] = {
                            {'8', '1', '3'}, 
                            {'_', '4', '5'}, 
                            {'2', '7', '6'}
                            };
    // char** config_init;
    // config_init[0][0] = '1';
    // config_init[0][1] = '2';
    // config_init[0][2] = '3';
    // config_init[1][0] = '_';
    // config_init[1][1] = '4';
    // config_init[1][2] = '6';
    // config_init[2][0] = '7';
    // config_init[2][0] = '5';
    // config_init[2][0] = '8';

    char but[3][3] = {
                        {'1', '2', '3'}, 
                        {'8', '_', '4'}, 
                        {'7', '6', '5'}
                        };
    //char config_permut[3][3];

    


    Noeud* racine = creerNoeud();
    copier(config_init, racine->config);
    racine->parent = NULL;
    racine->niveau = 0;
    racine->fval = f(racine, but);
    printf("Configuration initiale :");
    // afficher_noeud(racine);

    insererEnOrdre(queue, racine);

    while(!listeVide(queue)){

        Noeud* noeud = creerNoeud();
        noeud = (Noeud*) extraireEnTeteDeListe(queue);
        
        printf("******** NOEUD CHOISI *********\n");
        //afficher_noeud(noeud);
        insererEnTeteDeListe(noeuds_visites, noeud);

        // test but
        if(testBut(noeud->config, but)){
            printf("******** SLAYED *********\n");
            break; //move on to print but
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
                Noeud* fils = creerNoeud();
                copieridem(noeud->config, fils->config);
    //             //copier(noeud->config, config_permut);
                permuteridem(fils->config, x1, y1, x2, y2);            
    //             //permuter(config_permut, x1, y1, x2, y2);            
    //             //fils->config = config_permut;


                // si la config du fils n'a pas encore ete visitee
                // inserer fils dans la queue 
                // if(chercherUnObjet(noeuds_visites, fils) == NULL){
                //     fils->niveau = noeud->niveau + 1;
                //     fils->parent = noeud;
                //     fils->fval = f(fils, but);
                //     afficher_noeud(fils);
                //     //inserer fils dans queue
                //     insererEnOrdre(queue, fils);
                // }

                    fils->niveau = noeud->niveau + 1;
                    fils->parent = noeud;
                    fils->fval = f(fils, but);
                    //afficher_noeud(fils);
                    //inserer fils dans queue
                    insererEnOrdre(queue, fils);
                
            }

        }
    }
    
    

    //PRINT BUT
    
    Noeud* courant = (Noeud*) extraireEnTeteDeListe(noeuds_visites);
    afficher_noeud(courant);
    while(true){
        // le dernier insere est le noeud but
        if(courant->parent == NULL) break;
        afficher_noeud(courant->parent);
        
        courant = courant->parent;
    }
    

    detruireListe(noeuds_visites);
    detruireListe(queue);

    return 0;
}