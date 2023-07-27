class Solution:
  def distinctSubseqII(self, s: str) -> int:
    kMod = 1_000_000_007
    # endsWith[i] := # of subseqs ends with 'a' + i
    endsWith = [0] * 26

    for c in s:
      endsWith[ord(c) - ord('a')] = (sum(endsWith) + 1) % kMod

    return sum(endsWith) % kMod
