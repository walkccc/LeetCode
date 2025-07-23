class Solution:
  def countKConstraintSubstrings(
      self,
      s: str,
      k: int,
      queries: list[list[int]]
  ) -> list[int]:
    n = len(s)
    ans = []
    count = [0, 0]
    # leftToRight[l] := the maximum right index r s.t. s[l..r] is valid
    leftToRight = [0] * n
    # rightToLeft[r] := the minimum left index l s.t. s[l..r] is valid
    rightToLeft = [0] * n

    l = 0
    for r in range(n):
      count[int(s[r])] += 1
      while min(count) > k:
        count[int(s[l])] -= 1
        l += 1
      rightToLeft[r] = l

    count = [0, 0]
    r = n - 1
    for l in reversed(range(n)):
      count[int(s[l])] += 1
      while min(count) > k:
        count[int(s[r])] -= 1
        r -= 1
      leftToRight[l] = r

    # prefix[i] := the number of valid substrings ending in [0..i - 1].
    prefix = list(itertools.accumulate((r - l + 1
                                       for r, l in enumerate(rightToLeft)),
                                       initial=0))

    for l, r in queries:
      if r > leftToRight[l]:
        # If r is beyond leftToRight[l], compute the number of valid substrings
        # from l to leftToRight[l] and add the number of valid substrings
        # ending in [leftToRight[l] + 1..r].
        #
        # prefix[r + 1] := the number of valid substrings ending in [0..r].
        # prefix[leftToRight[l] + 1] := the number of valid substrings ending
        # in [0..leftToRight].
        # => prefix[r + 1] - prefix[leftToRight[l] + 1] := the number of valid
        # substrings ending in [leftToRight[l] + 1..r].
        sz = leftToRight[l] - l + 1
        numValidSubstrings = sz * (sz + 1) // 2 + (
            prefix[r + 1] - prefix[leftToRight[l] + 1])
      else:
        # If r is within the range of leftToRight[l], compute the number of
        # valid substrings directly from l to r.
        sz = r - l + 1
        numValidSubstrings = sz * (sz + 1) // 2
      ans.append(numValidSubstrings)

    return ans
