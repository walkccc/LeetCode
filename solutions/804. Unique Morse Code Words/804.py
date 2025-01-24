class Solution:
  def uniqueMorseRepresentations(self, words: list[str]) -> int:
    morse = [".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
             ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
             "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."]
    transformations = set()

    for word in words:
      transformation = ''.join(
          morse[string.ascii_lowercase.index(c)] for c in word)
      transformations.add(transformation)

    return len(transformations)
