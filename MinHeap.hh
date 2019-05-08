#include"HeapNode.hh"
#include<algorithm>
class MinHeap{
private:
  int capacity;
  int size;
  HeapNode* array;
public:
  MinHeap(int c){
    capacity=c;
    size=0;
    array=new HeapNode[capacity];
  }

  void addHeapNode(int vNumber,int dist){
    if(size<capacity){
      array[size].setHeapNode(vNumber, dist);
      ++size;
    }else{std::cout<<"Heap is full"<<'\n';}
  }
  //wierzchołkowi v ustaw dystans d
  void changeHeapNode(int v, int d){
    array[v].setDistanceFromSource(d);
  }
  //zwraca dystans do wierzchołka v od wierzchołka startowego
  int returnNodeDistance(int v){
    int i=returnIndex(v);

    return array[i].returnDistanceFromSource();
  }
  int returnSize(){return size;}

  void minHeapify(int a){

    int parentIndex=a;
    int rightIndex=2*parentIndex+2;
    int leftIndex=2*parentIndex+1;
    int smallest=parentIndex;

    if(rightIndex < size && array[rightIndex].returnDistanceFromSource() < array[smallest].returnDistanceFromSource()){
      smallest=rightIndex;
    }
    if(leftIndex < size && array[leftIndex].returnDistanceFromSource()<array[smallest].returnDistanceFromSource()){
      smallest=leftIndex;
    }
    if(smallest != parentIndex){
      // swapHeapNodes(smallest, parentIndex);
       std::swap(array[smallest],array[parentIndex]);
      minHeapify(smallest);
    }

  }

  void buildMinHeap(){
    for(int i=size/2 -1; i>=0; i--){
      minHeapify(i);
    }
  }

  HeapNode extract(){
    HeapNode root=array[0];
    HeapNode last=array[size-1];
    array[0]=last;
    // swapHeapNodes(0,size);
    size--;
    // buildMinHeap();
    return root;
  }
  //zwraca numer indeksu tablicy array dla wierzchołka o numerze vNumber
  int returnIndex(int vNumber){
    int i=0;
    if(size>0){
      while(array[i].returnVertexNumber()!=vNumber){ i++;}
      return i;
    }
    return -1;
  }
  //wierzchołkowi o numerze v zwieksza dystans o d
  void updateDistance(int v, int d){
    int i=returnIndex(v);
    array[i].setDistanceFromSource(d);
  }



  void seeNode( HeapNode h){
    std::cout <<h.returnVertexNumber()  <<"  ";
    std::cout <<h.returnDistanceFromSource()  << '\n';
  }
  void seeArray(){
    for(int i=0;i<size;i++){
      seeNode(array[i]);
    }
  }
};
