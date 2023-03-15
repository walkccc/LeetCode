class Solution:
  def minSessions(self, tasks: List[int], sessionTime: int) -> int:
    # Returns True if we can assign tasks[s:] to `sessions`. Note that `sessions`
    # may be occupied by some tasks.
    def dfs(s: int, sessions: List[int]) -> bool:
      if s == len(tasks):
        return True

      for i, session in enumerate(sessions):
        # Can't assign tasks[s] to this session.
        if session + tasks[s] > sessionTime:
          continue
        # Assign tasks[s] to this session.
        sessions[i] += tasks[s]
        if dfs(s + 1, sessions):
          return True
        # Backtracking.
        sessions[i] -= tasks[s]
        # If it's the first time we assign tasks[s] to this session. Then, future
        # `session`s can't satisfy either.
        if sessions[i] == 0:
          return False

      return False

    for numSessions in range(1, len(tasks) + 1):
      if dfs(0, [0] * numSessions):
        return numSessions
