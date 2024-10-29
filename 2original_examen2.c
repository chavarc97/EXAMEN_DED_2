/* Prohibido agregar librerías adicionales a estas: */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char alumno[100] = "Salvador Rodriguez Ceballos";

/*

    Fecha : 29 de Octubre 2024
    Diseno de Estructura de Datos - Grupo B
    Segunda Evaluación Síncrona

  Ejercicio 1:  Mandar al Inicio          /15 pts
  Ejercicio 2:  Ingresar nodo a la mitad  /20 pts
  Ejercicio 3:  Arreglo de listas         /15 pts
  Ejercicio 4:  Destinos                  /20 pts
  Ejercicio 5:  Password                  /20 pts
  Ejercicio 6:  Reverse                   /20 pts
                                      ________
  Calificación Final:                     /110 puntos
*/

/*Definiciones y Funciones de utilidad - NO TOCAR*/
typedef struct node
{
  int value;
  struct node *next;
  struct node *prev;
} node;

void printlist(node *n) // NO TOCAR
{
  while (n)
  {
    printf("%d ", n->value);
    n = n->next;
  }
  printf("\n");
}

void printlistBack(node *n) // NO TOCAR
{
  while (n)
  {
    printf("%d ", n->value);
    n = n->prev;
  }
  printf("\n");
}

node *L1, *L2;
node L1n1, L1n2, L1n3, L1n4;
node L2n1, L2n2, L2n3, L2n4, L2n5;
node *LD1, *LD2, *LD1B, *LD2B;
node LD1n1, LD1n2, LD1n3, LD1n4;
node LD2n1, LD2n2, LD2n3, LD2n4, LD2n5, LD2n6;
node LD1nuevo, LD2nuevo;
/* NO TOCAR */
/*Definiciones y Funciones de utilidad - NO TOCAR*/

/* INSTRUCCION GENERAL:
   Codifica SIEMPRE dentro de las secciones: */

/* ----------  INICIO RESPUESTA:  --------------- */
// tu codigo del examen
// va en estas seccion
/* ----------  FIN RESPUESTA:  --------------- */

/*Inicio de Examen*/

/*  = = = = = = = Ejercicio 01: Mandar al Inicio = = = = = =
    Valor: 15 puntos
    = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
  Crea una función, que reciba el apuntador a una lista ligada.
  La funcion deberá de recorrer la lista hasta llegar al último elemento y moverlo al inicio de la lista.

  Te recomiendo que la función regrese el nuevo header de la lista.

  Ejemplos:
  Lista Inicial: 8 -> 45 -> 70 -> 12 -> Null
  Lista después del cambio: 12 -> 8 -> 45 -> 70 -> Null

  Lista Inicial: 1 -> 2 -> 3 -> 4 -> 5 -> Null
  Lista después del cambio: 5 -> 1 -> 2 -> 3 -> 4 -> Null

  Comprueba el funcionamiento correcto llamando tu función.
  Usa la funcion printList provista y comprueba el resultado.
  Usa las listas de ejemplo L1 y L2 creadas.

*/

/* ----------  INICIO RESPUESTA:  --------------- */
void moveLastToFirst(node **h)
{
  if (*h == NULL || (*h)->next == NULL)
    return;
  // Encontrar el último y penúltimo nodo
  node *current = *h;
  node *prev = NULL;

  // Recorrer hasta el último nodo
  while (current->next != NULL)
  {
    prev = current;
    current = current->next;
  }

  // Ahora current es el último nodo y prev es el penúltimo

  // El penúltimo nodo ahora apunta a NULL
  prev->next = NULL;

  // El último nodo ahora apunta al antiguo head
  current->next = *h;

  // Actualizar el head para que apunte al antiguo último nodo
  *h = current;
}

/* ----------  FIN RESPUESTA:  --------------- */

