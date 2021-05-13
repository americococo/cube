#include <vector>

enum eMixType
{
  eR=1000,
  eL,
  eF,
  eB,
  eU,
  eD,
  eRr,
  eLl,
  eFf,
  eBb,
  eUu,
  eDd,
};

class cubeManager
{
public:
  int Init();
  int R_one();
  int L_one();
  int U_one();
  int D_one();
  int F_one();
  int B_one();

  std::vector<std::vector<std::vector<char>>> cube;

  int printcube(int i);
  void just_one(char value);

  int printDetail();

private:
  int vectorswap(int first,int second,int third,int fourth,int changefi,int changese,int sepy,int sepx);
  
  int vectorswapFB(int first,int second,int third,int fourth, int fiY,int fiX,int seY,int seX,int thiY,int thiX, int fourY,int fourX);

  void random();

};



