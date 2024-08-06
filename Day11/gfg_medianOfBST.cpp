void inorder(struct Node* root,vector<int> &arr)
{
    if(root==NULL)return;
    
    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}
float findMedian(struct Node *root)
{
      vector<int> arr;
      inorder(root,arr);
      int mid = arr.size()/2;
      float median;
      
      if(arr.size()%2!=0)   median = arr[mid];
      
      else median = (arr[mid]+arr[mid -1])/2.0;
      
      return median;
}