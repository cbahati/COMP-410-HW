#include "homework3.h"

void usage();

int main(int agvc, char * argv[ ]){

  time_t start_time, end_time;
  unsigned int lower_bound, upper_bound;

  if( agvc != 3){
    usage();
    return 0;
  }

  lower_bound = 1000000;
  upper_bound = 5000000;

  if (strcmp(argv[1],"--createDataFile") == 0){
    writer(argv[2], lower_bound, upper_bound);
  }
  else if(strcmp(argv[1], "--processDataFile") == 0){
    start_time = clock();
    start_computational_threads(argv[2], lower_bound, upper_bound);
    end_time = clock();

    double time_elapsed = end_time - start_time;
    float time_elapsed_milli = time_elapsed / (CLOCKS_PER_SEC);
    cout << "Program Took " << time_elapsed_milli << " Seconds To Run\n";;
    
  }
  else{
    usage();
  }
  return 0;
}

void usage( ){
  cout << "Usage:\n";
  cout << "./Homework3 --createDataFile numbers.txt\n";
  cout << "./Homework3 --processDataFile numbers.txt\n";

}
