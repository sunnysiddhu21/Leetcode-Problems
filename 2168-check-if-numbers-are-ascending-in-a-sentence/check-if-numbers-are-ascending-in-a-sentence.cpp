class Solution {
public:
    bool areNumbersAscending(string s) {
        int prev_num = -1;  
        stringstream ss(s);
        string word;

        while (ss >> word) {
            
            if (isdigit(word[0])) {
                int current_num = stoi(word);  
                
                
                if (current_num <= prev_num) {
                    return false;
                }
                prev_num = current_num;  
            }
        }

        return true;
    }
};
