class Solution:
  def countLetters(self, s: str) -> int:
    ans = 0
    dp = 0         # length of the running letter
    letter = '@'  # running letter

    for c in s:
      if c == letter:
        dp += 1
      else:
        dp = 1
        letter = c
      ans += dp  # Add # of substrings ending at current letter.

    return ans
