/**
     * Programación I - UTN Fra
     * Trabajo práctico Nº 1 - Calculadora
     * Alumno : Roberto Desipio 1º 'C'
     */

    #include <stdio.h>
    #include <stdlib.h>
    #include "funciones.h"
    #include "funcAux.h"

    int main()
    {
        int opcion=0;

        float operandoUno;
        float operandoDos;

        int flagNro1  = 0;
        int flagNro2  = 0;
        int flagSuma  = 0;
        int flagResta = 0;
        int flagDivi  = 0;
        int flagMulti = 0;
        int flagFacto = 0;

        float totSuma;
        float totResta;
        float totMulti;
        float totDivi;
        long long totFacto;

        while(1){
            system("cls");
            printf("\t=======   Trabajo practico Nro. 1 - Calculadora   ========");
            if (flagNro1 == 1){
                printf("\n\n\n\t\t1. El 1er operando es ( A=%.*f )", operandoUno-(int) operandoUno ? 6 : 0, operandoUno);
            }else{
                printf("\n\n\n\t\t1. Ingresar 1er operando (A=X)");
            }

            if (flagNro2 == 1){
                printf("\n\n\t\t2. El 2do es operando ( B=%.*f )",  operandoDos-(int) operandoDos ? 6 : 0, operandoDos);
            }else{
                printf("\n\n\t\t2. Ingresar 2do operando ( B=Y )");
            }

            if (flagSuma == 1){
                printf("\n\n\t===>    3- La suma es ( %.*f+%.*f=%.*f )", operandoUno-(int) operandoUno ? 6 : 0, operandoUno, operandoDos-(int) operandoDos ? 6 : 0, operandoDos, totSuma-(int) totSuma ? 6 : 0, totSuma);
                flagSuma = 0;
            }else{
                printf("\n\n\t\t3- Calcular la suma ( A+B )");
            }

            if (flagResta == 1){
                printf("\n\n\t===>    4- La resta es ( %.*f-%.*f=%.*f )", operandoUno-(int) operandoUno ? 6 : 0, operandoUno, operandoDos-(int) operandoDos ? 6 : 0, operandoDos, totResta-(int) totResta ? 6 : 0, totResta);
                flagResta = 0;
            }else{
                printf("\n\n\t\t4- Calcular resta ( A-B )");
            }

            if (operandoDos==0 && flagDivi == 1){
                printf("\n\n\t===>    5- ( ERROR no se puede dividir por 0 )");
                flagDivi = 0;
            }else if (flagDivi == 0){
                 printf("\n\n\t\t5- Calcular la division ( A/B )");
            }else {
                printf("\n\n\t===>    5- La division es ( %.*f/%.*f=%.*f )", operandoUno-(int) operandoUno ? 6 : 0, operandoUno, operandoDos-(int) operandoDos ? 6 : 0, operandoDos, totDivi-(int) totDivi ? 6 : 0, totDivi);
                flagDivi = 0;
            }

            if (flagMulti == 0){
                printf("\n\n\t\t6- Calcular la multiplicacion ( A*B )");
            }else{
                printf("\n\n\t===>    6- La multiplicacion es ( %.*f*%.*f=%.*f )", operandoUno-(int) operandoUno ? 6 : 0, operandoUno, operandoDos-(int) operandoDos ? 6 : 0, operandoDos, totMulti-(int) totMulti ? 6 : 0, totMulti);
                flagMulti = 0;
            }

            if (operandoUno<0 && flagFacto == 1){
                printf("\n\n\t===>    7- ( ERROR el factorial no puede ser menor a 0 )");
             }else if (flagFacto == 0){
                printf("\n\n\t\t7- Calcular factorial de ( !A )");
            }else if(operandoUno-(int) operandoUno!=0){
                printf("\n\n\t===>    7- ( ERROR no se calcular factorial de un flotante )");
            }else if(operandoUno>20){
                printf("\n\n\t===>    7- ( ERROR no se calcular factorial mayor a 20 )");
            }else{
                printf("\n\n\t===>    7- El factorial es ( %lld )", totFacto);
                flagFacto = 0;
            }

            printf("\n\n\t\t8- Calcular todas las operaciones");
            printf("\n\n\t\t9- Salir\n");
            printf("\n\n\t\tIngrese Opcion :--> ");
            scanf("%d",&opcion);

            switch(opcion){
                case 1:
                    printf("\t\tIngresar 1er operando: ");
                    operandoUno = pedirNumero();
                    flagNro1 = 1;
                    break;
                case 2:
                    printf("\t\tIngresar 2do operando: ");
                    operandoDos = pedirNumero();
                    flagNro2 = 1;
                    break;
                case 3:
                    totSuma = sumar(operandoUno, operandoDos);
                    flagSuma=1;
                    break;
                case 4:
                    totResta = restar(operandoUno, operandoDos);
                    flagResta=1;
                    break;
                case 5:
                    flagDivi=1;
                    totDivi = dividir(operandoUno, operandoDos);
                    break;
                case 6:
                    flagMulti=1;
                    totMulti = multiplicar(operandoUno, operandoDos);
                    break;
                case 7:
                    totFacto = factorial((int)operandoUno);
                    flagFacto=1;
                    break;
                case 8:
                    flagSuma =1;
                    flagResta=1;
                    flagMulti=1;
                    flagDivi =1;
                    flagFacto=1;
                    totSuma  = sumar(operandoUno, operandoDos);
                    totResta = restar(operandoUno, operandoDos);
                    totDivi  = dividir(operandoUno, operandoDos);
                    totMulti = multiplicar(operandoUno, operandoDos);
                    totFacto = factorial((int)operandoUno);
                    break;
                case 9:
                    return 1;
                    break;
                default :
                    printf( "\n   Debe ingresar de 1 al 9  -  " );
                    system("pause");
            }
        }
        return 0;
    }
