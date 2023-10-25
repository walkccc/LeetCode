class Solution:
  def removeVowels(self, s: str) -> str:
    return re.sub('a|e|i|o|u', '', s)
