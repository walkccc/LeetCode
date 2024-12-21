class Solution:
  def subStrHash(
      self,
      s: str,
      power: int,
      modulo: int,
      k: int,
      hashValue: int,
  ) -> str:
    maxPower = pow(power, k, modulo)
    hash = 0

    def val(c: str) -> int:
      return string.ascii_lowercase.index(c) + 1

    for i, c in reversed(list(enumerate(s))):
      hash = (hash * power + val(c)) % modulo
      if i + k < len(s):
        hash = (hash - val(s[i + k]) * maxPower) % modulo
      if hash == hashValue:
        bestLeft = i

    return s[bestLeft:bestLeft + k]
