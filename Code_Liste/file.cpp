#include <stdlib.h>
#include <stdio.h>
#include "file.h"

File* creerFile(int type, char* (*afficher) (Objet*), int (*comparer) (Objet*, Objet*)){
    return creerListe(type, afficher, comparer);
}

booleen fileVide(File* f){
    return listeVide(f);
}

void enfiler(File* f, Objet* objet){
    insererEnFinDeListe(f, objet);
}

Objet* defiler(File* f){
    if(fileVide(f)) return NULL;
    else return retraitEnTeteDeListe(f);
}

void listerFile(File* f){
    listerListe(f);
}

void detruireFile(File* f){
    detruireListe(f);
}

