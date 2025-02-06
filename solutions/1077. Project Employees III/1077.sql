WITH
  RankedProjectToEmployee AS (
    SELECT
      Project.project_id,
      Project.employee_id,
      RANK() OVER(
        PARTITION BY Project.project_id
        ORDER BY Employee.experience_years DESC
      ) AS `rank`
    FROM Project
    INNER JOIN Employee
      USING (employee_id)
  )
SELECT project_id, employee_id
FROM RankedProjectToEmployee
WHERE `rank` = 1;
