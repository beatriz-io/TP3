#include "Banco.h"

Banco::Banco(string newBanco)
{
	nomeBanco = newBanco;
}

void Banco::addCliente(Cliente newCliente) {
	
	Arquivo a;
	string aux;
	
	aux = "./Bancos/" + this->nomeBanco + "/Clientes " + this->nomeBanco + ".txt";
	
	this->setClientList();
	this->clientes.push_back(newCliente);
	a.salvarListaClientes(aux,this->clientes);
	
}

void Banco::addConta(Cliente newConta) {

	Conta c(newConta);
	Arquivo a;
	string aux;
	
	aux = "./Bancos/Inter/Contas " + this->nomeBanco + ".txt";
	
	this->setClientList();
	this->setContaList();
	this->contas.push_back(c);
	a.salvarListaContas(aux,this->contas);
}

void Banco::removeCliente(string cpf) {
	
	for (auto it = clientes.begin(); it != clientes.end(); ++it) {
		if (it->getCPF_CNPJ() == cpf) {
			for (auto y : this->contas) {
				if (y.getCliente().getCPF_CNPJ() == cpf) {
					cout << "Este cliente nÃ£o pode ser removido pois possui uma Conta" << endl;
					return;
				}
			}
		}
		this->clientes.erase(it);
		return;
	}
}

void Banco::removeConta(int contaRemovida) {

	for (auto it = contas.begin(); it != contas.end(); ++it) {
		if (it->getNumConta() == contaRemovida) {
			this->contas.erase(it);
			break;
		}	
	}
}

string Banco::getnomeBanco() {
	return nomeBanco;
}


vector<Cliente> Banco::getClientList() {
		
	return this->clientes;
	
}

vector<Conta> Banco::getContasList() {
	
	return this->contas;
		
}


void Banco::deposito(int numConta, double valDeposito) {
	
	int count = 0;
	
	for (auto x : this->contas) {
		if (numConta == x.getNumConta()) {
				this->contas[count].creditarConta(valDeposito, "Deposito");
			break;
		}
		count++;
	}
}

void Banco::saque(int numConta, double valSaque) {
	
	int count = 0;
	
	for (auto x : this->contas) {
		if (numConta == x.getNumConta()) {
			this->contas[count].debitarConta(valSaque, "Saque");
			break;
		}
		count++;
	}
}

double Banco::getSaldo(int numConta) {
	for (auto x : this->contas) {
		if (numConta == x.getNumConta()) {
			double saldo = x.getSaldo();
			return saldo;
		}
	}
}

void Banco::transferencia(int contaorigem, int contadestino, double valorTransferencia) {
	
	int count = 0;
	
	for (auto x : this->contas) {
		if (contaorigem == x.getNumConta()) {
			this->contas[count].debitarConta(valorTransferencia, "Transferencia para a conta: " + contadestino);
			break;
		}
		count++;
	}
	
	count = 0;
	
	for (auto x : this->contas) {
		if (contadestino == x.getNumConta()) {
			this->contas[count].creditarConta(valorTransferencia, "Transferencia da conta: " + contaorigem);
			break;
		}
		count++;
	}
}

void Banco::tarifa() {
	
	int count = 0;
	
	for (auto x : this->contas) {
		this->contas[count].debitarConta(15, "Cobrança de tarifa");
		count++;
	}
}

vector<Move> Banco::extratomes(int numConta) {
	
	vector<Move> aux;
	int count = 0;
	
	for (auto x : this->contas) {
		if (numConta == x.getNumConta()) {		
			aux = this->contas[count].obterExtratoMes();			
			break;
		}
		count++;
	}
	return aux;
}

vector<Move> Banco::extratoentredatas(int numConta, Data di, Data df) {
	
	vector<Move> aux;
	int count = 0;
	
	for (auto x : this->contas) {
		if (numConta == x.getNumConta()) {
			aux = this->contas[count].obterExtratoEntreDatas(di, df);
			break;
		}
		count++;
	}
	return aux;
}

vector<Move> Banco::extratoapartirdata(int numConta, Data di) {
	
	vector<Move> aux;
	int count = 0;
	
	for (auto x : this->contas) {
		if (numConta == x.getNumConta()) {
			aux = this->contas[count].obterExtratoaPartirDeData(di);
			break;
		}
	}
	return aux;
}

void Banco::imposto() {
	
	int count = 0;
	vector<Move> vetMovi;
	
	for (auto x : this->contas) {
		float valor = 0;
		vetMovi = this->contas[count].getMovimentacoes();
		for (auto y : vetMovi) {
			if (y.getDC() == 'C') {
				valor += y.getValor();
			}
		}
		valor = valor * 0.0038;
		this->contas[count].debitarConta(valor, "Cobranca de CPMF");
		count++;
	}
}

void Banco::setClientList(){
	
	Arquivo a;
	string aux;
	
	aux = "./Bancos/" + this->nomeBanco + "/Clientes " + this->nomeBanco + ".txt";
	this->clientes = a.preencheVectorCliente(aux);
	
}

void Banco::setContaList(){
	
	Arquivo a;
	string aux;
	int count = 0;
	
	aux = "./Bancos/" + this->nomeBanco + "/Contas " + this->nomeBanco + ".txt";
	this->contas = a.preencheVectorConta(aux);
	for(auto x : this->contas){
		for(auto y : this->clientes){
			if(this->contas[count].getCliente().getCPF_CNPJ() == y.getCPF_CNPJ()) {
				this->contas[count].setCliente(y);
			}
		}
	}
}

void Banco::salvar(){
	
	Arquivo a;
	string aux = "./Bancos/" + this->nomeBanco + "/Contas " + this->nomeBanco + ".txt";

	a.salvarListaContas(aux,this->contas);
	aux = "./Bancos/" + this->nomeBanco + "/Clientes " + this->nomeBanco + ".txt";
	a.salvarListaClientes(aux,this->clientes);
}

Banco::~Banco()
{
}


