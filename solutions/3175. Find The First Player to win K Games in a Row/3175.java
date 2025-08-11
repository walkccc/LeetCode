class Solution {
  // Similar to 1535. Find the Winner of an Array Game
  public int findWinningPlayer(int[] skills, int k) {
    int ans = 0;
    int wins = 0;

    for (int i = 1; i < skills.length && wins < k; ++i)
      if (skills[i] > skills[ans]) {
        ans = i;
        wins = 1;
      } else {
        ++wins;
      }

    return ans;
  }
}
