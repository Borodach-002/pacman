#pragma once
#include <iostream>
#include <time.h>
#include <ctime> 
#include <thread>
#include <mutex>
#define X 17
#define Y 19

// mutex mtx1;
// mutex mtx2;

void settings (int ARR[Y][X], int* x, int* y, int* score, int*gameOver, char key);

void settings (int ARR[Y][X], int* x, int* y, int*gameOver, int* flag_coin);
