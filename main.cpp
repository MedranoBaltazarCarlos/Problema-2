#include <iostream>
#include <cstring>

class Materia {
private:
    int Clave;
    char Nombre[50];
    char ProfesorTit[50];
    char LibroTexto[50];

public:
    // Constructor por defecto
    Materia() {
        Clave = 0;
        strcpy(Nombre, "");
        strcpy(ProfesorTit, "");
        strcpy(LibroTexto, "");
    }

    // Constructor con parámetros
    Materia(int clave, const char* nombre, const char* profesorTit, const char* libroTexto) {
        Clave = clave;
        strcpy(Nombre, nombre);
        strcpy(ProfesorTit, profesorTit);
        strcpy(LibroTexto, libroTexto);
    }

    // Método para imprimir los datos de la materia
    void Imprime() const {
        std::cout << "Clave: " << Clave << std::endl;
        std::cout << "Nombre: " << Nombre << std::endl;
        std::cout << "Profesor Titular: " << ProfesorTit << std::endl;
        std::cout << "Libro de Texto: " << LibroTexto << std::endl;
    }

    // Método para cambiar la clave de la materia
    void CambiaClave(int nuevaClave) {
        Clave = nuevaClave;
    }

    // Método para cambiar el nombre del profesor titular
    void CambiaProfe(const char nuevoProfe[]) {
        strcpy(ProfesorTit, nuevoProfe);
    }
};

int main() {
    // Declaración de los objetos Programacion y BasesDatos
    Materia Programacion(101, "Programacion", "Prof. Ramirez", "C++ for Beginners");
    Materia BasesDatos(202, "Bases de Datos", "Prof. Gonzalez", "Database Design");

    int opcion;
    do {
        std::cout << "\nMenu de Opciones:\n";
        std::cout << "1. Cambiar la clave de la materia Programacion\n";
        std::cout << "2. Cambiar el nombre del maestro que imparte la materia BasesDatos\n";
        std::cout << "3. Imprimir todos los datos de la materia BasesDatos\n";
        std::cout << "4. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch(opcion) {
            case 1: {
                int nuevaClave;
                std::cout << "Ingrese la nueva clave para Programacion: ";
                std::cin >> nuevaClave;
                Programacion.CambiaClave(nuevaClave);
                std::cout << "Clave de Programacion actualizada.\n";
                break;
            }
            case 2: {
                char nuevoProfe[50];
                std::cout << "Ingrese el nuevo nombre del profesor para BasesDatos: ";
                std::cin.ignore(); // Limpiar el buffer
                std::cin.getline(nuevoProfe, 50);
                BasesDatos.CambiaProfe(nuevoProfe);
                std::cout << "Profesor de BasesDatos actualizado.\n";
                break;
            }
            case 3: {
                std::cout << "Datos de la materia BasesDatos:\n";
                BasesDatos.Imprime();
                break;
            }
            case 4:
                std::cout << "Saliendo del programa...\n";
                break;
            default:
                std::cout << "Opcion invalida. Intente de nuevo.\n";
        }
    } while(opcion != 4);

    return 0;
}
