//
//  main.c
//  Lenet-5
//
//  Created by Zheng Liu on 7/10/19.
//  Copyright © 2019 Zheng Liu. All rights reserved.
//

#include <stdio.h>
#include "Lenet5.h"
#include <time.h>
#include <stdlib.h>

//defining four MINIST files
#define TRAIN_IMAGE "train-images-idx3-ubyte"
#define TRAIN_LABEL "train-labels-idx1-ubyte"
#define TEST_IMAGE  "t10k-images-idx3-ubyte"
#define TEST_LABEL  "t10k-labels-idx1-ubyte"

//other definings
typedef unsigned char uint8;
typedef uint8 image[28][28];
#define COUNT_TRAIN        60000

//read data, labels. And put data into 28*28 data array.
void read_minst(const char dataFile[], const char labelFile[], unsigned char (*data)[28][28], unsigned char label[], int numOfResult)
{
    //read binary file
    FILE *fp_image = fopen(dataFile, "rb");
    FILE *fp_label = fopen(labelFile, "rb");
    
    if(!fp_image || !fp_label){
        printf("Error, File not found!");
    }
   
    //find the start of reading
    fseek(fp_image, 16, SEEK_SET);//Referring to Yann LeCun, the image data starts at 16
    fseek(fp_label, 8, SEEK_SET); //Referring to Yann LeCun, the label data starts at 8
    
    //start reading
    fread(data, sizeof(*data)*numOfResult, 1, fp_image);
    fread(label, numOfResult, 1, fp_label);
    
    //close file
    fclose(fp_image);
    fclose(fp_label);
    
}



int main(int argc, const char * argv[]) {
    /* test read_minst
    image *train_data = (image *)calloc(COUNT_TRAIN, sizeof(image));
    unsigned char *train_label = (uint8 *)calloc(COUNT_TRAIN, sizeof(uint8));
    read_minst(TRAIN_IMAGE, TRAIN_LABEL, train_data, train_label, COUNT_TRAIN);
    printf("%hhu \n", *(train_label+3));*/
    
    return 0;
}
