class Solution:
  def subStrHash(self, s: str, power: int, modulo: int, k: int, hashValue: int) -> str:
    maxPower = pow(power, k, modulo)
    hashed = 0

    def val(c: chr) -> int:
      return ord(c) - ord('a') + 1

    for i, c in reversed(list(enumerate(s))):
      hashed = (hashed * power + val(c)) % modulo
      if i + k < len(s):
        hashed = (hashed - val(s[i + k]) * maxPower) % modulo
      if hashed == hashValue:
        bestLeft = i

    return s[bestLeft:bestLeft + k]
