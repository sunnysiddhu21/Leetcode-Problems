class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxi = 0;

        for(int i = 0; i < sentences.size(); i++) {
            int cnt = 1; 
            string temp = sentences[i];

            for(int j = 0; j < temp.size(); j++) {
                if(temp[j] == ' ') {
                    cnt++; 
                }
            }
            
            maxi = max(maxi, cnt);
        }

        return maxi;
    }
};
