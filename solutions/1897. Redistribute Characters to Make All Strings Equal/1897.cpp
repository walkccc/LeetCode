class Solution {
 public:
  bool makeEqual(vector<string>& words) {
    vector<int> count(26);

    for (const string& word : words)
      for (const char c : word)
        ++count[c - 'a'];

    return all_of(begin(count), end(count),
                  [&](const int c) { return c % words.size() == 0; });
  }
};
