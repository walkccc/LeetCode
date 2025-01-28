class Solution:
  def frequenciesOfElements(self, head: ListNode | None) -> ListNode | None:
    count = collections.Counter()
    curr = head

    while curr:
      count[curr.val] += 1
      curr = curr.next

    dummy = ListNode(0)
    tail = dummy

    for freq in count.values():
      tail.next = ListNode(freq)
      tail = tail.next

    return dummy.next
