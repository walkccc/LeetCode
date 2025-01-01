class Solution:
  def flatten(self, head: 'Node') -> 'Node':
    def flatten(head: 'Node', rest: 'Node') -> 'Node':
      if not head:
        return rest

      head.next = flatten(head.child, flatten(head.next, rest))
      if head.next:
        head.next.prev = head
      head.child = None
      return head

    return flatten(head, None)
