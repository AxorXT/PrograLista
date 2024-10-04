#pragma once
#include "Nodo.h"
#include <iostream>

enum LIST_TYPE {
	LISTA_LINEAL_LIGADA = 0,
	LISTA_CIRCULAR_LIGADA,
	LISTA_LINEAL_DOBLE_LIGADA,
	LISTA_CIRCULAR_DOBLE_LIGADA
};

class Lista : Nodo
{
private:
	Nodo* root;
	LIST_TYPE listaTipo;

public:

	Lista();
	Lista(LIST_TYPE tipo);
	~Lista();

	void SetRoot(Nodo*);
	void SetRoot();
	void SetListaTipo(LIST_TYPE tipo);

	int GetValue(int x);

	void Push(int newValue); // Inserta nuevo elemento

	void ReadList() const; // Muestra la lista
	void ClearList(); // Borra o limpia toda la lista
	void BackNodo(); // Te muestra el ultimo agregado en la lista

	int Pop();
	int Dequeue();
};

