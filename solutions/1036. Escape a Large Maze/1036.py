class Solution:
  def isEscapePossible(
      self,
      blocked: list[list[int]],
      source: list[int],
      target: list[int]
  ) -> bool:
    def dfs(i: int, j: int, target: list[int], seen: set) -> bool:
      if i < 0 or i >= 10**6 or j < 0 or j >= 10**6:
        return False
      if (i, j) in blocked or (i, j) in seen:
        return False
      seen.add((i, j))
      return (len(seen) > (1 + 199) * 199 // 2 or [i, j] == target or
              dfs(i + 1, j, target, seen) or
              dfs(i - 1, j, target, seen) or
              dfs(i, j + 1, target, seen) or
              dfs(i, j - 1, target, seen))

    blocked = set(tuple(b) for b in blocked)
    return (dfs(source[0], source[1], target, set()) and
            dfs(target[0], target[1], source, set()))
