// #include<iostream>
using namespace std;

template<typename T> class List;
template <typename T>
class Node{
private:
  T data;
  Node<T>* next;
 friend class  List<T>;
public:
  //
  // T Get_data( ){
  //   return data;
  // }
  //
  // Node<T> Get_next(){
  //   return next;
  // }
  //
  // void Set_data(T new_data){
  //   data=new_data;
  // }
  //
  // void Set_next(Node<T> new_next){
  //   next=new_next;
  // }
};
