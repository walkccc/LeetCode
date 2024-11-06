class Solution:
  def minSessions(self, tasks: list[int], sessionTime: int) -> int:
    # Returns True if we can assign tasks[s..n) to `sessions`. Note that `sessions`
    # may be occupied by some tasks.
    def dfs(s: int, sessions: list[int]) -> bool:
      if s == len(tasks):
        return True

      for i, session in enumerate(sessions):
        # Can't assign the tasks[s] to this session.
        if session + tasks[s] > sessionTime:
          continue
        # Assign the tasks[s] to this session.
        sessions[i] += tasks[s]
        if dfs(s + 1, sessions):
          return True
        # Backtracking.
        sessions[i] -= tasks[s]
        # If it's the first time we assign the tasks[s] to this session, then future
        # `session`s can't satisfy either.
        if sessions[i] == 0:
          return False

      return False

    for numSessions in range(1, len(tasks) + 1):
      if dfs(0, [0] * numSessions):
        return numSessions
