#ifndef TABLE_H
#define TABLE_H

#define NB_MAX_TABLES 10
#define NB_MAX_CHAMPS 10
#define TAILLE_MAX_NOM_CHAMP 20
#define TAILLE_MAX_TYPE_CHAMP 10
#define MAX_NB_ENREGISTREMENT 100

// Structure pour représenter un champ
typedef struct {
    char nom[TAILLE_MAX_NOM_CHAMP];
    char type[TAILLE_MAX_TYPE_CHAMP];
} Champ;

// Structure pour représenter une table
typedef struct {
    char nom[TAILLE_MAX_NOM_CHAMP];
    Champ fields[NB_MAX_CHAMPS];
    int nb_champs;
    int nb_enregistre;
    char donnees[MAX_NB_ENREGISTREMENT][NB_MAX_CHAMPS][TAILLE_MAX_TYPE_CHAMP];
} Table;

extern Table tables[NB_MAX_TABLES];
extern int nb_tables = 0;

void cree_table_donnees();
void insertion_donnees();
void selection_donnees();
void afficher_donnees();
void supprimer_donnees();
void mise_a_jour_donnees();

#endif