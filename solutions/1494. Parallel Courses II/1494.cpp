class Solution {
 public:
  int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
    // dp[i] := min # of semesters to take all courses in mask i
    vector<int> dp(1 << n, n);
    // prereq[i] := bit representation of all dependencies of course i
    vector<int> prereq(n);

    for (const auto& r : relations) {
      const int prevCourse = r[0] - 1;
      const int nextCourse = r[1] - 1;
      prereq[nextCourse] |= 1 << prevCourse;
    }

    dp[0] = 0;  // no need time to finish 0 course

    for (int i = 0; i < dp.size(); ++i) {
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
      for (int s = coursesCanBeTaken; s; s = (s - 1) & coursesCanBeTaken)
        if (__builtin_popcount(s) <= k)
          // any combination of courses (if <= k) can be taken now
          // i | s := combining courses taken with courses can be taken
          dp[i | s] = min(dp[i | s], dp[i] + 1);
    }

    return dp.back();
  }
};
