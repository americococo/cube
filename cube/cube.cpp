#include "cube.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>
  int cubeManager::Init()
  {
    
    cube=
    {
      {
        {'a','a','a'},
        {'a','a','a'},
        {'a','a','a'}
      },
      {
        {'b','b','b'},
        {'b','b','b'},
        {'b','b','b'}
      },
      {
        {'c','c','c'},
        {'c','c','c'},
        {'c','c','c'}
      },
      {
        {'d','d','d'},
        {'d','d','d'},
        {'d','d','d'}
      },
      {
        {'e','e','e'},
        {'e','e','e'},
        {'e','e','e'}
      },
      {
        {'f','f','f'},
        {'f','f','f'},
        {'f','f','f'}
      }

    };

    return 1;
  }

   int cubeManager:: printcube(int i)
   {
    // std::cout<< std::endl<< i << "번 면을 출력" <<std::endl;

     for(int y=0;y<3;y++)
     {
       for(int x=0;x<3;x++)
       {
         std::cout << cube[i][y][x];
       }
       std::cout << std::endl;
     }
     std::cout << std::endl;
     return 1;
   }

  int cubeManager::printDetail()
  {
    
    std::cout << std::endl;
    std::cout<<"윗면";
    std::cout<<std::endl;
    printcube(5);
   
    std::cout<<"앞면   옆면"<<std::endl;

    for(int y=0;y<3;y++)
    {
      for(int d=0;d<2;d++)
      {
        for(int x=0;x<3;x++)
        {
         std::cout<<cube[d][y][x];
        }
        std::cout<<"   ";
      }
      std::cout<<std::endl;
    }
    std::cout<<std::endl;



    std::cout<<"전개도 버전"<<std::endl;
    printcube(5);

    std::cout<< std::endl;

    for(int y=0;y<3;y++)
    {
      for(int d=0;d<4;d++)
      {
        for(int x=0;x<3;x++)
        {
          std::cout<< cube[d][y][x];
        }
          std::cout<<"   ";
      }
          std::cout<<std::endl;
    }
    std::cout<< std::endl;

    printcube(4);

     return 1;
  }
  int cubeManager::vectorswap(int first,int second,int third,int fourth,int changefi,int changese,int sepy,int sepx)
  {
    char temp = 't';

    temp = cube[first][changefi][changese];
    cube[first][changefi][changese] = cube[second][changefi][changese];
    cube[second][changefi][changese] = cube[third][sepy][sepx];
    cube[third][sepy][sepx] = cube[fourth][changefi][changese];
    cube[fourth][changefi][changese] = temp;
    return 1;
  }

int cubeManager::vectorswapFB(int first,int second,int third,int fourth, int fiY,int fiX,int seY,int seX,int thiY,int thiX, int fourY,int fourX)
  {
    char temp = 't';
    temp = cube[first][fiY][fiX];
    cube[first][fiY][fiX] = cube[second][seY][seX];
    cube[second][seY][seX] = cube[third][thiY][thiX];
    cube[third][thiY][thiX] = cube[fourth][fourY][fourX];
    cube[fourth][fourY][fourX] = temp;

    return 1;
  }
  int cubeManager:: R_one()
  {
    vectorswap(0, 5,2, 4, 0, 2, 2, 0);
    vectorswap(0, 5,2, 4, 1, 2, 1, 0);
    vectorswap(0, 5,2, 4, 2, 2, 0, 0);
    
    return 1;
  }
  int cubeManager:: L_one()
  {
    vectorswap(0, 4, 2, 5, 0, 0,2,2);
    vectorswap(0, 4, 2, 5, 1, 0,1,2);
    vectorswap(0, 4, 2, 5, 2, 0,0,2);

    return 1;
  }
  int cubeManager:: U_one()
  {
    vectorswap(0, 1, 2, 3, 0, 0,0,0);
    vectorswap(0, 1, 2, 3, 0, 1,0,1);
    vectorswap(0, 1, 2, 3, 0, 2,0,2);

    return 1;
  }
  int cubeManager:: D_one()
  {
    vectorswap(3, 2, 1, 0, 2, 0,2,0);
    vectorswap(3, 2, 1, 0, 2, 1,2,1);
    vectorswap(3, 2, 1, 0, 2, 2,2,2);

    return 1;
  }
  int cubeManager:: F_one()
  {
    vectorswapFB(5, 1, 4, 3, 2, 0, 0, 0, 0, 2, 2, 2);
    vectorswapFB(5, 1, 4, 3, 2, 1, 1, 0, 0, 1, 1, 2);
    vectorswapFB(5, 1, 4, 3, 2, 2, 2, 0, 0, 0, 0, 2);
    
    return 1;
  }
  int cubeManager:: B_one()
  {
    vectorswapFB(3, 4, 1, 5, 0, 0, 2, 0, 2, 2, 0, 2);
    vectorswapFB(3, 4, 1, 5, 1, 0, 2, 1, 1, 2, 0, 1);
    vectorswapFB(3, 4, 1, 5, 2, 0, 2, 2, 0, 2, 0, 0);
    return 1;
  }


void cubeManager::just_one(char value)
{

  switch(value)
  {
        case 'r' :
        R_one();
        break;
        case 'R' :
         R_one(); R_one(); R_one();
        break;
        case 'l':
         L_one();
        break;
        case 'L':
         L_one(); L_one(); L_one();
        break;
        case 'u':
         U_one();
        break;
        case 'U':
         U_one(); U_one(); U_one();
        break;
        case 'd':
         D_one();
        break;
        case 'D':
         D_one(); D_one(); D_one();
        break;
        case 'f':
         F_one();
        break;
        case 'F':
         F_one(); F_one(); F_one();
        break;
        case 'b':
         B_one();
        break;
        case 'B':
         B_one(); B_one(); B_one();
        break;
        case '=':
          random();

        default:
        break;
  }

}

void cubeManager::random()
{
  srand(time(NULL));
  int ran = 0;
  ran = rand()%20+1;

  std::vector<char> mixinfo;
  mixinfo.clear();

  for(int i=0;i<ran;i++)
  {
    int type = rand()%12+1000;




    switch(type)
    {
      case eMixType::eR: 
      R_one();
      mixinfo.push_back('r');
      break;
      case eMixType::eL: 
      L_one();
      mixinfo.push_back('l');
      break;
      case eMixType::eF: 
      mixinfo.push_back('f');
      F_one();
      break;
      case eMixType::eB: 
      B_one();
      mixinfo.push_back('b');
      break;
      case eMixType::eU: 
      U_one();
      mixinfo.push_back('u');
      break;
      case eMixType::eD: 
      mixinfo.push_back('d');
      D_one();
      break;
      case eMixType::eRr: 
      R_one();R_one();R_one();
      mixinfo.push_back('R');
      break;
      case eMixType::eLl: 
      L_one();L_one();L_one();
      mixinfo.push_back('L');
      break;
      case eMixType::eFf: 
      F_one();F_one();F_one();
      mixinfo.push_back('F');
      break;
      case eMixType::eBb: 
      B_one();B_one();B_one();
      mixinfo.push_back('B');
      break;
      case eMixType::eUu: 
      U_one();U_one();U_one();
      mixinfo.push_back('U');
      break;
      case eMixType::eDd: 
      D_one();D_one();D_one();
      mixinfo.push_back('D');
      break;
    }

  }

  std::cout<<ran<<"번 섞음";
    std::cout<<std::endl;
    for(int i=0;i<mixinfo.size();i++)
    {
      std::cout<<mixinfo[i]<<" ";
    }
}