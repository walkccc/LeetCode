WITH
  EmployeesWithMaxSalaryInDepartment AS (
    SELECT
      Department.name AS department,
      Employee.name AS employee,
      Employee.salary,
      MAX(Employee.salary) OVER(
        PARTITION BY Employee.departmentId
      ) AS max_salary
    FROM Employee
    LEFT JOIN Department
      ON (Employee.departmentId = Department.id)
  )
SELECT
  department AS Department,
  employee AS Employee,
  salary AS Salary
FROM EmployeesWithMaxSalaryInDepartment
WHERE salary = max_salary;