int ex01()
{
  /* NO TOCAR, inicalizacion de listas demo L1 y L2 */
  L1n1.value = 8;
  L1n2.value = 45;
  L1n3.value = 70;
  L1n4.value = 12;
  L1n1.next = &L1n2;
  L1n2.next = &L1n3;
  L1n3.next = &L1n4;
  L1n4.next = NULL;
  L2n1.value = 1;
  L2n2.value = 2;
  L2n3.value = 3;
  L2n4.value = 4;
  L2n5.value = 5;
  L2n1.next = &L2n2;
  L2n2.next = &L2n3;
  L2n3.next = &L2n4;
  L2n4.next = &L2n5;
  L2n5.next = NULL;
  L1 = &L1n1; // Header de Lista 1
  L2 = &L2n1; // Header de Lista 2

  printf("Lista 1 antes del cambio:\n");
  printlist(L1);
  printf("Lista 2 antes del cambio:\n");
  printlist(L2);
  /* NO TOCAR */

  /* ----------  INICIO RESPUESTA:  --------------- */
  // Espacio para que mandes llamar tu función y compruebes el resultado.
  moveLastToFirst(&L1);
  moveLastToFirst(&L2);
  /* ----------  FIN RESPUESTA:  --------------- */

  /* NO TOCAR */
  printf("\nLista 1 después del cambio:\n");
  printlist(L1);
  printf("Lista 2 después del cambio:\n");
  printlist(L2);
  return 0;
  /* NO TOCAR */
}

/*  = = = = = = = Ejercicio 02: Ingresar nodo a la mitad = = = = = =
    Valor: 20 puntos
    = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
  Crea una función que se llame "insertMiddle".
  Deberá  reciba el apuntador a una lista doblemente ligada, y un nuevo nodo.
  La lista doblemente ligada siempre tendrá un número par de elementos.
  La funcion deberá de recorrer la lista hasta llegar a la mitad de la lista e insertar el nuevo nodo.

  Ejemplos:
  Lista Inicial: Null <-> 1 <-> 2 <-> 3 <-> 4 <-> Null
  Número entero: 10
  Lista después del cambio: Null <-> 1 <-> 2 <-> 5 <-> 3 <-> 4 <-> Null

  Lista Inicial: Null <-> 70 <-> 45 <-> 32 <-> 32 <-> 32  <-> 1 <-> Null
  Número entero: 11
  Lista después del cambio: Null Null <-> 70 <-> 45 <-> 32 <-> 11 <-> 32 <-> 32  <-> 1 <-> Null

  Comprueba el funcionamiento correcto llamando tu función.
  Usa las funciones printList y printListBack provistas y comprueba el resultado.
  Usa las listas de ejemplo LD1 y LD2 creadas.

*/

/* ----------  INICIO RESPUESTA:  --------------- */
void insertMiddle(node *h, node *nuevo)
{
  if (h == NULL || h->next == NULL)
    return;
  // Encontrar la mitad de la lista
  node *slow = h;
  node *fast = h;
  node *prev = NULL;

  // Fast avanza el doble que slow, así que cuando fast llegue al final
  // slow estará en la mitad
  while (fast != NULL && fast->next != NULL)
  {
    fast = fast->next->next;
    prev = slow;
    slow = slow->next;
  }
  // Ahora prev apunta al nodo antes del punto medio
  // y slow apunta al nodo después del punto medio

  // Actualizar enlaces del nuevo nodo
  nuevo->next = slow;
  nuevo->prev = prev;

  // Actualizar enlaces de los nodos vecinos
  prev->next = nuevo;
  slow->prev = nuevo;
}

/* ----------  FIN RESPUESTA:  --------------- */

int ex02()
{
  /* NO TOCAR, inicalizacion de listas demo LD1 y LD2 */
  LD1n1.value = 1;
  LD1n2.value = 2;
  LD1n3.value = 3;
  LD1n4.value = 4;
  LD1n1.next = &LD1n2;
  LD1n2.next = &LD1n3;
  LD1n3.next = &LD1n4;
  LD1n4.next = NULL;
  LD1n1.prev = NULL;
  LD1n2.prev = &LD1n1;
  LD1n3.prev = &LD1n2;
  LD1n4.prev = &LD1n3;
  LD2n1.value = 70;
  LD2n2.value = 40;
  LD2n3.value = 32;
  LD2n4.value = 32;
  LD2n5.value = 32;
  LD2n6.value = 1;
  LD2n1.next = &LD2n2;
  LD2n2.next = &LD2n3;
  LD2n3.next = &LD2n4;
  LD2n4.next = &LD2n5;
  LD2n5.next = &LD2n6;
  LD2n6.next = NULL;
  LD2n1.prev = NULL;
  LD2n2.prev = &LD2n1;
  LD2n3.prev = &LD2n2;
  LD2n4.prev = &LD2n3;
  LD2n5.prev = &LD2n4;
  LD2n6.prev = &LD2n5;
  LD1 = &LD1n1;  // Header de Lista Doble 1
  LD2 = &LD2n1;  // Header de Lista Doble 2
  LD1B = &LD1n4; // Ultimo elemento de Lista Doble 1
  LD2B = &LD2n6; // Ultimo elemento de Lista Doble 2

  printf("Lista Doble 1 antes del cambio:\n");
  printlist(LD1);
  printf("Lista Doble 2 antes del cambio:\n");
  printlist(LD2);

  LD1nuevo.value = 10;
  LD2nuevo.value = 11;

  // Llamadas a las funciones que tienes que crear.
  insertMiddle(LD1, &LD1nuevo);
  insertMiddle(LD2, &LD2nuevo);

  printf("\nLista Doble 1 después del cambio:\n");
  printlist(LD1);
  printf("Inverso: ");
  printlistBack(LD1B);
  printf("Lista Doble 2 después del cambio:\n");
  printlist(LD2);
  printf("Inverso: ");
  printlistBack(LD2B);
  return 0;
  /* NO TOCAR */
}

