class Solution {
 public:
  // Same as 926. Flip String to Monotone Increasing
  int minimumDeletions(string s) {
    int dp = 0;  // # of chars to be deleted to make substring so far balanced
    int countB = 0;

    for (const char c : s)
      if (c == 'a')
        // 1. Delete 'a'.
        // 2. Keep 'a' and delete previous 'b's.
        dp = min(dp + 1, countB);
      else
        ++countB;

    return dp;
  }
};
