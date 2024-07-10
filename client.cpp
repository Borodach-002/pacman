#include <iostream>



#include "1betinput.h"
#include "rendering.h"
#include "settings.h"
#include "erproc.h"

using namespace std;

#define X 17
#define Y 19

//mutex mtx1;



void SingleGame()
{
   int score = 0;
    int gameOver = 1;
    char key;
    int x = 8;
    int y = 10;
    int flag_coin1(1),flag_coin2(1),flag_coin3(1),flag_coin4(1);
    int Enemy1X(1),Enemy1Y(1);
    int Enemy2X(1),Enemy2Y(17);
    int Enemy3X(15),Enemy3Y(1);
    int Enemy4X(15),Enemy4Y(17);
  
    //15

    int ARR[Y][X] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                     1,4,2,2,2,2,2,2,2,2,2,2,2,2,2,4,1,
                     1,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,1,
                     1,2,1,2,1,2,1,1,1,1,1,2,1,2,1,2,1,
                     1,2,2,2,1,2,2,2,1,2,2,2,1,2,2,2,1,
                     1,1,1,2,1,1,1,2,1,2,1,1,1,2,1,1,1,
                     0,0,1,2,1,2,2,2,2,2,2,2,1,2,1,0,0,
                     1,1,1,2,1,2,1,1,1,1,1,2,1,2,1,1,1,
                     0,0,1,2,2,2,1,0,0,0,1,2,2,2,1,0,0,
                     1,1,1,2,1,2,1,1,1,1,1,2,1,2,1,1,1,
                     0,0,1,2,1,2,2,2,3,2,2,2,1,2,1,0,0,
                     1,1,1,2,1,2,1,1,1,1,1,2,1,2,1,1,1,
                     1,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,1,
                     1,2,1,2,1,1,1,2,1,2,1,1,1,2,1,2,1,
                     1,2,1,2,2,2,2,2,2,2,2,2,2,2,1,2,1,
                     1,1,1,2,1,2,1,1,1,1,1,2,1,2,1,1,1,
                     1,2,2,2,1,2,2,2,1,2,2,2,1,2,2,2,1,
                     1,4,2,2,2,2,2,2,2,2,2,2,2,2,2,4,1,
                     1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};

  
    fd_set rfds;
    struct timeval tv;
    int retval;

    tv.tv_sec = 0;
    tv.tv_usec = 100000;
	
    srand(time(0));
  
    set_keypress();
    while (1) 
  {
  // 1460

    //clrScr();
    FD_ZERO(&rfds);
    FD_SET(0, &rfds);
    //delay(10);
    Playing_field(ARR, &score);
    //delay(10);
    
    if(select(1, &rfds, NULL, NULL, &tv))
    key = getc(stdin);
    settings(ARR, &x, &y, &score, &gameOver, key);    
    thread th1([&]()                                                   // разделение на разные потоки. 
    {
      settings(ARR, &Enemy1X, &Enemy1Y , &gameOver, &flag_coin1);     
    });
    thread th2([&]()                
    {
      settings(ARR, &Enemy2X, &Enemy2Y , &gameOver, &flag_coin2);     // использование лямбда функций для передачи значений по ссылке в функции
    });
    thread th3([&]()
    {
      settings(ARR, &Enemy3X, &Enemy3Y , &gameOver, &flag_coin3);
    });
    thread th4([&]()
    {
      settings(ARR, &Enemy4X, &Enemy4Y , &gameOver, &flag_coin4);
    });
        //key = '5';                              
        
        
        usleep(500000);
    th1.join();                                 //ждем пока все потоки завершат свою работу
    th2.join();
    th3.join();
    th4.join();
        if (score == 1450) 
    {
      Playing_field(ARR, &score);
      cout << "\nYou win!" << endl;
      break;
    }
    
    if (gameOver == 0)
    {
      Playing_field(ARR, &score);
      cout << "\nYou lose!" << endl;
      break;
    }
  }

  //cout << "Работает"<<endl;
    reset_keypress();
}

