class Solution:
  def betterCompression(self, compressed: str) -> str:
    count = collections.Counter()
    i = 0

    while i < len(compressed):
      c = compressed[i]
      i += 1
      freq = 0
      while i < len(compressed) and compressed[i].isdigit():
        freq = freq * 10 + int(compressed[i])
        i += 1
      count[c] += freq

    return ''.join([c + str(count[c])
                    for c in sorted(count.keys())])
