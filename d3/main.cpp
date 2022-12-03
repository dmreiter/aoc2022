#include "aoc.hpp"

using namespace std;

int priority(char c) {
  if (islower(c)) return c-'a'+1;
  return c-'A'+27;
}

int main() {
  vector<string> in = readinput();

  int p = 0, sum = 0;
  while (p < in.size()) {
    unordered_set<char> first, second, seen;
    for (auto c : in[p]) {
      first.insert(c);
    }

    for (auto c : in[p+1]) {
      second.insert(c);
    }

    for (auto c : in[p+2]) {
      if (first.count(c) && second.count(c) && !seen.count(c)) {
        seen.insert(c);
        sum += priority(c);
      }
    }
    p += 3;
  }

  cout << sum << endl;
}
