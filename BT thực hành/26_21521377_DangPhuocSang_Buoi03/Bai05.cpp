#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node* pNext;
        Node()
        {
            data = 0;
            pNext = NULL;
        }
        void DataNode(int x);
};

void Node::DataNode(int x)
{
    this->data = x;
    this->pNext = NULL;
}

typedef class LinkedList
{
    private:
        Node *pHead, *pTail;
    public:
        LinkedList()
        {
            pHead = pTail = NULL;
        }
        void AddHead(Node *p);
        void AddTail(Node *p);
        void AddAfterQ(Node *p, Node *q);
        void OutputList();
        int LengthList();
        int FindValue(int x);
        void InsertAfterValue(int x, int y);
        void OddEven();
        int DeleteHead();
} List;

void List::AddHead(Node *p)
{
    if (pHead == NULL)
    {
        pHead = p;
        pTail = p;
    }
    else
    {
        p->pNext = pHead;
        pHead = p;
    }
}

void List::AddTail(Node *p)
{
    if (pHead == NULL)
    {
        pHead = p;
        pTail = p;
    }
    else
    {
        pTail->pNext = p;
        pTail = p;
    }
}

void List::AddAfterQ(Node *p, Node *q)
{
    if (q != NULL)
    {
        p->pNext = q->pNext;
        q->pNext = p;
        if (pTail == q) pTail = p;
    }
    else
        AddHead(p);
}

void List::OutputList()
{
    Node *temp = pHead;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->pNext;
    }
}

int List::LengthList()
{
    int length = 0;
    Node *temp = pHead;
    if (temp == NULL)
        return 0;
    while (temp != NULL)
    {
        length++;
        temp = temp->pNext;
    }
    return length;
}

int List::FindValue(int x)
{
    int location = 1;
    Node *temp = pHead;
    while (temp != NULL)
    {
        if (temp->data == x)
            return location;
        else
        {
            temp = temp->pNext;
            location++;
        }
    }
    return -1;
}

void List::InsertAfterValue(int x, int y)
{
    Node *p;
    p->DataNode(x);
    Node *temp = pHead;
    while (temp != NULL)
    {
        if (temp->data == y){
            AddAfterQ(p,temp);
            break;
        }
        temp = temp->pNext;
    }
}

void List::OddEven()
{
    int odd = 0, even = 0;
    Node *temp = pHead;
    while (temp != NULL)
    {
        if (temp->data % 2 == 0)
            even++;
        else
            odd++;
        temp = temp->pNext;
    }
    cout << "So phan tu chan la: " << even << endl;
    cout << "So phan tu le la: " << odd << endl;
}

int List::DeleteHead()
{
    if (pHead != NULL)
    {
        Node *temp = pHead;
        pHead = temp->pNext;
        delete temp;
        if (pHead == NULL)
            pTail = NULL;
        return 1;
    }
    return 0;
}

int main()
{
    List L;
    Node *p, *q;
    int k, x, y;
    while (1)
    {
        cout << "==========MENU==========" << endl;
        cout << "Lua chon 1: Tao danh sach" << endl;
        cout << "Lua chon 2: Them vao dau" << endl;
        cout << "Lua chon 3: Them vao cuoi" << endl;
        cout << "Lua chon 4: Xuat danh sach" << endl;
        cout << "Lua chon 5: Tinh do dai" << endl;
        cout << "Lua chon 6: Tim gia tri" << endl;
        cout << "Lua chon 7: Chen 1 gia tri x sau gia tri y" << endl;
        cout << "Lua chon 8: Dem so luong gia tri chan, le" << endl;
        cout << "Lua chon 9: Xoa 1 phan tu(Xoa dau)" << endl;
        cout << "========================" << endl;
        cout << "Nhap lua chon: ";
        cin >> k;
        switch(k)
        {
            case 1:
                cout << "Da khoi tao danh sach" << endl;
                break;
            case 2:
                cout << "Nhap gia tri cho Node: ";
                cin >> x;
                p->DataNode(x);
                L.AddHead(p);
                break;
            case 3:
                cout << "Nhap gia tri cho Node: ";
                cin >> x;
                p->DataNode(x);
                L.AddTail(p);
                break;
            case 4:
                L.OutputList();
                break;
            case 5:
                cout << "Do dai danh sach la: " << L.LengthList() << endl;
                break;
            case 6:
                cout << "Nhap gia tri can tim: ";
                cin >> x;
                if (L.FindValue(x) == -1)
                    cout << "Khong tim thay" << endl;
                else
                    cout << "Gia tri can tim o Node thu: " << L.FindValue(x) << endl;
                break;
            case 7:
                cout << "Nhap gia tri x cho Node can chen: ";
                cin >> x;
                cout << "Nhap gia tri y: ";
                cin >> y;
                L.InsertAfterValue(x,y);
                break;
            case 8:
                L.OddEven();
                break;
            case 9:
                L.DeleteHead();
                break;
            default:
                cout << "Khong co lua chon nay" << endl;
                exit(1);
        }
    }
    return 0;
}
