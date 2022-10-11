#include <stdio.h>
#include <stdlib.h>

void leer_arreglo(int n, int arr[]);
int busqueda_binaria_ciclos(int arr[], int x, int n);
int busqueda_binaria_recursiva(int arr[], int x, int n);

int main()
{
    int arr[100];
    int n,x;
    printf("Tam del arreglo: ");
    scanf("%d", &n);
    leer_arreglo(n,arr);
    printf("Valor a buscar: ");
    scanf("%d", &x);
    if(busqueda_binaria_ciclos(arr,x,n)==1){
        printf("Si se encontro el valor(ciclos)\n");
    }else{
        printf("No se encontro el valor(ciclos)\n");
    }
    if(busqueda_binaria_recursiva(arr,x,n)==1){
        printf("Si se encontro el valor(recursivo)\n");
    }else{
        printf("No se encontro el valor(recursivo)\n");
    }
    return 0;
}

void leer_arreglo(int n, int arr[]){
    printf("Datos del arreglo: ");
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
}

int busqueda_binaria_ciclos(int arr[], int x, int n){
    int p=0, r=n-1;
    while(p<=r){
        int q=(p+r)/2;
        if(arr[q]==x){
            return 1;
        }
        if(arr[q]>x){
            r=q-1;
        }else{
            p=q+1;
        }
    }
    return 0;
}

int busqueda_binaria_recursiva(int arr[], int x, int n){
    int p=0,r=n-1;
    if (p>r){
        return 0;
    }

    int q=(p+r)/2;

    int mitad = arr[q];
    if (x == mitad){
        return 1;
    }

    if (x < mitad){
        // Entonces está hacia la izquierda
        r = q - 1;
    }else{
        // Está hacia la derecha
        p = q + 1;
    }
    return busqueda_binaria_recursiva(arr, x, n);
}
