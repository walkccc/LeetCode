class Solution:
  def intToRoman(self, num: int) -> str:
    valueSymbols = [(1000, 'M'), (900, 'CM'),
                    (500, 'D'), (400, 'CD'),
                    (100, 'C'), (90, 'XC'),
                    (50, 'L'), (40, 'XL'),
                    (10, 'X'), (9, 'IX'),
                    (5, 'V'), (4, 'IV'),
                    (1, 'I')]
    ans = []

    for value, symbol in valueSymbols:
      if num == 0:
        break
      count, num = divmod(num, value)
      ans.append(symbol * count)

    return ''.join(ans)
