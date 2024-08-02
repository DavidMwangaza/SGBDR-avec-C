#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inclusion du fichier d'en-tête contenant les définitions des structures et des constantes
#include "sgbdr.h"

// Déclaration des tables et du nombre de tables
Table tables[MAX_TABLES];
int nombre_tables = 0;

// Fonction pour créer une nouvelle table
void creer_table() {
    // Vérifie si le nombre maximum de tables est atteint
    if (nombre_tables >= MAX_TABLES) {
        printf("Nombre maximum de tables atteint.\n");
        return;
    }

    // Saisie du nom de la nouvelle table
    printf("Nom de la nouvelle table : ");
    scanf("%s", tables[nombre_tables].nom);

    // Saisie du nombre de champs de la nouvelle table
    printf("Nombre de champs : ");
    scanf("%d", &tables[nombre_tables].nombre_champs);

    // Saisie des informations des champs (nom et type)
    for (int i = 0; i < tables[nombre_tables].nombre_champs; i++) {
        printf("Nom du champ %d : ", i + 1);
        scanf("%s", tables[nombre_tables].champs[i].nom);

        printf("Type du champ %d (entier, chaine) : ", i + 1);
        scanf("%s", tables[nombre_tables].champs[i].type);
    }

    // Initialisation du nombre d'enregistrements à 0
    tables[nombre_tables].nombre_enrestre = 0;
    nombre_tables++;

    printf("Table cree avec succes.\n");
}

// Fonction pour insérer des données dans une table
void inserer_donnees() {
    int table_index;
    
    // Affichage des tables disponibles
    printf("Selectionnez la table dans laquelle insérer des donnees :\n");
    for (int i = 0; i < nombre_tables; i++) {
        printf("%d. %s\n", i + 1, tables[i].nom);
    }
    
    // Saisie de la table choisie
    printf("Votre choix : ");
    scanf("%d", &table_index);
    table_index--;

    // Vérification de la validité de la table choisie
    if (table_index < 0 || table_index >= nombre_tables) {
        printf("Table non valide.\n");
        return;
    }

    // Vérification si le nombre maximum de lignes est atteint pour la table choisie
    if (tables[table_index].nombre_enrestre >= MAX_RECORDS) {
        printf("Nombre maximum de lignes atteint pour cette table.\n");
        return;
    }

    // Saisie des valeurs pour chaque champ de la table choisie
    for (int i = 0; i < tables[table_index].nombre_champs; i++) {
        printf("Entrez la valeur pour le champ %s (%s) : ", 
                tables[table_index].champs[i].nom, 
                tables[table_index].champs[i].type);
        scanf("%s", tables[table_index].donnees[tables[table_index].nombre_enrestre][i]);
    }

    // Incrémentation du nombre d'enregistrements
    tables[table_index].nombre_enrestre++;
    printf("Donnees inserees avec succes.\n");
}

// Fonction pour sélectionner des données dans une table
void selectionner_donnees() {
    int table_index;
    
    // Affichage des tables disponibles
    printf("Selectionnez la table dans laquelle rechercher des donnees :\n");
    for (int i = 0; i < nombre_tables; i++) {
        printf("%d. %s\n", i + 1, tables[i].nom);
    }
    
    // Saisie de la table choisie
    printf("Votre choix : ");
    scanf("%d", &table_index);
    table_index--;

    // Vérification de la validité de la table choisie
    if (table_index < 0 || table_index >= nombre_tables) {
        printf("Table non valide.\n");
        return;
    }

    // Saisie de la condition de sélection
    printf("Entrez la condition de selection (par exemple, 'id = 5' ou 'nom LIKE 'Jean%'') : ");
    char condition[100];
    scanf("%s", condition);

    // Affichage des résultats correspondant à la condition
    printf("Resultats :\n");
    for (int i = 0; i < tables[table_index].nombre_enrestre; i++) {
        int match = 1;
        for (int j = 0; j < tables[table_index].nombre_champs; j++) {
            // Vérifier si la condition correspond aux données de la ligne
            if (!strstr(tables[table_index].donnees[i][j], condition)) {
                match = 0;
                break;
            }
        }
        if (match) {
            printf("| ");
            for (int j = 0; j < tables[table_index].nombre_champs; j++) {
                printf("%s | ", tables[table_index].donnees[i][j]);
            }
            printf("\n");
        }
    }
}

