#pragma once
#include "Lista.h"

class Aplicacion : Lista
{
	Lista lista;
	
	void ListType();
	void SortType();
	void GetIndex();
	void SearchOnList();
	void LastNodo();
	void PushValue();
	void List();
	void ClearValue();
	void Pila();
	void Cola();
	void RandomNum();

public:

	void Init();
	void MainMenu();

	Aplicacion();
	~Aplicacion();
};

