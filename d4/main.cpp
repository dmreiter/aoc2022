#include "aoc.hpp"

using namespace std;

int p1(vector<string> input) {
  int res = 0;
  for (auto &s : input) {
    auto [r, l1, h1, l2, h2] = scn::scan_tuple<int, int, int, int>(s, "{}-{},{}-{}");
    if ((l1 <= l2 && h1 >= h2) || (l2 <= l1 && h2 >= h1)) {
      ++res;
    }
  }
  
  return res;
}

int p2(vector<string> input) {
  int res = 0;
  for (auto &s : input) {
    auto [r, l1, h1, l2, h2] = scn::scan_tuple<int, int, int, int>(s, "{}-{},{}-{}");
    if ((min(l1, l2) == l1 && h1 >= l2) || (min(l1, l2) == l2 && h2 >= l1)) {
      ++res;
    }
  }
  
  return res;
}

int main() {
  vector<string> input = readinput();
  cout << p1(input) << endl;
  cout << p2(input) << endl;
}