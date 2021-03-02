class UF {
 public:
  UF(int n) : size(n, 1), id(n) {
    iota(begin(id), end(id), 0);
  }

  void union_(int p, int q) {
    int i = find(p);
    int j = find(q);
    if (i == j)
      return;
    if (size[i] < size[j]) {
      id[i] = j;
      size[j] += size[i];
    } else {
      id[j] = i;
      size[i] += size[j];
    }
  }

  int find(int i) {
    while (i != id[i]) {
      id[i] = id[id[i]];
      i = id[i];
    }
    return i;
  }

 private:
  vector<int> size;
  vector<int> id;
};

struct compare {
  bool operator()(const char a, const char b) {
    return a > b;
  }
};

class Solution {
 public:
  string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
    string ans;
    UF uf(s.length());
    unordered_map<int, priority_queue<char, vector<char>, compare>> map;

    for (vector<int>& pair : pairs)
      uf.union_(pair[0], pair[1]);

    for (int i = 0; i < s.length(); ++i)
      map[uf.find(i)].push(s[i]);

    for (int i = 0; i < s.length(); ++i)
      ans += map[uf.find(i)].top(), map[uf.find(i)].pop();

    return ans;
  }
};
