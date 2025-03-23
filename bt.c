#include <stdio.h>
// HeapSort 11.8
// QuickSort 21.3

// Tham an balo 1 2.92
// Tham an balo 2 3.91
// Tham an balo 3 4.94

// Nhanh an balo 1 5.94
// Nhanh an balo 2 6.87
// Nhanh an balo 3 8.28

// QHD balo 1 9.73
// QHD balo 2 1.085
// QHD balo 3 1.200

// ATM tham an 13.18
// TSP tham an 14.12

//TSP nhanh can 15.81

// Tam giac so QHD 17.47


typedef int keytype;
typedef float othertype;

typedef struct {
    keytype key;
    othertype otherfields;
} recordtype;

void Swap(recordtype *x, recordtype *y) {
    recordtype temp = *x;
    *x = *y;
    *y = temp;
}

//void SelectionSort(recordtype a[], int n) {
//    int i, j, lowindex;
//    keytype lowkey;
//    for (i = 0; i <= n -2; i++) {
//    	lowkey = a[i].key;
//        lowindex = i;
//        for (j = i + 1; j <= n - 1; j++) {
//            if (a[j].key < lowkey) {
//                lowkey = a[j].key;
//				lowindex = j;
//            }
//        }
//        Swap(&a[i], &a[lowindex]);
//    }
//}

//void InsertSort(recordtype a[],int n){
//	int i,j;
//	for(i=1;i<=n-1;i++){
//		j=i;
//		while(j>0 & a[j].key < a[j-1].key){
//			Swap(&a[j],&a[j-1]);
//			j--;
//		}
//		
//	}
//}

void BubbleSort(recordtype a[], int n) {
    int i, j;
    for (i = 0; i <= n - 2; i++) {
        for (j = n-1 ; j >=i + 1; j--) {
            if (a[j].key < a[j - 1].key) {
                Swap(&a[j], &a[j - 1]);
            }
        }
    }
}




void Read_Data(recordtype a[], int *n) {
    FILE *f = fopen("data.txt", "r");
    if (f == NULL) {
        printf("Loi mo file\n");
        return;
    }
    *n = 0;
    while (fscanf(f, "%d%f", &a[*n].key, &a[*n].otherfields) == 2) {
        (*n)++;
    }
    fclose(f);
}

void Print_Data(recordtype a[], int n) {
	int i;
    for (i = 0; i < n; i++) {
        printf("%3d %5d %8.2f\n", i + 1, a[i].key, a[i].otherfields);
    }
}

int main() {
    recordtype a[100];
    int n;

    printf("Thuat toan Selection_Sort\n\n");
    Read_Data(a, &n);
    printf("Du lieu truoc khi sap xep:\n");
    Print_Data(a, n);
//	SelectionSort(a,n);
//	InsertSort(a,n);
	BubbleSort(a,n);

    printf("Du lieu sau khi sap xep:\n");
    Print_Data(a, n);

    return 0;
}
// Heap Sort 118

#include <stdio.h>

typedef int keytype;
typedef float othertype;

typedef struct {
    keytype key;
    othertype otherfields;
} recordtype;

void Swap(recordtype *x, recordtype *y) {
    recordtype temp = *x;
    *x = *y;
    *y = temp;
}

void pushdown(recordtype a[], int first, int last){
    int r = first;
    int left, right;

    while (r <= (last - 1)/2) {
        left = 2 * r + 1;
        right = 2 * r + 2;

        if (last == left) {
            if (a[r].key > a[last].key) {
                Swap(&a[r], &a[last]);
            }
            r = last;
        }
        else if ((a[r].key > a[left].key) && (a[left].key <= a[right].key)) {
            Swap(&a[r], &a[left]);
            r = left;
        }
        else if ((a[r].key > a[right].key) && (a[right].key < a[left].key)) {
            Swap(&a[r], &a[right]);
            r = right;
        }
        else {
            r = last;
        }
    }
}

void heapsort(recordtype a[], int n) {
	int i;
    for (i = (n - 2) / 2; i >= 0; i--)
        pushdown(a, i, n-1);
    for (i = n - 1; i >= 2; i--) {
        Swap(&a[0], &a[i]);
        pushdown(a, 0, i - 1);  
    }
    Swap(&a[0],&a[1]);
}

void Read_Data(recordtype a[], int *n) {
    FILE *f = fopen("data.txt", "r");
    if (f == NULL) {
        printf("Loi mo file\n");
        return;
    }
    *n = 0;
    while (fscanf(f, "%d%f", &a[*n].key, &a[*n].otherfields) == 2) {
        (*n)++;
    }
    fclose(f);
}

void Print_Data(recordtype a[], int n) {
    int i;
    for (i = 0; i  < n; i++) {
        
        printf("%3d %5d %8.2f\n", i + 1, a[i].key, a[i].otherfields);
    }
}

int main() {
    recordtype a[100];
    int n;

    printf("Thuat toan Quick_Sort\n");
    Read_Data(a, &n);
    
    printf("Du lieu truoc khi sap xep:\n");
    Print_Data(a, n);

    heapsort(a,n);  

    printf("Du lieu sau khi sap xep:\n");
    Print_Data(a, n);

    return 0;
}
// QuickSort 213

#include <stdio.h>

typedef int keytype;
typedef float othertype;

typedef struct {
    keytype key;
    othertype otherfields;
} recordtype;

void swap(recordtype *x, recordtype *y) {
    recordtype temp = *x;
    *x = *y;
    *y = temp;
}

int partition(recordtype a[], int low, int high) {
	int j;
    keytype pivot = a[high].key; 
    int i = low - 1;
    for (j = low; j <= high - 1; j++) {
        if (a[j].key < pivot) {  
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[high]);  
    return i + 1;
}

void quickSort(recordtype a[], int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);

        quickSort(a, low, pi - 1);  
        quickSort(a, pi + 1, high); 
    }
}

void Read_Data(recordtype a[], int *n) {
    FILE *f = fopen("data.txt", "r");
    if (f == NULL) {
        printf("Loi mo file\n");
        return;
    }
    *n = 0;
    while (fscanf(f, "%d%f", &a[*n].key, &a[*n].otherfields) == 2) {
        (*n)++;
    }
    fclose(f);
}

void Print_Data(recordtype a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        
        printf("%3d %8d %8.2f\n", i + 1, a[i].key, a[i].otherfields);
    }
}

int main() {
    recordtype a[100];
    int n;

    printf("Thuat toan Quick_Sort\n");
    Read_Data(a, &n);
    
    printf("Du lieu truoc khi sap xep:\n");
    Print_Data(a, n);

    quickSort(a, 0, n - 1);  

    printf("Du lieu sau khi sap xep:\n");
    Print_Data(a, n);

    return 0;
}
// Tham an Balo 1 292
// Bai toan Cai ba lo 1
// Moi do vat co so luong khong han che 
// Du lieu cho trong file CaiBalo1.TXT
// Giai bai toan bang thuat toan THAM AN

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct {
	char TenDV[20];
	float TL, GT, DG;
	int PA;
}DoVat;

DoVat *ReadFromFile(float *W, int *n){
     FILE *f;
     f = fopen("CaiBalo1.TXT", "r");
     fscanf(f, "%f",W); // Xac dinh trong luong Ba lo
	 DoVat *dsdv;
	 dsdv=(DoVat*)malloc(sizeof(DoVat));
	 int i=0;
 	 while (!feof(f)){
	   fscanf(f, "%f%f%[^\n]",&dsdv[i].TL,&dsdv[i].GT,&dsdv[i].TenDV);
	   dsdv[i].DG=dsdv[i].GT/dsdv[i].TL;
	   dsdv[i].PA=0;
	   i++;
	   dsdv=(DoVat*)realloc(dsdv, sizeof(DoVat)*(i+1));  
	 }
	 *n=i;
     fclose(f);
     return dsdv;
}

void swap(DoVat *x, DoVat *y){
	DoVat Temp;
	Temp = *x;
	*x   = *y;
	*y   = Temp;
}

void BubbleSort(DoVat *dsdv, int n){
	int i,j;
	for(i=0; i<=n-2; i++)
	   for (j=n-1; j>=i+1; j--){
	   	 if (dsdv[j].DG>dsdv[j-1].DG) 
			swap(&dsdv[j],&dsdv[j-1]);
	  }   
}

