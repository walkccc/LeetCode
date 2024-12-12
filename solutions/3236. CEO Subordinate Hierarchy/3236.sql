WITH
  RECURSIVE EmployeeHierarchy AS (
    -- Base case: direct reports to CEO
    SELECT
      employee_id,
      employee_name,
      salary,
      1 AS hierarchy_level
    FROM Employees
    WHERE manager_id = (
        SELECT employee_id
        FROM Employees
        WHERE manager_id IS NULL
      )
    UNION ALL
    -- Recursive case: reports of reports
    SELECT
      Employees.employee_id,
      Employees.employee_name,
      Employees.salary,
      EmployeeHierarchy.hierarchy_level + 1
    FROM Employees
    INNER JOIN EmployeeHierarchy
      ON (Employees.manager_id = EmployeeHierarchy.employee_id)
  ),
  Ceo AS (
    SELECT salary
    FROM Employees
    WHERE manager_id IS NULL
  )
SELECT
  EmployeeHierarchy.employee_id AS subordinate_id,
  EmployeeHierarchy.employee_name AS subordinate_name,
  EmployeeHierarchy.hierarchy_level,
  EmployeeHierarchy.salary - Ceo.salary AS salary_difference
FROM EmployeeHierarchy
CROSS JOIN Ceo
ORDER BY hierarchy_level, employee_id;
