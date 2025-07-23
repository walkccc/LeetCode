class Solution:
  def maxEnvelopes(self, envelopes: list[list[int]]) -> int:
    envelopes.sort(key=lambda x: (x[0], -x[1]))
    return self._lengthOfLIS(envelopes)

  def _lengthOfLIS(self, envelopes: list[list[int]]) -> int:
    # tails[i] := the minimum tails of all the increasing subsequences having
    # length i + 1
    tails = []

    for _, h in envelopes:
      if not tails or h > tails[-1]:
        tails.append(h)
      else:
        tails[bisect.bisect_left(tails, h)] = h

    return len(tails)
