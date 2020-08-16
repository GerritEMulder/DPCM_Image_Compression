// Name: Gerrit Mulder

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "libpnm.h"

// The function for encoding images using DPCM encoding.
void Encode_Using_DPCM(char *in_PGM_filename_Ptr, int prediction_rule, float *avg_abs_error_Ptr, float *std_abs_error_Ptr) {
	struct PGM_Image *pgmImage = malloc(sizeof(*pgmImage));
	load_PGM_Image(pgmImage, in_PGM_filename_Ptr);
	int maxgreyvalue = pgmImage -> maxGrayValue;
	int error_array[maxgreyvalue + 1];
	int encoded_array[pgmImage -> height][pgmImage -> width];
	int row, col, prediction_error, pixel_value, abs_error, prediction, third_prediction1, third_prediction2;

	// Sets the default value of every array slot to zero.
	for (int i = 0; i < maxgreyvalue + 1; ++i) {
		error_array[i] = 0;
	}

	// The prediction rule is one, so encodes the image using the 1st prediction rule.
	if (prediction_rule == 1) {

		// Loops through the image pixel by pixel.
		for(row = 0; row < pgmImage -> height; row++) {
    		for(col = 0; col < pgmImage -> width; col++) {

	    		// This pixel is in the first row and the first column and so is predicted as 128.
	    		if ((row == 0) && (col == 0)) {

	    			pixel_value = pgmImage -> image[row][col];
	    			prediction_error = pixel_value - 128;
	    			encoded_array[row][col] = prediction_error; // Starts filling in the encoded image array.
	    			abs_error = abs(prediction_error);
	    			error_array[abs_error] = error_array[abs_error] + 1; // Adds one to the frequecy array.
	    		}

	    		// This pixel is in the first row and so is predicted as W.
	    		else if ((row == 0) && (col != 0)) {

	    			pixel_value = pgmImage -> image[row][col];
	    			prediction = pgmImage -> image[row][col - 1];
	    			prediction_error = pixel_value - prediction;
	    			encoded_array[row][col] = prediction_error;
	    			abs_error = abs(prediction_error);
	    			error_array[abs_error] = error_array[abs_error] + 1; // Adds one to the frequecy array.
	    		}

	    		// This pixel is in the first, second, or last column, or first row and so it is predicted as N. 
	    		else if ((col == 0) || (col == 1) || (col == (pgmImage -> width - 1)) || (row == 1)) {

	    			pixel_value = pgmImage -> image[row][col];
	    			prediction = pgmImage -> image[row - 1][col];
	    			prediction_error = pixel_value - prediction;
	    			encoded_array[row][col] = prediction_error;
	    			abs_error = abs(prediction_error);
	    			error_array[abs_error] = error_array[abs_error] + 1; // Adds one to the frequecy array.
	    		}

	    		// This pixel is not in any of the previous situations and because the prediction rule is 1, it is predicted as W.
	    		else {

	    			pixel_value = pgmImage -> image[row][col];
	    			prediction = pgmImage -> image[row][col - 1];
	    			prediction_error = pixel_value - prediction;
	    			encoded_array[row][col] = prediction_error;
	    			abs_error = abs(prediction_error);
	    			error_array[abs_error] = error_array[abs_error] + 1; // Adds one to the frequecy array.
	    		}
	    	}
		}
	}

	// The prediction rule is two, so encodes the image using the 2nd prediction rule.
	else if (prediction_rule == 2) {

		// Loops through the image pixel by pixel.
		for(row = 0; row < pgmImage -> height; row++) {
    		for(col = 0; col < pgmImage -> width; col++) {

	    		// This pixel is in the first row and the first column and so is predicted as 128.
	    		if ((row == 0) && (col == 0)) {

	    			pixel_value = pgmImage -> image[row][col];
	    			prediction_error = pixel_value - 128;
	    			encoded_array[row][col] = prediction_error; // Starts filling in the encoded image array.
	    			abs_error = abs(prediction_error);
	    			error_array[abs_error] = error_array[abs_error] + 1; // Adds one to the frequecy array.
	    		}

	    		// This pixel is in the first row and so is predicted as W.
	    		else if ((row == 0) && (col != 0)) {

	    			pixel_value = pgmImage -> image[row][col];
	    			prediction = pgmImage -> image[row][col - 1];
	    			prediction_error = pixel_value - prediction;
	    			encoded_array[row][col] = prediction_error;
	    			abs_error = abs(prediction_error);
	    			error_array[abs_error] = error_array[abs_error] + 1; // Adds one to the frequecy array.
	    		}

	    		// This pixel is not in any of the previous situations and because the prediction rule is 2, it is predicted as N.
	    		else {

	    			pixel_value = pgmImage -> image[row][col];
	    			prediction = pgmImage -> image[row - 1][col];
	    			prediction_error = pixel_value - prediction;
	    			encoded_array[row][col] = prediction_error;
	    			abs_error = abs(prediction_error);
	    			error_array[abs_error] = error_array[abs_error] + 1; // Adds one to the frequecy array.
	    		}
	    	}
		}

	}

	// The prediction rule is three, so encodes the image using the 3rd prediction rule.
	else if (prediction_rule == 3) {

		// Loops through the image pixel by pixel.
		for(row = 0; row < pgmImage -> height; row++) {
    		for(col = 0; col < pgmImage -> width; col++) {

	    		// This pixel is in the first row and the first column and so is predicted as 128.
	    		if ((row == 0) && (col == 0)) {

	    			pixel_value = pgmImage -> image[row][col];
	    			prediction_error = pixel_value - 128;
	    			encoded_array[row][col] = prediction_error; // Starts filling in the encoded image array.
	    			abs_error = abs(prediction_error);
	    			error_array[abs_error] = error_array[abs_error] + 1; // Adds one to the frequecy array.
	    		}

	    		// This pixel is in the first row and so is predicted as W.
	    		else if ((row == 0) && (col != 0)) {

	    			pixel_value = pgmImage -> image[row][col];
	    			prediction = pgmImage -> image[row][col - 1];
	    			prediction_error = pixel_value - prediction;
	    			encoded_array[row][col] = prediction_error;
	    			abs_error = abs(prediction_error);
	    			error_array[abs_error] = error_array[abs_error] + 1; // Adds one to the frequecy array.
	    		}

	    		// This pixel is in the first, second, or last column, or first row and so it is predicted as N. 
	    		else if ((col == 0) || (col == 1) || (col == (pgmImage -> width - 1)) || (row == 1)) {

	    			pixel_value = pgmImage -> image[row][col];
	    			prediction = pgmImage -> image[row - 1][col];
	    			prediction_error = pixel_value - prediction;
	    			encoded_array[row][col] = prediction_error;
	    			abs_error = abs(prediction_error);
	    			error_array[abs_error] = error_array[abs_error] + 1; // Adds one to the frequecy array.
	    		}

	    		// This pixel is not in any of the previous situations and because the prediction rule is 3, it is predicted as W/2 +N/2.
	    		else {

	    			pixel_value = pgmImage -> image[row][col];
	    			third_prediction1 = pgmImage -> image[row][col - 1]; // W
	    			third_prediction2 = pgmImage -> image[row - 1][col]; // N
	    			prediction = (third_prediction1 / 2) + (third_prediction2 / 2);
	    			prediction_error = pixel_value - prediction;
	    			encoded_array[row][col] = prediction_error;
	    			abs_error = abs(prediction_error);
	    			error_array[abs_error] = error_array[abs_error] + 1; // Adds one to the frequecy array.
	    		}
	    	}
		}

	}

	// The prediction rule is four, so encodes the image using the 4th prediction rule.
	else if (prediction_rule == 4) {

		int north, north_north, north_east, north_north_east, north_west, west, west_west;

		// Loops through the image pixel by pixel.
		for(row = 0; row < pgmImage -> height; row++) {
    		for(col = 0; col < pgmImage -> width; col++) {

	    		// This pixel is in the first row and the first column and so is predicted as 128.
	    		if ((row == 0) && (col == 0)) {

	    			pixel_value = pgmImage -> image[row][col];
	    			prediction_error = pixel_value - 128;
	    			encoded_array[row][col] = prediction_error; // Starts filling in the encoded image array.
	    			abs_error = abs(prediction_error);
	    			error_array[abs_error] = error_array[abs_error] + 1; // Adds one to the frequecy array.
	    		}

	    		// This pixel is in the first row and so is predicted as W.
	    		else if ((row == 0) && (col != 0)) {

	    			pixel_value = pgmImage -> image[row][col];
	    			prediction = pgmImage -> image[row][col - 1];
	    			prediction_error = pixel_value - prediction;
	    			encoded_array[row][col] = prediction_error;
	    			abs_error = abs(prediction_error);
	    			error_array[abs_error] = error_array[abs_error] + 1; // Adds one to the frequecy array.
	    		}

	    		// This pixel is in the first, second, or last column, or first row and so it is predicted as N. 
	    		else if ((col == 0) || (col == 1) || (col == (pgmImage -> width - 1)) || (row == 1)) {

	    			pixel_value = pgmImage -> image[row][col];
	    			prediction = pgmImage -> image[row - 1][col];
	    			prediction_error = pixel_value - prediction;
	    			encoded_array[row][col] = prediction_error;
	    			abs_error = abs(prediction_error);
	    			error_array[abs_error] = error_array[abs_error] + 1; // Adds one to the frequecy array.
	    		}

	    		// This pixel is not in any of the previous situations and because the prediction rule is 4, it is predicted using CALIC.
	    		else {

	    			pixel_value = pgmImage -> image[row][col];
	    			west = pgmImage -> image[row][col - 1];
	    			north = pgmImage -> image[row - 1][col]; 
	    			north_north = pgmImage -> image[row - 2][col]; 
	    			north_north_east = pgmImage -> image[row - 2][col + 1]; 
	    			north_east = pgmImage -> image[row - 1][col + 1]; 
	    			north_west = pgmImage -> image[row - 1][col - 1]; 
	    			west_west = pgmImage -> image[row][col - 2]; 

	    			// Binary mode definite
	    			if (pixel_value == west) {
	    				prediction_error = -1000;
	    				error_array[0] = error_array[0] + 1; // Adds one to the frequecy array.
	    			}

	    			// Binary mode is not definite so we need to check.
	    			else {

	    				int which_mode = 0; // the mode default is 0 which is binary mode.

	    				// The following if statements check to see if more then two values appear in the surrounding 7 pixels.
	    				if ((north != west) && (north != pixel_value)) {
	    					which_mode = 1;
	    				}
	    				if ((north_west != west) && (north_west != pixel_value)) {
	    					which_mode = 1;
	    				}
	    				if ((north_north != west) && (north_north != pixel_value)) {
	    					which_mode = 1;
	    				}
	    				if ((north_east != west) && (north_east != pixel_value)) {
	    					which_mode = 1;
	    				}
	    				if ((west_west != west) && (west_west != pixel_value)) {
	    					which_mode = 1;
	    				}

	    				// Still in binary so set the prediction error to 1000;
	    				if (which_mode == 0) {
	    					prediction_error = 1000;
	    					error_array[0] = error_array[0] + 1; // Adds one to the frequecy array.
	    				}

	    				// It is not binary mode so now we muct use Gradient-Adjusted Prediction (GAP).
	    				else {
	    					int dh, dv;
	    					dh = abs(west - west_west) + abs(north - north_west) + abs(north_east - north);
	    					dv = abs(west - north_west) + abs(north - north_north) + abs(north -north_north_east);

	    					// Sharp horizontal edge
	    					if (dv - dh > 80) {
								prediction = west;
								
							}

							// Sharp vertical edge
							else if (dh - dv > 80) {
								prediction = north;
							}

							else {
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
							}

							prediction_error = pixel_value - prediction;
							abs_error = abs(prediction_error);
	    					error_array[abs_error] = error_array[abs_error] + 1; // Adds one to the frequecy array.
	    				}
	    			}

	    			encoded_array[row][col] = prediction_error;
	    		}
	    	}
		}
	}

	// Entered an invalid prediction rule so print an error.
	else {
		printf("Error: Entered a non-valid prediction rule\n");
		return;
	}


	// Sets up the file name.
	FILE *error_hist, *main_file;
	char buf[256];
	char temp[256];
 	sprintf(buf, "%d", prediction_rule);
 	char temp_char[256];
	strcat(in_PGM_filename_Ptr, ".");
	strcat(in_PGM_filename_Ptr, buf);
	strcat(in_PGM_filename_Ptr, ".");
	char file_name[200];
	strcpy(file_name, in_PGM_filename_Ptr);
	strcat(file_name, "errors.csv");
	int count = 0;

	error_hist = fopen(file_name, "w");
	for (int i = 0; i < maxgreyvalue + 1; i++) { // Prints the error information into a csv file.
		if (error_array[i] != 0) {
			sprintf(temp_char, "%d", i);
			fputs(temp_char, error_hist);
			fputs( ",", error_hist);
			sprintf(temp_char, "%d", error_array[i]);
			fputs(temp_char, error_hist);
			fputs( "\n", error_hist);
		}
	}
	fclose(error_hist);

	// Prints the information we need for decoding into the the encoded file.
	strcpy(file_name, in_PGM_filename_Ptr);
	strcat(file_name, "DPCM");
	strcpy(temp, file_name);
	strcat(temp, ".pgm");
	main_file = fopen(file_name, "w");
	sprintf(temp_char, "%d", pgmImage -> height);
	fputs(temp_char, main_file);
	fputs("\n", main_file);
	sprintf(temp_char, "%d", pgmImage -> width);
	fputs(temp_char, main_file);
	fputs("\n", main_file);
	sprintf(temp_char, "%d", pgmImage -> maxGrayValue);
	fputs(temp_char, main_file);
	fputs("\n", main_file);
	sprintf(temp_char, "%d", prediction_rule);
	fputs(temp_char, main_file);
	fputs("\n", main_file);
	fputs(temp, main_file);
	fputs("\n", main_file);
	float error_ave = 0;
	
	// Loops through the encoded array and puts the array values into the file.
	for(row = 0; row < pgmImage -> height; row++) {
   		for(col = 0; col < pgmImage -> width; col++) {
   			sprintf(temp_char, "%d", encoded_array[row][col]);
			fputs(temp_char, main_file);
			fputs( ",", main_file);

			// Used for calculating the average of the ABSOLUTE prediction errors.
			error_ave = error_ave + abs(encoded_array[row][col]);
			count++;
    	}
    }

    fputs("\n", main_file);
    fclose(main_file);

    *avg_abs_error_Ptr = error_ave / count; // Finds the average.

    float error_var = 0;
	float error_temp, error_div;

	// For each number: subtract the Mean and square the result
	for(row = 0; row < pgmImage -> height; row++) {
   		for(col = 0; col < pgmImage -> width; col++) {

			error_temp = encoded_array[row][col] - *avg_abs_error_Ptr;
			error_var = error_var + pow(error_temp, 2);
		}
	}
	error_div = error_var / count;

	*std_abs_error_Ptr = sqrt(error_div); // The std diviations of the error.

	free_PGM_Image(pgmImage);
}
