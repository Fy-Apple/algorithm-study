#include <iostream>
#include <unordered_map>
//
// Created by apple on 2024/10/24.
//



class LRUCache {
private:
  struct ListNode {
    int val;
    int key;
    ListNode *prev;
    ListNode *next;
    ListNode() : key(-1), val(-1), prev(nullptr), next(nullptr) {}
    explicit  ListNode(const int x, const int y) : key(x), val(y), prev(nullptr), next(nullptr) {}
  };
  std::unordered_map<int, ListNode*> nodeMap;
  int capacity_;
  int curCapacity_;
  ListNode *front, *rear;
public:
  LRUCache(int capacity) : capacity_(capacity), curCapacity_(0){
    front = new ListNode();
    rear = new ListNode();
    front->next = rear;
    rear->prev = front;
  }
  ~LRUCache(){
    while (front) {
      rear = front;
      front = front->next;
      delete rear;
    }
  }

  int get(int key) {
    if (nodeMap.find(key) != nodeMap.end()) {
      nodeMap[key]->prev->next = nodeMap[key]->next;
      nodeMap[key]->next->prev = nodeMap[key]->prev;
      rear->prev->next = nodeMap[key];
      nodeMap[key]->prev = rear->prev;
      rear->prev = nodeMap[key];
      nodeMap[key]->next = rear;
      return nodeMap[key]->val;
    }
    return -1;
  }

  void put(int key, int value) {
    if (nodeMap.find(key) != nodeMap.end()) {
      nodeMap[key]->val = value;
      nodeMap[key]->prev->next = nodeMap[key]->next;
      nodeMap[key]->next->prev = nodeMap[key]->prev;
      rear->prev->next = nodeMap[key];
      nodeMap[key]->prev = rear->prev;
      rear->prev = nodeMap[key];
      nodeMap[key]->next = rear;
    }else {
      if (curCapacity_ == capacity_) {
        ListNode *temp = front->next;
        front->next = front->next->next;
        front->next->prev = front;
        nodeMap.erase(temp->key);
        delete temp;
        --curCapacity_;
      }
      ListNode *p = new ListNode(key, value);
      nodeMap.emplace(key, p);
      rear->prev->next = p;
      p->prev = rear->prev;
      p->next = rear;
      rear->prev = p;
      ++curCapacity_;
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main(int argc, char** argv) {
  LRUCache cache(2);
  cache.put(2, 1);  // 2->1
  cache.put(1, 1);  // 2->1   1->1
  cache.put(2, 3);  // 1->1   2->3
  cache.put(4, 1);  // 1->1(x)   2->3   4->1
  std::cout << cache.get(1) << std::endl;   // 2->3   4->1    -1
  std::cout << cache.get(2) << std::endl;   // 4->1   2->3    3

  return 0;
}

template<typename Compare,typename T>
class Bind1st{
public:
  Bind1st(Compare com,T first):comp_(com),val_(first){}
  bool operator()(const T &second) const{
    return comp_(val_,second);
  }
private:
  Compare comp_;
  T val_;
};
