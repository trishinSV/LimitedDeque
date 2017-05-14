#include <iostream>
#include "deque.h"

using namespace std;

int main(){
    
	Deque<int> dq;
	cout << "-------Inserting/removing numbers while alternating-------\n";
	cout << "dq starting out with " << dq;
	for(int i = 0; i < 15; i++){
			cout << "Inserting " << i << " to the front of the deque. ";
			dq.insertFront(i);
			cout << dq;
	}
	while(!dq.empty()){
		if(dq.getSize()%2 == 0){
			cout << "Removing " << dq.removeFront() << " from the front of the deque. ";
			cout << dq;
		}
		else{
			cout << "Removing " << dq.removeRear() << " from the rear of the deque. ";
			cout << dq;
		}	
	}

    Deque<float> dq1;
    cout << "-------Inserting/removing numbers while alternating-------\n";
    cout << "dq starting out with " << dq1;
    for(int i = 0; i < 10; i++){
        cout << "Inserting " << i << " to the front of the deque. ";
        dq1.insertFront(i+0.1*i);
        cout << dq1;
    }
    while(!dq1.empty()){
        if(dq1.getSize()%2 == 0){
            cout << "Removing " << dq1.removeFront() << " from the front of the deque. ";
            cout << dq1;
        }
        else{
            cout << "Removing " << dq1.removeRear() << " from the rear of the deque. ";
            cout << dq1;
        }	
    }
    
	return 0;
}
