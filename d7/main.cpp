#include "aoc.hpp"

using namespace std;

struct Dir {
  string name;
  int size = 0;
  unordered_map<string, Dir*> children;
  unordered_map<string, int> files;
  Dir* parent;
  Dir(string name) : name(name) {}
};

// add all directory sizes < 1000000 to res
int p1helper(Dir* current, int& res) {
  for (auto [_, c] : current->children) {
    current->size += p1helper(c, res);
  }

  for (auto [_, f] : current->files) {
    current->size += f;
  }

  if (current->size < 100000) {
    res += current->size;
  }

  return current->size;
}

// find smallest dir size > min_size
void p2helper(Dir* current, int min_size, int& res) {
  if (current->size >= min_size) {
    res = min(res, current->size);
  }

  for (auto [_, c] : current->children) {
    p2helper(c, min_size, res);
  }
}

int solve(vector<string> input) {
  Dir* current_dir = new Dir("/"), *root = current_dir;

  for (int i = 0; i < input.size(); ++i) {
    string s = input[i];
    
    if (s[2] == 'c') { // cd
      auto [_, name] = scn::scan_tuple<string>(s, "$ cd {}");

      if (name == "..") {
        current_dir = current_dir->parent;
      } else {
        Dir* child = new Dir(name);
        child->parent = current_dir;
        current_dir->children[name] = child;

        current_dir = child;
      }
    } else if (s[2] == 'l') { // ls
      ++i;

      while (i < input.size() && input[i][0] != '$') {
        auto [_, sz, name] = scn::scan_tuple<string, string>(input[i], "{} {}");
        if (sz != "dir") {
          current_dir->files[name] = atoi(sz.c_str());
        }
        ++i;
      }

      --i;
    }
  }

  int p1 = 0;
  p1helper(root, p1);
  cout << p1 << endl;

  int p2 = INT_MAX;
  p2helper(root, root->size - 40000000, p2);
  cout << p2 << endl;
}

int main() {
  vector<string> input = readinput();
  solve(input);
}
