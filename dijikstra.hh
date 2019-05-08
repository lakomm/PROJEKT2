#include"MinHeap.hh"
#include<time.h>
clock_t start,stop;
double czas;

template <typename T>
double dijikstra(T G, int startVertex,std::fstream &File){
  start=clock();
  int v=G.returnNumberOfVertices();

  HeapNode dist[v];         //tablica wierzcholkow z ich dystansami
  int visited[v];           //do sprawdzania czy wierzcholek byl odwiedzony
  int previous[v];         //needed for path
  MinHeap H(v);            //Tworzymy kolejkę
  for(int i=0;i<v;i++){        //Ustawiamy dystanse wszystkim wierzcholkom na INF
    H.addHeapNode(i,INT_MAX);
    visited[i]=0;
    previous[i]=i;
  }

  H.changeHeapNode(startVertex,0);  //zmieniamy dystans w stratowego na 0
  HeapNode ptr;
  int nr,n,w,d;
  while(H.returnSize()!=0){
    H.buildMinHeap();         //zbuduj min kopiec
    ptr=H.extract();          //wyciagnij element z najmniejszym dystansem
    nr=ptr.returnVertexNumber();    //Nr zdjetego wierzcholka
    d=ptr.returnDistanceFromSource(); //Dystans od zdjetego wierzcholka do W startowego
    visited[nr]=1;                 //Uaktualnia tbalice odwiedzonych
    dist[nr]=ptr;                  //Uaktualnia tablice dystansow
    int i=G.returnNumberOfNeighbours(nr);

    while(i>0){                      //Uaktualnia dystanse dla wszystkich sasiadow sciagnietego wierzcholka
      w=G.returnNeighbourWeight(nr,i);
      n=G.returnNeighbourNumber(nr,i);

      if( visited[n]<=0 && w+d < H.returnNodeDistance(n)){
        H.updateDistance(n,w+d);
        previous[n]=nr;
      }
      i--;
    }
  }
  stop=clock();
  czas=(double)(stop-start)/CLOCKS_PER_SEC;
  //
  // File.open( "File.txt", std::ios::app | std::ios::out );
  // for(int i=0;i<v;i++){
  //   File<<dist[i].returnVertexNumber()<<"  "<< dist[i].returnDistanceFromSource()<<"  path: ";
  //   int j=i;
  //   if (i!=startVertex){
  //     File<<i<<"<--";
  //   }
  //       do{
  //     File<<previous[j]<<"<--";
  //     j=previous[j];
  //   }while(previous[j]!=startVertex);
  //   File<<startVertex<<'\n';
  // }
  //
  // File<<'\n'<<'\n'<<'\n';
  // File.close();
  // G.PrintGraph();
return czas;
}
