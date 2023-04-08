#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "taquin.h"


struct Noeud* creer_noeud() {
  struct Noeud* noeud = (struct Noeud*)malloc(sizeof(struct Noeud));

  // allocate space for the 2D char array
  noeud->config = (char**)malloc(3 * sizeof(char*));
  for (int i = 0; i < 3; i++) {
    noeud->config[i] = (char*)malloc(3 * sizeof(char));
  }

  return noeud;
}

void afficher_taquin(char** config){
    int i;
    int j;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            printf("%c ", config[i][j]);
        }
        printf("\n");
    }
}

void afficher_noeud(Noeud* noeud){
    printf("\nConfig :\n");
    afficher_taquin(noeud->config);
    //printf("niveau parent : %d\n", noeud->parent->niveau);
    printf("niveau : %d\n", noeud->niveau);
    printf("fval = %d\n", noeud->fval);
}

booleen comparer_noeud   (Objet* n1, Objet* n2){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(((Noeud*) n1)->config[i][j] != ((Noeud*) n2)->config[i][j])
                return false;
        }
    }
    return true;
}

int comparer_cout(Objet* n1, Objet* n2){
    return ((Noeud*)n1)->fval - ((Noeud*)n2)->fval;
}

int h(char** config, char(*but)[3]){
    int count = 0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(config[i][j] != but[i][j])
                count++;
        }
    }
    return count;
}

int f(Noeud* noeud, char (*but)[3]){
    return noeud->niveau + h(noeud->config, but);
}

booleen test_but(char** config, char(*but)[3]){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(config[i][j] != but[i][j])
                return false;
        }
    }
    return true;
}

/*
generer_fils(noeud parent) returns tableau de noeuds
    set: config, niveau(niveau parent + 1), fval = 0, parent = parent noeud
(needs find, shuffle, copy)
*/


int* trouver(char** config, char x){
    int* position = (int*) malloc(sizeof(int)*2);
    //position = {NULL};
    // x could be "_";
    for(int i=0; i < 3; i++){
        for(int j=0; j<3; j++){
            if(config[i][j] == x){
                position[0] = i;
                position[1] = j;
                return position;
            }
        }
    }
    return position;
}

void permuter(char** config, int x1, int y1, int x2, int y2) {
    // va modifier config!
    if(x2 >= 0 && x2 < 3 && y2 >= 0 && y2 < 3){
        char temp = config[x2][y2];
        config[x2][y2] = config[x1][y1];
        config[x1][y1] = temp;
    }
}

void injecter(char (*src)[3], char** dest){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            dest[i][j] = src[i][j];
        }
    }
}

void copier(char** src, char** dest){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            dest[i][j] = src[i][j];
        }
    }
}



void reconstruire_chemin(Liste* noeuds_visites){    
    Liste *chemin = creerListe(NULL, NULL, NULL);
    // courant = but
    Noeud* courant = (Noeud*) extraireEnTeteDeListe(noeuds_visites);

    // remonter depuis le noeud but en utilisant noeud->parent
    // va reconstruire le chemin mais dans l'ordre inverse
        
    while(true){
        // remplir chemin dans le bon ordre
        insererEnTeteDeListe(chemin, courant);
        if(courant->parent == NULL) break;
        courant = courant->parent;
    }

    // afficher le chemin dans l'ordre correct
    printf("\n********** Solution **********\n");
    while(!listeVide(chemin)){
        // le dernier insere est le noeud but
        courant = (Noeud*) extraireEnTeteDeListe(chemin);
        afficher_noeud(courant);
    }    
    detruireListe(chemin);
}


