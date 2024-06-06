class Solution {
 public:
  bool checkAlmostEquivalent(string word1, string word2) {
    vector<int> count(26);

    for (const char c : word1)
      ++count[c - 'a'];

    for (const char c : word2)
      --count[c - 'a'];

    return ranges::all_of(count, [](int freq) { return abs(freq) <= 3; });
  }
};
