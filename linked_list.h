#ifndef LISTA_ENCADEADA_SIMPLES_H
#define LISTA_ENCADEADA_SIMPLES_H
#include <iostream>

using namespace std;

template<typename T>
struct TElemento{
    T dado;
    TElemento *proximo;
};

template<typename T>
struct TListaEnc{
  TElemento <T> *inicio;
};

template<typename T>
void inicializaListaE(TListaEnc<T> &lista){
    lista.inicio = NULL;   
}

//------------------------------------insercao-----------------------------------------

template<typename T>
void insercaoFinal(TListaEnc<T> &lista, T dado){
    TElemento<T> *novo_elemento = new TElemento<T>;
    novo_elemento->dado = dado;
    novo_elemento->proximo = NULL;

    if(lista.inicio == NULL){
        lista.inicio = novo_elemento;
    }

    TElemento<T> *aux = lista.inicio;

    while (aux->proximo != NULL) {
        aux = aux->proximo;
    }
    aux->proximo = novo_elemento;
}

template<typename T>
void insercaoInicio(TListaEnc<T> &lista, T dado){
    TElemento<T> *novo_elemento = new TElemento<T>;
    novo_elemento->dado = dado;
    novo_elemento->proximo = lista.inicio;
    lista.inicio = novo_elemento;
}

template<typename T>
void insercaoPosicao(TListaEnc<T> &lista, T dado, int pos){
    TElemento<T> *novo_elemento = new TElemento<T>;
    TElemento<T> *aux = lista.inicio;

    int cont = 0;
    while(aux->proximo != NULL){
        cont ++;
        aux = aux->proximo;

        if(cont == pos){
            novo_elemento->dado = dado;
            novo_elemento->proximo = aux->proximo;
            aux->proximo = novo_elemento;
        }
    }
}

//-----------------------------------remocao----------------------------------------------

template<typename T>
int remocaoFinal(TListaEnc<T> &lista){
    if(lista.inicio == NULL){
        return 0;
    }

    TElemento<T> *anterior, *elemento = lista.inicio;
    while(elemento->proximo != NULL){
        anterior = elemento;
        elemento = elemento->proximo;

    }
    if (elemento == lista.inicio){ // é o ultimo elemento da lista? remover o primeiro?
        lista.inicio = elemento->proximo;

    }
    else{
        anterior->proximo = elemento->proximo;
        delete elemento;
        return 1;
    }
}
template<typename T>
int remocaoInicio(TListaEnc<T> &lista){
    if (lista.inicio == NULL){
        return 0;
    }
    TElemento<T> *aux = lista.inicio;
    lista.inicio = aux->proximo;
    delete aux;
}



#endif // LISTA_ENCADEADA_SIMPLES_H
