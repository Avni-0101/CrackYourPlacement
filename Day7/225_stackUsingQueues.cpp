#include<bits/stdc++.h>
using namespace std;

class MyStack {
public:
    queue<int> q1,q2;

    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);    
    }
    
    int pop() {
        int top=-1;
        if(q1.empty())
        {
            while(q2.size()>1)
            {
                top = q2.front();
                q1.push(top);
                q2.pop();
            }
            if(q2.size()==1)
            {
                top = q2.front();
                q2.pop();
            }
        }
        else
        {
            while(q1.size()>1)
            {
                top = q1.front();
                q2.push(top);
                q1.pop();
            }
            if(q1.size()==1)
            {
                top = q1.front();
                q1.pop();
            }
        }
        return top;
    }
    
    int top() {
        int top=-1;
        if(q1.empty())
        {
            while(!q2.empty())
            {
                top = q2.front();
                q1.push(top);
                q2.pop();
            }
        }
        else
        {
            while(!q1.empty())
            {
                top = q1.front();
                q2.push(top);
                q1.pop();
            }
        }
        return top;
    }
    
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */