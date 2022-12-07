class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int sum1=0,sum2=0;
        unordered_map<int,int> hash_s1;
        unordered_map<int,int> hash_s2;
        for(auto num:nums1){
            sum1+=num;
            hash_s1[num]++;
        }
        for(auto num:nums2){
            sum2+=num;
            hash_s2[num]++;
        }
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int diff=sum1-sum2;
        //如果diff大于0，那么nums1该减小，或nums2应该增大，按照贪心的思路，应该先减小nums1里的大数或增加nums2里的小数
        if(diff==0){
            return 0;
        }
        int res=0;
        int adjust_num=0;
        int adjust_max=0;
        int adjust_step=0;
        cout<<diff<<endl;
        if(diff>0){
            for(int i=1;i<=6;i++){
                adjust_num=hash_s1[7-i]+hash_s2[i];
                adjust_step=6-i;
                adjust_max=adjust_num*adjust_step;
                cout<<"i"<<i<<"adjust_max"<<adjust_max<<endl;
                if(diff<=adjust_max){
                    res+=(diff%adjust_step)?(diff/adjust_step)+1:diff/adjust_step;
                    //cout<<"i"<<i<<"adjust_max"<<adjust_max<<endl;
                    return res;
                }
                else{
                    diff-=adjust_max;
                    res+=adjust_num;
                }
            }
        }
        //如果diff小于0，那么nums1该增大，或nums2应该减小，按照贪心的思路，应该先增大nums1里的小数或减小nums2里的大数
        else if(diff<0){
            diff=-1*diff;
            for(int i=1;i<=6;i++){
                adjust_num=hash_s1[i]+hash_s2[7-i];
                adjust_step=6-i;
                adjust_max=adjust_num*adjust_step;
                //cout<<"i"<<i<<"adjust_max"<<adjust_max<<endl;
                if(diff<=adjust_max){
                    res+=(diff%adjust_step)?(diff/adjust_step)+1:diff/adjust_step;
                    return res;
                }
                else{
                    diff-=adjust_max;
                    res+=adjust_num;
                }
            }
        }
        return -1;
    }
};
