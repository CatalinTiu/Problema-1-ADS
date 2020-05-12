

//Tiu Catalin Group 3 SubGroup 4 Homework 1
//Part 1

#include <iostream>
#include <cstdlib>
using namespace std; 

class vectorClass { 
  
    int* arr; 
  
    int capacity; 
  
    int current; 
  
public: 
    vectorClass();

    void push(int data);

    void push(int data, int index);

    int get(int index);

    void pop();

    int size();

    int getcapacity();

    void print(); 
    void sort();
};

vectorClass::vectorClass(){
        arr = new int[1]; 
        capacity = 1; 
        current = 0;
    }

void vectorClass::push(int data){ 
  
        
        if (current == capacity) { 
            int* temp = new int[2 * capacity];
            for (int i = 0; i < capacity; i++) { 
                temp[i] = arr[i]; 
            }
            delete[] arr; 
            capacity *= 2; 
            arr = temp; 
        }
        arr[current] = data; 
        current++; 
    } 

void vectorClass::push(int data, int index){ 
  
        
        if (index == capacity) 
            push(data); 
        else
            arr[index] = data; 
    } 
  
int vectorClass::get(int index){ 
        if (index < current) 
            return arr[index]; 
    } 

void vectorClass::pop(){ 
        current--; 
    } 

int vectorClass::size(){ 
        return current; 
    }

int vectorClass::getcapacity(){ 
        return capacity; 
    } 
  
void vectorClass::print(){ 
        for (int i = 0; i < current; i++) { 
            cout << arr[i] << " "; 
        } 
        cout << endl; 
    }
    
void vectorClass::sort(){
    int aux;
    for (int i = 0; i < current-1; i++){
        for (int j = i+1; j < current; j++){
            if(arr[i] > arr[j]){
                aux = arr[i];
                arr[i] = arr[j];            
                arr[j] = aux;
            }
        }
    }
}

int main() 
{ 
    vectorClass v; 
    v.push(10); 
    v.push(20); 
    v.push(30); 
    v.push(40); 
    v.push(50); 
    cout << " The vector's elements : "; 
    v.print(); 
    v.sort();
    cout << " Vector after being sorted : ";
    v.print();
    return 0; 
} 