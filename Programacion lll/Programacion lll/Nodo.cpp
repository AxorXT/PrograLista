#include "Nodo.h"

int Nodo::GetValue()
{
	return value;
}

Nodo* Nodo::GetNext()
{
	return nextNodo;
}

void Nodo::SetValue(int _value)
{

}

void Nodo::SetNext(Nodo* _next)
{
	nextNodo = _next;
}



Nodo::Nodo() : value(0), nextNodo(nullptr)
{

}

Nodo::Nodo(int _value, Nodo* _nextNodo) : value(_value), nextNodo(nullptr)
{

}

Nodo::~Nodo()
{
}
