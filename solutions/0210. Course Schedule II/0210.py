class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        def hasCycle(course: int) -> bool:
            if state[course] == 1:
                return True
            if state[course] == 2:
                return False

            state[course] = 1
            for neighbor in graph[course]:
                if hasCycle(neighbor):
                    return True
            state[course] = 2
            ans.append(course)

            return False

        ans = []
        graph = [[] for _ in range(numCourses)]
        state = [0] * numCourses

        for a, b in prerequisites:
            graph[b].append(a)

        for course in range(numCourses):
            if hasCycle(course):
                return []

        return ans[::-1]
