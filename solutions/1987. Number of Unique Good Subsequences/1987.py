class Solution:
  # Similar to 940. Distinct Subsequences II
  def numberOfUniqueGoodSubsequences(self, binary: str) -> int:
    kMod = 1_000_000_007
    # endsIn[i] := the number of subsequence that end in ('0' + i)
    endsIn = {'0': 0, '1': 0}

    for c in binary:
      endsIn[c] = sum(endsIn.values()) % kMod
      # Don't count '0' since we want to avoid the leading zeros case.
      # However, we can always count '1'.
      if c == '1':
        endsIn['1'] += 1

    # Count '0' in the end.
    return (sum(endsIn.values()) + ('0' in binary)) % kMod
