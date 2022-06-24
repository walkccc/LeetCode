class Solution:
  def killProcess(self, pid: List[int], ppid: List[int], kill: int) -> List[int]:
    ans = []
    tree = defaultdict(list)

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
