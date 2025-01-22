class Solution:
  def minNumberOfSemesters(
      self,
      n: int,
      relations: list[list[int]],
      k: int,
  ) -> int:
    # dp[i] := the minimum number of semesters to take the courses, where i is
    # the bitmask of the taken courses
    dp = [n] * (1 << n)
    # prereq[i] := bitmask of all dependencies of course i
    prereq = [0] * n

    for prevCourse, nextCourse in relations:
      prereq[nextCourse - 1] |= 1 << prevCourse - 1

    dp[0] = 0  # Don't need time to finish 0 course.

    for i in range(1 << n):
      # the bitmask of all the courses can be taken
      coursesCanBeTaken = 0
      # Can take the j-th course if i contains all of j's prerequisites.
      for j in range(n):
        if (i & prereq[j]) == prereq[j]:
          coursesCanBeTaken |= 1 << j
      # Don't take any course which is already taken.
      # (i represents set of courses that are already taken)
      coursesCanBeTaken &= ~i
      # Enumerate every bitmask subset of `coursesCanBeTaken`.
      s = coursesCanBeTaken
      while s:
        if s.bit_count() <= k:
          # Any combination of courses (if <= k) can be taken now.
          # i | s := combining courses taken with courses can be taken.
          dp[i | s] = min(dp[i | s], dp[i] + 1)
        s = (s - 1) & coursesCanBeTaken

    return dp[-1]
