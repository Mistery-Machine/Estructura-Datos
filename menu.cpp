#include "menu.h"
#include <windows.h>

void menu()
{
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "es_ES.UTF-8");

    ListaProductos lista;
    int opcion = 0;

    do
    {
        std::cout << "\n-------------------------------------------\n";
        std::cout << "   MENÚ PRINCIPAL - SISTEMA DE PRODUCTOS   \n";
        std::cout << "-------------------------------------------\n";
        std::cout << "1. Insertar producto al final\n";
        std::cout << "2. Buscar producto por nombre\n";
        std::cout << "3. Buscar producto por ID\n";
        std::cout << "4. Eliminar producto por nombre\n";
        std::cout << "5. Mostrar todos los productos\n";
        std::cout << "6. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada inválida. Por favor ingrese un número.\n";
            continue;
        }

        switch (opcion)
        {
        case 1:
        {
            int id, cantidad;
            double precio;
            std::string nombre;

            std::cout << "\n--- INSERTAR PRODUCTO ---\n";
            std::cout << "Ingrese el ID del producto: ";
            std::cin >> id;
            std::cout << "Ingrese el nombre del producto: ";
            std::cin.ignore();
            std::getline(std::cin, nombre);
            std::cout << "Ingrese el precio del producto: ";
            std::cin >> precio;
            std::cout << "Ingrese la cantidad del producto: ";
            std::cin >> cantidad;

            lista.insertarFinal(id, nombre, precio, cantidad);
            break;
        }

        case 2:
        {
            std::string nombreBuscar;
            std::cout << "\n--- BUSCAR PRODUCTO POR NOMBRE ---\n";
            std::cout << "Ingrese el nombre del producto: ";
            std::cin.ignore();
            std::getline(std::cin, nombreBuscar);
            Producto *encontrado = lista.buscar(nombreBuscar);
            if (encontrado != nullptr)
            {
                std::cout << "\nProducto encontrado:\n";
                encontrado->imprimir();
            }
            break;
        }

        case 3:
        {
            int idBuscar;
            std::cout << "\n--- BUSCAR PRODUCTO POR ID ---\n";
            std::cout << "Ingrese el ID del producto: ";
            std::cin >> idBuscar;
            Producto *encontrado = lista.buscar(idBuscar);
            if (encontrado != nullptr)
            {
                std::cout << "\nProducto encontrado:\n";
                encontrado->imprimir();
            }
            break;
        }

        case 4:
        {
            std::string nombreEliminar;
            std::cout << "\n--- ELIMINAR PRODUCTO POR NOMBRE ---\n";
            std::cout << "Ingrese el nombre del producto a eliminar: ";
            std::cin.ignore();
            std::getline(std::cin, nombreEliminar);
            lista.eliminar(nombreEliminar);
            break;
        }

        case 5:
        {
            std::cout << "\n--- LISTA DE PRODUCTOS ---\n";
            lista.imprimir();
            break;
        }

        case 6:
        {
            std::cout << "\nSaliendo del programa...\n";
            break;
        }

        default:
        {
            std::cout << "Opción inválida. Intente nuevamente.\n";
            break;
        }
        }

    } while (opcion != 6);
}