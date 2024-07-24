#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "creation_table.h" // le fichier d'en-tete
#include "creation_table.c" // le fichier d'en-tete

// Fonction pour insérer des données dans une table
void insertion_donnees() {
    int table_index;
    printf("Selectionnez la table dans laquelle insérer des donnees :\n");
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

    if (tables[table_index].nb_enregistre >= MAX_NB_ENREGISTREMENT) {
        printf("Nombre maximum de lignes atteint pour cette table.\n");
        return;
    }

    for (int i = 0; i < tables[table_index].nb_champs; i++) {
        printf("Entrez la valeur pour le champ %s (%s) : ", 
                tables[table_index].fields[i].nom, 
                tables[table_index].fields[i].type);

        scanf("%s", tables[table_index].donnees[tables[table_index].nb_enregistre][i]);
    }

    tables[table_index].nb_enregistre++;
    printf("Donnees inserees avec succes.\n");
}
