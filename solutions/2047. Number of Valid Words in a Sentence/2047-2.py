class Solution:
  def countValidWords(self, sentence: str) -> int:
    pattern = re.compile(r'^[a-z]*([a-z]-[a-z])?[a-z]*[!,.]?$')
    return sum(pattern.search(token) != None for token in
               sentence.strip().split())
