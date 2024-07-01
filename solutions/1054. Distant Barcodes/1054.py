class Solution:
  def rearrangeBarcodes(self, barcodes: List[int]) -> List[int]:
    ans = [0] * len(barcodes)
    count = collections.Counter(barcodes)
    i = 0  # ans' index
    maxNum = max(count, key=count.get)

    def fillAns(num: int) -> None:
      nonlocal i
      while count[num]:
        ans[i] = num
        i = i + 2 if i + 2 < len(barcodes) else 1
        count[num] -= 1

    fillAns(maxNum)
    for num in count.keys():
      fillAns(num)

    return ans
