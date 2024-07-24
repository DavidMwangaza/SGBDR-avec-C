// Fonction pour sélectionner des données dans une table
void selection_donnees() {
    int table_index;
    printf("Selectionnez la table dans laquelle rechercher des donnees :\n");
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

    printf("Entrez la condition de selection (par exemple, 'id = 5' ou 'nom LIKE 'Jean%'') : ");
    char condition[100];
    scanf("%s", condition);

    printf("Resultats :\n");
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
            printf("| ");
            for (int j = 0; j < tables[table_index].nb_champs; j++) {
                printf("%s | ", tables[table_index].donnees[i][j]);
            }
            printf("\n");
        }
    }
}
