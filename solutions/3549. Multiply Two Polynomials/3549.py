from numpy import array, round
from numpy.fft import fft, ifft


class Solution:
  def multiply(self, poly1: list[int], poly2: list[int]) -> list[int]:
    n1 = len(poly1)
    n2 = len(poly2)
    n = n1 + n2 - 1
    sz = 1 << (n - 1).bit_length()
    arr1 = array(poly1 + [0] * (sz - n1))
    arr2 = array(poly2 + [0] * (sz - n2))
    ans = ifft(fft(arr1) * fft(arr2))
    return round(ans).astype(int).tolist()[:n]
