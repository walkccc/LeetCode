class Solution {
 public:
  vector<int> findNumOfValidWords(vector<string>& words,
                                  vector<string>& puzzles) {
    vector<int> ans;
    unordered_map<int, int> binaryCount;

    for (const string& word : words) {
      int mask = 0;
      for (char c : word)
        mask |= 1 << c - 'a';
      ++binaryCount[mask];
    }

    for (const string& puzzle : puzzles) {
      int valid = 0;
      const int n = puzzle.length() - 1;
      for (int i = 0; i < (1 << n); ++i) {
        int mask = 1 << puzzle[0] - 'a';
        for (int j = 0; j < n; ++j)
          if (i >> j & 1)
            mask |= 1 << puzzle[j + 1] - 'a';
        if (const auto it = binaryCount.find(mask); it != binaryCount.cend())
          valid += it->second;
      }
      ans.push_back(valid);
    }

    return ans;
  }
};
