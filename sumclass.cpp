#include <iostream>
#include <stdio.h>

using namespace std;

class adding{
  private:
    int a, b, sum;
  public:
    adding (int, int);
    int nextint();
    int addanother(int, int);
    void sumprint(int);

};

adding::adding(int x, int y){
  a=x;
  b=y;
}


int adding::nextint(){
  cout << "Enter the next integer to add" << endl;
  cin >> a;
  return a;
}

int adding::addanother(int x, int y){
sum = x+y;
return sum;
}

void adding::sumprint(int sum){
  cout << "The sum is: " << endl;
  cout << sum << endl;
}
int main(){
  int i = 0;
  int n, a=0;
  int b=0;
  cout << "Enter the number of integers to add" << endl;
  cin >> n;
  adding testinstance(b, a);
  while (i < n) {

    a = testinstance.nextint();
    b = testinstance.addanother(b, a);

    i+=1;
  }
  testinstance.sumprint(b);
return 1;
}