// Fonction pour afficher les données d'une table
void afficher_donnees() {
    int table_index;
    
    // Affichage des tables disponibles
    printf("Selectionnez la table a afficher :\n");
    for (int i = 0; i < nombre_tables; i++) {
        printf("%d. %s\n", i + 1, tables[i].nom);
    }
    
    // Saisie de la table choisie
    printf("Votre choix : ");
    scanf("%d", &table_index);
    table_index--;

    // Vérification de la validité de la table choisie
    if (table_index < 0 || table_index >= nombre_tables) {
        printf("Table non valide.\n");
        return;
    }

    // Affichage des données de la table choisie
    printf("Table %s :\n", tables[table_index].nom);
    printf("| ");
    for (int i = 0; i < tables[table_index].nombre_champs; i++) {
        printf("%s | ", tables[table_index].champs[i].nom);
    }
    printf("\n");

    for (int i = 0; i < tables[table_index].nombre_enrestre; i++) {
        printf("| ");
        for (int j = 0; j < tables[table_index].nombre_champs; j++) {
            printf("%s | ", tables[table_index].donnees[i][j]);
        }
        printf("\n");
    }
}

// Fonction pour supprimer des données d'une table
void supprimer_donnees() {
    int table_index;
    
    // Affichage des tables disponibles
    printf("Selectionnez la table dans laquelle supprimer des donnees :\n");
    for (int i = 0; i < nombre_tables; i++) {
        printf("%d. %s\n", i + 1, tables[i].nom);
    }
    
    // Saisie de la table choisie
    printf("Votre choix : ");
    scanf("%d", &table_index);
    table_index--;

    // Vérification de la validité de la table choisie
    if (table_index < 0 || table_index >= nombre_tables) {
        printf("Table non valide.\n");
        return;
    }

    // Saisie de la condition de suppression
    printf("Entrez la condition de suppression (par exemple, 'id = 5' ou 'nom LIKE 'Jean%'') : ");
    char condition[100];
    scanf("%s", condition);

    // Suppression des données correspondant à la condition
    int deleted = 0;
    for (int i = 0; i < tables[table_index].nombre_enrestre; i++) {
        int match = 1;
        for (int j = 0; j < tables[table_index].nombre_champs; j++) {
            // Vérifier si la condition correspond aux données de la ligne
            if (!strstr(tables[table_index].donnees[i][j], condition)) {
                match = 0;
                break;
            }
        }
        if (match) {
            // Déplacer les autres lignes pour supprimer la ligne courante
            for (int j = i; j < tables[table_index].nombre_enrestre - 1; j++) {
                for (int k = 0; k < tables[table_index].nombre_champs; k++) {
                    strcpy(tables[table_index].donnees[j][k], tables[table_index].donnees[j + 1][k]);
                }
            }
            tables[table_index].nombre_enrestre--;
            i--;
            deleted++;
        }
    }

    printf("%d ligne(s) supprimée(s).\n", deleted);
}

// Fonction pour mettre à jour des données dans une table
void mettre_a_jour_donnees() {
    int table_index;

    // Afficher la liste des tables disponibles et demander à l'utilisateur de sélectionner une table
    printf("Selectionnez la table dans laquelle mettre a jour des donnees :\n");
    for (int i = 0; i < nombre_tables; i++) {
        printf("%d. %s\n", i + 1, tables[i].nom);
    }
    printf("Votre choix : ");
    scanf("%d", &table_index);
    table_index--;

    // Vérifier si l'indice de table sélectionné est valide
    if (table_index < 0 || table_index >= nombre_tables) {
        printf("Table non valide.\n");
        return;
    }

    // Demander à l'utilisateur la condition de mise à jour
    printf("Entrez la condition de mise a jour (par exemple, 'id = 5' ou 'nom LIKE 'Jean%'') : ");
    char condition[100];
    scanf("%s", condition);

    int updated = 0;

    // Parcourir toutes les entrées de la table pour trouver celles qui correspondent à la condition
    for (int i = 0; i < tables[table_index].nombre_enrestre; i++) {
        int match = 1;
        for (int j = 0; j < tables[table_index].nombre_champs; j++) {
            // Vérifier si la condition correspond aux données de la ligne
            if (!strstr(tables[table_index].donnees[i][j], condition)) {
                match = 0;
                break;
            }
        }

        // Si une correspondance est trouvée, demander à l'utilisateur de saisir les nouvelles valeurs pour chaque champ
        if (match) {
            for (int j = 0; j < tables[table_index].nombre_champs; j++) {
                printf("Nouvelle valeur pour le champ %s (%s) : ", 
                        tables[table_index].champs[j].nom, 
                        tables[table_index].champs[j].type);

                scanf("%s", tables[table_index].donnees[i][j]);
            }
            updated++;
        }
    }

    // Afficher le nombre de lignes mises à jour
    printf("%d ligne(s) mise(s) à jour.\n", updated);
}

