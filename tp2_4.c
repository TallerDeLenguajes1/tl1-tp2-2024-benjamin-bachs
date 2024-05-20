#include<stdio.h>
#include<stdlib.h>
#define N 5

const char tipos[6][10]={"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};

typedef struct {
    int velocidad;//entre 1 y 3 GHz
    int anio;//entre 2015 y 2023
    int cantidad;//entre 1 y 8
    char *tipo_cpu; //valores del arreglo tipos
} compu;

void cargarLista(compu * lista);
void mostrarCompu(compu pc);
void mostrarLista(compu * lista);
void masAntigua(compu * lista);
void masRapida(compu * lista);

int main(void){
    compu lista[N];
    cargarLista(lista);
    mostrarLista(lista);
    masAntigua(lista);
    masRapida(lista);

}

void cargarLista(compu * lista){
    
    for (int i = 0; i < N; i++){
        lista[i].velocidad = rand()%2+1;
        lista[i].anio = rand()%8+2015;
        lista[i].cantidad = rand()%7+1;
        lista[i].tipo_cpu = tipos[rand()%5];
    }
}

void mostrarCompu(compu pc){
        printf("Velocidad: %d\n", pc.velocidad);
        printf("Anio: %d\n", pc.anio);
        printf("Cantidad: %d\n", pc.cantidad);
        printf("Tipo de CPU: %s\n\n", pc.tipo_cpu);
}

void mostrarLista(compu * lista){
    for (int i = 0; i < N; i++)
    {
        printf("Computadora %d\n", i+1);
        mostrarCompu(lista[i]);
    }
    
}

void masAntigua(compu * lista){
    int antigua = 0;
    for (int i = 1; i < N; i++)
    {
        if (lista[i].anio < lista[antigua].anio)
        {
            antigua = i;
        }
    }
    printf("Computadora %d es la mas antigua\n", antigua+1);
    mostrarCompu(lista[antigua]);
}

void masRapida(compu * lista){
    int rapida = 0;
    for (int i = 1; i < N; i++)
    {
        if (lista[i].velocidad > lista[rapida].velocidad)
        {
            rapida = i;
        }
    }
    printf("Computadora %d es la mas rapida\n", rapida+1);
    mostrarCompu(lista[rapida]);
}