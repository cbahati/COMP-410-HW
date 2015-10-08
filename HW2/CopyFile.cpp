#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <ctime>

using namespace std;

int main (int agvc, char * argv [ ] ){
  
  time_t start_time, end_time;
  int buffer_size;
  char *buffer;
  ofstream new_file;
  ifstream source_file;
  int file_size;
  int bytes_per_seconds;
  buffer_size = atoi(argv[1]);
  
  buffer = new char[buffer_size]; 

  source_file.open(argv[2]); // open source file
  new_file.open(argv[3]);    // create destination file
  
  start_time = clock(); // start the timer

  // copies the source file into a new file
  while (!source_file.eof()){
    source_file.read(buffer, buffer_size);
    new_file.write(buffer, strlen(buffer));
    }

  end_time = clock(); // stops the timer

  // checks how much time elapsed
  double time_elapsed = end_time - start_time;
  float time_elapsed_milli = time_elapsed / (CLOCKS_PER_SEC);

  // closes the files
  source_file.close();
  new_file.close();

  // checks how many bytes were copied into the new file  
  source_file.open(argv[3], ios::binary);
  source_file.seekg(0, ios ::end);
  file_size = source_file.tellg();
  source_file.close();

  bytes_per_seconds = file_size / time_elapsed_milli;

  printf("Copied %d bytes in %.4f seconds at the rate of %d bytes per second\n", file_size, time_elapsed_milli, bytes_per_seconds);
  

  delete[] buffer;

  return 0; 
}