void OnlineGame()
{
    //подключаемся к серверу
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in adr = {0};
    adr.sin_family = AF_INET;
    adr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &adr.sin_addr);
    connect(fd, (struct sockaddr *) &adr, sizeof adr);
    int enemy_score(0);

    int score = 0;
    int gameOver = 1;
    char key;
    int x = 8;
    int y = 10;
    int flag_coin1(1),flag_coin2(1),flag_coin3(1),flag_coin4(1);
    int Enemy1X(1),Enemy1Y(1);
    int Enemy2X(1),Enemy2Y(17);
    int Enemy3X(15),Enemy3Y(1);
    int Enemy4X(15),Enemy4Y(17);
  


    int ARR[Y][X] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                     1,4,2,2,2,2,2,2,2,2,2,2,2,2,2,4,1,
                     1,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,1,
                     1,2,1,2,1,2,1,1,1,1,1,2,1,2,1,2,1,
                     1,2,2,2,1,2,2,2,1,2,2,2,1,2,2,2,1,
                     1,1,1,2,1,1,1,2,1,2,1,1,1,2,1,1,1,
                     0,0,1,2,1,2,2,2,2,2,2,2,1,2,1,0,0,
                     1,1,1,2,1,2,1,1,1,1,1,2,1,2,1,1,1,
                     0,0,1,2,2,2,1,0,0,0,1,2,2,2,1,0,0,
                     1,1,1,2,1,2,1,1,1,1,1,2,1,2,1,1,1,
                     0,0,1,2,1,2,2,2,3,2,2,2,1,2,1,0,0,
                     1,1,1,2,1,2,1,1,1,1,1,2,1,2,1,1,1,
                     1,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,1,
                     1,2,1,2,1,1,1,2,1,2,1,1,1,2,1,2,1,
                     1,2,1,2,2,2,2,2,2,2,2,2,2,2,1,2,1,
                     1,1,1,2,1,2,1,1,1,1,1,2,1,2,1,1,1,
                     1,2,2,2,1,2,2,2,1,2,2,2,1,2,2,2,1,
                     1,4,2,2,2,2,2,2,2,2,2,2,2,2,2,4,1,
                     1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
  
    fd_set rfds;
    struct timeval tv;
    int retval;

    tv.tv_sec = 0;
    tv.tv_usec = 100000;
	
    srand(time(0));
  
    set_keypress();
    while (1) 
  {
  // 1460


    FD_ZERO(&rfds);
    FD_SET(0, &rfds);

    //write(fd, map, 1596);

    int buf1[1] = {score};
    int buf2[1];

    int ARR_BUF[Y][X];

    write(fd, buf1, 4);                   // передача счета противнику
    read(fd, buf2, 4);                    // прием счета противника
    
    write(fd, ARR, 1292);
    read(fd, ARR_BUF, 1292);


    enemy_score = buf2[0];

    Playing_field(ARR, &score);
    Playing_field_enemy(ARR_BUF, buf2);           // отображения экрана противника
    
    if(select(1, &rfds, NULL, NULL, &tv))
    key = getc(stdin);
    settings(ARR, &x, &y, &score, &gameOver, key);    
    thread th1([&]()                                                   // разделение на разные потоки. 
    {
      settings(ARR, &Enemy1X, &Enemy1Y , &gameOver, &flag_coin1);     
    });
    thread th2([&]()                
    {
      settings(ARR, &Enemy2X, &Enemy2Y , &gameOver, &flag_coin2);     // использование лямбда функций для передачи значений по ссылке в функции
    });
    thread th3([&]()
    {
      settings(ARR, &Enemy3X, &Enemy3Y , &gameOver, &flag_coin3);
    });
    thread th4([&]()
    {
      settings(ARR, &Enemy4X, &Enemy4Y , &gameOver, &flag_coin4);
    });
  
      // settings(ARR, &Enemy1X, &Enemy1Y , &gameOver, &flag_coin1);     

      // settings(ARR, &Enemy2X, &Enemy2Y , &gameOver, &flag_coin2);     // использование лямбда функций для передачи значений по ссылке в функции

      // settings(ARR, &Enemy3X, &Enemy3Y , &gameOver, &flag_coin3);

      // settings(ARR, &Enemy4X, &Enemy4Y , &gameOver, &flag_coin4);

        //key = '5';                              
        usleep(500000);
    th1.join();                                 //ждем пока все потоки завершат свою работу
    th2.join();
    th3.join();
    th4.join();
      if (score == 1450) 
    {
      Playing_field(ARR, &score);
      cout << "\nYou win!" << endl;
      Playing_field_enemy(ARR_BUF, buf2); 
      cout << "\nYour enemy lose!" << endl;
      break;
    }
    
    if (gameOver == 0)
    {
      Playing_field(ARR, &score);
      cout << "\nYou lose!" << endl;
      Playing_field_enemy(ARR_BUF, buf2); 
      cout << "\nYour enemy win!" << endl;
      break;
    }
  }

  //cout << "Работает"<<endl;
    reset_keypress();
}



int main()
{
  int mode;
  cout<< "Выберите режим игры:\n"
          "1 - одиночная игра;\n"
          "2 - игра по сети;\n"
          "3 - закрыть приложение;\n";

  cin>>mode;
  switch (mode)
  {
  case 1:
  {
    SingleGame();
    break;
  }

  case 2:
  {
    OnlineGame();
    break;
  }

  default:
    break;
  }
}

