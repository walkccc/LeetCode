class Solution:
  def spellchecker(self, wordlist: list[str], queries: list[str]) -> list[str]:
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

    for query in queries:
      if query in dict:
        ans.append(dict[query])
      elif lowerKey(query) in dict:
        ans.append(dict[lowerKey(query)])
      elif vowelKey(query) in dict:
        ans.append(dict[vowelKey(query)])
      else:
        ans.append('')

    return ans
