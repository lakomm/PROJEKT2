// #include<iostream>
#include"Node.hh"
#include"Vertex.hh"
using namespace std;

template <typename T>
class List{
private:
Node<T>* head;
int size;
public:
List(){
  head=NULL;
  size=0;
}
~List(){}


bool exist(const T& element){
  Node<T>* iter=head;
  bool exist=false;
  do{
    if(iter->data == element){
      exist=true;
    }
    iter=iter->next;
  }  while( iter != NULL );
  delete iter;
  return exist;
}
void addFront(const T& element){
  Node<T>* curr= new Node<T>;
  curr->data = element;
  curr->next = head;
  head=curr;
  size++;
}
//returns front element of the list
const T& seeFront()const{
  return head->data;
}
//returns n-th (starting from front) element of the list
T returnElement(int n){
  Node<T> *iter=head;
  while( n>=2&& iter!=NULL){
    iter=iter->next;
    n--;
  }
  return iter->data;
}
//couts all lists elements starting from front
void seeAll()const{
  if(empty()!=1){
    Node<T>* iter=head;
    do{
      cout<< iter->data;
      iter=iter->next;
    }  while(iter !=  NULL);
  }else{
    std::cout << "empty" << '\n';
  }
}
//if empty return returnDistanceFromSource
bool empty()const{
  if (head==NULL) return true;
  return false;
}
void removeFront(){
  if(empty()==0){
    Node<T>* old=head;
    head=old->next;
    delete old;
    size --;
  }
}
void removeALL(){
  do{
    removeFront();
  }while(head!= NULL);
}
int Size(){
  return size;
}
};
