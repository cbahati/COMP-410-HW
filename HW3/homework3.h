#include <iostream>
#include <thread>
#include <mutex>
#include <deque>
#include <cmath>
#include <vector>
#include <ctime>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>


using namespace std;

void add_prime(int, deque<int> *);
bool is_prime( int);
char * parse( char * );
void shared_print(int);
void calculate( deque<int>, deque<int> *);
char * reader(char *, char *);
void writer( char *, int, int);
void start_computational_threads( char *, int, int );
