//implementación del algoritmo de minimizacion planteado por Kozen

//Se incluyen las libreriás necesarias para la ejecución del programa
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void readFile();
vector<string> alfabeto;

int main(){
    readFile();
    return 0;
}

void readFile(){
    ifstream archivo("File.txt"); // Abrimos el archivo que contiene los DFA´s a minimizar

    if (!archivo) {
        cout << "Error al abrir el archivo, intentelo de nuevo" << endl;
        return;
    } 
    
    string line;
    getline(archivo, line); // Leemos la primera linea del archivo
    int c = stoi(line); 
    archivo.ignore(); // Ignoramos la siguiente linea del archivo

    for (int i= 0; i < c; i++) {
        getline(archivo, line); // Leemos la siguiente linea del archivo que representa el numero de estados que tiene el DFA
        int numEstados = stoi(line);

        getline(archivo, line); // Leemos la siguiente linea del archivo que representa el alfabeto del DFA
        stringstream ss(line);
        string simbolo;
        while (getline(ss, simbolo, ' ')) {  // Almacenamos los simbolos del alfabeto en un vector
            alfabeto.push_back(simbolo);      
        }
    }
};

