#include <stdio.h>
#include <stdlib.h>
#include "identite.h"

int main()
{
    int nCptId = 0;
    int *pId= &nCptId;
    FILE *fic = fopen("cartes.txt","a+");
    if (fic==NULL)
        exit(1);

    menu(fic,&*pId);

    fclose(fic);
    return 0;
}
