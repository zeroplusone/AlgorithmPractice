#include<iostream>
#include<string.h>
using namespace std;
#define max 30

class HugeInt 
{
  friend ostream &operator<<(ostream&,const HugeInt&);
  friend istream &operator>>(istream&,HugeInt&);

 public:
  HugeInt(const string);  
  HugeInt(long long int = 0);
  ~HugeInt(); 

  HugeInt operator+(HugeInt);
  HugeInt operator-(HugeInt);
  HugeInt operator*(HugeInt);
  HugeInt operator/(HugeInt);
  const HugeInt &operator=(const HugeInt &);
  bool operator==(const HugeInt&)const;
  bool operator!=(const HugeInt&)const;
  bool operator>=(const HugeInt&)const;
  bool operator<=(const HugeInt&)const;

  private:
    int len;
    int n[max];
};
