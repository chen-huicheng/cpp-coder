#include <bits/stdc++.h>
using namespace std;
void adjust(vector<int> &nums, int n, int idx)
{
    int k = nums[idx];
    while (idx * 2 + 1 < n)
    {
        int l = idx * 2 + 1;
        if (l + 1 < n && nums[l] > nums[l + 1])
        {
            l++;
        }
        if (nums[l] < k)
        {
            nums[idx] = nums[l];
            idx = l;
        }
        else
        {
            break;
        }
    }
    nums[idx] = k;
}

vector<int> TopKInHeap(vector<int> &nums, int k)
{
    int len = nums.size();
    if (len < k)
        k = len;
    vector<int> res(nums.begin(), nums.begin() + k);
    int t = k / 2;
    for (int i = t; i >= 0; --i)
    {
        adjust(res, k, i);
    }
    for (int i = k; i < len; i++)
    {
        if (nums[i] > res[0])
        {
            res[0] = nums[i];
            adjust(res, k, 0);
        }
    }
    for (int i = k - 1; i >= 0; --i)
    {
        swap(res[i], res[0]);
        adjust(res, i, 0);
    }
    return res;
}

void heap_sort(vector<int> &nums)
{
    int n = nums.size();
    int k = n / 2;
    for (int i = k; i >= 0; --i)
    {
        adjust(nums, n, i);
    }
    for (int i = n - 1; i >= 0; --i)
    {
        swap(nums[i], nums[0]);
        adjust(nums, i, 0);
    }
}

int findk(vector<int> &nums, int k)
{
    int n = nums.size();
    int l = 0, r = n - 1;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (nums[mid] == k)
            return mid;
        if (nums[mid] > nums[r])
        {
            if (nums[mid] > k && k > nums[r])
                r = mid - 1;
            else
                l = mid + 1;
        }
        else if (nums[mid] < nums[r])
        {
            if (nums[mid] < k && k < nums[r])
            {
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        else
        {
            if (nums[r] == k)
                return r;
            r--;
        }
    }
    return -1;
}

struct Node
{
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int n) : val(n), next(nullptr) {}
};
Node *combineList(Node *head1, Node *head2)
{
    Node head;
    Node *p = &head;
    while (head1 && head2)
    {
        if (head1->val < head2->val)
        {
            p->next = head1;
            p = p->next;
            head1 = head1->next;
        }
        else
        {
            p->next = head2;
            p = p->next;
            head2 = head2->next;
        }
    }
    while (head2)
    {
        p->next = head2;
        p = p->next;
        head2 = head2->next;
    }
    while (head1)
    {
        p->next = head1;
        p = p->next;
        head1 = head1->next;
    }
    return head.next;
}
Node *List(Node *head)
{
    Node h1(0);
    Node *p = head, *q;
    while (p && p->next)
    {
        q = p->next;
        p->next = p->next->next;
        p = p->next;
        q->next = h1.next;
        h1.next = q;
    }
    return combineList(h1.next, head);
}

class LRUCache {
public:
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(cache.count(key))
        {
            movetotop(key);
            return cache[key]->second;
        }
            
        return -1;
    }
    
    void put(int key, int value) {
        
        if(cache.count(key)==0){
            if(times.size()>=cap){
                cache.erase(times.back().first);
                times.pop_back();
            }
            times.push_front(make_pair(key,value));
            cache[key]=times.begin();

        }else{
            cache[key]->second=value;
            movetotop(key);
        }
        
    }
    void movetotop(int key){
        auto P=*cache[key];
        times.erase(cache[key]);
        times.push_front(P);
        cache[key]= times.begin();
        
    }
private:
    int cap;
    map<int,list<pair<int,int>>::iterator> cache;
    list<pair<int,int>> times;


};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */








int main()
{
    // vector<int> nums;
    // int n = 20;
    // srand((unsigned)time(NULL));
    // for (int i = 0; i < n; i++)
    //     nums.push_back(rand() % 100);
    // cout << "sort:\t";
    // vector<int> temp(nums);
    // sort(temp.begin(), temp.end());
    // for (auto n : nums)
    //     cout << n << " ";
    // cout << endl;
    // vector<int> res = TopKInHeap(nums, 5);
    // for (auto r : res)
    //     cout << r << " ";
    vector<int> nums = {1, 8, 3, 6, 5, 4, 7, 2, 9};
    Node head;
    Node *p = &head;
    for (auto n : nums)
    {
        p->next = new Node(n);
        p = p->next;
    }

    p->next = nullptr;
    p = List(head.next);
    while (p)
    {
        cout << p->val << " ";
        p = p->next;
    }
    cout << "end" << endl;
}