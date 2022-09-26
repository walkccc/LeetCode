class Solution:
  def generateAbbreviations(self, word: str) -> List[str]:
    ans = []

    def getCountString(count: int) -> str:
      return str(count) if count > 0 else ''

    def dfs(i: int, count: int, path: List[str]) -> None:
      if i == len(word):
        ans.append(''.join(path) + getCountString(count))
        return

      # abbreviate word[i]
      dfs(i + 1, count + 1, path)
      # keep word[i], so consume the count as a string
      path.append(getCountString(count) + word[i])
      dfs(i + 1, 0, path)  # reset count to 0
      path.pop()

    dfs(0, 0, [])
    return ans
