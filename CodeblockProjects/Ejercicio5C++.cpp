#include <iostream>
using namespace std;

int main() {
    // ================== 1. DECLARACIÓN DE VARIABLES ==================
    int monto_solicitado;
    int billetes20, billetes10, billetes5, billetes1;
    int saldo_usuario;
    int efectivo_cajero;

    // Inicializar disponibilidad del cajero
    billetes20 = 10; // 10 billetes de 20
    billetes10 = 10; // 10 billetes de 10
    billetes5 = 10;  // 10 billetes de 5
    billetes1 = 10;  // 10 billetes de 1

    // Inicializar saldo del usuario
    saldo_usuario = 500;

    // Variables para controlar la entrega
    int billetes20_entregados = 0, billetes10_entregados = 0, billetes5_entregados = 0, billetes1_entregados = 0;
    int monto_restante;
    bool posible = true;

    // ================== 2. PROCESO ==================
    // --- Entrada de datos con validación ---
    cout << "Bienvenido al cajero automático" << endl;
    cout << "Saldo disponible del usuario: $" << saldo_usuario << endl;
    cout << "Efectivo disponible en el cajero:" << endl;
    cout << "Billetes de $20: " << billetes20 << endl;
    cout << "Billetes de $10: " << billetes10 << endl;
    cout << "Billetes de $5: " << billetes5 << endl;
    cout << "Billetes de $1: " << billetes1 << endl;
    cout << "\nIngrese el monto a retirar: $";
    cin >> monto_solicitado;

    while (monto_solicitado <= 0) {
        cout << "Monto inválido. Debe ser positivo. Ingrese nuevamente: $";
        cin >> monto_solicitado;
    }

    // --- Verificar si el monto solicitado es válido ---
    if (monto_solicitado > saldo_usuario) {
        cout << "\nERROR: El monto solicitado ($" << monto_solicitado << ") excede su saldo disponible ($" << saldo_usuario << ")." << endl;
        posible = false;
    } else {
        // Calcular el efectivo total disponible en el cajero
        efectivo_cajero = billetes20 * 20 + billetes10 * 10 + billetes5 * 5 + billetes1 * 1;

        if (monto_solicitado > efectivo_cajero) {
            cout << "\nERROR: El monto solicitado ($" << monto_solicitado << ") excede el efectivo disponible en el cajero ($" << efectivo_cajero << ")." << endl;
            posible = false;
        } else {
            monto_restante = monto_solicitado;

            // --- Intentar entregar billetes (usando la menor cantidad posible) ---
            // Billetes de 20
            if (monto_restante >= 20 && billetes20 > 0) {
                int necesarios = monto_restante / 20;
                if (necesarios <= billetes20) {
                    billetes20_entregados = necesarios;
                    billetes20 -= necesarios;
                    monto_restante -= necesarios * 20;
                } else {
                    billetes20_entregados = billetes20;
                    monto_restante -= billetes20 * 20;
                    billetes20 = 0;
                }
            }

            // Billetes de 10
            if (monto_restante >= 10 && billetes10 > 0) {
                int necesarios = monto_restante / 10;
                if (necesarios <= billetes10) {
                    billetes10_entregados = necesarios;
                    billetes10 -= necesarios;
                    monto_restante -= necesarios * 10;
                } else {
                    billetes10_entregados = billetes10;
                    monto_restante -= billetes10 * 10;
                    billetes10 = 0;
                }
            }

            // Billetes de 5
            if (monto_restante >= 5 && billetes5 > 0) {
                int necesarios = monto_restante / 5;
                if (necesarios <= billetes5) {
                    billetes5_entregados = necesarios;
                    billetes5 -= necesarios;
                    monto_restante -= necesarios * 5;
                } else {
                    billetes5_entregados = billetes5;
                    monto_restante -= billetes5 * 5;
                    billetes5 = 0;
                }
            }

            // Billetes de 1
            if (monto_restante >= 1 && billetes1 > 0) {
                int necesarios = monto_restante;
                if (necesarios <= billetes1) {
                    billetes1_entregados = necesarios;
                    billetes1 -= necesarios;
                    monto_restante -= necesarios;
                } else {
                    billetes1_entregados = billetes1;
                    monto_restante -= billetes1;
                    billetes1 = 0;
                }
            }

            // --- Verificar si se pudo entregar el monto exacto ---
            if (monto_restante > 0) {
                cout << "\nERROR: No es posible entregar el monto exacto de $" << monto_solicitado
                     << " con la combinación de billetes disponible en el cajero." << endl;
                posible = false;

                // Restaurar los billetes que se habían descontado (simulación)
                billetes20 += billetes20_entregados;
                billetes10 += billetes10_entregados;
                billetes5 += billetes5_entregados;
                billetes1 += billetes1_entregados;
            }
        }
    }

    // ================== 3. SALIDA DE RESULTADOS ==================
    if (posible) {
        // Actualizar saldo del usuario
        saldo_usuario -= monto_solicitado;

        // Calcular efectivo restante del cajero
        efectivo_cajero = billetes20 * 20 + billetes10 * 10 + billetes5 * 5 + billetes1 * 1;

        cout << "\n--- Operación exitosa ---" << endl;
        cout << "Billetes entregados:" << endl;
        cout << "De $20: " << billetes20_entregados << endl;
        cout << "De $10: " << billetes10_entregados << endl;
        cout << "De $5: " << billetes5_entregados << endl;
        cout << "De $1: " << billetes1_entregados << endl;
        cout << "\nSaldo restante del usuario: $" << saldo_usuario << endl;
        cout << "Efectivo restante en el cajero: $" << efectivo_cajero << endl;
        cout << "Billetes restantes en el cajero:" << endl;
        cout << "De $20: " << billetes20 << endl;
        cout << "De $10: " << billetes10 << endl;
        cout << "De $5: " << billetes5 << endl;
        cout << "De $1: " << billetes1 << endl;
    }

    return 0;
}