/*  = = = = = = = Ejercicio 03: Arreglo de Listas = = = = = =
    Valor: 15 puntos
    = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
    Utiliza memoria dinamica para crear un arreglo de apuntadores a 6 listas ligadas.
    Guarda las listas L1, L2, LD1 y LD2 en las primeras 4 posiciones.
    Prueba tu arreglo llamando la funcion printList.
*/

int ex03()
{
  /* ----------  INICIO DE RESPUESTA:  --------------- */
  // aloca memoria para un arreglo de 6 apuntadores a nodos
  node **ptr_arr = (node **)malloc(6 * sizeof(node *));
  if (ptr_arr == NULL)
  {
    printf("Error al asignar memoria\n");
    return 1;
  }

  // Inicializar las listas en las primeras 4 posiciones
  for (int i = 0; i < 4; i++)
  {
    ptr_arr[i] = NULL; // Inicialmente, todas las listas están vacías
  }

  // Guarda las listas L1, L2, LD1 y LD2 en las primeras 4 posiciones
  ptr_arr[0] = L1;
  ptr_arr[1] = L2;
  ptr_arr[2] = LD1;
  ptr_arr[3] = LD2;

  // Imprime las listas guardadas
  for (int i = 0; i < 4; i++)
  {
    printf("Lista %d: ", i + 1);
    printlist(ptr_arr[i]);
  }

  // Libera la memoria
  free(ptr_arr);

  /* ----------  FIN DE RESPUESTA:  --------------- */
  return 0;
}

/*  = = = = = = = Ejercicio 04: Destinos  = = = = = =
    Valor: 20 puntos
    = = = = = = = = = = = = = = = = = = = = = = = = =
   Abre del archivo de texto "destinos.txt" que viene incluido en tu examen.
   El archivo de texto tiene la siguiente estructura:

    * 1era línea = Un número que se refiere a cuantos registros tiene el archivo.
    * 2nda en adelante = El nombre de una ciudad + el costo (con $) de un vuelo a esa ciudad.

  Ejemplo:
  3
  Tokyo $10000
  Roma $8000
  Barcelona $5500

  1. Contruye dos arreglo de forma DINAMICA,para almacenar la informacion leida del archivo.
    Uno de caracteres para las ciudades y uno de enteros para los costos.
  2. Imprime tus arreglos para confirmar.
  3. Con tu código, escribe tu nombre completo al inicio o al final de tu archivo destinos.txt.
    TIP, si entre ejecuciones, modificas el archivo te recomiendo regresarlo a su forma original.
  4. Libera tu memoria dinámica.

    VALOR 20 pts:
    a) (5 pts) Lectura de archivos
    b) (5 pts) Escritura de archivos
    c) (10 pts) Creacion y liberacion de memoria dinamica.
      NOTA: Si no puedes leer el archivo, pide los datos de consola, pero solo valdra 10pts.
*/

