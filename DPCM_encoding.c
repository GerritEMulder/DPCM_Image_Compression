// Name: Gerrit Mulder

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "DPCM_encoding_function.h"

// The main function of the program.
int main(int argc, char** argv) { 

	// Not enough arguments are given so display an error.
    if (argc < 3 || argc > 3) {
        printf("Error: Did not give the correct number of arguments, please try again with the correct number of arguments.\n");
        return 0;
    }

    char* in_PGM_filename_Ptr = argv[1];
    int prediction_rule = atoi(argv[2]);

    if (strstr(in_PGM_filename_Ptr, ".pgm") == NULL) {
    	printf("Error: Did not give a valid filename, please try again with a valid filename\n");
    	return 0;
    }

    float* avg_abs_error_Ptr = malloc(sizeof(*avg_abs_error_Ptr));
	float* std_abs_error_Ptr = malloc(sizeof(*std_abs_error_Ptr));

	clock_t t;
   	t = clock(); // Used for finding out encoding time.

   	Encode_Using_DPCM(in_PGM_filename_Ptr, prediction_rule, avg_abs_error_Ptr, std_abs_error_Ptr);

   	t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC; // calculate the elapsed time

	printf("Average of the absolute prediction error values: %f\n", *avg_abs_error_Ptr);
	printf("Standard deviation of the absolute prediction error values: %f\n", *std_abs_error_Ptr);
	printf("The compression time: %f\n", time_taken);
	free(avg_abs_error_Ptr);
	free(std_abs_error_Ptr);

	return 0;
}


