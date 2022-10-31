class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map <string,int> hashmap;
        int sum_index=list1.size()+list2.size()+2;
        vector<string> result;
        
        for(int i=0;i<list1.size();i++){
            hashmap[list1[i]]=i;
        }
        for(int j=0;j<list2.size();j++){
            if(hashmap.count(list2[j])>0){
                if(j+hashmap[list2[j]]<sum_index){
                    sum_index=j+hashmap[list2[j]];
                    result.clear();
                    result.push_back(list2[j]);

                }
                else if(j+hashmap[list2[j]]==sum_index){
                    result.push_back(list2[j]);
                }

            }

        }
        return result;

    }
};