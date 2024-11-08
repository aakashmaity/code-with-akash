# Write your MySQL query statement below
SELECT e1.employee_id,e1.name, count(e1.employee_id) as reports_count, ROUND(AVG(e2.age)) as average_age
FROM Employees e1
INNER JOIN Employees e2
on e1.employee_id = e2.reports_to
group by e2.reports_to
order by e1.employee_id