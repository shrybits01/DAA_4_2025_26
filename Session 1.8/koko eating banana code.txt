class Solution {
public:
    int sum(vector<int>& piles, int n){
        int count=0;
        for(int i=0;i<piles.size();i++){
            if(piles[i]%n==0){
                count+=piles[i]/n;
            }else{
                count+=(piles[i]/n)+1;
            }
        }
        return count;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int a=1;
        int b=*max_element(piles.begin(), piles.end());
        while(a<b){
            int mid =(a+b)/2;
            if(sum(piles,mid)>h){
                a=mid+1;
            }else{
                b=mid;
            }
        }
        return a;
    }
};