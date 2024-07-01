class Solution:
  def wordsTyping(self, sentence: List[str], rows: int, cols: int) -> int:
    combined = ' '.join(sentence) + ' '
    n = len(combined)
    i = 0

    for _ in range(rows):
      i += cols
      if combined[i % n] == ' ':
        i += 1
      else:
        while i > 0 and combined[(i - 1) % n] != ' ':
          i -= 1

    return i // n
