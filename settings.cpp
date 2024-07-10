#include "settings.h"




void settings (int ARR[Y][X], int* x, int* y, int* score, int*gameOver, char key) 
{
  switch (key)
  {
    case 'w':
    {
      if(ARR[*y-1][*x] == 0)
      {
        ARR[*y-1][*x] = 3;
        ARR[*y][*x] = 0;
        *y = *y - 1;
      }else if(ARR[*y-1][*x] == 2)
      {
        ARR[*y-1][*x] = 3;
        ARR[*y][*x] = 0;
        *y = *y - 1;
        *score += 10;
      }else if(ARR[*y-1][*x] == 4)
      {
        *gameOver = 0;
      }
      break;
    }
    case 'a':
    {
      if (ARR[*y][*x - 1] == 0)
      {
        ARR[*y][*x - 1] = 3;
        ARR[*y][*x] = 0;
        *x = *x - 1;
      }else if (ARR[*y][*x - 1] == 2)
      {
        ARR[*y][*x - 1] = 3;
        ARR[*y][*x] = 0;
        *x = *x - 1;
        *score += 10;
      }else if (ARR[*y][*x - 1] == 4)
      {
        *gameOver = 0;
      }
      break;
    }
    case 's':
    {
      if(ARR[*y+1][*x] == 0)
      {
        ARR[*y+1][*x] = 3;
        ARR[*y][*x] = 0;
        *y = *y + 1;
      } else if(ARR[*y+1][*x] == 2)
      {
        ARR[*y+1][*x] = 3;
        ARR[*y][*x] = 0;
        *y = *y + 1;
        *score += 10;
      } else if(ARR[*y+1][*x] == 4)
      {
        *gameOver = 0;
      }
      break;
    }
    case 'd':
    {
      if (ARR[*y][*x + 1] == 0)
      {
        ARR[*y][*x + 1] = 3;
        ARR[*y][*x] = 0;
        *x = *x + 1;
      } else if (ARR[*y][*x + 1] == 2)
      {
        ARR[*y][*x + 1] = 3;
        ARR[*y][*x] = 0;
        *x = *x + 1;
        *score += 10;
      } else if (ARR[*y][*x + 1] == 4)
      {
        *gameOver = 0;
      }
      break;
    }
    case 'q':
    {
      *gameOver = 0;
    }
  }
}

void settings (int ARR[Y][X], int* x, int* y, int*gameOver, int* flag_coin)
{
  int dir;
    dir = rand() % 4;
    //dir = 0;
    //lock_guard<mutex> guard(mtx2);        //работа с защищиенностью потоков 
    if (dir == 0) { 
        if (ARR[*y - 1][*x] == 0) {
            if (*flag_coin) {
                ARR[*y - 1][*x] = 4;
                ARR[*y][*x] = 2;
                *flag_coin = 0;
            }
            else {
                ARR[*y - 1][*x] = 4;
                ARR[*y][*x] = 0;
            }
            *y = *y - 1;
        }
        else if (ARR[*y - 1][*x] == 2) {
            if(*flag_coin) {
                ARR[*y - 1][*x] = 4;
                ARR[*y][*x] = 2;
                *flag_coin = 0;
            }
            else {
                ARR[*y - 1][*x] = 4;
                ARR[*y][*x] = 0;
            }
            *y = *y - 1;
            *flag_coin = 1;
        }
        else if (ARR[*y - 1][*x] == 3) {
            if (flag_coin) {
                ARR[*y - 1][*x] = 4;
                ARR[*y][*x] = 2;
                *flag_coin = 0;
            }
            else {
                ARR[*y - 1][*x] = 4;
                ARR[*y][*x] = 0;
            }
            *y = *y - 1;
            *gameOver = 0;
        }
    }
    else if (dir == 1) { 
        if (ARR[*y][*x - 1] == 0) {
            if (*flag_coin) {
                ARR[*y][*x - 1] = 4;
                ARR[*y][*x] = 2;
                *flag_coin = 0;
            }
            else {
                ARR[*y][*x - 1] = 4;
                ARR[*y][*x] = 0;
            }
            *x = *x - 1;
        }
        else if (ARR[*y][*x - 1] == 2) {
            if (*flag_coin) {
                ARR[*y][*x - 1] = 4;
                ARR[*y][*x] = 2;
                *flag_coin = 0;
            }
            else {
                ARR[*y][*x - 1] = 4;
                ARR[*y][*x] = 0;
            }
            *x = *x - 1;
            *flag_coin = 1;
        }
        else if (ARR[*y][*x - 1] == 3) {
            if (*flag_coin) {
                ARR[*y][*x - 1] = 4;
                ARR[*y][*x] = 2;
                *flag_coin = 0;
            }
            else {
                ARR[*y][*x - 1] = 4;
                ARR[*y][*x] = 0;
            }
            *x = *x - 1;
            *gameOver = 0;
        }
    }
    else if (dir == 2) { 
        if (ARR[*y + 1][*x] == 0) {
            if (*flag_coin) {
                ARR[*y + 1][*x] = 4;
                ARR[*y][*x] = 2;
                *flag_coin = 0;
            } else {
                ARR[*y + 1][*x] = 4;
                ARR[*y][*x] = 0;
            }
            *y = *y + 1;
        }
        else if (ARR[*y + 1][*x] == 2) {
            if(*flag_coin) {
                ARR[*y + 1][*x] = 4;
                ARR[*y][*x] = 2;
                *flag_coin = 0;
            }
            else {
                ARR[*y + 1][*x] = 4;
                ARR[*y][*x] = 0;
            }
            *y = *y + 1;
            *flag_coin = 1;
        }
        else if (ARR[*y + 1][*x] == 3) {
            if (flag_coin) {
                ARR[*y + 1][*x] = 4;
                ARR[*y][*x] = 2;
                *flag_coin = 0;
            }
            else {
                ARR[*y + 1][*x] = 4;
                ARR[*y][*x] = 0;
            }
            *y = *y + 1;
            *gameOver = 0;
        }
    }
    else { 
        if (ARR[*y][*x + 1] == 0) {
            if (*flag_coin) {
                ARR[*y][*x + 1] = 4;
                ARR[*y][*x] = 22;
                *flag_coin = 0;
            }
            else {
                ARR[*y][*x + 1] = 4;
                ARR[*y][*x] = 0;
            }
            *x = *x + 1;
        }
        else if (ARR[*y][*x + 1] == 2) {
            if (*flag_coin) {
                ARR[*y][*x + 1] = 4;
                ARR[*y][*x] = 2;
                *flag_coin = 0;
            }
            else {
                ARR[*y][*x + 1] = 4;
                ARR[*y][*x] = 0;
            }
            *x = *x + 1;
            *flag_coin = 1;
        }
        else if (ARR[*y][*x + 1] == 3) {
            if (*flag_coin) {
                ARR[*y][*x + 1] = 4;
                ARR[*y][*x] = 2;
                *flag_coin = 0;
            }
            else {
                ARR[*y][*x + 1] = 4;
                ARR[*y][*x] = 0;
            }
            *x = *x + 1;
            *gameOver = 0;
        }
    }
}