WITH
  MandatoryMajors AS (
    SELECT major, COUNT(course_id) AS course_count
    FROM Courses
    WHERE mandatory = 'Yes'
    GROUP BY 1
  ),
  StudentsMetadata AS (
    SELECT
      Students.student_id,
      Students.major,
      SUM(
        Students.major = Courses.major
        AND Courses.mandatory = 'YES'
        AND Enrollments.grade = 'A'
      ) AS mandatory_grade_a_count,
      SUM(
        Students.major = Courses.major
        AND Courses.mandatory = 'No'
      ) AS elective_count,
      ROUND(
        SUM(Enrollments.GPA * Courses.credits) / SUM(Courses.credits),
        1
      ) AS avg_gpa
    FROM Students
    INNER JOIN Enrollments
      USING (student_id)
    INNER JOIN Courses
      USING (course_id)
    GROUP BY 1
  )
SELECT StudentsMetadata.student_id
FROM StudentsMetadata
INNER JOIN MandatoryMajors
  ON (
    StudentsMetadata.major = MandatoryMajors.major
    AND StudentsMetadata.mandatory_grade_a_count = MandatoryMajors.course_count)
WHERE StudentsMetadata.avg_gpa >= 2.5 AND StudentsMetadata.elective_count >= 2
ORDER BY 1;
