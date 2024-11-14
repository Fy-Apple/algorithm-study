//
// Created by apple on 2024/10/29.
//
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;
// 小根堆
class minHeap {
private:
  vector<int> value_vector_;
  int nums = 0;
  void heapify(int i) {
    int minimum = i;
    const int left = 2 * i + 1;
    const int right = 2 * i + 2;
    if (left < nums && value_vector_[left] < value_vector_[minimum]) {
      minimum = left;
    }
    if (right < nums && value_vector_[right] < value_vector_[minimum]) {
      minimum = right;
    }
    if (minimum != i) {
      swap(value_vector_[minimum], value_vector_[i]);
      heapify(minimum);
    }
  }
  void push_heap(int pos) {
    if (pos == 0) return;
    int father = (pos - 1) / 2;
    if (value_vector_[pos] < value_vector_[father]) {
      swap(value_vector_[pos], value_vector_[father]);
      push_heap(father);
    }
  }
public:
  minHeap() = default;
  minHeap(const minHeap&) = delete;
  minHeap& operator=(const minHeap&) = delete;

  void push(int val) {
    value_vector_.emplace_back(val);
    ++nums;
    push_heap(nums - 1);
  }
  void pop() {
    if (nums > 0) {
      swap(value_vector_[0], value_vector_[nums--]);
      heapify(0);
      value_vector_.pop_back();
    }
  }
  int top() {
    if (nums > 0)
      return value_vector_[0];
    return -1;
  }
  bool empty() {
    if (nums == 0)
      return true;
    return false;
  }
};


class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> numMap;
    for (const auto& num : nums) {
      ++numMap[num];
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, function<bool(const pair<int, int>&, const pair<int, int>&)>> minHeap(
      [](const pair<int, int>& a, const pair<int, int>& b)->bool {
        return a.second > b.second;
      });
    auto it = numMap.begin();
    for (int i = 0; it != numMap.end() && i < k; ++it, ++i) {
      minHeap.emplace(*it);
    }
    for (; it != numMap.end(); ++it) {
      if (it->second > minHeap.top().second) {
        minHeap.pop();
        minHeap.emplace(*it);
      }
    }
    vector<int> result;
    while (!minHeap.empty()) {
      result.emplace_back(minHeap.top().first);
      minHeap.pop();
    }
    return result;
  }
};

int main(int argc, char *argv[]) {
  minHeap heap;
  heap.push(7);
  heap.push(1);
  heap.push(5);
  heap.push(16);
  heap.push(3);
  heap.push(9);
  cout << heap.top() << endl;
  heap.pop();
  cout << heap.top() << endl;

  return 0;
}

