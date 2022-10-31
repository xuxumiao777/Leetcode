class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int result_forward=0,result_backward,sum=0;
        for(int i=0;i<distance.size();i++){
            sum+=distance[i];
            
        }
        cout<<sum<<endl;
        if(start>destination){
            swap(start,destination);
        }
        if(start==destination){
            return 0;
        }
        
        //result_forward+=distance[start];
        while(start!=destination){
            result_forward+=distance[start];
            start++;
        }
            //return result_forward<0.5*sum?result_forward:(sum-result_forward);
        

        return result_forward<(0.5*sum)?result_forward:(sum-result_forward);

    }
};