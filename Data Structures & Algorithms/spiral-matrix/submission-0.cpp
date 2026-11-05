class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> order;
        int rows = matrix.size(), cols = matrix[0].size();
        int l = 0, r = cols - 1, top = 0, bottom = rows - 1;
        while(l <= r && top <= bottom) {
            for(int col = l; col <= r; col ++) {
                order.push_back(matrix[top][col]);
            }
            for(int row = top + 1; row <= bottom; row ++) {
                order.push_back(matrix[row][r]);
            }
            if(l < r && top < bottom) {
                for(int col = r - 1; col > l; col --) {
                    order.push_back(matrix[bottom][col]);
                }
                for(int row = bottom; row > top; row --) {
                    order.push_back(matrix[row][l]);
                }
            }
            l ++;
            r --;
            top ++;
            bottom --;
        }
        return order;
    }
};