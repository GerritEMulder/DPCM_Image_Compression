// Name: Gerrit Mulder

#include <stdio.h>
#include "mean_absolute_error.h"

// The main function of the program.
int main(int argc, char** argv) { 

	// Not enough arguments are given so display an error.
    if (argc < 3 || argc > 3) {
        printf("Error: Did not give the correct number of arguments, please try again with the correct number of arguments.\n");
        return 0;
    }

    // Creates all the variables I need.
    char* first_file = argv[1];
    char* second_file = argv[2];


    float MAN = mean_absolute_error(first_file, second_file);

    printf("Mean Absolute Error of the two images: %f\n", MAN);


}