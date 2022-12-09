#include "aoc.hpp"

using namespace std;

typedef pair<int, int> position;

position& operator+=(position& a, position& b) {
  a.first += b.first;
  a.second += b.second;
  return a;
}

unordered_map<char, position> dP = {{'U', {1, 0}}, {'D', {-1, 0}}, {'L', {0, -1}}, {'R', {0, 1}}};

// ..H.. dY = 2, dX = 2
// ..... T += 1 = dY-1, dX-1
// T....

// ..T.. dY = -2, dX = -2
// ..... T -= 1 = dY+1, dX+1
// H....



void fix_tail(position& head, position &tail) {
  int dY = head.first - tail.first, dX = head.second - tail.second;

  if (abs(dY) > 1 && abs(dX) > 1) {
    // pull diagonally
    tail.first += dY > 0 ? 1 : -1;
    tail.second += dX > 0 ? 1 : -1;
  } else if (abs(dY) > 1) {
    tail.first = head.first + (dY > 0 ? -1 : 1);
    tail.second = head.second;
  } else if (abs(dX) > 1) {
    tail.second = head.second + (dX > 0 ? -1 : 1);
    tail.first = head.first;
  }
}

void step(char dir, position &head, position &tail) {
  head += dP[dir];
  fix_tail(head, tail);
}

void step2(char dir, vector<position>& v) {
  v[0] += dP[dir];
  for (int i = 1; i < 10; ++i) {
    fix_tail(v[i-1], v[i]);
  }
}

int p1(vector<string> input) {
  position head = {0,0}, tail = {0,0};
  set<position> seen;

  for (auto s : input) {
    auto [_, dir, n] = scn::scan_tuple<char, int>(s, "{} {}");
    for (int i = 0; i < n; ++i) {
      step(s[0], head, tail);
      seen.insert(tail);
    }
  }

  return seen.size();
}

int p2(vector<string> input) {
  vector<position> v(10);
  set<position> seen;

  for (int i = 0; i < 10; ++i) v[i] = {0, 0};

  for (auto s : input) {
    auto [_, dir, n] = scn::scan_tuple<char, int>(s, "{} {}");
    for (int i = 0; i < n; ++i) {
      step2(s[0], v);
      seen.insert(v[9]);
    }
  }

  return seen.size();
}

int main() {
  vector<string> input = readinput();
  cout << p1(input) << endl;
  cout << p2(input) << endl;
}
