class Solution:
  def countHighestScoreNodes(self, parents: List[int]) -> int:
    tree = [[] for _ in range(len(parents))]

    for i, parent in enumerate(parents):
      if parent == -1:
        continue
      tree[parent].append(i)

    ans = 0
    maxScore = 0

    def dfs(u: int) -> int:  # Returns node count
      nonlocal ans
      nonlocal maxScore
      count = 1
      score = 1
      for v in tree[u]:
        childCount = dfs(v)
        count += childCount
        score *= childCount
      score *= len(parents) - count or 1
      if score > maxScore:
        maxScore = score
        ans = 1
      elif score == maxScore:
        ans += 1
      return count

    dfs(0)
    return ans
