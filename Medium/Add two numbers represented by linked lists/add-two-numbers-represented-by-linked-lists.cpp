//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
   Node *reverse(Node *head){
        if(head==NULL or head->next==NULL) return head;
        Node *prev=NULL;
        Node *curr=head;
        Node *temp=NULL;
        while(curr){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
        // code here
       Node *l1=reverse(num1);
       Node *l2=reverse(num2);
       
       
       Node *dummy=new Node(-1);
       Node *curr=dummy;
       int carry=0;
       while(l1 or l2 or carry){
            int sum=carry;
            if(l1){
                sum=sum+l1->data;
                l1=l1->next;
            }
            if(l2){
                sum=sum+l2->data;
                l2=l2->next;
            }
            Node *temp=new Node(sum%10);
            carry=sum/10;
            curr->next=temp;
            curr=curr->next;
       }
       Node *head=reverse(dummy->next);
       
       while(head->next!=NULL and head->data==0 ){
           head=head->next;
       }
       return head;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends