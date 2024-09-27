#pragma once
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
	Nodo* GetNext();

	void SetValue(int _value);
	void SetNext(Nodo* _next);
};

