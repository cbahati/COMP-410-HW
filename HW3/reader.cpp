#include "homework3.h" 
 

/* taken from cplusplus.com to load the whole file into a buffer at once */

char * reader( char * buffer, char * filename ){
  FILE * pFile;
  long lSize;
  size_t result;

  pFile = fopen ( filename , "rb" );
  if (pFile==NULL) {fputs ("File error",stderr); exit (1);}

  // obtain file size:
  fseek (pFile , 0 , SEEK_END);
  lSize = ftell (pFile);
  rewind (pFile);

  // allocate memory to contain the whole file:
  buffer = (char*) malloc (sizeof(char)*lSize);
  if (buffer == NULL) {fputs ("Memory error",stderr); exit (2);}

  // copy the file into the buffer:
  result = fread (buffer,1,lSize,pFile);
  if (result != lSize) {fputs ("Reading error",stderr); exit (3);}


  /* the whole file is now loaded in the memory buffer. */
  

  // terminate
  fclose (pFile);
  
  return buffer;
  free (buffer);

  
}
