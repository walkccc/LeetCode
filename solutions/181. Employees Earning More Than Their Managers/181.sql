SELECT Worker.name AS Employee
FROM Employee AS Worker
INNER JOIN Employee AS Manager
  ON (Worker.managerId = Manager.id)
WHERE Worker.salary > Manager.salary;
