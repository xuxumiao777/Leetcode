class MyLinkedList {
public:
    struct node{//单链表节点结构
        int val;//数据域
        node *next;//指针域
        node(int x): val(x),next(NULL){}//表示的含义就是节点数值为x，指针为空（初始化一个新节点）
    };

    MyLinkedList() {
        head=new node(0);
        size=0;
  
    }
    
    int get(int index) {
        if(index<0||index>size-1)
        {
            return -1;
        }
        node *cur=head->next;
        while(index--)
        {
            cur=cur->next;
        }
        return cur->val;

    }
    
    void addAtHead(int val) {
        node *newhead=new node(val);
        newhead->next=head->next;
        head->next=newhead;
        size++;


    }
    
    void addAtTail(int val) {
        node *newtail=new node(val);
        node *cur=head;
        while(cur->next){
            cur=cur->next;
        }
        newtail->next=cur->next;
        cur->next=newtail;
        size++;

    }
    
    void addAtIndex(int index, int val) {
        
        if(index<=0) addAtHead(val);//插入index的时候，如果下标是=0,就相当于从头插入，所以要包含<=
        else if(index==size) addAtTail(val);
        else if(index>size) return ;
        else{
            node *newnode=new node(val);
            node *cur=head;//辅助指针从头指针开始
            while(index--) cur=cur->next;//遍历到第index-1的节点，循环次数是index次 但是辅助指针是从头指针开始而不是第一个节点
            newnode->next=cur->next;//连接index
            cur->next=newnode;//连接前一个
            size++;//长度+1
        }

        

    }
    
    void deleteAtIndex(int index) {
        if(index<0||index>=size) return ;
        node *cur=head;//从头指针开始
        while(index--){//遍历到index-1的位置,循环次数是index次
            cur=cur->next;
        }
        cur->next = cur->next->next;//相当于直接跨过了index节点
        size--;

    }
private://私人函数定义
    int size;//表示链表长度
    node *head;//定义头指针

};


  //Your MyLinkedList object will be instantiated and called as such:
  //MyLinkedList* obj = new MyLinkedList();
  //int param_1 = obj->get(index);
  //obj->addAtHead(val);
 // obj->addAtTail(val);
 // obj->addAtIndex(index,val);
 // obj->deleteAtIndex(index);
 