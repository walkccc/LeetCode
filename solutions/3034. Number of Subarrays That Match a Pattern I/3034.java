class Solution {
  public int countMatchingSubarrays(int[] nums, int[] pattern) {
    int[] numsPattern = getNumsPattern(nums);
    return kmp(numsPattern, pattern);
  }

  private int getNum(int a, int b) {
    if (a < b)
      return 1;
    if (a > b)
      return -1;
    return 0;
  }

  private int[] getNumsPattern(int[] nums) {
    int[] numsPattern = new int[nums.length - 1];
    for (int i = 1; i < nums.length; ++i)
      numsPattern[i - 1] = getNum(nums[i - 1], nums[i]);
    return numsPattern;
  }

  // Returns the number of occurrences of the pattern in `nums`.
  private int kmp(int[] nums, int[] pattern) {
    int[] lps = getLPS(pattern);
    int res = 0;
    int i = 0; // nums' index
    int j = 0; // pattern's index
    while (i < nums.length) {
      if (nums[i] == pattern[j]) {
        ++i;
        ++j;
        if (j == pattern.length) {
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

  // Returns the lps array, where lps[i] is the longest proper prefix of
  // pattern[0..i] which is also a suffix of this substring.
  private int[] getLPS(int[] pattern) {
    int[] lps = new int[pattern.length];
    for (int i = 1, j = 0; i < pattern.length; ++i) {
      while (j > 0 && pattern[j] != pattern[i])
        j = lps[j - 1];
      if (pattern[i] == pattern[j])
        lps[i] = ++j;
    }
    return lps;
  }
}
