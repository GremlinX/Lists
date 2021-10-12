#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H
#include <iostream>

using namespace std;

template<typename T>
struct TElemento{
    T dado;
    TElemento *proximo;
    TElemento *anterior;
};

template<typename T>
struct TListaEncadCir{
    TElemento<T>* inicio;
    TElemento<T>* fim;
};
template<typename T>
TElemento<T>* criarElemento(T valor){
    TElemento<T>* elemento = new TElemento<T>;
    elemento->dado = valor;
    elemento->proximo = elemento->anterior = NULL;
    return elemento;
}

template<typename T>
TListaEncadCir<T>* inicializarLista(){
    TListaEncadCir<T>* lista = new TListaEncadCir<T>;
    lista->inicio = lista->fim = NULL;
    return lista;
}

template<typename T>
void insercaoInicio(TListaEncadCir<T>* lista, T valor) {
    TElemento<T>* criarElemento(valor);
    TElemento<T>* elemento = criarElemento(valor);;
    if (lista->inicio == NULL) {
        lista->inicio = lista->fim = elemento;
    }
    elemento->proximo = lista->inicio;
    lista->inicio->anterior = elemento;
    lista->inicio = elemento;
}

template<typename T>
void insercaoFinal(TListaEncadCir<T>* lista, T valor) {
    TElemento<T>* criarElemento(valor);
    TElemento<T>* elemento = criarElemento(valor);
    if (lista->inicio == NULL) {
        lista->inicio = lista->fim = elemento;

    } else {
        elemento->anterior = lista->fim;
        lista->fim->proximo = elemento;
        lista->cauda = elemento;
    }
}

template<typename T>
void insrcaoPosicao(TListaEncadCir<T>* lista, T valor) {
    TElemento<T>* criarElemento(valor);
    TElemento<T>* elemento = criarElemento(valor);
    if (lista->inicio == NULL) {
        lista->inicio = lista->fim = elemento;

    } else {
        int quantidade = 0;
        TElemento<T>* tmp = lista->inicio;
        // Encontra o nó, cujo valor é menor ou igual ao
        // valor requisitado.
        while (tmp->proximo != NULL && quantidade <= valor) {
            tmp = tmp->proximo;
            quantidade++;
        }
        elemento->anterior = tmp;
        tmp->proximo = elemento;
        if (tmp == lista->inicio) {
            lista->inicio = elemento;
            lista->fim = elemento->anterior;
        }
    }
}

template<typename T>
TElemento<T>* obterElemento(TListaEncadCir<T>* lista, T valor) {
    if (lista->inicio == NULL){
        return NULL;
    }
    if (lista->inicio == lista->fim){
        return lista->inicio; // 1 elemento
    }
    TElemento<T>* inicioAtual = lista->inicio;
    TElemento<T>* fimAtual = lista->fim;

    // Move os ponteiros Inicio e Fim até que um
    // dos dois ache o valor requisitado.
    //  I============>               <===========F
    // [1] <-> [5] <-> [6] <-> [10] <-> [3] <-> [9]
    while (inicioAtual != fimAtual) {
        if (inicioAtual != NULL && fimAtual->valor == valor){
            return inicioAtual;
        }
        else if (inicioAtual != NULL){
            inicioAtual = inicioAtual->next;
        }
        if (fimAtual != NULL && fimAtual->value == valor){
            return fimAtual;
        }
        else if (fimAtual != NULL){
            fimAtual = fimAtual->anterior;
        }
    }
    return NULL;
}

template<typename T>
bool remocaoInicio(TListaEncadCir<T>* lista, T valor) {
    TElemento<T>* elemento = obterElemento(lista, valor);
    if (elemento == NULL){
        return false;
    }
    // Remove do Inicio
    if (elemento->anterior == NULL) { 
        TElemento<T>* tmp = lista->inicio;
        lista->inicio = lista->inicio->proximo;
        lista->inicio->anterior = NULL;
        free(tmp);
        return true;
    }
}
template<typename T>
bool remocaoFinal(TListaEncadCir<T>* lista, T valor) {
    TElemento<T>* elemento = obterElemento(lista, valor);
    if (elemento == NULL){
        return false;
    }
    // Remove do Fim
    if (elemento->proximo == NULL) { 
        TElemento<T>* tmp = lista->fim;
        lista->fim = lista->fim->anterior;
        lista->fim->proximo = NULL;
        delete (tmp);
        return true;
    }
}
template<typename T>
bool remocaoPosicao(TListaEncadCir<T>* lista, int pos) {
    TElemento<T>* elemento = obterElemento(lista, pos);
    if (elemento == NULL){
        return false;
    }
    if ((insercaoInicio(lista, pos) && remocaoFinal(lista, pos)) == false){
        TElemento<T>* ant = elemento->anteiror;
        TElemento<T>* prox = elemento->proximo;
        ant->proximo = prox;
        prox->anteiror = ant;
        delete (elemento);
        return true;
    }
}

template<typename T>
void remocaoPosicao(TListaEncadCir<T>* lista, T valor) {
    cout << "[";
    TElemento<T>* atual = lista->inicio;
    while (atual != NULL) {
        if (atual->proximo == NULL) {
            cout << atual->valor;
        } else {
            cout << atual->valor;
        }
        atual = atual->proximo;
    }
    cout << "]" << endl;
}

#endif // LISTA_CIRCULAR_H
