#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 3000
#define WORD_LENGTH 6
#define LINE_SIZE 512
#define MAX_TRIES 6


int load_wordle_words(const char* chemin, char mots[MAX_WORDS][WORD_LENGTH]) {
    FILE* fichier = fopen(chemin, "r");
    if (!fichier) {
        printf("Erreur : impossible d'ouvrir le fichier %s\n", chemin);
        return -1;
    }

    char ligne[LINE_SIZE];
    int nbMots = 0;
    int lecture_active = 0;

    while (fgets(ligne, LINE_SIZE, fichier) != NULL) {
        if (strstr(ligne, "Wordle Words List Starting With") != NULL) {
            lecture_active = 1;
            continue;
        }

        if (lecture_active && strlen(ligne) > 1) {
            char* mot = strtok(ligne, " \t\n");
            while (mot != NULL && nbMots < MAX_WORDS) {
                if (strlen(mot) == 5) {
                    strcpy(mots[nbMots++], mot);
                }
                mot = strtok(NULL, " \t\n");
            }
        }
    }

    fclose(fichier);
    return nbMots;
}


int est_valide(char mot[], char mots[][WORD_LENGTH], int nbMots) {
    for (int i = 0; i < nbMots; i++) {
        if (strcmp(mot, mots[i]) == 0){
          return 1;
          }
    }
    return 0;
}

void afficher_indice(char mot_secret[], char tentative[]) {
    for (int i = 0; i < 5; i++) {
        if (tentative[i] == mot_secret[i]) {
            printf("[ %c ]", tentative[i]); // Bien placé
        } else if (strchr(mot_secret, tentative[i]) != NULL) {
            printf("( %c )", tentative[i]); // Mal placé
        } else {
            printf("  %c  ", tentative[i]); // Pas dans le mot
        }
    }
    printf("\n");
}

int main() {
    char mots[MAX_WORDS][WORD_LENGTH];
    const char* fichier_chemin = "ressource/bdd_wordle.txt";
    int nbMots = load_wordle_words(fichier_chemin, mots);

    if (nbMots <= 0) {
        printf("Erreur lors du chargement des mots.\n");
        return 1;
    }

    srand(time(NULL));

    char choix;
    do {
        char mot_secret[WORD_LENGTH];
        strcpy(mot_secret, mots[rand() % nbMots]);

        printf("🟩 Bien placé [ ]\n🟨 Mal placé ( )\n🔁 Mot de 5 lettres à deviner !\n");

        int essais = 0;
        int gagne = 0;

        while (essais < MAX_TRIES && !gagne) {
            char tentative[WORD_LENGTH];
            printf("\nEssai %d/%d: ", essais + 1, MAX_TRIES);
            scanf("%5s", tentative);

            if (!est_valide(tentative, mots, nbMots)) {
                printf("❌ Mot invalide, réessaie sans perdre d’essai !\n");
                continue;
            }

            essais++;
            if (strcmp(tentative, mot_secret) == 0) {
                gagne = 1;
                printf("🎉 Bravo ! Tu as trouvé le mot %s en %d essais !\n", mot_secret, essais);
            } else {
                afficher_indice(mot_secret, tentative);
            }
        }

        if (!gagne) {
            printf("💀 Dommage ! Le mot était : %s\n", mot_secret);
        }

        printf("🔁 Veux-tu rejouer ? (o/n) : ");
        scanf(" %c", &choix);

    } while (choix == 'o' || choix == 'O');

    printf("Merci d'avoir joué ! 👋\n");
    return 0;
}

