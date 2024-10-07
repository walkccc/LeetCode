class Solution:
  def categorizeBox(
      self,
      length: int,
      width: int,
      height: int,
      mass: int,
  ) -> str:
    isBulky = (length >= 10000 or
               width >= 10000 or height >= 10000 or
               length * width * height >= 1_000_000_000)
    isHeavy = mass >= 100
    if isBulky and isHeavy:
      return 'Both'
    if isBulky:
      return 'Bulky'
    if isHeavy:
      return 'Heavy'
    return 'Neither'
