class Solution {
 public:
  int countDivisibleSubstrings(string word) {
    // Let f(c) = d, where d = 1, 2, ..., 9.
    // Rephrase the question to return the number of substrings that satisfy
    //    f(c1) + f(c2) + ... + f(ck) / k = avg
    // => f(c1) + f(c2) + ... + f(ck) - k * avg, where avg in [1, 9].
    int ans = 0;

    for (int avg = 1; avg <= 9; ++avg) {
      int prefix = 0;
      unordered_map<int, int> prefixCount{{0, 1}};
      for (const char c : word) {
        prefix += f(c) - avg;
        ans += prefixCount[prefix]++;
      }
    }

    return ans;
  }

 private:
  int f(char c) {
    return 9 - ('z' - c) / 3;
  }
};
