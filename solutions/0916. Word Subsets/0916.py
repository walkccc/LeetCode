class Solution:
  def wordSubsets(self, A: List[str], B: List[str]) -> List[str]:
    count = Counter()

    for b in B:
      count = count | Counter(b)

    return [a for a in A if Counter(a) & count == count]
