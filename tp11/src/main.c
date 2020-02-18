#include "main.h"
/*!\author Lilian Naretto <narettolil@eisti.eu>
\date 21 decembre 2019
\file main.c
\brief main
\version 0.1 premier jet*/


float getNextFloatValue(FILE* File){
  float res = 0;
  float count = 0;
  boolean boolhav = 0;
  boolean boolnega = 0;
  for(;!feof(File);){
    char k = fgetc(File);
    if(!boolhav && (k >= 48 && k <= 57)){
      boolhav = 1;
    }
    if(k == 35){ 
      char ignore[1024];
      fgets(ignore, 1024, File);
    } else {
      if(k == 10 || k == 32 || k == 9){
        if(boolhav){
          return res*((boolnega)? -1 : 1)*((count != 0)? count : 1);
        }
      } else if (k >= 48 && k <= 57){
        res *= 10;
        res += k-48;
        count *= 0.1;
      } else if(k == 45){
        boolnega = 1;
      } else if(k == 46){ 
        count = 1;
      }
    }
  }
  return res*((boolnega)? -1 : 1)*((count != 0)? count : 1);
}

int getNextValue(FILE* File){
  int res = 0;
  boolean boolhav = 0;
  boolean boolnega = 0;
  for(;!feof(File);){
    char k = fgetc(File);
    if(!boolhav && (k >= 48 && k <= 57)){
      boolhav = 1;
    }
    if(k == 35){ 
      char ignore[1024];
      fgets(ignore, 1024, File);
    } else {
      if(k == 10 || k == 32 || k == 9){
        if(boolhav){
          return res*((boolnega)? -1 : 1);
        }
      } else if (k >= 48 && k <= 57){
        res *= 10;
        res += k-48;
      } else if(k == 45){
        boolnega = 1;
      }
    }
  }
  return res*((boolnega)? -1 : 1);
}

struct sImagePPM* loadImagePPM(char* data){
  FILE* file = fopen(data, "r");
  if(file != NULL){
    char* motif = malloc(3*sizeof(char));
    motif[0] = fgetc(file);
    motif[1] = fgetc(file);
    motif[2] = '\0';
    if(strcmp(motif, "P3") == 0){ 
      struct sImagePPM* sIPPM_image = malloc(1*sizeof(struct sImagePPM));
      (*sIPPM_image).width = getNextValue(file);
      (*sIPPM_image).height = getNextValue(file);
      (*sIPPM_image).range = getNextValue(file);
      (*sIPPM_image).pixels = malloc((*sIPPM_image).width*(*sIPPM_image).height*sizeof(struct sPixel));
      for(int i = 0; i < (*sIPPM_image).width*(*sIPPM_image).height; i++){
        for(int j = 0; j < 3; j++){
          (*sIPPM_image).pixels[i].Color[j] = getNextValue(file);
        }
      }
      free(motif);
      fclose(file);
      return sIPPM_image;
    } else { 
      free(motif);
      fclose(file);
      printf("format incorrecte\n");
      exit(-2);
      return NULL;
    }
  }
  printf("Image non trouvé\n");
  return NULL;
}

struct sImagePGM* loadImagePGM(char* data){
  FILE* file = fopen(data, "r");
  if(file != NULL){
    char* motif = malloc(3*sizeof(char));
    motif[0] = fgetc(file);
    motif[1] = fgetc(file);
    motif[2] = '\0';
    if(strcmp(motif, "P2") == 0){ 
      struct sImagePGM* sIPGM_image = malloc(1*sizeof(struct sImagePGM));
      (*sIPGM_image).width = getNextValue(file);
      (*sIPGM_image).height = getNextValue(file);
      (*sIPGM_image).range = getNextValue(file);
      (*sIPGM_image).pixels = malloc((*sIPGM_image).width*(*sIPGM_image).height*sizeof(struct sPixel));
      for(int i = 0; i < (*sIPGM_image).width*(*sIPGM_image).height; i++){
        (*sIPGM_image).pixels[i].Color[0] = getNextValue(file);
      }
      free(motif);
      fclose(file);
      return sIPGM_image;
    } else { 
      free(motif);
      fclose(file);
      printf("format incorrecte\n");
      exit(-2);
      return NULL;
    }
  }
  printf("Image non trouvé\n");
  return NULL;
}

