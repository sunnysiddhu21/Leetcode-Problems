class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int x) {
        int n=matrix.size();
        int m=matrix[0].size();
        if(n==0 || m==0) return -1;
    
        int row = 0, col = m-1;
        while(row < n && col >= 0){
            if(matrix[row][col] == x) return 1;
            else if(matrix[row][col] < x) row++;
            else if(matrix[row][col] > x) col--;
        }
        return 0;
    }
};