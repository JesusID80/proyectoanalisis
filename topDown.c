// A recursive solution for subset sum problem
#include <stdio.h>
#include <stdlib.h>

int tab[5][9];

void imprimirTab() {
    for (int i = 0; i <= 5; i++) {
        for (int j = 0; j <= 9; j++) {
            printf(" %d ",tab[i][j]);
        }
        printf("\n");
    }
}

void inicializarTab() {
    for (int i = 0; i <= 5; i++) {
        for (int j = 0; j <= 9; j++) {
            tab[i][j] = -1;
        }
    }
}

int esSumaConjunto(int a[], int n, int sum){
	// Casos Base
	if(sum == 0)
		return 1;
	if(n == 0)
		return 0;
	
	//Si el valor ya ha sido calculado
	if(tab[n-1][sum] == -1)
		return tab[n-1][sum] = esSumaConjunto(a, n-1, sum);
	
	if(a[n-1] > sum) //Si el elemento del arreglo es mayor a la suma se ignora
		return tab[n-1][sum];
		
	if(tab[n-1][sum] == 1){ //Sino, se consideran dos casos, no incluir al elemento e incluirlo
		return 1;
	} else {
		if(tab[n-1][sum - a[n-1]] == -1){
			tab[n-1][sum] = esSumaConjunto(a, n-1, sum-a[n-1]);
		}
		return tab[n-1][sum-a[n-1]];
	}
}

int main()
{
	int a[] = {3, 34, 4, 12, 5, 2};
	int sum = 9;
	int n =  sizeof(a) / sizeof(a[0]);;
	
	inicializarTab();
	
	if (esSumaConjunto(a, n, sum))
        printf("Se encontro un subconjunto con la suma dada");
    else
        printf("No se encontro un subconjunto con la suma dada");

	return 0;
}

