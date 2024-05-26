#include "tris.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tris.h"
// Implémentation des fonctions
void ajouter_entrainement(Athlete *athlete, const char *date, const char *event, float time) {
    if (athlete->training_count < MAX_TRAININGS) {
        Training *training = &athlete->trainings[athlete->training_count++];
        strncpy(training->date, date, MAX_DATE_LENGTH);
        strncpy(training->event, event, MAX_EVENT_LENGTH);
        training->time = time;
    } else {
        printf("Nombre maximal d'entraînements atteint.\n");
    }
}

void consulter_historique(const Athlete *athlete) {
    for (int i = 0; i < athlete->training_count; i++) {
        printf("Date: %s, Epreuve: %s, Temps: %.2f\n",
               athlete->trainings[i].date, athlete->trainings[i].event, athlete->trainings[i].time);
    }
}

void sauvegarder_entrainements(const Athlete *athlete) {
    FILE *file = fopen(athlete->nom, "w");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier pour sauvegarde.\n");
        return;
    }
    for (int i = 0; i < athlete->training_count; i++) {
        fprintf(file, "%s %s %.2f\n", athlete->trainings[i].date, athlete->trainings[i].event, athlete->trainings[i].time);
    }
    fclose(file);
}

void charger_entrainements(Athlete *athlete) {
    FILE *file = fopen(athlete->nom, "r");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier pour chargement.\n");
        return;
    }
    athlete->training_count = 0;
    while (fscanf(file, "%s %s %f", athlete->trainings[athlete->training_count].date,
                  athlete->trainings[athlete->training_count].event,
                  &athlete->trainings[athlete->training_count].time) == 3) {
        athlete->training_count++;
    }
    fclose(file);
}

float meilleure_performance(const Athlete *athlete, const char *event) {
    float best = -1;
    for (int i = 0; i < athlete->training_count; i++) {
        if (strcmp(athlete->trainings[i].event, event) == 0) {
            if (best == -1 || athlete->trainings[i].time < best) {
                best = athlete->trainings[i].time;
            }
        }
    }
    return best;
}

float pire_performance(const Athlete *athlete, const char *event) {
    float worst = -1;
    for (int i = 0; i < athlete->training_count; i++) {
        if (strcmp(athlete->trainings[i].event, event) == 0) {
            if (worst == -1 || athlete->trainings[i].time > worst) {
                worst = athlete->trainings[i].time;
            }
        }
    }
    return worst;
}

float moyenne_performance(const Athlete *athlete, const char *event) {
    float total = 0;
    int count = 0;
    for (int i = 0; i < athlete->training_count; i++) {
        if (strcmp(athlete->trainings[i].event, event) == 0) {
            total += athlete->trainings[i].time;
            count++;
        }
    }
    return count > 0 ? total / count : -1;
}

float difference_performance(const Athlete *athlete, const char *event, const char *date1, const char *date2) {
    float time1 = -1, time2 = -1;
    for (int i = 0; i < athlete->training_count; i++) {
        if (strcmp(athlete->trainings[i].event, event) == 0) {
            if (strcmp(athlete->trainings[i].date, date1) == 0) {
                time1 = athlete->trainings[i].time;
            }
            if (strcmp(athlete->trainings[i].date, date2) == 0) {
                time2 = athlete->trainings[i].time;
            }
        }
    }
    if (time1 != -1 && time2 != -1) {
        return time2 - time1;
    }
    return -1;
}

void regression_lineaire(const Athlete *athlete, const char *event, float *a, float *b) {
    float sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;
    int count = 0;

    for (int i = 0; i < athlete->training_count; i++) {
        if (strcmp(athlete->trainings[i].event, event) == 0) {
            float x = (float)i;
            float y = athlete->trainings[i].time;
            sumX += x;
            sumY += y;
            sumXY += x * y;
            sumX2 += x * x;
            count++;
        }
    }

    if (count > 0) {
        *a = (count * sumXY - sumX * sumY) / (count * sumX2 - sumX * sumX);
        *b = (sumY - *a * sumX) / count;
    } else {
        *a = 0;
        *b = 0;
    }
}