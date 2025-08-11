class Solution:
  def hasMatch(self, s: str, p: str) -> bool:
    prefix, suffix = p.split('*')
    i = s.find(prefix)
    return i != -1 and s.find(suffix, i + len(prefix)) != -1
