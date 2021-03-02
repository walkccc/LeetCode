class Solution:
  def partition(self, s: str) -> List[List[str]]:
    ans = []

    self.dfs(s, 0, [], ans)

    return ans

  def dfs(self, s: str, j: int, path: List[str], ans: List[List[str]]) -> None:
    if j == len(s):
      ans.append(path)
      return

    for i in range(j, len(s)):
      if self.isPalindrome(s[j: i + 1]):
        self.dfs(s, i + 1, path + [s[j: i + 1]], ans)

  def isPalindrome(self, s: str) -> bool:
    return s == s[::-1]
