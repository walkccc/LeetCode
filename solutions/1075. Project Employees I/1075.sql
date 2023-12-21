SELECT
  Project.project_id,
  ROUND(AVG(Employee.experience_years), 2) AS average_years
FROM Project
INNER JOIN Employee
  USING (employee_id)
GROUP BY 1;
