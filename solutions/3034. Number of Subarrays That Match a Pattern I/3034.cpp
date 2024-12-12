class Solution {
 public:
  int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
    const vector<int> numsPattern = getNumsPattern(nums);
    return kmp(numsPattern, pattern);
  }

 private:
  int getNum(int a, int b) {
    if (a < b)
      return 1;
    if (a > b)
      return -1;
    return 0;
  }

  vector<int> getNumsPattern(const vector<int>& nums) {
    vector<int> numsPattern;
    for (int i = 1; i < nums.size(); ++i)
      numsPattern.push_back(getNum(nums[i - 1], nums[i]));
    return numsPattern;
  }

  // Returns the number of occurrences of the pattern in `nums`.
  int kmp(const vector<int>& nums, const vector<int>& pattern) {
    const vector<int> lps = getLPS(pattern);
    int res = 0;
    int i = 0;  // nums' index
    int j = 0;  // pattern's index
    while (i < nums.size()) {
      if (nums[i] == pattern[j]) {
        ++i;
        ++j;
        if (j == pattern.size()) {
          ++res;
          j = lps[j - 1];
        }
      }
      // Mismatch after j matches.
      else if (j > 0) {
        // Don't match lps[0..lps[j - 1]] since they will match anyway.
        j = lps[j - 1];
      } else {
        ++i;
      }
    }
    return res;
  }

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
