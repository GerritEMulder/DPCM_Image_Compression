// Name: Gerrit Mulder

#include <stdio.h>
#include <time.h>
#include <string.h>
#include "DPCM_decoding_function.h"


// The main function of the program.
int main(int argc, char** argv) { 

	// Not enough arguments are given so display an error.
    if (argc < 2 || argc > 2) {
        printf("Error: Did not give the correct number of arguments, please try again with the correct number of arguments.\n");
        return 0;
    }

    char* in_encoded_filename_Ptr = argv[1];

    if (strstr(in_encoded_filename_Ptr, ".DPCM") == NULL) {
    	printf("Error: Did not give a valid filename, please try again with a valid filename\n");
    	return 0;
    }

	clock_t t;
   	t = clock(); // Used for finding out compression time.
	
	Decode_Using_DPCM(in_encoded_filename_Ptr);

	t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC; // calculate the elapsed time

	printf("The decompression time: %f\n", time_taken);

	return 0;
}