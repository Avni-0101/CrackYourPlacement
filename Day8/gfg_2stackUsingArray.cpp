#include<bits/stdc++.h>
using namespace std;

class twoStacks {
  public:
    int *arr;
    int top1,top2,size;
    
    twoStacks(int n=100) {
        size=n;
        arr = new int[n];
        top1=-1;
        top2=size;
    }

    // Function to push an integer into the stack1.
    void push1(int x) {
        
        if(top1<top2-1)
        {
            top1++;
            arr[top1]=x;
        }
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        
        if(top1<top2-1)
        {
            top2--;
            arr[top2]=x;
        }
    }

    // Function to remove an element from top of the stack1.
    int pop1() {
        if(top1>=0)
        {
            int x = arr[top1];
            top1--;
            return x;
        }
        else
        {
            return -1;
        }
    }

    // Function to remove an element from top of the stack2.
    int pop2() {
        if(top2<size)
        {
            int x = arr[top2];
            top2++;
            return x;
        }
        else
        {
            return -1;
        }
    }
};


///////////////////// YE SAHI THA BUT BELOW CODE I WROTE WAS WRONG SOMEHOW ///////////////////////

class twoStacks {
  public:
    vector<int> arr;
    int top1,top2;
    int count1=0,count2=0;
    twoStacks() {
        top1=-1;    count1=0;
        top2=-1;    count2=0;
    }

    // Function to push an integer into the stack1.
    void push1(int x) {
        count1++;
        if(top1>=top2)
        {
            top1++;
            arr.push_back(x);
        }
        else
        {
            arr.push_back(arr.back());
            for(int i=arr.size()-1;i>top1+1;i--)
            {
                arr[i]=arr[i-1];
            }
            arr[top1+1]=x;
            top1++; top2++;
        }
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        count2++;
        if(top2<top1)
        {
            top2=top1+1;
            arr.push_back(x);
        }
        else
        {
            top2++;
            arr.push_back(x);
        }
    }

    // Function to remove an element from top of the stack1.
    int pop1() {
        if(!count1){  
            return -1;
        }
        else
        {
            int x = arr[top1];
            arr[top1]=-1;
            top1--; count1--;
            return x;
        }
    }

    // Function to remove an element from top of the stack2.
    int pop2() {
        if(count2)
        {
            int x = arr[top2];
            top2--; count2--;
            arr.resize(arr.size()-1);
            return x;
        }
        else
        {
            return -1;
        }
    }
};

