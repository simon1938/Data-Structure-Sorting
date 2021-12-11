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






    //============Instruction============//
do {
    printf("Bienvenue veuillez entrez la base dans laquelle vous voulez entrez vos nombres\n");
    scanf("%d", &Base);
} while (Base<2||Base>16);


    printf("Veuillez entrez le nombre de nombre que vous voulez trier s'il vous plait ;)\n");
    scanf("%d", &nombre_de_nombre);



    listDeSeau= creer_liste_de_seau(Base);                             //Créaction du tableau de seau

do {
    printf("Veuillez entrez la taille de chaque nombre  s'il vous plait ;)\n");
    scanf("%d", &taille_nombre);
} while (taille_nombre<=0||taille_nombre>10);

    Liste_initial=intialiser_liste_initial(Liste_initial,nombre_de_nombre,taille_nombre);

    printf("voici votre liste initial\n");
    afficher_liste_initiale(Liste_initial);





       listDeSeau = ajouter_au_seau_correspondant_avec_derniere_valeur_avec_liste_initial(listDeSeau, Liste_initial,0,i);

        afficher_tout_les_seau(listDeSeau,Base);

    printf("===========Etape 1 ===============\n");

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

                }

            }
            Liste_intermediaire = ajouter_element_queue(Liste_intermediaire, "s");

        }

      //  afficher_liste_initiale(Liste_intermediaire);
            listDeSeau= free_listedeseau(listDeSeau,Base);
        listDeSeau=mettreajourlesseau(listDeSeau,Liste_intermediaire,Base);
        Liste_intermediaire=free_seau(Liste_intermediaire);
        afficher_tout_les_seau(listDeSeau,Base);
       printf("=============Etape%d==========\n",position+1);

        }
    printf("Voici ci dessus votre liste de nombre triee\n");

    return 0;
   }



