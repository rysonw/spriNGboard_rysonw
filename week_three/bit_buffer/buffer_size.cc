#include <iostream>
#include <vector>

using namespace std;

int32_t buffer_size (int32_t W, int32_t N)
{
  /////////////////////////////
  // IMPLEMENT FUNCTION HERE //
  /////////////////////////////

}

int main ()
{
  vector<int32_t> N_bits = {
    0,   1,
    7,   8,
    16, 17,
    32, 33,
    64, 65
  };

  for (int32_t W=8; W<=32; W*=2)
  {
    for (int32_t idx=0; idx<N_bits.size(); ++idx)
    {
      int32_t const N = N_bits[idx];

      cout << "it takes " << buffer_size(W,N)
           << " " << W << "-bit words "
           << "to store " << N << " bits"
           << endl;
    }
  }
}

