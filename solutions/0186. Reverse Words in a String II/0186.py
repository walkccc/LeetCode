class Solution:
  def reverseWords(self, s: List[str]) -> None:
    def reverse(l: int, r: int) -> None:
      while l < r:
        s[l], s[r] = s[r], s[l]
        l += 1
        r -= 1

    def reverseWords(n: int) -> None:
      i = 0
      j = 0

      while i < n:
        while i < j or (i < n and s[i] == ' '):  # skip spaces
          i += 1
        while j < i or (j < n and s[j] != ' '):  # skip non spaces
          j += 1
        reverse(i, j - 1)  # reverse the word

    reverse(0, len(s) - 1)  # reverse the whole string
    reverseWords(len(s))  # reverse each word
