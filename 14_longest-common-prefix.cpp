class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int min_len = strs[0].length();
        for (int k = 0; k < strs.size(); k++)
        {
            min_len = min_len < strs[k].length() ? min_len : strs[k].length();
        }

        
        int len_vector=strs.size();
        string str_new;
        int i=0;
        int f=-1;
        for(int i=0;i<min_len;i++){//每一个str的长度
            for(int j=0;j<len_vector;j++){//vec中所有str的数量
                if(strs[0][i]!=strs[j][i]){
                    f=i;
                    break;
                    
                }         
            }
            if(f!=-1){
                break;
            }           
            
            //str_new.push_back(strs[0][i]);
        }
        if(f==-1){
            str_new=strs[0].substr(0,min_len);
        }
        else{
            str_new=strs[0].substr(0,f);
        }

    return str_new;
    }
};