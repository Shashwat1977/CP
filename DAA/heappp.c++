#include <bits/stdc++.h>
using namespace std;
 
struct PriorityQueue
{
private:
    
    vector<int> arr;
 

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return (2*i + 1);
    }
 
    int right(int i) {
        return (2*i + 2);
    }
 

    void heapify_down(int i)
    {
        int l = left(i);
        int r = right(i);
 
        int smallest = i;


        if (l < size() && arr[l] < arr[i]) {
            smallest = l;
        }
 
        if (r < size() && arr[r] < arr[smallest]) {
            smallest = r;
        }
 

        if (smallest != i)
        {
            swap(arr[i], arr[smallest]);
            heapify_down(smallest);
        }
    }
 
    
    void heapify_up(int i)
    {
   
        if (i && arr[parent(i)] > arr[i])
        {
            swap(arr[i], arr[parent(i)]);
            heapify_up(parent(i));
        }
    }
 
public:

    unsigned int size() {
        return arr.size();
    }

    bool empty() {
        return size() == 0;
    }

    void push(int key)
    {
      
        arr.push_back(key);
       
        int index = size() - 1;
        heapify_up(index);
    }
 
    void pop()
    {
        try {
            
            if (size() == 0)
            {
                throw out_of_range("index is out of range(Heap underflow)");
            }
 
            
            arr[0] = arr.back();
            arr.pop_back();
            heapify_down(0);
        }
        
        catch (const out_of_range &oor) {
            cout << endl << oor.what();
        }
    }
 
    
    int top()
    {
        try {

            if (size() == 0)
            {
                throw out_of_range("index is out of range(Heap underflow)");
            }
 
            
            return arr.at(0);        
        }
        
        catch (const out_of_range &oor) {
            cout << endl << oor.what();
        }
    }
};
 

int main()
{
    PriorityQueue pq;
 
    // Note: The element's value decides priority
 
    pq.push(3);
    pq.push(2);
    pq.push(15);
 
    cout << "Size is " << pq.size() << endl;
 
    cout << pq.top() << " ";
    pq.pop();
 
    cout << pq.top() << " ";
    pq.pop();
 
    pq.push(5);
    pq.push(4);
    pq.push(45);
 
    cout << endl << "Size is " << pq.size() << endl;
 
    cout << pq.top() << " ";
    pq.pop();
 
    cout << pq.top() << " ";
    pq.pop();
 
    cout << pq.top() << " ";
    pq.pop();
 
    cout << pq.top() << " ";
    pq.pop();
 
    cout << endl << boolalpha << pq.empty();
 
    pq.top();    
    pq.pop();    
 
    return 0;
}
