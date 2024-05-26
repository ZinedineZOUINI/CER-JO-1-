#ifndef TRIS_H
#define TRIS_H

#define MAX_NAME_LENGTH 50
#define MAX_EVENT_LENGTH 50
#define MAX_DATE_LENGTH 11
#define MAX_TRAININGS 100

typedef struct {
    char date[MAX_DATE_LENGTH];
    char event[MAX_EVENT_LENGTH];
    float time;
} Training;

typedef struct {
    char nom[MAX_NAME_LENGTH];
    Training trainings[MAX_TRAININGS];
    int training_count;
} Athlete;

// Prototypes des fonctions de athlete.c
void ajouter_entrainement(Athlete *athlete, const char *date, const char *event, float time);
void consulter_historique(const Athlete *athlete);
void sauvegarder_entrainements(const Athlete *athlete);
void charger_entrainements(Athlete *athlete);
float meilleure_performance(const Athlete *athlete, const char *event);
float pire_performance(const Athlete *athlete, const char *event);
float moyenne_performance(const Athlete *athlete, const char *event);
float difference_performance(const Athlete *athlete, const char *event, const char *date1, const char *date2);
void regression_lineaire(const Athlete *athlete, const char *event, float *a, float *b);

#endif // TRIS_H