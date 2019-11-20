#include <iostream>
#include "Cliente.h"

using namespace std;

Cliente::Cliente(){
	
	this->nomeCliente = "";
	this->cpf_cnpj = "";
	this->endereco = "";
	this->fone = "";
	
}

Cliente::Cliente(string newnome, string newcpf, string newendereco, string newfone) //construtor
{
	nomeCliente = newnome;
	cpf_cnpj = newcpf;
	endereco = newendereco;
	fone = newfone;
}

Cliente::Cliente(const Cliente& novocliente) //construtor de copia
{
	nomeCliente = novocliente.nomeCliente;
	cpf_cnpj = novocliente.cpf_cnpj;
	endereco = novocliente.endereco;
	fone = novocliente.fone;
}

Cliente::~Cliente() //destrutor
{

}

void Cliente::setNome(string novonome)
{
	nomeCliente = novonome;
}

void Cliente::setCPF_CNPJ(string novocpf)
{
	cpf_cnpj = novocpf;
}

void Cliente::setEndereco(string novoendereco)
{
	endereco = novoendereco;
}

void Cliente::setFone(string novofone)
{
	fone = novofone;
}
string Cliente::getNome()
{
	return nomeCliente;
}

string Cliente::getCPF_CNPJ()
{
	return cpf_cnpj;
}

string Cliente::getEndereco()
{
	return endereco;
}

string Cliente::getFone()
{
	return fone;
}

