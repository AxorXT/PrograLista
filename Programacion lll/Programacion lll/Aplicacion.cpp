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
        system("pause"); 
        system("CLS");
}

void Aplicacion::SortType()
{
    int opcion;
    std::cout << "Selecciona el tipo de ordenamiento que quieres hacer:"
        << "\n[1] BUBBLE SORT (BURBUJA)"
        << "\n[4] REGRESAR AL MENU PRINCIPAL" << std::endl;
    std::cin >> opcion;

    switch (opcion)
    {
    case 1:
        lista.BubbleSort();
        system("pause");
        break;
        
    case 4:
        std::cout << "Regresando..." << std::endl;
        system("pause");
        return MainMenu();
        
    default:
        std::cout << "Opcion no valida" << std::endl; 
        break;
    }
    return MainMenu();
    system("CLS");
}

void Aplicacion::GetIndex()
{
	int index;
	std::cout << "Que dato de la lista deseas ver?" << std::endl;
	std::cin >> index;
	int value = lista.GetValue(index);
    if (value == 0 && index != 0) {
        std::cout << "No se puede obtener el valor" << std::endl;
    } else {
        std::cout << "Valor:";
        std::cout << value << std::endl;
    }
	system("pause");
}

void Aplicacion::SearchOnList()
{
    if (lista.GetListaTipo() != LISTA_CIRCULAR_DOBLE_LIGADA) {
        std::cout << "Esta funcion solo es valida para listas circulares doblemente ligadas." << std::endl;
        system("pause");
        return;
    }

    // Verifica si la lista está vacía
    if (!lista.GetRoot()) { // Asegúrate de que GetRoot() esté implementado en la clase Lista
        std::cout << "La lista esta vacia." << std::endl;
        system("CLS");
        return;
    }

    int opcion; 
    do {
        lista.MostrarValor(); // Muestra el valor del nodo actual
        std::cout << "Presiona '1' para siguiente, '2' para anterior, '3' para salir: " << std::endl;
        std::cin >> opcion;

        if (opcion == 1) {
            lista.SearchFront(); // Mueve al siguiente nodo
        }
        else if (opcion == 2) {
            lista.SearchBack(); // Mueve al nodo anterior
        }
        else if (opcion != 3) {
            std::cout << "Opcion no valida. Por favor, intente de nuevo." << std::endl;
        }
        system("CLS");
    } while (opcion != 3);
}


void Aplicacion::LastNodo()
{
	lista.BackNodo();
	system("pause");
}

void Aplicacion::PushValue()
{
	int num;
    while (true) {
        std::cout << "Ingresa el numero que quieres agregar: " << std::endl;
        std::cin >> num;

        if (std::cin.fail()) 
        {
            std::cout << "Entrada no valida. Introduce solo numeros" << std::endl;

            std::cin.clear();
            std::cin.ignore(10000, '\n');
            system("pause"); 
            return;
        }
        else 
        {
            lista.Push(num);
            std::cout << "El numero se agrego correctamente" << std::endl;
            system("pause"); 
            return;
        }
    }
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

void Aplicacion::RandomNum()
{
    int cantidad, limInferior, limSuperior;

    std::cout << "Introduce la cantidad de numeros que quiere: ";
    std::cin >> cantidad;

    std::cout << "Introduce el limite inferior: ";
    std::cin >> limInferior;

    std::cout << "Introduce el limite superior: ";
    std::cin >> limSuperior;

    if (limInferior > limSuperior)
    {
        std::cout << "El limite inferior no puede ser mayor que el limite superior" << std::endl;
        return;
    }
    
    lista.FillList(cantidad, limInferior, limSuperior);
    std::cout << "Se ha rellenado la lista correctamente" << std::endl;
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
            "\n[1] Insertar un nuevo numero a la lista presiona"
            "\n[2] Leer la lista presiona"
            "\n[3] Limpiar la lista presiona"
            "\n[4] Mostrar dato de la lista"
            "\n[5] Mostrar el ultimo dato escrito"
            "\n[6] Eliminar el ultimo dato (Pila)"      
            "\n[7] Eliminar el primer dato (Cola)" 
            "\n[8] Cambiar tipo de lista"
            "\n[9] Buscar en la lista"
            "\n[r] Agregar numeros random a la lista"
            "\n[z] Ordenar lista"
            "\n[x] Salir de la aplicacion presiona" << std::endl;
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
        else if (input == "9") 
        {
            SearchOnList();
        }
        else if (input == "r")
        {
            RandomNum();
        }
        else if (input == "z")
        {
            SortType();
        }
        else if (input == "x")
        {
            std::cout << "Saliendo de la aplicacion." << std::endl; 
            exit(0);
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
