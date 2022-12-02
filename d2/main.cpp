#include "aoc.hpp"
#include <boost/algorithm/string.hpp>

using namespace std;

// calculate result given two players
int res(int a, int b) {
  if (a == b) return 1; // draw
  return a == ((b + 1) % 3) ? 0 : 2;
}

// calculate what we should play given one player and outcome
char play(int a, int b) {
  if (b == 1) return 'X' + a;
  else if (b == 0) return 'X' + ((a - 1) < 0 ? 2 : a - 1);
  else return 'X' + (a + 1) % 3;
}

int main() {
  vector<string> in = readinput();
  int q1 = 0, q2 = 0;
  vector<string> buf;

  for (auto turn : in) {  
    boost::split(buf, turn, boost::is_space());
    int p1 = buf[0][0]-'A', p2 = buf[1][0]-'X';

    q1 += (p2 + 1) + res(p1, p2)*3;
    q2 += (play(p1, p2) - 'X' + 1) + p2*3;
  }

  cout << q1 << " " << q2 << endl;
}