class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        // code here
        long long num1=0,num2=0,ans;
        long long mod = 1e9 + 7;
        
        while(first!=NULL)
        {
            num1= (num1*10)%(mod);
            num1+=first->data;
            first=first->next;
        }
        
        while(second!=NULL)
        {
            num2= (num2*10)%(mod);
            num2+=second->data;
            second=second->next;
        }
        
        ans = num1*num2;
        return ans%mod;
    }
};