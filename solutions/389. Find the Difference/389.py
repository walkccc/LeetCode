class Solution:
  def findTheDifference(self, s: str, t: str) -> str:
    sXors = chr(functools.reduce(operator.xor, map(ord, s), 0))
    tXors = chr(functools.reduce(operator.xor, map(ord, t), 0))
    return chr(ord(sXors) ^ ord(tXors))
