    #include "funciones.h"

    float sumar(float nroUno, float nroDos) {
        return nroUno + nroDos;
    }

    float restar(float nroUno, float nroDos){
        return nroUno - nroDos;
    }

    float dividir(float nroUno, float nroDos) {
        return nroUno/nroDos;
    }

    float multiplicar(float nroUno, float nroDos) {
        return nroUno*nroDos;
    }

     long long factorial(int nroUno){
        if(nroUno>1){
            return nroUno*factorial(nroUno-1);
        }else{
            return 1;
        }
    }

