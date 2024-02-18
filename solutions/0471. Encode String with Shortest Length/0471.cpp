class Solution {
 public:
  string encode(string s) {
    const int n = s.length();
    vector<vector<string>> mem(n, vector<string>(n));
    return encode(s, 0, n - 1);
  }

 private:
  // Returns the shortest encoded string of s[i..j].
  string encode(const string& s, int i, int j, vector<vector<string>>& mem) {
    if (!mem[i][j].empty())
      return mem[i][j];

    const string& curr = s.substr(i, j - i + 1);
    mem[i][j] = curr;

    if (mem[i][j].length() < 5)
      return mem[i][j];

    // Try all the possible partitions.
    for (int k = i; k < j; ++k) {
      const string& l = encode(s, i, k, mem);
      const string& r = encode(s, k + 1, j, mem);
      if (l.length() + r.length() < mem[i][j].length())
        mem[i][j] = l + r;
    }

    // Try to compress the string.
    // e.g. s = aabaabaab -> 3[aab]
    for (int k = i; k <= j; ++k) {
      const string& pattern = s.substr(i, k - i + 1);
      if (curr.length() % pattern.length() == 0 &&
          regex_replace(curr, regex(pattern), "").empty()) {
        const string& candidate = to_string(curr.length() / pattern.length()) +
                                  '[' + encode(s, i, k, mem) + ']';
        if (candidate.length() < mem[i][j].length())
          mem[i][j] = candidate;
      }
    }

    return mem[i][j];
  }
};
