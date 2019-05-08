#include<fstream>
#include"graph2.hh"
#include"graph3.hh"
#include"dijikstra.hh"
// #include<time.h>
// clock_t start,stop;
// double czas;

int main(){
  std::fstream file;
  std::fstream FileOfTimes;
  // std::fstream FileToRead;
  srand( time( NULL ));
  double sredni_czas=0;
    // int V=10;
    // int s1,s2,s3,k=0;
    // double g;
    // int e=1;
    // FileToRead.open("plik.txt", ios::in);
    // if(FileToRead.good() == true)
    // {
    //       if(k==0){FileToRead >>V>>e>>g;std::cout<<V<<" "<<e<<" "<<g<<'\n';k++;}
    //     }
    //     Graph2 G(V);
    //
    //       while( !FileToRead.eof() && k<=e)
    //       {
    //         FileToRead >> s1 >> s2 >> s3;
    //         std::cout<<s1<<" "<<s2<<" "<<s3<<'\n';
    //         G.addEdge(s1,s2,s3);
    //         k++;
    //
    //     }
    //     FileToRead.close();
    //     G.PrintGraph();
    // }
    //
    int NumberOfGraphs=50;
    int V[]={20,50,100,200,500};
    double DENSITY[]={0.25,0.5,0.75,1};
    for(int i=0;i<5;i++){
      Graph3 G(V[i]);
      for(int j=0;j<4;j++){
        int E= (DENSITY[j])*(V[i]*(V[i]-1))/2;
        for(int n=0; n < NumberOfGraphs; n++){
          // std::cout<<"E= "<<E<<" X= " <<G.returnNumberOfEdges()<<'\n';
          G.removeAllEdges();
          // cout<<"removed"<< n<<'\n';

          for(int k=0;k<V[i]-1;k++){
            G.addEdge(k,k+1,rand()%1001);
          }
          // cout<<"after first for"<<'\n';
          while (E>G.returnNumberOfEdges()) {
            int a=rand()%V[i];
            int b=rand()%V[i];
            // cout<<"checke existance"<<'\n';
            // std::cout<<"a= "<<a<<"b= "<< b<<" exist= "<<G.edgeExist(a,b)<<'\n';
            if(G.edgeExist(a,b)==0){
              // cout<<"befor add rand"<<'\n';
              G.addEdge(a,b,rand()%1001);
            // cout<<"after add rand"<<'\n';
            }
          }
          // cout<<"before dijikstra"<<n;
          sredni_czas=sredni_czas+(dijikstra(G,0,file));
          // cout<<" after dijikstra "<<n<<'\n';
        }
        FileOfTimes.open( "times.txt", std::ios::app | std::ios::out );
        FileOfTimes<<V[i]<<"  "<<DENSITY[j]<<" "<<sredni_czas<<'\n';
        FileOfTimes.close();
        sredni_czas=0;
      }
      // G.removeAllVertices();
    }
    cout<<"FINISHED";
  return 0;
}
