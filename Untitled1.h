#ifndef BANK_H_INCLUDED
#define BANK_H_INCLUDED

int solde,choix,x;
typedef struct Client
{
    int Code_cli;
    char Nom[CMAX];
    char Prenom[CMAX];
}Client;


typedef struct Date
{
    int Jour;
    int Mois;
    int Annee;
}Date;

typedef struct Compte
{
    int code_cpt;
    int Code_cli;
    int somme;
    struct Date d_compte;
}Compte;

#endif // BANK_H_INCLUDED
