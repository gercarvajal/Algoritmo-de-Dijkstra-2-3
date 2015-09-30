#include<stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MaxNodos 8

// Inicializa la lista de adyacencia a NULL 
void init() {
    int i;
    for (i = 0; i < MaxNodos; i++)
        Lista[i] = NULL;    
}

void mostrar_lista_adyacencia () {
   Tnodo *q;
   int i;
   
   for (i = 0; i < Num_Vertices; i++) {
      if (Lista[i] != NULL) {
         q = Lista[i];
         printf ("vertice %d: ", i);
         while (q) {
            printf ("%d ", q->etiqueta);
            q = q->sig;
         }
         printf("\n");
      }
   }
}
