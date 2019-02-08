#ifndef IDENTITE_H_INCLUDED
#define IDENTITE_H_INCLUDED

#define TAILLE 50

typedef struct tIdentite{
    int nId;
    char sNom[TAILLE];
    char sPrenom[TAILLE];
    char sAdresse[TAILLE];
    char sVille[TAILLE];
    int nCodePostal;
    }tIdentite;

extern void ajoutIdentite(FILE *fic, int *pId);
extern void menu(FILE *fic, int *pId);
extern void lireIdentite(FILE *fic);

#endif // IDENTITE_H_INCLUDED
