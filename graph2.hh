#include"List.hh"
// #include"MinHeap.hh"
#include<climits>
class Graph2{
private:
List<Vertex>* adjList;
int numberOfVertices;
int numberOfEdges;
public:
Graph2(int v){
  numberOfVertices=v;
  numberOfEdges=0;
  adjList= new List<Vertex>[numberOfVertices];
}
// ~Graph2(){};
// (numer wierzchołka początkowego, numer wierzchołka końcowego, waga krawędzi)
void addEdge(int begin,int end, int weight){
  if(begin!=end && weight >0 ){              //krawędzie nie mogą się powtarzac
    Vertex newVertex;
    newVertex.setVertex(end,weight);
    adjList[begin].addFront(newVertex);
    newVertex.setVertex(begin,weight);
    adjList[end].addFront(newVertex);
    numberOfEdges++;
  }
}

int returnNumberOfVertices(){
  return numberOfVertices;
}
int returnNumberOfEdges(){
  return numberOfEdges;
}
//zwraca ilość sąsiadów wierzchołka v
int returnNumberOfNeighbours(int v){
  return adjList[v].Size();
}
// numer n-tego sasiada wierzchołka v
int returnNeighbourNumber(int v,int n){
  return adjList[v].returnElement(n).seeVertexNumber();
}
//waga krawędzi pomiedzy  n-tym sasiadem, a wierzchołkiem v
int returnNeighbourWeight(int v,int n){
  return adjList[v].returnElement(n).seeVertexWeight();
}

void PrintGraph(){
  for(int i=0; i<numberOfVertices;i++){
    cout<< i <<"-->"; adjList[i].seeAll(); cout<<endl;
  }
  cout<<'\n';
}

void removeAllEdges(){
  for(int i=0;i<numberOfVertices;i++){
    adjList[i].removeALL();
  }
  numberOfEdges=0;
}

void removeAllVertices(){
  for(int i=0;i<numberOfVertices;i++)
{
    delete[] adjList;
}
  numberOfVertices=0;
}
// List<Vertex>* returnList(){
//   return adjList;
// }
bool edgeExist(int begin, int end){
    Vertex v1; v1.setVertexNumber(end);
    Vertex v2; v2.setVertexNumber(begin);
    if(adjList[begin].exist(v1) && adjList[end].exist(v2)){
        return true;
      }else{return false;}
    }
};