void InDSDV(DoVat *dsdv, int n, float W){
	int i;
	float TongTL=0.0, TongGT=0.0;
	printf("\nPhuong an Cai Ba lo 1 dung thuat toan THAM AN nhu sau:\n");
	printf("\nTrong luong cua ba lo = %-9.2f\n",W);
	printf("|---|------------------|---------|---------|---------|-----------|\n");
	printf("|STT|     Ten Do Vat   | T Luong | Gia Tri | Don Gia | Phuong an |\n");
	printf("|---|------------------|---------|---------|---------|-----------|\n");
	for(i=0;i<n;i++){
		printf("|%2d |%-18s|%9.2f|%9.2f|%9.2f|%6d     |\n",
		i+1,dsdv[i].TenDV,dsdv[i].TL,dsdv[i].GT,dsdv[i].DG,dsdv[i].PA);
		TongTL=TongTL+dsdv[i].PA * dsdv[i].TL;
		TongGT=TongGT+dsdv[i].PA * dsdv[i].GT;
	}	
	printf("|---|------------------|---------|---------|---------|-----------|\n");	
	printf("Phuong an (theo thu tu DG giam dan): X(");
	for(i=0; i<n-1; i++){
		printf("%d,", dsdv[i].PA);
	}	
	printf("%d)", dsdv[n-1].PA);
	printf("\nTong trong luong = %-9.2f\n",TongTL);
	printf("Tong gia tri = %-9.2f\n",TongGT);
	
	

}

void Greedy(DoVat *dsdv,int n, float W){
  int i;
  for(i=0; i<n; i++) {
     dsdv[i].PA = (W/dsdv[i].TL);
     W = W-dsdv[i].PA * dsdv[i].TL;
  }
}

int main(){
	int n;
	float W;
	DoVat *dsdv;
	
	dsdv=ReadFromFile(&W, &n);
    BubbleSort(dsdv,n);
	Greedy(dsdv,n,W);
	InDSDV(dsdv,n,W);
	
	free(dsdv);
	return 0;
}
// Tham an balo 2 391
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct {
    char TenDV[20];
    float TL, GT, DG;
    int SL, PA;
} DoVat;

DoVat* ReadFromFile(float* W, int* n) {
    FILE* f = fopen("CaiBalo2.TXT", "r");
    if (f == NULL) {
        printf("Loi khi mo file\n");
        return NULL;
    }

    fscanf(f, "%f", W); 
    DoVat* dsdv = (DoVat*)malloc(sizeof(DoVat));
    int i = 0;

    while (!feof(f)) {
        fscanf(f, "%f%f%d%[^\n]", &dsdv[i].TL, &dsdv[i].GT, &dsdv[i].SL, dsdv[i].TenDV);
        dsdv[i].DG = dsdv[i].GT / dsdv[i].TL; 
        dsdv[i].PA = 0; 
        i++;
        dsdv = (DoVat*)realloc(dsdv, sizeof(DoVat) * (i + 1));
    }
    *n = i;
    fclose(f);
    return dsdv;
}

void swap(DoVat* x, DoVat* y) {
    DoVat Temp = *x;
    *x = *y;
    *y = Temp;
}

void BubbleSort(DoVat* dsdv, int n) {
    int i, j;
    for (i = 0; i <= n - 2; i++) {
        for (j = n - 1; j >= i + 1; j--) {
            if (dsdv[j].DG > dsdv[j - 1].DG)
                swap(&dsdv[j], &dsdv[j - 1]);
        }
    }
}

void InDSDV(DoVat* dsdv, int n, float W) {
    int i;
    float TongTL = 0.0, TongGT = 0.0;

    printf("\nPhuong an Cai Ba lo 1 dung thuat toan THAM AN nhu sau:\n");
    printf("\nTrong luong cua ba lo = %-9.2f\n", W);
    printf("|---|------------------|---------|---------|--------|---------|-----------|\n");
    printf("|STT|     Ten Do Vat   | T Luong | Gia Tri |So Luong| Don Gia | Phuong an |\n");
    printf("|---|------------------|---------|---------|--------|---------|-----------|\n");

    for (i = 0; i < n; i++) {
        printf("|%2d |%-18s|%9.2f|%9.2f|%6d  |%9.2f|%6d     |\n",
               i + 1, dsdv[i].TenDV, dsdv[i].TL, dsdv[i].GT, dsdv[i].SL, dsdv[i].DG,dsdv[i].PA);
        TongTL = TongTL + dsdv[i].PA * dsdv[i].TL;
        TongGT = TongGT + dsdv[i].PA * dsdv[i].GT;
    }
    printf("|---|------------------|---------|---------|--------|---------|-----------|\n");
    printf("Phuong an (theo thu tu DG giam dan): X(");
    for (i = 0; i < n - 1; i++) {
        printf("%d,", dsdv[i].PA);
    }
    printf("%d)", dsdv[n - 1].PA);
    printf("\nTong trong luong = %-9.2f\n", TongTL);
    printf("Tong gia tri = %-9.2f\n", TongGT);
}


void Greedy(DoVat* dsdv, int n, float W) {
    int i;
    for (i = 0; i < n; i++) {
        int max = (int)(W / dsdv[i].TL);  
        dsdv[i].PA = (max <= dsdv[i].SL) ? max : dsdv[i].SL; 

        W -= dsdv[i].PA * dsdv[i].TL;
    }
}

int main() {
    int n;
    float W;
    DoVat* dsdv;

    dsdv = ReadFromFile(&W, &n);
    if (dsdv == NULL) return 1;

    BubbleSort(dsdv, n);  
    Greedy(dsdv, n, W);   
    InDSDV(dsdv, n, W);   

    free(dsdv); 
    return 0;
}

// THam an balo 3 494
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct {
    char TenDV[20]; // Item name
    float TL,GT,DG;       // Weight of the item
    int PA;         // Packed quantity (0 or 1 for 0/1 knapsack)
} DoVat;

DoVat *ReadFromFile(float *W, int *n) {
    FILE *f;
    f = fopen("CaiBalo3.TXT", "r");
    fscanf(f, "%f", W); // Knapsack weight capacity
    DoVat *dsdv;
    dsdv = (DoVat*)malloc(sizeof(DoVat));
    int i = 0;
    while (!feof(f)) {
        fscanf(f, "%f%f%[^\n]", &dsdv[i].TL, &dsdv[i].GT, &dsdv[i].TenDV);
        dsdv[i].DG = dsdv[i].GT / dsdv[i].TL; // Value-to-weight ratio
        dsdv[i].PA = 0; // Initially, no items are packed
        i++;
        dsdv = (DoVat*)realloc(dsdv, sizeof(DoVat)*(i+1));
    }
    *n = i;
    fclose(f);
    return dsdv;
}

// Swap two items
void swap(DoVat *x, DoVat *y) {
    DoVat Temp;
    Temp = *x;
    *x = *y;
    *y = Temp;
}

// Sort items by their value-to-weight ratio in descending order
void BubbleSort(DoVat *dsdv, int n) {
    int i, j;
    for(i = 0; i <= n - 2; i++)
        for (j = n - 1; j >= i + 1; j--) {
            if (dsdv[j].DG > dsdv[j - 1].DG) 
                swap(&dsdv[j], &dsdv[j - 1]);
        }
}

// Print the selected items and the result
void InDSDV(DoVat *dsdv, int n, float W) {
    int i;
    float TongTL = 0.0, TongGT = 0.0;
    printf("\nPhuong an Cai Ba lo 1 dung thuat toan THAM AN nhu sau:\n");
    printf("\nTrong luong cua ba lo = %-9.2f\n", W);
    printf("|---|------------------|---------|---------|---------|-----------|\n");
    printf("|STT|     Ten Do Vat   | T Luong | Gia Tri | Don Gia | Phuong an |\n");
    printf("|---|------------------|---------|---------|---------|-----------|\n");
    for(i = 0; i < n; i++) {
        printf("|%2d |%-18s|%9.2f|%9.2f|%9.2f|%6d     |\n",
            i + 1, dsdv[i].TenDV, dsdv[i].TL, dsdv[i].GT, dsdv[i].DG, dsdv[i].PA);
        TongTL = TongTL + dsdv[i].PA * dsdv[i].TL;
        TongGT = TongGT + dsdv[i].PA * dsdv[i].GT;
    }   
    printf("|---|------------------|---------|---------|---------|-----------|\n");    
    printf("Phuong an (theo thu tu DG giam dan): X(");
    for(i = 0; i < n - 1; i++) {
        printf("%d,", dsdv[i].PA);
    }   
    printf("%d)", dsdv[n - 1].PA);
    printf("\nTong trong luong = %-9.2f\n", TongTL);
    printf("Tong gia tri = %-9.2f\n", TongGT);
}

