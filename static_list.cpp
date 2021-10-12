#include <iostream>
#include "lista_estatica.h"

using namespace std;

void iniciarListaEstatica(ListaEstatica &lista){
    lista.quantidade = 0;
    cout << "Lista estatica inicializada..." << endl;
}

void inserirFinal(ListaEstatica &lista, Arquivo arquivo){
    lista.arquivos[lista.quantidade] = arquivo;
    lista.quantidade++;
}

void inserirInicio(ListaEstatica &lista, Arquivo arquivo){
    for(int i = lista.quantidade; i > 0; i--){
        lista.arquivos[i] = lista.arquivos[i-1];
    }
    lista.arquivos[0] = arquivo;
    lista.quantidade++;
}

void inserirPosicao(ListaEstatica &lista, Arquivo arquivo, int index){
    if(index <= lista.quantidade){
        for(int i = lista.quantidade; i > index; i--){
            lista.arquivos[i] = lista.arquivos[i-1];
        }
        lista.arquivos[index] = arquivo;
        lista.quantidade++;
    } else {
        cout << "Nao pode inserir nesta posicao... \n";
    }
}

void removerFinal(ListaEstatica &lista){
    if(lista.quantidade > 0){
      lista.quantidade--;
    } else {
        cout << "Erro ao remover no final! \n";
    }
}

void removerInicio(ListaEstatica &lista){
    for(int i = 1; i < lista.quantidade; i++){
       lista.arquivos[i-1] = lista.arquivos[i];
    }
    lista.quantidade--;
}

void removerPosicao(ListaEstatica &lista, int index){
    if(index <= lista.quantidade){
        for(int i = index; i < lista.quantidade; i++){
            lista.arquivos[i] = lista.arquivos[i+1];
        }
        lista.quantidade--;
    }
}

void imprimeLista(ListaEstatica &lista){
    for(int i = 0; i < lista.quantidade; i++){
        cout << "Item[" << i << "] = " << lista.arquivos[i].nome << " " << lista.arquivos[i].tamanho << endl;
    }
}
