class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        dummy = ListNode(0)
        curr = dummy
        pq = []

        for i, lst in enumerate(lists):
            if lst:
                heapq.heappush(pq, (lst.val, i, lst))

        while pq:
            node = heapq.heappop(pq)
            curr.next = node[2]
            curr = curr.next
            if curr.next:
                heapq.heappush(pq, (curr.next.val, node[1], curr.next))

        return dummy.next
