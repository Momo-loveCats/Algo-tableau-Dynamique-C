#include "tableau.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Fonction main de test rapide pour verifier que mes codes marches
int main()
{
    tableauDynamique *tab = creerTableau(3);
    int valeur;
    do
    {
        printf("Donner une valeur et 0 pour quiiter : ");
        scanf("%i", &valeur);
        ajouterElementA(tab, 0, valeur);
        afficherTableau(tab);
        if (valeur == 0)
        {
            break;
        }
    } while (true);

    do
    {
        printf("supprime le dernier : ");
        scanf("%i", &valeur);
        supprimerFin(tab);
        afficherTableau(tab);
    } while (estVide(tab) == false);

    libererTableau(tab);
    printf("FIN --------\n");
}

// Affichier tableau creer
void afficherTableau(tableauDynamique *tab)
{
    // Parcours de tableau
    for (int i = 0; i < tab->taille; i++)
    {
        if (i == tab->taille - 1) // Pas de fleche pour le dernier element
        {
            printf("[%d]\n", tab->elements[i]);
            break;
        }
        printf("[%d] ->", tab->elements[i]);
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

// est vide
bool estVide(tableauDynamique *tab)
{
    return taille(tab) == 0;
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
    if (taille(tab) >= capacite(tab))
    {
        tab->capacite *= 2;
        int *temp = malloc(sizeof(int) * tab->capacite);
        for (int i = 0; i < taille(tab) - 1; i++)
        {
            temp[i] = get(tab, i);
        }
        free(tab->elements);
        tab->elements = temp;
    }
    tab->elements[taille(tab) - 1] = element;
}

int supprimerFin(tableauDynamique *tab)
{
    int valeur = get(tab, taille(tab) - 1);
    tab->taille -= 1;
    return valeur;
}

// Ajouter des element a un index compris dans les marges jusqua tab.taille incluse
void ajouterElementA(tableauDynamique *tab, int index, int element)
{
    // le but c est d ajouter a l index et declarer le reste vers la droite
    // la taille du tableau augmente
    tab->taille += 1;
    if (taille(tab) >= capacite(tab)) // si la taille est plus grande doubler le tableau
    {
        tab->capacite *= 2; // On double la capacite
    }
    int *temp = malloc(sizeof(int) * tab->capacite); // on cree un tableau temporaire
    for (int i = 0; i < index; i++)                  // copie tous les elements avant index
    {
        temp[i] = get(tab, i);
    }
    temp[index] = element; // mettre index a sa valeur
    for (int i = index; i < taille(tab) - 1; i++)
    {
        temp[i + 1] = get(tab, i);
    }
    free(tab->elements);
    tab->elements = temp;
}
