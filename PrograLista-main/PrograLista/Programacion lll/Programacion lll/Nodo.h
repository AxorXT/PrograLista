#pragma once
#include <iostream>

class Nodo
{
private:
	int value;
	Nodo* nextNodo;

public:

	Nodo();
	Nodo(int _value, Nodo* _nextNodo = nullptr);
	~Nodo();

	int GetValue();
	Nodo* GetNext(); // Con esto obtenemos el nodo siguiente en las listas enlazadas

	void SetValue(int _value); 
	void SetNext(Nodo* _next); // Con esto establecemos el siguiente nodo
};

