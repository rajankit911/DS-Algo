#include <bits/stdc++.h>
#define forloop(i,s,e) for(int i=s; i<e; i++)

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

/*first element as pivot*/

void swap(int& a, int& b) {
    int temp;
    temp = b;
    b = a;
    a = temp;
}

int partition(int arr[], int low, int high) {

    int pivot = arr[low];
    int i = low, j = high;
    while(i <= j) {
        if(arr[i] > pivot && arr[j] < pivot)
            swap(arr[i], arr[j]); 
        
        if(arr[i] <= pivot) i++;
        if(arr[j] >= pivot) j--;
    }

    swap(arr[low], arr[j]);
    return j;
}

void quicksort(int arr[], int low, int high) {

    if(low < high) {
        int j = partition(arr, low, high);
        quicksort(arr,low,j-1);
        quicksort(arr,j+1,high);
    }
}

int main(int argc, char const *argv[])
{  
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif

    int n;
    cin >> n;
    int arr[n];

    for(int i=0; i<n;i++)
        cin >> arr[i];
    
    quicksort(arr,0,n-1);

    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    
} 