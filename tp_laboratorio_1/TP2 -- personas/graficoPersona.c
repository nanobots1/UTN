    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "Persona.h"
    #include "grafico.h"

    void graficoPersona(ePersona persona[],int tampersonas) {
        eGrafico grafico[tampersonas];
        inicializarGrafico(grafico, tampersonas);
        int i;
        int flag=0;
        for(i=0; i<20; i++){
            if (persona[i].edad<18 &&persona[i].estado==1){
                strcpy(grafico[flag].menor18,"*");
                grafico[flag].estado=1;
                flag++;
            }
        }
        flag=0;
        for(i=0; i<20; i++){
            if ((persona[i].edad>18 && persona[i].edad<=35)&&persona[i].estado==1){
                strcpy(grafico[flag].entre19y35,"*");
                grafico[flag].estado=1;
                 flag++;
            }
        }
        flag=0;
        for(i=0; i<20; i++){
            if (persona[i].edad>35 && persona[i].estado==1){
                strcpy(grafico[flag].mayora35,"*");
                grafico[flag].estado=1;
                flag++;
            }
        }
        system("cls");
        printf("\t-----------------------------------------------------------------\n");
        printf("\t|                Grafico de personas por edad                   |\n");
        printf("\t-----------------------------------------------------------------\n\n\n\n");
        for (i=20;i>=0;i--){
            if(grafico[i].estado==1){
                printf("\t\t\t%s\t\t%s\t\t%s   \n",grafico[i].menor18,grafico[i].entre19y35,grafico[i].mayora35);
            }
        }
        printf("\n\t\t Menores de 18    entre 19 y 35     mayores de 35 \n\n\n\n\n");
        system("pause");
    }
