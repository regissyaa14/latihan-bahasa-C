 //Latihan merge sort
#include<stdio.h>

//fungsi yg dijalankan after void mergeSort
void gabungkan(int arr[], int kiri, int tengah, int kanan){
    int i, j, k; /*i untuk melacak array sementara bagian kiri, j untuk melacak 
    array sementara bagian kanan, k untuk melacak letak penulisan di array utama*/
    int n1 = tengah - kiri + 1; //menghitung jumlah elemen sebelah kiri
    int n2 = kanan - tengah; //menghitung jumlah elemen sebelah kanan
    
    int L[n1], R[n2]; /*array sementara untuk menyalin dan mengamankan angka-angka 
    dari potongan bagian kiri (Left) dan kanan (Right)*/
    
    //perulangan for untuk menyalin data asli
    for(i = 0; i < n1; i++) L[i] = arr[kiri + i];
    for(j = 0; j < n2; j++) R[j] = arr[tengah + 1 + j];
    
    //reset posisi awal penunjuk
    i = 0;
    j = 0;
    k = kiri;
    
    //selama wadah L & R masih ada representasi angka yang blm dicek, maka lakukan perbandingan dibawah
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){ /*kalau angka di kiri lebih kecil atau sama dengan angka di kanan
        maka angka tersebut yang diletakkan lebih dulu ke array utama (arr[k]), lalu penunjuk wadah kiri bergeser maju*/
            arr[k] = L[i];
            i++;
        } else { /*jika ternyata angka di kanan lebih kecil, maka angka di kanan yang dimasukkan ke array utama
        lalu penunjuk bagian kanan bergeser maju (j++)*/
            arr[k] = R[j];
            j++;
        }
        k++; /*apapun yang dimasukkan lebih dulu, posisi penulisan di array utama harus
        bergeser maju ke kotak berikutnya*/
    }
    while(i < n1){ /*kalau bagian kanan habis duluan, sisa angka di sebelah kiri langsung dimasukkan
    ke dalam array utama tanpa dibandingkan lagi*/
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j < n2){ /*sama seperti bagian kiri yang habis duluan*/
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int kiri, int kanan){
    if(kiri < kanan){ //kondisi base case, proses pembelahan elemen menjadi 1 bagian terjadi disini
        int tengah = kiri + (kanan - kiri) / 2; //mencari titik koordinat tepat di tengah array untuk membagi 2 elemen
        mergeSort(arr, kiri, tengah); //perintah membelah array bagian kiri sampai batas tengah
        mergeSort(arr, tengah + 1, kanan); //perintah membelah array bagian kanan, mulai dari tengah sampai index paling kanan
        gabungkan(arr, kiri, tengah, kanan); //menggabungkan elemen2 tunggal menjadi satu kesatuan array sambil diurutkan
    }
}


int main(){
    int i;
    int n;
    
    printf("Masukkan ukuran array: ");
    scanf("%d", &n);
    int arr[n];
    
    printf("Masukkan %d angka integer acak untuk mengisi array:\n", n);
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    
    printf("Nilai array yang sudah dimasukkan:\n");
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    mergeSort(arr, 0, n-1);
    printf("Data yang sudah diurutkan menggunakan metode Merge Sort:\n");
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
