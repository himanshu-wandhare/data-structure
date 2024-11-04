// Fibonacci Series using recursion
#include <iostream>
using namespace std;

// int fib(int n)
// {
//   if(n <= 1)
//     return n;
//   else
//     return fib(n-2)+fib(n-1);
// }
// int main()
// {
//   cout<<fib(6);
//   return 0;
// }

//Reduced Form using recursion - takes less time using (Memoization)
int F[10];
int fib(int n)
{
  if(n<=1)
  {
    F[n]=n;
    return n;
  }
  else{

    if(F[n-2] == -1)
      F[n-2]=fib(n-2);
    
    if(F[n-1] == -1)
      F[n-1]=fib(n-1);

    F[n]=F[n-2]+F[n-1];
    return F[n];
  }
}

int main()
{
  for(int i=0;i<10;i++)
    F[i]=-1;

  cout<<fib(4);
}

//Fibonacci series using loops

int fibo(int n)
{
  int a=0,b=1,f=0;
  for(int i=2;i<=10;i++)
  {
    f=a+b;
    a=b;
    b=f;
  }
  return f;
}
