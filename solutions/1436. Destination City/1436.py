class Solution:
  def destCity(self, paths: List[List[str]]) -> str:
    count = Counter()

    for a, b in paths:
      count[a] += 1

    for a, b in paths:
      if b in count:
        count[b] -= 1
        if count[b] == 0:
          del count[b]
      else:
        return b