int ex04()
{
  /* ----------  INICIO RESPUESTA:  --------------- */
  FILE *fp;
  int num_destinos;
  char **ciudades;
  int *costos;
  char buffer[100];

  // Abrir el archivo
  fp = fopen("destinos.txt", "r");
  if (fp == NULL)
  {
    printf("Error al abrir el archivo\n");
    return 1;
  }

  // Leer número de destinos
  fscanf(fp, "%d\n", &num_destinos);

  // crear arreglos dinamicos
  ciudades = (char **)malloc(num_destinos * sizeof(char *));
  costos = (int *)malloc(num_destinos * sizeof(int));
  if (ciudades == NULL || costos == NULL) // Verificar que la asignación de memoria fue exitosa
  {
    printf("Error en la asignación de memoria\n");
    fclose(fp);
    return 1;
  }

  // Leer los destinos
  for (int i = 0; i < num_destinos; i++)
  {
    char ciudad[100];
    int costo;
    char signo;

    // leer linea completa
    fgets(buffer, sizeof(buffer), fp);
    // parsear la ciudad y el costo
    sscanf(buffer, "%s $%d", ciudad, &costo);
    // Asignar memoria para el string de la ciudad
    ciudades[i] = (char *)malloc((strlen(ciudad) + 1) * sizeof(char));
    if (ciudades[i] == NULL)
    {
      printf("Error en la asignación de memoria\n");
      // Liberar memoria previamente asignada
      for (int j = 0; j < i; j++)
      {
        free(ciudades[j]);
      }
      free(ciudades);
      free(costos);
      fclose(fp);
      return 1;
    }

    // Copiar la ciudad y el costo a los arreglos
    strcpy(ciudades[i], ciudad);
    costos[i] = costo;
  }

  // Imprimir los arreglos
  printf("Destinos y costo:\n");
  for (int i = 0; i < num_destinos; i++)
  {
    printf("%s $%d\n", ciudades[i], costos[i]);
  }

  // Cerrar el archivo
  fclose(fp);

  // Escribir nombre al final del archivo
    fp = fopen("destinos.txt", "a");
    if (fp == NULL) {
        printf("Error al abrir el archivo para escritura\n");
        return 1;
    }
    
    fprintf(fp, "%s\n", alumno);
    fclose(fp);

  // Liberar memoria
  for(int i = 0; i < num_destinos; i++) {
    free(ciudades[i]);
  }
  free(ciudades);
  free(costos);

  /* ----------  FIN RESPUESTA:  --------------- */
  return 0;
}

/*  = = = = = = = Ejercicio 05: Password  = = = = = =
    Valor: 20 puntos
    = = = = = = = = = = = = = = = = = = = = = = = = =
  Eres un hacker que acaba de obtener un archivo binario que contiene la contraseña de Canvas del profesor.
  Abre el archivo binario password.data que viene con tu examen.
  Encuentra el password correcto e imprímelo en pantalla.

  Lo que sabes del archivo:
  * El archivo está lleno de cadenas de 4 caracteres o de enteros.
  * El password está en algún lugar del archivo y lo demás es basura.
  * El password empieza justo después de encontrar el número entero 123456.
  * El password consiste de 1 número entero (4 dígitos) + 4 caracteres (en ese orden).

*/

int ex05()
{
  /* ----------  INICIO RESPUESTA:  --------------- */
  FILE *fp;
  /* ----------  FIN RESPUESTA:  --------------- */
  return 0;
}

/*  = = = = = = = Ejercicio 06: Reverse = = = = = =
    Valor: 20 puntos
    = = = = = = = = = = = = = = = = = = = = = = =
    Para programar una funcion que invierta el contenido de una cadena
    de caracteres (STRING).
    Prohibido utilizar librerías externas.
    Copia las funciones que necesites del STACK que vimos en clase.

    ej
    char prueba[10] = {"ITESO"};

    printf("%s\n", prueba); //Debe imprimir "ITESO"
    reverse(prueba);
    printf("%s\n", prueba); //Debe imprimir "OSETI"

    TIP. Necesitas la longitud de la cadena, o la envias, o la calculas con
    alguna libreria.
  */

/* ----------  INICIO RESPUESTA:  --------------- */
// Agrega aquí tus estructuras, funciones del Stack, y función "reverse".

/* ----------  FIN RESPUESTA:  --------------- */

void ex06()
{
  char prueba[10] = "ITESO";
  printf("%s\n", prueba); // Debe imprimir "ITESO"
  /* ----------  INICIO RESPUESTA:  --------------- */
  // Llama tu función aquí.

  /* ----------  FIN RESPUESTA:  --------------- */
  printf("%s\n", prueba); // Debe imprimir "OSETI"
}

int main()
{
  printf("Examen Parcial 2 de : %s\n", alumno);
  printf("=== E01: Mandar al inicio\n");
  ex01();
  printf("\n=== E02: Ingresar nodo a la mitad\n");
  ex02();
  printf("\n=== E03: Arreglo de listas\n");
  ex03();
  printf("\n=== E04: Destinos \n");
   ex04();
  printf("\n=== E05: Password \n");
  // ex05();
  printf("\n=== E06: Reverse \n");
  // ex06();
  return 0;
}