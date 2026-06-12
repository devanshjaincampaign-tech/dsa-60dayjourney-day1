class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalcolor=image[sr][sc];
        if(originalcolor==color)return image;

        int rows=image.size();
        int cols=image[0].size();

        queue<pair<int,int>>q;
        q.push({sr,sc});
        image[sr][sc]=color;

        int dRow[]={-1,1,0,0};
        int dcol[]={0,0,-1,1};

        while(!q.empty()){
            auto[r,c]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nRow=r+dRow[i];
                int ncol=c+dcol[i];

                if(nRow>=0 && nRow<rows && ncol>=0 && ncol<cols &&image[nRow][ncol]==originalcolor){
                    image[nRow][ncol]=color;
                    q.push({nRow,ncol});
                }
            }
        }
        return image;
    }
};