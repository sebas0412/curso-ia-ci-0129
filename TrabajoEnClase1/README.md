# Curso IA CI-0129

## Tarea A*


## Realizado por

### Gerardo Campos Badilla, B81506

### Sebastian Chaves Vargas, B52067

## Observaciones

En cuanto a las métricas de rendimiento, el algoritmo IDS y A* (El cual también es un tipo de IDS) utilizan casi la misma cantidad de memoria, pues son algoritmos recursivos que no necesitan almacenar estados visitados ni fronteras.

El algoritmo Ancho Primero hace un uso significativo de la memoria (unos cuantos megabytes), pues debe almacenarse cada estado distinto en una cola. Además, el algoritmo Ancho Primero debe hacer muchas comparaciones para verificar si un estado ya existe en la cola o no, por lo que se afecta mucho su rendimiento

El algoritmo con DFS con heurística de Greedy search es extremadamente rápido y no usa casi nada de memoria para encontrar una respuesta aproximada pero no siempre puede encontrar la solución óptima.
