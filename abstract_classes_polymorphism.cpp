class LRUCache : public Cache {
public:
    LRUCache(int capacity)
    {
        cp = capacity;
        tail = nullptr;
        head = nullptr;
    }
    void set(int key, int value) override
    {
        auto it = mp.find(key);
        if (it != mp.end())
        {
            auto n = it->second;
            n->value = value;
            update_head(n);
        }
        else
        {
            Node* n = new Node(key, value);
            if (head == nullptr)
            {
                head = n;
                tail = n;
            }
            n->next = head->next;
            n->prev = tail;
            head = n;
            
            mp.emplace(key, n);
            if (mp.size() > cp)
            {
                remove_tail();
            }
        }
    }
    int get(int key) override
    {
        auto it = mp.find(key);
        if (it == mp.end())
            return -1;

        //update head
        auto n = it->second;
        update_head(n);
        return n->value;
    }

    void update_head(Node* n)
    {
        auto next = n->next;
        n->prev->next = n->next;
        n->next = head;
        n->prev = tail;
        head = n;
    }

    void remove_tail()
    {
        mp.erase(tail->key);
        tail->prev->next = head;
        tail = tail->prev;
    }
};