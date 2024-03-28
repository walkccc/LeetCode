class Solution {
 public:
  long long wonderfulSubstrings(string word) {
    long long ans = 0;
    int prefix = 0;           // the binary prefix
    vector<int> count(1024);  // the binary prefix count
    count[0] = 1;             // the empty string ""

    for (const char c : word) {
      prefix ^= 1 << c - 'a';
      // All the letters occur even number of times.
      ans += count[prefix];
      // ('a' + i) occurs odd number of times.
      for (int i = 0; i < 10; ++i)
        ans += count[prefix ^ 1 << i];
      ++count[prefix];
    }

    return ans;
  }
};
