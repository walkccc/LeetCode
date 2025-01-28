class Solution:
  def generateAbbreviations(self, word: str) -> list[str]:
    ans = []

    def getCountString(count: int) -> str:
      return str(count) if count > 0 else ''

    def dfs(i: int, count: int, path: list[str]) -> None:
      if i == len(word):
        ans.append(''.join(path) + getCountString(count))
        return

      # Abbreviate the word[i].
      dfs(i + 1, count + 1, path)
      # Keep the word[i], so consume the count as a string.
      path.append(getCountString(count) + word[i])
      # Reset the count to 0.
      dfs(i + 1, 0, path)
      path.pop()

    dfs(0, 0, [])
    return ans
