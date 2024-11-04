//Combination Fromula (nCr)

#include <iostream>
using namespace std;

//Without recursion
// nCr = n!/r!(n-r)!

// int nCr(int n, int r)
// {
//   int t1,t2,t3;
//   t1=fact(n);
//   t2=fact(r);
//   t3=fact(n-r);
//   return t1/(t2*t3);
// }


//With Recursion using Pascal's triangle
int nCr(int n, int r)
{
  if(r==0 || r==n)
    return 1;
  return nCr(n-1,r-1)+nCr(n-1,r);
}

int main()
{
  cout<<nCr(5,3);
  return 0;
}
