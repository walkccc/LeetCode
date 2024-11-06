class Solution:
  def clearDigits(self, s: str) -> str:
    ans = []

    for c in s:
      if c.isdigit():
        # Since `ans` only contains non-digit characters, removing the last
        # character is equivalent to deleting the closest non-digit character.
        ans.pop()
      else:
        ans.append(c)

    return ''.join(ans)
