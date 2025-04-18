WITH
  EmployeesWithAvgWorkload AS (
    SELECT
      Employees.employee_id,
      Employees.name AS employee_name,
      Project.project_id,
      Project.workload AS project_workload,
      AVG(workload) OVER(PARTITION BY team) AS avg_team_workload
    FROM Project
    INNER JOIN Employees
      USING (employee_id)
)
SELECT
  employee_id,
  project_id,
  employee_name,
  project_workload
FROM EmployeesWithAvgWorkload
WHERE project_workload > avg_team_workload
ORDER BY 1, 2;
