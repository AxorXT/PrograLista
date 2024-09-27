#pragma once
#include "Nodo.h"
#include <iostream>

class Lista : Nodo
{
private:
	Nodo* root;
public:

	Lista();
	Lista(Nodo* _root);
	~Lista();

	void SetRoot(Nodo*);
	void SetRoot();

	int GetValue(int x);

	void Push(int newValue);

	void ReadList() const;
	void ClearList();
	void BackNodo();

	int Pop();
	void Erase(int _erase);
};

