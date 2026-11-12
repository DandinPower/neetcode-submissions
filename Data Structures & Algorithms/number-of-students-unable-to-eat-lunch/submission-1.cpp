class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        size_t check_counter = 0;
        int sandwitch_head_index = 0;
        deque<int> students_queue(students.begin(), students.end());
        // deque<int> students_queue(
        //     std::make_move_iterator(students.begin()),
        //     std::make_move_iterator(students.end())
        // ); 這個寫法在 int 的情況沒意義，內容物是 string, buffer 等 data 才有意義
        while (students_queue.size() != 0 && check_counter != students_queue.size()) {
            if (students_queue.front() == sandwiches[sandwitch_head_index]) {
                students_queue.pop_front();
                sandwitch_head_index += 1;
                check_counter = 0;
            }
            else {
                int temp_student = students_queue.front();
                students_queue.pop_front();
                students_queue.push_back(temp_student);
                check_counter += 1;
            }
        }
        return students_queue.size();
    }
};