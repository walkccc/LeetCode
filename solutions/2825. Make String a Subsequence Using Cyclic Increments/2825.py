class Solution:
  def canMakeSubsequence(self, str1: str, str2: str) -> bool:
    i = 0  # str2's index

    for c in str1:
      if c == str2[i] or chr(
              ord('a') + (string.ascii_lowercase.index(c) + 1) % 26) == str2[i]:
        i += 1
        if i == len(str2):
          return True

    return False
