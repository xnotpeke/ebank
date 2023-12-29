#include <stdio.h>
#include <stdlib.h>
#define CMAX 10
#include <stdbool.h>
#include "Untitled1.h"
//fonction pour verifier que le client existe deja dans le fichier
int comparer (const void* a, const void* b)
{
    const Client *c1 = a ;
    const Client *c2 = b ;
    return strcmp(c1->Nom, c2->Nom);
}


Client clients[20];
Compte comptes[20];

// menu de l'application
void menu()
{
    printf("=========EBANK=========\n");
    printf("1- Gerer les clients\n");
    printf("2- Gerer les comptes\n");
    printf("3- Gerer les transactions\n");
    printf("4- Quitter \n");
    printf("Choisir le menu : ");
    scanf("%d", &choix);
    sous_menu(choix);
}

void sous_menu(int choix)
{
    switch(choix){
        //si l'utilisateur choisit de faire la gestion des clients
        case 1:

        printf("1- Ajouter un client\n");
        printf("2- Modifier le profil du client\n");
        printf("3- Supprimer un client existant\n");
        printf("4- Afficher les details d'un client \n");
        printf("5- Retour\n");
        printf("Choisir  : ");
        scanf("%d", &x);
        gerer_client(x);
        break ;

    case 2:
        //si l'utilisateur choisit de faire la gestion des comptes

        printf("1- Ajouter un compte\n");
        printf("2- Rechercher un compte existant\n");
        printf("3- Afficher la liste descomptes\n");
        printf("4- Supprimer un compte existant\n");
        printf("5- Retour\n");
        printf("Choisir : ");
        scanf("%d", &x);
        gerer_compte(x);
        break;

    case 3:
        //si l'utilisateur choisit de faire la gestion des transaction
        printf("1- Retrait\n");
        printf("2- Versement \n");
        printf("Choisir : ");
        scanf("%d", &x);
        gerer_operation(x);
        break ;

        case 4 :
        return 0;
    default :

        printf("choix invalide");


}}

void gerer_client(int choix)
{
    switch(choix){
    case 1 : ;//empty statement
        struct Client client;
        FILE *file;

        printf("Code Client : ");
        scanf("%d", &client.Code_cli);
        printf("Nom : ");
        scanf("%s", &client.Nom);
        printf("Prenom : ");
        scanf("%s", &client.Prenom);
        file = fopen("client.txt", "a");
        fwrite(&client, sizeof(client), 1, file);
        if(fwrite != 0)
            printf("client ajoute avec succes");
        else
            printf("erreur");
        fclose(file);
        break;

    case 2 : ;//empty statement

        struct Client aclient;
        struct Client nvClient;
        FILE *cfile;
        printf("Code Client a modifier : ");
        scanf("%d", &nvClient.Code_cli);
        printf("nv nom : ");
        scanf("%s", &nvClient.Nom);
        printf("nv prenom : ");
        scanf("%s", &nvClient.Prenom);
        cfile = fopen("client.txt", "r");
        int nbClients = 0;
        while(fread(&aclient, sizeof(struct Client), 1, cfile)) {
            clients[nbClients] = aclient;
            nbClients++;
        }
        fclose(cfile);
        remove("client.txt");
        FILE *nf;
        nf = fopen("nv.txt", "a");
        for ( int i=0 ; i<nbClients ; i++)
        {
            if (clients[i].Code_cli == nvClient.Code_cli)
                fwrite(&nvClient, sizeof(clients[i]), 1, nf);
            else
                fwrite(&clients[i], sizeof(clients[i]), 1, nf);
        }
        fclose(nf);
        rename("nv.txt", "client.txt");
        break;
       case 3 : ; //empty statement
        struct Client nclient;
        int code;
        FILE *nfile;
        printf("Code Client a supprimer : ");
        scanf("%d", &code);
        nfile = fopen("client.txt", "r");
        int nClients = 0;
        while(fread(&nclient, sizeof(struct Client), 1, nfile)) {
            clients[nClients] = nclient;
            nClients++;}
        fclose(nfile);
        remove("client.txt");
        FILE *anf;
        anf = fopen("nv.txt", "a");
        for ( int i=0 ; i<nClients ; i++)
        {
            if (clients[i].Code_cli != code)
                fwrite(&clients[i], sizeof(clients[i]), 1, nf);
        }
        fclose(anf);
        rename("nv.txt", "client.txt");
        break;
    case 4: ;//empty statement
        FILE *tfile;
        struct Client tclient;
        tfile = fopen("client.txt", "r");
        int nbrClients = 0;
        while(fread(&tclient, sizeof(struct Client), 1, tfile)) {
            clients[nbrClients] = tclient;
            nbrClients++;
        }
        fclose(tfile);
        qsort(clients, nbrClients, sizeof(Client), comparer);
        for (int c=0 ; c<nbrClients ; c++)
        {
            printf("\nCode client : %d", clients[c].Code_cli);
            printf("\nNom: %s | %s", clients[c].Nom, clients[c].Prenom);
            printf("\n");
        }
        break ;
    case 5 :
        menu();
        break ;
}
}

