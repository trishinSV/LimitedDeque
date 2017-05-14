#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>

template <typename T>
class Deque {
	friend std::ostream &operator<<(std::ostream &os, const Deque &dq){
		os << "[";
		for(int i = dq.front; i <= dq.rear; i++){
			if(dq.size == 0)
				break;	
			os << dq.arr[i] << (i == dq.rear ? "" : ", ");
		}
		os << "]\n";
		return os;
	}

	public :
		Deque();
		void insertFront(const T &value);
		T removeFront();
		T removeRear();
		int getSize();
		bool empty();
	
	private : 
		void checkFront();
		void checkRear();
		void expand();
		int size, capacity, front, rear;
		T *arr;
		static const int initialCap = 10;
};


template <typename T>
Deque<T>::Deque(): size(0), capacity(initialCap), front((capacity-1)/2), rear((capacity-1)/2) {arr = new T[capacity];}

template <typename T>
void Deque<T>::insertFront(const T &value){
    checkFront();
    if(size == 0){
        if(front > rear){
            arr[((capacity-1)/2)-1] = value;
            front--;
            size++;
        } else {
            arr[(capacity-1)/2] = value;
            size++;
        }
    } else {
        arr[front-1] = value;
        front--;
        size++;
    }
}

template <typename T>
T Deque<T>::removeFront(){
    T hold = 0;
    if(front > rear){
        std::cerr << "No more elements to remove from the front.\n";
    } else {
        hold = arr[front];
        front++;
        size--;
        return hold;
    }
    return hold;
    
}

template <typename T>
T Deque<T>::removeRear(){
    T hold = 0;
    if(front > rear){
        std::cerr << "No more elements to remove from the rear.\n";
    } else {
        hold = arr[rear];
        rear--;
        size--;
        return hold;
    }
    return hold;
    
}

template <typename T>
int  Deque<T>::getSize(){
    return size;
}

template <typename T>
bool Deque<T>::empty(){
    return size == 0 ? true : false;
}

template <typename T>
void Deque<T>::checkFront(){
    if(front == 0)
        expand();
    else
        return;
}

template <typename T>
void Deque<T>::checkRear(){
    if(rear == capacity-1)
        expand();
    else
        return;
}

template <typename T>
void Deque<T>::expand(){
    T *temp = new T[2*capacity];
    int qtr;
    if(front == 0){
        qtr = (2*capacity)/4;
        for(int i = front; i <= rear; i++){
            temp[qtr] = arr[i];
            qtr++;
        }
        delete [] arr;
        arr = temp;
        front = (2*capacity)/4;
        rear = qtr-1;
        capacity*=2;
        std::cerr << "Expanded from " << capacity/2 << " to " << capacity << std::endl;
    }
    else if(rear == capacity-1){
        qtr = (2*capacity) - capacity/4;
        for(int i = rear; i >= front; i--){
            temp[qtr] = arr[i];
            qtr--;
        }
        delete [] arr;
        arr = temp;
        front = qtr+1;
        rear = (2*capacity) - capacity/4;
        capacity*=2;
        std::cerr << "Expanded from " << capacity/2 << " to " << capacity << std::endl;
    }
}

#endif
