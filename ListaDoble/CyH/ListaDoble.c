#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaDoble.h"

//Generar letras random
char generarLetraAleatoria() {
    return 'A' + (rand() % 26);
}

void generarTexto(char *texto, int tamano) {
    for (int i = 0; i < tamano; i++) {
        texto[i] = generarLetraAleatoria();
    }
    texto[tamano] = '\0';  
}

Nodo* crearNodo() {
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->sig = NULL;
    nodo->prev = NULL;
    nodo->blog = crearBlog();
    return nodo;
}

Blog* crearBlog() {
    Blog* nodoBlog = (Blog*)malloc(sizeof(Blog));
    int randomSizeUsuario = rand()% 28;
    for(int i=0; i< randomSizeUsuario; i++){
        nodoBlog->usuario[i] = generarLetraAleatoria();
        
    }

    int randomSizeComentario = rand()% 255;
    for(int i = 0; i<randomSizeComentario; i++){
        nodoBlog->comentario[i] = generarLetraAleatoria();
    }

    nodoBlog->cantLetrasUsuario = strlen(nodoBlog->usuario);
    nodoBlog->cantLetrasComentario = strlen(nodoBlog->comentario);

    return nodoBlog;
}

ListaDoble* crearLista() {
    ListaDoble* lista = (ListaDoble*)malloc(sizeof(ListaDoble));
    lista->head = NULL;
    lista->tail = NULL;
    lista->current = NULL;
    lista->size = 0;
    return lista;
}

void pushFront(ListaDoble* lista) {
    Nodo* nodo = crearNodo();
    Blog* nodoBlog = crearBlog();
    nodo->blog = nodoBlog;
    if (lista->head == NULL) {
        lista->tail = nodo;
    } else {
        nodo->sig = lista->head;
        lista->head->prev = nodo;
    }
    lista->head = nodo;
    lista->size++;
}

void pushBack(ListaDoble* lista) {
    Nodo* nodo = crearNodo();
    Blog* nodoBlog = crearBlog();
    nodo->blog = nodoBlog;
    if (lista->tail == NULL) {
        lista->head = nodo;
    } else {
        nodo->prev = lista->tail;
        lista->tail->sig = nodo;
    }
    lista->tail = nodo;
    lista->size++;
}

void pushPos(ListaDoble* lista, int pos) {
    if (pos == 0) {
        pushFront(lista);
    } else if (lista->size == pos) {
        pushBack(lista);
    } else {
        Nodo* nodo = crearNodo();
        Blog* nodoBlog = crearBlog();
        nodo->blog = nodoBlog;
        Nodo* ant = buscarNodo(lista, pos-1);
        if (ant != NULL) {
            nodo->sig = ant->sig;
            nodo->prev = ant;
            if (ant->sig != NULL) {
                ant->sig->prev = nodo;
            ant->sig = nodo;
            lista->size++;
        }
    }
    }
}

Nodo* buscarNodo(ListaDoble* lista, int pos) {
    if (pos < 0 || pos >= lista->size) {
        return NULL;
    }

    Nodo* actual = lista->head;
    for (int i = 0; i < pos; i++) {
        actual = actual->sig;
    }

    return actual;
}

void mostrarLista(ListaDoble* lista) {
    lista->current = lista->head;
    while (lista->current != NULL) {
        printNodo(lista->current);
        lista->current = lista->current->sig;
    }
    printf("\n");
}

void mostrarListaInversa(ListaDoble* lista) {
    lista->current = lista->tail;
    while (lista->current != NULL) {
        printNodo(lista->current);
        lista->current = lista->current->prev;
    }
    printf("\n");
}

void liberarNodo(Nodo *nodo) {
    if (nodo != NULL) {
        free(nodo->blog);
        free(nodo);
    }
}
void liberarLista(ListaDoble* lista) {
    Nodo* current = lista->head;
    Nodo* siguiente;

    while (current != NULL) {
        siguiente = current->sig;
        liberarNodo(current);
        current = siguiente;
    }
    
    free(lista);
}

void printNodo(Nodo *nodo) {
    if (nodo != NULL) {
        printf("Usuario: %s\n", nodo->blog->usuario);
        printf("Comentario: %s\n", nodo->blog->comentario);
        printf("        |       \n");
        printf("        v       \n");
    }
}

ListaDoble* ordenarLista(ListaDoble* lista) {
    Nodo* actual;
    Nodo* sigActual;

    if (lista->size < 2) {
        return lista;
    }

    for (int i = 0; i < lista->size - 1; i++) {
        actual = lista->head;
        sigActual = actual->sig;

        for (int j = 0; j < lista->size - 1 - i; j++) {
            if ((actual->blog->cantLetrasComentario) > (sigActual->blog->cantLetrasComentario)) 
            {
                Blog* temp = actual->blog;
                actual->blog = sigActual->blog;
                sigActual->blog = temp;
            }
            actual = sigActual;
            sigActual = sigActual->sig;
        }
    }

    return lista;
}

int borrarPos(ListaDoble *lista, int pos){
    if(pos == 0){
        Nodo *temp = lista->head->sig;
        free(lista->head->blog);
        free(lista->head);
        lista->head = temp;
        lista->size--;
        return 1;
    }
    Nodo *temp1;
    temp1 = buscarNodo(lista, pos-1);
    Nodo *nodoAborrar = buscarNodo(lista, pos);
    temp1->sig = nodoAborrar->sig;
    free(nodoAborrar->blog);
    free(nodoAborrar);
    if(pos == lista->size-1){
        lista->tail = temp1;
    }
    lista->size--;
    return 1;
}

ListaDoble* veinteLetras(ListaDoble* lista) {
    Nodo* actual = lista->head;
    int i = 0;

    while (actual != NULL) {
        Nodo* siguiente = actual->sig;

        if (actual->blog->cantLetrasComentario >= 21) {
            borrarPos(lista, i);
        } else {
            i++;
        }

        actual = siguiente;
    }

    return lista;
}

ListaDoble* usuarioTresLetras(ListaDoble* lista) {
    Nodo* actual = lista->head;
    int i = 0;

    while (actual != NULL) {
        Nodo* siguiente = actual->sig;

        if (actual->blog->cantLetrasUsuario >= 3) {
            borrarPos(lista, i);
        } else {
            i++;
        }

        actual = siguiente;
    }

    return lista;
}



