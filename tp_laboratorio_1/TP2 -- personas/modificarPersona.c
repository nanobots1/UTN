    /**
     * Programación I - UTN Fra
     * Trabajo práctico Nº 2 - ABM
     * Alumno : Roberto Desipio 1 F
     */

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <conio.h>
    #include "Persona.h"
    #include "modificarPersona.h"

    void modificarPersona(ePersona persona[],int tampersonas) {
        int i;
        int id;
        int salir=0;
        int flagPersona=0;
        do{
            system("cls");
            printf("\t-------------------------------------------------------");
            printf("\n\t|             Modificacion  de usuario                    |");
            printf("\n\t-------------------------------------------------------");
            id=ePersonaVacio(persona, tampersonas);
            if(id==0){
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\tNo hay persona para mostrar - archivo vacio ");
                system("pause");
            }else{
                ordenarPersonaNombre(persona, tampersonas);
                mostrarListaPersonas(persona, tampersonas);
                printf("\n\n\n\t\t Selecione un legajo a modificar - 0 salir : ");
                scanf("%d", &id);
                if(id!=0){
                    for(i=0; i<tampersonas; i++){
                        if(persona[i].idPersona == id){
                            persona[i].estado=0;
                            cambiosPersona(persona, i);
                            flagPersona=1;
                            salir=-1;
                            break;
                        }
                    }
                    if (flagPersona!=1){
                            printf("\n\tEl usuario %d no exsiste  -  ",id);
                            system("pause");
                            break;
                    }

                }else{
                        salir=-1;
                    }
            }
        }while(salir!=-1);
    }
    void cambiosPersona(ePersona usuario[],int id) {
        ePersona auxPersona;
        auxPersona=usuario[id];
        int salir=0;
        do{
            fflush(stdin);
            system("cls");
            printf("\t-------------------------------------------------------");
            printf("\n\t|               Modificacion  de usuario 1                   |");
            printf("\n\t-------------------------------------------------------");
            int opcion=0;

            printf("\n\n\n\t\tPersona Nro.     : %d",auxPersona.idPersona);
            printf("\n\n\t\t1- Nombre : %s",auxPersona.nombre);
            printf("\n\n\t\t2- Pasword : %d",auxPersona.dni);

            printf("\n\n\n\n\n\n\t\tIngrese campo a modificar - 0 Salir :--> ");
            scanf("%d",&opcion);

            if (opcion< 0 || opcion>2){
               printf("\n\n\t\t\tError - Debe ingresar entre %d y %d\n",0,2);
               system("\n\n\t\tpause");
            }
            switch(opcion){
                case 0:
                    guardarcambios(usuario, id, auxPersona);
                    salir=-1;
                    break;
                case 1:
                    printf("\t\tIngresar nombre usuario: ");
                    fflush(stdin);
                    gets(auxPersona.nombre);
                    break;
                case 2:
                    printf("\t\tIngresar nuevo dni: ");
                    fflush(stdin);
                    scanf("%d",&auxPersona.dni);
                    break;
            }

    }while(salir!=-1);
  }



       void guardarcambios(ePersona usuario[],int idPersona, ePersona auxPersona){
        int salir=0;
        do{
           fflush(stdin);
            system("cls");
            printf("\t-------------------------------------------------------");
            printf("\n\t|               Modificacion  de usuario 2                   |");
            printf("\n\t-------------------------------------------------------");
            int opcion=0;

            printf("\n\n\n\t\tPersona Nro.     : %d",auxPersona.idPersona);
            printf("\n\n\t\t1- Nombre : %s",auxPersona.nombre);
            printf("\n\n\t\t2- D.N.I. : %d",auxPersona.dni);

            printf("\n\n\n\n\t\tElija una opcion  1 Guardar cambios - 0 Salir :--> ");
            scanf("%d",&opcion);
            if (opcion<0 || opcion>1){
               printf("\n\n\t\t\tError - Debe ingresar entre %d y %d\n",0,1);
               system("\n\n\t\tpause");
            }
            switch(opcion) {
                case  0 :
                    salir=-1;
                    break;
                case 1 :
                    strcpy(usuario[idPersona].nombre, auxPersona.nombre);
                    usuario[idPersona].dni= auxPersona.dni;
                    usuario[idPersona].estado=1;
                    salir=-1;
                    break;
            }

    }while(salir!=-1);
  }



