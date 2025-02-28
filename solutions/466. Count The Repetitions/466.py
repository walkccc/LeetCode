from dataclasses import dataclass


@dataclass
class Record:
  count: int
  nextIndex: int


class Solution:
  def getMaxRepetitions(self, s1: str, n1: int, s2: str, n2: int) -> int:
    # records[i].count := the number of times that s2 starting from index i has
    # been fully matched with s1
    # records[i].nextIndex := the next index in s2 to be matched after
    # completing a full match starting from index i
    records = []

    for nextIndex in range(len(s2)):
      count = 0
      for c in s1:
        if s2[nextIndex] == c:
          nextIndex += 1
          if nextIndex == len(s2):  # There's a match.
            count += 1
            nextIndex = 0
      records.append(Record(count, nextIndex))

    matches = 0  # the number of matches between `s1` x n1 and `s2`
    i = 0  # the index in `s2` to start matching

    for _ in range(n1):
      matches += records[i].count
      i = records[i].nextIndex

    return matches // n2