void Greedy(DoVat *dsdv, int n, float W) {
    int i;
    for(i = 0; i < n; i++) {
        if (dsdv[i].TL <= W) { // If the item fits in the knapsack
            dsdv[i].PA = 1;     // Take the item
            W -= dsdv[i].TL;    // Decrease the remaining capacity
        }
    }
}

int main() {
    int n;
    float W;
    DoVat *dsdv;

    dsdv = ReadFromFile(&W, &n);

    BubbleSort(dsdv, n);

    Greedy(dsdv, n, W);

    InDSDV(dsdv, n, W);

    free(dsdv);
    return 0;
}

//NHanh can balo 1 594
#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define MAX_N 100

typedef struct {
    int w, v, qty;
    float ppu; //price per unit
    char name[25];    
} item;

void swap (item *a, item* b){
    item temp = *a;
    *a = *b;
    *b = temp;
}

void sort (item *a, int n){
    for(int i = 0; i < n-1; i++)
        for(int j = i+1; j < n; j++)
            if(a[i].ppu < a[j].ppu)
                swap(&a[i], &a[j]);
}

void readFile (item **a, int *n, int *m){
    FILE *f = fopen("CaiBalo1.txt", "r");
    *a = (item*)malloc(sizeof(item));
    fscanf(f, "%d", m);
    int i = 0;    
    while (!feof(f)){
        (*a) = realloc(*a, sizeof(item)*(i+1));
        fscanf(f, "\n%d %d %[^\r\n]s", &(*a)[i].w, &(*a)[i].v, (*a)[i].name);
        (*a)[i].ppu = (float)(*a)[i].v / (*a)[i].w;
        (*a)[i].qty = 0;
        i++;
    }
    *n = i;
}

void printChart (item *a, int n, int m){
    int total_val = 0, total_weight = 0;
    printf("|---|---------------------|-----------|-------|-------|---------|\n");
	printf("|%-3s|%-21s|%-11s|%-7s|%-7s|%-9s|\n", "STT", "     Ten do vat", "Trong luong", "Gia tri", "Don gia","Phuong an");
	printf("|---|---------------------|-----------|-------|-------|---------|\n");
	for(int i = 0, k = 1; i < n; i++){        
        printf("| %-2d| %-20s|%11d|%7d|%7.2f|%9d|\n", k++, a[i].name, a[i].w, a[i].v, a[i].ppu, a[i].qty);
        total_val += a[i].v*a[i].qty;
        total_weight += a[i].w*a[i].qty;
	}	
	printf("|---|---------------------|-----------|-------|-------|---------|\n");	
	printf("Phuong an (theo thu tu DG giam dan): X(");
	for(int i=0; i<n-1; i++){
		printf("%d,", a[i].qty);
	}	
	printf("%d)\n", a[n-1].qty);
	printf("Trong luong cua ba lo = %5d\n",m);
    printf("Tong trong luong      = %5d\n", total_weight);
    printf("Tong gia tri          = %5d\n", total_val);
}

void solve(item *a, int n, int p_val, int m, int x[], int i, float *final_res){
	for(int j = m/a[i].w; j >= 0; j--){
		float cur_val, remain, ubound;
		cur_val= p_val + j*a[i].v;
		remain = m - j*a[i].w;
		ubound = cur_val + remain*a[i+1].ppu;
		if(ubound > *final_res){
			x[i] = j;			
			if((i == n-1 || remain == 0) && cur_val > *final_res){
				*final_res = cur_val;
				for(int k = 0; k < n; k++){
					a[k].qty = x[k];
				}		
			}
			else
				solve(a, n, cur_val, remain, x, i+1, final_res);
		}		
		x[i] = 0;	
	}
}

int main (){
	item *a;
	int n, m, x[MAX_N];
	float final_res = 0;
	readFile(&a, &n, &m);
	sort(a, n);	
	solve(a, n, 0, m, x, 0, &final_res);
	printChart(a, n, m);
}

// Nhanh an balo 2 687
// Bai toan Cai ba lo 2
// Moi do vat co so luong xac dinh
// Du lieu cho trong file CaiBalo2.INP
// Giai bai toan bang thuat toan NHANH CAN

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct {
	char TenDV[20];
	float TL, GT, DG;
	int SL, PA;
} DoVat;

DoVat * ReadFromFile(float *W, int *n){
     FILE *f;
     f = fopen("CaiBalo2.txt", "r");
     fscanf(f, "%f",W); // Xac dinh trong luong Ba lo
	 DoVat *dsdv;
	 dsdv=(DoVat*)malloc(sizeof(DoVat));
	 int i=0;
 	 while (!feof(f)){
	   fscanf(f, "%f%f%d%[^\n]",&dsdv[i].TL,&dsdv[i].GT,&dsdv[i].SL,&dsdv[i].TenDV);
	   dsdv[i].DG=dsdv[i].GT/dsdv[i].TL;
	   dsdv[i].PA=0;
	   i++;
	   dsdv=(DoVat*)realloc(dsdv, sizeof(DoVat)*(i+1));  
	 }
	 *n=i;
     fclose(f);
     return dsdv;
}

void swap(DoVat *x, DoVat *y){
	DoVat Temp;
	Temp = *x;
	*x   = *y;
	*y   = Temp;
}

void BubbleSort(DoVat *dsdv, int n){
	int i,j;
	for(i=0; i<=n-2; i++)
	   for (j=n-1; j>=i+1; j--){
	   	 if (dsdv[j].DG>dsdv[j-1].DG) 
			swap(&dsdv[j],&dsdv[j-1]);
	  }   
}

void InDSDV(DoVat *dsdv ,int n, float W){
	int i;
	float TongTL=0.0, TongGT=0.0;
	printf("\nPhuong an Cai Ba lo 2 dung thuat toan NHANH CAN nhu sau:\n");
	printf("|---|--------------------|---------|---------|---------|---------|-----------|\n");
	printf("|STT|     Ten Do Vat     |T. Luong | Gia Tri |So luong | Don gia | Phuong an |\n");
	printf("|---|--------------------|---------|---------|---------|---------|-----------|\n");
	for(i=0;i<n;i++){
		printf("|%2d |%-20s|%9.2f|%9.2f|%5d    |%9.2f|%6d     |\n",
		i+1,dsdv[i].TenDV,dsdv[i].TL,dsdv[i].GT,dsdv[i].SL,dsdv[i].DG, dsdv[i].PA);
		TongTL=TongTL+dsdv[i].PA * dsdv[i].TL;
		TongGT=TongGT+dsdv[i].PA * dsdv[i].GT;
	}	
	printf("|---|--------------------|---------|---------|---------|---------|-----------|\n");	
	printf("Trong luong cua ba lo = %-9.2f\n",W);
	printf("Tong trong luong = %-9.2f\n",TongTL);
	printf("Tong gia tri = %-9.2f\n",TongGT);
}

// Tinh cac dai luong tai nut goc
void Tao_Nut_Goc(float W, float *V, float *CT, float *GLNTT, float *TGT, float DG_Max){
	*TGT = 0.0;
	*V = W;
	*CT = *V * DG_Max; 	// Can tren cua nut goc
	*GLNTT = 0.0;
} 

//Ghi nhan phuong an tot nhat tam thoi
void Cap_Nhat_GLNTT(float TGT, float *GLNTT, int x[], DoVat *dsdv, int n){
	 int i;
	 if(*GLNTT < TGT){
		 *GLNTT = TGT;
		 for(i=0;i<n;i++)
		 	dsdv[i].PA=x[i];
	 }
}

int min(int a, int b){
	return a<b? a:b;
}

