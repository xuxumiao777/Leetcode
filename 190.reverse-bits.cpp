class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res;
        for(int i=0;i<32;i++){
            
            res=res<<1|(n&1);
            //cout<<res<<endl;
            n=n>>1;
        }
        return res;
    }
};