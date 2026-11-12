class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int student_counts[2] = {0, 0};
        for (int student: students) {
            student_counts[student] += 1;
        }

        size_t i;
        for (i=0; i < sandwiches.size(); i++) {
            if (student_counts[sandwiches[i]] > 0) {
                student_counts[sandwiches[i]] -= 1;
            }
            else {
                break;
            }
        }

        return sandwiches.size() - i;
    }
};