struct sImagePBM* loadImagePBM(char* data){
  FILE* file = fopen(data, "r");
  if(file != NULL){
    char* motif = malloc(3*sizeof(char));
    motif[0] = fgetc(file);
    motif[1] = fgetc(file);
    motif[2] = '\0';
    if(strcmp(motif, "P1") == 0){ 
      struct sImagePBM* sIPBM_image = malloc(1*sizeof(struct sImagePBM));
      (*sIPBM_image).width = getNextValue(file);
      (*sIPBM_image).height = getNextValue(file);
      (*sIPBM_image).pixels = malloc((*sIPBM_image).width*(*sIPBM_image).height*sizeof(struct sPixel));
      for(int i = 0; i < (*sIPBM_image).width*(*sIPBM_image).height; i++){
        (*sIPBM_image).pixels[i].Color[0] = getNextValue(file);
      }
      free(motif);
      fclose(file);
      return sIPBM_image;
    } else { 
      free(motif);
      fclose(file);
      printf("format incorrecte\n");
      exit(-2);
      return NULL;
    }
  }
  printf("Image non trouvé\n");
  return NULL;
}

void PrintsPixel(struct sPixel sPixl_pixel, int int_range){
  for(int i = 0 ; i < 3; i++){
    printf("x%2x ", (int)round((sPixl_pixel.Color[i]/(float)int_range)*255));
  }
  printf("\n");
}

void PrintsImagePPM(struct sImagePPM* sIPPM_im){
  printf("sImagePPM : \n");
  printf("width : %d height : %d\n", (*sIPPM_im).width, (*sIPPM_im).height);
  for(int i = 0; i < (*sIPPM_im).width*(*sIPPM_im).height; i++){
    printf("%2d %2d : ", i%(*sIPPM_im).width, i/(*sIPPM_im).width);
    PrintsPixel((*sIPPM_im).pixels[i], (*sIPPM_im).range);
  }
  printf("\n");
}

void PrintsImagePGM(struct sImagePGM* sIPGM_im){
  printf("sImagePGM : \n");
  printf("width : %d height : %d\n", (*sIPGM_im).width, (*sIPGM_im).height);
  for(int i = 0; i < (*sIPGM_im).width*(*sIPGM_im).height; i++){
    printf("%2d %2d : ", i%(*sIPGM_im).width, i/(*sIPGM_im).width);
    printf("x%2x \n", (int)round(((*sIPGM_im).pixels[i].Color[0]/((float)(*sIPGM_im).range))*255));
  }
  printf("\n");
}

void PrintsImagePBM(struct sImagePBM* sIPBM_im){
  printf("sImagePBM : \n");
  printf("width : %d height : %d\n", (*sIPBM_im).width, (*sIPBM_im).height);
  for(int i = 0; i < (*sIPBM_im).width*(*sIPBM_im).height; i++){
    printf("%2d %2d : ", i%(*sIPBM_im).width, i/(*sIPBM_im).width);
    printf("x%2x \n", abs((*sIPBM_im).pixels[i].Color[0]-1)*255);
  }
  printf("\n");
}

void freesImagePPM(struct sImagePPM* sIPPM_im){
  free((*sIPPM_im).pixels);
  free(sIPPM_im);
}

void freesImagePGM(struct sImagePGM* sIPGM_im){
  free((*sIPGM_im).pixels);
  free(sIPGM_im);
}

void freesImagePBM(struct sImagePBM* sIPBM_im){
  free((*sIPBM_im).pixels);
  free(sIPBM_im);
}