void Nhanh_Can(int i, float *TGT, float *CT, float *V, float *GLNTT, int x[], DoVat *dsdv, int n){
	 int j; 	// j la so vat duoc chon
	 int yk; 	// So do vat lon nhat co the chon
	 yk = min(dsdv[i].SL, *V/dsdv[i].TL);	
	 for(j = yk; j>=0; j--){	// Xet tat ca cac kha nang co the phan nhanh theo so luong do vat
	 		// Ung voi mot gia tri cua j la mot nut tren cay 
	 		// Tinh 3 dai luong cua mot nut trong
	 		
		 *TGT = *TGT + j*dsdv[i].GT;
		 *V = *V - j*dsdv[i].TL;
		 *CT = *TGT + *V * dsdv[i+1].DG;	// dsdv[i+1].DG la DG vat ke tiep cua vat i (i + 1)
		
		 if(*CT > *GLNTT){ 					// Truong hop Chua cat tia (Dieu kien Cat tia la khi CT <= GLNTT)
			x[i] = j;
		 	if((i==n-1)||(*V==0)) 		// Da xet het tat ca cac do vat hoac ba lo da day
		 		Cap_Nhat_GLNTT(*TGT, GLNTT, x, dsdv, n);
		 	else
		 		Nhanh_Can(i+1, TGT, CT, V, GLNTT, x, dsdv, n); //Xet nut con cua nut i
	 	}
	 // Quay lui xet nut khac
	 x[i] = 0;
	 *TGT = *TGT - j*dsdv[i].GT;	// Tra lai Tong gia tri cua nut cha
	 *V = *V + j*dsdv[i].TL;		// Tra lai Trong luong con lai cua nut cha
	 }
}
	
int main(){
	DoVat * dsdv;	// Danh sach cac do vat (mang dong cua cac do vat)
	int n; 			// luu so luong do vat
	float W; 		// Luu trong luong cua Ba lo
	
	float CT; 		// Luu can tren
	float TGT; 		// Luu Tong gia tri cua cac vat da duoc chon tai moi nut
	float V; 		// Luu Trong luong con lai cua Ba lo tai moi nut
	float GLNTT; 	// Luu Gia lon nhat tam thoi 
	
	dsdv = ReadFromFile(&W, &n);
	
	int x[n];		// Luu phuong an tot nhat tam thoi
	
	BubbleSort(dsdv,n);
	Tao_Nut_Goc(W, &V, &CT, &GLNTT, &TGT, dsdv[0].DG);
	Nhanh_Can(0, &TGT, &CT, &V, &GLNTT, x, dsdv, n);
	InDSDV(dsdv,n,W);
	
	free(dsdv);
	return 0;
}

// Nhanh can balo 3 828
//Moi do vat chi co mot cai

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct {
    char TenDV[20];  // Ten do vat
    float TL, GT, DG; // Trong luong, gia tri, va ty le gia tri/trong luong
    int SL,PA; // So luong do vat (SL = 1), Phuong an chon (PA = 1 neu chon, PA = 0 neu khong)
} DoVat;

// Doc du lieu tu file CaiBalo2.txt
DoVat* ReadFromFile(float* W, int* n) {
    FILE* f;
    f = fopen("CaiBalo3.txt", "r");
    fscanf(f, "%f", W); // Xac dinh trong luong Ba lo
    DoVat* dsdv;
    dsdv = (DoVat*)malloc(sizeof(DoVat));
    int i = 0;
    while (!feof(f)) {
        fscanf(f, "%f%f%[^\n]", &dsdv[i].TL, &dsdv[i].GT, dsdv[i].TenDV);
        dsdv[i].SL = 1; // Moi mon do chi co 1 cai
        dsdv[i].DG = dsdv[i].GT / dsdv[i].TL; // Tinh ty le gia tri/trong luong
        dsdv[i].PA = 0; // Co danh dau phuong an chon (0: chua chon, 1: da chon)
        i++;
        dsdv = (DoVat*)realloc(dsdv, sizeof(DoVat)*(i + 1));  
    }
    *n = i;
    fclose(f);
    return dsdv;
}

// Hoan doi 2 do vat
void swap(DoVat* x, DoVat* y) {
    DoVat Temp;
    Temp = *x;
    *x = *y;
    *y = Temp;
}

// Sap xep danh sach do vat theo ty le gia tri/trong luong giam dan
void BubbleSort(DoVat* dsdv, int n) {
    int i, j;
    for (i = 0; i <= n - 2; i++)
        for (j = n - 1; j >= i + 1; j--) {
            if (dsdv[j].DG > dsdv[j - 1].DG)
                swap(&dsdv[j], &dsdv[j - 1]);
        }
}

// In danh sach do vat va ket qua
void InDSDV(DoVat* dsdv, int n, float W) {
    int i;
    float TongTL = 0.0, TongGT = 0.0;
    printf("\nPhuong an cai ba lo 01 nhu sau:\n");
    printf("|---|--------------------|---------|---------|---------|---------|-----------|\n");
    printf("|STT|     Ten Do Vat     |T. Luong | Gia Tri | So Luong| Don Gia | Phuong An |\n");
    printf("|---|--------------------|---------|---------|---------|---------|-----------|\n");
    for (i = 0; i < n; i++) {
        printf("|%2d |%-20s|%9.2f|%9.2f|%5d    |%9.2f|%6d     |\n",
               i + 1, dsdv[i].TenDV, dsdv[i].TL, dsdv[i].GT, dsdv[i].SL, dsdv[i].DG, dsdv[i].PA);
        TongTL = TongTL + dsdv[i].PA * dsdv[i].TL;
        TongGT = TongGT + dsdv[i].PA * dsdv[i].GT;
    }
    printf("|---|--------------------|---------|---------|---------|---------|-----------|\n");
    printf("Trong luong ba lo = %-9.2f\n", W);
    printf("Tong trong luong = %-9.2f\n", TongTL);
    printf("Tong gia tri = %-9.2f\n", TongGT);
}

// Tao cac dai luong ban dau
void Tao_Nut_Goc(float W, float* V, float* CT, float* GLNTT, float* TGT, float DG_Max) {
    *TGT = 0.0;
    *V = W;
    *CT = *V * DG_Max; // Can tren cua nut goc
    *GLNTT = 0.0;
}

// Cap nhat gia tri lon nhat tam thoi
void Cap_Nhat_GLNTT(float TGT, float* GLNTT, int x[], DoVat* dsdv, int n) {
    int i;
    if (*GLNTT < TGT) {
        *GLNTT = TGT;
        for (i = 0; i < n; i++)
            dsdv[i].PA = x[i]; // Luu phuong an tot nhat
    }
}

// Ham tim gia tri nho hon cua 2 so
int min(int a, int b) {
    return a < b ? a : b;
}

// Thuat toan Nhanh Can (Branch and Bound)
void Nhanh_Can(int i, float* TGT, float* CT, float* V, float* GLNTT, int x[], DoVat* dsdv, int n) {
    int j;  // j la so do vat duoc chon (0 hoac 1)
    int yk;  // So do vat toi da co the chon

    yk = min(dsdv[i].SL, *V / dsdv[i].TL);  // Tinh so mon do toi da co the chon

    for (j = yk; j >= 0; j--) {  // Chon tu 0 den yk mon do
        *TGT = *TGT + j * dsdv[i].GT;
        *V = *V - j * dsdv[i].TL;
        *CT = *TGT + *V * dsdv[i + 1].DG; // Can tren cho nut tiep theo

        if (*CT > *GLNTT) {  // Neu khong cat tia
            x[i] = j;
            if ((i == n - 1) || (*V == 0))  // Da xet het do vat hoac ba lo day
                Cap_Nhat_GLNTT(*TGT, GLNTT, x, dsdv, n);  // Cap nhat phuong an tot nhat
            else
                Nhanh_Can(i + 1, TGT, CT, V, GLNTT, x, dsdv, n);  // Tien sau vao cay tim kiem
        }

        // Quay lai xet cac truong hop khac
        x[i] = 0;
        *TGT = *TGT - j * dsdv[i].GT;  // Quay lai gia tri cua nut cha
        *V = *V + j * dsdv[i].TL;     // Quay lai trong luong con lai cua nut cha
    }
}

int main() {
    DoVat* dsdv;  // Danh sach cac do vat (mang dong)
    int n;         // So luong do vat
    float W;       // Trong luong cua ba lo

    float CT;      // Can tren
    float TGT;     // Tong gia tri cua cac do vat da chon
    float V;       // Trong luong con lai cua ba lo
    float GLNTT;   // Gia tri lon nhat tam thoi

    dsdv = ReadFromFile(&W, &n);

    int x[n];      // Luu phuong an toan canh tam thoi

    BubbleSort(dsdv, n);
    Tao_Nut_Goc(W, &V, &CT, &GLNTT, &TGT, dsdv[0].DG);
    Nhanh_Can(0, &TGT, &CT, &V, &GLNTT, x, dsdv, n);
    InDSDV(dsdv, n, W);

    free(dsdv);
    return 0;
}

