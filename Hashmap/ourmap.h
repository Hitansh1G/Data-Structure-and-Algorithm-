#include<string>
template<typename V>
class MapNode{
    public:
    string key;
    V value;
    MapNode* next;

    MapNode(string key , V value){
        this->key = key;
        this-> value = value;
        next = NULL;
    }
    ~MapNode(){
        delete next;
    }
}
template<typename V>
class ourmap{
    MapNode<V>** buckets;
    int size ;
    int numbuckets;
    
    public:
    ourmap(){
        count = 0;
        numbuckets = 5;
        buckets = new MapNode<V>* [numbuckets];
        for(int i=0 ; i<numbuckets ; i++){
            buckets[i]=NULL;
        }
    }
    ~ourmap(){
        for(int i=0 ; i<numbuckets ; i++){
            delete buckets[i];
        }
        delete [] buckets;
    }
    int size(){
        return count;
    }
    private:
    getbucketIndex(string key , V value){
        int hashcode=0;
        //here its like abc = 'a'*p^2 + 'b'*p^1 + 'c'*p^0 where p is a prime number
        int currentCoeff=1;
        for(int i=key.length()-1 ; i>=0 ; i--){
            hashcode += key[i]*currentCoeff;
            hashcode = hashcode%numbuckets;
            currentCoeff*=37;
            //37 is a prime 
            currentCoeff = currentCoeff%numbuckets;
        }

        return hashcode%numbuckets;
    }
    public:
    void insert(string key , V value){
        int bucketIndex = getbucketIndex(string, value);
        MapNode<V>*head = buckets[bucketIndex];
        while(head != NULL){
            if(head ->key==key){
                head->value =value;
                return;
            }
            head = head->next;
        }
        head = buckets[bucketIndex];
        MapNode<V>*node = new MapNode<V>(key,value);
        node->next = head;
        buckets[bucketIndex]=node;
        count++;
    }

    void getValue(string key){

    }
    V remove(string key){

    }
}
