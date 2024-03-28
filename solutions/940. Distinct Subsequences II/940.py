class Solution:
  def distinctSubseqII(self, s: str) -> int:
    kMod = 1_000_000_007
    # endsIn[i] := the number of subsequence that end in ('a' + i)
    endsIn = [0] * 26

    for c in s:
      endsIn[ord(c) - ord('a')] = (sum(endsIn) + 1) % kMod

    return sum(endsIn) % kMod
