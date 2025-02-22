//implementación del algoritmo de minimizacion planteado por Kozen

//Se incluyen las libreriás necesarias para la ejecución del programa
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void readFile();

int main(){
    readFile();
    return 0;
}

void readFile(){
    ifstream archivo("file.txt");
    string line;

    if (!archivo) {
        cout << "Error al abrir el archivo, intentelo de nuevo" << endl;
        return;
    }
};

