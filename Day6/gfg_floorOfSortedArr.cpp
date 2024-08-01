class Solution {
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> &v, long long n, long long x) {

        int index=-1;
        for(long long i=0;i<n;i++)
        {
            if(v[i]<=x)
            {
                index++;
            }
            else
            {
                break;
            }
        }
        return index;
    }
};