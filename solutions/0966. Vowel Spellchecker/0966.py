class Solution:
  def spellchecker(self, wordlist: List[str], queries: List[str]) -> List[str]:
    def lowerKey(word: str) -> str:
      return '$' + ''.join([c.lower() for c in word])

    def vowelKey(word: str) -> str:
      return ''.join(['*' if c.lower() in 'aeiou' else c.lower() for c in word])

    ans = []
    dict = {}

    for word in wordlist:
      dict.setdefault(word, word)
      dict.setdefault(lowerKey(word), word)
      dict.setdefault(vowelKey(word), word)

    for q in queries:
      if q in dict:
        ans.append(dict[q])
      elif lowerKey(q) in dict:
        ans.append(dict[lowerKey(q)])
      elif vowelKey(q) in dict:
        ans.append(dict[vowelKey(q)])
      else:
        ans.append('')

    return ans
