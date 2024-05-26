#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tris.h"

void afficher_menu() {
    printf("Menu:\n");
    printf("1. Ajouter un entraînement\n");
    printf("2. Consulter l'historique\n");
    printf("3. Sauvegarder les entraînements\n");
    printf("4. Charger les entraînements\n");
    printf("5. Calculer la meilleure performance\n");
    printf("6. Calculer la pire performance\n");
    printf("7. Calculer la moyenne des performances\n");
    printf("8. Calculer la différence de performance entre deux dates\n");
    printf("9. Calculer la régression linéaire\n");
    printf("0. Quitter\n");
}

int main() {
    char nom_athlete[MAX_NAME_LENGTH];
    printf("Entrez le nom de l'athlète: ");
    scanf("%s", nom_athlete);

    Athlete athlete;
    strncpy(athlete.nom, nom_athlete, MAX_NAME_LENGTH);
    athlete.training_count = 0;

    int choix;
    char date[MAX_DATE_LENGTH];
    char event[MAX_EVENT_LENGTH];
    float time;
    char date1[MAX_DATE_LENGTH];
    char date2[MAX_DATE_LENGTH];
    float a, b;

    do {
        afficher_menu();
        printf("Entrez votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Entrez la date (YYYY-MM-DD): ");
                scanf("%s", date);
                printf("Entrez l'épreuve: ");
                scanf("%s", event);
                printf("Entrez le temps: ");
                scanf("%f", &time);
                ajouter_entrainement(&athlete, date, event, time);
                break;
            case 2:
                consulter_historique(&athlete);
                break;
            case 3:
                sauvegarder_entrainements(&athlete);
                break;
            case 4:
                charger_entrainements(&athlete);
                break;
            case 5:
                printf("Entrez l'épreuve: ");
                scanf("%s", event);
                printf("Meilleure performance pour %s: %.2f\n", event, meilleure_performance(&athlete, event));
                break;
            case 6:
                printf("Entrez l'épreuve: ");
                scanf("%s", event);
                printf("Pire performance pour %s: %.2f\n", event, pire_performance(&athlete, event));
                break;
            case 7:
                printf("Entrez l'épreuve: ");
                scanf("%s", event);
                printf("Moyenne des performances pour %s: %.2f\n", event, moyenne_performance(&athlete, event));
                break;
            case 8:
                printf("Entrez l'épreuve: ");
                scanf("%s", event);
                printf("Entrez la première date (YYYY-MM-DD): ");
                scanf("%s", date1);
                printf("Entrez la deuxième date (YYYY-MM-DD): ");
                scanf("%s", date2);
                printf("Différence de performance entre %s et %s pour %s: %.2f\n", date1, date2, event,
                       difference_performance(&athlete, event, date1, date2));
                break;
            case 9:
                printf("Entrez l'épreuve: ");
                scanf("%s", event);
                regression_lineaire(&athlete, event, &a, &b);
                printf("Régression linéaire pour %s: y = %.2fx + %.2f\n", event, a, b);
                break;
            case 0:
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
                break;
        }
    } while (choix != 0);

    return 0;
}
