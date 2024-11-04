#include <iostream>
using namespace std;

// int power(int m,int n)
// {
//   if(n==0)
//     return 1;
//   else
//     return power(m,n-1)*m;
// }


// Reduced Form
// It takes less time and space than the above program
int power(int m,int n)
{
  if(n == 0)
    return 1;
  else if(n%2 == 0)
    return power(m*m,n/2);
  else
    return m*power(m*m,(n-1)/2);
}

int main()
{
  cout<<power(2,3);
  return 0;
}

