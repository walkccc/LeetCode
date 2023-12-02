class Solution:
  def uniqueMorseRepresentations(self, words: List[str]) -> int:
    morse = [".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--",
             "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."]
    transformations = set()

    for word in words:
      transformation = ''.join(morse[ord(c) - ord('a')] for c in word)
      transformations.add(transformation)

    return len(transformations)
