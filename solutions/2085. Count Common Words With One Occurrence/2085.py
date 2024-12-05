class Solution:
  def countWords(self, words1: list[str], words2: list[str]) -> int:
    count = collections.Counter(words1)

    for word in words2:
      if word in count and count[word] < 2:
        count[word] -= 1

    return sum(value == 0 for value in count.values())
