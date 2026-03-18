#include <iostream>
using namespace std;

int main(){
    //Declaración de variables
    int hora, num_faltas, credencial, curso;

    //Proceso o ingreso de variables
    cout<< "Hora actual: 13:00h  /  ";
    cout<< "Curso del horario (tarde): 3"<<endl;

    do{
        cout<< "Ingrese su hora de ingreso(minutos 00, 10, 15, etc): ";
        cin>> hora;
    }while(hora<0 || hora>60);

    do{
        cout<< "Ingrese la cantidad de faltas que tenga: ";
        cin>> num_faltas;
    }while(num_faltas<0);

    do{
        cout<< "Tiene credencial? 1.-Si  /  2.-No : ";
        cin>> credencial;
    }while(credencial<=0 || credencial>=3);

    do{
        cout<< "Ingrese al curso al que pertenece: ";
        cin>> curso;
    }while(curso<=0 || curso>5);

    //Salida
    if(hora==00 && num_faltas<3 && credencial==1 && curso==3){
        cout<< "\nPuede ingresar a clases.";
    }else if(((hora>0 && hora<=10) || (num_faltas>=3 && num_faltas<=5)) && credencial==1 && curso==3){
        if((hora>0 && hora<=10) && num_faltas<3){
            cout<< "\nPuede ingresar a clases pero con advertencia. Debe ingresar puntual.";
        }else if(hora==00 && (num_faltas>=3 && num_faltas<=5)){
            cout<< "\nPuede ingresar a clases pero con advertencia. No debe cometer más faltas";
        }else if((hora>0 && hora<=10) && (num_faltas>=3 && num_faltas<=5)){
            cout<< "\nPuede ingresar a clases pero con advertnecia. Debe ingresar puntual y ya no debe cometer más faltas";
        }
    }else if(hora>10 || num_faltas>5 || credencial==2 || curso!=3){
        cout<< "\nNo puede ingresar a clases.";
    }

    return 0;
}
