#include <iostream>
using namespace std;

void sort0s1s2s(int array[], int n) {
    int low = 0, high = n-1, mid = 0;

    while( high>=mid ) {
    
        switch(array[mid]) {
            
            case 0:
            
            if ( array[low] != array[mid]) {
              swap(array[low], array[mid]);
            }
            low++;
            mid++;
            
              break;
              
            case 1:
            mid++;
            break;
    
            case 2:
            
            if(array[mid] != array[high]) {
            swap(array[mid], array[high]);
            }
            
            high--;
            break;
        }
    }
}
    void swap(int *a, int *b) {
        int temp = *a;
        *a= *b;
        *b = temp;
    }
    
    void printElements(int array[], int n) {
        
        for(int i =0;i<n;i++) {
            cout << array[i] << " " ;
        }
    }
    


int main() {
	//code
	
	int t1, i, array[100];
	cin >> t1;
	
	for(i = 0;i< t1; i++) {
	    cin >> array[i];
	}
	sort0s1s2s(array, t1);

      for(int i =0;i<t1;i++) {
            cout << array[i] << " " ;
        }


	return 0;
}