// Bai toan cai ba lo 1 973
// Moi do vat co so luong khong han che
// Du lieu cho trong file QHD_CaiBalo.INP
// Giai bai toan bang thuat toan QUY HOACH DONG

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct {
	char TenDV[20];
	int TL, GT, PA;
} DoVat;

typedef int bang[50][100];// Ba lo co trong luong toi da 99 va co toi da 50 do vat

DoVat *ReadFromFile(int *W, int *n){
     FILE *f;
     f = fopen("CaiBalo1,3.txt", "r");
     fscanf(f, "%d",W); // Xac dinh trong luong Ba lo
	 DoVat *dsdv;
	 dsdv=(DoVat*)malloc(sizeof(DoVat));
	 int i=0;
 	 while (!feof(f)){
	   fscanf(f, "%d%d%[^\n]",&dsdv[i].TL,&dsdv[i].GT,&dsdv[i].TenDV);
	   dsdv[i].PA=0;
	   i++;
	   dsdv=(DoVat*)realloc(dsdv,sizeof(DoVat)*(i+1));  
	 }
	 *n=i;
     fclose(f);
     return dsdv;
}

void InDSDV(DoVat *dsdv ,int n, int W){
	int i, TongTL=0, TongGT=0;
	printf("\nPhuong an Cai Ba lo 1 dung thuat toan QUY HOACH DONG nhu sau:\n");
		printf("|---|------------------|----------|---------|-----------|\n");
		printf("|STT|     Ten Do Vat   | T Luong  | Gia Tri | Phuong an |\n");
		printf("|---|------------------|----------|---------|-----------|\n");
	for(i=0;i<n;i++){
		printf("|%2d |%-18s|%5d     |%5d    |%6d     |\n",
		i+1,dsdv[i].TenDV,dsdv[i].TL,dsdv[i].GT,dsdv[i].PA);
		TongTL=TongTL+dsdv[i].PA * dsdv[i].TL;
		TongGT=TongGT+dsdv[i].PA * dsdv[i].GT;
	}	
	printf("|---|------------------|----------|---------|-----------|\n");	
	printf("Trong luong cua ba lo = %-9d\n",W);
	printf("Tong trong luong = %-9d\n",TongTL);
	printf("Tong gia tri = %-9d\n",TongGT);
}

void TaoBang(DoVat *dsdv,int n,int W, bang F,bang X){
 	int xk, yk, k;
 	int FMax, XMax, V;
	
	// Dien dong dau tien cua hai bang
 	for(V= 0; V<=W; V++) {
 		X[0][V] = V/dsdv[0].TL;
 		F[0][V] = X[0][V] * dsdv[0].GT;
 	}
	
	//  ien c c d ng c n lai
	 for(k= 1; k<n; k++)
		 for(V=0; V<=W; V++) {
			 FMax = F[k-1][V] ;
			 XMax = 0;
			 yk = V/dsdv[k].TL;
			 for(xk = 1; xk<=yk; xk++)
			 	if(F[k-1][V-xk*dsdv[k].TL]+xk*dsdv[k].GT>FMax){
			 		FMax=F[k-1][V-xk*dsdv[k].TL]+xk*dsdv[k].GT;
			 		XMax= xk;
			 		}
			 F[k][V] = FMax;
			 X[k][V] = XMax;
	 	}
}

void InBang(int n, int W, bang F, bang X){
	int V, k;
	for(k=0; k<n; k++){
		for(V=0; V<=W; V++)
		 	printf("|%4d%2d",F[k][V], X[k][V]);
		printf("\n");
	}
}

void TraBang(DoVat *dsdv, int n, int W, bang X) {
	int k, V;
	V = W;
	for(k= n-1; k>=0; k--) {
	 	dsdv[k].PA = X[k][V];
	 	V = V - X[k][V] * dsdv[k].TL;
	}
}

int main(){
	int n, W;
	bang X,F;
	DoVat *dsdv;
	dsdv=ReadFromFile(&W, &n);
	
	TaoBang(dsdv,n,W,F,X);
	InBang(n,W,F,X);
	printf("\n");
	TraBang(dsdv,n,W,X);
	InDSDV(dsdv,n,W);
	
	free(dsdv);
	return 0;
}

#include <stdio.h> //1085
#include <malloc.h>
#include <string.h>

typedef struct {
    char TenDV[20];
    int TL, GT, PA, SL; // Them truong SL (so luong) vao
} DoVat;

typedef int bang[50][100]; // Ba lo co trong luong toi da 99 va co toi da 50 do vat

// Doc du lieu tu file
DoVat *ReadFromFile(int *W, int *n){
    FILE *f;
    f = fopen("CaiBalo2.txt", "r");
    fscanf(f, "%d", W); // Xac dinh trong luong Ba lo
    DoVat *dsdv;
    dsdv = (DoVat*)malloc(sizeof(DoVat));
    int i = 0;
    while (!feof(f)) {
        fscanf(f, "%d%d%d%[^\n]", &dsdv[i].TL, &dsdv[i].GT, &dsdv[i].SL, dsdv[i].TenDV);
        dsdv[i].PA = 0;
        i++;
        dsdv = (DoVat*)realloc(dsdv, sizeof(DoVat) * (i + 1));  
    }
    *n = i;
    fclose(f);
    return dsdv;
}

// In danh sach do vat
void InDSDV(DoVat *dsdv, int n, int W) {
    int i, TongTL = 0, TongGT = 0;
    printf("\nPhuong an Cai Ba lo 2 dung thuat toan QUY HOACH DONG nhu sau:\n");
    printf("|---|------------------|----------|---------|----------|-----------|\n");
    printf("|STT|     Ten Do Vat   | T Luong  | Gia Tri | So luong | Phuong an |\n");
    printf("|---|------------------|----------|---------|----------|-----------|\n");
    for(i = 0; i < n; i++) {
        printf("|%2d |%-18s|%5d     |%5d    |%5d     |%6d     |\n",
            i + 1, dsdv[i].TenDV, dsdv[i].TL, dsdv[i].GT, dsdv[i].SL, dsdv[i].PA);
        TongTL = TongTL + dsdv[i].PA * dsdv[i].TL;
        TongGT = TongGT + dsdv[i].PA * dsdv[i].GT;
    }  
    printf("|---|------------------|----------|---------|----------|-----------|\n");
    printf("Trong luong cua ba lo = %-9d\n", W);
    printf("Tong trong luong = %-9d\n", TongTL);
    printf("Tong gia tri = %-9d\n", TongGT);
}

// Tao bang DP cho bai toan
void TaoBang(DoVat *dsdv, int n, int W, bang F, bang X) {
    int xk, yk, k;
    int FMax, XMax, V;

    // Dien dong dau tien cua bang DP
    for(V = 0; V <= W; V++) {
        X[0][V] = V / dsdv[0].TL;  // Luong toi da do vat co the chon
        if(X[0][V] > dsdv[0].SL) X[0][V] = dsdv[0].SL;  // Khong vuot qua so luong co san
        F[0][V] = X[0][V] * dsdv[0].GT;
    }

    // Cac dong tiep theo cua bang DP
    for(k = 1; k < n; k++)
        for(V = 0; V <= W; V++) {
            FMax = F[k - 1][V];
            XMax = 0;
            yk = V / dsdv[k].TL;  // Tinh so luong toi da co the lay
            if(yk > dsdv[k].SL) yk = dsdv[k].SL;  // Gioi han theo so luong co san cua do vat k
            for(xk = 1; xk <= yk; xk++) {
                if(F[k - 1][V - xk * dsdv[k].TL] + xk * dsdv[k].GT > FMax) {
                    FMax = F[k - 1][V - xk * dsdv[k].TL] + xk * dsdv[k].GT;
                    XMax = xk;
                }
            }
            F[k][V] = FMax;
            X[k][V] = XMax;
        }
}

// In bang DP (chi danh cho debug)
void InBang(int n, int W, bang F, bang X) {
    int V, k;
    for(k = 0; k < n; k++) {
        for(V = 0; V <= W; V++)
            printf("|%4d%2d", F[k][V], X[k][V]);
        printf("\n");
    }
}

