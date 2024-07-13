#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TABLES 10
#define MAX_FIELDS 10

typedef struct
{
    char nom[50];
    char type[20];
}Champ;

typedef struct 
{
    char nom[50];
    Champ champs[MAX_FIELDS];
    int numChamps;
}Table;

Table tables[MAX_TABLES];
int numTables = 0;

void creeTable(char nom[50])
{
    if (numTables >= MAX_TABLES)
    {
        printf("Erreur: Nombre maximum de tables atteint.\n");
        
        return;
    }

    strcpy(tables[numTables].nom, nom);
    tables[numTables].numChamps = 0;
    numTables++;

    printf("table '%s' cree avec succes.\n", nom);
}

void ajouterChamp(char nomTable[50],char nomChamp[50],char typeChamp[20])
{
    int i;
    int indexTable = -1;

    for (i = 0; i < numTables; i++)
    {
        if (strcmp(tables[i].nom, nomTable) == 0)
        {
            indexTable = i;
            break;
        }
    }
    
    if (indexTable == -1)
    {
        printf("Erreur: Table '%s' introuvable.\n", nomTable);

        return;
    }

    Table* table = &tables[indexTable];
    Champ* champ = &(table -> champs[table -> numChamps]);

    strcpy(champ -> nom, nomChamp);
    strcpy(champ -> type, typeChamp);
    tables -> numChamps++;

    printf ("champ '%s' de type '%s' ajoute a la table '%s'.\n", nomChamp, typeChamp, nomTable);
}
