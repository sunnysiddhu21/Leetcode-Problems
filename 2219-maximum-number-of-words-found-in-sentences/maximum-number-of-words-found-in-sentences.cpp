class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxi = 0;

        for (const string& sentence : sentences) {
            // Count spaces and add 1 to get the word count
            int wordCount = count(sentence.begin(), sentence.end(), ' ') + 1;
            maxi = max(maxi, wordCount);
        }

        return maxi;
    }
};
