class Solution:
  # Similar to 940. Distinct Subsequences II
  def numberOfUniqueGoodSubsequences(self, binary: str) -> int:
    kMod = 1_000_000_007
    # endsWith[i] := # of subseqs ends with '0' + i
    endsWith = {'0': 0, '1': 0}

    for c in binary:
      endsWith[c] = sum(endsWith.values()) % kMod
      # Don't cound '0' since we want to avoid the leading zeros case.
      # However, we can always count '1'.
      if c == '1':
        endsWith['1'] += 1

    # Count '0' in the end.
    return (sum(endsWith.values()) + ('0' in binary)) % kMod
