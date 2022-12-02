#include "aoc.hpp"

using namespace std;

int main() {
  vector<string> v = readinput();
  priority_queue<int> pq;
  int r = 0;

  for (auto &x : v) {
    if (x.size() == 0) {
      pq.push(r);
      r = 0;
    } else {
      r += stoi(x);
    }
  }

  int ans = 0;
  for (int i = 0; i < 3; ++i) {
    ans += pq.top(); pq.pop();
  }
  
  cout << ans << endl;
}