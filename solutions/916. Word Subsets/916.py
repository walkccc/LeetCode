class Solution:
  def wordSubsets(self, A: list[str], B: list[str]) -> list[str]:
    count = collections.Counter()

    for b in B:
      count = count | collections.Counter(b)

    return [a for a in A if collections.Counter(a) & count == count]
