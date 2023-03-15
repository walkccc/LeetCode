class Solution:
  def uniqueOccurrences(self, arr: List[int]) -> bool:
    count = collections.Counter(arr)
    occurrences = set()

    for value in count.values():
      if value in occurrences:
        return False
      occurrences.add(value)

    return True
