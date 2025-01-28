class Solution {
 public:
  char findTheDifference(string s, string t) {
    vector<int> count(26);

    for (const char c : s)
      ++count[c - 'a'];

    for (const char c : t) {
      if (count[c - 'a'] == 0)
        return c;
      --count[c - 'a'];
    }

    throw;
  }
};
