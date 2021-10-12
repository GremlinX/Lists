#ifndef LISTA_ESTATICA_H_INCLUDED
#define LISTA_ESTATICA_H_INCLUDED

#include <iostream>

using namespace std;

struct Arquivo{
    string nome;
    //Arquivo computador;
    int tamanho; // tamanho do arquivo
    //Dispositivo diretorio_origem;
    //dataCriacao
    //dataTransf (hora atual do pc)
};

struct Repositorio{
    Arquivo arquivo_repositorio[10000];
};

struct Dispositivo{
    int nome;
    int codigo_fabrica;
};

struct ListaEstatica{
    Arquivo arquivos[10];
    int quantidade;
};

void inicializarLista(ListaEstatica &lista);
void inserirInicio(ListaEstatica &lista, int item);
void inserirFinal(ListaEstatica &lista, int item);
void inserirPosicao(ListaEstatica &lista, int item, int index);
void removerInicio(ListaEstatica &lista);
void removerFinal(ListaEstatica &lista);
void removerPosicao(ListaEstatica &lista, int index);
void imprimeLista(ListaEstatica &lista);

#endif // LISTA_ESTATICA_H_INCLUDED
