    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <conio.h>
    #include "Persona.h"

     void altaPersona(ePersona persona[], int tampersonas, int posicion) {
        ePersona auxPersona;
        char nombre[20];
        int existe;
        int opcion=0;
        int flag=1;
        int flagLegajo=0;
        int flagNombre=0;
        long int flagDni=0;
        int flagEdad=0;

        do{
            system("cls");
            printf("\t-------------------------------------------------------\n");
            printf("\t|                 Alta  de persona                    |\n");
            printf("\t-------------------------------------------------------\n");
            if (flagLegajo==0){
                printf("\n\n\n\n\t\tPersona Nro.     :");
            }else{
                printf("\n\n\n\n\t\tPersona Nro.     : %d",auxPersona.idPersona);
            }
            if (flagNombre==0){
                printf("\n\n\t\tNombre persona   :");
            }else{
                printf("\n\n\t\tNombre persona   : %s",auxPersona.nombre);
            }

            if (flagDni==0){
                printf("\n\n\t\tD.N.I. Nro.      :");
            }else{
                printf("\n\n\t\tD.N.I. Nro.      : %d",auxPersona.dni);
            }

           if (flagEdad==0){
                printf("\n\n\t\tEdad.            :");
            }else{
                printf("\n\n\t\tEdad             : %d",auxPersona.edad);
            }

            switch(flag){
                case 0:
                    printf("\n\n\t\t\tError - Debe ingresar entre %d y %d\n",0,1);
                    system("\n\n\t\tpause");
                case 1:
                    auxPersona.idPersona=ingresoDatoInt("Ingrese persona : ");
                    existe=personaExiste(persona, tampersonas, auxPersona.idPersona);
                    if (existe!=-1){
                        flagLegajo = 1;
                        flag=2;
                    }else{
                        printf("\n\n\t\t\tError - El persona %d ya existe\n",auxPersona.idPersona);
                        system("\n\n\t\tpause");
                    }
                    break;
                case 2:
                    strcpy(auxPersona.nombre, ingresoDatoChar("Ingrese nombre : ",nombre));
                    flagNombre = 1;
                    flag=3;
                    break;
                case 3:
                    printf("\n\n\n\n\n\n\n\n\t\t\t\tIngrese D.N.I. : ");
                    scanf("%d",&auxPersona.dni);
                    flagDni=1;
                    flag=4;
                    break;
                case 4:
                    printf("\n\n\n\n\n\n\n\n\t\t\t\tIngrese edad : ");
                    scanf("%d",&auxPersona.edad);
                    flagEdad=1;
                    flag=5;
                    break;
               case 5:
                    flag=6;
                    opcion=opcionesMenu("\n\n\t\tConfirma cambios ?    1-grabar 0-Salir :");
                    if(opcion<0 || opcion>1){
                        printf("\n\n\t\t\tError - Debe ingresar entre %d y %d\n",0,1);
                        system("\n\n\t\tpause");
                        flag=5;
                    }else if (opcion==1){
                        persona[posicion].idPersona=auxPersona.idPersona;
                        strcpy(persona[posicion].nombre, auxPersona.nombre);
                        persona[posicion].estado=1;
                        flag=7;
                    }else{
                        flag=7;
                        break;
                    }
                }
            }while(flag!=7);
       }
