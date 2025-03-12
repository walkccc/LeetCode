class Solution:
  def simulationResult(
      self,
      windows: list[int],
      queries: list[int],
  ) -> list[int]:
    ans = []
    seen = set()

    for query in reversed(queries):
      if query not in seen:
        ans.append(query)
        seen.add(query)

    for window in windows:
      if window not in seen:
        ans.append(window)
        seen.add(window)

    return ans
