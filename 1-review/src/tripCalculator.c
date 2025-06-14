#include <stdio.h>
#include <stdlib.h>

/*
 ? main function: the entry point of your program. It's the first thing the OS searches for and executes.
 
 ? Argument Count (int argc): The total number of arguments passed via the Command Line Interface (CLI) when the program is executed.

 ? Argument Vector (char *argv[]): A pointer array to characters (i.e., an array of strings). Each element points to a string representing one of the arguments passed through the CLI.

 ! NOTE: argv[0] is always the program's name itself.
 */

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