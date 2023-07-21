class Solution {
public:
    int BS(long long int x,long long int low, long long int high){
        int ans=0;
        while(low<=high){
            long long int mid=(low+high)/2;
            if(mid*mid==x){
                return mid;
            }
            else if(mid*mid>x){
                high=mid-1;
            }
            else if(mid*mid<x){
                ans=mid;
                low=mid+1;
            }
        }
        return ans;
    }
    int mySqrt(int x) {
        if(x==0){
            return x;
        }
        return BS(x,1,x);
    }
};