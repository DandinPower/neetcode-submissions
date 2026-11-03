class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> answer;
        int sum = 0;
        int temp = -1;
        for (string operation : operations) {
            if (operation == "+") {
                // assert at least have 2 score
                temp = answer[answer.size()-1] + answer[answer.size()-2];
                sum += temp;
                answer.push_back(temp);
            }
            else if (operation == "D") {
                // assert at least have 1 score
                temp = 2 * answer[answer.size()-1];
                sum += temp;
                answer.push_back(temp);
            }
            else if (operation == "C") {
                // assert at least have 1 score
                temp = answer[answer.size()-1];
                sum -= temp;
                answer.pop_back();
            }
            else {
                temp = std::stoi(operation);
                sum += temp;
                answer.push_back(temp);
            }
        }
        return sum;
    }
};