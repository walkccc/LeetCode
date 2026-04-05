class Solution:
  def decode(self, encoded: list[int]) -> list[int]:
    # Our goal is to find the value of a1, which will allow us to decode a2, a3,
    # ..., an. This can be achieved by performing XOR operation between each
    # element in `encoded` and a1.
    #
    # e.g. n = 3, perm = [a1, a2, a3] is a permutation of [1, 2, 3].
    #               encoded = [a1^a2, a2^a3]
    #    accumulatedEncoded = [a1^a2, a1^a3]
    #    a1 = (a1^a2)^(a1^a3)^(a1^a2^a3)
    #    a2 = a1^(a1^a2)
    #    a3 = a2^(a2^a3)
    n = len(encoded) + 1
    nXors = functools.reduce(operator.xor, [i for i in range(1, n + 1)])

    # Instead of constructing the array, we can track of the running XOR value
    # of `accumulatedEncoded`.
    xors = 0  # xors(accumulatedEncoded)

    for encode in encoded:
      runningXors ^= encode
      xors ^= runningXors

    ans = [xors ^ nXors]

    for encode in encoded:
      ans.append(ans[-1] ^ encode)

    return ans
