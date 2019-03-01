#ifndef _MYLIB_H_
#define _MYLIB_H_
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include "./ffmpeg-4.1/libavcodec/avcodec.h"
  #define INBUF_SIZE 4096
#endif
/*
* The goal of this project is to learn how to use the library
* libavcodec to decode a video, which will then be processed.
* A video sample should be provided.
* I assume that it looks like:
* input the video stream -> perform decoding -> exit (and save?)
*/

int SAY(char *phrase){
  printf("\n:::::::::: ");
  printf(phrase);
  printf(" ::::::::::\n");
  return 0;
}


static void SAVE_TO_FILE(char *filename, unsigned char *buf, int xsize,
                                                  int ysize, int wrap){
  FILE *f;
  int i;
  f = fopen(filename, "w");// Opening the file
  fprintf(f, "P5\n%d %d\n%d\n", xsize, ysize, 255);
  for (i = 0; i < ysize; i++)
    fwrite(buf + i * wrap, 1, xsize, f);
  fclose(f);
}

static void READ_THE_FILE(FILE *f){
  while (!feof(f)){
    f = f + 1;
  }
}


int main(int *argc, char **argv){
  FILE *f;

  char message[1024];
  const char *filename, *outfilename;

  filename = argv[1];
  outfilename = argv[2];
  sprintf(message, "Transforming %s into %s.", filename, outfilename);
  SAY(message);



  char *buf;
  buf = "This is a message to write in the file";
  int xsize = 10;
  int ysize = 20;
  int wrap = 2;
  SAVE_TO_FILE(outfilename, buf, xsize, ysize, wrap);




  return 0;
}
