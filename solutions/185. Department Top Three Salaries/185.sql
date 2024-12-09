WITH
  EmployeesWithRankInDepartment AS (
    SELECT
      Department.name AS department,
      Employee.name AS employee,
      Employee.salary,
      DENSE_RANK() OVER(
        PARTITION BY Employee.departmentId
        ORDER BY Employee.salary DESC
      ) AS `rank`
    FROM Department
    INNER JOIN Employee
      ON (Department.id = Employee.departmentId )
  )
SELECT
  department AS Department,
  employee AS Employee,
  salary AS Salary
FROM EmployeesWithRankInDepartment
WHERE `rank` <= 3;
