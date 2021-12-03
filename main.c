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
char Base1;

    //Etape 0 demander des nombre et les stocker dans un seau  && créer Tableau de seaux// correct

    printf("Bienvenue veuillez entrez la base dans laquelle vous voulez entrez vos nombres\n");
    scanf("%d",&Base);

    printf("Veuillez entrez le nombre de nombre que vous voulez trier s'il vous plait ;)\n");
    scanf("%d",&nombre_de_nombre);



    listDeSeau= creer_liste_de_seau(Base);                             //Créaction du tableau de seau


    printf("Veuillez entrez la taille de chaque nombre  s'il vous plait ;)\n");
    scanf("%d",&taille_nombre);


    Liste_initial=intialiser_liste_initial(Liste_initial,nombre_de_nombre);

    afficher_liste_initiale(Liste_initial);



    printf("===========Etape 1 ===============\n");

       listDeSeau = ajouter_au_seau_correspondant_avec_derniere_valeur_avec_liste_initial(listDeSeau, Liste_initial,0,i);

        afficher_tout_les_seau(listDeSeau,Base);

    printf("==============fin Etape1==========\n\n");


    printf("=============deuxieme partie==========\n");

//variablenessesaire //
    int position;
    int position_souhaiter;
    int chiffre_viser;
    seau Liste_intermediaire=NULL;
   //variablenessesaire //

    for ( position = 1; position < taille_nombre; ++position) {

        for (int numero_maj = 0; numero_maj < Base; ++numero_maj) {
            for (int numero_seau = 0; numero_seau < Base; ++numero_seau) {


                seau perm = listDeSeau[numero_seau];
                Nombre nombre_copier = malloc(sizeof(char) * 10);
                // List_de_seau perm2=listDeSeau;


                while (perm != NULL) {

                    position_souhaiter = strlen(perm->number) - 1 - position;
                    if (position_souhaiter < 0) {

                        return 450;
                    }
                    chiffre_viser = convertion_char_int(perm->number[position_souhaiter]);


                    if (chiffre_viser == numero_maj) {

                        Liste_intermediaire = ajouter_element_queue(Liste_intermediaire, perm->number);

                    }
                    perm = perm->suivant;

                    //afficher_tout_les_seau(listDeSeau, Base);

                }

               // printf("Fin du prem tour %d\n", numero_seau);


            }
            Liste_intermediaire = ajouter_element_queue(Liste_intermediaire, "s");
            printf("===aie%d===\n",numero_maj);

        }
        printf("===testttt\n");
        afficher_liste_initiale(Liste_intermediaire);
        printf("===testttt=\n");
       listDeSeau= free_listedeseau(listDeSeau,Base);
        listDeSeau=mettreajourlesseau(listDeSeau,Liste_intermediaire,Base);
        Liste_intermediaire=free_seau(Liste_intermediaire);
        afficher_tout_les_seau(listDeSeau,Base);
        printf("Fin Grand Tour position vaut %d\n",position);
        printf("=============Etape%d==========\n",position);

        }
    afficher_tout_les_seau(listDeSeau,Base);

    return 0;

   }



