class Solution:
  def totalFruit(self, tree: List[int]) -> int:
    ans = 0
    count = defaultdict(int)

    l = 0
    for r, t in enumerate(tree):
      count[t] += 1
      while len(count) > 2:
        count[tree[l]] -= 1
        if count[tree[l]] == 0:
          del count[tree[l]]
        l += 1
      ans = max(ans, r - l + 1)

    return ans
