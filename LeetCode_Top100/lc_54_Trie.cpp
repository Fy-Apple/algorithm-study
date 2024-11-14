//
// Created by apple on 2024/10/26.
//
#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;



class Trie {
private:
  struct node {
    bool end;
    unordered_map<char, node*> nodeAddr;
    node(): end(false) {}
  };
  unordered_map<char, node*> addMap;
public:
  Trie() = default;

  void insert(string word) {
    node * curNode = nullptr;
    unordered_map<char, node*>* curMap = &addMap;
    for (const auto& c : word) {
      if (curMap->find(c) == curMap->end()) {
        cout << "insert  -->  char: " << c  << " not exist"<< endl;
        (*curMap)[c] = new node();
      }
      curNode = (*curMap)[c];
      curMap = &(curNode->nodeAddr);
    }
    if (curNode) curNode->end = true;
  }

  bool search(string word) {
    const node * curNode = nullptr;
    unordered_map<char, node*>* curMap = &addMap;
    for (const auto& c : word) {
      if (curMap->find(c) != curMap->end()) {
        cout << "search  -->  char: " << c  << " find"<< endl;
        curNode = (*curMap)[c];
        curMap = (&(*curMap)[c]->nodeAddr);
      }else {
        cout << "search  -->  char: " << c  << " not exist return"<< endl;
        return false;
      }
    }
    if (curNode && curNode->end) return true;
    return false;
  }

  bool startsWith(string prefix) {
    unordered_map<char, node*>* curMap = &addMap;
    for (const auto& c : prefix) {
      if (curMap->find(c) != curMap->end()) {
        curMap = (&(*curMap)[c]->nodeAddr);
      }else {
        return false;
      }
    }
    return true;
  }
};


int main(int argc, char *argv[]) {
  Trie t;
  t.insert("apple");
  cout << t.search("apple");


  return 0;
}
