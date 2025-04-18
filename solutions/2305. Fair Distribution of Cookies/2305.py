class Solution:
  def distributeCookies(self, cookies: list[int], k: int) -> int:
    ans = math.inf

    def dfs(s: int, children: list[int]) -> None:
      nonlocal ans
      if s == len(cookies):
        ans = min(ans, max(children))
        return

      for i in range(k):
        children[i] += cookies[s]
        dfs(s + 1, children)
        children[i] -= cookies[s]

    dfs(0, [0] * k)
    return ans
