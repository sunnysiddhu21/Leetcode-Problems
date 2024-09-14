class Solution {
public:
    bool areNumbersAscending(string s) {
        int prev_num = -1;  // Start with a number smaller than any valid number in the string
        stringstream ss(s);
        string word;

        while (ss >> word) {
            // Check if the word represents a number
            if (isdigit(word[0])) {
                int current_num = stoi(word);  // Convert string to integer
                
                // Compare with the previous number
                if (current_num <= prev_num) {
                    return false;
                }
                prev_num = current_num;  // Update the previous number
            }
        }

        return true;
    }
};
