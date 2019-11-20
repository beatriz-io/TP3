#include "CheckData.h"

using namespace std;

bool VerificaDados::verficaCPF_CNPJ(string cpf_cnpj){
	
	return ((cpf_cnpj.size() == 11 || cpf_cnpj.size() == 14 ) && isNumeric(cpf_cnpj));
	
}

bool VerificaDados::verificaEndereco(string endereco){
	
	int i;
	bool numero = false, caracter = false;
	
	for(i = 0; i < endereco.size(); i++){
		
		if(endereco[i] >= 65 && endereco[i] <= 90 || endereco[i] >= 97 && endereco[i] <= 122)	{
			caracter = true;
		}
		
		if(endereco[i] >= 48 && endereco[i] <= 57){
			numero = true;
		}
	}
	return caracter && numero;
}

bool VerificaDados::verificaFone(string fone){
	
	return (fone.size() == 9 && isNumeric(fone));
	
}

bool VerificaDados::verificaNome(string nome){
	
	int i;
	bool check = true;
	
	for(char c : nome){
		
		if(nome[i] < 65 && nome[i] > 90 || nome[i] < 97 && nome[i] > 122)	{
			check = false;
		}
	}
	return check;
}

bool VerificaDados::verificaNumConta(int numConta){
	
	return (numConta % 1000 <= 9 && numConta % 1000 >= 1);
	
}

bool VerificaDados::isNumeric(string s){
	
	int i;
	
	for(i = 0;i < s.size() - 1;i++) {
		if((int)s[i] >= 48 &&  (int)s[i] <= 57) {
			return true;
		} else {
			return false;
		}
	}	
}
