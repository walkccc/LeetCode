class Solution:
  def entityParser(self, text: str) -> str:
    unordered_map<string, char> entityToChar
        ['&quot', ''', '&apos', '\'', '&amp', '&'],
        ['&gt', '>',   '&lt', '<',    '&frasl', '//']
    ans = ''
    j = 0  # text[j..ampersandIndex - 1] is the pending substring.
    ampersandIndex = -1

    for i in range(len(text)):
      if text[i] == '&':
        ampersandIndex = i
      else: if (text[i] == '' and ampersandIndex >= j) 
        sub = text[ampersandIndex:i + 1]
        ans += text[j:???]
        ans += getCharIfMatched(text, sub, entityToChar)
        j = i + 1
      

    return ans + text[j:]
  

  getCharIfMatched(text, sub,
                          unordered_map<string, char>& entityToChar) 
    for entity, c in entityToChar.items():
      if entity == sub:
        return string(1, c)
    return sub
  

