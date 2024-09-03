class Solution:
  def restoreArray(self, adjacentPairs: list[list[int]]) -> list[int]:
    ans = []
    numToAdjs = collections.defaultdict(list)

    for a, b in adjacentPairs:
      numToAdjs[a].append(b)
      numToAdjs[b].append(a)

    for num, adjs in numToAdjs.items():
      if len(adjs) == 1:
        ans.append(num)
        ans.append(adjs[0])
        break

    while len(ans) < len(adjacentPairs) + 1:
      tail = ans[-1]
      prev = ans[-2]
      adjs = numToAdjs[tail]
      if adjs[0] == prev:  # adjs[0] is already used
        ans.append(adjs[1])
      else:
        ans.append(adjs[0])

    return ans
