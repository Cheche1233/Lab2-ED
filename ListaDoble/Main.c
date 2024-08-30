#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ListaDoble.h>



int main() {
    srand(time(NULL));


    /*1.- Genera 100 comentarios, se puede repetir por usuario
    2.- Guarda los comentarios del blog en una lista enlazada doble, utiliza random para elegir el tipo de inserción que se va usar por comentario.
    3.- Una vez que la lista tenga todos los comentarios, realiza lo siguiente
    genera una lista doble enlazada en donde este ordenado de el comentario que tiene menor cantidad de letras, hasta el comentario que tiene mayor cantidad de letras e imprimela
    genera una lista doble enlazada en donde solamente contenga los comentarios que tengan 20 letras o menos e imprimela
    4.- De la lista original de comentarios, elimina todos los comentarios cuyo usuario sea mayor a 3 letras
    5.- Imprime la lista original 
    6.- Imprime la lista original pero al revés
    7.- libera toda la memoria dinámica utilizada
    */
    ListaDoble *listaComentarios = crearLista();


    for(int i =0; i<=100; i++){
        int tipoInsercion = rand() % 3;
        if(tipoInsercion == 0){
            pushFront(listaComentarios);
        }
        else if(tipoInsercion == 1){
            pushBack(listaComentarios);
        }
        else{
            int posicionRandom = rand() % listaComentarios->size;
            pushPos(listaComentarios, posicionRandom);
        }
    }
    
    //ordenar menor a mayor comentarios
    //ordenarLista(listaComentarios);

    //filtrar solo comentarios con 20 letras
    //veinteLetras(listaComentarios);

    //filtrar usuarios con 3 letras
    //usuarioTresLetras(listaComentarios);

    //imprimir lista
    mostrarLista(listaComentarios);

    //imprimir lista inversa
    //mostrarListaInversa(listaComentarios);

    liberarLista(listaComentarios);

    
    return 0;
    
}
