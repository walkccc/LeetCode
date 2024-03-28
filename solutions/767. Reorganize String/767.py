class Solution:
  def reorganizeString(self, s: str) -> str:
    count = collections.Counter(s)
    if max(count.values()) > (len(s) + 1) // 2:
      return ''

    ans = []
    maxHeap = [(-freq, c) for c, freq in count.items()]
    heapq.heapify(maxHeap)
    prevFreq = 0
    prevChar = '@'

    while maxHeap:
      # Get the letter with the maximum frequency.
      freq, c = heapq.heappop(maxHeap)
      ans.append(c)
      # Add the previous letter back s.t. any two adjacent characters are not
      # the same.
      if prevFreq < 0:
        heapq.heappush(maxHeap, (prevFreq, prevChar))
      prevFreq = freq + 1
      prevChar = c

    return ''.join(ans)
