#include <stdio.h>
#include "seau.h"
#include<stdlib.h>
#include<string.h>
int main() {

    //=========VariableImportante============//


     int Base;

     List_de_seau listDeSeau;   //Tableau de seau//

     int nombre_de_nombre;      //Le nombre de nombre a trier

     seau Liste_initial=NULL;    //Liste initial des nombres à trier

     //Variable d'itération/divers//

     int i=0;
     char *nombre= malloc(sizeof (char)*10);
     char val[4]="525";



    //============Instruction============//

    //Etape 0 demander des nombre et les stocker dans un seau  && créer Tableau de seaux// correct

    printf("Bienvenue veuillez entrez la base dans laquelle vous voulez entrez vos nombres\n");
    scanf("%d",&Base);

    printf("==%d==",'8'-48);

    listDeSeau= creer_liste_de_seau(Base);                              //Créaction du tableau de seau

    printf("Veuillez entrez le nombre de nombre que vous voulez trier s'il vous plait ;)\n");
    scanf("%d",&nombre_de_nombre);


    Liste_initial=intialiser_liste_initial(Liste_initial,nombre_de_nombre);

    afficher_liste_initiale(Liste_initial);

    // Fin etape 0//

    //étape 1//


    for (int i = 0; i < Base; ++i) {

        listDeSeau = ajouter_au_seau_correspondant_avec_derniere_valeur_avec_liste_initial(listDeSeau, Liste_initial,0,i);
        printf("=====\n");

    }

    afficher_tout_les_seau(listDeSeau,Base);
    //Fin étape 1//

    //  Etape 2//









    printf("=============Etape2==========\n");
    //Il va falloir créer une lise permanante pour stocker les élement triéer

    for (int i = 0; i < Base; ++i) {

        listDeSeau = ajouter_au_seau_correspondant_avec_derniere_valeur(listDeSeau,listDeSeau[i],1,i);


        afficher_tout_les_seau(listDeSeau,Base);
        printf("=====\n");

    }

    afficher_tout_les_seau(listDeSeau,Base);


    return 0;
}
