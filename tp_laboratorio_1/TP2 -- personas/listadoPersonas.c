    #include <stdio.h>
    #include <stdlib.h>
    #include "Persona.h"
    #include "listadoPersonas.h"

    void listadoPersonas(ePersona persona[], int tampersonas) {
        system("cls");
        printf("\t--------------------------------------------------------------\n");
        printf("\t|        Sistema Personas - Listado  -version 1.0            |\n");
        printf("\t--------------------------------------------------------------\n");
        mostrarListaPersonas(persona, tampersonas);
        system("pause");
    }



