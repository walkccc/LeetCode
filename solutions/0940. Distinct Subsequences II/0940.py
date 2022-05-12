class Solution:
  def distinctSubseqII(self, s: str) -> int:
    kMod = int(1e9) + 7
    # endsWith[i] := # of subseqs ends with 'a' + i
    endsWith = [0] * 26

    for c in s:
      endsWith[ord(c) - ord('a')] = (sum(endsWith) + 1) % kMod

    return sum(endsWith) % kMod
