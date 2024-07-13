#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "creation_table.h" // le fichier d'en-tete
#include "creation_table.c" // le fichier d'en-tete

int main(){
    creeTable("utilisateurs");

    ajouterChamp("utilisateurs","id","entier");
    ajouterChamp("utilisateurs","nom","chaine");
    ajouterChamp("utilisateurs","age","entier");


    // inserer les donnees dans la table ici
    return 0;
}