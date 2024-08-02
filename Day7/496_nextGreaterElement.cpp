class Solution {
public:
    int nextGreater(int n, vector<int> &num2)
    {
        int ans=-1,temp;
        for(int i=0;i<num2.size();i++)
        {
            if(n == num2[i])
            {
                temp = i;
            }
        }
        
        for(int i=temp+1;i<num2.size();i++)
        {
            if(num2[i]>n)
            {
                ans=num2[i];
                break;
            }
        }
        return ans;
    } 

    vector<int> nextGreaterElement(vector<int>& num1, vector<int>& num2) {
        vector<int>res;
        for(int i=0;i<num1.size();i++)
        {
            res.push_back(nextGreater(num1[i],num2));
        }
        return res;
    }
};