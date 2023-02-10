#include <iostream>
#include <iomanip>

#include <chrono>

using namespace std;

int fib(int N)
{
    int prevNum = 0;
    int currNum = 1;
    int sum = 0;

    if (N == 0) {
      return 0;
    }

    if (N == 1) {
      return 0;
    }

    for (int i = 2; i <= N; i++) {
      sum = prevNum + currNum;
      prevNum = currNum;
      currNum = sum;
    }

    return currNum;
}

int main ()
{
  for (int N=0; N<45; ++N)
  {

    auto start = chrono::high_resolution_clock::now();

    int f = fib(N);

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration<double>(end-start).count();

    cout << "N=" << setw(2) << N << " "
         << "F(N)=" << setw(10) << f << " "
         << "elapsed=" << scientific << setprecision(6) << elapsed << " [sec]" << endl;
  }

  return 0;
}

