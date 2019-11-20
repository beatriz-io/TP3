#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#include <iostream>
#include <vector>
#include <list>
#include <cstdio>
#include "../Model/Banco.h"
#include "../Model/Cliente.h"
#include "../Model/Conta.h"
#include "../Controller/FileIO.h"

using namespace std;

class Interface{

    public:

    Interface();
    void menu(Banco b);
    void cadastraNovoCliente(Banco b);
    void criarNovaConta(Banco b);
    void excluiCliente(Banco b);
    void excluiConta(Banco b);
    void deposito(Banco b);
    void saque(Banco b);
    void transferencia(Banco b);
    void obterSaldo(Banco b);
    void cobrarTarifa();
    void cobrarCPMF();
    void obterExtrato(Banco b);
    void listarClientes(Banco b);
    void listarContas(Banco b);
    ~Interface();

};

#endif // INTERFACE_H_INCLUDED
