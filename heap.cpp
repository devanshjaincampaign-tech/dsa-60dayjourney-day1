#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class minHeap{
    private:
    vector<int>heap;

    int parent(int i){
        return (i-1)/2;
    }
    int left(int i){
        return (2*i)+1;
    }
    int right(int i){
        return (2*i)+2;
    }
/*The following code is for the upheapify, this particular concept is used whenever we insert
a new element in the heap. The new element is inserted at the last node to maintain its 
completeness. hence it may be possible that it violates the heap property and hence
we need to send the element to the top of the heap by checking if the parent is smaller
or greater than the child Node*/
    void upheapify(int index){
        while(index>0 && heap[index]<heap[parent(index)]){
            swap(heap[index],heap[parent(index)]);
            index=parent(index);
        }
    }

    void downheapify(int index){
        
        int smallest =index;
        int l=left(smallest);
        int r=right(smallest);

        if(l<heap.size() && heap[l]<heap[smallest]){
            smallest=l;
        }

        if(r<heap.size() && heap[r]<heap[smallest]){
            smallest=r;
        }

        if(smallest!=index){
            swap(heap[index],heap[smallest]);
            downheapify(smallest);
        }
    }
    public:
        void push(int val){
            heap.push_back(val);
            upheapify(heap.size()-1);
        }

        void pop(){
            if(heap.empty()){
                cout<<"heap underflow";
                return;
            }
            heap[0]=heap.back();
            heap.pop_back();
            if(!heap.empty()){
                downheapify(0);
            }
        }
        int top(){
            if(heap.empty()){
                throw runtime_error("heap is empty");
            }
            return heap[0];
        }

        bool empty(){
            return heap.empty();
        }
};