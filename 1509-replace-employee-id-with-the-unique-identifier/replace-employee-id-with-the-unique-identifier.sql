# Write your MySQL query statement below
SELECT euni.unique_id,e.name
FROM EmployeeUNI AS euni
RIGHT JOIN Employees AS e
ON e.id=euni.id