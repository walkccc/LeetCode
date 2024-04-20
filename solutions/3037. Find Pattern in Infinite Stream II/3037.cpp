/**
 * Definition for an infinite stream.
 * class InfiniteStream {
 *  public:
 *   InfiniteStream(vector<int> bits);
 *   int next();
 * };
 */

class Solution {
 public:
  // Same as 3023. Find Pattern in Infinite Stream I
  int findPattern(InfiniteStream* stream, vector<int>& pattern) {
    const vector<int> lps = getLPS(pattern);
    int i = 0;    // stream's index
    int j = 0;    // pattern's index
    int bit = 0;  // the bit in the stream
    bool readNext = false;
    while (true) {
      if (!readNext) {
        bit = stream->next();
        readNext = true;
      }
      if (bit == pattern[j]) {
        ++i, readNext = false;
        ++j;
        if (j == pattern.size())
          return i - j;
      }
      // Mismatch after j matches.
      else if (j > 0) {
        // Don't match lps[0..lps[j - 1]] since they will match anyway.
        j = lps[j - 1];
      } else {
        ++i, readNext = false;
      }
    }
    throw;
  }

 private:
  // Returns the lps array, where lps[i] is the length of the longest prefix of
  // pattern[0..i] which is also a suffix of this substring.
  vector<int> getLPS(const vector<int>& pattern) {
    vector<int> lps(pattern.size());
    for (int i = 1, j = 0; i < pattern.size(); ++i) {
      while (j > 0 && pattern[j] != pattern[i])
        j = lps[j - 1];
      if (pattern[i] == pattern[j])
        lps[i] = ++j;
    }
    return lps;
  }
};
