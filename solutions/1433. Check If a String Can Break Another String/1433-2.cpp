class Solution {
 public:
  bool checkIfCanBreak(string s1, string s2) {
    vector<int> count(26);

    for (const char c : s1)
      ++count[c - 'a'];

    for (const char c : s2)
      --count[c - 'a'];

    for (int i = 1; i < 26; ++i)
      count[i] += count[i - 1];

    return ranges::all_of(count, [](int c) { return c <= 0; }) ||
           ranges::all_of(count, [](int c) { return c >= 0; });
  }
};
