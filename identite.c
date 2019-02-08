#include <stdio.h>
#include <stdlib.h>
#include "identite.h"

//BUT : Ajoute les donn�es entr�es par l'utilisateur dans le fichier texte
//ENTREE : saisies utilisateur
//SORTIE : donn�es inscrites dans le fichier texte
void ajoutIdentite(FILE *fic, int *pId)
{
    //r�cup�ration du num�ro d'id dans le fichier texte
    fseek(fic, -3, SEEK_END);
    fscanf(fic,"%d",&*pId);
    *pId+=1;
    printf("%d\n",*pId);

    tIdentite identite;
    fic = fopen("cartes.txt","a");

    //SAISIE DES DONNEES
    printf("Veuillez entrer votre nom\n");
    fgets(identite.sNom, TAILLE, stdin);
    fflush(stdin);

    printf("Veuillez entrer votre prenom\n");
    fgets(identite.sPrenom, TAILLE, stdin);
    fflush(stdin);

    printf("Veuillez entrer votre adresse\n");
    fgets(identite.sAdresse, TAILLE, stdin);
    fflush(stdin);

    printf("Veuillez entrer votre ville\n");
    fgets(identite.sVille, TAILLE, stdin);
    fflush(stdin);

    printf("Veuillez entrer votre code postal\n");
    scanf("%d",&identite.nCodePostal);
    fflush(stdin);

    //ECRITURE FICHIER
    fputs("----------\n",fic);
    fprintf(fic,"%s",identite.sNom);
    fprintf(fic,"%s",identite.sPrenom);
    fprintf(fic,"%s",identite.sAdresse);
    fprintf(fic,"%s",identite.sVille);
    fprintf(fic,"%d\n",identite.nCodePostal);
    if (*pId<10)
    {
        fprintf(fic,"00%d\n",*pId);
    }
    else if ((*pId<100) && (*pId>=10))
    {
        fprintf(fic,"0%d\n",*pId);
    }
    else if (*pId>=100)
    {
        fprintf(fic,"%d\n",*pId);
    }
    fic = fopen("cartes.txt","a+");
}

//BUT : Menu de l'utilisateur lui permettant d'entrer des donn�es, de les lire ou de quitter le programme
//ENTREE : saisie utilisateur
//SORTIE : proc�dure correspondante
void menu(FILE *fic, int *pId)
{
    int nSaisie;
    while (nSaisie!=0)
    {
        printf("Tapez : \n1 pour creer un nouvel ID.\n2 pour afficher les ID deja entres.\n0 pour quitter.\n");
        scanf("%d",&nSaisie);
        fflush(stdin);
        switch(nSaisie)
        {
            case 1 :
                ajoutIdentite(fic,&*pId);
                break;
            case 2 :
                lireIdentite(fic);
                break;
            default :
                break;
        }
    }
}

//BUT : lire les donn�es entr�es, qui se situent dans le fichier texte "carte"
// ENTREE : fichier texte
//SORTIE : donn�es affich�es sur la console
void lireIdentite(FILE *fic)
{
    char ch;
    fic = fopen("cartes.txt","r");
    while((ch = fgetc(fic)) != EOF)
        printf("%c",ch);
    fic = fopen("cartes.txt","a+");
}
