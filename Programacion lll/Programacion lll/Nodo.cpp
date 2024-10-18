#include "Nodo.h"

int Nodo::GetValue()
{
	return value;
}

Nodo* Nodo::GetNext()
{
	return nextNodo;
}

Nodo* Nodo::GetPrev()
{
	return prevNodo;
}

void Nodo::SetValue(int _value)
{
	value = _value;
}

void Nodo::SetNext(Nodo* _next)
{
	nextNodo = _next;
}

void Nodo::SetPrev(Nodo* _prev)
{
	prevNodo = _prev;
}


Nodo::Nodo() : value(0), nextNodo(nullptr), prevNodo(nullptr)
{

}

Nodo::Nodo(int _value, Nodo* _nextNodo, Nodo* _prevNodo) : value(_value), nextNodo(nullptr), prevNodo(nullptr)
{

}

Nodo::~Nodo()
{
}
