select s.student_id,s.student_name, sj.subject_name,count(e.student_id) as attended_exams
from students as s 
cross join subjects as sj
left join examinations as e
on s.student_id = e.student_id
and sj.subject_name = e.subject_name
group by 1,2,3
order by 1,3
;