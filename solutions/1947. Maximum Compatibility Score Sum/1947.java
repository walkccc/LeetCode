class Solution {
  public int maxCompatibilitySum(int[][] students, int[][] mentors) {
    dfs(students, mentors, 0, /*score=*/0, new boolean[students.length]);
    return ans;
  }

  private int ans = 0;

  private void dfs(int[][] students, int[][] mentors, int i, int scoreSum, boolean[] used) {
    if (i == students.length) {
      ans = Math.max(ans, scoreSum);
      return;
    }
    for (int j = 0; j < students.length; ++j) {
      if (used[j])
        continue;
      used[j] = true; // The `mentors[j]` is used.
      dfs(students, mentors, i + 1, scoreSum + getScore(students[i], mentors[j]), used);
      used[j] = false;
    }
  }

  private int getScore(int[] student, int[] mentor) {
    int score = 0;
    for (int i = 0; i < student.length; ++i)
      if (student[i] == mentor[i])
        ++score;
    return score;
  }
}
