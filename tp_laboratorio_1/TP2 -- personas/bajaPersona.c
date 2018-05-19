    #include <stdio.h>
    #include <stdlib.h>
    #include "Persona.h"
    #include "bajaPersona.h"

    void bajaPersona(ePersona persona[],int tampersonas) {
        int i;
        int id;
        int salir;
        do{
            salir=0;
            system("cls");
            printf("\t-------------------------------------------------------\n");
            printf("\t|                    Baja de persona                  |\n");
            printf("\t-------------------------------------------------------\n");
            ordenarPersonaId(persona, tampersonas);
            mostrarListaPersonas(persona, tampersonas);
            printf("\n\n\t\t Selecione un persona a dar de baja - 0 salir : ");
            scanf("%d", &id);
            if(id!=0){
                for(i=0; i<tampersonas; i++){
                    if(persona[i].idPersona == id && persona[i].estado==1){
                        confirmaBaja(persona, i);
                        salir=2;
                        break;
                    }else{
                        salir=3;
                    }
                }
                if (salir==3){
                    printf("\n\tPersona %d no exsiste - ",id);
                    system("pause");
                }
            }
         }while(salir!=0);
       }

       void confirmaBaja(ePersona persona[], int id){
        int salir=0;
        do{
            int opcion=0;
            system("cls");
            printf("\t-------------------------------------------------------\n");
            printf("\t|                 Baja de persona                     |\n");
            printf("\t-------------------------------------------------------\n");
            printf("\n\n\t\t\tPersona Nro. : %d",persona[id].idPersona);
            printf("\n\n\t\t\tNombre       : %s",persona[id].nombre);
            printf("\n\n\t\t\tD.N.I.       : %d",persona[id].dni);
            printf("\n\n\t\t\tEdad         : %d",persona[id].edad);
            printf("\n\n\n\n\n\n\t\tElija una opcion  1 Confirma baja - 0 Salir :--> ");
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
                   persona[id].estado=0;
                   salir=-1;
                   break;
            }
    }while(salir!=-1);
  }
