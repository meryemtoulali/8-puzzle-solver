#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "taquin.h"

booleen fin = faux;
int count_explores = 0;


void IDA_boucle(Noeud* noeud, char(*but)[3], 
    int f_limite, int* f_exces_min, 
    Liste* noeuds_visites){
    // si but, quitter
    if(test_but(noeud->config, but)){
        printf("But trouvé !\n");
        fin = vrai;
        return;
    }
    // si pas but
    
    // si le noeud surpasse limite, 
    // f_exces_min = min(fval, f_exces_min) et quitter
    if(noeud->fval > f_limite){
        if(noeud->fval < *f_exces_min){
            *f_exces_min = noeud->fval;
        }
        return;
    }

    // sinon, approfondir
    int* position = (int*) malloc(sizeof(int)*2);
    position = trouver(noeud->config, '_');
    int x1 = position[0], y1 = position[1], x2, y2;
    // creer des permutations
    int permut[4][2] = {{x1, y1-1}, {x1, y1+1}, {x1-1, y1}, {x1+1, y1}};
    // generer les fils
    for(int i = 0; i<4; i++){
        // construire de nouvelles configurations 
        // a partir des permutations possibles
        x2 = permut[i][0]; y2 = permut[i][1];
        if((x2 >= 0) && (x2 < 3) && (y2 >=0) && (y2 < 3)){
            Noeud* fils = creer_noeud();
            copier(noeud->config, fils->config);
            permuter(fils->config, x1, y1, x2, y2);            
            fils->niveau = noeud->niveau + 1;
            fils->parent = noeud;
            fils->fval = f(fils, but);
            insererEnTeteDeListe(noeuds_visites, fils);
            count_explores ++;
                        
            IDA_boucle(fils, but, f_limite, f_exces_min, noeuds_visites);
            if(fin) return;
        }
    } 
}


int main () {

    int *f_exces_min = (int*) malloc(sizeof(int)); 
    int f_limite;

    Liste *noeuds_visites = creerListe(NULL, NULL, NULL);

    char config_init[3][3] = {
                            {'8', '1', '3'}, 
                            {'_', '4', '5'}, 
                            {'2', '7', '6'}
                            };
    char but[3][3] = {
                        {'1', '2', '3'}, 
                        {'8', '_', '4'}, 
                        {'7', '6', '5'}
                        };
 
       
    Noeud* racine = creer_noeud();
    injecter(config_init, racine->config);
    racine->parent = NULL;
    racine->niveau = 0;
    racine->fval = f(racine, but);

    insererEnTeteDeListe(noeuds_visites, racine);

    printf("\n************ IDA* ************\n");

    printf("Configuration initiale :\n");
    afficher_noeud(racine);
    printf("\n");

    f_limite = racine->fval;
    printf("\n********* Exploration *********\n\n");


    while(!fin){
        *f_exces_min = 1000;
        count_explores = 0;

        printf("Nouvelle limite : %d\n", f_limite);
        // restart ida*(racine, f_limite, *f_exces_min);

        // that function should explore depth first 
        // and change the new f_limit = min (f explored)

        IDA_boucle(racine, but, f_limite, f_exces_min, noeuds_visites);
        printf("%d noeuds explorés.\n", count_explores);

        f_limite = *f_exces_min;
    }

    
    reconstruire_chemin(noeuds_visites);

    detruireListe(noeuds_visites);
    
    return 0;
}