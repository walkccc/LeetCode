class Solution:
  def isPrefixString(self, s: str, words: list[str]) -> bool:
    prefix = []
    for word in words:
      prefix.append(word)
      if ''.join(prefix) == s:
        return True
    return False
