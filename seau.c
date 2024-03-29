//
// Created by simon on 20/11/2021.
//

#include <stdio.h>
#include "seau.h"
#include<stdlib.h>
#include<string.h>



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
    if(liste==NULL){
        new_elem->suivant=liste;
        return new_elem;
    }
    else
    {
        seau perm=liste;
        while (perm->suivant!=NULL){

            perm=perm->suivant;
        }
       perm->suivant=new_elem;
        return liste;
    }

}

seau intialiser_liste_initial(seau Liste_initial,int nombre_de_nombre, int taille_nombre){



    char *nombre_a_ajouter= malloc(sizeof (char)*10);

    for (int i = 0; i < nombre_de_nombre; ++i) {

        do {
            printf("Nombre numero %d \n", i);

            scanf("%s", nombre_a_ajouter);
        } while (strlen(nombre_a_ajouter)!=taille_nombre);

        printf("Nombre est %s \n",nombre_a_ajouter);
        Liste_initial=ajouter_element_queue(Liste_initial,nombre_a_ajouter);
    }

    return Liste_initial;

}


List_de_seau creer_liste_de_seau(int Base){

    List_de_seau listDeSeau=NULL;

    listDeSeau= malloc(sizeof (seau)*Base);

    for (int i = 0; i < Base; ++i) {
        listDeSeau[i]= malloc(sizeof (seau));
       listDeSeau[i]=NULL;
            }

    return listDeSeau;
}

seau supprimer_la_tete(seau Seau){


    if(Seau!=NULL){
        seau perm=Seau->suivant;
        free(Seau);
        return perm;
    }else
    {

        return NULL;
    }

}
seau supprimer_la_queue(seau Seau){
    seau temp1=Seau;
    seau temp2=Seau;
    if(Seau==NULL){
        return NULL;
    }
    if(Seau->suivant==NULL){
        free(Seau);
        return NULL;
    }
    while (temp1->suivant!=NULL){
        temp2=temp1;
        temp1=temp1->suivant;
    }
    temp2->suivant=NULL;
    free(temp1);
    return Seau;
}

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
        while (seau_courant!= NULL) {

            printf("Le nombre du seau numero : %d en postion %d vaut :%s\n", i, j, seau_courant->number);
            j++;
            seau_courant = seau_courant->suivant;
        }
        j=0;
        i++;


    }
}

seau free_seau(seau Seau){


    while (Seau!=NULL){

        Seau= supprimer_la_queue(Seau);

    }
    return Seau;

}

List_de_seau free_listedeseau(List_de_seau listDeSeau,int Base){

    for(int i=0; i < Base; i++){
        listDeSeau[i]=free_seau(listDeSeau[i]);

    }
    return listDeSeau;
}

List_de_seau mettreajourlesseau(List_de_seau listDeSeau,seau Liste_intermediaire,int Base){

    seau perm=Liste_intermediaire;
    for (int i = 0; i < Base; ++i) {

        if(strcmp(perm->number,"s")!=0) {
            while (strcmp(perm->number,"s")!=0) {
                listDeSeau[i] = ajouter_element_queue(listDeSeau[i], perm->number);
                perm = perm->suivant;
            }
        }
        perm=perm->suivant;
    }
    return listDeSeau;
}


List_de_seau ajouter_au_seau_correspondant_avec_derniere_valeur_avec_liste_initial(List_de_seau listDeSeau,seau Liste_initial,int position,int numero_seau){

    int chiffre;

    seau perm=Liste_initial;

    while (perm!=NULL){


            chiffre= convertion_char_int(perm->number[strlen(perm->number)-1]);


            listDeSeau[chiffre]=ajouter_element_queue(listDeSeau[chiffre],perm->number);


        perm=perm->suivant;
    }

    return listDeSeau;

}

seau racorder_entete(seau Seau,seau element_a_trouver){

    seau perm2=Seau;

    if(perm2==element_a_trouver){

        Seau=supprimer_la_tete(Seau);

        return Seau;
    }
    else if(perm2->suivant==NULL){
        perm2=NULL;

       return perm2;
    }
    else
    {
        while (perm2!=element_a_trouver) {//

            perm2 = perm2->suivant;
        }
        perm2=perm2->suivant;
        free(element_a_trouver);
        return Seau;
    }

}

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

