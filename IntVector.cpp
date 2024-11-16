#include "IntVector.h"

int debug=1;

IntVector::IntVector(unsigned capacity , int value):_size(capacity), _capacity(capacity){
    _data=nullptr;
    // if(debug==1){
    //     cout<<"Before dynamically allocating an array"<<endl;
    // }
    if (capacity != 0){
        _data=new int[capacity];
        for(unsigned i=0; i<capacity; ++i){
           _data[i]=value;
        }
    }
    // if(debug==1){
    //     cout<<"After dynamically allocating an array"<<endl;
    // }

}
IntVector::~IntVector(){
    if(_data!=nullptr)
        delete[]_data;
}
unsigned IntVector::size() const{
    return _size;
}
unsigned IntVector::capacity() const{
    return _capacity;
}
bool IntVector::empty()const{
    return _size==0;
}
const int & IntVector::at (unsigned index) const{
    if(index >= _size){
        throw out_of_range("IntVector::at_range_check");
    }
    return _data[index];
}
const int & IntVector::front() const{
    return _data[0];
}
const int & IntVector::back()const{
    return _data[_size-1];
}



void IntVector::expand(){
    unsigned updatedSize=_capacity*2;
    if(updatedSize==0){
        updatedSize=1;
    }
    int * temp= new int [updatedSize];
    for(unsigned i=0;i<_size;++i){
        temp[i]=_data[i];
    }
    delete[] _data;
    _data=temp;
    _capacity=updatedSize;

}
void IntVector::expand(unsigned amount){
    unsigned updatedSize=_capacity+amount;
        int * temp= new int [updatedSize];
        for(unsigned i=0;i<_size;++i){
            temp[i]=_data[i];
        }
        delete[] _data;
        _data=temp;
        _capacity=updatedSize;
}
void IntVector::insert (unsigned index, int value){
    if(index>_size){
        throw out_of_range("IntVector::insert_range_check");
    }
    if(_size>=_capacity){
        expand();
    }
    for(unsigned i=_size; i>index;--i){
        _data[i]=_data[i-1];
    }
    _data[index]=value;
    ++_size;
} 
void IntVector::erase (unsigned index){ 
    if(index>_size || _size==0 || index==_size){
        throw out_of_range("IntVector::erase_range_check");
    }
    for(unsigned i=index; i<_capacity; ++i){
        _data[i]=_data[i+1];
    }
    _size-=1;
}
void IntVector::push_back(int value){
    if(_size==_capacity){
        expand();
    }
    _data[_size]=value;
    _size++;
}
void IntVector::pop_back(){
    _size--;
}
void IntVector::clear(){
    _size=0;
}
void IntVector::resize(unsigned n, int value){  
    if(n<_size){
        _size=n;                                    //checks if n is smaller than current size
    }
    if(n>_size){                                    //checks if n is greater than current size
        while(n>_capacity){
            if(n>_capacity){
                if(_capacity*2>(n-_capacity)+_capacity){
                    expand();
                }
                else{
                    expand(n-_capacity);
                }
            }
        }
        for(unsigned i=_size;i<n;++i){              //only runs if n is greater than size b/c we need to fill the new space with something
            _data[i]=value;
        }
        _size=n;
    }
}
void IntVector::reserve(unsigned n){
   if(n>_capacity){
    expand(n-_capacity);
   }
}
void IntVector::assign (unsigned n, int value){
    if(n>_capacity){
        if(_capacity*2>(n-_capacity)+_capacity){
            expand();
        }
        else {
            expand(n-_capacity);
        }
    }
    clear();
    _size=n;
    for(unsigned i=0; i<_size;++i){
        _data[i]=value;
    }
}

int & IntVector::at(unsigned index){
    if(index==_size || index > _size){
        throw out_of_range("IntVector::at_range_check");
    }
    return _data[index];
}

int & IntVector::front(){
    return _data[0];
}
int & IntVector::back(){
    return _data[_size-1];
}




/*


int *ptr=new int 7;         memory leak is when we lose the address of the thing that the pointer was pointing at b/c we reassigned the pointer

int i = 5;

ptr = &i;




*/