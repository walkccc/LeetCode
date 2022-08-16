class Solution {
  public int minNumberOfSemesters(int n, int[][] relations, int k) {
    // dp[i] := min # of semesters to take all courses in mask i
    int[] dp = new int[1 << n];
    Arrays.fill(dp, n);
    // prereq[i] := bit representation of all dependencies of course i
    int[] prereq = new int[n];

    for (int[] r : relations) {
      final int prevCourse = r[0] - 1;
      final int nextCourse = r[1] - 1;
      prereq[nextCourse] |= 1 << prevCourse;
    }

    dp[0] = 0; // no need time to finish 0 course

    for (int i = 0; i < dp.length; ++i) {
      // bit representation of all the courses can be taken
      int coursesCanBeTaken = 0;
      // can take course j if i contains all j's prerequisites
      for (int j = 0; j < n; ++j)
        if (i & prereq[j] == prereq[j])
          coursesCanBeTaken |= 1 << j;
      // don't take any course which is already taken
      // (i represents set of courses that are already taken)
      coursesCanBeTaken &= ~i;
      // enumerate all bit subset of coursesCanBeTaken
      for (int s = coursesCanBeTaken; s > 0; s = (s - 1) & coursesCanBeTaken)
        if (Integer.bitCount(s) <= k)
          // any combination of courses (if <= k) can be taken now
          // i | s := combining courses taken with courses can be taken
          dp[i | s] = Math.min(dp[i | s], dp[i] + 1);
    }

    return dp[(1 << n) - 1];
  }
}
