#include "homework3.h"

void writer(char *file_name, int lower_bound, int  upper_bound){

  ofstream new_file;
  
  new_file.open(file_name);    // create destination file
  

  // copies the source file into a new file
  for( int i = lower_bound; i < upper_bound + 1; i++){
    new_file << i << " ";
    }

  new_file.close();

   
}
