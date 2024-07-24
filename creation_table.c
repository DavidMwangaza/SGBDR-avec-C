#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "creation_table.h"


// Fonction pour créer une nouvelle table
void cree_table_donnees() {
    if (nb_tables >= NB_MAX_TABLES) {
        printf("Nombre maximum de tables atteint.\n");
        return;
    }

    printf("Nom de la nouvelle table : ");
    scanf("%s", tables[nb_tables].nom);

    printf("Nombre de champs : ");
    scanf("%d", &tables[nb_tables].nb_champs);

    for (int i = 0; i < tables[nb_tables].nb_champs; i++) {
        printf("Nom du champ %d : ", i + 1);
        scanf("%s", tables[nb_tables].fields[i].nom);

        printf("Type du champ %d (entier, chaine) : ", i + 1);
        scanf("%s", tables[nb_tables].fields[i].type);
    }

    tables[nb_tables].nb_enregistre = 0;
    nb_tables++;

    printf("Table cree avec succes.\n");
}
