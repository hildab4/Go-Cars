# TC1031-Integral-A

# Correcciones
* -> Se agrega la estructura lineal y el árbol.
* -> Se agrega la escritura y lectura de archivos, y la consulta de datos en las estructuras.
* -> Se agrega la complejidad temporal de las funciones.

# Programa para conocer las ventas de cada modelo de carro
El programa despliega un menú para que el usuario pueda elegir la opción que quiera llevar a cabo, es un programa para manejar las ventas de ciertos modelos de carros. El usuario puede desplegar la lista en orden alfabético, ordenar los modelos por ventas de menor a mayor, actualizar el valor de ventas por modelo, y buscar ventas por modelo.

# SICT0302B - Toma de decisiones

## Selecciona un algoritmo de ordenamiento adecuado al problema
* Se seleccionó el algoritmo de ordenamiento de búrbuja, ya que la complejidad espacial es menor en comparación con el ordenamiento de selección y el merge. Su complejidad temporal es de O(n^2). Se utiliza para mostrar en orden alfabético los modelos con las cantidades correspondientes.

## Selecciona y usa una estructura lineal adecuada al problema
* Se seleccionó la estructura lineal de la lista doblemente ligada, ya que nos permite insertar objetos al final de la lista, lo cual da información sobre en qué orden se agregó. Se utilizó para consultar la cantidad vendida por medio del modelo ingresado, para actualizar las ventas dependiendo del modelo, y agregar nuevo modelo con ventas.

## Usa un árbol adecuado para resolver un problema
* Se seleccionó el árbol BST (Binary Search Tree) para almacenar objetos, los cuales son ordenados por la cantidad de ventas que tienen; se utiliza la función inorder para recorrer el árbol y desplegar los datos en orden ascendente.

# SICT0303B - Implementa acciones científicas

## Implementa mecanismos para consultar información de las estructuras correctos
* Los mecanismos de consulta para las distintas estructuras dentro del proyecto son los siguientes:
* sort.h -> la función ordenaCarro ordena en orden ascendente los datos basados en el atributo modelo (alfabéticamente); muestraOrdenado permite desplegar el vector ya ordenado.
* dlist.h -> agregaCarro permite agregar un elemento nuevo a la lista; buscaCarro permite buscar la cantidad de ventas basado en el modelo; actualizaCarro modifica la cantidad de ventas a cierto modelo.
* bst.h -> la función addCarro agrega un elemento nuevo al árbol, este algoritmo usa findCarro para comprobar que el elemento no sea parte del árbol; removeCarros permite vaciar el árbol para volver a leer el archivo modificado.

## Implementa mecanismos de lectura de archivos correctos
* Tanto sort.h, dlist.h y bst.h utilizan un mecanismo de lectura de archivos para llenar tanto el vector y el árbol como la lista doblemente ligada. Se hace uso de la librería fstream, que nos permite tanto leer como escribir archivos. En este caso se leen los datos del archivo llamado 'datos.csv' para todos los casos.

## Implementa mecanismos de escritura de archivos correctos
* dlist.h utiliza un mecanismo de escritura de archivos para reescribir el archivo de ventas cada vez que se actualiza o que se agrega un modelo con ventas. Se hace uso de la librería fstream, que nos permite tanto leer como escribir archivos. En este caso se escriben los datos en el archivo llamado 'datos.csv'. El archivo 'datos1.csv' es una copia de respaldo para reemplazar el archivo datos.csv.

# SICT0301B - Evalúa los componentes

## Presenta Casos de Prueba correctos y completos para todas las funciones y procedimientos del programa
* El main funciona al elegir la opción para la operación deseada; desplegar modelos en orden alfabético solo los imprime en la consola, mientras que la opción desplegar ventas ordenadas por medio de un árbol BST. La opción de actualizar ventas permite modificar el atributo cant por medio del atributo modelo; mientras que la opción de agregar modelo y ventas permite generar un objeto nuevo con atributos cant y modelo. Al igual que las dos opciones anteriores, la opción de buscar ventas por modelo recibe el string modelo para buscarlo en la lista ligada y obtener el atributo cant del objeto.
* El archivo pruebas.cpp se presentó en la Integral B.

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
* inorder -> Permite recorrer todo el árbol para después desplegarlo en la consola, como depende de la cantidad de nodos en el árbol, la complejidad temporal es de O(n) para todos los casos.
* findCarro -> Recorre el árbol hasta encontrar el valor deseado en los nodos, en el peor de los casos se tendría que recorrer todo el árbol, por lo que la complejidad temporal es de O(n).
* removeCarros -> Recorre el árbol hasta eliminar todos los nodos, depende de la cantidad de nodos existentes en el árbol; por lo que la complejidad temporal es de O(n).
* addCarro -> Recorre el árbol hasta encontrar la posición en donde se almacenará el objeto, en el peor de los casos tendría que recorrer todo el árbol; por lo que la complejidad temporal es de O(n).