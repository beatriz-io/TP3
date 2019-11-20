#ifndef DATA_H_
#define DATA_H_

#include <iostream>
#include <ctime>
#include <iostream>
#include <math.h>
#include <sstream>
#include <vector>

using namespace std;

class Data{
	
	private:
		int ano_;
		int mes_;
		int dia_;
	public:

	//Construtores
		Data();											
		Data(int d, int m, int a);						
		Data(Data& data);
	//Destrutor
		~Data();	
		bool valid() const;
	//Setters
		void setDia(int dia);
		void setMes(int mes);
		void setAno(int ano);
	//Getters
		int getDia();
		int getMes();
		int getAno();
		void getDataSistema();
	//Sobrecarga de Operadores
		Data operator++();
		Data operator++(int);
		Data operator--();
		Data operator--(int);
		bool operator == (Data);
		bool operator != (Data);
		bool operator < (Data);
		bool operator > (Data);
		bool operator <= (Data);
		bool operator >= (Data);
	//Metodo para retornar ultimo dia do mes de acordo com o mes e ano
		int numeroDias(int mes, int ano);
	//Metodo para ler objeto data
		Data lerData(string data);

};

#endif
