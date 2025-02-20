class Solution:
  def beautifulArray(self, n: int) -> list[int]:
    arr = [i for i in range(1, n + 1)]

    def partition(l: int, r: int, mask: int) -> int:
      nextSwapped = l
      for i in range(l, r + 1):
        if arr[i] & mask:
          arr[i], arr[nextSwapped] = arr[nextSwapped], arr[i]
          nextSwapped += 1
      return nextSwapped - 1

    def divide(l: int, r: int, mask: int) -> None:
      if l >= r:
        return
      m = partition(l, r, mask)
      divide(l, m, mask << 1)
      divide(m + 1, r, mask << 1)

    divide(0, n - 1, 1)
    return arr
