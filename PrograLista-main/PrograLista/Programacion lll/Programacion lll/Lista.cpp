#include "Lista.h"

Lista::Lista() : root(nullptr), listaTipo(LISTA_LINEAL_LIGADA)
{

}

Lista::Lista(LIST_TYPE tipo) : root(nullptr), listaTipo(tipo)
{
}

Lista::~Lista()
{
	while (root) {
		Nodo* temp = root;
		root = root->GetNext();
		delete temp;
	}
}

void Lista::SetRoot(Nodo* _root)
{
	root = _root;
}

void Lista::SetRoot()
{

}

void Lista::SetListaTipo(LIST_TYPE tipo)
{
	listaTipo = tipo;
}

int Lista::GetValue(int x)
{
	Nodo* tempNodo = root;
	if (root) {
		for (int i = 0; i < x; i++) {
			if (tempNodo) {
				tempNodo = tempNodo->GetNext();
			}
			else {
				std::cout << "No hay ";
				return 0;
			}
		}
		if (tempNodo) {
			return tempNodo->GetValue();
		}
	}
	return 0;
}

void Lista::Push(int newValue)
{
	Nodo* nNodo = new Nodo(newValue);
	if (!root)
	{
		root = nNodo;
		if (listaTipo == LISTA_CIRCULAR_LIGADA || listaTipo == LISTA_CIRCULAR_DOBLE_LIGADA)
		{
			root->SetNext(root);
		}
	} 
	else 
	{
		Nodo* temp = root;
		while (temp->GetNext() && temp->GetNext() != root) {
			temp = temp->GetNext();
		}
		temp->SetNext(nNodo);
		if (listaTipo == LISTA_CIRCULAR_LIGADA || listaTipo == LISTA_CIRCULAR_DOBLE_LIGADA)
		{
			nNodo->SetNext(root);
		}
	}
}

void Lista::ReadList() const
{
	if (!root)
	{
		std::cout << "La lista esta vacia." << std::endl; 
		return;
	}

	Nodo* temp = root; 

	// Para listas circulares, paramos cuando volvemos al nodo raíz
	if (listaTipo == LISTA_CIRCULAR_LIGADA || listaTipo == LISTA_CIRCULAR_DOBLE_LIGADA) 
	{
		do
		{
			std::cout << temp->GetValue() << std::endl; 
			temp = temp->GetNext(); 
		} while (temp != root);  // Se detiene cuando regresa a la raíz 
	}
	else  // Para listas lineales
	{
		while (temp) 
		{
			std::cout << temp->GetValue() << std::endl; 
			temp = temp->GetNext(); 
		}
	}
}

void Lista::ClearList()
{
	if (!root) 
	{
		std::cout << "La lista esta vacia." << std::endl; 
		return;
	}

	Nodo* temp; 

	// Si es una lista circular, primero rompemos el ciclo
	if (listaTipo == LISTA_CIRCULAR_LIGADA || listaTipo == LISTA_CIRCULAR_DOBLE_LIGADA) 
	{
		Nodo* last = root; 
		while (last->GetNext() != root)  // Encontramos el último nodo que apunta a la raíz 
		{ 
			last = last->GetNext(); 
		}
		last->SetNext(nullptr);  // Rompemos el ciclo circular 
	}

	// Ahora eliminamos los nodos como en una lista lineal
	while (root) 
	{
		temp = root; 
		root = root->GetNext(); 
		delete temp; 
	}
}

void Lista::BackNodo()
{
	if (!root) {
		std::cout << "La lista esta vacia." << std::endl; 
		return;
	}

	Nodo* temp = root; 

	// Si es una lista circular, recorremos hasta encontrar el nodo que apunta al root
	if (listaTipo == LISTA_CIRCULAR_LIGADA || listaTipo == LISTA_CIRCULAR_DOBLE_LIGADA) 
	{ 
		while (temp->GetNext() != root) 
		{ 
			temp = temp->GetNext(); 
		}
	}
	else { // Si es una lista lineal o doble ligada
		while (temp->GetNext()) 
		{
			temp = temp->GetNext();
		}
	}

	// Imprimimos el valor del último nodo
	std::cout << "El ultimo valor en la lista es: " << temp->GetValue() << std::endl;
}


int Lista::Pop() // Para una pila (LIFO)
{
	if (!root) {
		std::cout << "La lista esta vacia." << std::endl;
		return -1;
	}

	// Para una lista con un solo nodo
	if (root->GetNext() == root) {
		int value = root->GetValue();
		delete root;
		root = nullptr; // Establecemos root a nullptr
		return value;
	}

	Nodo* temp = root;
	Nodo* prev = nullptr;

	// En listas circulares, llegamos al nodo antes del root
	if (listaTipo == LISTA_CIRCULAR_LIGADA || listaTipo == LISTA_CIRCULAR_DOBLE_LIGADA) {
		// Recorremos hasta encontrar el último nodo que apunta al root
		while (temp->GetNext() != root) {
			prev = temp;
			temp = temp->GetNext();
		}
		// temp es ahora el último nodo
		// Guardamos el valor a eliminar
		int value = temp->GetValue();

		// Si la lista tiene solo dos nodos
		if (prev == root) {
			// Ajustamos el puntero del nodo anterior
			root->SetNext(root); // Hacemos que root apunte a sí mismo
		}
		else {
			// Ajustamos el puntero del penúltimo nodo para que apunte a root
			prev->SetNext(root);
		}

		delete temp; // Eliminamos el último nodo
		return value;
	}
	else { // Para listas lineales
		while (temp->GetNext()->GetNext()) {
			temp = temp->GetNext();
		}
		// `temp` es ahora el penúltimo nodo
		int value = temp->GetNext()->GetValue();
		delete temp->GetNext(); // Eliminamos el último nodo
		temp->SetNext(nullptr); // Ajustamos el puntero del penúltimo nodo a nullptr
		return value;
	}
}


int Lista::Dequeue() // Para una cola (FIFO)
{
	if (!root) {
		std::cout << "La lista esta vacia." << std::endl;
		return -1;
	}

	Nodo* temp = root;
	int value = temp->GetValue();

	// Caso para listas circulares (ligadas o doblemente ligadas)
	if (listaTipo == LISTA_CIRCULAR_LIGADA || listaTipo == LISTA_CIRCULAR_DOBLE_LIGADA) {
		Nodo* last = root;
		// Encontramos el último nodo
		while (last->GetNext() != root) {
			last = last->GetNext();
		}
		root = root->GetNext();  // Actualizamos el root al siguiente nodo
		last->SetNext(root);      // Ajustamos el puntero del último nodo al nuevo root
	}
	// Caso para listas lineales
	else {
		root = root->GetNext();   // Actualizamos el root al siguiente nodo
	}

	delete temp;  // Eliminamos el nodo antiguo root
	return value;
}
