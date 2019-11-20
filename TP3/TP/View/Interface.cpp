#include "Interface.h"

using namespace std;

Interface::Interface(){}

Interface::~Interface(){}

void Interface::menu(Banco b){
	
    int opc;
    
    while(1){
    	
    	b.setClientList();
    	b.setContaList();
    	cout << "\t\t\t  Bem Vindo ao Banco " << b.getnomeBanco() << "!\n\n";
        cout << ("\nEscolha uma Funcao\n\n");
        cout << ("  [1] - Cadastrar um novo cliente\n");
        cout << ("  [2] - Criar uma nova conta\n");
        cout << ("  [3] - Excluir uma conta\n");
        cout << ("  [4] - Efetuar deposito\n");
        cout << ("  [5] - Efetuar saque\n");
        cout << ("  [6] - Efetuar transferencia\n");
        cout << ("  [7] - Cobrar tarifa\n");
        cout << ("  [8] - Cobrar CPMF\n");
        cout << ("  [9] - Obter saldo\n");
        cout << ("  [10] - Obter extrato\n");
        cout << ("  [11] - Listar clientes\n");
        cout << ("  [12] - Listar contas\n");
        cout << ("  [0] - Sair do programa\n");
        cout << ("\n\n");
		
		cin >> opc;
		cin.ignore();

    switch(opc){
        case 1:
            cadastraNovoCliente(b);
            break;

        case 2:
            criarNovaConta(b);
            break;

        case 3:
            excluiConta(b);
            break;

        case 4:
            deposito(b);
            break;

        case 5:
            saque(b);
            break;

        case 6:
            transferencia(b);
            break;

        case 7:
            b.tarifa();
            break;

        case 8:
            b.imposto();
            break;

        case 9:
            obterSaldo(b);
            break;

        case 10:
            obterExtrato(b);
            break;

        case 11:
            listarClientes(b);
            break;

        case 12:
            listarContas(b);
        break;
        
        default:
        	system("cls");
        	cout << "Por favor selecione uma opção valida!" << endl;
        }
    }
}

void Interface::cadastraNovoCliente(Banco b){

    Cliente novoCliente;
    string aux;

    //cadastrar novo cliente
    cout << "Digite o nome do novo cliente: " ;
    getline(cin,aux);
	novoCliente.setNome(aux);
	aux.clear();
    cout << "Digite o CPF ou o CNPJ: ";
    cin >> aux;
    cin.ignore();
	novoCliente.setCPF_CNPJ(aux);
	aux.clear();
    cout << "Digite o endereço: ";
    getline(cin,aux);
	novoCliente.setEndereco(aux);
	aux.clear();
    cout << "Digite o telefone: ";
    cin >> aux;
    cin.ignore();
	novoCliente.setFone(aux);
	aux.clear();

    b.addCliente(novoCliente);
    
    cout << "Cliente adicionado com sucesso" << endl;
    system("pause");
    system("cls");
}

void Interface::criarNovaConta(Banco b){

    string CPF;
	vector<Cliente> clientes;
	int i = 1;
	
    clientes = b.getClientList();
    cout << "Selecione Um cliente da lista: " << endl;
    
    for(auto x : clientes){
    	
    	cout << i << " : " << x.getNome() << endl;
    	i++;
    	
	}
    
    cout << "\n\n";
    cin >> i;
    cin.ignore();
    
    b.addConta(clientes[i - 1]);
    
    cout << "Conta criada com sucesso!" << endl;
    cout << "Bem Vindo(a) ao banco " << b.getnomeBanco() << " " << clientes[i - 1].getNome() << "!!!" << endl;

}

void Interface::excluiCliente(Banco b){

    string CPF, s;
    vector<Conta> contas;

    cout << "Digite o CPF do cliente a ser excluido: " ;
    cin >> CPF;
    cin.ignore();
    
    for(auto x : contas){
    	if(x.getCliente().getCPF_CNPJ() == CPF){
    		s = x.getCliente().getNome();
		}
	}
    
    cout << "O cliente escolhido foi: " << s << endl;
    b.removeCliente(CPF);

}

