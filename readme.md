# Count Reference Implemetation

En este repositorio implemente, un contador de referencias basicos, ademas de hacer que su 
funcionamiento, fuera similas a un __shared_ptr__ de la libreria estandar de C++.

# Problemas

El operador de movimiento de __ReferenceCount__, no funciona del todo bien, porque  si el puntero 
que es movido, es usado, el programa falla por un segment fault, a causa de un puntero nulo.
Esto pense que es un problema de mi implementacion, pero el __shared_ptr__, sufre del mismo problema.

Gracias a esto, entendi, porque los smart pointer y move sematics son conceptos, que falla entre si,
porque los smart pointer, solo son una envoltura del un puntero sin formato, y es subestible a los 
fallos de los punteros sin formato.


# Cosas a implementar en el futuro

- Un metodo parecido al _make__ de los smart_pointer para facilitar la creacion de instancias de
  objetos.