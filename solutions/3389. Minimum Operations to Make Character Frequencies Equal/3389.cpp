class Solution {
 public:
  int makeStringGood(string s) {
    int ans = s.length();
    vector<int> count(26);

    for (const char c : s)
      ++count[c - 'a'];

    const int mx = ranges::max(count);
    for (int target = 1; target <= mx; ++target)
      ans = min(ans, getMinOperations(count, target));

    return ans;
  }

 private:
  int getMinOperations(const vector<int>& count, int target) {
    // dp[i] := the minimum number of operations to make the frequency of
    // (i..25)-th (0-indexed) letters equal to `target`.
    vector<int> dp(27);

    for (int i = 25; i >= 0; --i) {
      // 1. Delete all the i-th letters.
      const int deleteAllToZero = count[i];
      // 2. Insert/delete the i-th letters to have `target` number of letters.
      const int deleteOrInsertToTarget = abs(target - count[i]);
      dp[i] = min(deleteAllToZero, deleteOrInsertToTarget) + dp[i + 1];
      if (i + 1 < 26 && count[i + 1] < target) {
        const int nextDeficit = target - count[i + 1];
        // Make the frequency of the i-th letter equal to the `target` or 0.
        const int needToChange =
            count[i] > target ? count[i] - target : count[i];
        const int changeToTarget =
            nextDeficit > needToChange
                // 3. Change all the i-th letters to the next letter and then
                // insert the remaining deficit for the next letter.
                ? needToChange + (nextDeficit - needToChange)
                // 4. Change `nextDeficit` i-th letters to the next letter and
                // then delete the remaining i-th letters.
                : nextDeficit + (needToChange - nextDeficit);
        dp[i] = min(dp[i], changeToTarget + dp[i + 2]);
      }
    }

    return dp[0];
  }
};
