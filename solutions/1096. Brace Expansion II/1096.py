class Solution:
  def braceExpansionII(self, expression: str) -> list[str]:
    def merge(groups: list[list[str]], group: list[str]) -> None:
      if not groups[-1]:
        groups[-1] = group
        return

      groups[-1] = [word1 + word2 for word1 in groups[-1]
                    for word2 in group]

    def dfs(s: int, e: int) -> list[str]:
      groups = [[]]
      layer = 0

      for i in range(s, e + 1):
        c = expression[i]
        if c == '{':
          layer += 1
          if layer == 1:
            left = i + 1
        elif c == '}':
          layer -= 1
          if layer == 0:
            group = dfs(left, i - 1)
            merge(groups, group)
        elif c == ',' and layer == 0:
          groups.append([])
        elif layer == 0:
          merge(groups, [c])

      return sorted(list({word for group in groups for word in group}))

    return dfs(0, len(expression) - 1)
