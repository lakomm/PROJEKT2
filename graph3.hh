#include<climits>
class Graph3{
private:
int numberOfVertices;
int numberOfEdges;
Vertex ** adjMatrix;
public:
Graph3(int v){
  numberOfVertices=v;
  numberOfEdges=0;
  adjMatrix=new Vertex*[numberOfVertices];
  for(int i=0;i<numberOfVertices;i++){
    adjMatrix[i]=new Vertex[numberOfVertices];
    for(int j=0;j<numberOfVertices;j++){
      adjMatrix[i][j].setVertexWeight(0);
    }
  }
}

void addEdge(int begin, int end,int weight){
  if(begin!=end && weight>0){
    adjMatrix[begin][end].setVertex(end,weight);
    adjMatrix[end][begin].setVertex(begin,weight);
    numberOfEdges++;
  }
}
int returnNumberOfVertices(){
  return numberOfVertices;
}
int returnNumberOfEdges(){
  return numberOfEdges;
}
bool edgeExist(int begin,int end){
  if(adjMatrix[begin][end].seeVertexWeight() != 0){
    return true;
  }else{return false;}
}
//zwraca ilość sąsiadów wierzchołka v
int returnNumberOfNeighbours(int v){
  int n=0;
  for(int i=0; i<numberOfVertices;i++ ){
    if(adjMatrix[v][i].seeVertexWeight()!=0) {n++;}
  }

  return n;
}
// numer n-tego sasiada wierzchołka v
int returnNeighbourNumber(int v, int n){
  int j=0;
  int k=0;
    // for(k=0; k<numberOfVertices; k++){
      while(k<numberOfVertices && j<n){
        if(adjMatrix[v][k].seeVertexWeight()!=0){
          j++;
        }
        k++;
    }
  return k-1;
}
//waga krawędzi pomiedzy  n-tym sasiadem, a wierzchołkiem v
int returnNeighbourWeight(int v, int n){
  int j=0;
  int k=0;
  while(k<numberOfVertices && j<n){
        if(adjMatrix[v][k].seeVertexWeight()!=0){
          j++;
        }
        k++;
    }

  return adjMatrix[v][k-1].seeVertexWeight();
}
void removeAllEdges(){
  for(int i=0;i<numberOfVertices;i++){
    adjMatrix[i]=new Vertex[numberOfVertices];
    for(int j=0;j<numberOfVertices;j++){
      adjMatrix[i][j].setVertexWeight(0);
    }
    numberOfEdges=0;
  }
}
void PrintGraph(){
  for(int i=0;i<numberOfVertices;i++){
    cout<<'\n';
    for(int j=0;j<numberOfVertices;j++){
      cout<< adjMatrix[i][j].seeVertexWeight()<<" ";
    }
  }
    cout<<'\n';
}
};