void saveImagePPM(char* str_name, struct sImagePPM* sIPPM_im){
  FILE* file = fopen(str_name, "w");
  if(file != NULL){
    fprintf(file, "P3\n");
    fprintf(file, "%d %d\n", (*sIPPM_im).width, (*sIPPM_im).height);
    fprintf(file, "%d\n", (*sIPPM_im).range); 
    int length;
    int count = (*sIPPM_im).range;
    for(length = 0; count != 0; length++){
      count /= 10;
    }
    for(int i = 0; i < (*sIPPM_im).width*(*sIPPM_im).height; i++){
      for(int j = 0; j < 3; j++){
        fprintf(file, "%*d ", length, (*sIPPM_im).pixels[i].Color[j]);
      }
      if(i%(*sIPPM_im).width == (*sIPPM_im).width-1){
        fprintf(file, "\n");
      } else {
        fprintf(file, "   ");
      }
    }
    fclose(file);
    return;
  }
  printf("Cannot open File");
}

void saveImagePGM(char* str_name, struct sImagePGM* sIPGM_im){
  FILE* file = fopen(str_name, "w");
  if(file != NULL){
    fprintf(file, "P2\n");
    fprintf(file, "%d %d\n", (*sIPGM_im).width, (*sIPGM_im).height);
    fprintf(file, "%d\n", (*sIPGM_im).range);
    int length;
    int count = (*sIPGM_im).range;
    for(length = 0; count != 0; length++){
      count /= 10;
    }
    for(int i = 0; i < (*sIPGM_im).width*(*sIPGM_im).height; i++){
      fprintf(file, "%*d ", length, (*sIPGM_im).pixels[i].Color[0]);
      if(i%(*sIPGM_im).width == (*sIPGM_im).width-1){
        fprintf(file, "\n");
      }
    }
    fclose(file);
    return;
  }
  printf("Cannot open File");
}

void saveImagePBM(char* str_name, struct sImagePBM* sIPBM_im){
  FILE* file = fopen(str_name, "w");
  if(file != NULL){
    fprintf(file, "P1\n");
    fprintf(file, "%d %d\n", (*sIPBM_im).width, (*sIPBM_im).height);
    for(int i = 0; i < (*sIPBM_im).width*(*sIPBM_im).height; i++){
      fprintf(file, "%d ", (*sIPBM_im).pixels[i].Color[0]);
      if(i%(*sIPBM_im).width == (*sIPBM_im).width-1){
        fprintf(file, "\n");
      }
    }
    fclose(file);
    return;
  }
  printf("Cannot open File");
}

int max(int int_a, int int_b){
  return (int_a > int_b)? int_a : int_b;
}

int min(int int_a, int int_b){
  return (int_a < int_b)? int_a : int_b;
}

struct sImagePGM* WhiteBlackFilter(struct sImagePPM* sIPPM_im){
  struct sImagePGM* res = malloc(1*sizeof(struct sImagePGM));
  (*res).width = (*sIPPM_im).width;
  (*res).height = (*sIPPM_im).height;
  (*res).range = (*sIPPM_im).range;
  (*res).pixels = malloc((*res).width*(*res).height*sizeof(struct sPixel));
  for(int i = 0; i < (*res).width*(*res).height; i++){
    (*res).pixels[i].Color[0] = min((int)round((*sIPPM_im).pixels[i].Color[0]*0.299+(*sIPPM_im).pixels[i].Color[1]*0.587+(*sIPPM_im).pixels[i].Color[2]*0.144), (*res).range);
  }
  return res;
}

struct sImagePBM* Thresholding(struct sImagePGM* sIPGM_im, int int_value){
  struct sImagePBM* res = malloc(1*sizeof(struct sImagePBM));
  (*res).width = (*sIPGM_im).width;
  (*res).height = (*sIPGM_im).height;
  (*res).pixels = malloc((*res).width*(*res).height*sizeof(struct sPixel));
  for(int i = 0; i < (*res).width*(*res).height; i++){
    (*res).pixels[i].Color[0] = ((*sIPGM_im).pixels[i].Color[0] > int_value)? 0 : 1;
  }
  return res;
}

