#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

void limpiarBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void registrarEstudiante() {
    string nombre, carrera;
    int edad;
    float promedio;
    ofstream archivo;

    archivo.open("estudiantes.txt", ios::app);

    if (archivo.fail()) {
        cout << "Error: No se pudo abrir el archivo para escribir." << endl;
        return;
    }

    cout << "\n--- REGISTRO DE ESTUDIANTE ---" << endl;
    cin.ignore();

    cout << "Nombre: ";
    getline(cin, nombre);

    cout << "Edad: ";
    while (!(cin >> edad) || edad <= 0) {
        cout << "Dato invalido. Ingrese una edad numerica: ";
        limpiarBuffer();
    }

    cin.ignore();
    cout << "Carrera: ";
    getline(cin, carrera);

    cout << "Promedio: ";
    while (!(cin >> promedio) || promedio < 0 || promedio > 10) {
        cout << "Dato invalido. Ingrese un promedio (0-10): ";
        limpiarBuffer();
    }

    archivo << nombre << "\t | " << edad << "\t | " << carrera << "\t | " << promedio << endl;

    archivo.close();
    cout << "\nDatos guardados correctamente." << endl;
}

void visualizarEstudiantes() {
    ifstream archivo;
    string linea;

    archivo.open("estudiantes.txt", ios::in);

    if (archivo.fail()) {
        cout << "\nEl archivo no existe o aun no tiene registros." << endl;
        return;
    }

    cout << "\n--- LISTA DE ESTUDIANTES REGISTRADOS ---" << endl;
    cout << "Nombre\t\t | Edad\t | Carrera\t | Promedio" << endl;
    cout << "------------------------------------------------------------" << endl;

    while (getline(archivo, linea)) {
        cout << linea << endl;
    }

    archivo.close();
}

int main() {
    int opcion;

    do {
        cout << "\n========================================" << endl;
        cout << "   SISTEMA DE ARCHIVOS - UTA" << endl;
        cout << "========================================" << endl;
        cout << "1. Registrar estudiante" << endl;
        cout << "2. Visualizar registros" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione: ";

        if (!(cin >> opcion)) {
            cout << "Opcion no valida." << endl;
            limpiarBuffer();
            continue;
        }

        switch (opcion) {
            case 1:
                registrarEstudiante();
                break;
            case 2:
                visualizarEstudiantes();
                break;
            case 3:
                cout << "Cerrando sistema..." << endl;
                break;
            default:
                cout << "Opcion incorrecta." << endl;
        }

    } while (opcion != 3);

    return 0;
}
