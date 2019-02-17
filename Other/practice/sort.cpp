#include <iostream>
using namespace std;

void swap(int* a, int* b){
    int tmp = *a;
    *a=*b;
    *b=tmp;
}

void selectionSort(int* arr, int len){
    int min;
    for(int i=0;i<len;++i){
        min = i;
        for(int j=i+1;j<len;++j){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        swap(&arr[i], &arr[min]);
        for(int j=0;j<len;++j){
            cout<<arr[j]<<" ";
        }
        cout<<endl;
    }
    return;
}

void insertionSort(int* arr, int len)
{
    int last;
    for(int i=1;i<len;++i){
        int j=i-1, r=arr[i];
        while(arr[j]>r){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=r;

        for (j = 0; j < len; ++j)
        {
            cout << arr[j] << " ";
        }
        cout << endl;
    }
}

void bubbleSort(int* arr, int len)
{
    bool flag=false;
    for (int i = len-1; i >=0; --i)
    {
        flag = false;
        for (int j = 0; j < i ; ++j)
        {
            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                flag = true;
            }
        }
        
        for (int j = 0; j < len; ++j)
        {
            cout << arr[j] << " ";
        }
        cout<<endl;

        if (!flag)
        {
            break;
        }
    }

}

int main(){
    int arr[] = {5,8,3,6,2};
    int len = sizeof(arr)/sizeof(int);
    selectionSort(arr, len);
    cout<<"===="<<endl;
    int arr1[] = {5, 8, 3, 6, 2};
    insertionSort(arr1, len);
    cout << "====" << endl;
    int arr2[] = {1, 2, 3, 4, 5};
    bubbleSort(arr2, len);
    return 0;
}