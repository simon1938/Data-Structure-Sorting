//
// Created by simon on 20/11/2021.
//

#include <stdio.h>
#include "seau.h"
#include<stdlib.h>
#include<string.h>

//Fonction sur les seau//

Nombre dernier_nombre(seau Seau){

    seau perm=Seau;

    while (perm->suivant!=NULL){

        perm=perm->suivant;

    }

    return perm->number;

}


seau ajouter_element_tete(seau liste, char *val){

    Element *new_elem= malloc(sizeof (Element));


    strcpy(new_elem->number,val);
    new_elem->suivant=liste;

    return new_elem ;
}

seau ajouter_element_queue(seau liste,char *val){

    Element *new_elem= malloc(sizeof (Element));
    strcpy(new_elem->number,val);
    new_elem->suivant=NULL;
    if(liste->suivant==NULL){
        new_elem->suivant=liste;
        return new_elem;
    }
    else
    {
        seau perm=liste;
        while (perm->suivant->suivant!=NULL){

            perm=perm->suivant;
        }
        new_elem->suivant=perm->suivant;
        perm->suivant=new_elem;
        return liste;
    }

}

seau intialiser_liste_initial(seau Liste_initial,int nombre_de_nombre){



    char *nombre_a_ajouter= malloc(sizeof (char)*10);

    for (int i = 0; i < nombre_de_nombre; ++i) {
        printf("Nombre numero %d \n",i);
        scanf("%s",nombre_a_ajouter);
        printf("Nombre est %s \n",nombre_a_ajouter);
        Liste_initial=ajouter_element_tete(Liste_initial,nombre_a_ajouter);
    }



    return Liste_initial;

}

//fonction sur les List_de_seau
List_de_seau creer_liste_de_seau(int Base){

    List_de_seau listDeSeau=NULL;

    listDeSeau= malloc(sizeof (seau)*Base);

    for (int i = 0; i < Base; ++i) {
        listDeSeau[i]= malloc(sizeof (seau));
        listDeSeau[i]->suivant=NULL;
        strcpy(listDeSeau[i]->number,"0");
    }

    return listDeSeau;
}

seau supprimer_la_tete(seau Seau){

    seau perm=Seau;

    if(Seau!=NULL){
        perm=Seau->suivant;
        free(Seau);
        return perm;
    }else
    {
        Seau=NULL;
        return Seau;
    }

}

//Procédure

void afficher_liste_initiale(seau Liste_initial){
    int i=0;
    seau perm=Liste_initial;
    while(perm!=NULL){

        printf("Le nombre %d vaut : %s\n",i,perm->number);
        perm=perm->suivant;
        i++;
    }


}
void afficher_un_seau(List_de_seau listDeSeau,int numero_seau){

    int i=0;
    List_de_seau perm=listDeSeau;

    while(perm[numero_seau]!=NULL){

        printf("Le nombre %d vaut : %s\n",i,perm[numero_seau]->number);

        perm[numero_seau]=perm[numero_seau]->suivant;
        i++;
    }




}

void afficher_tout_les_seau(List_de_seau listDeSeau,int base){
    int i=0;
    int j=0;
    seau seau_courant;

    while(i<base) {
        seau_courant=listDeSeau[i];
        while (seau_courant->suivant != NULL) {

            printf("Le nombre du seau numero : %d en postion %d vaut :%s\n", i, j, seau_courant->number);
            j++;
            seau_courant = seau_courant->suivant;
        }
        j=0;
        i++;

    }
}


List_de_seau ajouter_au_seau_correspondant_avec_derniere_valeur_avec_liste_initial(List_de_seau listDeSeau,seau Liste_initial,int position,int numero_seau){

    int taille;

    seau perm=Liste_initial;




    while (perm!=NULL){

        taille=strlen(perm->number)-1-position;

        if(perm->number[taille]==numero_seau+48){
        //    printf("le nombre est bon %s\n",perm->number);

            listDeSeau[numero_seau]=ajouter_element_tete(listDeSeau[numero_seau],perm->number);
        }else{

            //    printf("le nombre est pas bon \n");
        }

        perm=perm->suivant;
    }

    return listDeSeau;

}

seau racorder_entete(seau Seau,seau element_a_trouver){

    seau perm2=Seau;
     printf("%d,%d %d\n",perm2,element_a_trouver,Seau);


    if(perm2==element_a_trouver){

        //supprimer en tete
        Seau=supprimer_la_tete(Seau);

        printf("on cherche1\n");
          /*
        printf("%d",Seau->number);
        printf("%d",Seau->suivant);
         */
        return Seau;//1645 5421 1987 9852 0054
    }
    else if(perm2->suivant==NULL){
        perm2=NULL;
        free(element_a_trouver->suivant);
         printf("on cherche2\n");
       return perm2;
    }
    else
    {
        while (perm2->suivant!=element_a_trouver) {//

              printf("on cherche\n");

            perm2 = perm2->suivant;
        }
       // printf("on cherche\n");
        perm2->suivant=perm2->suivant->suivant;//
        free(element_a_trouver);
        return Seau;//


    }



}






List_de_seau ajouter_au_seau_correspondant_avec_derniere_valeur(List_de_seau listDeSeau,seau Liste_initial,seau liste_transition,int position,int numero_seau,int Base){

    int position_souhaiter;
    int chiffre_viser;
    seau pointeur_temporaire=NULL;

    seau perm=Liste_initial;
    Nombre nombre_copier= malloc(sizeof (char)*10);
    // List_de_seau perm2=listDeSeau;


    while (perm->suivant!=NULL){

        position_souhaiter=strlen(perm->number)-1-position;
        if(position_souhaiter<0){
            position_souhaiter=0;
        }
        chiffre_viser=convertion_char_int(perm->number[position_souhaiter]);


        if(position_souhaiter>=0&&chiffre_viser!=numero_seau){

            printf("le nombre %s est changeable Chiffre rechercher %d Postion dans nombre : %d Tour numero Seau : %d \n",perm->number,chiffre_viser,position_souhaiter,numero_seau);
            strcpy(nombre_copier,perm->number);
            //supprimer l'element de tete de la perm et en suite...

            listDeSeau[numero_seau]=racorder_entete(listDeSeau[numero_seau],perm);
            perm=listDeSeau[numero_seau];
            liste_transition= ajouter_element_queue(liste_transition,nombre_copier);





            //le remplacer
        }else{

            printf("le nombre est pas bon \n");
            perm=perm->suivant;
        }


        printf("=====Vérif\n");
        afficher_tout_les_seau(listDeSeau,Base);
        printf("=====Fin_Vérif\n");
    }
    liste_transition= ajouter_element_queue(liste_transition,"seau");
     afficher_liste_initiale(liste_transition);//probleme avec le fait que le pointeur est remplacer peut etre obliger de faire avec tableau... a voir
    printf("Fin du prem tour %d\n",numero_seau);

    return listDeSeau;

}



//divers

int convertion_char_int(char character) {
    int result = -1;
    if(character=='0'){
        return 0;
    }
    if( character > 48 && character < 58) {
        result = character - 48; //les chiffres de 0 à 9 sont les caractères 48 à 57 du code ASCII
    } else if( character > 96 && character < 103){
        result = character - 96 + 10; //les lettres de l'alphabet majuscules sont les caractères 97 (a) à 122 (z) du code ASCII.
    } else if ( character > 64 && character < 71 ) {
        result = character - 64 + 10; //les lettres de l'alphabet majuscules sont les caractères 65 (A) à 90 (Z) du code ASCII.
    } else if ( character == '\0') {
        result = 0;
    }
    return result;
}

