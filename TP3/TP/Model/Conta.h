#ifndef CONTA_H_
#define CONTA_H_


#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include "Cliente.h"
#include "Move.h"
#include "Data.h"


using namespace std;

class Conta{
	
	public:
		
		//Construtor
		
		Conta();
		Conta(Cliente c);
		Conta(int numConta, double Saldo, string cpf_cnpj);
		
		//Getters
		
		int getNumConta();
		double getSaldo();
		Cliente getCliente();
		vector<Move> getMovimentacoes();
		static int getProxNumConta();
		
		//Metodos
		
		int gerarNumConta();
		void debitarConta(double debito, string descricao);
		void creditarConta(double credito, string descricao);
		vector<Move> obterExtratoEntreDatas(Data di, Data df);
		vector<Move> obterExtratoaPartirDeData(Data di);
		vector<Move> obterExtratoMes();

		//Setters

		void setCliente(Cliente c);
		
	private:
		
		int numConta;
		double saldo;
		Cliente cliente;
		vector<Move> movimentacoes;
		int proxNumConta;
	
};

#endif
