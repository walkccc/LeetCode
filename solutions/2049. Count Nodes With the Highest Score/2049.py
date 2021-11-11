class Solution:
  def countHighestScoreNodes(self, parents: List[int]) -> int:
    tree = [[] for _ in range(len(parents))]

    for i, parent in enumerate(parents):
      if parent == -1:
        continue
      tree[parent].append(i)

    self.ans = 0
    self.maxScore = 0

    def dfs(u: int) -> int:  # return node count
      count = 1
      score = 1
      for v in tree[u]:
        childCount = dfs(v)
        count += childCount
        score *= childCount
      score *= len(parents) - count or 1
      if score > self.maxScore:
        self.maxScore = score
        self.ans = 1
      elif score == self.maxScore:
        self.ans += 1
      return count

    dfs(0)

    return self.ans
