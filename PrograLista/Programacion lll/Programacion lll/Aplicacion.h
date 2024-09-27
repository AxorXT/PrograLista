#pragma once
#include "Lista.h"
#include <iostream>

class Aplicacion : Lista
{
	Lista lista;
	void GetIndex();
	void LastNodo();
	void PushValue();
	void List();
	void ClearValue();

public:

	void Init();
	void MainMenu();

	Aplicacion();
	~Aplicacion();
};

