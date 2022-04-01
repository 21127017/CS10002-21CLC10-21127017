# CS10002-21CLC10-21127017
Công việc tuần 07(tính theo số lab ktlt th):
- Bảo: thiết kế danh sách.
- Trà: Design.
- Anh: Lưu trữ dữ liệu (speed :v).
            ~~Gần xong rồi cố lên mn ơi!!!

Công việc đã hoàn thành:
- Bảo:
    + Thiết kế khung sườn đồ án (Struct và các hàm cần thiết).
    + Tạo năm học mới.
    + Tạo học kì mới.
    + Thêm môn học.
    + Thêm học sinh thủ công.
    + Thêm lớp học.
    + Tạo giao diện thao tác cơ bản.
    + Hàm xoá các danh sách liên kết đã sử dụng.
    + Hiển thị danh sách sinh viên (chưa qua thiết kế).
    + Thêm các điều kiện ràng buộc cơ bản(vd: không thể tạo thêm năm học mới nếu chưa tạo đủ 3 kì).
    + Nhập điểm cho học sinh.
    + Xoá môn học.
    + Xoá học sinh.
    + Thay đổi điểm của học sinh.
    + Xem thông tin 1 môn học.
    + view list of student in class.
    + view list of class.
    + view list of course.
    + View list of student in a course.
    + View a list of his/her scoreboard.
    + View list of enrolled course.
    + View the scoreboard of a course.
    + Profile
- Trà:
    + Thiết kế giao diện login
    + Đăng nhập, đổi mật khẩu
    + Thiết kế giới hạn giao diện, hàm vẽ khung
    + Hàm Lưu trữ dữ liệu tài khoản mật khẩu.
    + Thiết kế giao diện menu giáo vụ
    + Hàm di chuyển con trỏ bằng bàn phím
- Anh:
    + Hàm hiện/ẩn con trỏ
    + Hàm đăng kí môn học cho sinh viên
    + Hàm hủy đăng kí môn học cho sinh viên
    + Hàm lưu thông tin học sinh
    + Hàm lưu trữ dữ liệu giảng viên.


Các công việc còn lại
- Tạo fie csv.
- Viết hàm ràng buộc dữ liệu đầu vào.
- Hàm lưu trữ dữ liệu tổng hợp.(Tuấn Anh).


----------------------------------------------------------------------------
PHẦN THIẾT KẾ:
- Profile: // Bao
    + Truyền vào role, *pstudent, *staff.
    + Tụi em xác định vai trò là gv hay học sinh bằng biến role, cụ thể nếu role = 1 là gv, role = 2 là hs.
    + In ra thông tin dựa vào 2 list đã truyền vào (Bố cục như hôm bữa trong zoom em có nói sơ qua).
    + Truyền vào biến &choice trả lại 1 hoặc 2 (1 là đổi pass 2 là back to menu).

- (DONE) view list of class (phần này mình hiện về danh sách các lớp có trong kì hiện tại):
    + Truyền vào *pclass, *pstudent, year, semester.
    + Theo bố cục từ trái sang phải: STT, Tên lớp, Số lượng học sinh của mỗi lớp (phần này  chạy trâu cái list học sinh để đếm số học sinh có class là lớp mình đang xuất rồi đếm nha).

- (DONE) view list of student in class (phần này hiển thị danh sách học sinh của 1 lớp):
    + Truyền vào classid(biến này dùng để so với pstudent -> classroom để in học sinh ra), *pstudent.
    + Từ trái sang phải: STT, tên học sinh (first_name + last_name), id, ngày sinh (dob.year, dob.month, dob.day), giới tính.

- (DONE) view list of course:  
    + Truyền vào: *psubject, *pstudent
    + In từ trái sang phải: course_id, namne, teacher, num of creadits, Month start(start), month end(end), session[1], session[2], num of enroll / maximum (num of enroll được tính bằng cách chạy trâu list pstudent đếm xem đứa nào có học môn đấy).

- (DONE) View list of student in a course: 
    + Truyền biến id_subject, *pstudent
    (Mặc định là mình đã có id của môn học cần in là id_course, để in số học sinh mình cần so id_course với 
    pstudent -> sub2 -> course_id)
    + Từ trái sang phải: STT, tên học sinh (first_name + last_name), id, ngày sinh (dob.year, dob.month, dob.day), giới tính.

- Export list of student in a course to cvs file:
    + Tương tự với view list of student, khác là thay vì xuất ra console mình in ra file CSV ^^!

- (DONE) View the scoreboard of a course: 
    + Truyền biến id_course, *pstudent
    (Mặc định mình đã có môn học cần tra là id_course, mình so nó với pstudent -> psub2 -> course_id)
    + Từ trái sang phải: Tên hs (fisrt_name + last_name), id, classroom, psub2 -> score

- View scoreboard of a class: update sau.

- (DONE) View list of enrolled course (in ra môn học đã đăng ký của một học sinh): 
    + Truyền id_student, *pstudent, *psubject
    (So sáng id_student với pstudent -> id để tìm ra hs cần in, sau đó so sánh pstudent -> psub2 -> course_id với psubject -> courseid để in ra các thông tin về môn học)
    + STT, Tên Môn học, Id môn học, giảng viên, Month start, month end, num of creadits.

- (DONE) View a list of his/her scoreboard: 
    + Truyền id_student, *pstudent, *psubject
    (dùng id_student so với pstudent -> id để kiếm học sinh cần in)
    + Chạy list psub2 in tên môn học, tín chỉ, Month start, month end, điểm số .
    (lấy tên môn học bằng cách tra course_id từ psub2 với course_id từ psubject).
    + Con update


