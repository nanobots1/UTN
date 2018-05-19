    /**
     * Programación I - UTN Fra
     * Trabajo práctico Nº 2 - ABM
     * Alumno : Roberto Desipio  - 1 F
    */
    #include <string.h>
    #include "Persona.h"
    #include "grafico.h"
    #include "menuPantalla.h"
    #define TAMPERSONAS 20

    int main(){
        char txt[25];
        strcpy(txt,"Ingrese una opcion ==> ");
        int min=1;
        int max=6;
        ePersona persona[TAMPERSONAS];
        HardCodePersona(persona, TAMPERSONAS);
        menuPersona(txt, min, max, persona, TAMPERSONAS);
        return 0;
    }
