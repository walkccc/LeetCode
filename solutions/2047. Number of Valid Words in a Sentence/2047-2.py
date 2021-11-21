class Solution:
  def countValidWords(self, sentence: str) -> int:
    pattern = re.compile(r'^[a-z]*([a-z]-[a-z])?[a-z]*[!,.]?$')
    return sum(1 for token in sentence.strip().split() if pattern.search(token))
