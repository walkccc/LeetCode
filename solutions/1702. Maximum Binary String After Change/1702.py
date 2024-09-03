class Solution:
  def maximumBinaryString(self, binary: str) -> str:
    #     e.g. binary = '100110'
    # Do Operation 2 -> '100011'
    # Do Operation 1 -> '111011'
    # So, the index of the only '0' is prefixOnes + zeros - 1.
    zeros = binary.count('0')
    prefixOnes = binary.find('0')

    # Make the entire string as 1s.
    ans = ['1'] * len(binary)

    # Make the only '0' if necessary.
    if prefixOnes != -1:
      ans[prefixOnes + zeros - 1] = '0'
    return ''.join(ans)
