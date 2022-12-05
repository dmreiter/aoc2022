#include "aoc.hpp"

using namespace std;

int NUM_STACKS = 9;

void move_stack(vector<deque<char>>& stacks, int n, int f, int t) {
  for (int i = 0; i < n && !stacks[f].empty(); ++i) {
    stacks[t].push_back(stacks[f].back());
    stacks[f].pop_back();
  }
}

void move_stack_multiple(vector<deque<char>>& stacks, int n, int f, int t) {
  stack<char> s;
  for (int i = 0; i < n && !stacks[f].empty(); ++i) {
    s.push(stacks[f].back());
    stacks[f].pop_back();
  }

  while (!s.empty()) {
    stacks[t].push_back(s.top());
    s.pop();
  }
}

vector<deque<char>> build_stacks(vector<string>& input) {
  vector<deque<char>> stacks(NUM_STACKS);
  for (int i = 0; i < 9; ++i) {
    string s = input[i];
    for (int j = 0; j < s.size(); j += 2) {
      if (s[j] != ' ') stacks[j/2].push_front(s[j]);
    }
  }
  return stacks;
}

void print_stacks(vector<deque<char>>& stacks) {
  for (auto x : stacks) {
    cout << x.back();
  }
  cout << endl;
}

// back is top
int p1(vector<string> input) {
  vector<deque<char>> stacks = build_stacks(input);

  for (int i = 9; i < input.size(); ++i) {
    auto [_, n, f, t] = scn::scan_tuple<int, int, int>(input[i], "move {} from {} to {}");
    move_stack(stacks, n, f-1, t-1);
  }

  print_stacks(stacks);

  return 0;
}

int p2(vector<string> input) {
  vector<deque<char>> stacks = build_stacks(input);

  for (int i = 9; i < input.size(); ++i) {
    auto [_, n, f, t] = scn::scan_tuple<int, int, int>(input[i], "move {} from {} to {}");
    move_stack_multiple(stacks, n, f-1, t-1);
  }

  print_stacks(stacks);

  return 0;
}

int main() {
  vector<string> input = readinput();
  p1(input);
  p2(input);
}