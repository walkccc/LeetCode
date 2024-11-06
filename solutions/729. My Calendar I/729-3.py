from dataclasses import dataclass


@dataclass
class Node:
  start: int
  end: int
  left = None
  right = None


class Tree:
  def __init__(self):
    self.root = None

  def insert(self, node: Node, root: Node = None) -> bool:
    if not root:
      if not self.root:
        self.root = node
        return True
      else:
        root = self.root

    if node.start >= root.end:
      if not root.right:
        root.right = node
        return True
      return self.insert(node, root.right)
    elif node.end <= root.start:
      if not root.left:
        root.left = node
        return True
      return self.insert(node, root.left)
    else:
      return False


class MyCalendar:
  def __init__(self):
    self.tree = Tree()

  def book(self, start: int, end: int) -> bool:
    return self.tree.insert(Node(start, end))
