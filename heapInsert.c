#include <stdio.h>

int insertElement(int x, int ult, int v[]);
void printVetor(int v[], int ult);

int main(void) 
{
    int lenght;
    lenght = 0;
    int arvore[20];
    
    lenght = insertElement(5, lenght, arvore);
    lenght = insertElement(14, lenght, arvore);
    lenght = insertElement(1, lenght, arvore);
    lenght = insertElement(20, lenght, arvore);
    lenght = insertElement(25, lenght, arvore);
    
    
    printVetor(arvore, lenght);
	// your code goes here
	return 0;
}

int insertElement(int x, int ult, int v[])
{
    ult++;
    int k = ult;
    while((k/2) && x > v[k/2])
    {
        v[k] = v[k/2];
        k = k/2;
    }
    v[k] = x;
    
    return ult;
}

void printVetor(int v[], int ult)
{
    int i = 0;
    for(i = 1; i < ult+1; i++)
    {
        printf("%d\n", v[i]);
    }
}

