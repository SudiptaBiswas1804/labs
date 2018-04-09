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
  int left(int i){return 2*i+1; }
  int right(int i){return 2*i+2; }
  void insert(int key);
  void show();
  void deletion();
  void heap(int i);
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

void Maxheap::deletion(){
 int root=arr[0];
 arr[0] = arr[hlength-1];
 hlength--;
 heap(0);
 }

void heap(int i){
 if(arr[left(i)]==0 && arr[right(i)]==0){
  return ;
 }

 else if(arr[left(i)]==0 || arr[right(i)]==0){
  if(arr[left(i)]==0){
   if(arr[right(i)]>arr[i]){
      swap(&arr[right(i)],&arr[i];
      }
   }
 else{
  if(arr[left(i)]>arr[i]){
    swap(&arr[left(i)],&arr[i]);
    }
 }
}
 
 else if(arr[left(i)]!=0 && arr[right(i)]!=0){
  if(arr[left(i)]>arr[right(i)]){
    if(arr[left(i)]>arr[i]){
      swap(&arr[left(i)],&arr[i]);
  }
}
  else(arr[right(i)]>arr[left(i)]){
   if(arr[right(i)]>arr[i]){
    swap(&arr[right(i)],&arr[i]);
   }
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
 h.deletion();
 h.show();
 return 0;
}
