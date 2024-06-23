class Solution:
  def minMovesToMakePalindrome(self, s: str) -> int:
    ans = 0
    chars = list(s)

    while len(chars) > 1:
      # Greedily match the last digit.
      i = chars.index(chars[-1])
      if i == len(chars) - 1:
        # s[i] is the middle letter.
        ans += i // 2
      else:
        chars.pop(i)
        ans += i  # Swap the matched letter to the left.
      chars.pop()

    return ans
