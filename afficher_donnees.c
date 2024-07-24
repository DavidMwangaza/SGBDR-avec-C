#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "creation_table.h"

// Fonction pour afficher les données d'une table
void afficher_donnees() {
    int table_index;
    printf("Selectionnez la table a afficher :\n");
    for (int i = 0; i < nb_tables; i++) {
        printf("%d. %s\n", i + 1, tables[i].nom);
    }
    printf("Votre choix : ");
    scanf("%d", &table_index);
    table_index--;

    if (table_index < 0 || table_index >= nb_tables) {
        printf("Table non valide.\n");
        return;
    }

    printf("Table %s :\n", tables[table_index].nom);
    printf("| ");
    for (int i = 0; i < tables[table_index].nb_champs; i++) {
        printf("%s | ", tables[table_index].fields[i].nom);
    }
    printf("\n");

    for (int i = 0; i < tables[table_index].nb_enregistre; i++) {
        printf("| ");
        for (int j = 0; j < tables[table_index].nb_champs; j++) {
            printf("%s | ", tables[table_index].donnees[i][j]);
        }
        printf("\n");
    }
}