class Solution:
  def buildArray(self, target: list[int], n: int) -> list[str]:
    ans = []
    i = 0  # Target pointer
    num = 1  # Curr num

    while i < len(target):
      t = target[i]
      if t == num:
        ans.append('Push')
        i += 1
      else:
        ans.append('Push')
        ans.append('Pop')
      num += 1

    return ans