// Fonction pour mettre à jour des données dans une table
void mettre_a_jour_donnees() {
    int table_index;
    printf("Selectionnez la table dans laquelle mettre a jour des donnees :\n");
    for (int i = 0; i < nombre_tables; i++) {
        printf("%d. %s\n", i + 1, tables[i].nom);
    }
    printf("Votre choix : ");
    scanf("%d", &table_index);
    table_index--;

    if (table_index < 0 || table_index >= nombre_tables) {
        printf("Table non valide.\n");
        return;
    }

    printf("Entrez la condition de mise a jour (par exemple, 'id = 5' ou 'nom LIKE 'Jean%'') : ");
    char condition[100];
    scanf("%s", condition);

    int updated = 0;
    for (int i = 0; i < tables[table_index].nombre_enrestre; i++) {
        int match = 1;
        for (int j = 0; j < tables[table_index].nombre_champs; j++) {
            // Vérifier si la condition correspond aux données de la ligne
            if (!strstr(tables[table_index].donnees[i][j], condition)) {
                match = 0;
                break;
            }
        }
        if (match) {
            for (int j = 0; j < tables[table_index].nombre_champs; j++) {
                printf("Nouvelle valeur pour le champ %s (%s) : ", tables[table_index].champs[j].nom, 
                        tables[table_index].champs[j].type);
                
                scanf("%s", tables[table_index].donnees[i][j]);
            }
            updated++;
        }
    }

    printf("%d ligne(s) mise(s) à jour.\n", updated);
}

// Fonction pour trier les données d'une table
void trier_donnees() {
    int table_index;
    printf("Selectionnez la table a trier :\n");
    for (int i = 0; i < nombre_tables; i++) {
        printf("%d. %s\n", i + 1, tables[i].nom);
    }
    printf("Votre choix : ");
    scanf("%d", &table_index);
    table_index--;

    if (table_index < 0 || table_index >= nombre_tables) {
        printf("Table non valide.\n");
        return;
    }

    printf("Selectionnez le champ sur lequel trier :\n");
    for (int i = 0; i < tables[table_index].nombre_champs; i++) {
        printf("%d. %s\n", i + 1, tables[table_index].champs[i].nom);
    }
    int sort_field;
    printf("Votre choix : ");
    scanf("%d", &sort_field);
    sort_field--;

    if (sort_field < 0 || sort_field >= tables[table_index].nombre_champs) {
        printf("Champ non valide.\n");
        return;
    }

    // Implémentation du tri (par exemple, tri à bulles)
    for (int i = 0; i < tables[table_index].nombre_enrestre - 1; i++) {
        for (int j = 0; j < tables[table_index].nombre_enrestre - i - 1; j++) {
            if (strcmp(tables[table_index].donnees[j][sort_field], tables[table_index].donnees[j + 1][sort_field]) > 0) {
                // Échanger les lignes
                for (int k = 0; k < tables[table_index].nombre_champs; k++) {
                    char temp[MAX_FIELD_TYPE];
                    strcpy(temp, tables[table_index].donnees[j][k]);
                    strcpy(tables[table_index].donnees[j][k], tables[table_index].donnees[j + 1][k]);
                    strcpy(tables[table_index].donnees[j + 1][k], temp);
                }
            }
        }
    }

    printf("Table triee avec succes.\n");
}

