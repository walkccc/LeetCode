class Solution:
  def destCity(self, paths: list[list[str]]) -> str:
    count = collections.Counter()

    for a, b in paths:
      count[a] += 1

    for a, b in paths:
      if b in count:
        count[b] -= 1
        if count[b] == 0:
          del count[b]
      else:
        return b
