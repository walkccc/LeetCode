SELECT
  Students.id,
  Students.name
FROM Students
LEFT JOIN Departments
  ON (Students.department_id = Departments.id)
WHERE Departments.id IS NULL;
