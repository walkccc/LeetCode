class Solution {
 public:
  bool isItPossible(string word1, string word2) {
    const vector<int> count1 = getCount(word1);
    const vector<int> count2 = getCount(word2);
    const int distinct1 = getDistinct(count1);
    const int distinct2 = getDistinct(count2);

    for (int i = 0; i < 26; ++i)
      for (int j = 0; j < 26; ++j) {
        if (count1[i] == 0 || count2[j] == 0)
          continue;
        if (i == j) {
          // Swapping the same letters won't change the number of distinct
          // letters in each string, so just check if `distinct1 == distinct2`.
          if (distinct1 == distinct2)
            return true;
          continue;
        }
        // The calculation is meaningful only when i != j.
        // Swap ('a' + i) in word1 with ('a' + j) in word2.
        const int distinctAfterSwap1 =
            distinct1 - (count1[i] == 1) + (count1[j] == 0);
        const int distinctAfterSwap2 =
            distinct2 - (count2[j] == 1) + (count2[i] == 0);
        if (distinctAfterSwap1 == distinctAfterSwap2)
          return true;
      }

    return false;
  }

 private:
  vector<int> getCount(const string& s) {
    vector<int> count(26);
    for (const char c : s)
      ++count[c - 'a'];
    return count;
  }

  int getDistinct(const vector<int>& count) {
    return ranges::count_if(count, [](const int c) { return c > 0; });
  }
};
