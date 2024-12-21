class Solution {
  public int minSessions(int[] tasks, int sessionTime) {
    for (int numSessions = 1; numSessions <= tasks.length; ++numSessions)
      if (dfs(tasks, 0, new int[numSessions], sessionTime))
        return numSessions;
    throw new IllegalArgumentException();
  }

  // Returns true if we can assign tasks[s..n) to `sessions`. Note that `sessions`
  // may be occupied by some tasks.
  private boolean dfs(int[] tasks, int s, int[] sessions, int sessionTime) {
    if (s == tasks.length)
      return true;

    for (int i = 0; i < sessions.length; ++i) {
      // Can't assign the tasks[s] to this session.
      if (sessions[i] + tasks[s] > sessionTime)
        continue;
      // Assign the tasks[s] to this session.
      sessions[i] += tasks[s];
      if (dfs(tasks, s + 1, sessions, sessionTime))
        return true;
      // Backtracking.
      sessions[i] -= tasks[s];
      // If it's the first time we assign the tasks[s] to this session, then future
      // `session`s can't satisfy either.
      if (sessions[i] == 0)
        return false;
    }

    return false;
  }
}
