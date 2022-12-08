#include "aoc.hpp"

using namespace std;

int score(vector<vector<int>>& v, int i, int j) {
  int a = i+1, b = i-1, c = j+1, d = j-1;
  while (a < v.size()-1 && v[a][j] < v[i][j]) ++a;
  while (b > 0 && v[b][j] < v[i][j]) --b;
  while (c < v[0].size()-1 && v[i][c] < v[i][j]) ++c;
  while (d > 0 && v[i][d] < v[i][j]) --d;

  return (a-i) * (i-b) * (c-j) * (j-d);
}

int p1(vector<string> input) {
  vector<vector<int>> v;
  set<pair<int, int>> seen;
  for (auto s : input) {
    v.push_back({});
    for (auto c : s) {
      v.back().push_back(c - '0');
    }
  }

  // mark seen trees left & right
  for (int i = 1; i < v.size()-1; ++i) {
    vector<int> maxes = {v[i][0], v[i].back()};
    for (int j = 1; j < v[0].size()-1; ++j) {
      if (v[i][j] > maxes[0]) {
        seen.insert({ i, j });
      }
      if (v[i][v[0].size()-j-1] > maxes[1]) {
        seen.insert({ i, v[0].size()-j-1 });
      }

      maxes = { max(maxes[0], v[i][j]), max(maxes[1], v[i][v[0].size()-j-1]) };
    }
  }

  // mark seen trees up & down
  for (int j = 1; j < v[0].size()-1; ++j) {
    vector<int> maxes = {v[0][j], v[v.size()-1][j]};
    for (int i = 1; i < v.size()-1; ++i) {
      if (v[i][j] > maxes[0]) {
        seen.insert({ i, j });
      }
      if (v[v.size()-i-1][j] > maxes[1]) {
        seen.insert({ v.size()-i-1, j });
      }

      maxes = { max(maxes[0], v[i][j]), max(maxes[1], v[v.size()-i-1][j]) };
    }
  }

  return seen.size() + 2*v.size() + 2*v[0].size() - 4;
}

int p2(vector<string> input) {
  vector<vector<int>> v;
  for (auto s : input) {
    v.push_back({});
    for (auto c : s) {
      v.back().push_back(c - '0');
    }
  }

  int res = 0;
  for (int i = 1; i < v.size()-1; ++i) {
    for (int j = 1; j < v[0].size()-1; ++j) {
      res = max(res, score(v, i, j));
    }
  }

  return res;
}

int main() {
  vector<string> input = readinput();
  cout << p1(input) << endl;
  cout << p2(input) << endl;
}
