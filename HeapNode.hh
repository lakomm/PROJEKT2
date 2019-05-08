#include<iostream>
class HeapNode{
private:
int vertexNumber;
int distanceFromSource;
 // friend HeapNode & operator =( const HeapNode &h );
 // friend std::ostream& operator << (ostream& stm, const HeapNode &c);
 // friend std::ostream& operator << (ostream& stm, const Vertex &c);
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
  // HeapNode& operator = ( const HeapNode &h ){
  //   this->vertexNumber=h.returnVertexNumber();
  //   this->distanceFromSource=h.returnDistanceFromSource();
  //   return *this;
  // }
};
// std::ostream& operator << (ostream& stm, const HeapNode &c){
//   stm << c.vertexNumber;
//   stm <<" "<<c.distanceFromSource<<'\n';
//   return stm;
// }