// Truy vet lai phuong an
void TraBang(DoVat *dsdv, int n, int W, bang X) {
    int k, V;
    V = W;
    for(k = n - 1; k >= 0; k--) {
        dsdv[k].PA = X[k][V];
        V = V - X[k][V] * dsdv[k].TL;
    }
}

// Ham main
int main() {
    int n, W;
    bang X, F;
    DoVat *dsdv;
    dsdv = ReadFromFile(&W, &n);
     
    TaoBang(dsdv, n, W, F, X);
    InBang(n, W, F, X);  // Neu can in bang DP, co the bo comment
    TraBang(dsdv, n, W, X);
    InDSDV(dsdv, n, W);
    
    free(dsdv);
    return 0;
}

#include <stdio.h> //1200
#include <malloc.h>
#include <string.h>

typedef struct {
    char TenDV[20];
    int TL, GT, PA; // PA la phuong an chon do vat
} DoVat;

typedef int bang[50][100]; // Ba lo co trong luong toi da 99 va co toi da 50 do vat

// Doc du lieu tu file
DoVat *ReadFromFile(int *W, int *n){
    FILE *f;
    f = fopen("CaiBalo1,3.txt", "r");
    fscanf(f, "%d", W); // Xac dinh trong luong Ba lo
    DoVat *dsdv;
    dsdv = (DoVat*)malloc(sizeof(DoVat));
    int i = 0;
    while (!feof(f)) {
        fscanf(f, "%d%d%[^\n]", &dsdv[i].TL, &dsdv[i].GT, dsdv[i].TenDV);
        dsdv[i].PA = 0; // Khoi tao phuong an cho tung do vat
        i++;
        dsdv = (DoVat*)realloc(dsdv, sizeof(DoVat) * (i + 1));  
    }
    *n = i;
    fclose(f);
    return dsdv;
}

// In danh sach do vat
void InDSDV(DoVat *dsdv, int n, int W) {
    int i, TongTL = 0, TongGT = 0;
    printf("\nPhuong an Cai Ba lo 1 dung thuat toan QUY HOACH DONG nhu sau:\n");
    printf("|---|------------------|----------|---------|-----------|\n");
    printf("|STT|     Ten Do Vat   | T Luong  | Gia Tri | Phuong an |\n");
    printf("|---|------------------|----------|---------|-----------|\n");
    for(i = 0; i < n; i++) {
        printf("|%2d |%-18s|%5d     |%5d    |%6d     |\n",
            i + 1, dsdv[i].TenDV, dsdv[i].TL, dsdv[i].GT, dsdv[i].PA);
        TongTL = TongTL + dsdv[i].PA * dsdv[i].TL;
        TongGT = TongGT + dsdv[i].PA * dsdv[i].GT;
    }  
    printf("|---|------------------|----------|---------|-----------|\n");  
    printf("Trong luong cua ba lo = %-9d\n", W);
    printf("Tong trong luong = %-9d\n", TongTL);
    printf("Tong gia tri = %-9d\n", TongGT);
}

// Tao bang DP cho bai toan
void TaoBang(DoVat *dsdv, int n, int W, bang F, bang X) {
    int k, V;
    int FMax, XMax;

    // Dien dong dau tien cua bang DP
    for(V = 0; V <= W; V++) {
        if(V >= dsdv[0].TL) {
            F[0][V] = dsdv[0].GT;
            X[0][V] = 1;
        } else {
            F[0][V] = 0;
            X[0][V] = 0;
        }
    }

    // Cac dong tiep theo cua bang DP
    for(k = 1; k < n; k++)
        for(V = 0; V <= W; V++) {
            FMax = F[k - 1][V];
            XMax = 0;
            // Neu co the chon do vat k
            if(V >= dsdv[k].TL) {
                if(F[k - 1][V - dsdv[k].TL] + dsdv[k].GT > FMax) {
                    FMax = F[k - 1][V - dsdv[k].TL] + dsdv[k].GT;
                    XMax = 1;
                }
            }
            F[k][V] = FMax;
            X[k][V] = XMax;
        }
}

// In bang DP (chi danh cho debug)
void InBang(int n, int W, bang F, bang X) {
    int V, k;
    for(k = 0; k < n; k++) {
        for(V = 0; V <= W; V++)
            printf("|%4d%2d", F[k][V], X[k][V]);
        printf("\n");
    }
}

// Truy vet lai phuong an
void TraBang(DoVat *dsdv, int n, int W, bang X) {
    int k, V;
    V = W;
    for(k = n - 1; k >= 0; k--) {
        dsdv[k].PA = X[k][V];
        V = V - X[k][V] * dsdv[k].TL;
    }
}

// Ham main
int main() {
    int n, W;
    bang X, F;
    DoVat *dsdv;
    dsdv = ReadFromFile(&W, &n);
    
    TaoBang(dsdv, n, W, F, X);
    InBang(n, W, F, X);  // Neu can in bang DP, co the bo comment
    TraBang(dsdv, n, W, X);
    InDSDV(dsdv, n, W);
    
    free(dsdv);
    return 0;
}

// Bai toan tra tien cua may ATM 1318
// Du lieu cho trong file D:/ATM.INP
// Giai bang phuong phap THAM AN

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct {
	char TenTien[25];
	int MG,PA;
}Tien;


Tien * ReadFromFile(int *n){
	FILE *f = fopen("ATM.txt","r");
	Tien *dslt = (Tien*)malloc(sizeof(Tien));
	int i=0;
	while (!feof(f)){
		fscanf(f, "%d%[^\n]",&dslt[i].MG,&dslt[i].TenTien);
		dslt[i].PA=0;
		i++;
		dslt=(Tien*)realloc(dslt, sizeof(Tien)*(i+1));
	}
	*n=i;
	fclose(f);
	return dslt;
}
 

void Swap(Tien *x, Tien *y){
	Tien Temp;
	Temp = *x;
	*x = *y;
	*y = Temp;
	}
	// Sap xep theo thu tu giam dan cua Menh gia tien

void BubbleSort(Tien *dslt, int n){
int i,j;
for(i=0; i<n-2; i++)
for (j=n-1; j>=i+1; j--){
if (dslt[j].MG>dslt[j-1].MG)
Swap(&dslt[j],&dslt[j-1]);
}
}

void InDS(Tien *dslt , int n, int TienCanRut){
int i;
int TongTienTra=0;
printf("|---|-------------------------|---------|---------|----------|\n");
    printf("|%-3s|%-25s|%-9s|%-9s|%-10s|\n", "STT", "   Loai tien ","Menh Gia", "So to","Thanh tien");
    printf("|---|-------------------------|---------|---------|----------|\n");
    for(i=0;i<n;i++){
    	if (dslt[i].PA !=0){
       printf("|%-3d",i+1);
       printf("|%-25s",dslt[i].TenTien);
       printf("|%-9d",dslt[i].MG);
       printf("|%-9d",dslt[i].PA);
       printf("|%-10d|\n",dslt[i].MG*dslt[i].PA);
       TongTienTra=TongTienTra+dslt[i].PA * dslt[i].MG;
   }
   else {
   	continue;
   }
   }
    printf("|---|-------------------------|---------|---------|----------|\n");
    printf("So tien can rut= %9d\n",TienCanRut);
    printf("So tien da tra= %9d\n", TongTienTra);
}

void Greedy(Tien *dslt,int n, int TienCanRut){
  int i=0;
  while(i<n&&TienCanRut>0) {
    dslt[i].PA= TienCanRut/dslt[i].MG;
    TienCanRut = TienCanRut-dslt[i].PA *dslt[i].MG;
    i++;
 }
}

int main(){
    int n;
    int TienCanRut;
    printf("Nhap so tien can rut: ");
    scanf("%d",&TienCanRut);
    Tien *dslt;
    dslt=ReadFromFile(&n);
    BubbleSort(dslt,n);
    Greedy(dslt,n,TienCanRut);
    InDS(dslt,n,TienCanRut);
    free(dslt);
    return 0;
}

