class Solution:
  def readBinaryWatch(self, turnedOn: int) -> list[str]:
    ans = []

    for h in range(12):
      for m in range(60):
        if h.bit_count() + m.bit_count() == turnedOn:
          ans.append(f'{h}:{m:02d}')

    return ans
