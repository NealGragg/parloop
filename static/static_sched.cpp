#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <chrono>
#include <cmath>

#include "seq_loop.hpp"

#ifdef __cplusplus
extern "C" {
#endif

float f1(float x, int intensity);
float f2(float x, int intensity);
float f3(float x, int intensity);
float f4(float x, int intensity);

#ifdef __cplusplus
}
#endif


int main (int argc, char* argv[]) {

  if (argc < 7) {
    std::cerr<<"usage: "<<argv[0]<<" <functionid> <a> <b> <n> <intensity> <nbthreads>"<<std::endl;
    return -1;
  }

  int functionID = atoi(argv[1]);
  float lowerBound = std::stof(argv[2]);
  float upperBound = std::stof(argv[3]);
  int numOfPoints = atoi(argv[4]);
  int intensity = atoi(argv[5]);
  int nbthreads = atoi(argv[6]);
  float finalValue = 0.0;
  SeqLoop seq_loop;

  auto start = std::chrono::steady_clock::now();

  switch(functionID) {
  case 1:
    finalValue = seq_loop.parforThreads(lowerBound, upperBound, numOfPoints, intensity, nbthreads, f1);
    break;
  case 2:
    finalValue = seq_loop.parforThreads(lowerBound, upperBound, numOfPoints, intensity, nbthreads, f2); 
    break;
  case 3:
    finalValue = seq_loop.parforThreads(lowerBound, upperBound, numOfPoints, intensity, nbthreads, f3);
    break;
  case 4:
    finalValue = seq_loop.parforThreads(lowerBound, upperBound, numOfPoints, intensity, nbthreads, f4);
    break;
  default:
    std::cerr<<"Invalid function ID."<<std::endl;
  }

auto end = std::chrono::steady_clock::now();

std::cout<<finalValue<<std::endl;

std::chrono::duration<double> seconds_elapsed = end-start;
std::cerr<<seconds_elapsed.count()<<std::endl; 

  return 0;
}