// Fonction pour joindre des tables
void joindre_tables() {
    int table1_index, table2_index;
    printf("Selectionnez la premiere table à joindre :\n");
    for (int i = 0; i < nombre_tables; i++) {
        printf("%d. %s\n", i + 1, tables[i].nom);
    }
    printf("Votre choix : ");
    scanf("%d", &table1_index);
    table1_index--;

    if (table1_index < 0 || table1_index >= nombre_tables) {
        printf("Table non valide.\n");
        return;
    }

    printf("Selectionnez la deuxième table à joindre :\n");
    for (int i = 0; i < nombre_tables; i++) {
        if (i != table1_index) {
            printf("%d. %s\n", i + 1, tables[i].nom);
        }
    }
    printf("Votre choix : ");
    scanf("%d", &table2_index);
    table2_index--;

    if (table2_index < 0 || table2_index >= nombre_tables || table2_index == table1_index) {
        printf("Table non valide.\n");
        return;
    }

    printf("Entrez la condition de jointure (par exemple, 'table1.id = table2.id') : ");
    char condition[100];
    scanf("%s", condition);

    printf("Resultats :\n");
    for (int i = 0; i < tables[table1_index].nombre_enrestre; i++) {
        for (int j = 0; j < tables[table2_index].nombre_enrestre; j++) {
            int match = 1;
            // Vérifier si la condition de jointure est satisfaite
            if (!strstr(tables[table1_index].donnees[i][0], condition) || 
            !strstr(tables[table2_index].donnees[j][0], condition)) {
                match = 0;
            }
            if (match) {
                printf("| ");
                for (int k = 0; k < tables[table1_index].nombre_champs; k++) {
                    printf("%s | ", tables[table1_index].donnees[i][k]);
                }
                for (int k = 0; k < tables[table2_index].nombre_champs; k++) {
                    printf("%s | ", tables[table2_index].donnees[j][k]);
                }
                printf("\n");
            }
        }
    }
    // Fonction pour afficher les données d'une table
void afficher_donnees() {
    int table_index;

    // Afficher la liste des tables disponibles et demander à l'utilisateur de sélectionner une table à afficher
    printf("Selectionnez la table a afficher :\n");
    for (int i = 0; i < nombre_tables; i++) {
        printf("%d. %s\n", i + 1, tables[i].nom);
    }
    printf("Votre choix : ");
    scanf("%d", &table_index);
    table_index--;

    // Vérifier si l'indice de table sélectionné est valide
    if (table_index < 0 || table_index >= nombre_tables) {
        printf("Table non valide.\n");
        return;
    }

    // Afficher les en-têtes des champs
    printf("Table %s :\n", tables[table_index].nom);
    printf("| ");
    for (int i = 0; i < tables[table_index].nombre_champs; i++) {
        printf("%s | ", tables[table_index].champs[i].nom);
    }
    printf("\n");

    // Afficher les données de chaque ligne
    for (int i = 0; i < tables[table_index].nombre_enrestre; i++) {
        printf("| ");
        for (int j = 0; j < tables[table_index].nombre_champs; j++) {
            printf("%s | ", tables[table_index].donnees[i][j]);
        }
        printf("\n");
    }
}
    // Fonction pour supprimer des données d'une table
void supprimer_donnees() {
    int table_index;

    // Afficher la liste des tables disponibles et demander à l'utilisateur de sélectionner une table pour supprimer des données
    printf("Selectionnez la table dans laquelle supprimer des donnees :\n");
    for (int i = 0; i < nombre_tables; i++) {
        printf("%d. %s\n", i + 1, tables[i].nom);
    }
    printf("Votre choix : ");
    scanf("%d", &table_index);
    table_index--;

    // Vérifier si l'indice de table sélectionné est valide
    if (table_index < 0 || table_index >= nombre_tables) {
        printf("Table non valide.\n");
        return;
    }

    // Demander à l'utilisateur la condition de suppression
    printf("Entrez la condition de suppression (par exemple, 'id = 5' ou 'nom LIKE 'Jean%'') : ");
    char condition[100];
    scanf("%s", condition);

    int deleted = 0;

    // Parcourir les entrées de la table pour trouver celles qui correspondent à la condition
    for (int i = 0; i < tables[table_index].nombre_enrestre; i++) {
        int match = 1;
        for (int j = 0; j < tables[table_index].nombre_champs; j++) {
            // Vérifier si la condition correspond aux données de la ligne
            if (!strstr(tables[table_index].donnees[i][j], condition)) {
                match = 0;
                break;
            }
        }

        // Si une correspondance est trouvée, supprimer la ligne
        if (match) {
            // Déplacer les autres lignes pour combler le vide laissé par la suppression
            for (int j = i; j < tables[table_index].nombre_enrestre - 1; j++) {
                for (int k = 0; k < tables[table_index].nombre_champs; k++) {
                    strcpy(tables[table_index].donnees[j][k], tables[table_index].donnees[j + 1][k]);
                }
            }
            tables[table_index].nombre_enrestre--;
            i--;
            deleted++;
        }
}
