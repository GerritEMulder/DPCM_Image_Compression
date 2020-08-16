// Name: Gerrit Mulder

#include <stdio.h>
#include <stdlib.h>
#include "libpnm.h"

void Decode_Using_DPCM (char *in_filename_Ptr) {
	struct PGM_Image *pgmImage = malloc(sizeof(*pgmImage));
	FILE *pgm_file;

	// Reads in all the values before the prediction array.
	char buff[265];
	pgm_file = fopen(in_filename_Ptr, "r");
	fgets(buff, 265, pgm_file);
	int height = atoi(buff);
	fgets(buff, 265, pgm_file);
	int width = atoi(buff);
	fgets(buff, 265, pgm_file);
	int maxgreyvalue = atoi(buff);
	fgets(buff, 265, pgm_file);
	int prediction_rule = atoi(buff);
	fgets(buff, 265, pgm_file);
	char *file_Ptr = buff;

	int row, col, prediction_error, temp_int, north, north_north, north_east, north_north_east, north_west, west, west_west;

	create_PGM_Image(pgmImage, width, height, maxgreyvalue); // Creates the pgm image so it can be filled.

	// Reads in the prediction array and decodes the image.
	for(row = 0; row < height; row++) {
   		for(col = 0; col < width; col++) {

   			// The prediction rule is one, so dencodes the image using the 1st prediction rule.
   			if (prediction_rule == 1) {

   				// This pixel is in the first row and the first column and so 128 is added to the prediction error.
   				if ((row == 0) && (col == 0)) {
   					fscanf(pgm_file, "%d,", &prediction_error);
   					pgmImage -> image[row][col] = prediction_error + 128; 
   				}

   				// This pixel is in the first row and so west is added to the prediction error.
   				else if ((row == 0) && (col != 0)) {
   					fscanf(pgm_file, "%d,", &prediction_error);
   					west = pgmImage -> image[row][col - 1];
   					pgmImage -> image[row][col] = prediction_error + west; 
   				}

   				// This pixel is in the first, second, or last column, or first row and so north is added to the prediction error. 
   				else if ((col == 0) || (col == 1) || (col == (pgmImage -> width - 1)) || (row == 1)) {
   					fscanf(pgm_file, "%d,", &prediction_error);
   					north = pgmImage -> image[row - 1][col];
   					pgmImage -> image[row][col] = prediction_error + north; 
   				}

   				// This pixel is not in any of the previous situations and because the prediction rule is 1, west is added to the prediction error.
	    		else {
	    			fscanf(pgm_file, "%d,", &prediction_error);
   					west = pgmImage -> image[row][col - 1];
   					pgmImage -> image[row][col] = prediction_error + west; 
	    		}

   			}

   			// The prediction rule is two, so dencodes the image using the 2nd prediction rule.
   			else if (prediction_rule == 2) {

   				// This pixel is in the first row and the first column and so 128 is added to the prediction error.
	    		if ((row == 0) && (col == 0)) {
	    			fscanf(pgm_file, "%d,", &prediction_error);
   					pgmImage -> image[row][col] = prediction_error + 128; 
	    		}

	    		// This pixel is in the first row and so west is added to the prediction error.
	    		else if ((row == 0) && (col != 0)) {
	    			fscanf(pgm_file, "%d,", &prediction_error);
   					west = pgmImage -> image[row][col - 1];
   					pgmImage -> image[row][col] = prediction_error + west; 
	    		}

	    		// This pixel is not in any of the previous situations and because the prediction rule is 2, north is added to the prediction error.
	    		else {
	    			fscanf(pgm_file, "%d,", &prediction_error);
   					north = pgmImage -> image[row - 1][col];
   					pgmImage -> image[row][col] = prediction_error + north; 
	    		}
   			}

   			// The prediction rule is three, so dencodes the image using the 3rd prediction rule.
   			else if (prediction_rule == 3) {

   				// This pixel is in the first row and the first column and so 128 is added to the prediction error.
   				if ((row == 0) && (col == 0)) {
   					fscanf(pgm_file, "%d,", &prediction_error);
   					pgmImage -> image[row][col] = prediction_error + 128; 
   				}

   				// This pixel is in the first row and so west is added to the prediction error.
   				else if ((row == 0) && (col != 0)) {
   					fscanf(pgm_file, "%d,", &prediction_error);
   					west = pgmImage -> image[row][col - 1];
   					pgmImage -> image[row][col] = prediction_error + west; 
   				}

   				// This pixel is in the first, second, or last column, or first row and so north is added to the prediction error. 
   				else if ((col == 0) || (col == 1) || (col == (pgmImage -> width - 1)) || (row == 1)) {
   					fscanf(pgm_file, "%d,", &prediction_error);
   					north = pgmImage -> image[row - 1][col];
   					pgmImage -> image[row][col] = prediction_error + north; 
   				}

   				// This pixel is not in any of the previous situations and because the prediction rule is 3, West/2 + North/2 is added to the prediction error.
	    		else {
	    			fscanf(pgm_file, "%d,", &prediction_error);
   					west = pgmImage -> image[row][col - 1];
   					north = pgmImage -> image[row - 1][col];
   					temp_int = (west / 2) + (north / 2);
   					pgmImage -> image[row][col] = prediction_error + temp_int; 
	    		}
   			}

   			// The prediction rule is four, so dencodes the image using the 4th prediction rule.
   			else if (prediction_rule == 4) {

   				// This pixel is in the first row and the first column and so 128 is added to the prediction error.
   				if ((row == 0) && (col == 0)) {
   					fscanf(pgm_file, "%d,", &prediction_error);
   					pgmImage -> image[row][col] = prediction_error + 128; 
   				}

   				// This pixel is in the first row and so west is added to the prediction error.
   				else if ((row == 0) && (col != 0)) {
   					fscanf(pgm_file, "%d,", &prediction_error);
   					west = pgmImage -> image[row][col - 1];
   					pgmImage -> image[row][col] = prediction_error + west; 
   				}

   				// This pixel is in the first, second, or last column, or first row and so north is added to the prediction error. 
   				else if ((col == 0) || (col == 1) || (col == (pgmImage -> width - 1)) || (row == 1)) {
   					fscanf(pgm_file, "%d,", &prediction_error);
   					north = pgmImage -> image[row - 1][col];
   					pgmImage -> image[row][col] = prediction_error + north; 
   				}

   				// This pixel is not in any of the previous situations and because the prediction rule is 4, CALIC is used to decode.
	    		else {
	    			fscanf(pgm_file, "%d,", &prediction_error);
   					west = pgmImage -> image[row][col - 1];
   					north = pgmImage -> image[row - 1][col];
   					north_north = pgmImage -> image[row - 2][col]; 
	    			north_north_east = pgmImage -> image[row - 2][col + 1]; 
	    			north_east = pgmImage -> image[row - 1][col + 1]; 
	    			north_west = pgmImage -> image[row - 1][col - 1]; 
	    			west_west = pgmImage -> image[row][col - 2]; 

	    			// The Ternary code is 0 so get West.
	    			if (prediction_error == -1000) {
	    				temp_int = west;
	    				pgmImage -> image[row][col] = temp_int;
	    			}

	    			// The Ternary code is 1 so find the value in the 6 other pixels
	    			else if (prediction_error == 1000) {

	    				// Checks to see which pixel is different.
	    				if (north != west) {
	    					temp_int = north;
	    				}
	    				else if (north_north != west) {
	    					temp_int = north_north;
	    				}
	    				else if (north_west != west) {
	    					temp_int = north_west;
	    				}
	    				else if (north_east != west) {
	    					temp_int = north_east;
	    				}
	    				else if (north_north_east != west) {
	    					temp_int = north_north_east;
	    				}
	    				else if (west_west != west) {
	    					temp_int = west_west;
	    				}
	    				pgmImage -> image[row][col] = temp_int;
	    			}

	    			// We are not in binary mode so use GAP to decode.
	    			else {
	    				int dh, dv;
	    				dh = abs(west - west_west) + abs(north - north_west) + abs(north_east - north);
	    				dv = abs(west - north_west) + abs(north - north_north) + abs(north -north_north_east);

	    				// Sharp horizontal edge
	    				if (dv - dh > 80) {
							pgmImage -> image[row][col] = prediction_error + west;
						}

						// Sharp vertical edge
						else if (dh - dv > 80) {
							pgmImage -> image[row][col] = prediction_error + north;
						}

						else {
							int prediction;
							prediction = ((west + north) / 2) + ((north_east - north_west) / 4);

							// Horizontal edge
							if (dv - dh > 32) {
								prediction = ((0.5 * prediction) + (0.5 * west));
							}

							// Vertical edge
							else if (dh - dv > 32) {
								prediction = ((0.5 * prediction) + (0.5 * north));
							}

							// Weak horizontal edge
							else if (dv - dh > 8) {
								prediction = ((0.75 * prediction) + (0.25 * west));
							}

							// Weak vertical edge
							else if (dh - dv > 8) {
								prediction = ((0.75 * prediction) + (0.25 * north));
							}

							pgmImage -> image[row][col] = prediction_error + prediction;
						}
	    			}	 
	    		}
   			}

   			// Entered an invalid prediction rule so print an error.
			else {
				printf("Error: Entered a non-valid prediction rule\n");
				return;
			}
   		}
   	}

   	save_PGM_Image(pgmImage, file_Ptr, 1);
   	free_PGM_Image(pgmImage);
   	fclose(pgm_file); // we are done with the file so close it.
}