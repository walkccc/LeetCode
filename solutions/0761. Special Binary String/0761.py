class Solution:
  def makeLargestSpecial(self, S: str) -> str:
    specials = []
    count = 0

    i = 0
    for j, c in enumerate(S):
      count += 1 if c == '1' else -1
      if count == 0:
        specials.append(
            '1' + self.makeLargestSpecial(S[i + 1:j]) + '0')
        i = j + 1

    return ''.join(sorted(specials)[::-1])
