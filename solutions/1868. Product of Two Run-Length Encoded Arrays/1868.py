class Solution:
  def findRLEArray(self, encoded1: List[List[int]],
                   encoded2: List[List[int]]) -> List[List[int]]:
    ans = []
    i = 0  # encoded1's index
    j = 0  # encoded2's index

    while i < len(encoded1) and j < len(encoded2):
      mult = encoded1[i][0] * encoded2[j][0]
      minFreq = min(encoded1[i][1], encoded2[j][1])
      if ans and mult == ans[-1][0]:
        ans[-1][1] += minFreq
      else:
        ans.append([mult, minFreq])
      encoded1[i][1] -= minFreq
      encoded2[j][1] -= minFreq
      if encoded1[i][1] == 0:
        i += 1
      if encoded2[j][1] == 0:
        j += 1

    return ans
