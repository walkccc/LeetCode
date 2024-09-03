class Solution:
  def largestPalindrome(self, n: int, k: int) -> str:
    match k:
      case 1:
        return '9' * n
      case 2:
        return '8' * n if n <= 2 else '8' + '9' * (n - 2) + '8'
      case 3 | 9:
        return '9' * n
      case 4:
        return '8' * n if n <= 4 else '88' + '9' * (n - 4) + '88'
      case 5:
        return '5' * n if n <= 2 else '5' + '9' * (n - 2) + '5'
      case 6:
        if n <= 2:
          return '6' * n
        elif n % 2 == 1:
          l = n // 2 - 1
          return '8' + '9' * l + '8' + '9' * l + '8'
        else:
          l = n // 2 - 2
          return '8' + '9' * l + '77' + '9' * l + '8'
      case 8:
        return '8' * n if n <= 6 else '888' + '9' * (n - 6) + '888'
      case _:
        middle = {
            0: '', 1: '7', 2: '77', 3: '959', 4: '9779', 5: '99799',
            6: '999999', 7: '9994999', 8: '99944999', 9: '999969999',
            10: '9999449999', 11: '99999499999'
        }
        q, r = divmod(n, 12)
        return '999999' * q + middle[r] + '999999' * q
