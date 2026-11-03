class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> answer;
        int sum = 0;
        for (const string& operation : operations) {
            if (operation == "+") {
                // assert at least have 2 score
                int temp = answer[answer.size()-1] + answer[answer.size()-2];
                sum += temp;
                answer.push_back(temp);
            }
            else if (operation == "D") {
                // assert at least have 1 score
                int temp = 2 * answer.back();
                sum += temp;
                answer.push_back(temp);
            }
            else if (operation == "C") {
                // assert at least have 1 score
                int temp = answer.back();
                sum -= temp;
                answer.pop_back();
            }
            else {
                int temp = std::stoi(operation);
                sum += temp;
                answer.push_back(temp);
            }
        }
        return sum;
    }
};