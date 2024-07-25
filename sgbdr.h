#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef SGBDR_H
#define SGBDR_H


#define MAX_TABLES 10
#define MAX_FIELDS 10
#define MAX_FIELD_NAME 20
#define MAX_FIELD_TYPE 10
#define MAX_RECORDS 100

// Structure pour représenter un champ
typedef struct {
    char nom[MAX_FIELD_NAME];
    char type[MAX_FIELD_TYPE];
} Champ;

// Structure pour représenter une table
typedef struct {
    char nom[MAX_FIELD_NAME];
    Champ champs[MAX_FIELDS];
    int nombre_champs;
    int nombre_enrestre;
    char donnees[MAX_RECORDS][MAX_FIELDS][MAX_FIELD_TYPE];
} Table;

extern Table tables[MAX_TABLES];
extern int nombre_tables;

void creer_table();
void inserer_donnees();
void selectionner_donnees();
void afficher_donnees();
void supprimer_donnees();
void mettre_a_jour_donnees();
void trier_donnees();
void joindre_tables();

#endif // SGBDR_H
