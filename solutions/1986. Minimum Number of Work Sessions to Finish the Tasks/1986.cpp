class Solution {
 public:
  int minSessions(vector<int>& tasks, int sessionTime) {
    for (int numSessions = 1; numSessions <= tasks.size(); ++numSessions)
      if (dfs(tasks, 0, vector<int>(numSessions), sessionTime))
        return numSessions;
    throw;
  }

  // Returns true if we can assign tasks[s:] to `sessions`. Note that `sessions`
  // may be occupied by some tasks.
  bool dfs(const vector<int>& tasks, int s, vector<int>&& sessions,
           const int& sessionTime) {
    if (s == tasks.size())
      return true;

    for (int& session : sessions) {
      // Can't assign tasks[s] to this session.
      if (session + tasks[s] > sessionTime)
        continue;
      // Assign tasks[s] to this session.
      session += tasks[s];
      if (dfs(tasks, s + 1, move(sessions), sessionTime))
        return true;
      // Backtracking.
      session -= tasks[s];
      // If it's the first time we assign tasks[s] to this session. Then, future
      // `session`s can't satisfy either.
      if (session == 0)
        return false;
    }

    return false;
  }
};
