#include "Move.h"

Move::Move(Data data, string desc, char debC, double val)
{
	dataMov = data;
	descricao = desc;
	debitoCredito = debC;
	valor = val;
}

Move::Move(const Move& m)
{
	dataMov = m.dataMov;
	descricao = m.descricao;
	debitoCredito = m.debitoCredito;
	valor = m.valor;
}

Move::~Move()
{

}

Data Move::getData()
{
	return dataMov;
}

string Move::getDesc()
{
	return descricao;
}

char Move::getDC()
{
	return debitoCredito;
}

double Move::getValor()
{
	return valor;
}