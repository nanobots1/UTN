    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "Persona.h"
    #include "grafico.h"

    void burbujeo(ePersona persona[], int i,int j){
        int auxId=persona[i].idPersona;
        persona[i].idPersona=persona[j].idPersona;
        persona[j].idPersona=auxId;

        char auxnombre[50];
        strcpy(auxnombre,persona[i].nombre);
        strcpy(persona[i].nombre,persona[j].nombre);
        strcpy(persona[j].nombre,auxnombre);

        int auxDni=persona[i].dni;
        persona[i].dni=persona[j].dni;
        persona[j].dni=auxDni;

        int auxEdad=persona[i].edad;
        persona[i].edad=persona[j].edad;
        persona[j].edad=auxEdad;

        int auxEstado=persona[i].estado;
        persona[i].estado=persona[j].estado;
        persona[j].estado=auxEstado;
    }
    void HardCodePersona(ePersona persona[], int tampersonas){
        int i;
        int id[20] = {1015,1014,1004,1003,1006,1005,1008,1007,1009,1010,1011,1012,1013,1001,1002};
        char nombre[][50]= {"Mariana","Mauro","Laura","Vanesa","Gustavo","Alexandra","Marcelo","Natalia","Victoria","Gisela","Antonela","Patricia","Santiago","Pedro","Romualdo"};
        int dni[20] = {2809454,25978654,2287466,12941598,9619629,93864644,20458689,309459850,24665454,317910522,19262912,31854965,28226657,30867155,94769558};
        int edad[20] = {17,40,45,64,24,26,68,16,19,15,39,17,23,19,21};
        int estado[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
        for(i=0; i<tampersonas; i++){
            persona[i].edad = 0;
            persona[i].estado = 0;
        }
        for(i=0; i<15; i++){
            persona[i].idPersona = id[i];
            strcpy(persona[i].nombre, nombre[i]);
            persona[i].dni = dni[i];
            persona[i].edad = edad[i];
            persona[i].estado = estado[i];
        }
    }
    int ePersonaVacio(ePersona persona[], int tampersona){
        int vacio = 0;
        int i;
        for(i=0; i<tampersona; i++){
             if (persona[i].estado != 0){
                vacio = 1;
                break;
            }
        }
        return vacio;
    }
    int ingresoDatoInt(char txt[]){
        int dato;
        printf("\n\n\n\n\n\n\n\n\t\t%s ",txt);
        scanf("%d", &dato);
        return dato;
    }
    void *ingresoDatoChar(char *txt, char *nombre){
        printf("\n\n\n\n\n\n\n\n\t\t%s ",txt);
        fflush(stdin);
        gets(nombre);
 //        nombre=substring(nombre, 30);
        return nombre;
    }
       void *ingresoNumero(char *txt, char *numero){
        printf("\n\n\n\n\n\n\n\n\t\t%s ",txt);
        fflush(stdin);
        gets(numero);
 //        nombre=substring(nombre, 30);
        return numero;
    }
    int personaExiste(ePersona persona[], int tampersona, int id){
        int existe = 0;
        int i;
        for(i=0; i<tampersona; i++){
             if (persona[i].idPersona == id){
                existe = -1;
                break;
            }
        }
        return existe;
    }
    int personaLibre(ePersona buscar[], int registros){
        int posicion = -1;
        int i;
        for(i=0; i<registros; i++){
            if (buscar[i].estado == 0){
                 posicion = 1;
            break;
            }
        }
        return posicion;
    }
    void mostrarListaPersonas(ePersona persona[], int tampersona) {
        int i;
        printf("\t\tpersona            nombre\n");
        for(i=0; i<tampersona; i++){
            if(persona[i].estado == 1){
                 printf("\n\t\t%1d          %1s", persona[i].idPersona, persona[i].nombre);
            }
        }
       printf("\n\n");
    }
    void ordenarPersonaId(ePersona persona[], int tampersona){
        for(int i=0;i<tampersona-1; i++){
            for(int j=i+1;j<tampersona; j++){
                if(persona[i].idPersona > persona[j].idPersona){
                    burbujeo(persona, i,j);
                }
            }
        }
    }
    void ordenarPersonaNombre(ePersona persona[], int tampersona){
        for(int i=0;i<tampersona-1; i++){
            for(int j=i+1;j<tampersona; j++){
                if(strcmp(persona[j].nombre,persona[i].nombre)<0){
                   burbujeo(persona, i, j);
                }
            }
        }
    }
    int opcionesMenu(char txt[]){
        int dato;
        printf("\n\n\n\t\t%s ",txt);
        scanf("%d", &dato);
        return dato;
    }

