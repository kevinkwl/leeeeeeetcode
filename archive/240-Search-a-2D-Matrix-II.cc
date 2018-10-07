class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        int r = 0, c = matrix[0].size() - 1;
        while (r < matrix.size() && c >= 0) {
            if (target == matrix[r][c])
                return true;
            else if (target < matrix[r][c])
                c--;
            else
                r++;
        }
        return false;
    }

};

// divide and conquer
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        return search(matrix, 0, 0, matrix.size() - 1, matrix[0].size() - 1, target);
    }
    
    bool search(vector<vector<int>>& mat, int sr , int sc, int er, int ec, int target) {
        if (sr > er || sc > ec)
            return false;
        if (sr == er && sc == ec)
            return mat[sr][sc] == target;
        if (target < mat[sr][sc] || target > mat[er][ec])
            return false;
        
        int mr = sr + (er - sr) / 2;
        int mc = sc + (ec - sc) / 2;
        
        // try halve rows
        if (mat[mr][sc] == target || mat[mr][ec] == target)
            return true;
        else if (mat[mr][sc] > target)
            return search(mat, sr, sc, mr - 1, ec, target);
        else if (mat[mr][ec] < target)
            return search(mat, mr + 1, sc, er, ec, target);
        
        // otherwise try halve columns
        if (mat[sr][mc] == target || mat[er][mc] == target)
            return true;
        else if (mat[sr][mc] > target)
            return search(mat, sr, sc, er, mc - 1, target);
        else if (mat[er][mc] < target)
            return search(mat, sr, mc + 1, er, ec, target);
        
        // if we are here, [sr : mr][sc], [mr : er][ec], [sr][sc : mc], [er][mc : ec] can be discarded
        if (search(mat, sr + 1, sc + 1, mr, mc, target))
            return true;
        if (search(mat, sr, mc + 1, mr, ec, target))
            return true;
        if (search(mat, mr + 1, sc, er, mc - 1, target))
            return true;
        if (search(mat, mr + 1, mc, er - 1, ec - 1, target))
            return true;
        return false;
    }
};
