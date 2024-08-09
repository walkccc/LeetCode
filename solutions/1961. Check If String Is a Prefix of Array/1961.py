class Solution:
  def isPrefixString(self, s: str, words: List[str]) -> bool:
    prefix = []
    for word in words:
      prefix.append(word)
      if ''.join(prefix) == s:
        return True
    return False
