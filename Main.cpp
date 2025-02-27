#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

void readFile();
void minimizarDFA(int numEstados, const vector<string> &alfabeto, const vector<int> &estadosFinales, const vector<vector<int>> &MatrizTransicion);

int main() {
    readFile();
    return 0;
}

void readFile() {
    ifstream archivo("file.txt");
    if (!archivo) {
        cout << "Error al abrir el archivo, inténtelo de nuevo." << endl;
        return;
    }

    string line;
    getline(archivo, line);
    int c = stoi(line);

    cout << "Número de DFA's a minimizar: " << c << endl;

    for (int i = 0; i < c; i++) {
        if (!getline(archivo, line) || line.empty()) continue;
        int numEstados = stoi(line);

        vector<string> alfabeto;
        vector<int> estadosFinales;
        vector<vector<int>> MatrizTransicion(numEstados);

        if (!getline(archivo, line) || line.empty()) continue;
        stringstream ss(line);
        string simbolo;
        while (ss >> simbolo) {
            alfabeto.push_back(simbolo);
        }

        if (!getline(archivo, line) || line.empty()) continue;
        stringstream cc(line);
        int estado;
        while (cc >> estado) {
            estadosFinales.push_back(estado);
        }

        for (int i = 0; i < numEstados; i++) {
            if (!getline(archivo, line) || line.empty()) continue;
            stringstream pp(line);
            vector<int> filaTransicion(alfabeto.size());
            for (int j = 0; j < alfabeto.size(); j++) {
                pp >> filaTransicion[j];
            }
            MatrizTransicion[i] = filaTransicion;
        }

        minimizarDFA(numEstados, alfabeto, estadosFinales, MatrizTransicion);
    }
}

void minimizarDFA(int numEstados, const vector<string> &alfabeto, const vector<int> &estadosFinales, const vector<vector<int>> &MatrizTransicion) {
    vector<vector<bool>> marked(numEstados, vector<bool>(numEstados, false));

    for (int i = 0; i < numEstados; ++i) {
        for (int j = i + 1; j < numEstados; ++j) {
            bool iFinal = find(estadosFinales.begin(), estadosFinales.end(), i) != estadosFinales.end();
            bool jFinal = find(estadosFinales.begin(), estadosFinales.end(), j) != estadosFinales.end();
            if (iFinal != jFinal) {
                marked[i][j] = true;
            }
        }
    }

    bool changed;
    do {
        changed = false;
        for (int i = 0; i < numEstados; ++i) {
            for (int j = i + 1; j < numEstados; ++j) {
                if (!marked[i][j]) {
                    for (int k = 0; k < alfabeto.size(); ++k) {
                        int nextI = MatrizTransicion[i][k];
                        int nextJ = MatrizTransicion[j][k];

                        if (nextI != nextJ && marked[min(nextI, nextJ)][max(nextI, nextJ)]) {
                            marked[i][j] = true;
                            changed = true;
                            break;
                        }
                    }
                }
            }
        }
    } while (changed);

    vector<pair<int, int>> equivalentPairs;
    for (int i = 0; i < numEstados; ++i) {
        for (int j = i + 1; j < numEstados; ++j) {
            if (!marked[i][j]) {
                equivalentPairs.push_back(make_pair(i, j));
            }
        }
    }

    sort(equivalentPairs.begin(), equivalentPairs.end());

    cout << "Pares de estados equivalentes: ";
    for (const auto& pair : equivalentPairs) {
        cout << "(" << pair.first << ", " << pair.second << ") ";
    }
    cout << endl;
}
