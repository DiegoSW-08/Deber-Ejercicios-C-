#include <iostream>
using namespace std;

int main() {

    int numero_hojas, tipodeImpresion, estudianteOdocente, horario, anillado;
    float subtotal_impresion, descuento, recargo, valor_anillado, total_A_pagar;


    cout << "Ingrese el número de hojas: ";
    cin >> numero_hojas;
    while (numero_hojas <= 0) {
        cout << "Número de hojas inválido. Debe ser positivo. Ingrese nuevamente: ";
        cin >> numero_hojas;
    }

    cout << "Ingrese el tipo de impresión (1 = blanco/negro, 2 = color): ";
    cin >> tipodeImpresion;
    while (tipodeImpresion != 1 && tipodeImpresion != 2) {
        cout << "Valor inválido. Ingrese 1 para blanco/negro o 2 para color: ";
        cin >> tipodeImpresion;
    }

    cout << "Ingrese el tipo de usuario (1 = estudiante, 2 = docente): ";
    cin >> estudianteOdocente;
    while (estudianteOdocente != 1 && estudianteOdocente != 2) {
        cout << "Valor inválido. Ingrese 1 para estudiante o 2 para docente: ";
        cin >> estudianteOdocente;
    }

    cout << "Ingrese el horario (1 = normal, 2 = nocturno): ";
    cin >> horario;
    while (horario != 1 && horario != 2) {
        cout << "Valor inválido. Ingrese 1 para normal o 2 para nocturno: ";
        cin >> horario;
    }

    cout << "¿Lleva anillado? (0 = no, 1 = sí): ";
    cin >> anillado;
    while (anillado != 0 && anillado != 1) {
        cout << "Valor inválido. Ingrese 0 para no o 1 para sí: ";
        cin >> anillado;
    }


    float precio_base_por_hoja = 0;
    float costo_anillado_base = 2.5;
    descuento = 0;
    recargo = 0;
    valor_anillado = 0;


    if (tipodeImpresion == 1) {
        if (numero_hojas <= 20) {
            precio_base_por_hoja = 0.10;
        } else if (numero_hojas <= 100) {
            precio_base_por_hoja = 0.08;
        } else {
            precio_base_por_hoja = 0.05;
        }
    } else { // Color
        if (numero_hojas <= 20) {
            precio_base_por_hoja = 0.25; // Primer tramo, precio A (color más caro)
        } else if (numero_hojas <= 100) {
            precio_base_por_hoja = 0.20; // Segundo tramo, precio B
        } else {
            precio_base_por_hoja = 0.15; // Tercer tramo, precio C
        }
    }


    subtotal_impresion = numero_hojas * precio_base_por_hoja;


    float descuento_docente = 0.05;
    float descuento_estudiante = 0.08;

    if (estudianteOdocente == 1) {
        if (numero_hojas > 50) {
            descuento = subtotal_impresion * descuento_estudiante;
        }
    } else {
        descuento = subtotal_impresion * descuento_docente;
    }


    if (horario == 2) {
        recargo = subtotal_impresion * 0.10;
    }


    if (anillado == 1) {
        valor_anillado = costo_anillado_base;

        if (numero_hojas > 50) {
            valor_anillado = valor_anillado * 0.85;
        }
    }


    total_A_pagar = subtotal_impresion - descuento + recargo + valor_anillado;


    cout << "\n--- Resultados de la facturación ---\n";
    cout << "Subtotal impresión: $" << subtotal_impresion << endl;
    cout << "Descuento aplicado: $" << descuento << endl;
    cout << "Recargo: $" << recargo << endl;
    cout << "Valor de anillado: $" << valor_anillado << endl;
    cout << "Total a pagar: $" << total_A_pagar << endl;

    return 0;
}
