class Solution {
public:
    vector<string> res;
    string combination; 
    unordered_map<int,string> hashmap{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    void backtrack(vector<string> &res,string &combination,int index,string digits){
        if(index==digits.size()){
            res.push_back(combination);
            return;
        }
        for(auto character:hashmap[digits[index]]){
            combination.push_back(character);
            backtrack(res,combination,index+1,digits);
            combination.pop_back();
        }



    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0){
            return res;
        }
        backtrack(res,combination,0,digits);
        return res;



    }
};