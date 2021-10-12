#ifndef LISTA_ENCADEADA_DUPLA_H
#define LISTA_ENCADEADA_DUPLA_H
#include <iostream>

using namespace std;


template<typename T>
struct TElemento{
    T dado;
    TElemento *proximo;
    TElemento *anterior;
};

template<typename T>
struct TListaDuplaEnc{
    TElemento<T>* inicio;
    TElemento<T>* cauda;
};

template <typename T>
void InicializaLista(TListaDuplaEnc<T> &lista){
    lista.primeiro = nullptr;
    lista.ultimo = nullptr;
}

template<typename T>
TElemento<T>* criarElemento(T dado){
    TElemento<T>* elemento = new TElemento<T>;
    elemento->dado = dado;
    elemento->proximo = elemento->anterior = NULL;
    return elemento;
}

template<typename T>
TListaDuplaEnc<T>* criarLista(){
    TListaDuplaEnc<T>* lista = new TListaDuplaEnc<T>;
    lista->inicio = lista->cauda = NULL;
    return lista;
}

template<typename T>
void insercaoInicio(TListaDuplaEnc<T>* lista, T dado) {
    TElemento<T>* criarElemento(dado); // Ou coloca a função LDupl...head() antes da node_new(valor).
    TElemento<T>* elemento = criarElemento(dado);
    if (lista->inicio == NULL) {
        lista->inicio = lista->cauda = elemento;
    }
    elemento->proximo = lista->inicio;
    lista->inicio = elemento;
    lista->inicio = elemento;
    lista->anterior = NULL;
}


template<typename T>
void InsercaoPosicao(TListaDuplaEnc<T>* lista, T dado) {
    TElemento<T>* criarElemento(dado); 
    TElemento<T>* elemento = criarElemento(dado);
    if (lista->inicio == NULL) {
        lista->inicio = lista->cauda = elemento;
    } else {
        TElemento<T>* tmp = lista->inicio;
        // Encontra o nó, na qual o valor é menor ou igual ao
        // valor requisitado.
        int quantidade = 0;
        while (tmp->proximo != NULL && quantidade <= dado) {
            tmp = tmp->proximo;
            quantidade++;
        }
        elemento->promixo = tmp;
        tmp->anterior = elemento;
        if (tmp == lista->inicio) {
            lista->inicio = elemento;
        }
    }
}

template<typename T>
TElemento<T>* obterElemento(TListaDuplaEnc<T>* lista, T dado) {
    if (lista->inicio == NULL){
        return NULL;
    }
    if (lista->inicio == lista->cauda){
    return lista->inicio; // 1 elemento
    }

    TElemento<T>* inicioAtual = lista->inicio;
    TElemento<T>* caudaAtual = lista->cauda;

    // Move os ponteiros Inicio e Fim até que um
    // dos dois ache o valor requisitado.
    //  I============>               <===========F
    // [1] <-> [5] <-> [6] <-> [10] <-> [3] <-> [9]
    while (inicioAtual != caudaAtual) {
        if (inicioAtual != NULL && inicioAtual->valor == dado){
            return inicioAtual;
        }
        else if (inicioAtual != NULL){
            inicioAtual = inicioAtual->proximo;
        }
        if (caudaAtual != NULL && caudaAtual->value == dado){
            return caudaAtual;
        }
        else if (caudaAtual != NULL){
            caudaAtual = caudaAtual->anterior;
        }
    }
    return NULL;
}

template<typename T>
bool remocaoInicio(TListaDuplaEnc<T>* lista, T valor) {
    TElemento<T>* no = obterElemento(lista, valor);
    if (no == NULL){
        return false;
    }
    if (no->anterior == NULL) { // Remove do Inicio
        TElemento<T>* tmp = lista->inicio;
        lista->inicio = lista->inicio->proximo;
        lista->inicio->anterior = NULL;
        delete (tmp);
        return true;
    }
}
template<typename T>
bool remocaoFinal(TListaDuplaEnc<T>* lista, int valor) {
    TElemento<T>* elemento = obterElemento(lista, valor);
    if (elemento == NULL){
        return false;
    }
    if (elemento->proximo == NULL) { // Remove do Fim
    TElemento<T>* tmp = lista->cauda;
    lista->cauda = lista->cauda->anterior;
    lista->cauda->proximo = NULL;
    delete (tmp);
    return true;
    }
}
template<typename T>
bool remocaoPosicao(TListaDuplaEnc<T>* lista, int valor) {
    TElemento<T>* elemento = obterElemento(lista, valor);
    if (elemento == NULL){
        return false;
    }
    if ((remocaoInicio(lista, valor) && remocaoFinal(lista, valor)) == false){
        TElemento<T>* prev = elemento->anteiror;
        TElemento<T>* next = elemento->proximo;
        prev->proximo = next;
        next->anteiror = prev;
        free(elemento); // delete elemento, ambos funcionam
        return true;
    }
}

template<typename T>
void imprimirLista(TListaDuplaEnc<T>* lista) {
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

#endif // LISTA_DE_H
