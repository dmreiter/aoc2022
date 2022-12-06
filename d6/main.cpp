#include "aoc.hpp"

using namespace std;

int solve(vector<string>& input, int n) {
  string &s = input[0];
  unordered_map<char, int> freq;
  for (int i = 0; i < s.size(); ++i) {
    ++freq[s[i]];
    if (i > n-1) {
      if (!--freq[s[i-n]]) freq.erase(s[i-n]);
    }
    if (freq.size() == n) return i+1;
  }
  return 0;
}

int p1(vector<string> input) {
  return solve(input, 4);
}

int p2(vector<string> input) {
  return solve(input, 14);;
}

int main() {
  vector<string> input = readinput();
  cout << p1(input) << endl;
  cout << p2(input) << endl;
}
