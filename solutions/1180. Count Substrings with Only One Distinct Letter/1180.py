class Solution:
  def countLetters(self, s: str) -> int:
    ans = 0
    dp = 0  # the length of the running letter
    letter = '@'  # the running letter

    for c in s:
      if c == letter:
        dp += 1
      else:
        dp = 1
        letter = c
      ans += dp  # Add the number of substrings ending in the current letter.

    return ans
