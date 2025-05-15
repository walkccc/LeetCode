class Solution:
  def decodeMessage(self, key: str, message: str) -> str:
    keyToActual = {' ': ' '}
    currChar = 'a'

    for c in key:
      if c not in keyToActual:
        keyToActual[c] = currChar
        currChar = chr(ord(currChar) + 1)

    return ''.join(keyToActual[c] for c in message)
