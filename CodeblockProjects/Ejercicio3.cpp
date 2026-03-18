#include <iostream>
#include <cmath>
using namespace std;

int main() {

    int lado1, lado2, lado3, altura;
    float angulo_principal, area;

    cout << "Ingrese el primer lado (entero positivo): ";
    cin >> lado1;
    while (lado1 <= 0) {
        cout << "Valor inválido. Ingrese un entero positivo: ";
        cin >> lado1;
    }

    cout << "Ingrese el segundo lado (entero positivo): ";
    cin >> lado2;
    while (lado2 <= 0) {
        cout << "Valor inválido. Ingrese un entero positivo: ";
        cin >> lado2;
    }

    cout << "Ingrese el tercer lado (entero positivo): ";
    cin >> lado3;
    while (lado3 <= 0) {
        cout << "Valor inválido. Ingrese un entero positivo: ";
        cin >> lado3;
    }

    cout << "Ingrese la altura (entero positivo): ";
    cin >> altura;
    while (altura <= 0) {
        cout << "Valor inválido. Ingrese un entero positivo: ";
        cin >> altura;
    }

    cout << "Ingrese el ángulo principal (0-180 grados): ";
    cin >> angulo_principal;
    while (angulo_principal <= 0 || angulo_principal >= 180) {
        cout << "Ángulo inválido. Debe estar entre 0 y 180 grados (excluyendo extremos): ";
        cin >> angulo_principal;
    }


    cout << "\n--- Resultados ---\n";

    if (lado1 + lado2 > lado3 && lado1 + lado3 > lado2 && lado2 + lado3 > lado1) {
        cout << "Validez: El triángulo es válido." << endl;
        cout << "Tipo por lados: ";
        if (lado1 == lado2 && lado2 == lado3) {
            cout << "equilátero" << endl;
        } else if (lado1 == lado2 || lado1 == lado3 || lado2 == lado3) {
            cout << "isósceles" << endl;
        } else {
            cout << "escaleno" << endl;
        }

        cout << "Tipo por ángulos: ";
        if (angulo_principal < 90) {
            cout << "acutángulo" << endl;
        } else if (angulo_principal == 90) {
            cout << "rectángulo" << endl;
        } else {
            cout << "obtusángulo" << endl;
        }


        area = (lado1 * altura) / 2.0;
        cout << "Área: " << area << endl;


        if (altura > lado1) {
            cout << "Advertencia de inconsistencia: La altura (" << altura
                 << ") es mayor que el lado base (" << lado1
                 << "), lo cual es geométricamente imposible." << endl;
        } else if (angulo_principal == 90 && altura > lado2 && altura > lado3) {
            cout << "Advertencia de inconsistencia: En un triángulo rectángulo, la altura no puede ser mayor que los catetos." << endl;
        } else {
            cout << "La altura es consistente con la base seleccionada." << endl;
        }

    } else {
        cout << "Validez: Los lados ingresados NO forman un triángulo." << endl;
    }

    return 0;
}
