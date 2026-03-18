#include <iostream>
using namespace std;

int main() {
    float promedio, materias_perdidas, ingresos_familiares, participacion_proyectos, asistencia;

    cout << "Ingrese el promedio (0-10): ";
    cin >> promedio;
    while (promedio < 0 || promedio > 10) {
        cout << "Promedio inválido. Debe estar entre 0 y 10. Ingrese nuevamente: ";
        cin >> promedio;
    }

    cout << "Ingrese el número de materias perdidas: ";
    cin >> materias_perdidas;
    while (materias_perdidas < 0) {
        cout << "Número de materias perdidas no puede ser negativo. Ingrese nuevamente: ";
        cin >> materias_perdidas;
    }

    cout << "Ingrese el porcentaje de asistencia (0-100): ";
    cin >> asistencia;
    while (asistencia < 0 || asistencia > 100) {
        cout << "Asistencia inválida. Debe estar entre 0 y 100. Ingrese nuevamente: ";
        cin >> asistencia;
    }

    cout << "Ingrese el nivel de ingresos familiares (0 = altos, 1 = bajos): ";
    cin >> ingresos_familiares;
    while (ingresos_familiares != 0 && ingresos_familiares != 1) {
        cout << "Valor inválido. Ingrese 0 para ingresos altos o 1 para ingresos bajos: ";
        cin >> ingresos_familiares;
    }

    cout << "Ingrese la participación en proyectos (0 = no participa, 1 = participa): ";
    cin >> participacion_proyectos;
    while (participacion_proyectos != 0 && participacion_proyectos != 1) {
        cout << "Valor inválido. Ingrese 0 para no participa o 1 para participa: ";
        cin >> participacion_proyectos;
    }

    cout << "\n--- Resultados ---\n";

    if (asistencia < 80) {
        cout << "Tipo de ayuda: Sin beneficio" << endl;
        cout << "Razón académica: Asistencia menor al 80% (" << asistencia << "%)." << endl;
        cout << "Razón económica: No aplica evaluación económica por incumplimiento académico." << endl;
        cout << "Observación final: El estudiante tiene: Asistencia menor al 80% (" << asistencia << "%). No aplica evaluación económica por incumplimiento académico. Por lo tanto, se otorga: Sin beneficio." << endl;
    } else if (promedio < 7) {
        cout << "Tipo de ayuda: Sin beneficio" << endl;
        cout << "Razón académica: Promedio menor a 7 (" << promedio << ")." << endl;
        cout << "Razón económica: No aplica evaluación económica por incumplimiento académico." << endl;
        cout << "Observación final: El estudiante tiene: Promedio menor a 7 (" << promedio << "). No aplica evaluación económica por incumplimiento académico. Por lo tanto, se otorga: Sin beneficio." << endl;
    } else if (promedio >= 9 && asistencia >= 90 && materias_perdidas == 0) {
        cout << "Tipo de ayuda: Beca completa" << endl;
        cout << "Razón académica: Promedio " << promedio << ", asistencia de " << asistencia << ", y 0 materias perdidas." << endl;
        cout << "Razón económica: Cumple con todos los requisitos académicos para beca completa." << endl;
        cout << "Observación final: El estudiante tiene: Promedio " << promedio << ", asistencia de " << asistencia << "%, y 0 materias perdidas. Cumple con todos los requisitos académicos para beca completa. Por lo tanto, se otorga: Beca completa." << endl;
    } else if (promedio >= 8 && promedio < 9 && asistencia >= 85) {
        if (participacion_proyectos == 1 && ingresos_familiares == 1 && materias_perdidas == 0) {
            cout << "Tipo de ayuda: Beca completa" << endl;
            cout << "Razón académica: Promedio " << promedio << ", asistencia de " << asistencia << "%." << endl;
            cout << "Razón económica: Mejora a beca completa por participación en proyectos e ingresos bajos (sin materias perdidas)." << endl;
            cout << "Observación final: El estudiante tiene: Promedio " << promedio << ", asistencia de " << asistencia << "%. Mejora a beca completa por participación en proyectos e ingresos bajos (sin materias perdidas). Por lo tanto, se otorga: Beca completa." << endl;
        } else if (participacion_proyectos == 1 && ingresos_familiares == 1 && materias_perdidas > 0) {
            cout << "Tipo de ayuda: Beca parcial" << endl;
            cout << "Razón académica: Promedio " << promedio << ", asistencia de " << asistencia << "%." << endl;
            cout << "Razón económica: Participa en proyectos e ingresos bajos, pero no puede obtener beca completa por tener materias perdidas (" << materias_perdidas << ")." << endl;
            cout << "Observación final: El estudiante tiene: Promedio " << promedio << ", asistencia de " << asistencia << "%. Participa en proyectos e ingresos bajos, pero no puede obtener beca completa por tener materias perdidas (" << materias_perdidas << "). Por lo tanto, se otorga: Beca parcial." << endl;
        } else {
            cout << "Tipo de ayuda: Beca parcial" << endl;
            cout << "Razón académica: Promedio " << promedio << ", asistencia de " << asistencia << "%." << endl;

            if (participacion_proyectos == 1 && ingresos_familiares == 0) {
                cout << "Razón económica: Participa en proyectos pero los ingresos no son bajos." << endl;
                cout << "Observación final: El estudiante tiene: Promedio " << promedio << ", asistencia de " << asistencia << "%. Participa en proyectos pero los ingresos no son bajos. Por lo tanto, se otorga: Beca parcial." << endl;
            } else if (participacion_proyectos == 0 && ingresos_familiares == 1) {
                cout << "Razón económica: Ingresos bajos pero no participa en proyectos." << endl;
                cout << "Observación final: El estudiante tiene: Promedio " << promedio << ", asistencia de " << asistencia << "%. Ingresos bajos pero no participa en proyectos. Por lo tanto, se otorga: Beca parcial." << endl;
            } else {
                cout << "Razón económica: No cumple condiciones para mejora económica." << endl;
                cout << "Observación final: El estudiante tiene: Promedio " << promedio << ", asistencia de " << asistencia << "%. No cumple condiciones para mejora económica. Por lo tanto, se otorga: Beca parcial." << endl;
            }
        }
    } else {

        if (participacion_proyectos == 1 && ingresos_familiares == 1) {
            cout << "Tipo de ayuda: Beca parcial" << endl;
            cout << "Razón académica: Promedio " << promedio << " y asistencia de " << asistencia << ", pero no cumple requisitos para beca parcial o completa." << endl;
            cout << "Razón económica: Mejora a beca parcial por participación en proyectos e ingresos bajos." << endl;
            cout << "Observación final: El estudiante tiene: Promedio " << promedio << " y asistencia de " << asistencia << ", pero no cumple requisitos para beca parcial o completa. Mejora a beca parcial por participación en proyectos e ingresos bajos. Por lo tanto, se otorga: Beca parcial." << endl;
        } else {
            cout << "Tipo de ayuda: Solo ayuda de materiales" << endl;
            cout << "Razón académica: Promedio " << promedio << " y asistencia de " << asistencia << ", pero no cumple requisitos para beca parcial o completa." << endl;

            if (participacion_proyectos == 1 && ingresos_familiares == 0) {
                cout << "Razón económica: Participa en proyectos pero los ingresos no son bajos." << endl;
                cout << "Observación final: El estudiante tiene: Promedio " << promedio << " y asistencia de " << asistencia << "), pero no cumple requisitos para beca parcial o completa. Participa en proyectos pero los ingresos no son bajos. Por lo tanto, se otorga: Solo ayuda de materiales." << endl;
            } else if (participacion_proyectos == 0 && ingresos_familiares == 1) {
                cout << "Razón económica: Ingresos bajos pero no participa en proyectos." << endl;
                cout << "Observación final: El estudiante tiene: Promedio " << promedio << " y asistencia de " << asistencia << ", pero no cumple requisitos para beca parcial o completa. Ingresos bajos pero no participa en proyectos. Por lo tanto, se otorga: Solo ayuda de materiales." << endl;
            } else {
                cout << "Razón económica: No cumple condiciones para mejora económica." << endl;
                cout << "Observación final: El estudiante tiene: Promedio " << promedio << " y asistencia de " << asistencia << ", pero no cumple requisitos para beca parcial o completa. No cumple condiciones para mejora económica. Por lo tanto, se otorga: Solo ayuda de materiales." << endl;
            }
        }
    }

    return 0;
}
