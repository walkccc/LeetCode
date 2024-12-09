class Solution:
  def equalDigitFrequency(self, s: str) -> int:
    kBase = 11
    kHash = 1_000_000_007
    counts: list[dict] = []  # counts[i] := the counter map of s[0..i]
    count = collections.Counter()
    pows = [1]  # pows[i] := kBase^i % kHash
    # hash[i] = the hash of the first i letters of s, where hash[i] =
    # (26^(i - 1) * s[0] + 26^(i - 2) * s[1] + ... + s[i - 1]) % kHash
    hash = [0]

    def val(c: str) -> int:
      return int(c) + 1

    for c in s:
      count[c] += 1
      counts.append(count.copy())
      pows.append(pows[-1] * kBase % kHash)
      hash.append((hash[-1] * kBase + val(c)) % kHash)

    def getRollingHash(l: int, r: int) -> int:
      """Returns the rolling hash of s[l..r)."""
      h = (hash[r] - hash[l] * pows[r - l]) % kHash
      return h + kHash if h < 0 else h

    return len({getRollingHash(i, j + 1)
                for i in range(len(s))
                for j in range(i, len(s))
                if self._isSameFreq(counts, i, j)})

  def _isSameFreq(self, counts: list[dict], i: int, j: int) -> bool:
    count = counts[j].copy()
    if i > 0:
      for c, freq in counts[i - 1].items():
        count[c] -= freq
        if count[c] == 0:
          del count[c]
    return min(count.values()) == max(count.values())
