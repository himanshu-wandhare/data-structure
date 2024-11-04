//Taylor's series by Horner's rule using recursion

#include <iostream>
using namespace std;

// double e(int x, int n)
// {
//   static double s=1;
//   if(n == 0)
//     return s;
//   else
//   {
//     s=1+x*s/n;
//     return e(x,n-1);
//   }
// }

//Taylor series by Horner's rule using loops
double e(int x, int n)
{
  double s=1;
  for(;n>0;n--)
  {
    s=1+x*s/n;
  }
  return s;
}

int main()
{
  cout<<e(1,10);
  return 0;
}