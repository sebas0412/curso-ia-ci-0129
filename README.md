# Curso IA CI-0129



## Trabajo En Clase - Codigo Para 8-Tile Puzzle


## Realizado por

### Gerardo Campos Badilla, B81506

### Sebastian Chaves Vargas, B52067


## Observaciones

El algoritmo IDS utiliza la memoria y el CPU de manera mas eficiente, pues los
llamados recursivossolamente necesitan revisar una profundidad a la vez, 
lo cual evita ciclos.

En el caso del algoritmo 'Ancho Primero', es necesario utilizar colas para tener
un control de elementos visitados y frontera, lo cual puede llegar a utilizar mucha
memoria. Por otro lado, al existir tantos elementos en la cola, es necesario verificar
si un elemento ya existe antes de insertarse, lo cual es muy ineficiente para colas muy
grandes.