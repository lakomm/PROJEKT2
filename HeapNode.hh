#include<iostream>
class HeapNode{
private:
int vertexNumber;
int distanceFromSource;

public:

  void setHeapNode(int n, int d){
    setVertexNumber(n);
    setDistanceFromSource(d);
  }
  void setVertexNumber(int n){
    vertexNumber=n;
  }
  void setDistanceFromSource(int d){
    distanceFromSource=d;
  }
  int returnVertexNumber()const{
    return vertexNumber;
  }
  int returnDistanceFromSource()const{
    return distanceFromSource;
  }

};