void Interface::excluiConta(Banco b){

    int numConta;

    cout << "Escolha a conta a ser excluida: " ;
    cin >> numConta;
    cin.ignore();
    cout << "A conta escolhida foi: " << numConta << endl;
    b.removeConta(numConta);
    b.salvar();

}

void Interface::deposito(Banco b){

    float valDeposito;
    int numConta;

    cout << "Escolha o valor de deposito: " ;
    cin >> valDeposito;
    cin.ignore();
    cout << "Digite o numero conta que recebera o deposito: ";
    cin >> numConta;
    cin.ignore();
    cout << "Deposito de " << valDeposito << " reais, na conta: " << numConta << endl;
    b.deposito(numConta, valDeposito);
    b.salvar();

}

void Interface::saque(Banco b){

    float valSaque;
    int numConta;
	
	cout << "Digite o numero da conta que deseja sacar o valor solicitado: ";
    cin >> numConta;
    cin.ignore();
    cout << "Escolha o valor de saque: ";
    cin >> valSaque ;
    cin.ignore();
    cout << "Saque de " << valSaque << " reais, da conta: " << numConta << endl;
    b.saque(numConta, valSaque);
    b.salvar();

}

void Interface::transferencia(Banco b){

    int numContaO;
    int numContaD;
    float valTransf;

    cout << "Escolha a conta de origem" ;
    cin >> numContaO;
    cin.ignore();
    cout << "Escolha a conta destino" ;
    cin >> numContaD;
    cin.ignore();
    cout << "Escolha o valor a transferir" ;
    cin >> valTransf;
    cin.ignore();
    cout << "Transferencia no valor de " << valTransf << " reais " << " da conta " << numContaO << " para conta " << numContaD <<endl;
    b.transferencia(numContaO, numContaD, valTransf);
    b.salvar();
    
}

void Interface::obterSaldo(Banco b){

    int numConta;

    cout << "Digite o numero da conta para obter o saldo:" ;
    cin >> numConta;
    cin.ignore();
    cout << b.getSaldo(numConta) << endl;
}

