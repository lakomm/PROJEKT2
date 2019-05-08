#include<iostream>
using namespace std;
class Vertex{
private:
  int vertexNumber;
  int weight;
  friend std::ostream& operator << (ostream& stm, const Vertex &c);
  // friend bool operator ==( const Vertex & v );
public:
  Vertex(){};
  ~Vertex(){};
void setVertex(int n, int w){
  setVertexNumber(n);
  setVertexWeight(w);
}

void setVertexWeight(int w){
  weight=w;
}

void setVertexNumber(int n){
  vertexNumber=n;
}


  int seeVertexNumber()const{
    return vertexNumber;
  }

  int seeVertexWeight()const{
    return weight;
  }

  bool operator ==( const Vertex & v ){
    if(( this->vertexNumber == v.vertexNumber )  ){
      return true;
    }else{
      return false;
    }
  }

};
std::ostream& operator << (ostream& stm, const Vertex &c){
  stm << c.vertexNumber;
  stm <<"-("<<c.weight << ")";
  return stm;
}
