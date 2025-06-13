#include <stdio.h>
#include <stdlib.h>

// ? main function -> entrance point: first thing the OS looks for and executes
// ? int argc (argument count): quantidade de argumentos que foram passados para o programa na linha de comando ao chamar o executável
// ? char *argv´[] (Argument Vector):  vetor de ponteiros para caracteres. Cada elemento desse vetor aponta para uma string que representa um dos argumentos passados na linha de comando -> argv[0] sempre será o nome do programa 

int main(int argc, char *argv[]){

    // * Arguments passed to the main function
    if (argc != 4){
        printf("WARN: You should type (only numbers): %s <Fuel consumption [km/L]> <Trip time [h]> <Car speed [km/h]>\n", argv[0]);
        return 1;
    }

    double fuel_consumption = atof(argv[1]); // atof -> ASCII to Float
    double time = atof(argv[2]);
    double speed = atof(argv[3]);

    printf("Fuel consumption: %.2f km/L | Trip time: %.2f h | Car speed: %.2f km/h \n", fuel_consumption, time, speed);
    printf("Distance traveled: %.2f km\n", time * speed);
    printf("Fuel used: %.2f litros\n", (time * speed) / fuel_consumption);

    return 0;

}