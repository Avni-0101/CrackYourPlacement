class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    
    sort(a.begin(),a.end());
    long long start=0;
    long long end=m-1;
    long long minDiff = INT_MAX;
    
    while(end<a.size())
    {
        long long diff = a[end]-a[start];
        minDiff = min(diff,minDiff);
        start++;end++;
    }
        
        return minDiff;
    }   
};