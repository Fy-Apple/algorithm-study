//
// Created by apple on 2024/10/29.
//
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class MedianFinder {
private:
  priority_queue<int> leftLargeHeap_;
  priority_queue<int, vector<int>, greater<int>> rightSmallHeap_;
public:
  MedianFinder() = default;

  void addNum(int num) {
    if (leftLargeHeap_.empty() || num < leftLargeHeap_.top()) {
      leftLargeHeap_.push(num);
    }else {
      rightSmallHeap_.push(num);
    }
    if (leftLargeHeap_.size() > rightSmallHeap_.size() + 1) {
      rightSmallHeap_.push(leftLargeHeap_.top());
      leftLargeHeap_.pop();
    }else if (leftLargeHeap_.size() < rightSmallHeap_.size()) {
      leftLargeHeap_.push(rightSmallHeap_.top());
      rightSmallHeap_.pop();
    }
  }

  double findMedian() {
    if ((leftLargeHeap_.size() + rightSmallHeap_.size()) % 2 == 1) return leftLargeHeap_.top();
    return (leftLargeHeap_.top() + rightSmallHeap_.top()) / 2.0;
  }
};




class MedianFinder2 {
private:
  vector<int> left_vector_;
  vector<int> right_vector_;
  int left = -1;
  int right = -1;
  int nums = 0;
  void heap_push(int num) {
    int addNum;
    if (left_vector_.size() == right_vector_.size()) {
      if (num > right) {
        addNum = left;
        left = right;
        right = num;
      }else if (num < left) {
        addNum = num;
      }else {
        addNum = left;
        left = num;
      }
      left_vector_.push_back(addNum);
    }else {
      if (num > right) {
        addNum = right;
      }else if (num < left) {
        addNum = right;
        right = left;
        left = num;
      }else {
        addNum = right;
        right = num;
      }
      right_vector_.push_back(addNum);
    }
    cout << endl << left_vector_.size() << " " << right_vector_.size() << endl;
  }

public:
  MedianFinder2() {

  }

  void addNum(int num) {
    if (nums == 0) {
      left = num;
    }else if (nums == 1) {
      if (left > num) {
        right = left;
        left = num;
      }else {
        right = num;
      }
    }else {
      heap_push(num);
    }
    ++nums;
  }

  double findMedian() {
    if (nums % 2 == 1) return left;
    return (left + right) / 2.0;
  }
};

int main(int argc, char *argv[]) {
  MedianFinder m;
  m.addNum(1);
  //cout << m.findMedian() << endl;
  m.addNum(2);
  //cout << m.findMedian() << endl;
  m.addNum(3);
  //cout << m.findMedian() << endl;
  m.addNum(9);
  cout << m.findMedian() << endl;

  return 0;
}


