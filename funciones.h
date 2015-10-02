#include<stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MaxNodos 8


Tnodo *Lista[MaxNodos]; //lista de adyacencia
int marca[MaxNodos]; //visitados
int predecesores[MaxNodos]; //ruta
float d[MaxNodos]; // distancia - peso
int Num_Vertices; //numero de vertices
int tipo; //1 no dirigido, 0 dirigido


void cargar_grafo (char *fn) {
  FILE *fp;
  int vortex_i, vortex_f; //vertices de inicio y final
  float peso;
  if ((fp = fopen ("grafo.txt", "r")) == NULL)
  {
       printf ("No se puede abrir el archivo\n", fn);
       exit(0);         
   }
   fscanf (fp, "%d\n", &tipo);
   fscanf (fp, "%d\n", &Num_Vertices); //Num_Vertices es una vble global 
        while (!feof(fp))
        {
             fscanf(fp, "%d %d %f\n", &v_in, &v_fn, &peso);
             inserta(vortex_i, vortex_f, peso);
             inserta (vortex_f, vortex_i, peso);
        }
   fclose (fp);
} 
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
