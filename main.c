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

int main(int *argc, char **argv){
  FILE *f;
  int i;
  char message[1024];
  const char *filename, *outfilename;

  filename = argv[1];
  outfilename = argv[2];
  f = fopen(filename,"w");

  sprintf(message, "Transforming %s into %s.", filename, outfilename);
  SAY(message);


  fclose(f);



  return 0;
}
