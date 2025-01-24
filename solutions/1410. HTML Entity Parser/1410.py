class Solution:
  def entityParser(self, text: str) -> str:
    entityToChar = {'&quot;': '"', '&apos;': '\'',
                    '&gt;': '>', '&lt;': '<', '&frasl;': '/'}

    for entity, c in entityToChar.items():
      text = text.replace(entity, c)

    # Process '&' in last.
    return text.replace('&amp;', '&')
