//Iterative Binary Search
#include<stdio.h>
int binarySearch(int arr[], int n, int x){
    int low = 0;
    int high = n - 1;
    
    while (low <= high){
        int mid = low + (high - low) / 2;
        
        //periksa apakah x ada di tengah
        if(arr[mid] == x)
            return mid;
        
        //jika x lebih besar, abaikan bagian kiri
        if(arr[mid] < x)
            low = mid + 1;
        
        //jika x lebih kecil, abaikan bagian kanan
        else
            high = mid - 1;
    }
    
    //jika melakukan bagian ini, maka elemen tersebut tidak ada
    return -1;
}

int main(){
    int i, j, n;
    int ketemu = 0;
    
    printf("Masukkan ukuran array: ");
    scanf("%d", &n);
    int arr[n];
    printf("\n");
    
    printf("Masukkan %d angka TERURUT MEMBESAR untuk mengisi nilai array:\n", n);
    for(i = 0; i < n; i++){
    scanf("%d", &arr[i]);
    }
    
    printf("\n");
    
    printf("Nilai yang sudah dimasukkan:\n");
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    printf("\nMasukkan nilai yang ingin dicari: ");
    scanf("%d", &j);
    printf("\n");
    
    int result = binarySearch(arr, n, j);
    
    if(result == -1){
        printf("Nilai tidak ada dalam array.\n");
    }
    else {
        printf("Nilai ada dalam index %d\n", result);
    }
    
return 0;
}