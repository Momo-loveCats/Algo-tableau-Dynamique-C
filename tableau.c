#include "tableau.h"
#include <stdlib.h>
#include <stdio.h>

// Fonction main de test rapide pour verifier que mes codes marches
int main()
{
}

// Affichier tableau
void afficherTableau(tableauDynamique tab)
{
    // Parcours de tableau
    for (int i = 0; i < tab.taille; i++)
    {
        if (i == tab.taille - 1) // Pas de fleche pour le dernier element
        {
            printf("[%d]\n", tab.elements[i]);
            break;
        }
        printf("[%d] ->", tab.elements[i]);
    }
    printf("\n");
}

// Creer un tableau vide
tableauDynamique *creerTableau(int capacite)
{
    tableauDynamique *tab = malloc(sizeof(tableauDynamique));
    tab->elements = malloc(sizeof(int) * capacite);
    tab->capacite = capacite;
    tab->taille = 0;

    return tab;
}

// liberer un tableau de la memoire
void libererTableau(tableauDynamique *tab)
{
    free(tab->elements); // supprimer les element
    free(tab);           // supprimer la structure
}

// taille du tableau
int taille(tableauDynamique *tab)
{
    return tab->taille;
}

int capacite(tableauDynamique *tab)
{
    return tab->capacite;
}

// obtenir la valeur
int get(tableauDynamique *tab, int index)
{
    return tab->elements[index];
}

// normalement je dois faire un setter
// Mais bon

void ajouteFin(struct tableauDynamique *tab, int element)
{
    // si on arrive a cap doubler le tableau
    tab->taille += 1;
    if (element >= get(tab, capacite(tab)))
    {

        tableauDynamique *temp =
    }
}
