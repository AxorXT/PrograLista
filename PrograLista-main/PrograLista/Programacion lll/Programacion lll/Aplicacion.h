#pragma once
#include "Lista.h"

class Aplicacion : Lista
{
	Lista lista;

	void ListType();
	void GetIndex();
	void LastNodo();
	void PushValue();
	void List();
	void ClearValue();
	void Pila();
	void Cola();

public:

	void Init();
	void MainMenu();

	Aplicacion();
	~Aplicacion();
};

