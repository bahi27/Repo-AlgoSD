#include <stdio.h>
#include <stdlib.h>

// structure d'un noeud d'arbre binaire
typedef struct Node {
    int valeur;
    struct Node* gauche;
    struct Node* droite;
} Node;

// création d'un noeud
Node* creerNoeud(int valeur) {
    Node* n = malloc(sizeof(Node));
    n->valeur = valeur;
    n->gauche = NULL;
    n->droite = NULL;
    return n;
}

// insertion dans un arbre binaire de recherche (BST)
Node* inserer(Node* racine, int valeur) {
    if (racine == NULL)
        return creerNoeud(valeur);

    if (valeur < racine->valeur)
        racine->gauche = inserer(racine->gauche, valeur);
    else if (valeur > racine->valeur)
        racine->droite = inserer(racine->droite, valeur);

    return racine;
}

// fonction pour chercher une valeur dans l'arbre
int chercher(Node* racine, int valeur) {
    if (racine == NULL)
        return 0;
    if (racine->valeur == valeur)
        return 1;
    else if (valeur < racine->valeur)
        return chercher(racine->gauche, valeur);
    else
        return chercher(racine->droite, valeur);
}

int main() {
    FILE* fichier = fopen("donnees.txt", "r");
    if (!fichier) {
        printf("Erreur ouverture fichier\n");
        return 1;
    }

    int n;
    fscanf(fichier, "%d", &n);

    Node* racine = NULL;
    for (int i = 0; i < n; i++) {
        int val;
        fscanf(fichier, "%d", &val);
        racine = inserer(racine, val);
    }

    int nbCherche;
    fscanf(fichier, "%d", &nbCherche);

    printf("Résultats :\n");
    for (int i = 0; i < nbCherche; i++) {
        int val;
        fscanf(fichier, "%d", &val);
        if (chercher(racine, val))
            printf("YES\n");
        else
            printf("NO\n");
    }

    fclose(fichier);
    return 0;
}
