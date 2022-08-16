class Solution:
  def reorganizeString(self, s: str) -> str:
    count = Counter(s)
    if max(count.values()) > (len(s) + 1) // 2:
      return ''

    ans = []
    maxHeap = [(-freq, c) for c, freq in count.items()]
    heapq.heapify(maxHeap)
    prevFreq = 0
    prevChar = '@'

    while maxHeap:
      # get the most freq letter
      freq, c = heapq.heappop(maxHeap)
      ans.append(c)
      # add the previous letter back so that
      # any two adjacent characters are not the same
      if prevFreq < 0:
        heapq.heappush(maxHeap, (prevFreq, prevChar))
      prevFreq = freq + 1
      prevChar = c

    return ''.join(ans)
