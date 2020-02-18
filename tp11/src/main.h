#ifndef __main_h_
#define __main_h_

#include <stdio.h>
#include <stdlib.h> 
#include <math.h> 
#include <string.h> 
#include <ctype.h> 
#include <limits.h> 

typedef int boolean;

struct sPixel {
  int Color[3]; 
};

struct sImagePPM {
  struct sPixel* pixels;
  int width; 
  int height; 
  int range; 
};


struct sImagePGM {
  struct sPixel* pixels; 
  int width; 
  int height; 
  int range; 
};


struct sImagePBM {
  struct sPixel* pixels; 
  int width; 
  int height; 
};


struct sImagePPM* loadImagePPM(char* data);


struct sImagePGM* loadImagePGM(char* data);


struct sImagePBM* loadImagePBM(char* data);


void PrintsPixel(struct sPixel sPixl_pixel, int int_range);

void PrintsImagePPM(struct sImagePPM* sIPPM_im);


void PrintsImagePGM(struct sImagePGM* sIPGM_im);


void PrintsImagePBM(struct sImagePBM* sIPBM_im);


void freesImagePPM(struct sImagePPM* sIPPM_im);


void freesImagePGM(struct sImagePGM* sIPGM_im);


void freesImagePBM(struct sImagePBM* sIPBM_im);


void saveImagePPM(char* str_name, struct sImagePPM* sIPPM_im);


void saveImagePGM(char* str_name, struct sImagePGM* sIPGM_im);


void saveImagePBM(char* str_name, struct sImagePBM* sIPBM_im);


struct sImagePGM* WhiteBlackFilter(struct sImagePPM* sIPPM_im);


struct sImagePBM* Thresholding(struct sImagePGM* sIPGM_im, int int_value);

#endif
