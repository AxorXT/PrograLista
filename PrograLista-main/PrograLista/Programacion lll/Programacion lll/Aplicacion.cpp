#include "Aplicacion.h"

void Aplicacion::ListType()
{
	int opcion;
        std::cout << "Selecciona el tipo de lista que quieres hacer:"
                  << "\nLISTA LINEAL LIGADA [0]"
                  << "\nLISTA CIRCULAR LIGADA [1]"
                  << "\nLISTA LINEAL DOBLE LIGADA [2]"
                  << "\nLISTA CIRCULAR DOBLE LIGADA [3]" 
                  << "\nSALIR [4]" << std::endl;
        std::cin >> opcion;

        if (opcion == 4)
        {
            std::cout << "Has salido de la aplicacion" << std::endl;
            exit(0);
        }

        switch (opcion)
        {
        case 0:
            std::cout << "Has seleccionado LISTA LINEAL LIGADA." << std::endl;
            break;
        case 1:
            std::cout << "Has seleccionado LISTA CIRCULAR LIGADA." << std::endl;
            break;
        case 2:
            std::cout << "Has seleccionado LISTA LINEAL DOBLE LIGADA." << std::endl;
            break;
        case 3:
            std::cout << "Has seleccionado LISTA CIRCULAR DOBLE LIGADA." << std::endl;
            break;
        default:
            std::cout << "Opción no válida." << std::endl;
            return;
        }

        lista.ClearList();

        lista.SetListaTipo(static_cast<LIST_TYPE>(opcion));
        std::cout << "Se ha seleccionado correctamente el tipo de lista" << std::endl;
        system("pause"); 
        system("CLS");
}

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
	system("pause");
}

void Aplicacion::ClearValue()
{
	lista.ClearList();
	std::cout << "Se ha limpiado la lista" << std::endl;
	system("pause");
}

void Aplicacion::Pila()
{
    int value = lista.Pop(); 
    if (value != -1) { 
        std::cout << "Se elimino el ultimo dato: " << value << std::endl; 
    }
    system("pause");
}

void Aplicacion::Cola()
{
    int value = lista.Dequeue(); 
    if (value != -1) { 
        std::cout << "Se elimino el primer dato: " << value << std::endl; 
    }
    system("pause");
}

void Aplicacion::Init()
{
	ListType();
	MainMenu();
}

void Aplicacion::MainMenu()
{
	std::string input;
    while (true)
    {
        std::cout << "Selecciona que quieres hacer:"
            "\nInsertar un nuevo numero a la lista presiona [1]"
            "\nLeer la lista presiona [2]"
            "\nLimpiar la lista presiona [3]"
            "\nMostrar dato de la lista [4]"
            "\nMostrar el ultimo dato escrito [5]"
            "\nEliminar el ultimo dato (Pila) [6]"      
            "\nEliminar el primer dato (Cola) [7]" 
            "\nCambiar tipo de lista [8]"
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
        else if (input == "6") 
        {
            Pila();
        }
        else if (input == "7") 
        {
            Cola();
        }
        else if (input == "8")
        {
            ListType();
            
        }
        else if (input == "x")
        {
            std::cout << "Saliendo de la aplicación." << std::endl; 
            break;
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
