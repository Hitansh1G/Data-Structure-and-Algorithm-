#include<vector>
class PriorityQueue{
    vector<int>pq;

    public:

    PriorityQueue(){

    }
    bool isEmpty(){
        return pq.size()==0;
    }
    int getSize(){
        return pq.size();
    }

    int getMin(){
        if(isEmpty()){
            return 0;
        }
        return pq[0];
    }
    void insert(int element){
        pt.push_back(element);
        //note - if there is a node - toh uske chuldren are present at 2i+1,2i+2
        //if we want to go from child to parent then (childIndex-1)/2
        int childIndex = pq.size()-1;
        int parentIndex = (childIndex-1)/2;

        if(pq[childIndex]<pq[parentIndex]){
            int temp = pq[childIndex];
            pq[childIndex]=pq[parentIndex];
            pq[parentIndex]=temp;
        }
        else break;
        childIndex = parentIndex;
    }
};