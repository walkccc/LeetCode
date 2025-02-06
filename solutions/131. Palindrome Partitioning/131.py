class Solution:
  def partition(self, s: str) -> list[list[str]]:
    ans = []

    def isPalindrome(s: str) -> bool:
      return s == s[::-1]

    def dfs(s: str, j: int, path: list[str], ans: list[list[str]]) -> None:
      if j == len(s):
        ans.append(path)
        return

      for i in range(j, len(s)):
        if isPalindrome(s[j: i + 1]):
          dfs(s, i + 1, path + [s[j: i + 1]], ans)

    dfs(s, 0, [], ans)
    return ans
