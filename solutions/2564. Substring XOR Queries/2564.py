class Solution:
  def substringXorQueries(self, s: str, queries: List[List[int]]) -> List[List[int]]:
    kMaxBit = 30
    # {val: [left, right]} := s[left..right]'s decimal value = val
    valToLeftAndRight = collections.defaultdict(lambda: [-1, -1])

    for left, c in enumerate(s):
      val = 0
      if c == '0':
        # edge case: Save the index of the first 0.
        if 0 not in valToLeftAndRight:
          valToLeftAndRight[0] = [left, left]
        continue
      for right in range(left, min(len(s), left + kMaxBit)):
        val = val * 2 + int(s[right])
        if val not in valToLeftAndRight:
          valToLeftAndRight[val] = [left, right]

    return [valToLeftAndRight[first, right]
            for first, right in queries]
