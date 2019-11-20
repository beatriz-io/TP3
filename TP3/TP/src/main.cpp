#include <iostream>
#include <vector>
#include "../Controller/FileIO.h"
#include "../Model/Banco.h"
#include "../View/Interface.h"
#include <conio.h>

using namespace std;

int main(){

	setlocale( LC_ALL, "Portuguese" );
	Conta c;
	Banco b("Inter");
	Interface i;
	
	i.menu(b);	
	
	/*
	for(i = 0; i < c.size(); i++){

		cout << "Nome: " << c[i].getNome() << " CPF: " << c[i].getCPF_CNPJ() << " Endereço: " << c[i].getEndereco() << " Fone: " << c[i].getFone() << endl;
	}
	
	cout << "\n\n\n\n\n\n";
	
	for(auto x : co){
		
		cout << "Num: " << x.getNumConta() << " Saldo: " << x.getSaldo() << " CPF ou CNPJ: " << x.getCliente().getCPF_CNPJ() << endl;
		
	}*/
	
	/*for(auto s : b.getClientList()){
		
		if(m[s.getCPF_CNPJ()].getCliente().getNome() == ""){
			continue;
		}
		cout << "Nome: " << m[s.getCPF_CNPJ()].getCliente().getNome() 
		<< " CPF: " << m[s.getCPF_CNPJ()].getCliente().getCPF_CNPJ() 
		<< " Endereço: " << m[s.getCPF_CNPJ()].getCliente().getEndereco() 
		<< " Fone: " << m[s.getCPF_CNPJ()].getCliente().getFone() << endl;
		
		cout << "Num: " << m[s.getCPF_CNPJ()].getNumConta() 
		<< " Saldo: " << m[s.getCPF_CNPJ()].getSaldo() << endl;
		cout << "\n";
			
	}*/
	
	
	
	return 0;

}
