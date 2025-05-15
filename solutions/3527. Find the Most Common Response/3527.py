class Solution:
  def findCommonResponse(self, responses: list[list[str]]) -> str:
    count = collections.Counter()

    for response in responses:
      for response in set(response):
        count[response] += 1

    maxFreq = max(count.values())
    return min([response
                for response, count in count.items()
                if count == maxFreq])
