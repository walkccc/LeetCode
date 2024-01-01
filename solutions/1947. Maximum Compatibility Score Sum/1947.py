class Solution:
  def maxCompatibilitySum(self, students: List[List[int]], mentors: List[List[int]]) -> int:
    ans = 0

    def dfs(i: int, scoreSum: int, used: List[bool]) -> None:
      nonlocal ans
      if i == len(students):
        ans = max(ans, scoreSum)
        return

      for j, mentor in enumerate(mentors):
        if used[j]:
          continue
        used[j] = True  # The `mentors[j]` is used.
        dfs(i + 1, scoreSum + sum(s == m
                                  for s, m in zip(students[i], mentor)), used)
        used[j] = False

    dfs(0, 0, [False] * len(students))
    return ans
