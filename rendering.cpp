#include "rendering.h"

// void Playing_field(int ARR[Y][X], int* score)
// {
//   system ("clear");
//   for (int i = 0; i < Y; i++) 
//     {
//       for (int j = 0; j < X; j++)
//         { 
//             if(ARR[i][j] == 0)
//                 printf("  ");
//             if(ARR[i][j] == 1)
//                 printf("\u2B1C"); //стена
//             if(ARR[i][j] == 2)
//                 printf("()"); //пакман
//             if(ARR[i][j] == 3)
//                 printf("\u3004"); // монетка
//             if(ARR[i][j] == 4)
//                 printf("MM"); //моб
//         }
//       cout<<endl;
//     }
//   cout<<"Score: "<< *score <<endl;
// }

void Playing_field(int ARR[Y][X], int* score)
{
  system ("clear");
  for (int i = 0; i < Y; i++) 
    {
      for (int j = 0; j < X; j++)
        { 
          if (ARR[i][j] == 1)
          {
            cout << "\u2B1B"; //стена
          } else if (ARR[i][j] == 2)
          {
            cout << "\u3004"; // монета
          } else if(ARR[i][j] == 3)
          {
            cout << "()"; // пакман
          } else if(ARR[i][j] == 4)
          {
            cout << "ёё"; //
          }else cout << "  ";
        }
      cout<<endl;
    }
  cout<<"Score: "<< *score <<endl;
}

void Playing_field_enemy(int ARR[Y][X], int score[1])
{
  cout<<"\n";
  for (int i = 0; i < Y; i++) 
    {
      for (int j = 0; j < X; j++)
        { 
          if (ARR[i][j] == 1)
          {
            cout << "\u2B1B"; //стена
          } else if (ARR[i][j] == 2)
          {
            cout << "\u3004"; // монета
          } else if(ARR[i][j] == 3)
          {
            cout << "()"; // пакман
          } else if(ARR[i][j] == 4)
          {
            cout << "ёё"; //
          }else cout << "  ";
        }
      cout<<endl;
    }
  cout<<"Score_enemy: "<< score[0] <<endl;
}