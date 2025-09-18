#ifndef TABLEAU_H
#define TABLEAU_H

#include <stdio.h>
#include <stdlib.h>

// Definition de la structure tableauDynamique
typedef struct tableauDynamique
{
    int *elements; // Peut importe le type de tableau
    int taille;
    int capacite;
} tableauDynamique;

// Affiche le tableau
void afficherTableau(struct tableauDynamique *tab);

// La fonction permet d'ajouter un element entre 0 et taille
void ajouterElementA(struct tableauDynamique *tab, int index, int element);

// la fonction cree un tableau vide avec capacite
struct tableauDynamique *creerTableau(int capacite);

// La fonction supprime un element a index < 0 < taille - 1
int supprimerA(struct tableauDynamique *tab, int index);

// Ajoute un element a la fin du tableau
void ajouteFin(struct tableauDynamique *tab, int element);

// supprimer le dernier element du tableau
int supprimerFin(struct tableauDynamique *tab);

// Obtenir la valeur a l index correcte;
int get(tableauDynamique *tab, int index);

// obtenir la taille
int taille(tableauDynamique *tab);

// Libere la memoire allouee au tableau
void libererTableau(struct tableauDynamique *tab);
#endif
