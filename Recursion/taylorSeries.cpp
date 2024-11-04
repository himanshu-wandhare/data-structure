// Taylor Series
// e^x = 1+ x/1 + x^2/2! + x^3/3! + ... + n terms

#include <iostream>
using namespace std;

// Tyalor Series using recursion
// double e(int x, int n)
// {
//   static double p = 1, f = 1;
//   double r;
//   if(n == 0)
//     return 1;
//   else
//   {
//     r = e(x,n-1);
//     p = p*x;
//     f = f*n;
//     return r+p/f;
//   }
// }

// Taylor's series using loop
double e(int x, int n)
{
  double s = 1, num = 1, den = 1;
  int i;

  for(i=1;i<=n;i++)
  {
    num*=x;
    den*=i;
    s+=num/den;
  }
  return s;
}

int main()
{
  cout<<e(1,10);
  return 0;
}