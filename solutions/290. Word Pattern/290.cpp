class Solution {
 public:
  bool wordPattern(string pattern, string str) {
    const int n = pattern.length();
    istringstream iss(str);
    vector<int> charToIndex(128);
    unordered_map<string, int> stringToIndex;

    int i = 0;
    for (string word; iss >> word; ++i) {
      if (i == n)  // out-of-bounds
        return false;
      if (charToIndex[pattern[i]] != stringToIndex[word])
        return false;
      charToIndex[pattern[i]] = i + 1;
      stringToIndex[word] = i + 1;
    }

    return i == n;
  }
};