void Interface::obterExtrato(Banco b){
	
	bool achouConta = false;
	int numConta;
    int opcExt;
    vector<Conta> auxConta;
    bool valido = false;
    Data di, df, dataCheck(0,0,0);
    string data, datai, dataf;


    cout << "\nEscolha o extrato desejado:\n\n" ;
    cout << "[1] - Extrato mensal\n" ;
    cout << "[2] - Extrato entre datas\n" ;
    cout << "[3] - Extrato a partir de\n" ;
    cout << "\n\n" ;

    cin >> opcExt;
    cin.ignore();
    
    while(!achouConta){
    	
		cout << "Digite o numero da conta: ";
        cin >> numConta;
        cin.ignore();
        auxConta = b.getContasList();
        for(auto x : auxConta){
        	if (x.getNumConta() == numConta){
        		achouConta = true;
        		break;
			}
		}
		if(achouConta){break;}
        cout << "Não foi encontrada conta com o numero digitado!" << endl;
		cout << "Tente Novamente" << endl;
	}

switch(opcExt){

    case 1:
    	
        cout << "Extrato:" << endl;
        //TODO: transformar em metodo void imprimeExtrato(vector<Move> move);
    	//
        for(auto x : b.extratomes(numConta)){
        	
        	switch(x.getDC()){
        			
        		case 'C':
        			cout << "Data da transação " << x.getData().getDia() << "/" << x.getData().getMes() << "/" << x.getData().getAno() << endl;
					cout << "Descrição: " << x.getDesc() << endl;
					cout << "Valor: " << x.getValor() << endl;
					break;
				case 'D':
        			cout << "Data do pagamento " << x.getData().getDia() << "/" << x.getData().getMes() << "/" << x.getData().getAno() << endl;
					cout << "Descrição: " << x.getDesc() << endl;
					cout << "Valor: " << x.getValor() << endl;
					break;
			}
		}

    	break;

    case 2:
        
		while(!valido){
            
			cout << "Digite a data inicial (dd/mm/aaaa): ";
            cin >> datai;
            cin.ignore();
            di.lerData(datai);
            cout << "Digite a data final (dd/mm/aaaa): ";
            cin >> dataf;
            cin.ignore();
            df.lerData(dataf); 
            if(di == dataCheck || df == dataCheck){
            	cout << "Digite uma data valida e no formato (dd/mm/aaaa), lembre-se de incluir as barras!" << endl;
			} else {
				valido = true;
			}
    	}
    	//TODO: transformar em metodo void imprimeExtrato(vector<Move> move);
    	//
    	for(auto x : b.extratoentredatas(numConta, di, df)){
        	
        	switch(x.getDC()){
        			
        		case 'C':
        			cout << "Data da transação " << x.getData().getDia() << "/" << x.getData().getMes() << "/" << x.getData().getAno() << endl;
					cout << "Descrição: " << x.getDesc() << endl;
					cout << "Valor: " << x.getValor() << endl;
					break;
				case 'D':
        			cout << "Data do pagamento " << x.getData().getDia() << "/" << x.getData().getMes() << "/" << x.getData().getAno() << endl;
					cout << "Descrição: " << x.getDesc() << endl;
					cout << "Valor: " << x.getValor() << endl;
					break;
			}
		}
    	
    	break;

    case 3:
		
		while(!valido){
            cout << "Digite a data inicial (dd/mm/aaaa): ";
            cin >> data;
            cin.ignore();
            di.lerData(data);
            if(di == dataCheck){
            	cout << "Digite uma data valida e no formato (dd/mm/aaaa), lembre-se de incluir as barras!" << endl;
			} else {
				valido = true;
			}
    	}
    	
    	//TODO: transformar em metodo void imprimeExtrato(vector<Move> move);
    	//
    	for(auto x : b.extratoapartirdata(numConta, di)){
        	
        	switch(x.getDC()){
        			
        		case 'C':
        			cout << "Data da transação " << x.getData().getDia() << "/" << x.getData().getMes() << "/" << x.getData().getAno() << endl;
					cout << "Descrição: " << x.getDesc() << endl;
					cout << "Valor: " << x.getValor() << endl;
					break;
				case 'D':
        			cout << "Data do pagamento " << x.getData().getDia() << "/" << x.getData().getMes() << "/" << x.getData().getAno() << endl;
					cout << "Descrição: " << x.getDesc() << endl;
					cout << "Valor: " << x.getValor() << endl;
					break;
			}
		}
		//
    	break;
    }
}

void Interface::listarClientes(Banco b){

    cout << "--------------LISTA DE CLIENTES------------" << endl;
    for (auto x : b.getClientList()) {
        cout << "------------------------------------------- " << endl;
        cout << "Nome do Cliente:.. " << x.getNome() << endl;
        cout << "CPF ou CNPJ:...... " << x.getCPF_CNPJ() << endl;
        cout << "Endereço:......... " << x.getEndereco() << endl;
        cout << "Telefone:......... " << x.getFone() << endl;
        cout << "------------------------------------------- " << endl;
        cout << "\n";
        } 
    }

void Interface::listarContas(Banco b){

	cout << "---------------LISTA DE CONTAS-------------" << endl;
	for (auto x : b.getContasList()) {
	    cout << "------------------------------------------- " << endl;
	    cout << "Numero da conta:.. " << x.getNumConta() << endl;
	    cout << "CPF ou CNPJ:...... " << x.getCliente().getCPF_CNPJ() << endl;
	    cout << "------------------------------------------- " << endl;
	}
}

