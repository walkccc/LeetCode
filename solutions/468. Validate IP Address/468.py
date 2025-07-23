class Solution:
  def validIPAddress(self, queryIP: str) -> str:
    if queryIP.count('.') == 3:
      parts = queryIP.split('.')
      if len(parts) == 4 and all(self._isIPv4(part) for part in parts):
        return 'IPv4'

    if queryIP.count(':') == 7:
      parts = queryIP.split(':')
      if len(parts) == 8 and all(self._isIPv6(part) for part in parts):
        return 'IPv6'

    return 'Neither'

  def _isIPv4(self, digit: str) -> bool:
    if not digit or len(digit) > 3:
      return False
    if len(digit) > 1 and digit[0] == '0':
      return False
    if not all(c.isdigit() for c in digit):
      return False
    num = int(digit)
    return 0 <= num <= 255

  def _isIPv6(self, digit: str) -> bool:
    if not digit or len(digit) > 4:
      return False
    validChars = set('0123456789abcdefABCDEF')
    return all(c in validChars for c in digit)
