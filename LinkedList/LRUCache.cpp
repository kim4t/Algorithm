class Node
{
public:
    int key;
    int val;
    Node* next = nullptr;
    Node* prev = nullptr;
    Node(int k=-1, int v=-1)
    {
        key = k;
        val = v;

    }
};

class LRUCache {
    unordered_map<int, Node*> um;
    int maxSize;
    Node* head = nullptr;
    Node* tail = nullptr;
public:
  
    LRUCache(int capacity) {
        maxSize = capacity;
        head = new Node();
    }

    int get(int key) {
        if (um.find(key) != um.end())
        {
            Node* target = um[key];
            if(tail != target)
                moveToEnd(target);
            return target->val;
        }
        return -1;
    }

    void put(int key, int value) {
        Node* node = new Node(key, value);
        if (um.find(key) != um.end())
        {
            um[key]->val = value;
            if (tail != um[key])
                moveToEnd(um[key]);
        }
        else
        {
            if (um.size() < maxSize)
            {
                addBack(node);

            }
            else
            {
                Node* target = head->next;
                um.erase(target->key);
                removeFromList(target);
                addBack(node);
            }
            um[key] = node;
        }
    }

    void addBack(Node* node)
    {
        if (um.size() == 0)
        {
            head->next = node;
            tail = head;
        }
        tail->next = node;
        node->prev = tail;
        tail = node;
    }

    void removeFromList(Node* target)
    {
        if (target == tail)
        {
            tail = target->prev;
            tail->next = nullptr;
            target->prev = nullptr;
        }
        else
        {
            target->prev->next = target->next;
            target->next->prev = target->prev;
            target->next = nullptr;
            target->prev = nullptr;
          
        }
        delete target;
    }
    void moveToEnd(Node* target)
    {
        target->prev->next = target->next;
        target->next->prev = target->prev;
        target->prev = tail;
        tail->next = target;
        target->next = nullptr;
        tail = target;
       
    }
    void printSize()
    {
        cout << um.size() << endl;
    }
    void printNodes()
    {
        Node* cur = head->next;
        while (cur != nullptr)
        {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};
