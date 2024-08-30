#pragma once

typedef struct Blog{
    char usuario[30];
    char comentario[255];
    int cantLetrasUsuario;
    int cantLetrasComentario;
}Blog;


typedef struct Nodo{
    struct Blog *blog;
    struct Nodo *sig;
    struct Nodo *prev;

}Nodo;

typedef struct Lista{
    Nodo *head;
    Nodo *tail;
    Nodo *current;
    int size;

}ListaDoble;

Nodo* crearNodo();
Blog* crearBlog();
ListaDoble* crearLista();
void pushFront(ListaDoble *lista);
void pushBack(ListaDoble *lista);
void pushPos(ListaDoble *lista, int pos);
Nodo* buscarNodo(ListaDoble *lista, int pos);
void liberarNodo(Nodo *nodo);
void printNodo(Nodo *nodo);
void mostrarLista(ListaDoble *lista);
void mostrarListaInversa(ListaDoble* lista);
void liberarLista(ListaDoble *lista);
ListaDoble* ordenarLista(ListaDoble* lista);
int borrarPos(ListaDoble *lista, int pos);
ListaDoble* veinteLetras(ListaDoble* lista);
ListaDoble* usuarioTresLetras(ListaDoble* lista);