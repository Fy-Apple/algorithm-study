#include <iostream>
#include <vector>
using namespace std;


int sum(int a, int b) {return a+b;}

int main() {
  int(*s)(int, int) = sum;

  cout << s(1, 2);

  typedef int(*b)(int, int);
  b ss = sum;
  cout << ss(1, 2);


  typedef  int c(int, int);
  c *bb = sum;
  cout << bb(1, 2);


  return 0;
}