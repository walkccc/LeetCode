from dataclasses import dataclass


@dataclass
class ListNode:
  val: int
  next: ListNode | None = None


class MyLinkedList:
  def __init__(self):
    self.length = 0
    self.dummy = ListNode(0)

  def get(self, index: int) -> int:
    if index < 0 or index >= self.length:
      return -1
    curr = self.dummy.next
    for _ in range(index):
      curr = curr.next
    return curr.val

  def addAtHead(self, val: int) -> None:
    curr = self.dummy.next
    self.dummy.next = ListNode(val)
    self.dummy.next.next = curr
    self.length += 1

  def addAtTail(self, val: int) -> None:
    curr = self.dummy
    while curr.next:
      curr = curr.next
    curr.next = ListNode(val)
    self.length += 1

  def addAtIndex(self, index: int, val: int) -> None:
    if index > self.length:
      return
    curr = self.dummy
    for _ in range(index):
      curr = curr.next
    temp = curr.next
    curr.next = ListNode(val)
    curr.next.next = temp
    self.length += 1

  def deleteAtIndex(self, index: int) -> None:
    if index < 0 or index >= self.length:
      return
    curr = self.dummy
    for _ in range(index):
      curr = curr.next
    temp = curr.next
    curr.next = temp.next
    self.length -= 1
