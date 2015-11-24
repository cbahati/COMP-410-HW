#include "homework3.h"

std::mutex m;

void shared_print( int prime){
  m.lock();
  cout << prime << endl;
  m.unlock();
}

void add_prime( int count, deque<int> * result ){
  m.lock();
  result->push_front(count);
  m.unlock();
}   
bool is_prime( int check_num ){

  int last_div;

  if (check_num % 2 == 0 && check_num != 2)
    return false;
  else{
    last_div = sqrt( check_num );
    for( int curr_division = 3; curr_division < last_div + 1; curr_division += 2){
      if( check_num % curr_division == 0 ){
	return false;
      }
    }
    return true;
  }  
}    


void calculate( deque<int> numbers, deque<int> * result){

  int check;
  int num = 0;
  for( deque<int>::iterator it = numbers.begin(); it != numbers.end(); it++){
    check = *it;

    if( is_prime(check) == true){                                                                                                          
      num++;
    }
  }
  //shared_print(num);
  add_prime(num, result);                                                                                                             
}

void start_computational_threads( char * filename, int lower_bound, int upper_bound){

  deque<int> num_list;
  deque<int> * result;
  int final_count = 0;
  int size, threads;
  char * buffer;
  char * tok;
  int count = 0;  


  size = (upper_bound - lower_bound);
  buffer = reader(buffer, filename);
  threads = std::thread::hardware_concurrency() * 2;
  size = size / threads;

  result = new deque<int>;
  deque<int> batch[threads];
  
  vector<thread> thread_list(threads);

  tok = strtok (buffer," ");
  for( int thread_count = 0; thread_count < threads; thread_count++){
    while( tok != NULL && count != size ){
      batch[thread_count].push_front(atoi(tok));
      tok = strtok( NULL, " ");
      count++;
    }
    thread_list.at(thread_count) = std::thread(calculate, batch[thread_count], result);
  count = 0;
  }


  for( vector<thread>::iterator it = thread_list.begin(); it != thread_list.end(); it++){
    it->join();
  }

  for( deque<int>::iterator it = result->begin(); it != result->end(); it++){
    final_count += *it;
  }
  printf("%d Primes Were Found Between %d and %d\n", final_count, lower_bound, upper_bound);

  delete result;
}




