class Solution:
  def countWords(self, words1: List[str], words2: List[str]) -> int:
    count = Counter(words1)

    for word in words2:
      if word in count and count[word] < 2:
        count[word] -= 1

    return sum(value == 0 for value in count.values())
