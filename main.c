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

     int taille_nombre;

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

    printf("Veuillez entrez la taille de chaque nombre  s'il vous plait ;)\n");
    scanf("%d",&taille_nombre);


    Liste_initial=intialiser_liste_initial(Liste_initial,nombre_de_nombre);

    afficher_liste_initiale(Liste_initial);



    // Fin etape 0//

    //étape 1//

//mise en place du tableau de seau//

    for (int i = 0; i < Base; ++i) {

        listDeSeau = ajouter_au_seau_correspondant_avec_derniere_valeur_avec_liste_initial(listDeSeau, Liste_initial,0,i);
        printf("=====\n");

    }
    afficher_tout_les_seau(listDeSeau,Base);

//mise en place du tableau de seau//

    //Fin étape 1//

    //  Etape 2//
//trie en fonction de l'avant dernier nombre//


    printf("=============Etape2==========\n");

//variablenessesaire //
    int position;
    int position_souhaiter;
    int chiffre_viser;
   //variablenessesaire //

    for ( position = 1; position < taille_nombre; ++position) {


        for (int numero_seau = 0; numero_seau < Base; ++numero_seau) {
// travaux

            seau perm = listDeSeau[numero_seau];
            Nombre nombre_copier = malloc(sizeof(char) * 10);
            // List_de_seau perm2=listDeSeau;


            while (perm->suivant != NULL) {

                position_souhaiter = strlen(perm->number) - 1 - position;
                if (position_souhaiter < 0) {
                    position_souhaiter = 0;
                }
                chiffre_viser = convertion_char_int(perm->number[position_souhaiter]);


                if (position_souhaiter >= 0 && chiffre_viser != numero_seau) {

                    printf("le nombre %s est changeable Chiffre rechercher %d Postion dans nombre : %d Tour numero Seau : %d \n",
                           perm->number, chiffre_viser, position_souhaiter, numero_seau);
                    strcpy(nombre_copier, perm->number);
                    //supprimer l'element de tete de la perm et en suite...

                    listDeSeau[numero_seau] = racorder_entete(listDeSeau[numero_seau], perm);//soucis chelou
                    perm = listDeSeau[numero_seau];
                    printf("========%d=====\n",chiffre_viser);
                    listDeSeau[chiffre_viser] = ajouter_element_queue(listDeSeau[chiffre_viser], nombre_copier);





                    //le remplacer
                } else {

                    printf("le nombre est pas bon \n");
                    perm = perm->suivant;
                }


                printf("=====Vérif\n");
                afficher_tout_les_seau(listDeSeau, Base);
                printf("=====Fin_Vérif\n");
            }

            printf("Fin du prem tour %d\n", numero_seau);


//travaux

        }
    }

  //  afficher_tout_les_seau(listDeSeau,Base);
   // afficher_liste_initiale(liste_transition);

//for w allant de 1 a base-1//


    return 0;
}





