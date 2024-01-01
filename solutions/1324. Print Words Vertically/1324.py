class Solution:
  def printVertically(self, s: str) -> List[str]:
    ans = []
    words = s.split()
    maxLength = max(len(word) for word in words)

    for i in range(maxLength):
      row = []
      for word in words:
        row.append(word[i] if i < len(word) else ' ')
      ans.append(''.join(row).rstrip())

    return ans
