class Solution:
  def distinctEchoSubstrings(self, text: str) -> int:
    seen = set()

    for k in range(1, len(text) // 2 + 1):  # the target length
      same = 0
      l = 0
      for r in range(k, len(text)):
        if text[l] == text[r]:
          same += 1
        else:
          same = 0
        if same == k:
          seen.add(text[l - k + 1:l + 1])
          # Move the window thus leaving a letter behind, so we need to
          # decrease the counter.
          same -= 1
        l += 1

    return len(seen)
