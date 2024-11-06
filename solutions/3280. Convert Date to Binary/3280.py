class Solution:
  def convertDateToBinary(self, date: str) -> str:
    year, month, day = map(int, date.split('-'))

    def toBinary(value: int) -> str:
      """Converts an integer to binary without leading zeros."""
      return bin(value)[2:]

    return '-'.join([toBinary(year), toBinary(month), toBinary(day)])
