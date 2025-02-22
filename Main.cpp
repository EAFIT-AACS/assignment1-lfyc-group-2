//Aca va el codigo correspondiente a la actividad
//implementación del algoritmo de minimizacion planteado por Kozen

#include <iostream>
#include <string>
using namespace std;

void menu();

int main(){
    menu();
    return 0;
}

void menu(){
int casos = 1;
int estado = 1;

    cout << "---------- Bienvenido al programa de minimizacion de automatas ----------" << endl;
    cout << "Ingrese el numero de casos que le gustaria evaluar: " << endl;
    cin >> casos;

    for (int i=0; i<casos; i++){
        cout << "Ingrese el numero de estados del automata: " << i+1 << endl;
        cin >> estado;
    }
}