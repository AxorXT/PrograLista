#include "Aplicacion.h"

void Aplicacion::GetIndex()
{
	int index;
	std::cout << "Que dato de la lista deseas ver?" << std::endl;
	std::cin >> index;
	int value = lista.GetValue(index);
	std::cout << "Valor:";
	std::cout << value << std::endl;
	system("pause");
}

void Aplicacion::LastNodo()
{
	lista.BackNodo();
	system("pause");
}

void Aplicacion::PushValue()
{
	int num;
	std::cout << "Ingresa el numero que quieres agregar: " << std::endl;
	std::cin >> num;
	lista.Push(num);
	std::cout << "El numero se agrego correctamente" << std::endl;
}

void Aplicacion::List()
{
	std::cout << "Contenido de la lista: " << std::endl;
	lista.ReadList();
}

void Aplicacion::ClearValue()
{
	lista.ClearList();
	std::cout << "Se ha limpiado la lista" << std::endl;
}

void Aplicacion::Init()
{
	MainMenu();
}

void Aplicacion::MainMenu()
{
	std::string input;
	while (input != "x") 
	{
		std::cout << "Selecciona que quieres hacer:"
			"\nInsertar un nuevo numero a la lista presiona [1]"
			"\nLeer la lista presiona [2]"
			"\nLimpiar la lista presiona [3]"
			"\nMostrar dato de la lista [4]"
			"\nMostrar el ultimo dato escrito [5]"
			"\nSalir de la aplicacion presiona [x]" << std::endl;
		std::cin >> input;
		if (input == "1")
		{
			PushValue();
		}
		else if (input == "2")
		{
			List();
		}
		else if (input == "3")
		{
			ClearValue();
		}
		else if (input == "4")
		{
			GetIndex();
		}
		else if (input == "5")
		{
			LastNodo();
		}
		system("CLS");
	}
}

Aplicacion::Aplicacion()
{
}

Aplicacion::~Aplicacion()
{
}
