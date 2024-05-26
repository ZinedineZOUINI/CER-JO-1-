# CER-JO-1-
voici notre projet d'informatique pour conduire  nos athlete(e)s français(es) au medaille d'or.

# Athlete Manager

## Description

Athlete Manager est un programme en C conçu pour gérer les entraînements d'un athlète. Il permet d'ajouter des entraînements, de consulter l'historique, de sauvegarder et de charger les entraînements, et d'effectuer diverses analyses des performances.

## Structure du projet

- `main.c` : Contient la fonction principale et le menu du programme.
- `tris.h` : Définit les structures et les prototypes des fonctions.
- `athlete.c` : Implémente les fonctions de gestion des entraînements et des analyses de performance.
- `Makefile` : Automatisation de la compilation et de l'exécution du programme.

## Prérequis

- Un compilateur C (gcc recommandé).
- Make utility pour automatiser la compilation.

## Compilation et exécution

Pour compiler et exécuter le programme, suivez les étapes ci-dessous :

1. **Naviguer vers le répertoire du projet :**

   ```sh
   cd /chemin/vers/votre/projet

Compiler le programme :
make
Cette commande génère les fichiers objets et l'exécutable athlete_manager.

Exécuter le programme :
make run
Cette commande compile (si nécessaire) et exécute le programme.

Nettoyer les fichiers générés (optionnel) :
make clean
Cette commande supprime les fichiers objets et l'exécutable pour nettoyer le répertoire.

Utilisation
Lors de l'exécution, le programme affichera un menu avec les options suivantes :

Ajouter un entraînement
Consulter l'historique
Sauvegarder les entraînements
Charger les entraînements
Calculer la meilleure performance
Calculer la pire performance
Calculer la moyenne des performances
Calculer la différence de performance entre deux dates
Calculer la régression linéaire
Quitter
Suivez les instructions à l'écran pour naviguer dans le menu et utiliser les différentes fonctionnalités.
   
