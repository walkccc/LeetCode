SELECT
  Department.dept_name,
  COUNT(Student.student_id) AS student_number
FROM Department
LEFT JOIN Student
  USING (dept_id)
GROUP BY 1
ORDER BY 2 DESC, 1;
