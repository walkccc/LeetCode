class Solution {
 public:
  int numWays(vector<string>& words, string target) {
    const int wordLength = words[0].length();
    vector<vector<int>> mem(target.length(), vector<int>(wordLength, -1));
    // counts[j] := the count map of words[i][j], where 0 <= i < |words|
    vector<vector<int>> counts(wordLength, vector<int>(26));

    for (int i = 0; i < wordLength; ++i)
      for (const string& word : words)
        ++counts[i][word[i] - 'a'];

    return numWays(target, 0, 0, counts, mem);
  }

 private:
  static constexpr int kMod = 1'000'000'007;

  // Returns the number of ways to form target[i..n) using word[j..n).
  int numWays(const string& target, int i, int j,
              const vector<vector<int>>& counts, vector<vector<int>>& mem) {
    if (i == target.length())
      return 1;
    if (j == counts.size())
      return 0;
    if (mem[i][j] != -1)
      return mem[i][j];
    return mem[i][j] = (numWays(target, i + 1, j + 1, counts, mem) *
                            static_cast<long>(counts[j][target[i] - 'a']) +
                        numWays(target, i, j + 1, counts, mem)) %
                       kMod;
  };
};
