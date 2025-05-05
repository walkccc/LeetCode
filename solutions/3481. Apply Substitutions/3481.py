class Solution:
  def applySubstitutions(self, replacements: list[list[str]], text: str) -> str:
    replaceMap = {key: value for key, value in replacements}

    def evaluate(text: str) -> str:
      """
      Evaluates the text and replaces the placeholders with the values
      from the replace_map recursively.
      """
      res = []
      i = 0
      while i < len(text):
        if text[i] == '%':
          j = i + 1 + text[i + 1:].find('%')
          key = text[i + 1:j]
          value = replaceMap[key]
          res.append(evaluate(value))
          i = j + 1
        else:
          res.append(text[i])
          i += 1
      return ''.join(res)

    return evaluate(text)
