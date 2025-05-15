SELECT Manager.name
FROM Employee
INNER JOIN Employee AS Manager
  ON (Employee.managerId = Manager.id)
GROUP BY Manager.id
HAVING COUNT(*) >= 5;
