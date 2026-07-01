class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(),tiles.end());
        int n = tiles.size();
        int ans = 0;
        int cover = 0;
        int j = 0;
        for(int i = 0;i<n;i++){
            int carpetEnd = tiles[i][0] + carpetLen - 1;
            while(j < n && tiles[j][1] <= carpetEnd){
                cover += tiles[j][1] - tiles[j][0] + 1;
                j++;
            }
            int partial = 0;
            if(j < n && tiles[j][0] <= carpetEnd){
                partial = carpetEnd - tiles[j][0] + 1;
            }
            ans = max(ans,cover + partial);
            cover -= tiles[i][1] - tiles[i][0] + 1;
        }
        return ans;
    }
};