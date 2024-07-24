
// Fonction pour supprimer des données d'une table
void supprimer_donnees() {
    int table_index;
    printf("Selectionnez la table dans laquelle supprimer des donnees :\n");
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

    printf("Entrez la condition de suppression (par exemple, 'id = 5' ou 'nom LIKE 'Jean%'') : ");
    char condition[100];
    scanf("%s", condition);

    int deleted = 0;
    for (int i = 0; i < tables[table_index].nb_enregistre; i++) {
        int match = 1;
        for (int j = 0; j < tables[table_index].nb_champs; j++) {
            // Vérifier si la condition correspond aux données de la ligne
            if (!strstr(tables[table_index].donnees[i][j], condition)) {
                match = 0;
                break;
            }
        }
        if (match) {
            // Déplacer les autres lignes pour supprimer la ligne courante
            for (int j = i; j < tables[table_index].nb_enregistre - 1; j++) {
                for (int k = 0; k < tables[table_index].nb_champs; k++) {
                    strcpy(tables[table_index].donnees[j][k], tables[table_index].donnees[j + 1][k]);
                }
            }
            tables[table_index].nb_enregistre--;
            i--;
            deleted++;
        }
    }

    printf("%d ligne(s) supprimée(s).\n", deleted);
}