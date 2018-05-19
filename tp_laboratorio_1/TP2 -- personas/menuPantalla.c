    #include <stdio.h>
    #include <stdlib.h>
    #include "Persona.h"
    #include "altaPersona.h"
    #include "bajaPersona.h"
    #include "listadoPersonas.h"
    #include "graficoPersona.h"

    int menuPersona(char texto[],int min, int max, ePersona persona[], int tampersona) {
        int opcion;
        int id;
        do{
            system("cls");
            printf("\t--------------------------------------------------------------\n");
            printf("\t|               Sistema Personas - version 1.0.0             |\n");
            printf("\t--------------------------------------------------------------\n");
            printf("\n\n\n\t\t\tSeleccione una opcion : ");
            printf("\n\n\n\t\t\t1- Alta persona");
            printf("\n\n\t\t\t2- Baja de persona");
            printf("\n\n\t\t\t3- Listado de persona");
            printf("\n\n\t\t\t4- Grafico de persona");
            printf("\n\n\t\t\t6- Salir");
            opcion=opcionesMenu(texto);
            if (opcion< min || opcion>max){
               printf("\n\n\t\t\tError - Debe ingresar entre %d y %d", min, max);
               system("pause");
            }
            switch( opcion ) {
                case  1 :
                    id=personaLibre(persona,tampersona);
                    if(id!=-1){
                        altaPersona(persona, tampersona);
                    }else{
                        printf("\n\tERROR - No hay mas espacio para agregar persona\n");
                        system("pause");
                    }
                     break;
                case 2 :
                    bajaPersona(persona, tampersona);
                    opcion=-1;
                    break;
                case 3 :
                    ePersonaVacio(persona, tampersona);
                    listadoPersonas(persona, tampersona);
                    opcion=-1;
                    break;
                case 4 :
                    graficoPersona(persona, tampersona);
                    opcion=-1;
                    break;

                case 6 :
                    system("cls");
                    opcion=0;
                    break;
            }
        } while( opcion!=0 );
        return opcion;
    }
