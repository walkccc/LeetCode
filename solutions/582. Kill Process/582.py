class Solution:
  def killProcess(
      self,
      pid: list[int],
      ppid: list[int],
      kill: int,
  ) -> list[int]:
    ans = []
    tree = collections.defaultdict(list)

    for v, u in zip(pid, ppid):
      if u == 0:
        continue
      tree[u].append(v)

    def dfs(u: int) -> None:
      ans.append(u)
      for v in tree.get(u, []):
        dfs(v)

    dfs(kill)
    return ans
