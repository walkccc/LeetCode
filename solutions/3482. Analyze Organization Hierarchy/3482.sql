WITH RECURSIVE
  EmployeeHierarchy AS (
    -- Base case: direct reports to CEO
    SELECT
      employee_id,
      employee_name,
      manager_id,
      salary,
      1 AS level
    FROM Employees
    WHERE manager_id IS NULL
    UNION ALL
    -- Recursive case: reports of reports
    SELECT
      Employees.employee_id,
      Employees.employee_name,
      Employees.manager_id,
      Employees.salary,
      EmployeeHierarchy.level + 1
    FROM Employees
    INNER JOIN EmployeeHierarchy
      ON (Employees.manager_id = EmployeeHierarchy.employee_id)
  ),
  -- Calculate team size and budget for each employee
  TeamSizeAndBudget AS (
    WITH RECURSIVE
      -- Get all subordinates (direct and indirect)
      Subordinates AS (
        -- Base case: direct reports
        SELECT
          manager_id,
          employee_id,
          salary
        FROM Employees
        WHERE manager_id IS NOT NULL
        UNION ALL
        -- Recursive case: indirect reports
        SELECT
          Subordinates.manager_id,
          Employees.employee_id,
          Employees.salary
        FROM Employees
        INNER JOIN Subordinates
          ON (Employees.manager_id = Subordinates.employee_id)
      )
    SELECT
      Employees.employee_id,
      COUNT(DISTINCT Subordinates.employee_id) AS team_size,
      IFNULL(SUM(Subordinates.salary), 0) + Employees.salary AS total_budget
    FROM Employees
    LEFT JOIN Subordinates
      ON (Employees.employee_id = Subordinates.manager_id)
    GROUP BY Employees.employee_id, Employees.salary
  )
SELECT
  EmployeeHierarchy.employee_id,
  EmployeeHierarchy.employee_name,
  EmployeeHierarchy.level,
  IFNULL(TeamSizeAndBudget.team_size, 0) AS team_size,
  IFNULL(TeamSizeAndBudget.total_budget, EmployeeHierarchy.salary) AS budget
FROM EmployeeHierarchy
LEFT JOIN TeamSizeAndBudget
  USING (employee_id)
ORDER BY
  EmployeeHierarchy.level,
  TeamSizeAndBudget.total_budget DESC,
  EmployeeHierarchy.employee_name;
