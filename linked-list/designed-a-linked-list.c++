class Node{
public:
    int val;
    Node *next;
    Node()
    {
        val=0;
        next=NULL;
    }
    Node(int n)
    {
        this->val=n;
        next=NULL;
    }
};
class MyLinkedList {
public:
    int size=0;
    Node *head= new Node();//關鍵在於這個head 並沒有任何值 
//不是真正的linked list開頭 而是一個指向linked list 的指標
    MyLinkedList() {
        //
    }
    
    int get(int index) {
        /*if(index >= size)
            return -1;
        Node *temp=Head->next;
        for(int i=0;i<index;i++)
        {
            temp=temp->next;
        }
        return temp->val;*/
         if(index>=size) return -1;
        Node* temp=head->next;
        for(int i=0;i<index;i++) temp=temp->next;
        return temp->val;
    }
    
    void addAtHead(int val) {
        /*Node *temp=new Node(val);
        temp->next=head;
        head=temp;
        cout << "head->val=" << head->val;
        size++;*/
        Node* temp=head->next;
        head->next=new Node(val);
        head->next->next=temp;
        size++;
    }
    
    void addAtTail(int val) {
        Node *temp=head;
       while(temp->next!=NULL){
           temp=temp->next;
       }
        temp->next= new Node(val);
        
        size++;
    }
    
    void addAtIndex(int index, int val) {
         if(index>size) return;
        Node *temp=head;
        for(int i=0;i<index;i++)
        {
            temp=temp->next;//會指到前一個，有多算一個head
        }
        Node *temp2=temp->next;
        temp->next= new Node(val);
        //temp2->next=temp->next->next;//錯誤寫法
        temp->next->next=temp2;
        size++;
    }
    
    void deleteAtIndex(int index) {
         if(index>=size) return;
        Node *temp=head;
        for(int i=0;i<index;i++)
        {
            temp=temp->next;
        }
        //Node *temp2=temp->next;//錯誤解法
        //temp->next=temp->next->next;//錯誤寫法
        cout << "index="<<index<<"\t val="<<temp->val <<endl;
        Node *temp2=temp->next;
        temp->next=temp2->next;
        temp2->next=NULL;
        
        delete temp2;
        
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
