#include <iostream>
#include <cstdlib>

/*
  Tests cache misses.
*/

void option1(long array[], long sI, long  sJ);
void option2(long array[], long  sI, long sJ);
void option3(long array[], long sI, long sJ);


int main(int argc, char *argv[]){

  long sI = std::atoi(argv[1]); 
  long sJ = std:: atoi(argv[2]);

  long *arr = new long[sI*sJ];

  option1(arr, sI, sJ);
  option2(arr, sI, sJ);  
  option3(arr, sI, sJ);
  
  
  return 0;
}

void option1(long array[], long sI, long sJ){

  for(long i = 0; i < sI; ++i)
    for (long j =0; j < sJ; ++j)
      array[(i*sJ) + j ] = i;


}


void option2(long array[], long sI, long sJ){

   for(long i = 0; i < sI; ++i)
    for (long j =0; j < sJ; ++j)
      array[(j*sI) + i ] = i;



}



void option3(long array[], long sI, long sJ){


  for(long i = 0; i<sI*sJ; ++i)

    array[i] = i;


}
