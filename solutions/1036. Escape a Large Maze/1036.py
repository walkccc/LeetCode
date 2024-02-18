class Solution:
  def isEscapePossible(self, blocked: List[List[int]], source: List[int], target: List[int]) -> bool:
    def dfs(i: int, j: int, target: List[int], visited: set) -> bool:
      if not 0 <= i < 10**6 or not 0 <= j < 10**6 or (i, j) in blocked or (i, j) in visited:
        return False

      visited.add((i, j))
      if len(visited) > (1 + 199) * 199 // 2 or [i, j] == target:
        return True
      return dfs(i + 1, j, target, visited) or \
          dfs(i - 1, j, target, visited) or \
          dfs(i, j + 1, target, visited) or \
          dfs(i, j - 1, target, visited)

    blocked = set(tuple(b) for b in blocked)
    return dfs(source[0], source[1], target, set()) and dfs(target[0], target[1], source, set())
