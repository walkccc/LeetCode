class Solution:
  def fullJustify(self, words: list[str], maxWidth: int) -> list[str]:
    ans = []
    row = []
    rowLetters = 0

    for word in words:
      # If we place the word in this row, it will exceed the maximum width.
      # Therefore, we cannot put the word in this row and have to pad spaces
      # for each word in this row.
      if rowLetters + len(word) + len(row) > maxWidth:
        for i in range(maxWidth - rowLetters):
          row[i % (len(row) - 1 or 1)] += ' '
        ans.append(''.join(row))
        row = []
        rowLetters = 0
      row.append(word)
      rowLetters += len(word)

    return ans + [' '.join(row).ljust(maxWidth)]
