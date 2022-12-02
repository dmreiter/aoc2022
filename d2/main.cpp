#include "aoc.hpp"
#include <boost/algorithm/string.hpp>

using namespace std;

bool win(char a, char b) {
  if (a == 'X') {
    if (b == 'B') return false;
    if (b == 'C') return true;
  } else if (a == 'Y') {
    if (b == 'A') return true;
    if (b == 'C') return false;
  } else if (a == 'Z') {
    if (b == 'A') return false;
    if (b == 'B') return true;
  }
}

char play(char o, char res) {
  if (res == 'Y') return (o - 'A') + 'X';

  if (o == 'A') {
    if (res == 'X') return 'Z';
    if (res == 'Z') return 'Y';
  } else if (o == 'B') {
    if (res == 'X') return 'X';
    if (res == 'Z') return 'Z';
  } else if (o == 'C') {
    if (res == 'X') return 'Y';
    if (res == 'Z') return 'X';
  }
}

int main() {
  vector<string> in = readinput();
  int score = 0;

  for (auto turn : in) {
    vector<string> s;
    boost::split(s, turn, boost::is_any_of(" "));

    char my = play(s[0][0], s[1][0]);
    score += (my - 'X' + 1);

    if (s[1][0] == 'Y') score += 3;
    else if (s[1][0] == 'Z') score += 6;
  }

  cout << score << endl;
}