char* add(char* a, char* b){
  char* res = malloc((strlen(a)+strlen(b)+1)*sizeof(char));
  for(int i = 0; i < strlen(a); i++){
    res[i] = a[i];
  }
  for(int i = 0; i < strlen(b); i++){
    res[i+strlen(a)] = b[i];
  }
  res[strlen(a)+strlen(b)] = '\0';
  return res;
}

void taskPPM(char* chr_in, char* chr_out, boolean bool_gris, int int_thres){
  struct sImagePPM* sIPPM_image = loadImagePPM(chr_in);
  if(sIPPM_image == NULL){
    return;
  }
  if(bool_gris || int_thres != -1){
    struct sImagePGM* sIPGM_imageGrey = WhiteBlackFilter(sIPPM_image);
    char* chr_outPgm = add(chr_out, ".pgm");
    saveImagePGM(chr_outPgm, sIPGM_imageGrey);
    free(chr_outPgm);
    if(int_thres >= 0){
      struct sImagePBM* sIPBM_imageBlack = Thresholding(sIPGM_imageGrey, int_thres);
      char* chr_outPbm = add(chr_out, ".pbm");
      saveImagePBM(chr_outPbm, sIPBM_imageBlack);
      free(chr_outPbm);
      freesImagePBM(sIPBM_imageBlack);
    }
    freesImagePGM(sIPGM_imageGrey);
  }
  freesImagePPM(sIPPM_image);
}

void taskPGM(char* chr_in, char* chr_out, int int_thres){
  struct sImagePGM* sIPGM_image = loadImagePGM(chr_in);
  if(sIPGM_image == NULL){
    return;
  }
  if(int_thres >= 0){
    struct sImagePBM* sIPBM_imageBlack = Thresholding(sIPGM_image, int_thres);
    char* chr_outPbm = add(chr_out, ".pbm");
    saveImagePBM(chr_outPbm, sIPBM_imageBlack);
    free(chr_outPbm);
    freesImagePBM(sIPBM_imageBlack);
  }
  freesImagePGM(sIPGM_image);
}

char* getExtension(char* fileName){
  int length = strlen(fileName);
  char* output;
  for(int i = length-1; i >= 0; i--){
    if(fileName[i] == 46){
      output = malloc((length-i)*sizeof(char));
      int j;
      for(j = i+1; j < length; j++){
        output[j-(i+1)] = fileName[j];
      }
      output[j-(i+1)] = '\0';
      return output;
    }
  }
  return NULL;
}

/*! \fn int main(int argc, char** argv)
\param argc nombre d'arguments en entrée
\param argv valeur des arguments en entrée
\brief lance les fonctions*/

int main(int argc, char** argv){
  boolean bool_gris = 0;
  char* chr_in = NULL;
  char* chr_out = NULL;
  int int_thres = -1;
  int int_listen = -1;
  for(int i = 1; i < argc; i++){
    if(int_listen != -1){
      if(int_listen == 2){
        int_thres = strtol(argv[i], NULL, 10);
      } else if(int_listen == 1){
        chr_out = argv[i];
      } else if(int_listen == 0){
        chr_in = argv[i];
      }
      int_listen = -1;
    } else if(strcmp(argv[i], "-in") == 0){
      int_listen = 0;
    } else if(strcmp(argv[i], "-out") == 0){
      int_listen = 1;
    } else if(strcmp(argv[i], "-gris") == 0){
      bool_gris = 1;
    } else if(strcmp(argv[i], "-seuil") == 0){
      int_listen = 2;
    }
  }
  if(chr_in != NULL && chr_out != NULL){
    char* chr_extension = getExtension(chr_in);
    if(strcmp(chr_extension, "ppm") == 0){
      taskPPM(chr_in, chr_out, bool_gris, int_thres);
    } else if(strcmp(chr_extension, "pgm") == 0){
      taskPGM(chr_in, chr_out, int_thres);
    } else {
      printf("nom de fichier -in incorrecte\n");
    }
    free(chr_extension);
  } else {
    if(chr_in == NULL){
      printf("utilisé la commande -in\n");
    }
    if(chr_out == NULL){
      printf("utilisé la commande -out\n");
    }
  }
  return 0;
}
