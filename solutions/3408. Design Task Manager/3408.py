from dataclasses import dataclass
from sortedcontainers import SortedDict, SortedSet


@dataclass(frozen=True)
class Task:
  userId: int
  taskId: int
  priority: int

  def __lt__(self, other):
    if self.priority == other.priority:
      return self.taskId > other.taskId
    return self.priority > other.priority


class TaskManager:
  def __init__(self, tasks: list[list[int]]):
    self.taskMap = SortedDict()  # {taskId: Task}, keeps tasks sorted by taskId
    self.taskSet = SortedSet()  # Stores tasks sorted by priority and taskId
    for task in tasks:
      self.add(task[0], task[1], task[2])

  def add(self, userId: int, taskId: int, priority: int) -> None:
    task = Task(userId, taskId, priority)
    self.taskMap[taskId] = task
    self.taskSet.add(task)

  def edit(self, taskId: int, newPriority: int) -> None:
    task = self.taskMap[taskId]
    self.taskSet.remove(task)
    editedTask = Task(task.userId, taskId, newPriority)
    self.taskSet.add(editedTask)
    self.taskMap[taskId] = editedTask

  def rmv(self, taskId: int) -> None:
    task = self.taskMap[taskId]
    self.taskSet.remove(task)
    del self.taskMap[taskId]

  def execTop(self):
    if not self.taskSet:
      return -1
    task = self.taskSet.pop(0)
    del self.taskMap[task.taskId]
    return task.userId
