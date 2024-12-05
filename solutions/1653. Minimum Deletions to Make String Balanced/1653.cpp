class Solution {
 public:
  // Same as 926. Flip String to Monotone Increasing
  int minimumDeletions(string s) {
    // the number of characters to be deleted to make the substring so far
    // balanced
    int dp = 0;
    int countB = 0;

    for (const char c : s)
      if (c == 'a')
        // 1. Delete 'a'.
        // 2. Keep 'a' and delete the previous 'b's.
        dp = min(dp + 1, countB);
      else
        ++countB;

    return dp;
  }
};
