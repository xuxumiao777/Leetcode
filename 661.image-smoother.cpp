class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> res(img);
        int m=img.size();
        int n=img[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int count=0;
                int first_ele=(i-1>=0&&j-1>=0)?img[i-1][j-1]:0;
                //cout<<first_ele;
                int second_ele=(i-1>=0&&j>=0)?img[i-1][j]:0;
                cout<<second_ele;
                int third_ele=(i-1>=0&&j+1<n)?img[i-1][j+1]:0;
                //cout<<third_ele;
                int forth_ele=(i>=0&&j-1>=0)?img[i][j-1]:0;
                //cout<<forth_ele;
                int fifth_ele=(i>=0&&j>=0)?img[i][j]:0;
                //cout<<fifth_ele;
                int sixth_ele=(i>=0&&j+1<n)?img[i][j+1]:0;
                //cout<<sixth_ele;
                int seventh_ele=(i+1<m&&j-1>=0)?img[i+1][j-1]:0;
                //cout<<seventh_ele;
                int eighth_ele=(i+1<m&&j>=0)?img[i+1][j]:0;
                //cout<<eighth_ele;
                int ninth_ele=(i+1<m&&j+1<n)?img[i+1][j+1]:0; 
                //cout<<ninth_ele;   
                count+=(i-1>=0&&j-1>=0)?1:0;
                count+=(i-1>=0&&j>=0)?1:0;
                count+=(i-1>=0&&j+1<n)?1:0;
                count+=(i>=0&&j-1>=0)?1:0;
                count+=(i>=0&&j>=0)?1:0;
                count+=(i>=0&&j+1<n)?1:0;
                count+=(i+1<m&&j-1>=0)?1:0;
                count+=(i+1<m&&j>=0)?1:0;
                count+=(i+1<m&&j+1<n)?1:0;  
                //cout<<count;                          
                res[i][j]=(first_ele+second_ele+third_ele+forth_ele+fifth_ele+sixth_ele+seventh_ele+eighth_ele+ninth_ele)/count;
                //cout<<res[i][j];
            }
        }
        return res;
    }
};
