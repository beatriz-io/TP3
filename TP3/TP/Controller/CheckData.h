#include <iostream>



class VerificaDados{
	
	public:
		
		bool verficaCPF_CNPJ(std::string cpf_cnpj);
		bool verificaNome(std::string nome);
		bool verificaSaldo(double saldo);
		bool verificaEndereco(std::string endereco);
		bool verificaFone(std::string fone);
		bool verificaNumConta(int numConta);
		bool isNumeric(std::string s);
};
