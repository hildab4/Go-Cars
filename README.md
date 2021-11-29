# TC1031-Integral-A

# Programa para conocer las ventas de cada modelo de carro
La cantidad de carros vendidos por modelo se encuentran en el archivo datos.csv, este se lee y se crea un vector con el dato de las ventas. Se ordena el vector en orden ascendente por medio de la función ordenaMerge.

# SICT0302B - Toma de decisiones

## Selecciona un algoritmo de ordenamiento adecuado al problema
* Se seleccionó el algoritmo de ordenamiento de búrbuja, ya que la complejidad espacial es menor en comparación con el ordenamiento de selección y el merge. Su complejidad temporal es de O(n^2).

## Selecciona y usa una estructura lineal adecuada al problema
* Se seleccionó la estructura lineal de la lista doblemente ligada, ya que nos permite recorrer la lista en dos direcciones, lo cual es útil en este caso para conocer detalles de las ventas. Es decir, se puede conocer en orden ascendente los carros más vendidos, y los menos vendidos.

# SICT0303B - Implementa acciones científicas

## Implementa mecanismos para consultar información de las estructuras correctos
* Los mecanismos de consulta para las distintas estructuras dentro del proyecto son los siguientes:
* sort.h -> la función ordenaCarro ordena en orden ascendente los datos basados en el atributo cantidad; muestraOrdenado permite desplegar el vector ya ordenado; busqCarro permite obtener las ventas de cierto modelo.
* dlist.h -> agregaCarro permite agregar un elemento nuevo a la lista; buscaCarro permite buscar la cantidad de ventas basado en el modelo; actualizaCarro modifica la cantidad de ventas a cierto modelo.

## Implementa mecanismos de lectura de archivos correctos
* Tanto sort.h y dlist.h utilizan un mecanismo de lectura de archivos para llenar tanto el vector como la lista doblemente ligada. Se hace uso de la librería fstream, que nos permite tanto leer como escribir archivos. En este caso se leen los datos del archivo llamado 'datos.csv' para ambos casos.

# SICT0301B - Evalúa los componentes

## Presenta Casos de Prueba correctos y completos para todas las funciones y procedimientos del programa

## Hace un análisis de complejidad correcto y completo para todo el programa y sus componentes
* ordenaCarro -> La complejidad temporal del algoritmo ordenaBurbuja es de O(n^2), ya que se conforma por dos ciclos for anidados, que dependen de la longitud (n) del vector. La complejidad espacial del algoritmo ordenaBurbuja es de O(1), siendo mejor que ordena merge e igual que ordena selección.
* busqCarro -> El algoritmo recorre el vector elemento por elemento, por lo que la cantidad de pasos a realizar depende de la longitud del mismo; así que la complejidad temporal en el peor de los casos es de O(n).
* mayormenor -> Se obtienen dos posiciones del vector, no es necesario recorrerlo así que las operaciones del algoritmo son de O(1) de complejidad temporal.
* muestraDatos -> Se recorre todo el vector, por lo que este depende de la cantidad de datos dentro del vector; entonces la complejidad temporal en el peor de los casos es de O(n).
* leeArchivo -> Se lee el archivo línea por línea, por lo que la complejidad temporal depende de la cantidad de líneas del archivo; por lo que en el peor de los casos es de O(n). (Es lo mismo para la función en sort.h y dlist.h)
* agregaCarro -> El algoritmo siempre inserta el dato al final de la lista, por lo que no depende de la longitud de la misma. Tiene complejidad temporal de O(1).
* buscaCarro -> Dentro del algoritmo se recorre la lista para encontrar el valor deseado, por lo que depende de la longitud que esta tenga. Tiene una complejidad temporal de O(n) para el peor de los casos.
* actualizaCarro -> El algoritmo recorre la lista hasta encontrar la posición en que se cambiará el dato, por lo que esto depende de la longitud de la lista. Tiene complejidad temporal de O(n) para el peor de los casos. 
* toStringForward y toStringBackward -> El algoritmo recorre toda la lista ligada en ambas funciones, dependiendo de la cantidad de elementos en la lista es el tiempo que tarda; por lo que la complejidad temporal es de O(n).