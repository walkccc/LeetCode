class Solution {
 public:
  int minimizeConcatenatedLength(vector<string>& words) {
    vector<vector<vector<int>>> mem(words.size(),
                                    vector<vector<int>>(26, vector<int>(26)));
    return words[0].length() + minimizeConcatenatedLength(words, 1,
                                                          words[0].front(),
                                                          words[0].back(), mem);
  }

 private:
  // Returns the minimum concatenated length of the first i words starting with
  // `first` and ending in `last`.
  int minimizeConcatenatedLength(const vector<string>& words, int i, char first,
                                 char last, vector<vector<vector<int>>>& mem) {
    if (i == words.size())
      return 0;
    const int j = first - 'a';
    const int k = last - 'a';
    if (mem[i][j][k] > 0)
      return mem[i][j][k];
    const char nextFirst = words[i].front();
    const char nextLast = words[i].back();
    return mem[i][j][k] =  //
           words[i].length() +
           min(
               // join(words[i - 1], words[i])
               minimizeConcatenatedLength(words, i + 1, first, nextLast, mem) -
                   (last == nextFirst ? 1 : 0),
               // join(words[i], words[i - 1])
               minimizeConcatenatedLength(words, i + 1, nextFirst, last, mem) -
                   (first == nextLast ? 1 : 0));
  }
};
