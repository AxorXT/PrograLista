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

Nodo* Lista::GetRoot()
{
	return root;
}

LIST_TYPE Lista::GetListaTipo()
{
	return listaTipo;
}

void Lista::SetListaTipo(LIST_TYPE tipo)
{
	listaTipo = tipo;
}

int Lista::GetValue(int x)
{
	Nodo* tempNodo = root;
	if (!root) {
		std::cout << "La lista esta vacia" << std::endl;
		return 0;
	}
		for (int i = 0; i < x; i++) {
			if (tempNodo) {
				tempNodo = tempNodo->GetNext();
			}
			else {
				return 0;
			}
		}
		if (tempNodo) {
			return tempNodo->GetValue();
		}
		else {
			return 0;
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
			root->SetPrev(root); 
		}
	} 
	else 
	{
		Nodo* temp = root;
		root->SetPrev(nNodo);
		while (temp->GetNext() && temp->GetNext() != root) {
			temp = temp->GetNext();
		}

		temp->SetNext(nNodo);
		nNodo->SetPrev(temp);

		if (listaTipo == LISTA_CIRCULAR_LIGADA || listaTipo == LISTA_CIRCULAR_DOBLE_LIGADA)
		{
			nNodo->SetNext(root);
			root->SetPrev(nNodo); 
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
		} while (temp != root);
	}
	else 
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
		while (last->GetNext() != root)  
		{ 
			last = last->GetNext(); 
		}
		last->SetNext(nullptr);
	}

	// Ahora eliminamos los nodos como en una lista lineal
	while (root) 
	{
		temp = root; 
		root = root->GetNext(); 
		delete temp; 
	}
}

void Lista::MostrarValor()
{
	if (root) {
		std::cout << "Valor actual: " << root->GetValue() << std::endl; 
	}
	else {
		std::cout << "La lista está vacía." << std::endl; 
	}
}

void Lista::SearchBack()
{
	if (listaTipo != LISTA_CIRCULAR_DOBLE_LIGADA) {
		std::cout << "Esta funcion solo es valida para listas circulares doblemente ligadas." << std::endl;
		return;
	}
	if (!root) {
		std::cout << "No hay nodo actual." << std::endl;
		return;
	}

	Nodo* prev = root->GetPrev();

	if (prev) {
		root = prev;
		MostrarValor();
	}
	else {
		std::cout << "No hay anterior." << std::endl;
	}

}

void Lista::SearchFront()
{
	if (listaTipo != LISTA_CIRCULAR_DOBLE_LIGADA) { 
		std::cout << "Esta funcion solo es valida para listas circulares doblemente ligadas." << std::endl;
		return;
	}
	if (root) { 
		root = root->GetNext();
		MostrarValor(); 
	}
	else {
		std::cout << "No hay siguiente." << std::endl; 
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
	else {
		while (temp->GetNext()) 
		{
			temp = temp->GetNext();
		}
	}

	
	std::cout << "El ultimo valor en la lista es: " << temp->GetValue() << std::endl;
}

void Lista::FillList(int cantidad, int limInferior, int limSuperior) // Rellena la lista con valores random
{
	srand(time(NULL)); // Con esto se generan los numeros, es como la semilla

	for (int i = 0; i < cantidad; i++) {
		int NumRandom = limInferior + rand() % (limSuperior + 1 - limInferior);
		Push(NumRandom);
	}
}

void Lista::BubbleSort()
{
	if (!root)
	{
		std::cout << "La lista esta vacia" << std::endl;
		return;
	}

	bool swapped;  // Indicador para verificar si hubo intercambio en la pasada
	Nodo* temp = nullptr;  // Temporal para comparar los nodos adyacentes
	Nodo* lastSorted = nullptr;  // Marca el último nodo ya ordenado

	bool isCircular = (GetListaTipo() == LISTA_CIRCULAR_LIGADA || GetListaTipo() == LISTA_CIRCULAR_DOBLE_LIGADA); // Incluimos las listas circulares en 'isCircular'

	do {
		swapped = false;
		temp = root;

		while (temp->GetNext() != lastSorted) {
			Nodo* nextNodo = temp->GetNext();
			if (nextNodo == root && isCircular)
			{
				break;
			}

			if (temp->GetValue() > nextNodo->GetValue()) {
				int swapValue = temp->GetValue();
				temp->SetValue(nextNodo->GetValue());
				nextNodo->SetValue(swapValue);

				swapped = true;
			}
			temp = temp->GetNext();
		}
		lastSorted = temp;

		if (isCircular && temp == root)
		{
			break;
		}

	} while (swapped);

	std::cout << "La lista ha sido ordenada con BUBBLE SORT" << std::endl;
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
		root = nullptr;
		return value;
	}

	Nodo* temp = root;
	Nodo* prev = nullptr;

	// En listas circulares, llegamos al nodo antes del root
	if (listaTipo == LISTA_CIRCULAR_LIGADA || listaTipo == LISTA_CIRCULAR_DOBLE_LIGADA) {
		while (temp->GetNext() != root) {
			prev = temp;
			temp = temp->GetNext();// temp es ahora el último nodo
		}
		
		// Guardamos el valor a eliminar
		int value = temp->GetValue();

		root->SetNext(root);
		prev->SetNext(prev);

		delete temp;
		return value;
	}
	else { // Para listas lineales
		while (temp->GetNext()->GetNext()) {
			temp = temp->GetNext();
		}
		int value = temp->GetNext()->GetValue();
		delete temp->GetNext();
		temp->SetNext(nullptr); 
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
		while (last->GetNext() != root) {
			last = last->GetNext();
		}
		root = root->GetNext(); 
		last->SetNext(root); 
		root->SetPrev(last);
	}
	// Caso para listas lineales
	else {
		root = root->GetNext();  
	}

	delete temp; 
	return value;
}
