
// Fonction principale pour afficher le menu et gérer les interactions
int main() {
    int choice;
    do {
        printf("\n--- Mini SGBDR ---\n");
        printf("1. Creer une table\n");
        printf("2. Inserer des donnees\n");
        printf("3. Selectionner des donnees\n");
        printf("4. Afficher les donnees\n");
        printf("5. Supprimer des donnees\n");
        printf("6. Mettre a jour des donnees\n");
        printf("7. Trier les donnees\n");
        printf("8. Joindre des tables\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                cree_table_donnees();
                break;
            case 2:
                insertion_donnees();
                break;
            case 3:
                selection_donnees();
                break;
            case 4:
                afficher_donnees();
                break;
            case 5:
                supprimer_donnees();
                break;
            case 6:
                mise_a_jour_donnees();
                break;
            case 7:
                trier_donnees();
                break;
            case 8:
                joindre_tables();
                break;
            case 0:
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix non valide. Veuillez reessayer.\n");
                break;
        }
    } while (choice != 0);
    return 0;
}