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

// imprime lista de adyacencia
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

//Inserta los nodos en la lista 
void inserta (int Vorigen, int Vfinal, float peso) {
    Tnodo *q;
    q = (Tnodo*) malloc (sizeof(Tnodo) * 1);
    if (!q) return; //si hay error
    q->etiqueta = Vfinal-1;
    q->peso     = peso;
    q->sig      = NULL;
    if (Lista[Vorigen-1] != NULL)
       q->sig = Lista[Vorigen-1];
    Lista[Vorigen-1] = q;
}

//elige mejor valor
int menor_valor() {
   int i, verticeMenor;
   float menor;
   menor = INT_MAX;
   for (i = 0; i < Num_Vertices; i++) {
      if (marca[i] == 0 )
         if (menor > d[i]) {
            menor = d[i];
            verticeMenor = i;
         }
   } 
   return verticeMenor;
}


// funcion Dijkstra 
void dijkstra (int origen, int destino)
{
   int i, last, x;
   Tnodo *p;
   // inicializacion
   for (i = 0; i < MaxNodos; i++) {
      d[i] = INT_MAX; //"infinito"
      marca[i] = 0;
      predecesores[i] = -1;
   }
   d[origen] = 0;
   marca[origen] = 1;
   last = origen;
   while (marca[destino] == 0) { //hasta que no lleguemos al destino
      p = Lista[last];
      while (p != NULL){   //para todos los nodos adyacendes
          if (marca[p->etiqueta] == 0) //si no ha sido visitado
                  if (d[p->etiqueta] > d[last] + return_peso(last, p->etiqueta))
              {
                      d[p->etiqueta] = d[last] + return_peso(last, p->etiqueta);
                      predecesores[p->etiqueta] = last;
                  } 
           p = p->sig;
      } 
      x = menor_valor();    
      marca[x] = 1;
      last = x;
   } // fin mientras
}
