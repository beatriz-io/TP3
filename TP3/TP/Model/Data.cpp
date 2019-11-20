#include "Data.h"

using namespace std;

Data::Data(){
	this->dia_ = 0;
	this->mes_ = 0;
	this->ano_ = 0;	
	
}

Data::Data(int a, int b, int c){
	
	this->dia_ = a;
	this->mes_ = b;
	this->ano_ = c;
}

Data::Data(Data &data){
	
	this->ano_ = data.getAno();
	this->mes_ = data.getMes();
	this->dia_ = data.getDia();
}

Data::~Data(){

}

int Data::getDia(){
	return this->dia_;
}

int Data::getMes(){
	return this->mes_;
}

int Data::getAno(){
	return this->ano_;
}

void Data::setDia(int dia){
	this->dia_ = dia;
}

void Data::setMes(int mes){
	this->mes_ = mes;
}

void Data::setAno(int ano){
	this->ano_ = ano;
}

void Data::getDataSistema(){
	
	time_t t = time(0);
	tm *time = localtime(&t);
	
	this->dia_ = time->tm_mday;
	this->mes_ = 1 + time->tm_mon;
	this->ano_ = 1900 + time->tm_year;

}

bool Data::valid() const{
	if (ano_ < 0) { return false; }
	if (mes_ > 12 || mes_ < 1) { return false; }
	if (dia_ > 31 || dia_ < 1) { return false; }
	if ((dia_ == 31 && (mes_ == 2 || mes_ == 4 || mes_ == 6 || mes_ == 9 || mes_ == 11))) { return false; }
	if (dia_ == 30 && mes_ == 2) { return false; }
	if (ano_ < 2000) { if ((dia_ == 29 && mes_ == 2) && !((ano_ - 1900) % 4 == 0)) { return false; } }
	if (ano_ > 2000) { if ((dia_ == 29 && mes_ == 2) && !((ano_ - 2000) % 4 == 0)) { return false; } }
	return true;
}
		

bool Data::operator == ( Data d1)
{
	if (!d1.valid()) { return false; };
	if (!this->valid()) { return false; };
	if (d1.getDia() == this->getDia() && (d1.getMes() == this->getMes() && (d1.getAno() == this->getAno()))) { return true; };
	return false;
}

/*bool operator != ( Data& d1)
{
	return !(d1 == d2);
}
*/
bool Data::operator < (Data d1)
{
	if (!d1.valid()) { return false; };
	if (!this->valid()) { return false; };
	if (d1.getAno() < this->getAno()) { return true; }
	else if (d1.getAno() > this->getAno()) { return false; }
	else
	{
		if (d1.getMes() < this->getMes()) { return true; }
		else if (d1.getMes() > this->getMes()) { return false; }
		else { return false; }
	}
	return false;
}

bool Data::operator > (Data d1)
{
	if (d1 == *this) { return false; }
	if (d1 < *this) { return false; }
	return true;
}

bool Data::operator <= (Data d1)
{
	if (d1 == *this) { return true; }
	return (d1 < *this);
}

bool Data::operator >= (Data d1)
{
	if (d1 == *this) { return true; }
	return (d1 > *this);
}

int Data::numeroDias(int mes,int ano){

	switch (mes)
	{
	case 1:
		return 31;
		break;
	case 2:
		if (ano <= 2000){ if((ano - 1900) % 4 == 0){ return 29;}}
		if (ano > 2000){ if((ano - 2000) % 4 == 0){ return 29;}}
		return 28;
		break;
	case 3:
		return 31;
		break;
	case 4:
		return 30;
		break;
	case 5:
		return 31;
		break;
	case 6:
		return 30;
		break;
	case 7:
		return 31;
		break;
	case 8:
		return 31;
		break;
	case 9:
		return 30;
		break;
	case 10:
		return 31;
		break;
	case 11:
		return 30;
		break;
	case 12:
		return 31;
		break;
	default:
		return 0;
		break;
	}
}

Data Data::lerData(string data){
	
	string aux;
	stringstream check(data);
	vector<int> dataParam;
	
	while(getline(check, aux, '/')){
		dataParam.push_back(stoi(aux)); 
	}
	
	this->dia_ = dataParam[0];
	this->mes_ = dataParam[1];
	this->ano_ = dataParam[2];
	
	if(!this->valid()){
		this->ano_ = 0;
		this->mes_ = 0;
		this->dia_ = 0;
	}
}

