#include "Lista.h"

Lista::Lista()
{

}

Lista::Lista(Nodo* _root) : root(_root)
{
}

Lista::~Lista()
{
	ClearList();
}

void Lista::SetRoot(Nodo* _root)
{
	root = _root;
}

void Lista::SetRoot()
{

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
	} 
	else 
	{
		Nodo* temp = root;
		while (temp->GetNext()) {  
			temp = temp->GetNext();
		}
		temp->SetNext(nNodo);
	}
}

void Lista::ReadList() const
{
	Nodo* temp = root;
	if (!root)
	{
		std::cout << "La lista esta vacia." << std::endl;
		return;
	}

	while (temp)
	{
		std::cout << temp->GetValue() << std::endl;
		temp = temp->GetNext();
	}
	system("pause");
}

void Lista::ClearList()
{
	Nodo* temp;
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
		std::cout << "La lista está vacía." << std::endl;
		return; // Si la lista está vacía, se imprime un mensaje y se retorna
	}

	Nodo* temp = root;

	// Recorremos hasta el último nodo
	while (temp->GetNext() != nullptr) {
		temp = temp->GetNext();
	}

	// Imprimimos el valor del último nodo
	std::cout << "El ultimo valor en la lista es: " << temp->GetValue() << std::endl;
}

int Lista::Pop()
{
	return 0;
}

void Lista::Erase(int _erase)
{

}
