class Solution:
  def movesToStamp(self, stamp: str, target: str) -> List[int]:
    def stampify(s: int) -> int:
      """
      Stamps target[i..i + |stamp|) and returns the number of newly stamped
      characters.
      e.g. stampify("abc", "ababc", 2) returns 3 because target becomes "ab***".
      """
      stampified = len(stamp)

      for i, st in enumerate(stamp):
        if target[s + i] == '*':  # It's already been stamped.
          stampified -= 1
        elif target[s + i] != st:  # We can't stamp on the index i.
          return 0

      for i in range(s, s + len(stamp)):
        target[i] = '*'

      return stampified

    ans = []
    target = list(target)
    # stamped[i] := True if we already stamped target by stamping on index i
    stamped = [False] * len(target)
    stampedCount = 0  # Our goal is to make stampedCount = |target|.

    while stampedCount < len(target):
      isStamped = False
      # Try to stamp target[i..i + |stamp|) for each index.
      for i in range(len(target) - len(stamp) + 1):
        if stamped[i]:
          continue
        stampified = stampify(i)
        if stampified == 0:
          continue
        stampedCount += stampified
        isStamped = True
        stamped[i] = True
        ans.append(i)
      # After trying to stamp on each index, we can't find a valid stamp.
      if not isStamped:
        return []

    return ans[::-1]
