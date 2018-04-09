#include <iostream>
using namespace std;

void swap(int *x, int *y);
class Maxheap{
 int *arr;
 int size;
 int hlength;

 public:
  Maxheap(int size);
  int parent(int i){return (i-1)/2;}
  void insert(int key);
  void show();
};

Maxheap::Maxheap(int cap){
 hlength=0;
 size=cap;
 arr= new int[cap];
 // node * temp = new node; 
}


void Maxheap::insert(int key){
 if(hlength==size){
  return ;
 }
 else{
  hlength++;
  int i = hlength-1;
  arr[i]=key;
  while(arr[i]>arr[parent(i)]){
   swap(arr[i],arr[parent(i)]);
   i=parent(i);
 }
}
}

void Maxheap::show(){
 for(int i=0; i<hlength; i++){
  cout<<arr[i]<<" ";
 } 
}


void swap(int *x, int *y){
 int temp=*x;
 *x=*y;
 *y=temp;
}
 
int main(){
 Maxheap h(100);
 h.insert(3);
 h.insert(4);
 h.insert(6);
 h.show();//*/
 return 0;
}