void gerer_compte(int choix){
    if (choix==1)
    {
        struct Compte compte;
        struct Compte compte0;
        FILE *file;
        FILE *fl;
        printf("Code Compte : ");
        scanf("%d", &compte.code_cpt);
        fl = fopen("compte.txt", "r");
        bool test=false;
        while(fread(&compte0, sizeof(struct Compte), 1, fl) && test==false) {
            if (compte0.code_cpt == compte.code_cpt)
                test=true;
        }
        if(test)
        {
            printf("code existant\n");
            return 0;
        }
        printf("Code Client : ");
        scanf("%d", &compte.Code_cli);
        printf("Date de creation du compte | ");
        printf("Jour : ");
        scanf("%d", &compte.d_compte.Jour);
        printf("Mois : ");
        scanf("%d", &compte.d_compte.Mois);
        printf("Annee : ");
        scanf("%d", &compte.d_compte.Annee);
        printf("Somme : ");
        scanf("%d", &compte.somme);
        file = fopen("compte.txt", "a");
        fwrite(&compte, sizeof(compte), 1, file);
        if(fwrite != 0)
            printf("compte ajouté avec succes");
        else
            printf("erreur");
    }
    else if (choix==2)
    {
        struct Compte compte;
        int code;
        FILE *file;
        printf("Code compte : ");
        scanf("%d", &code);
        file = fopen("compte.txt", "r");
        bool test=false;
        while(fread(&compte, sizeof(struct Compte), 1, file) && test==false) {
            if (compte.code_cpt == code){
                    printf("\n Code compte : %d", compte.code_cpt);
                    printf("\n Code client : %d", compte.Code_cli);
                    printf("\n Date creation %d / %d / %d", compte.d_compte.Jour, compte.d_compte.Mois, compte.d_compte.Annee);
                    printf("\n Somme %d", compte.somme);
                    test=true ;
               }
        }
        if(test)
            printf("code non existant\n");
        fclose(file);
    }
    else if (choix==3)
    {
        struct Compte compte;
        FILE *file;

        file = fopen("compte.txt", "r");

        while(fread(&compte, sizeof(struct Compte), 1, file)) {
                    printf("\n Code compte : %d", compte.code_cpt);
                    printf("\n Code client : %d", compte.Code_cli);
                    printf("\n Date creation %d / %d / %d", compte.d_compte.Jour, compte.d_compte.Mois, compte.d_compte.Annee);
                    printf("\n Somme %d", compte.somme);
                    printf("\n-----------------------------------------");
        }
        fclose(file);
    }
    else if (choix==4)
    {
        struct Compte compte;
        int code;
        FILE *file;

        printf("Code Compte a supprimer : ");
        scanf("%d", &code);

        file = fopen("compte.txt", "r");

        int nb = 0;

        while(fread(&compte, sizeof(struct Compte), 1, file)) {
            comptes[nb] = compte;
            nb++;
        }
        fclose(file);
        remove("compte.txt");

        FILE *nf;
        nf = fopen("nv.txt", "a");
        for ( int i=0 ; i<nb ; i++)
        {
            if (comptes[i].code_cpt != code)
                fwrite(&comptes[i], sizeof(comptes[i]), 1, nf);
        }
        fclose(nf);
        rename("nv.txt", "compte.txt");
    }
    else if (choix==5)
        menu();
}
void gerer_operation(int a)
{
    if (choix==1)
    {
        struct Compte compte;
        int code,m;
        FILE *file;
        printf("Code Compte : ");
        scanf("%d", &code);
        file = fopen("compte.txt", "r");
        int nb = 0;
        while(fread(&compte, sizeof(struct Compte), 1, file)) {
            comptes[nb] = compte;
            nb++;
        }
        fclose(file);
        remove("compte.txt");

        FILE *nf;
        nf = fopen("nv.txt", "a");
        for ( int i=0 ; i<nb ; i++)
        {
            if (comptes[i].code_cpt == code)
            {
                        do{
                            printf("\n montant : ");
                            scanf("%d", &m);
                            if (m>500)
                                printf("\n le montant ne doit pas depasser 500 DT");
                            solde = comptes[i].somme - m;
                            if (solde<250)
                                printf("\n le solde ne doit pas etre inferieur a 250 DT");
                        }while(m>500 || solde<250);
                comptes[i].somme = comptes[i].somme - m;
                printf("\n code compte %d", comptes[i].code_cpt);
                printf("\n code client %d", comptes[i].Code_cli);
                printf("\n nv somme : %d", comptes[i].somme);
                printf("\n Date creation %d / %d / %d", compte.d_compte.Jour, compte.d_compte.Mois, compte.d_compte.Annee);
                printf("\n-----------------------------------------");
            }
            fwrite(&comptes[i], sizeof(comptes[i]), 1, nf);
        }
        fclose(nf);
        rename("nv.txt", "compte.txt");
    }
    else if (choix==2)
    {
        struct Compte compte;
        int code1,code2,m;
        FILE *file;
        printf("Code Compte de depart : ");
        scanf("%d", &code1);
        printf("Code compte d'arrivee : ");
        scanf("%d", &code2);
        file = fopen("compte.txt", "r");
        int nb = 0;
        while(fread(&compte, sizeof(struct Compte), 1, file)) {
            comptes[nb] = compte;
            nb++;
        }
        fclose(file);
        remove("compte.txt");

        FILE *nf;
        nf = fopen("nv.txt", "a");
        for ( int i=0 ; i<nb ; i++)
        {
            if (comptes[i].code_cpt == code1)
            {
                        do{
                            printf("\n montant : ");
                            scanf("%d", &m);
                            if (m>500)
                                printf("\n le montant ne doit pas depasser 500 DT");
                            solde = comptes[i].somme - m;
                            if (solde<250)
                                printf("\n le solde ne doit pas etre inferieur a 250 DT");
                        }while(m>500 || solde<250);
                comptes[i].somme = comptes[i].somme - m;
                printf(" compte depart : ");
                printf("\n code compte %d", comptes[i].code_cpt);
                printf("\n code client %d", comptes[i].Code_cli);
                printf("\n nv somme : %d", comptes[i].somme);
                printf("\n Date creation %d / %d / %d", compte.d_compte.Jour, compte.d_compte.Mois, compte.d_compte.Annee);
                printf("\n-----------------------------------------");
            }
            else if (comptes[i].code_cpt == code2)
            {
                comptes[i].somme = comptes[i].somme + m;
                printf(" compte d'arrivée :");
                printf("\n code compte %d", comptes[i].code_cpt);
                printf("\n code client %d", comptes[i].Code_cli);
                printf("\n nv somme : %d", comptes[i].somme);
                printf("\n Date creation %d / %d / %d", compte.d_compte.Jour, compte.d_compte.Mois, compte.d_compte.Annee);
                printf("\n-----------------------------------------");
            }
            fwrite(&comptes[i], sizeof(comptes[i]), 1, nf);
        }
        fclose(nf);
        rename("nv.txt", "compte.txt");
    }
}
int main()
{
    menu();
    return 0;
}