/* Thuat toan THAM AN: 1412
- Sap xep cac canh theo thu tu tang dan cua do dai
- Uu tien chon cac canh co do dai nho nhat dua vao Phuong an
- Mot canh duoc dua vao Phuong an neu no khong tao thanh dinh cap 3 va khong tao thanh chu trinh thieu

Du lieu cho trong file "TSP.txt"
6
0		5.00	7.07	16.55	15.52	18.00
5.00	0		5.00	11.70	11.05	14.32
7.07	5.00	0		14.00	14.32	18.38
16.55	11.70	14.00	0		3.00	7.62
15.52	11.05	14.32	3.00	0		5.00
18.00	14.32	18.38	7.62	5.00	0

*/

#include <stdio.h>
#define size 30

/*Khai bao*/
typedef struct {
	float do_dai;
	int dau, cuoi;
} canh;

void read_file(char file_name[], canh a[], int *n){
	int i,j,t;
	float temp;
	FILE *f;
	f=fopen(file_name, "r");
	if (f==NULL){
		printf("Loi mo file!!!\n");
		return;
	}
	
	fscanf(f,"%d",n); // Doc so dinh cua do thi n
	
	int k=0;
	for(i=0; i<*n; i++)
		for(j=i; j<*n; j++)
			if(i==j) for(t=0; t<=j; t++)	fscanf(f,"%f",&temp); // Doc bo qua cac so duoi duong cheo chinh
			else {
				fscanf(f,"%f",&a[k].do_dai); // Doc luu tru cac so tren duong cheo chinh
				a[k].dau=i;
				a[k].cuoi=j;
				k++;
			}
	fclose(f);
}

void in_ds_canh(canh a[], int m, int la_PA){
	int i;
	float tong=0.0;
	for(i=0; i<m; i++){
		printf("%3d %c%c=%8.2f\n", i+1, a[i].dau+97, a[i].cuoi+97, a[i].do_dai);
		if (la_PA)
			tong+= a[i].do_dai;
	}
		if (la_PA)
			printf("Tong do dai cac canh = %5.2f\n", tong);
}

/*Doi cho*/
void swap(canh *x, canh *y){
	canh temp= *x;
	*x = *y;
	*y = temp;
}

void bubble_sort(canh a[], int n){
	int i,j;
	for(i=0; i<n-1; i++)
		for(j=n-1; j>i; j--)
			if(a[j].do_dai<a[j-1].do_dai)	
				swap(&a[j], &a[j-1]);
}
	
int dinh_cap3(canh PA[], int k, canh moi){
	int i,dem;
	i=0;
	dem=1;
	while (i<k && dem <3){
		if (moi.dau==PA[i].dau || moi.dau==PA[i].cuoi)
		dem++;
	i++;
	}
	if (dem==3)	return 1;
	
	i=0;
	dem=1;
	while (i<k && dem <3){
		if (moi.cuoi==PA[i].dau || moi.cuoi==PA[i].cuoi)
		dem++;
	i++;
	}
	return dem==3;
}

void init_forest(int parent[], int n){
	int i;
	for(i=0; i<n; i++) 
		parent[i]=i;
}

int find_root(int parent[], int u){
	while (u != parent[u])
		u = parent[u];
		return u;
}

int chu_trinh(int r_dau, int r_cuoi){
	return (r_dau == r_cuoi);
}

void update_forest(int parent[], int r1, int r2){
	parent[r2]= r1; //Hop nhat hai cay voi nhau
}
	
void greedy(canh ds_canh[], int n, canh PA[]){
	int i,j;
	int parent[n];
	init_forest(parent,n);
	int r_dau, r_cuoi;
// Chon cac canh nho nhat khong tao thanh dinh cap 3 va khong tao thanh chu trinh de dua vao PA
	j= 0;
	for(i=0; i<n*(n-1)/2 && j<n-1; i++){
		r_dau= find_root(parent, ds_canh[i].dau);
		r_cuoi= find_root(parent, ds_canh[i].cuoi);
		if (!dinh_cap3(PA,j, ds_canh[i]) && !chu_trinh(r_dau, r_cuoi)){
			PA[j]= ds_canh[i]; //ds_canh[i] khong tao dinh cap 3, khong tao thanh chu trinh thieu thi dua vao PA
			j++;
			update_forest(parent, r_dau, r_cuoi); //Hop nhat 2 cay: Dat cha cua goc cuoi bang goc dau
		}
	}
	
// Den day PA da co n-1 canh
// Tim mot canh trong so cac canh chua xet dua vao PA neu no khong tao thanh dinh cap 3 nhung phai tao thanh CHU TRINH
	for(; i<n*(n-1)/2; i++){
		r_dau= find_root(parent, ds_canh[i].dau);
		r_cuoi= find_root(parent, ds_canh[i].cuoi);
		if ((!dinh_cap3(PA, n-1, ds_canh[i])) && (chu_trinh(r_dau, r_cuoi))){
			PA[n-1]= ds_canh[i];
			break; //Ket thuc vi PA da co du n canh, tao thanh chu trinh
		}
	}
}

int main(){
	canh ds_canh[size];
	int n;
		
	printf("Phuong an TSP dung thuat toan THAM AN:\n");
	read_file("TSP.txt", ds_canh, &n);
	printf("Danh sach cac canh cua do thi:\n");
	in_ds_canh(ds_canh, n*(n-1)/2, 0);
	
	bubble_sort(ds_canh, n*(n-1)/2);
	printf("\nDanh sach cac canh cua do thi da SAP XEP:\n");
	in_ds_canh(ds_canh, n*(n-1)/2, 0);
	
	canh PA[n];
	greedy(ds_canh, n, PA);
		
	printf("\nPHUONG AN\n");
	in_ds_canh(PA, n, 1);
	
	return 0;
}

// Thuat toan NHANH CAN: 1581

#include <stdio.h>
#define size 30


typedef struct {
	float do_dai;
	int dau, cuoi;
	int da_dung;
} canh;

void read_file(char file_name[], canh a[][size], int *n){
	int i,j;
	FILE *f;
	f=fopen(file_name, "r");
	if (f==NULL){
		printf("Loi mo file!!!\n");
		return;
	}
	
	fscanf(f,"%d",n); // Doc so dinh cua do thi n
	
	for(i=0; i<*n; i++)
		for(j=0; j<*n; j++){
			fscanf(f,"%f",&a[i][j].do_dai); 
				a[i][j].dau=i;
				a[i][j].cuoi=j;
				a[i][j].da_dung=0;;
			}
	fclose(f);
}

void in_ma_tran(canh a[][size], int n){
	int i,j;
	printf("\nMa tran TRONG SO cua do thi\n");
	for(i=0; i<n; i++){
		for(j=0; j<n; j++)
			printf(" %c%c =%5.2f  ",a[i][j].dau+97, a[i][j].cuoi+97, a[i][j].do_dai);
		printf("\n");
	}
}

void in_PA(canh PA[], int n){
	int i;
	float sum=0.0;
	printf("\nPHUONG AN TIM DUOC:\n");
	for(i=0; i<n; i++){
		sum+= PA[i].do_dai;
		printf(" Canh %c%c = %5.2f\n", PA[i].dau+97, PA[i].cuoi+97, PA[i].do_dai);
    }  
    printf("CHU TRINH : ");
	for(i=0; i<n; i++){
		printf("%c",PA[i].dau+97);
		printf("-> ");
    }  
	printf("%c",PA[0].dau+97);    
	printf("\nTong do dai cac canh cua chu trinh = %5.2f\n", sum);
}

// Tim canh nho nhat trong so cac canh chua them vao chu trinh

float canh_NN(canh a[][size], int n){
	float Cmin=3.40282e+38;
	int i,j;
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			if(i!=j && !a[i][j].da_dung && a[i][j].do_dai<Cmin)	
				Cmin= a[i][j].do_dai;
	return Cmin;
}
	
float can_duoi(canh a[][size], float TGT, int n, int i){
	
	return TGT+ (n-i)*canh_NN(a,n);
}

// Ghi nhan phuong an tot nhat tam thoi

void Cap_Nhat_PA_TNTT(canh a[][size], int n, float TGT, float *GNNTT, canh x[], canh PA[]){
	 int i;
	 // mang x da co n-1 canh tu x[0] den x[n-2]
	 x[n-1]=a[x[n-2].cuoi][x[0].dau]; // Noi dinh cuoi cua x[n-2] voi dinh dau cua x[0] de co chu trinh
	 TGT= TGT + x[n-1].do_dai;		// Cong them vao TGT do dai cua canh noi dinh cuoi voi dinh dau
	 	 if(*GNNTT > TGT){
		 *GNNTT = TGT;
		 for(i=0; i<n; i++)
		 	PA[i]=x[i];
	 }
}
	
