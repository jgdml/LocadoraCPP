#ifndef _arquivo_locacao_h_
#define _arquivo_locacao_h_
#include "cliente.h"
#include "filme.h"

struct Locacao
{
    int id;
    Filme filme;
    Cliente cliente;

    int operator==(const Locacao &loc){
        return loc.id == id;
    }
};

#endif