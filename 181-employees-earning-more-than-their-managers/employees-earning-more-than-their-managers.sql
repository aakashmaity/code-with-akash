# Write your MySQL query statement below
select e1.name AS Employee
From Employee e1
Inner join Employee e2
on e1.managerId=e2.id
where e1.salary > e2.salary