// Gia su ta co mot phuong an thanh phan x, voi k canh
// Neu ta di toi dinh ke_tiep ma dinh ke_tiep nay trung voi mot dinh dau cua mot canh nao do
// thi tao thanh chu trinh

int co_chu_trinh(canh x[], int k, int ke_tiep){
	int i=0, co_CT=0;
	while (i<k && !co_CT)
		if(ke_tiep==x[i].dau) co_CT=1;
		else i++;
	return co_CT;
}

void Nhanh_Can(canh a[][size], int n, int i, int dau, float *TGT, float *CD, float *GNNTT, canh x[], canh PA[]){
	 int j; 	// j la dinh ke tiep 
	 for(j=0; j<n; j++) 	
		
		if (dau!=j && !a[dau][j].da_dung && !co_chu_trinh(x,i,j)){
		// Ung voi mot gia tri cua j la mot nut tren cay 
	 	// Tinh 2 dai luong cua mot nut trong
	 		
		 *TGT = *TGT + a[dau][j].do_dai;
		 *CD = can_duoi(a, *TGT, n, i+1);
		  if(*CD < *GNNTT){ 	// Neu CD >= GNNTT thi cat tia 
		  // Neu khong co dieu kien nay thi chuong trinh la VET CAN
		  	x[i] = a[dau][j];
		  	a[dau][j].da_dung=1;
		  	a[j][dau].da_dung=1;
		  	
		   	if(i==n-2) { // Da xet het tat ca cac dinh nhung duong di moi co n-1 canh
			   	Cap_Nhat_PA_TNTT(a, n, *TGT, GNNTT, x, PA);
	    	}   	
		 	else
		 		Nhanh_Can(a, n, i+1, j, TGT, CD, GNNTT, x, PA); //Xet nut con cua nut i
	 	}
	 // Quay lui xet nut khac (ung voi gia tri khac cua j)
	 *TGT = *TGT - a[dau][j].do_dai;	// Tra lai Tong gia tri cua nut cha
	 a[dau][j].da_dung=0;	// Tra lai Canh vua xet la chua su dung	 
	 a[j][dau].da_dung=0;
    }	
}
	
void reset(canh a[][size], int n){
	int i,j;
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			a[i][j].da_dung=0;
}
	
int main(){
	canh a[size][size];
	int n;
	printf("\nPhuong an TSP dung thuat toan NHANH CAN:\n");
	read_file("TSP1.txt",a,&n);
	canh PA[n];
	canh x[n];
	char tpxp, yn;
	while (1){
		fflush(stdin);
		in_ma_tran(a,n);
		float TGT=0.0, CD = 0.0, GNNTT = 3.40282e+38;
		printf("\nXuat phat tu thanh pho nao? ");
		printf("\n Nhap mot trong cac thanh pho tu a den %c: ", n-1+97);
		scanf("%c", &tpxp);
		Nhanh_Can(a, n, 0, tpxp-97, &TGT, &CD, &GNNTT, x, PA);
		in_PA(PA,n);
		fflush(stdin);
		printf("\nTiep tuc Y/N? ");
		scanf("%c", &yn);
		if (yn == 'N' || yn == 'n')
			break;
		reset(a,n);
    }	    	
	return 0;
}

// Bai toan Tam giac so 1747
// Du lieu cho trong file tam_giac_so.txt
// Giai bai toan bang thuat toan QUY HOACH DONG

#include <stdio.h>
#define size 50

void ReadData(int a[][size], int *n){
	FILE *f;
	f=fopen("tam_giac_so1.txt", "r");
	if(f==NULL){
		printf("Loi mo file!!!\n");
		return;
	}
	int i=0, j;	
	while (!feof(f)){
		for(j=0; j<=i; j++)
			fscanf(f, "%d", &a[i][j]); 
		i++;
		}
	*n=i;
	fclose(f);
}

void PrintData(int a[][size], int n){
	int i,j;
	printf("\nTAM GIAC SO da cho\n");
	for(i=0; i<n; i++){
		for(j=0; j<=i; j++)
			printf("%5d", a[i][j]);
		printf("\n");
	}
}

int CS_max(int F[][size], int i, int j){
	if (j==0)
		return (F[i-1][0]>F[i-1][1])? 0:1;
	if (j==i)
		return i-1;
	if (j==i-1)
		return (F[i-1][i-2]>F[i-1][i-1])? i-2:i-1;
	
	if (F[i-1][j-1]>F[i-1][j]&&F[i-1][j-1]>F[i-1][j+1])
		return j-1;
	if (F[i-1][j]>F[i-1][j-1]&&F[i-1][j]>F[i-1][j+1])
		return j;
	if (F[i-1][j+1]>F[i-1][j]&&F[i-1][j+1]>F[i-1][j-1])
		return j+1;
}

// Dung cong thuc truy hoi de tao bang F
void Tao_Bang(int a[][size], int n, int F[][size]){
 	int i, j;
	 // 2 dong dau tien cua bang F xac dinh cu the
 		F[0][0]= a[0][0];
 		F[1][0]= F[0][0] + a[1][0];
 		F[1][1]= F[0][0] + a[1][1];
 	// Tu dong thu 3 (i=2) tro ve sau
	// Moi phan tu cua bang F duoc xac dinh nho vao dong truoc do (truy hoi)
	 for(i=2; i<n; i++)
		 for(j=0; j<=i; j++){
			 int k=CS_max(F,i,j);
			 F[i][j] = F[i-1][k] + a[i][j];
	 }
}

void In_Bang(int n, int F[][size]){
	int i, j;
	printf("\nBang F\n");
	for(i=0; i<n; i++){
		for(j=0; j<=i; j++)
		 	printf("%5d", F[i][j]);
		printf("\n");
	}
}

int CS_max_dong_cuoi(int F[], int j){
	int somax=F[0];
	int maxindex=0;
	int k;
	
	for(k=1; k<=j; k++)
		if (F[k]>somax){
			somax=F[k];
			maxindex=k;
		}
	return maxindex;
}

// Tra bang F, nhung xac dinh phuong an tu trong tam giac so (bang a)

void Tra_Bang(int a[][size], int n, int F[][size], int PA[]){
	int i,j;
	// Xac dinh chi so j cua phan tu lon nhat o dong cuoi trong bang F
	j=CS_max_dong_cuoi(F[n-1],n-1);
	
	// Phan tu cuoi cung cua duong di tuc la PA[n-1]
	// la phan tu cua dong cuoi cung bang a, ung voi cot j vua tim thay o tren
	PA[n-1]=a[n-1][j];
	
	// Xet cac dong cua bang F, tu dong n-1 den dong 1
	// De xac dinh cac phan tu cua PA tu PA[n-2] den PA[0]
	
	for(i=n-1; i>=1; i--){
		
		// Can cu vao chi so cot j cua dong cuoi (dong i) cua bang F
		// ma xac dinh chi so cot j cua dong tren (dong i-1) cua bang F
		
		j=CS_max(F,i,j);
		
		// PA[i-1] la phan tu cua dong i-1 cua tam giac so a,
		// ung voi cot j vua tim thay o tren
		
		PA[i-1]=a[i-1][j];
	}
}

int GiaPA(int PA[], int n){
	int i;
	int sum=0;
	for(i=0; i<n; i++)	sum+=PA[i];
	return sum;
}

void PrintPA(int PA[], int n){
	int i;
	printf("\nPhuong an la duong di qua cac so : ");
	printf("\%d", PA[0]);
	for(i=1; i<n; i++)	printf(" => %d", PA[i]);
	printf("\n\nTong cac so tren duong di la %d\n", GiaPA(PA,n));
}	

int main(){
	int a[size][size]; //Luu tam giac so
	int n;
	
	printf("\nBai toan TAM GIAC SO dung thuat toan QUY HOACH DONG\n");
	ReadData(a,&n);
	PrintData(a,n);
	
	int PA[n]; 	//Phuong an toi uu: mang co n phan tu
	int F[n][size]; 	//Bang F: mang 2 chieu co n dong, n cot
	
	Tao_Bang(a,n,F);
	In_Bang(n,F);
	
	Tra_Bang(a,n,F,PA);
	PrintPA(PA,n);
	
	return 0;
}


