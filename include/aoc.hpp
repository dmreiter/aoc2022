#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

std::vector<std::string> readinput() {
  std::vector<std::string> res;
  std::string s;

  while (getline(std::cin, s)) {
    res.push_back(s);
  }

  return res;
}
