# Indiquer le compilateur à utiliser
CC = gcc

# Options de compilation
CFLAGS = -Wall -Wextra -std=c99

# Les fichiers objets à générer
OBJ = main.o athlete.o

# Nom de l'exécutable à créer
EXEC = athlete_manager

# Règle par défaut (ce qui est exécuté en appelant simplement "make")
all: $(EXEC)

# Règle pour créer l'exécutable
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)

# Règle pour compiler main.c en main.o
main.o: main.c
	$(CC) $(CFLAGS) -c main.c

# Règle pour compiler athlete.c en athlete.o
athlete.o: athlete.c
	$(CC) $(CFLAGS) -c athlete.c

# Règle pour nettoyer les fichiers générés
clean:
	rm -f $(OBJ) $(EXEC)

# Règle pour exécuter le programme
run: $(EXEC)
	./$(EXEC)
