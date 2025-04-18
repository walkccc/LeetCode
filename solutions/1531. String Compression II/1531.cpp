class Solution {
 public:
  int getLengthOfOptimalCompression(string s, int k) {
    vector<vector<int>> mem(s.length(), vector<int>(k + 1, kMax));
    return compression(s, 0, k, mem);
  }

 private:
  static constexpr int kMax = 101;

  // Returns the length of the optimal compression of s[i..n) with at most k
  // deletion.
  int compression(const string& s, int i, int k, vector<vector<int>>& mem) {
    if (k < 0)
      return kMax;
    if (i == s.length() || s.length() - i <= k)
      return 0;
    if (mem[i][k] != kMax)
      return mem[i][k];

    int maxFreq = 0;  // the maximum frequency in s[i..j]
    vector<int> count(128);

    // Make letters in s[i..j] be the same.
    // Keep the letter that has the maximum frequency in this range and remove
    // the other letters.
    for (int j = i; j < s.length(); ++j) {
      maxFreq = max(maxFreq, ++count[s[j]]);
      mem[i][k] = min(  //
          mem[i][k],    //
          getLength(maxFreq) +
              compression(s, j + 1, k - (j - i + 1 - maxFreq), mem));
    }

    return mem[i][k];
  }

  // Returns the length to compress `maxFreq`.
  int getLength(int maxFreq) {
    if (maxFreq == 1)
      return 1;  // c
    if (maxFreq < 10)
      return 2;  // [1-9]c
    if (maxFreq < 100)
      return 3;  // [1-9][0-9]c
    return 4;    // [1-9][0-9][0-9]c
  }
};
