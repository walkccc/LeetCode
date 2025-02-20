class Solution:
  def minimumScore(self, s: str, t: str) -> int:
    # leftmost[j] := the minimum index i s.t. t[0..j] is a subsequence of s[0..i].
    #          -1 := impossible
    leftmost = [-1] * len(t)
    # rightmost[j] := the maximum index i s.t. t[j:] is a subsequence of s[i..n).
    #           -1 := impossible
    rightmost = [-1] * len(t)

    j = 0  # t's index
    for i in range(len(s)):
      if s[i] == t[j]:
        leftmost[j] = i
        j += 1
        if j == len(t):
          break

    j = len(t) - 1  # t's index
    for i in reversed(range(len(s))):
      if s[i] == t[j]:
        rightmost[j] = i
        j -= 1
        if j == -1:
          break

    # The worst case is to delete t[0:j] since t[j:] is a subsequence of s. (deduced
    # from the above loop).
    ans = j + 1

    j = 0
    for i in range(len(t)):
      # It's impossible that t[0..i] is a subsequence of s. So, stop the loop since
      # no need to consider any larger i.
      if leftmost[i] == -1:
        break
      # While t[0..i] + t[j:] is not a subsequence of s, increase j.
      while j < len(t) and leftmost[i] >= rightmost[j]:
        j += 1
      # Now, leftmost[i] < rightmost[j], so t[0..i] + t[j:n] is a subsequence of s.
      # If i == j that means t is a subsequence of s, so just return 0.
      if i == j:
        return 0
      # Delete t[i + 1..j - 1] and that's a total of j - i - 1 letters.
      ans = min(ans, j - i - 1)

    return ans
