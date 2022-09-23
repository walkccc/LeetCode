class Solution:
  def minMovesToMakePalindrome(self, s: str) -> int:
    ans = 0
    A = list(s)

    while len(A) > 1:
      # greedily match the last digit
      i = A.index(A[-1])
      if i == len(A) - 1:
        # s[i] is the middle char
        ans += i // 2
      else:
        A.pop(i)
        ans += i  # swapped the matches to the left
      A.pop()

    return ans
