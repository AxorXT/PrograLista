#pragma once
#include "Nodo.h"
#include <iostream>
#include <cstdlib>
#include <time.h>

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
	Nodo* current;
	LIST_TYPE listaTipo;

public:

	Lista();
	Lista(LIST_TYPE tipo);
	~Lista();

	void SetRoot(Nodo*);
	Nodo* GetRoot();
	LIST_TYPE GetListaTipo();
	void SetListaTipo(LIST_TYPE tipo);

	int GetValue(int x);

	void Push(int newValue); // Inserta nuevo elemento

	void ReadList() const; // Muestra la lista
	void ClearList(); // Borra o limpia toda la lista
	void MostrarValor();
	void SearchBack();
	void SearchFront();
	void BackNodo(); // Te muestra el ultimo agregado en la lista
	void FillList(int cantidad, int limInferior, int limSuperior);

	void BubbleSort();

	int Pop();
	int Dequeue();
};

