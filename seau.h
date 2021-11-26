//
// Created by simon on 20/11/2021.
//

#ifndef LO21_PROJET_SEAU_H
#define LO21_PROJET_SEAU_H
typedef  char *Nombre;

typedef struct elem{
    char number[10];
    struct elem *suivant;
}Element;

typedef Element* seau;

typedef seau *List_de_seau;

//==================================//

//fonction List_de_seau

List_de_seau creer_liste_de_seau(int Base);

List_de_seau ajouter_au_seau_correspondant_avec_derniere_valeur_avec_liste_initial(List_de_seau listDeSeau,seau Liste_initial,int position,int numero_seau);

List_de_seau ajouter_au_seau_correspondant_avec_derniere_valeur(List_de_seau listDeSeau,seau Liste_initial,int position,int numero_seau);

//fonction seau

seau intialiser_liste_initial(seau Liste_initial,int nombre_de_nombre);

seau ajouter_element_tete(seau liste,char *val);

Nombre dernier_nombre(seau Seau);

seau supprimer_la_tete(seau Seau);

seau racorder_entete(seau Seau,seau element_a_trouver);



//Procédure
void afficher_liste_initiale(seau Liste_initial);

void afficher_un_seau(List_de_seau listDeSeau,int numero_seau);

void afficher_tout_les_seau(List_de_seau listDeSeau,int base);


//divers

int convertion_char_int(char character);


#endif //LO21_PROJET_SEAU_H
