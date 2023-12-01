class Solution {
  public int catchMaximumAmountofPeople(int[] team, int dist) {
    int ans = 0;
    int i = 0; // 0s index
    int j = 0; // 1s index

    while (i < team.length && j < team.length)
      if (i + dist < j || team[i] != 0) {
        // Find the next 0 that can be caught by 1.
        ++i;
      } else if (j + dist < i || team[j] != 1) {
        // Find the next 1 that can catch 0.
        ++j;
      } else {
        // team[j] catches team[i], so move both.
        ++ans;
        ++i;
        ++j;
      }

    return ans;
  }
}
