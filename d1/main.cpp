#include <scn/scn.h>
#include <scn/tuple_return.h>
#include "aoc.hpp"

using namespace std;

int main() {
  vector<string> file = readinput();
  auto [r, a, b, c] = scn::scan_tuple<int, string, char>(file[0], "{},{:5},{}");
  cout << a << " " << b << " " << c << endl;
}