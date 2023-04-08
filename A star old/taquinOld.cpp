#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "taquin.h"

void afficher_taquin(char(*config)[3]){
    int i;
    int j;
    char start[3][3] = {{'1', '2', '3'}, {'1', '2', '3'}, {'1', '2', '3'}};
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

int comparerCout(Objet* n1, Objet* n2){
    return ((Noeud*)n1)->fval - ((Noeud*)n2)->fval;
}

int h(char(*config)[3], char(*but)[3]){
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

booleen testBut(char(*config)[3], char(*but)[3]){
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


int* trouver(char(*config)[3], char x){
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

void permuter(char(*config)[3], int x1, int y1, int x2, int y2) {
    // will mutate config!
    if(x2 >= 0 && x2 < 3 && y2 >= 0 && y2 < 3){
        char temp = config[x2][y2];
        config[x2][y2] = config[x1][y1];
        config[x1][y1] = temp;
    }
}

void copier(char src[3][3], char dest [3][3]){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            dest[i][j] = src[i][j];
        }
    }
}
