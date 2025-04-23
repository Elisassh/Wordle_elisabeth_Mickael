
# Wordle en C

Ce projet est une implémentation du jeu **Wordle** en utilisant le langage de programmation **C**. Le but du jeu est de deviner un mot secret de 5 lettres en un maximum de 6 tentatives, avec des indices à chaque essai concernant la position des lettres.

## Présentation du projet

Dans ce jeu, le joueur doit deviner un mot de 5 lettres à partir d'une liste de mots validés (tous les mots de 5 lettres dans le fichier `bdd_wordle.txt`). Chaque tentative du joueur est analysée, et des indices sont donnés :
- **Bien placé** : une lettre correcte et bien positionnée.
- **Mal placé** : une lettre correcte mais mal positionnée.
- **Non présent** : une lettre absente du mot secret.

Le jeu propose également de rejouer après chaque partie.

## Prérequis

Avant de pouvoir compiler et exécuter ce programme, assurez-vous d'avoir installé les outils suivants :
- Un compilateur **C** (par exemple, **gcc** ou **clang**).
- Un terminal ou une interface de ligne de commande.

## Fichiers du projet

Le projet comprend les fichiers suivants :
- **wordle.c** : Le code source du jeu en C.
- **bdd_wordle.txt** : Le fichier contenant la liste des mots de 5 lettres disponibles dans le jeu.

## Installation

1. **Clonez ou téléchargez le projet** :
   Si vous utilisez `git`, clonez le projet à l'aide de la commande suivante :
   
   ```bash
   git clone https://github.com/Elisassh/Wordle_elisabeth_Mickael.git
   ```

2. **Placer le fichier `bdd_wordle.txt`** :
   Assurez-vous que le fichier `bdd_wordle.txt` (contenant la liste des mots) est dans le dossier `ressource` du projet. Si le fichier n'existe pas, vous pouvez le créer manuellement ou obtenir la liste complète des mots du jeu Wordle à partir de sources publiques.

## Compilation

### Sur Linux/macOS
1. Ouvrez votre terminal dans le répertoire du projet.
2. Utilisez la commande `gcc` pour compiler le programme :
   
   ```bash
   gcc -o bin/script src/script.c
   ```

   Cette commande va compiler le fichier `wordle.c` et générer un exécutable nommé `wordle`.

## Exécution

Une fois la compilation terminée, vous pouvez exécuter le jeu en utilisant la commande suivante dans le terminal :

```bash
./bin/script
```

Le jeu va démarrer et vous serez invité à proposer un mot de 5 lettres à chaque essai. Vous aurez un maximum de 6 tentatives pour deviner le mot secret.

Si vous devinez le mot avant d'atteindre 6 tentatives, vous serez félicité ! Sinon, le mot à deviner sera révélé.

## Fonctionnalités principales

- Sélection aléatoire d'un mot parmi les mots de 5 lettres.
- Validation des mots proposés par le joueur.
- Indication des lettres bien placées et mal placées après chaque essai.
- Limitation à 6 tentatives.
- Option pour recommencer le jeu après chaque partie.

