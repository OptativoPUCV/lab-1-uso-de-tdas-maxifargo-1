#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "arraylist.h"
#include "stack.h"

//#include "exercises.h"

//Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
//NO MODIFICAR
void imprime_lista(List *L) {
   int *dato;
   dato = (int*)first(L);
   printf("[");
   while(dato != NULL) {
      printf("%d ", *dato);
      dato = (int*)next(L);
   }
   printf("]\n");

}

//Ojo que la pila se vacía al imprimir y se imprime en orden inverso
//NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
   void *dato;
   printf("[");
   while((dato = pop(P)) != NULL) {
      printf("%d ", *(int*)dato);
   }
   printf("]\n");
}

/* 
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/
typedef struct Nodo {
    int *dato; 
    struct Nodo *siguiente;
} Nodo;

typedef struct List {
    Nodo *cabeza; 
    Nodo *temp;
} List;

List* crea_lista() {
   List* L = (List*)malloc(sizeof(List));
   L->cabeza = NULL, L->temp = NULL;
   for (int i = 1; i <= 10; i++) {
      Nodo *Nodo2 = (Nodo*)malloc(sizeof(Nodo));
      Nodo2->dato = (int*)malloc(sizeof(int));
      *(Nodo2->dato) = i;
      Nodo2->siguiente = NULL;
      if (L->cabeza == NULL) {
         L->cabeza = Nodo2;
         } else {
            L->temp->siguiente = Nodo2;}
      
      
         L->temp = Nodo2;
      }
   return L;
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/
int sumaLista(List *L) {
   for (int i = 0; i < 10; i++) {
       int suma = 0;
         Nodo *temp = L->cabeza;
         while (temp != NULL) {
            suma += *(temp->dato);  
            temp = temp->siguiente; 
         }

         return suma;
      }
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos 
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List*L, int elem){
   Nodo *temp = L->cabeza;
   Nodo *prev = NULL;

   while (temp != NULL) {
      if (*(temp->dato) == elem) {
         if (prev == NULL) {
            L->cabeza = temp->siguiente;
         } else {
            prev->siguiente = temp->siguiente;
         }
   
}}}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/
void copia_pila(Stack* P1, Stack* P2) {
   Stack* auxiliar = crear_pila(); 

          while (!es_pila_vacia(P1)) {
              push(auxiliar, pop(P1));
          }
          while (!es_pila_vacia(auxiliar)) {
              push(P2, pop(auxiliar)); 
          }}

/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena) {
   Pila* pila = crear_pila();
   for (int i = 0; cadena[i] != '\0'; i++) {
      char c = cadena[i];
         if (c == '(') {
               push(pila, c);
           }
         else if (c == ')') {
            if (es_pila_vacia(pila)) {
             free(pila);
                   return 0;
               }
               pop(pila);
           }
       }
       int balanceado = es_pila_vacia(pila);
       free(pila);
       return 1;
   }


