# lista_enlazada
Programa feito en C que crea, invirte e borra unha lista simplemente enlazada usando punteiros (linked list).
Cada elemento da lista é un nodo que contén un número enteiro.
Cada nodo será consecutivo, o usuario debe indicar o valor inicial e o número de elementos da lista.

Modo de compilación:

$ gcc -Wall lista_enlazada.c -o lista_enlazada

Uso: ./lista_enlazada <VALOR_INICIAL> <NUM_VALORES>

Por exemplo, se queres crear e invertir unha lista de seis elementos comezando por -2 tes que executalo así:

$ ./lista_enlazada -2 6
Contido da lista creada:
 -2, -1, 0, 1, 2, 3
Contido da lista invertida:
 3, 2, 1, 0, -1, -2
Contido da lista borrada:
Lista baleira.
