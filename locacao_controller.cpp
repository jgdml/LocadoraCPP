#include <list>
#include<stdio.h>
#include"util.cpp"
#include"locacao.h"
#include "cliente.h"
#include "filme.h"
#include "filme_controller.cpp"
#include "cliente_controller.cpp"

using namespace std;

#ifndef _arquivo_locacao_controller_cpp_
#define _arquivo_locacao_controller_cpp_

list<Locacao> locacoes;

Locacao getLocacaoById(int id) {
    for (Locacao const &loc: locacoes) {
        if (loc.id == id) {
            return loc;
        }
    }
    return Locacao();
}

Locacao makeLocacaoTeste(int position) {
    Locacao locacao{};
    locacao.id = getNextId();
    auto clientePosition = std::next(clientes.begin(), position);
    locacao.cliente = *clientePosition;
    auto filmePosition = std::next(filmes.begin(), position);
    locacao.filme = *filmePosition;

    return locacao;
}

void listarLocacao() {
    for (Locacao const &lc: locacoes) {
        printf(linhasDeCima);
        printf("|   Id: %d\n", lc.id);
        printf("|   Cliente:  %s\n", lc.cliente.nome);
        printf("|   Filme:  %s", lc.filme.titulo);
        printf(linhasDeBaixo);
    }
}

void locarFilme() {
    int idFilme;
    int idCliente;
    Locacao locacao{};

    listarAcervo();
    printf("Escolha um filme pelo ID: ");
    scanf("%d", &idFilme);
    locacao.filme = getFilmeById(idFilme);
    if (!locacao.filme.id) {
        printf("Filme inexistente! ");
        return;
    }

    listarCliente();
    printf("Escolha um cliente pelo ID: ");
    scanf("%d", &idCliente);
    locacao.cliente = getClienteById(idCliente);
    if (!locacao.cliente.id) {
        printf("Cliente inexistente! ");
        return;
    }

    locacao.id = getNextId();
    locacoes.push_back(locacao);
    printf("Filme locado! \n");
}
 
void devolucaoFilme(){
    
    int escolha;

    listarLocacao();

    printf("Escolha o ID de um filme para realizar a devolução: ");
    scanf("%d", escolha);

    locacoes.remove(getLocacaoById(escolha));

}

#endif