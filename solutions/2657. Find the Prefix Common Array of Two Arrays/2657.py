class Solution:
  def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
    n = len(A)
    prefixCommon = 0
    ans = []
    count = [0] * (n + 1)

    for a, b in zip(A, B):
      count[a] += 1
      if count[a] == 2:
        prefixCommon += 1
      count[b] += 1
      if count[b] == 2:
        prefixCommon += 1
      ans.append(prefixCommon)

    return ans
