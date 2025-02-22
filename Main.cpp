//implementación del algoritmo de minimizacion planteado por Kozen

//Se incluyen las libreriás necesarias para la ejecución del programa
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void readFile();
void minimizarDFA(int &numEstados, vector<string> &alfabeto, vector<int> &estadosFinales, vector<vector<int> > &MatrizTransicion);
vector<string> alfabeto;
vector<int> estadosFinales;
vector<vector<int> > MatrizTransicion;

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

    cout << "Numero de DFA´s a minimizar: " << c << endl;

    for (int i= 0; i < c; i++) {
        getline(archivo, line); // Leemos la siguiente linea del archivo que representa el numero de estados que tiene el DFA
        int numEstados;
        numEstados = stoi(line);

        getline(archivo, line); // Leemos la siguiente linea del archivo que representa el alfabeto del DFA
        stringstream ss(line);
        string simbolo;
        while (getline(ss, simbolo, ' ')) {  // Almacenamos los simbolos del alfabeto en un vector
            alfabeto.push_back(simbolo);      
        }

        getline(archivo, line); // Leemos la siguiente linea del archivo que representa los estados finales del DFA
        stringstream cc(line);
        while (getline(cc, simbolo, ' ')) {  // Almacenamos los esatdos finales en otro vector
            estadosFinales.push_back(stoi(simbolo));      
        }

         // Inicializar matriz de transición (vector de vectores)
         vector<vector<int> > MatrizTransicion(numEstados, vector<int>(alfabeto.size()+1)); //Matriz que simboliza la funicon de transicion
         for (int i=0; i < numEstados; i++) {
            getline(archivo, line); // Leemos la siguiente linea del archivo que representa la matriz de transición
            stringstream pp(line);
            for (int j=0; j < (alfabeto.size()+1); j++) {
                pp >> MatrizTransicion[i][j];
            }
         }

        minimizarDFA(numEstados, alfabeto, estadosFinales, MatrizTransicion);

        alfabeto.clear();
        estadosFinales.clear();
        MatrizTransicion.clear();

        archivo.ignore(); // Ignoramos la siguiente linea del archivo (hay un espacio en blanco)
    }
}

void minimizarDFA(int &numEstados, vector<string> &alfabeto, vector<int> &estadosFinales, vector<vector<int> > &MatrizTransicion){

    cout << "Numero de estados: " << numEstados << endl;
    cout << "Alfabeto: " << endl;
    for (int i = 0; i < alfabeto.size(); i++) {
        cout << alfabeto[i] << " ";
    }
    cout << endl;
    cout << "Estados finales: " << endl;
    for (int i = 0; i < estadosFinales.size(); i++) {
        cout << estadosFinales[i] << " ";
    }
    cout << endl;

    cout << "Matriz de Transición:\n";
    for (const auto& fila : MatrizTransicion) {
        for (int valor : fila) {
            cout << valor << " ";
        }
        cout << endl;
    }
    return;
}

