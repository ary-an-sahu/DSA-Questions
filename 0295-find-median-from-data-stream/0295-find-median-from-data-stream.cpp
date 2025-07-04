class MedianFinder {
public:

    priority_queue<int> maxHeap;
    priority_queue<int,vector<int> ,greater<int> > minHeap;

    double median;


    MedianFinder() {
        median = 0;

    }
    
    void addNum(int num) {
        if(maxHeap.size()== minHeap.size()){
            //insert in right
            if(num > median){
                minHeap.push(num);
                median = minHeap.top();
            }
            else{
                //insert in left
                maxHeap.push(num);
                median = maxHeap.top();
            }   
        }
        else if(maxHeap.size() == minHeap.size()+1){
            //maxheap ka size bada hai as compare to min heap 
            if(num > median){
                minHeap.push(num);  
                median = (minHeap.top() + maxHeap.top())/2.0;
            }else{
                //insert in left
                //max already bada h seedha insert nhi kr sakte , toh 1 element offload kro 
                int element = maxHeap.top();
                maxHeap.pop();
                minHeap.push(element);

                //now insert num in left
                maxHeap.push(num);
                median = (minHeap.top() + maxHeap.top())/2.0;


            }
        }
        else if(maxHeap.size() + 1 == minHeap.size()){
            //  minheap ka size bada hai 
            if(num> median){
                // insert in right
                int element = minHeap.top();
                minHeap.pop();
                maxHeap.push(element);

                minHeap.push(num);
                median = (minHeap.top() + maxHeap.top())/2.0;
            }
            else{
                // insert in left
                maxHeap.push(num);
                median = (minHeap.top() + maxHeap.top())/2.0;
            }
        }
        
        
    }
    
    double findMedian() {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */