# Ứng dụng thuật toán nhánh cận cho bài toán lập lịch sản xuất


## Mô tả

Đây là project môn Toán Rời Rạc 1, trong đó nhóm trình bày cơ sở lý thuyết về **thuật toán nhánh cận (Branch and Bound)** và ứng dụng trong việc giải bài toán **lập lịch sản xuất (production scheduling)**. Bên cạnh đó, nhóm bổ sung phiên bản **Brute-force** để so sánh hiệu quả giữa 2 phương pháp thông qua việc đánh giá thời gian chạy thực tế.

## Cấu trúc thư mục

├── branch-n-bound.cpp # Giải thuật áp dụng nhánh cận

├── brute-force.cpp # Giải thuật brute-force

├── test/ # Gồm 50 testcase, với input và output tương ứng

├── result/ # Kết quả khi cho chạy 2 chương trình trên bộ test + bản so sánh thời gian chạy

└── Thuật toán nhánh cận - Báo cáo nhóm 4.pdf # Báo cáo lý thuyết & xây dựng thuật toán

## Giải thuật sử dụng

- **Nhánh-cận (Branch and Bound):**  
  - Tại mỗi node, sử dụng **cận dưới (lower bound)** để quyết định có nên mở rộng nhánh đó.  
  - Cắt các nhánh không tiềm năng để giảm không gian tìm kiếm.  

- **Brute-force:**  
  - Liệt kê toàn bộ các phương án khả thi, sau đó chọn phương án cho hàm mục tiêu tốt nhất.  
  - Chạy chậm nhưng đảm bảo không bỏ sót trường hợp.
  
## Mô tả bộ test

Tất cả các test đều có số máy cố định (m = 10) do thời gian tính toán của bài toán này chủ yếu phụ thuộc vào số lượng chi tiết cần gia công (n).

- **Test 0 -> 9:**  3 <= n < 8.
- **Test 10 -> 19:** n = 8.
- **Test 20 -> 29:** n = 9.
- **Test 30 -> 39:** n = 10.
- **Test 40 -> 49:** n = 11.

## Kết quả so sánh

- Đối với các test n nhỏ (Test 0 -> 9, n < 8), sự khác biệt về thời gian chạy không đáng kể (đều là 0 ms).
- Khi n tăng lên, chương trình sử dụng thuật toán nhánh cận thể hiện ưu thế vượt trội về thời gian chạy.
- Ở những test cuối với n = 11, thời gian chạy trung bình của thuật toán nhánh cận gấp gần 15 lần so với brute-force.
<img width="800" height="600" alt="Screenshot 2025-11-20 234434" src="https://github.com/user-attachments/assets/c701e20a-a83c-4a6c-8b51-6fb7c4118ee6" />

