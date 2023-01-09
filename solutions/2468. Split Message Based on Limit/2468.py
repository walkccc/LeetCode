class Solution:
  def splitMessage(self, message: str, limit: int) -> List[str]:
    kMessageLength = len(message)

    def sz(num: int):
      return len(str(num))

    b = 1
    aLength = sz(1)  # Total length of a. Initialized with the length of "1".

    # Total length of b := b * sz(b)
    # Total length of "</>" := b * 3
    while b * limit < b * (sz(b) + 3) + aLength + kMessageLength:
      # If the length the last suffix "<b/b>" := sz(b) * 2 + 3 >= limit,
      # then it's impossible that the length of "*<b/b>" <= limit.
      if sz(b) * 2 + 3 >= limit:
        return []
      b += 1
      aLength += sz(b)

    ans = []

    i = 0
    for a in range(1, b + 1):
      # Length of "<a/b>" := sz(a) + sz(b) + 3
      j = limit - (sz(a) + sz(b) + 3)
      ans.append(f'{message[i:i + j]}<{a}/{b}>')
      i += j

    return ans
