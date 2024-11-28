Danh sach dac
Cac phep toan tren danh sach dac cac so nguyen
Khai bao
#define MaxLength 100
typedef struct {
    int Elements[MaxLength]; 
    int Last;              
} List;
Ten ham: makenullList()
void makenullList(List* pL) {
   	 	pL->Last = 0; 
}
Ten ham (function name): member()
int member(int x, List L) {
  	for (int i = 0; i < L.Last; i++) {
          		if (L.Elements[i] == x) {
          			return 1;
         		}
   	} return 0;
}
Ten ham (function name): sort()
void sort(List *pL) {
    int i, j;
    for (i = 0; i < pL->Last - 1; i++) {
        for (j = i + 1; j < pL->Last; j++) {
            if (pL->Elements[i] > pL->Elements[j]) {
                int temp = pL->Elements[i];
                pL->Elements[i] = pL->Elements[j];
                pL->Elements[j] = temp;
            }
        }
    }
}
Ten ham (function name): unionSet()
void unionSet(List L1, List L2, List *pL) {
    makenullList(pL); 
    for (int i = 0; i < L1.Last; i++) {
        insertSet(L1.Elements[i], pL);
    }
    for (int j = 0; j < L2.Last; j++) {
        if (!member(L2.Elements[j], *pL)) {
            insertSet(L2.Elements[j], pL);
        }
    }
}
Ten ham (function name): deleteList()
void deleteList(Position p, List *pL) {
    if (p < 1 || p > pL->Last) {
        printf("Vi tri khong hop le\n");
        return;
    }
    if (pL->Last == 0) {
        printf("Danh sach rong!\n");
        return;
    }
    for (int Q = p - 1; Q < pL->Last - 1; Q++) {
        pL->Elements[Q] = pL->Elements[Q + 1];
    }
    pL->Last--;
}
Ten ham (function name): removeAll()
void removeAll(int x, List *pL) {
    int pos;
    while ((pos = locate(x, *pL)) != pL->Last + 1) { // Neu tim thay x
        deleteList(pos, pL); // Xoa phan tu tai vi tri tim thay
    }
}
Ten ham (function name): intersection()
void intersection(List L1, List L2, List *pL) {
    makenullList(pL);
    for (int i = 0; i < L1.Last; i++) {
        ElementType x = L1.Elements[i];
        if (member(x, L2)) {
            insertSet(x, pL);
        }
    }
}
Ten ham (function name): copyEvenNumbers()
void copyEvenNumbers(List L1, List *pL2) {
makenullList(pL2); 
   	for (int i = 0; i < L1.Last; i++) {
          if (L1.Elements[i] % 2 == 0) {
          		insertList(L1.Elements[i], pL2->Last + 1, pL2); 
        }
    }
}
Ten ham (function name): insertSet()
void insertSet(int x, List *pL) {
    if (!member(x, *pL)) {
        pL->Elements[pL->Last] = x;
        pL->Last++;
    }
}
Ten ham (function name): insertList()
void insertList(int x, int p, List *pL) {
    if (p < 1 || p > pL->Last + 1) {
        printf("Vi tri khong hop le\n");
        return;
    }
    for (int i = pL->Last; i >= p; i--) {
        pL->Elements[i] = pL->Elements[i - 1];
    }
    pL->Elements[p - 1] = x;
    pL->Last++;
}
Ten ham (function name): locate()
int locate(int x, List L) {
    for (int i = 0; i < L.Last; i++) {
        if (L.Elements[i] == x) { 
            return i + 1; 
        }
    }
    return L.Last + 1;
}
Ten ham (function name): normalize()
void normalize(List *pL) {
    for (int i = 0; i < pL->Last; i++) {
        for (int j = i + 1; j < pL->Last; ) {
            if (pL->Elements[i] == pL->Elements[j]) {
                for (int k = j; k < pL->Last - 1; k++) {
                    pL->Elements[k] = pL->Elements[k + 1]; 
                }
                pL->Last--; 
            } else {
                j++; 
            }
        }
    }
}
Ten ham (function name): printOddNumbers()
void printOddNumbers(List L) {
    for (int i = 0; i < L.Last; i++) {
        if (L.Elements[i] % 2 != 0) { 
            printf("%d ", L.Elements[i]); 
        }
    }
    printf("\n"); 
}
Ten ham (function name): printList()
void printList(List L) {
    for (int i = 0; i < L.Last; i++) {
        printf("%d ", L.Elements[i]); 
    }
    printf("\n"); 
}
Ten ham (function name): getAvg()
float getAvg(List L) {
    if (L.Last == 0) {
        return -10000.0000; 
    }
    float sum = 0; 
    for (int i = 0; i < L.Last; i++) {
        sum += L.Elements[i]; 
    }
    return sum / L.Last; 
}
Ten ham (function name): readList()
void readList(List *pL) {
    int n, x;
    makenullList(pL); 
    scanf("%d", &n); 
    for (int i = 0; i < n; i++) {
        scanf("%d", &x); 
        insertList(x, pL->Last + 1, pL); 
    }
}
Ten ham (function name): readSet()
void readSet(List *pL) {
    int n, x;
    makenullList(pL); 
    scanf("%d", &n); 
    for (int i = 0; i < n; i++) {
        scanf("%d", &x); 
        if (!member(x, *pL)) {
            insertSet(x, pL); 
        }
    }
}
Ten ham (function name): difference()
void difference(List L1, List L2, List *pL) {
    makenullList(pL);  
    for (int i = 0; i < L1.Last; i++) {  
        if (!member(L1.Elements[i], L2)) {  trong L2
            insertSet(L1.Elements[i], pL);  
        }
    }
}
Ten ham (function name): erase()
void erase(int x, List *pL) {
    int p = locate(x, *pL);  
    if (p != -1) {  // Kiem tra neu p la mot vi tri hop le
        deleteList(p, pL);  
    }
}
Ap dung danh sach dac cac so nguyen
Bang cach su dung nhung phep toan chuan tren danh sach, hay viet chuong trinh cho phep liet ke cac so le, so chan trong danh sach

#include <stdio.h>
#include <stdlib.h>
#define MaxLength 100
typedef struct {
    int Elements[MaxLength];
    int Last;
} List;
// Cac ham da duoc dinh nghia truoc do
void makenullList(List *pL) {
    pL->Last = 0;
}
int member(int x, List L) {
    for (int i = 0; i < L.Last; i++) {
        if (L.Elements[i] == x) {
            return 1;
        }
    }
    return 0;
}
void insertSet(int x, List *pL) {
    if (pL->Last < MaxLength) {
        pL->Elements[pL->Last] = x;
        pL->Last++;
    }
}
void printOddNumbers(List L) {
    for (int i = 0; i < L.Last; i++) {
        if (L.Elements[i] % 2 != 0) {
            printf("%d ", L.Elements[i]);
        }
    }
    printf("\n");
}
void printEvenNumbers(List L) {
    for (int i = 0; i < L.Last; i++) {
        if (L.Elements[i] % 2 == 0) {
            printf("%d ", L.Elements[i]);
        }
    }
    printf("\n");
}
void printList(List L) {
    for (int i = 0; i < L.Last; i++) {
        printf("%d ", L.Elements[i]);
    }
    printf("\n");
}
void readList(List *pL) {
    int n, x;
    makenullList(pL);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        insertSet(x, pL);
    }
}
int main() {
    List L;
    readList(&L);
    printList(L);
    printOddNumbers(L);
    printEvenNumbers(L);
    return 0;
}

Bang cach su dung nhung phep toan chuan tren danh sach, hay viet chuong trinh cho phep tinh trung binh cong cac phan tu trong danh sach

#include <stdio.h>
#include <stdlib.h>

#define MaxLength 100

typedef struct {
    int Elements[MaxLength];
    int Last;
} List;
void makenullList(List *pL) {
    pL->Last = 0;
}
void insertSet(int x, List *pL) {
    if (pL->Last < MaxLength) {
        pL->Elements[pL->Last] = x;
        pL->Last++;
    }
}
void readList(List *pL) {
    int n, x;
    makenullList(pL);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        insertSet(x, pL);
    }
}
void printList(List L) {
    for (int i = 0; i < L.Last; i++) {
        printf("%d ", L.Elements[i]);
    }
    printf("\n");
}
double average(List L) {
    if (L.Last == 0) return 0;
    int sum = 0;
    for (int i = 0; i < L.Last; i++) {
        sum += L.Elements[i];
    }
    return (double)sum / L.Last;
}
int main() {
    List L;
    readList(&L);
    printList(L);
    double avg = average(L);
    printf("%.3f\n", avg);
    return 0;
}


Bang cach su dung nhung phep toan chuan tren danh sach, hay viet chuong trinh cho phep tim tap hop hop cua 2 danh sach bieu dien tap hop

#include <stdio.h>
#include <stdlib.h>
#define MaxLength 100
typedef struct {
    int Elements[MaxLength];
    int Last;
} List;
// Ham khoi tao danh sach
void makenullList(List *pL) {
    pL->Last = 0;
}
// Ham them phan tu vao danh sach neu chua co
void insertUnique(int x, List *pL) {
    for (int i = 0; i < pL->Last; i++) {
        if (pL->Elements[i] == x) {
            return; // Neu phan tu da co, khong them
        }
    }
    if (pL->Last < MaxLength) {
        pL->Elements[pL->Last] = x;
        pL->Last++;
    }
}
// Ham doc danh sach tu ban phim
void readList(List *pL) {
    int n, x;
    makenullList(pL);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        insertUnique(x, pL);
    }
}
// Ham hien thi danh sach
void printList(List L) {
    for (int i = 0; i < L.Last; i++) {
        printf("%d ", L.Elements[i]);
    }
    printf("\n");
}
// Ham tim tap hop hop cua 2 tap hop
void unionSets(List A, List B, List *C) {
    makenullList(C);
    // Them phan tu tu A
    for (int i = 0; i < A.Last; i++) {
        insertUnique(A.Elements[i], C);
    }
    // Them phan tu tu B
    for (int i = 0; i < B.Last; i++) {
        insertUnique(B.Elements[i], C);
    }
}
int main() {
    List A, B, C;
    // Nhap tap hop A
    readList(&A);
    printList(A);
    // Nhap tap hop B
    readList(&B);
    printList(B);
    // Tim tap hop hop
    unionSets(A, B, &C);
    // printf("Tap hop hop cua A va B: ");
    printList(C);
    return 0;
}

Bang cach su dung nhung phep toan chuan tren danh sach, hay viet chuong trinh cho phep tim hieu cua 2 danh sach bieu dien tap hop

#include <stdio.h>

#define Maxlength 300
typedef struct {
    int Elements[Maxlength];
    int Last;
} List;

// Khai bao truoc ham member
int member(int x, List L);

void makenullList(List *pL) {
    pL->Last = 0;
}

void insertSet(int x, List *pL) {
    // Kiem tra xem phan tu da ton tai trong danh sach chua
    if (!member(x, *pL)) {
        pL->Elements[pL->Last] = x;
        pL->Last++;
    }
}

void readSet(List *pL) {
    makenullList(pL);
    int n, x, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        insertSet(x, pL);
    }
}

void printList(List L) {
    int i;
    for (i = 0; i < L.Last; i++)
        printf("%d ", L.Elements[i]);
    printf("\n");
}

int member(int x, List L) {
    int i;
    for (i = 0; i < L.Last; i++) {
        if (L.Elements[i] == x) return 1; // Neu tim thay, tra ve 1
    }
    return 0; // Neu khong tim thay, tra ve 0
}

void difference(List L1, List L2, List *pL) {
    makenullList(pL);
    int i;
    for (i = 0; i < L1.Last; i++) {
        if (!member(L1.Elements[i], L2)) {
            insertSet(L1.Elements[i], pL); // Them vao pL neu khong co trong L2
        }
    }
}

int main() {
    List L1, L2, L;
    readSet(&L1);
    readSet(&L2);
    printList(L1);
    printList(L2);
    difference(L1, L2, &L);
    printList(L);
    return 0;
}



Bang cach su dung nhung phep toan chuan tren danh sach da cho trong thu vien AListLib.c, hay viet chuong trinh cho phep sap xep danh sach tang dan

#include <stdio.h>
#include "AListLib.c"

#define MaxLength 100
// Su dung kieu du lieu khac de tranh xung dot voi AListLib
typedef struct {
    int Elements[MaxLength];
    int Last;
} MyList;
void makenullMyList(MyList *pL) {
    pL->Last = 0;
}
void insertToMyList(int x, MyList *pL) {
    if (pL->Last < MaxLength) {
        pL->Elements[pL->Last] = x;
        pL->Last++;
    }
}
void readMyList(MyList *pL) {
    int n, x;
    makenullMyList(pL);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        insertToMyList(x, pL);
    }
}
void printMyList(MyList L) {
    for (int i = 0; i < L.Last; i++) {
        printf("%d ", L.Elements[i]);
    }
    printf("\n");
}
void sortMyList(MyList *pL) {
    for (int i = 0; i < pL->Last - 1; i++) {
        for (int j = 0; j < pL->Last - i - 1; j++) {
            if (pL->Elements[j] > pL->Elements[j + 1]) {
                // Hoan doi
                int temp = pL->Elements[j];
                pL->Elements[j] = pL->Elements[j + 1];
                pL->Elements[j + 1] = temp;
            }
        }
    }
}
int main() {
    MyList L;
    readMyList(&L);
    printMyList(L);
    sortMyList(&L);
    printMyList(L);
    return 0;
}


Bang cach su dung nhung phep toan chuan tren danh sach, hay viet chuong trinh cho phep tim tap hop giao cua 2 danh sach bieu dien tap hop

#include <stdio.h>
#include "AListLib.c" // Dam bao thu vien nay chua dinh nghia cho cac ham can thiet
int member(int x, List L) {
    for (int i = 0; i < L.Last; i++) {
        if (L.Elements[i] == x) {
            return 1; // Co thuoc
        }
    }
    return 0; // Khong thuoc
}
void insertSet(int x, List *pL) {
    if (!member(x, *pL)) {
        pL->Elements[pL->Last] = x; // Them phan tu vao cuoi danh sach
        pL->Last++; // Tang kich thuoc danh sach
    }
}
void readSet(List *pL) {
    int n, x;
    makenullList(pL); // Khoi tao danh sach rong
    scanf("%d", &n);  // Nhap so phan tu cua tap hop
    for (int i = 0; i < n; i++) {
        scanf("%d", &x); // Nhap phan tu x
        insertSet(x, pL); // Chen x vao tap hop
    }
}

void printList(List L) {
    for (int i = 0; i < L.Last; i++) {
        printf("%d ", L.Elements[i]); // Hien thi phan tu tai chi so i
    }
    printf("\n"); // Xuong dong sau khi in xong
}
void intersection(List L1, List L2, List *pL) {
    makenullList(pL); // Khoi tao danh sach ket qua la rong
    for (int i = 0; i < L1.Last; i++) {
        if (member(L1.Elements[i], L2)) {
            insertSet(L1.Elements[i], pL); // Chen phan tu vao danh sach ket qua
        }
    }
}
int main() {
    List L1, L2, result;
    readSet(&L1);
    printList(L1);
    readSet(&L2);
    printList(L2);
    intersection(L1, L2, &result);
    printList(result);
    return 0;
}



Hay hoan chinh chuong trinh tren bang cach dien cac lenh can thiet vao dau ...  de tao thanh 1 chuong trinh cho phep nhap va hien thi 1 danh sach tu ban phim.
readList(&L);
printList(L);
Bang cach su dung nhung phep toan chuan tren danh sach da cho trong thu vien AListLib.c, hay viet chuong trinh nhap mot danh sach tu ban phim va cho phep xoa phan tu x xuat hien dau tien trong danh sach

#include <stdio.h>

#define MaxLength 100
typedef struct {
    int Elements[MaxLength]; // Mang chua cac phan tu
    int Last;                // So luong phan tu hien tai trong danh sach
} List;
// Ham khoi tao danh sach rong
void makenullList(List *pL) {
    pL->Last = 0;
}
// Ham kiem tra phan tu x co trong danh sach hay khong
int member(int x, List L) {
    for (int i = 0; i < L.Last; i++) {
        if (L.Elements[i] == x) {
            return 1;
        }
    }
    return 0;
}
// Ham them phan tu x vao cuoi danh sach
void insertSet(int x, List *pL) {
    if (pL->Last < MaxLength) {
        pL->Elements[pL->Last] = x;
        pL->Last++;
    }
}

// Ham tim vi tri xuat hien dau tien cua phan tu x trong danh sach
int locate(int x, List L) {
    for (int i = 0; i < L.Last; i++) {
        if (L.Elements[i] == x) {
            return i + 1; // Tra ve vi tri (them 1 de chuyen sang chi so bat dau tu 1)
        }
    }
    return L.Last + 1; // Neu khong tim thay, tra ve L.Last + 1
}
// Ham xoa phan tu o vi tri p trong danh sach
void deleteList(int p, List *pL) {
    if (p < 1 || p > pL->Last) {
        return;
    }
    for (int Q = p - 1; Q < pL->Last - 1; Q++) {
        pL->Elements[Q] = pL->Elements[Q + 1];
    }
    pL->Last--;
}
// Ham xoa phan tu x xuat hien dau tien trong danh sach
void erase(int x, List *pL) {
    int p = locate(x, *pL);  // Tim vi tri xuat hien dau tien cua x trong danh sach
    if (p <= pL->Last) {  // Kiem tra neu p la mot vi tri hop le
        deleteList(p, pL);  // Xoa phan tu o vi tri p
    }
}
// Ham nhap danh sach tu ban phim
void readList(List *pL) {
    int n, x;
    makenullList(pL); // Khoi tao danh sach rong
    scanf("%d", &n); // Nhap so phan tu cua danh sach
    for (int i = 0; i < n; i++) {
        scanf("%d", &x); // Nhap phan tu x
        insertSet(x, pL); // Chen x vao danh sach
    }
}
// Ham hien thi danh sach
void printList(List L) {
    for (int i = 0; i < L.Last; i++) {
        printf("%d ", L.Elements[i]); // Hien thi phan tu tai chi so i
    }
    printf("\n"); // Xuong dong sau khi in xong
}
// Ham main
int main() {
    List L;
    readList(&L); // Nhap danh sach
    printList(L); // Hien thi danh sach
    int x;
    scanf("%d", &x); // Nhap gia tri x can xoa
    erase(x, &L); // Xoa phan tu x xuat hien dau tien
    printList(L); // Hien thi danh sach sau khi xoa
    return 0;
}


Bang cach su dung nhung phep toan chuan tren danh sach, hay viet chuong trinh cho phep liet ke cac so chan va tinh trung binh cong cac phan tu la so chan trong danh sach

#include <stdio.h>
#define MaxLength 100
typedef struct {
    int Elements[MaxLength]; // Mang chua cac phan tu
    int Last;                // So luong phan tu hien tai trong danh sach
} List;
void makenullList(List *pL) {
    pL->Last = 0;
}
void insertSet(int x, List *pL) {
    pL->Elements[pL->Last] = x;
    pL->Last++;
}
void readList(List *pL) {
    int n, x;
    makenullList(pL); // Khoi tao danh sach rong
    scanf("%d", &n); // Nhap so phan tu cua danh sach
    for (int i = 0; i < n; i++) {
        scanf("%d", &x); // Nhap phan tu x
        insertSet(x, pL); // Chen x vao danh sach
    }
}
void copyEvenNumbers(List L1, List *pL2) {
    makenullList(pL2); // Khoi tao danh sach ket qua rong
    for (int i = 0; i < L1.Last; i++) {
        if (L1.Elements[i] % 2 == 0) {
            insertSet(L1.Elements[i], pL2);
        }
    }
}
void printList(List L) {
    for (int i = 0; i < L.Last; i++) {
        printf("%d ", L.Elements[i]);
    }
    printf("\n");
}
float getAvg(List L) {
    if (L.Last == 0) {
        return -10000.0000; // Tra ve -10000.0000 neu danh sach rong
    }
    float sum = 0;
    for (int i = 0; i < L.Last; i++) {
        sum += L.Elements[i];
    }
    return sum / L.Last; // Tinh trung binh cong
}
int main() {
    List L, EvenList;
    readList(&L);
    printList(L);
    copyEvenNumbers(L, &EvenList);
    printList(EvenList);
    float avg = getAvg(EvenList);
    printf("%.3f\n", avg);
    return 0;
}


Bang cach su dung nhung phep toan chuan tren danh sach, hay viet chuong trinh cho phep xoa tat ca cac phan tu x trong danh sach

#include <stdio.h>
#include "AListLib.c" 
void readList(List *pL) {
    int n, x;
    makenullList(pL); 
    scanf("%d", &n);   
    for (int i = 0; i < n; i++) {
        scanf("%d", &x); // Nhap phan tu x
        insertList(x, pL->Last + 1, pL); 
    }
}
void printList(List L) {
    for (int i = 0; i < L.Last; i++) {
        printf("%d ", L.Elements[i]); 
    }
    printf("\n"); 
}
void eraseAll(int x, List *pL) {
    int pos;
    while ((pos = locate(x, *pL)) != pL->Last + 1) { // Tim vi tri xuat hien dau tien cua x
        deleteList(pos, pL); // Xoa phan tu o vi tri tim duoc
    }
}
int main() {
    List L;
    int x;
    readList(&L);
    printList(L);
    scanf("%d", &x);
    eraseAll(x, &L);
    printList(L);
    return 0;
}

Cac phep toan cua danh sach sinh vien
Gia su khai bao kieu DanhSach da duoc dinh nghia.  Hay viet 1 ham hien thi danh sach sinh vien
Ten ham: hienthi()
void hienthi(DanhSach L) {
    for (int i = 0; i < L.n; i++) {
        float tongDiem = L.A[i].DiemLT + L.A[i].DiemTH1 + L.A[i].DiemTH2;
        printf("%s - %s - %.2f - %.2f - %.2f - %.2f\n", 
               L.A[i].MSSV, 
               L.A[i].HoTen, 
               L.A[i].DiemLT, 
               L.A[i].DiemTH1, 
               L.A[i].DiemTH2, 
               tongDiem);
    }
}
Gia su khai bao kieu DanhSach da duoc dinh nghia.  Hay viet 1 ham tim vi tri sinh vien co ma so x cho truoc
Ten ham: tim()
int tim(const char *x, DanhSach L) {
    for (int i = 0; i < L.n; i++) {
        // So sanh ma so sinh vien
        if (strcmp(L.A[i].MSSV, x) == 0) {
            return i + 1; // Tra ve vi tri (1-based)
        }
    }
    return L.n + 1; // Neu khong tim thay, tra ve n + 1
}
Gia su khai bao kieu DanhSach da duoc dinh nghia. Hay viet 1 ham tra ve 1 danh sach sinh vien rong.
Ten ham: dsRong()
DanhSach dsRong() {
    DanhSach L; 
    L.n = 0; 
    return L; 
}
Ten ham: xoaSinhVien()
void xoaSinhVien(const char *x, DanhSach *pL) {
    char temp[10];
    int p = tim(temp, *pL); // Goi ham tim voi bien tam
    if (p != -1) {
        xoaTai(p, pL); // Xoa sinh vien o vi tri p
    }
}
Khai bao danh sach
Hay viet khai bao kieu DaThuc la mot danh sach dac dung de luu tru 1 da thuc gom cac truong:
struct DaThuc {
    DonThuc A[100]; // Mang cac don thuc, toi da 100 don thuc
    int so_luong;   // So luong don thuc co trong da thuc
};
Hay viet khai bao cho kieu du lieu dong van ban Line (trong do So ky tu toi da = 80) voi cac thanh phan duoc mo ta nhu hinh tren de la mot danh sach dac cac ky tu
#define MAX_LENGTH 80
typedef struct {
    char characters[MAX_LENGTH]; 
    int length;                 
} Line;
Gia su nguoi ta bieu dien mot da giac bang mot danh sach dac co toi da la 100 diem.
Hay viet khai bao cho kieu du lieu Polygon bieu dien cac da giac theo mo ta tren.
#define MAX_POINTS 100
typedef struct {
    int x;
    int y;
} Point;
typedef struct {
    Point points[MAX_POINTS];
    int num_points;
} Polygon;
Hay viet khai bao kieu List la mot danh sach dac dung de luu tru 1 danh sach sinh vien theo mo ta tren
#define MAX_STUDENTS 40
typedef struct {
    char maSo[10];        
    char hoTen[50];    
    float diemLyThuyet;  
    float diemThucHanh1; 
    float diemThucHanh2; 
} SinhVien;
typedef struct {
    SinhVien A[MAX_STUDENTS]; 
    int n;                     
} List;
Hay viet khai bao cho kieu du lieu List (trong do Maxlength=100) voi cac thanh phan duoc mo ta nhu hinh tren de la mot danh sach dac cac so thuc float
#define MAX_LENGTH 100
typedef struct {
    float A[MAX_LENGTH]; 
    int n;               
} List;

Dong van ban
Ten ham: isEmpty()
Tham so: L kieu Line
int isEmpty(Line L) {
    return (L.n == 0) ? 1 : 0;
}
Ten ham: printLine()
void printLine(Line L) {
    for (int i = 0; i < L.n; i++) {
        putchar(L.Data[i]);
    }
    putchar('\n');
}
Ten ham: initLine()
void initLine(Line *pL) {
    pL->n = 0;
}
Ten ham: appendChar()
void appendChar(char x, Line *pL) {
    if (pL->n < MaxLength) {
        pL->Data[pL->n] = x;
        pL->n++;
    } else {
        printf("LINE IS FULL\n");
    }
}
Viet ham tim vi tri xuat hien dau tien cua ky tu x trong dong van ban
Ten ham: locate()
int locate(char x, Line L) {
    for (int i = 0; i < L.n; i++) {
        if (L.Data[i] == x) {
            return i + 1; // Tra ve vi tri (1-based index)
        }
    }
    return L.n + 1; // Neu khong tim thay, tra ve L.n + 1
}
Ten ham: removeAt()
int removeAt(int p, Line *pL) {
    if (p < 1 || p > pL->n) {
        return 0; // Vi tri khong hop le
    }
    for (int i = p - 1; i < pL->n - 1; i++) {
        pL->Data[i] = pL->Data[i + 1];
    }
    pL->n--;
    return 1; // Xoa thanh cong
}
Ten ham: erasechar()
int erase(char ch, Line *pL) {
    int p = locate(ch, *pL);
    if (p > 0) {
        return removeAt(p, pL);
    }
    return 0; // Ky tu khong ton tai trong dong van ban
}
Ten ham: isFull()
int isFull(Line L) {
    if (L.n == MaxLength) {
        return 1; // Dong van ban day
    } else {
        return 0; // Dong van ban khong day
    }
}
Ten ham: countAlphabet()
int countAlphabet(Line L) {
    int count = 0;
    for (int i = 0; i < L.n; i++) {
        if ((L.Data[i] >= 'a' && L.Data[i] <= 'z') || (L.Data[i] >= 'A' && L.Data[i] <= 'Z')) {
            count++; // Tang bien dem neu ky tu la chu cai
        }
    }
    return count; // Tra ve so luong ky tu viet
}

Ten ham: countDigits()
int countDigits(Line L) {
    int count = 0;
    for (int i = 0; i < L.n; i++) {
        if (L.Data[i] >= '0' && L.Data[i] <= '9') {
            count++;
        }
    }
    return count;
}
Ten ham: appendLine()
void appendLine(Line *pDestination, Line Source) {
    for (int i = 0; i < Source.n; i++) {
        if (pDestination->n < MaxLength) {
            appendChar(Source.Data[i], pDestination);
        } else {
            printf("LINE IS FULL\n");
            break;
        }
    }
}
Goi thuc thi va cac phep toan cua sinh vien
Bang cach su dung nhung phep toan da dinh nghia tren danh sach sinh vien. Hay viet chuong trinh nhap va hien thi danh sach sinh vien.



#include <stdio.h>
#include <string.h>

#define MAX_SINH_VIEN 40

// Cau truc SinhVien
struct SinhVien {
    char MSSV[10];
    char HoTen[50];
    float DiemLT, DiemTH1, DiemTH2;
};

// Cau truc DanhSach
struct DanhSach {
    struct SinhVien A[MAX_SINH_VIEN];
    int n;
};

// Ham khoi tao danh sach rong
struct DanhSach dsRong() {
    struct DanhSach L;
    L.n = 0; // Khoi tao so luong sinh vien
    return L;
}

// Ham tim sinh vien theo ma so
int tim(struct DanhSach L, char *mssv) {
    for (int i = 0; i < L.n; i++) {
        if (strcmp(L.A[i].MSSV, mssv) == 0) {
            return i; // tra ve vi tri tim thay
        }
    }
    return -1; // khong tim thay
}

// Ham them sinh vien vao cuoi danh sach
void chenCuoi(struct DanhSach *L, struct SinhVien s) {
    if (L->n < MAX_SINH_VIEN) {
        L->A[L->n] = s;
        L->n++;
    }
}

// Ham nhap danh sach sinh vien
struct DanhSach nhap() {
    struct DanhSach L = dsRong(); // Khoi tao danh sach rong
    int soSinhVien;
    scanf("%d", &soSinhVien);

    for (int i = 0; i < soSinhVien; i++) {
        struct SinhVien sv;
        scanf("%s", sv.MSSV);
        
        // Kiem tra ma so da ton tai
        if (tim(L, sv.MSSV) != -1) {
            i--; // Giam chi so de nhap lai sinh vien
            continue; // Chuyen sang vong lap tiep theo
        }
        getchar(); // Xoa ky tu newline con lai trong buffer
        fgets(sv.HoTen, sizeof(sv.HoTen), stdin);
        sv.HoTen[strcspn(sv.HoTen, "\n")] = 0; // Xoa ky tu newline o cuoi chuoi
        scanf("%f %f %f", &sv.DiemLT, &sv.DiemTH1, &sv.DiemTH2);

        chenCuoi(&L, sv); // Them sinh vien vao danh sach
    }

    return L; // Tra ve danh sach sinh vien
}

// Ham hien thi danh sach sinh vien
void hienThi(struct DanhSach L) {
    for (int i = 0; i < L.n; i++) {
        printf("%s - %s - %.2f - %.2f - %.2f\n", L.A[i].MSSV, L.A[i].HoTen, L.A[i].DiemLT, L.A[i].DiemTH1, L.A[i].DiemTH2);
    }
}

// Ham main
int main() {
    struct DanhSach L;
    L = nhap(); // Nhap danh sach sinh vien
    hienThi(L); // Hien thi danh sach sinh vien
    return 0;
}


Bang cach su dung nhung phep toan da dinh nghia tren danh sach sinh vien. Hay viet chuong trinh nhap va hien thi danh sach sinh vien. Sau do liet ke nhung sinh vien DAT.




#include <stdio.h>
#include <string.h>

#define MAX_SINH_VIEN 40

// Cau truc SinhVien
struct SinhVien {
    char MSSV[10];
    char HoTen[50];
    float DiemLT, DiemTH1, DiemTH2;
};

// Cau truc DanhSach
struct DanhSach {
    struct SinhVien A[MAX_SINH_VIEN];
    int n;
};

// Ham khoi tao danh sach rong
struct DanhSach dsRong() {
    struct DanhSach L;
    L.n = 0; // Khoi tao so luong sinh vien
    return L;
}

// Ham tim sinh vien theo ma so
int tim(struct DanhSach L, char *mssv) {
    for (int i = 0; i < L.n; i++) {
        if (strcmp(L.A[i].MSSV, mssv) == 0) {
            return i; // tra ve vi tri tim thay
        }
    }
    return -1; // khong tim thay
}

// Ham them sinh vien vao cuoi danh sach
void chenCuoi(struct DanhSach *L, struct SinhVien s) {
    if (L->n < MAX_SINH_VIEN) {
        L->A[L->n] = s;
        L->n++;
    }
}

// Ham nhap danh sach sinh vien
struct DanhSach nhap() {
    struct DanhSach L = dsRong(); // Khoi tao danh sach rong
    int soSinhVien;
    scanf("%d", &soSinhVien);

    for (int i = 0; i < soSinhVien; i++) {
        struct SinhVien sv;
        scanf("%s", sv.MSSV);
        
        // Kiem tra ma so da ton tai
        if (tim(L, sv.MSSV) != -1) {
            i--; // Giam chi so de nhap lai sinh vien
            continue; // Chuyen sang vong lap tiep theo
        }
        getchar(); // Xoa ky tu newline con lai trong buffer
        fgets(sv.HoTen, sizeof(sv.HoTen), stdin);
        sv.HoTen[strcspn(sv.HoTen, "\n")] = 0; // Xoa ky tu newline o cuoi chuoi
        scanf("%f %f %f", &sv.DiemLT, &sv.DiemTH1, &sv.DiemTH2);

        chenCuoi(&L, sv); // Them sinh vien vao danh sach
    }

    return L; // Tra ve danh sach sinh vien
}

// Ham hien thi danh sach sinh vien
void hienThi(struct DanhSach L) {
    for (int i = 0; i < L.n; i++) {
        printf("%s - %s - %.2f - %.2f - %.2f\n", L.A[i].MSSV, L.A[i].HoTen, L.A[i].DiemLT, L.A[i].DiemTH1, L.A[i].DiemTH2);
    }
}

// Ham liet ke sinh vien dat
void lietKeDat(struct DanhSach L) {
    printf("Sinh vien DAT\n");
    for (int i = 0; i < L.n; i++) {
        float tongDiem = L.A[i].DiemLT + L.A[i].DiemTH1 + L.A[i].DiemTH2;
        if (tongDiem >= 4.0) {
            printf("%s - %s - %.2f - %.2f - %.2f\n", L.A[i].MSSV, L.A[i].HoTen, L.A[i].DiemLT, L.A[i].DiemTH1, L.A[i].DiemTH2);
        }
    }
}

// Ham main
int main() {
    struct DanhSach L;
    L = nhap(); // Nhap danh sach sinh vien
    hienThi(L); // Hien thi danh sach sinh vien
    lietKeDat(L); // Liet ke sinh vien dat
    return 0;
}


Bang cach su dung nhung phep toan da dinh nghia tren danh sach sinh vien. Hay viet chuong trinh nhap va hien thi danh sach sinh vien. Sau do liet ke nhung sinh vien KHONG DAT.




#include <stdio.h>
#include <string.h>

#define MAX_SINH_VIEN 40

// Cau truc SinhVien
struct SinhVien {
    char MSSV[10];
    char HoTen[50];
    float DiemLT, DiemTH1, DiemTH2;
};

// Cau truc DanhSach
struct DanhSach {
    struct SinhVien A[MAX_SINH_VIEN];
    int n;
};

// Ham khoi tao danh sach rong
struct DanhSach dsRong() {
    struct DanhSach L;
    L.n = 0; // Khoi tao so luong sinh vien
    return L;
}

// Ham tim sinh vien theo ma so
int tim(struct DanhSach L, char *mssv) {
    for (int i = 0; i < L.n; i++) {
        if (strcmp(L.A[i].MSSV, mssv) == 0) {
            return i; // tra ve vi tri tim thay
        }
    }
    return -1; // khong tim thay
}

// Ham them sinh vien vao cuoi danh sach
void chenCuoi(struct DanhSach *L, struct SinhVien s) {
    if (L->n < MAX_SINH_VIEN) {
        L->A[L->n] = s;
        L->n++;
    }
}

// Ham nhap danh sach sinh vien
struct DanhSach nhap() {
    struct DanhSach L = dsRong(); // Khoi tao danh sach rong
    int soSinhVien;
    scanf("%d", &soSinhVien);

    for (int i = 0; i < soSinhVien; i++) {
        struct SinhVien sv;
        scanf("%s", sv.MSSV);
        
        // Kiem tra ma so da ton tai
        if (tim(L, sv.MSSV) != -1) {
            i--; // Giam chi so de nhap lai sinh vien
            continue; // Chuyen sang vong lap tiep theo
        }

        getchar(); // Xoa ky tu newline con lai trong buffer
        fgets(sv.HoTen, sizeof(sv.HoTen), stdin);
        sv.HoTen[strcspn(sv.HoTen, "\n")] = 0; // Xoa ky tu newline o cuoi chuoi
        scanf("%f %f %f", &sv.DiemLT, &sv.DiemTH1, &sv.DiemTH2);

        chenCuoi(&L, sv); // Them sinh vien vao danh sach
    }

    return L; // Tra ve danh sach sinh vien
}

// Ham hien thi danh sach sinh vien
void hienThi(struct DanhSach L) {
    for (int i = 0; i < L.n; i++) {
        printf("%s - %s - %.2f - %.2f - %.2f\n", L.A[i].MSSV, L.A[i].HoTen, L.A[i].DiemLT, L.A[i].DiemTH1, L.A[i].DiemTH2);
    }
}

// Ham liet ke sinh vien khong dat
void lietKeKhongDat(struct DanhSach L) {
    printf("Sinh vien KHONG DAT\n");
    for (int i = 0; i < L.n; i++) {
        float tongDiem = L.A[i].DiemLT + L.A[i].DiemTH1 + L.A[i].DiemTH2;
        if (tongDiem < 4.0) {
            printf("%s - %s - %.2f - %.2f - %.2f\n", L.A[i].MSSV, L.A[i].HoTen, L.A[i].DiemLT, L.A[i].DiemTH1, L.A[i].DiemTH2);
        }
    }
}

// Ham main
int main() {
    struct DanhSach L;
    L = nhap(); // Nhap danh sach sinh vien
    hienThi(L); // Hien thi danh sach sinh vien
    lietKeKhongDat(L); // Liet ke sinh vien khong dat
    return 0;
}


Bang cach su dung nhung phep toan da dinh nghia tren danh sach sinh vien. Hay viet chuong trinh nhap va hien thi danh sach sinh vien. Sau do nhap mot ma so sinh vien tu ban phim, neu ma so ton tai thi xoa sinh vien co ma so do.




#include <stdio.h>
#include <string.h>

#define MAX_SINH_VIEN 40

// Cau truc SinhVien
struct SinhVien {
    char MSSV[10];
    char HoTen[50];
    float DiemLT, DiemTH1, DiemTH2;
};

// Cau truc DanhSach
struct DanhSach {
    struct SinhVien A[MAX_SINH_VIEN];
    int n;
};

// Ham khoi tao danh sach rong
struct DanhSach dsRong() {
    struct DanhSach L;
    L.n = 0; // Khoi tao so luong sinh vien
    return L;
}

// Ham tim sinh vien theo ma so
int tim(struct DanhSach L, char *mssv) {
    for (int i = 0; i < L.n; i++) {
        if (strcmp(L.A[i].MSSV, mssv) == 0) {
            return i; // tra ve vi tri tim thay
        }
    }
    return -1; // khong tim thay
}

// Ham them sinh vien vao cuoi danh sach
void chenCuoi(struct DanhSach *L, struct SinhVien s) {
    if (L->n < MAX_SINH_VIEN) {
        L->A[L->n] = s;
        L->n++;
    }
}

// Ham xoa sinh vien theo ma so
void xoa(struct DanhSach *L, char *mssv) {
    int viTri = tim(*L, mssv);
    if (viTri != -1) {
        for (int i = viTri; i < L->n - 1; i++) {
            L->A[i] = L->A[i + 1]; // Dich chuyen phan tu
        }
        L->n--; // Giam so luong sinh vien
    } else {
        printf("Khong tim thay sinh vien %s\n", mssv);
    }
}

// Ham nhap danh sach sinh vien
struct DanhSach nhap() {
    struct DanhSach L = dsRong(); // Khoi tao danh sach rong
    int soSinhVien;

    scanf("%d", &soSinhVien);

    for (int i = 0; i < soSinhVien; i++) {
        struct SinhVien sv;
        scanf("%s", sv.MSSV);
        
        // Kiem tra ma so da ton tai
        if (tim(L, sv.MSSV) != -1) {
            i--; // Giam chi so de nhap lai sinh vien
            continue; // Chuyen sang vong lap tiep theo
        }

        getchar(); // Xoa ky tu newline con lai trong buffer
        fgets(sv.HoTen, sizeof(sv.HoTen), stdin);
        sv.HoTen[strcspn(sv.HoTen, "\n")] = 0; // Xoa ky tu newline o cuoi chuoi

        scanf("%f %f %f", &sv.DiemLT, &sv.DiemTH1, &sv.DiemTH2);

        chenCuoi(&L, sv); // Them sinh vien vao danh sach
    }

    return L; // Tra ve danh sach sinh vien
}

// Ham hien thi danh sach sinh vien
void hienThi(struct DanhSach L) {
    for (int i = 0; i < L.n; i++) {
        printf("%s - %s - %.2f - %.2f - %.2f\n", L.A[i].MSSV, L.A[i].HoTen, L.A[i].DiemLT, L.A[i].DiemTH1, L.A[i].DiemTH2);
    }
}

// Ham main
int main() {
    struct DanhSach L;
    L = nhap(); // Nhap danh sach sinh vien
    hienThi(L); // Hien thi danh sach sinh vien

    char mssv[10];
    scanf("%s", mssv);

    // Tim kiem va xoa sinh vien
    int viTri = tim(L, mssv);
    if (viTri != -1) {
        printf("Tim thay sinh vien %s. Thong tin sinh vien:\n", mssv);
        printf("%s - %s - %.2f - %.2f - %.2f\n", L.A[viTri].MSSV, L.A[viTri].HoTen, L.A[viTri].DiemLT, L.A[viTri].DiemTH1, L.A[viTri].DiemTH2);
        xoa(&L, mssv); // Xoa sinh vien
    } else {
        printf("Khong tim thay sinh vien %s\n", mssv);
    }

    return 0;
}


Danh sach lien ket
Hay viet khai bao cho kieu du lieu List voi cac thanh phan duoc mo ta nhu hinh tren de la mot danh sach lien ket don cac so nguyen
typedef struct Node {
    int Element;
    struct Node* Next;
} Node;
typedef Node* Position;
typedef Node* List;
Ten ham: makenullList()
void makenullList(List *pL) {
    *pL = (List)malloc(sizeof(struct Node)); // Cap phat bo nho cho nut dau tien
    (*pL)->Next = NULL; // Truong Next chi toi NULL
}
Ten ham (function name): member()
int member(int x, List L) {
    for (Position p = L->Next; p; p = p->Next)
        if (p->Element == x) return 1;
    return 0;
}
Ten ham (function name): sort()
void sort(List* pL) {
    for (Position p = (*pL)->Next; p; p = p->Next) {
        for (Position q = p->Next; q; q = q->Next) {
            if (p->Element > q->Element) {
                int temp = p->Element;
                p->Element = q->Element;
                q->Element = temp;
            }
        }
    }
}
Ten ham (function name): unionSet()
List unionSet(List L1, List L2) {
    List result;
    makenullList(&result);
    for (Position p = L1->Next; p; p = p->Next) append(p->Element, &result);
    for (Position p = L2->Next; p; p = p->Next)
        if (!member(p->Element, result)) append(p->Element, &result);
    return result;
}
Ten ham: deleteList()
void deleteList(Position p, List *pL) {
    if (p != NULL && p->Next != NULL) {
        Position temp = p->Next; // Luu vi tri cua nut can xoa
        p->Next = p->Next->Next; // Cap nhat lien ket de bo qua nut can xoa
        free(temp); // Giai phong bo nho
    }
}
Ten ham: removeAll()
void removeAll(int x, List *pL) {
    for (Position i = *pL; i->Next; )
        if (i == locate(x, *pL))
            deleteList(i, pL);
        else
            i = i->Next;
}

Xoa phan tu dau tien
void deleteHead(List *pL) {
    if (pL->Head != NULL) { // Kiem tra xem danh sach co nut nao khong
        Position temp = pL->Head; // Luu vi tri cua nut Head
        pL->Head = pL->Head->Next; // Cap nhat Head de tro den nut tiep theo
        free(temp); // Giai phong bo nho cho nut A
    }
}

Ten ham (function name): intersection()
List intersection(List L1, List L2) {
    List result;
    makenullList(&result);
    for (Position p = L1->Next; p != NULL; p = p->Next) {
        if (member(p->Element, L2)) append(p->Element, &result);
    }
    return result;
}
Ten ham (function name): copyEvenNumbers()
void copyEvenNumbers(List L1, List *pL2) {
    makenullList(pL2);
    for (Position p = L1->Next; p != NULL; p = p->Next) {
        if (p->Element % 2 == 0) append(p->Element, pL2);
    }
}
Ten ham: append()
void append(int x, List *pL) {
    Position newNode = (Position)malloc(sizeof(struct Node));
    newNode->Element = x;
    newNode->Next = NULL;
    Position p = *pL;
    while (p->Next) p = p->Next;
    p->Next = newNode;
}
Ten ham: insertList()
void insertList(int x, Position p, List *pL) {
    Position newNode = (Position)malloc(sizeof(struct Node));
    newNode->Element = x;
    newNode->Next = p->Next;
    p->Next = newNode;
}
Ten ham: locate()
Position locate(ElementType x, List L) {
    Position p = L;
    while (p->Next != NULL && p->Next->Element != x) {
        p = p->Next;
    }
    return p;
}
Ten ham (function name): normalize()
void normalize(List *pL) {
    for (Position p = (*pL)->Next; p; p = p->Next) {
        Position prev = p;
        for (Position q = p->Next; q; q = prev->Next) {
            if (p->Element == q->Element) {
                deleteList(prev, pL);
            } else {
                prev = q;
            }
        }
    }
}
Ten ham (function name): printOddNumbers()
void printOddNumbers(List L) {
    for (Position p = L->Next; p; p = p->Next)
        if (p->Element % 2 != 0)
            printf("%d ", p->Element);
}
Ten ham (function name): getAvg()
float getAvg(List L) {
    if (L->Next == NULL) return -10000.0f;
    float sum = 0.0f;
    int count = 0;
    for (Position p = L->Next; p != NULL; p = p->Next) {
        sum += p->Element;
        count++;
    }
    return sum / count;
}
Ten ham: readList()

void readList(List *pL) {
    int n, x;
    makenullList(pL);
    scanf("%d", &n);
    for (Position p = *pL; n--; p = p->Next) {
        scanf("%d", &x);
        p->Next = (Position)malloc(sizeof(struct Node));
        p->Next->Element = x;
        p->Next->Next = NULL;
    }
}
Ten ham (function name): readSet()
List readSet() {
    List L;
    makenullList(&L);
    int n, x;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &x);
        if (!member(x, L)) addFirst(x, &L);
    }
    return L;
}
Ten ham (function name): difference()
List difference(List L1, List L2) {
    List result;
    makenullList(&result);
    for (Position p = L1->Next; p; p = p->Next)
        if (!member(p->Element, L2))
            append(p->Element, &result);
    return result;
}
Ten ham (function name): erase()
void erase(int x, List *pL) {
    Position p = locate(x, *pL);
    if (p->Next) {
        Position temp = p->Next;
        p->Next = temp->Next;
        free(temp);
    } else {
        printf("Not found %d\n", x);
    }
}
Ten ham: addFirst()
void addFirst(int x, List* pL) {
    Position newNode = (Position)malloc(sizeof(struct Node));
    newNode->Element = x;
    newNode->Next = (*pL)->Next;
    (*pL)->Next = newNode;
}


Bang cach su dung nhung phep toan chuan tren danh sach, hay viet chuong trinh cho phep liet ke cac so chan va tinh trung binh cong cac phan tu la so chan trong danh sach

#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int Element;
    struct Node* Next;
} Node;
typedef Node* List;
typedef Node* Position;
// Khoi tao danh sach rong
void makenullList(List *pL) {
    *pL = (List)malloc(sizeof(Node));
    (*pL)->Next = NULL;
}
// Them phan tu vao cuoi danh sach
void append(int x, List *pL) {
    Position newNode = (Position)malloc(sizeof(Node));
    newNode->Element = x;
    newNode->Next = NULL;
    Position p = *pL;
    while (p->Next != NULL) {
        p = p->Next;
    }
    p->Next = newNode;
}
// Hien thi danh sach
void displayList(List L) {
    Position p = L->Next;
    while (p != NULL) {
        printf("%d ", p->Element);
        p = p->Next;
    }
    printf("\n");
}
// Tinh trung binh cong cac so chan
float getAvgEven(List L) {
    float sum = 0;
    int count = 0;
    Position p = L->Next;
    while (p != NULL) {
        if (p->Element % 2 == 0) {
            sum += p->Element;
            count++;
        }
        p = p->Next;
    }
    return (count == 0) ? -10000.0f : sum / count;
}
// Chep cac so chan sang danh sach ket qua
void copyEvenNumbers(List L1, List *pL2) {
    makenullList(pL2);
    Position p = L1->Next;
    while (p != NULL) {
        if (p->Element % 2 == 0) {
            append(p->Element, pL2);
        }
        p = p->Next;
    }
}
int main() {
    List L, evenList;
    int n, x;
    scanf("%d", &n);
    makenullList(&L);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        append(x, &L);
    }
    displayList(L);
    copyEvenNumbers(L, &evenList);
    displayList(evenList);
    float avg = getAvgEven(L);
    printf("%.3f\n", avg);
    return 0;
}



Bang cach su dung nhung phep toan chuan tren danh sach, hay viet chuong trinh cho phep sap xep danh sach tang dan

#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int Element;
    struct Node* Next;
} Node;
typedef Node* List;
typedef Node* Position;
// Khoi tao danh sach rong
void makenullList(List *pL) {
    *pL = (List)malloc(sizeof(Node));
    (*pL)->Next = NULL;
}
// Them phan tu vao cuoi danh sach
void append(int x, List *pL) {
    Position newNode = (Position)malloc(sizeof(Node));
    newNode->Element = x;
    newNode->Next = NULL;
    Position p = *pL;
    while (p->Next != NULL) {
        p = p->Next;
    }
    p->Next = newNode;
}
// Hien thi danh sach
void displayList(List L) {
    Position p = L->Next;
    while (p != NULL) {
        printf("%d ", p->Element);
        p = p->Next;
    }
    printf("\n");
}
// Sap xep danh sach tang dan
void sortList(List L) {
    if (L->Next == NULL) return; // Danh sach rong
    Position p, q;
    int temp;
    for (p = L->Next; p->Next != NULL; p = p->Next) {
        for (q = p->Next; q != NULL; q = q->Next) {
            if (p->Element > q->Element) {
                // Doi cho gia tri cua p va q
                temp = p->Element;
                p->Element = q->Element;
                q->Element = temp;
            }
        }
    }
}
int main() {
    List L;
    int n, x;
    scanf("%d", &n);
    makenullList(&L);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        append(x, &L);
    }
    displayList(L);
    sortList(L);
    displayList(L);
    return 0;
}

Bang cach su dung nhung phep toan chuan tren danh sach, hay viet chuong trinh cho phep nhap va hien thi mot danh sach so nguyen tu ban phim

#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int Element;
    struct Node* Next;
} Node;
typedef Node* List;
typedef Node* Position;

// Ham khoi tao danh sach rong
void makenullList(List *pL) {
    *pL = (List)malloc(sizeof(Node));
    (*pL)->Next = NULL;
}
// Ham them phan tu vao cuoi danh sach
void append(int x, List *pL) {
    Position newNode = (Position)malloc(sizeof(Node));
    newNode->Element = x;
    newNode->Next = NULL;
    Position p = *pL;
    while (p->Next != NULL) {
        p = p->Next;
    }
    p->Next = newNode;
}
// Ham hien thi danh sach
void displayList(List L) {
    Position p = L->Next; // Bo qua phan tu dau tien
    while (p != NULL) {
        printf("%d ", p->Element);
        p = p->Next;
    }
    printf("\n");
}
int main() {
    List L;
    int n, x;
    scanf("%d", &n);
    makenullList(&L);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        append(x, &L);
    }
    displayList(L);
    return 0;
}

Bang cach su dung nhung phep toan tren tap hop, hay viet chuong trinh cho phep tim tap hop giao cua 2 danh sach bieu dien tap hop

#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
	int Element;
	struct Node* Next;
}Node;
typedef Node* pos;
typedef Node* List;
void makenullList(List *pL){
	*pL = (List)malloc(sizeof(struct Node));
	(*pL)->Next = NULL;
}
void addFirst(int x, List *pL){
	pos n = (pos)malloc(sizeof(struct Node));
	n->Element = x;
	n->Next = (*pL)->Next;
	(*pL)->Next = n;
}
int member(int x, List L){
	pos p;
	for(p = L->Next; p; p = p->Next)
		if(p->Element == x) return 1;
	return 0;
}

List readSet(){
	List L;
	makenullList(&L);
	int n, x;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&x);
		if(!member(x,L)) addFirst(x,&L);
	}
	return L;
}
void printList(List L){
	pos p;
	for(p = L->Next; p; p = p->Next)
		printf("%d ",p->Element); 
	printf("\n");
}
void append(int x, List *pL){
	pos n = (pos)malloc(sizeof(struct Node));
	n->Element = x;
	n->Next = NULL;
	pos p = *pL;
	while(p->Next)u
		p = p->Next;
	p->Next = n;
}
List intersection(List L1, List L2){
	List L;
	makenullList(&L);
	pos p;
	for(p = L1->Next; p; p = p->Next){
		if(member(p->Element,L2)) append(p->Element,&L);
	}
	return L;
}
int main(){
	List L1 = readSet();
	List L2 = readSet();
	printList(L1);
	printList(L2);
	List L = intersection(L1,L2);
	printList(L);
	return 0;
}

Bang cach su dung nhung phep toan chuan tren danh sach, hay viet chuong trinh cho phep xoa phan tu x xuat hien dau tien trong danh sach

#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
	int Element;
	struct Node* Next;
}Node;
typedef Node* Pos;
typedef Node* List;
void makenullList(List *pL){
	*pL = (Pos)malloc(sizeof(struct Node));
	(*pL)->Next = 0;
}
void append(int x, List *pL){
	Pos n = (Pos)malloc(sizeof(struct Node));
	n->Element = x;
	n->Next = NULL;
	Pos p = *pL;
	while(p->Next)
		p = p->Next;
	p->Next = n;
}
List read(){
	List L;
	makenullList(&L);
	int n, x;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&x);
		append(x,&L);
	}
	return L;
}
void printList(List L){
	Pos p;
	for(p = L->Next; p; p = p->Next)
		printf("%d ",p->Element);
	printf("\n");
}
Pos locate(int x, List L){
	Pos p = L;
	while(p->Next!=NULL && p->Next->Element != x)
		p = p->Next;
	return p;
}
void deleteList(Pos p, List *pL){
	if(p!=NULL && p->Next!=NULL){
		Pos tmp = p->Next;
		p->Next = p->Next->Next;
		free(tmp);
	}
}
void removeAll(int x, List *pL){
	Pos p;
	for(p = *pL; p->Next;){
		if(p==locate(x,*pL)) deleteList(p,pL);
		else p = p->Next;
	}
}
int main(){
	List L = read();
	printList(L);
	int x;
	scanf("%d",&x);
	removeAll(x,&L);
	printList(L);
	return 0;
}


Bang cach su dung nhung phep toan chuan tren danh sach, hay viet chuong trinh cho phep tinh trung binh cong cac phan tu trong danh sach

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int Element;
    struct Node* Next;
} Node;

typedef Node* List;

// Ham khoi tao danh sach rong
void makenullList(List *pL) {
    *pL = (List)malloc(sizeof(Node));
    (*pL)->Next = NULL;
}

// Ham them phan tu vao danh sach
void append(int x, List *pL) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->Element = x;
    newNode->Next = NULL;

    Node* p = *pL;
    while (p->Next != NULL) {
        p = p->Next;
    }
    p->Next = newNode; // Them vao cuoi danh sach
}

// Ham hien thi danh sach
void displayList(List L) {
    Node* p = L->Next; // Bo qua phan tu dau tien
    while (p != NULL) {
        printf("%d ", p->Element);
        p = p->Next;
    }
    printf("\n");
}

// Ham tinh trung binh cong cac phan tu trong danh sach
double calculateAverage(List L) {
    if (L->Next == NULL) return 0.0; // Neu danh sach rong

    Node* p = L->Next;
    int sum = 0, count = 0;

    while (p != NULL) {
        sum += p->Element;
        count++;
        p = p->Next;
    }

    return (double)sum / count; // Tinh trung binh cong
}

int main() {
    List L;
    int n;

    // Nhap danh sach
    scanf("%d", &n);
    makenullList(&L);
    
    for (int i = 0; i < n; i++) {
        int element;
        scanf("%d", &element);
        append(element, &L);
    }

    // Hien thi danh sach
    displayList(L);

    // Tinh va hien thi trung binh cong
    double average = calculateAverage(L);
    printf("%.3f\n", average);

    // Giai phong bo nho
    Node* current = L;
    Node* nextNode;
    while (current != NULL) {
        nextNode = current->Next;
        free(current);
        current = nextNode;
    }

    return 0;
}

Bang cach su dung nhung phep toan chuan tren danh sach, hay viet chuong trinh cho phep liet ke cac so le, so chan trong danh sach

#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
	int Element;
	struct Node* Next;
}Node;
typedef Node* List;
typedef Node* pos;
void makenullList(List *pL){
	*pL = (List)malloc(sizeof(struct Node));
	(*pL)->Next = NULL;
}
void append(int x, List *pL){
	pos n = (pos)malloc(sizeof(struct Node));
	n->Element = x;
	n->Next = NULL;
	pos p = *pL;
	while(p->Next)
		p = p->Next; 
	p->Next = n;
}
List readSet(){
	List L;
	makenullList(&L);
	int n, x;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&x);
		append(x,&L);
	}
	return L; 
}
void print(List L){
	pos p;
	for(p = L->Next; p; p = p->Next)
		printf("%d ",p->Element);
	printf("\n");
	for(p = L->Next; p; p = p->Next)
		if(p->Element % 2 != 0) printf("%d ",p->Element);
	printf("\n");
	for(p = L->Next; p; p = p->Next)
		if(p->Element % 2 == 0) printf("%d ",p->Element);
}

int main() {
    List L = readSet(); 
    print(L);
    return 0;
}

Bang cach su dung nhung phep toan tren tap hop, hay viet chuong trinh cho phep tim tap hop hop cua 2 danh sach bieu dien tap hop

#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
	int Element;
	struct Node* Next;
}Node;
typedef Node* Pos;
typedef Node* List;
void makenullList(List *pL){
	*pL = (Pos)malloc(sizeof(struct Node));
	(*pL)->Next = 0;
}
void append(int x, List *pL){
	Pos n = (Pos)malloc(sizeof(struct Node));
	n->Element = x;
	n->Next = NULL;
	Pos p = *pL;
	while(p->Next)
		p = p->Next;
	p->Next = n;
}
void addFirst(int x, List *pL){
	Pos n = (Pos)malloc(sizeof(struct Node));
	n->Element = x;
	n->Next = (*pL)->Next;
	(*pL)->Next = n;
}
int member(int x, List L){
	Pos p;
	for(p = L->Next; p; p = p->Next)
		if(p->Element == x) return 1;
	return 0; 
}
List read(){
	List L;
	makenullList(&L);
	int n, x;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&x);
		if(!member(x,L))
			addFirst(x,&L);
	}
	return L;
}
void printList(List L){
	Pos p;
	for(p = L->Next; p; p = p->Next)
		printf("%d ",p->Element);
	printf("\n");
}
List unionSet(List L1, List L2){
	List L;
	makenullList(&L);
	Pos p, q;
	for(p = L1->Next; p; p = p->Next)
		append(p->Element,&L);
	for(q = L2->Next; q; q = q->Next)
		if(!member(q->Element,L)) append(q->Element,&L);
	return L;
}
int main(){
	List L1 = read();
	List L2 = read();
	printList(L1);
	printList(L2);
	List L = unionSet(L1, L2);
	printList(L);
	return 0;
}









Ngan Xep
Ten ham: giatriDinh()
int giatriDinh(NganXep S){
    return S.DuLieu[S.Dinh];
}
Khai bao NganXep
#define SoPhanTu 100
typedef struct{
    int DuLieu[SoPhanTu];
    int Dinh;
}NganXep;
Ten ham: ktDay()
int ktDay(NganXep S){
    return S.Dinh ==0;
}
Ten ham: ktRong()
int ktRong(NganXep S){
 return S.Dinh == SoPhanTu;
}
Ten ham: hienthi()
void hienthi(NganXep *pS){
    while(!ktRong(*pS)){
        printf("%d ",giatriDinh(*pS));
        xoa(pS);
    }
    printf("\n");
}
Ten ham: them()
void them(int X, NganXep *pS){
    if(!ktDay(*pS)){
        pS->Dinh--;
        pS->DuLieu[pS->Dinh] = X;
    }
}
Ten ham: xoa()
void xoa(NganXep *pS){
    if (!ktRong(*pS))
    pS->Dinh++;
}
Ten ham: khoitao()
void khoitao(NganXep *pS){
    pS->Dinh = SoPhanTu;
}
UNG DUNG NGAN XEP
Ten ham: doiNhiPhan()

void doiNhiPhan(int n, NganXep *pS) {
    khoitao(pS); // Khoi tao ngan xep
    // Chuyen doi so nguyen duong n ve dang nhi phan
    while (n > 0) {
        int du = n % 2; // Lay phan du khi chia n cho 2
        them(du, pS); // Them phan du vao ngan xep
        n = n / 2; // Giam n di mot nua
    }
}
void hienthi(NganXep *pS) {
    while (!ktRong(*pS)) {
        int giaTri = giatriDinh(*pS);
        printf("%d ", giaTri);
        xoa(pS);
    }
}


Ham inThaplucphan() 

void inThaplucphan(int n) {
    Stack s;
    makenullStack(&s); // Khoi tao ngan xep
    // Mang chua cac ky tu thap luc phan
    char hexDigits[] = "0123456789ABCDEF";
    // Chuyen doi so nguyen n ve dang thap luc phan
    while (n > 0) {
        int du = n % 16; // Lay phan du khi chia n cho 16
        push(hexDigits[du], &s); // Them ky tu tuong ung vao ngan xep
        n = n / 16; // Giam n di mot phan muoi sau
    }
    // In ket qua tu ngan xep
    while (!emptyStack(s)) {
        char c = top(s); // Lay gia tri tai dinh ngan xep
        pop(&s); // Xoa phan tu tai dinh ngan xep
        printf("%c", c); // In ky tu
    }
    printf("\n"); // Xuong dong sau khi in xong
}

Ham ktChuoi() 

#define MAX_LENGTH 100 // Do dai toi da cua chuoi
// Gia su kieu du lieu Stack va cac ham lien quan da duoc dinh nghia o day
int ktChuoi() {
    Stack S;
    makenullStack(&S); // Khoi tao ngan xep
    char str[MAX_LENGTH];
    fgets(str, MAX_LENGTH, stdin); // Nhap chuoi
    // Loai bo ky tu newline neu co
    str[strcspn(str, "\n")] = '\0';
    // Duyet qua tung ky tu trong chuoi
    for (int i = 0; i < strlen(str); i++) {
        char ch = str[i];

        if (ch == '(') {
            push(ch, &S); // Neu la '(', dua vao ngan xep
        } else if (ch == ')') {
            if (emptyStack(S)) {
                return 0; // Ngan xep rong, chuoi khong dung
            }
            pop(&S); // Xoa phan tu tren dinh ngan xep
        }
    }
    // Kiem tra neu ngan xep rong
    return emptyStack(S) ? 1 : 0; // 1 neu dung, 0 neu khong dung
}

Ham tinhGiatri()

#define MAX_LENGTH 100 // Do dai toi da cua chuoi

// Gia su kieu du lieu Stack va cac ham lien quan da duoc dinh nghia o day

double tinhGiatri(char *expression) {
    Stack S;
    makenullStack(&S); // Khoi tao ngan xep

    for (int i = 0; i < strlen(expression); i++) {
        char ch = expression[i];

        if (isdigit(ch)) {
            // Neu la ky tu so, chuyen thanh so thuc va dua vao ngan xep
            double num = ch - '0';
            push(num, &S);
        } else if (ch == ' ') {
            // Bo qua ky tu khoang trang
            continue;
        } else {
            // Neu la ky tu phep toan, lay hai phan tu tren dinh ngan xep ra
            double val2 = top(S); pop(&S);
            double val1 = top(S); pop(&S);
            double result;

            // Thuc hien phep toan tuong ung
            switch (ch) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
                default: printf("Phep toan khong hop le\n"); return 0;
            }

            // Dua ket qua phep toan vao ngan xep
            push(result, &S);
        }
    }

    // Gia tri cuoi cung tren dinh ngan xep la ket qua cua bieu thuc hau to
    return top(S);
}



Ham chuyenHauto() 

#define MAX_LENGTH 100 // Do dai toi da cua chuoi

// Gia su kieu du lieu Stack va cac ham lien quan da duoc dinh nghia o day

void chuyenHauto(char *trungto, char *hauto) {
    Stack S;
    makenullStack(&S); // Khoi tao ngan xep
    int j = 0; // Chi so cho chuoi hauto

    for (int i = 0; i < strlen(trungto); i++) {
        char c = trungto[i];
        if (isalnum(c)) {
            // Neu la toan hang (so hoac chu cai), dua vao chuoi hauto
            hauto[j++] = c;
        } else if (c == '(') {
            // Neu la dau '(', dua vao ngan xep
            push(c, &S);
        } else if (c == ')') {
            // Neu la dau ')', lay cac toan tu ra khoi ngan xep cho den khi gap '('
            while (!emptyStack(S) && top(S) != '(') {
                hauto[j++] = top(S);
                pop(&S);
            }
            pop(&S); // Xoa dau '(' ra khoi ngan xep
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            // Neu la toan tu, xu ly theo muc uu tien
            while (!emptyStack(S) && top(S) != '(' && mucUutien(c) <= mucUutien(top(S))) {
                hauto[j++] = top(S);
                pop(&S);
            }
            push(c, &S);
        }
    }

    // Dua tat ca cac toan tu con lai trong ngan xep vao chuoi hauto
    while (!emptyStack(S)) {
        hauto[j++] = top(S);
        pop(&S);
    }

    hauto[j] = '\0'; // Ket thuc chuoi hauto
}

// int main() {
//     char trungto[MAX_LENGTH] = "(3+4)/2";
//     char hauto[MAX_LENGTH];

//     chuyenHauto(trungto, hauto);
//     printf("Bieu thuc hau to: %s\n", hauto);

//     return 0;
//}

Hang Doi
Tinh so don vi thoi gian can thiet cua Minh de hoan thanh n cong viec duoc giao.

#include <stdio.h>
#include <stdlib.h>
#define MAX_N 100
int main() {
    int N;
    scanf("%d", &N);
    int tasks[N];       // Danh sach cac cong viec duoc giao
    int optimal[N];     // Danh sach cac cong viec toi uu
    int time = 0;       // Thoi gian can thiet
    // Nhap danh sach cong viec duoc giao
    for (int i = 0; i < N; i++) {
        scanf("%d", &tasks[i]);
    }
    // Nhap danh sach cong viec toi uu
    for (int i = 0; i < N; i++) {
        scanf("%d", &optimal[i]);
    }
    int optimalIndex = 0; // Chi so cho danh sach toi uu
    // Su dung vong lap de xu ly cac cong viec
    for (int i = 0; i < N;) {
        // Neu cong viec hien tai khop voi cong viec toi uu
        if (tasks[i] == optimal[optimalIndex]) {
            // Thuc hien cong viec
            optimalIndex++;
            time++; // Tang thoi gian
            i++;    // Chuyen sang cong viec tiep theo trong danh sach giao
        } else {
            // Neu khong khop, chuyen cong viec vao cuoi
            int temp = tasks[i];
            for (int j = i; j < N - 1; j++) {
                tasks[j] = tasks[j + 1]; // Di chuyen cong viec
            }
            tasks[N - 1] = temp; // Dua cong viec vao cuoi danh sach
            time++; // Tang thoi gian
        }
        // Neu da thuc hien xong tat ca cong viec toi uu
        if (optimalIndex >= N) {
            break;
        }

        // Neu danh sach cong viec da trong
        if (i >= N) {
            i = 0; // Reset chi so ve dau danh sach
        }
    }

    printf("%d\n", time);
    return 0;
}

2. Minh co mot hang doi Q va co ay muon thuc hien N thao tac, moi thao tac la mot trong 2 dang sau:
E x: them x vao hang doi va in ra so luong phan tu cua hang doi
D: xoa phan tu dau hang, dong thoi in phan tu da xoa va so luong phan tu cua hang doi sau khi xoa, 2 gia tri nay cach nhau khoang trang. Neu hang doi rong, in -1 o cho phan tu da xoa.
Hay giup Minh Minh thuc hien cac thao tac tren.

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Ham khoi tao hang doi
void initializeQueue(Queue *q) {
    q->front = 0;
    q->rear = 0;
}

// Ham kiem tra hang doi rong
int isEmpty(Queue *q) {
    return q->front == q->rear;
}

// Ham kiem tra hang doi day
int isFull(Queue *q) {
    return q->rear == MAX_SIZE;
}

// Ham them phan tu vao hang doi
void enqueue(Queue *q, int x) {
    if (!isFull(q)) {
        q->data[q->rear] = x;
        q->rear++;
    }
}

// Ham xoa phan tu khoi hang doi
int dequeue(Queue *q) {
    if (!isEmpty(q)) {
        return q->data[q->front++];
    }
    return -1; // Tra ve -1 neu hang doi rong
}

// Ham lay so luong phan tu trong hang doi
int size(Queue *q) {
    return q->rear - q->front;
}

int main() {
    Queue q;
    initializeQueue(&q);
    
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        char command[2]; // De doc thao tac 'E' hoac 'D'
        scanf("%s", command);

        if (command[0] == 'E') {
            int x;
            scanf("%d", &x);
            enqueue(&q, x);
            printf("%d\n", size(&q)); // In ra so luong phan tu sau khi them
        } else if (command[0] == 'D') {
            int removed = dequeue(&q);
            if (removed == -1) {
                printf("-1 %d\n", size(&q)); // In ra -1 va so luong sau khi xoa
            } else {
                printf("%d %d\n", removed, size(&q)); // In ra phan tu da xoa va so luong sau khi xoa
            }
        }
    }

    return 0;
}


UNG DUNG HANG DOI
Bang cach su dung kieu du lieu truu tuong Stack va Queue da cho, hay viet chuong trinh kiem tra mot chuoi ky tu co doc xuoi va doc nguoc nhu nhau hay khong (kiem tra chuoi palindrome).

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 1000 // Kich thuoc toi da cho ngan xep va hang doi

// Dinh nghia kieu du lieu ky tu
typedef char ElementType;

// Cau truc ngan xep
typedef struct {
    ElementType data[MAX_SIZE];
    int top;
} Stack;

// Cau truc hang doi
typedef struct {
    ElementType data[MAX_SIZE];
    int front, rear;
} Queue;

// Ham khoi tao ngan xep
void makenullStack(Stack *pS) {
    pS->top = -1;
}

// Kiem tra ngan xep rong
int emptyStack(Stack S) {
    return S.top == -1;
}

// Them phan tu vao ngan xep
void push(ElementType x, Stack *pS) {
    if (pS->top < MAX_SIZE - 1) {
        pS->data[++pS->top] = x;
    }
}

// Lay phan tu tren dinh ngan xep
ElementType top(Stack S) {
    if (!emptyStack(S)) {
        return S.data[S.top];
    }
    return '\0'; // Tra ve gia tri mac dinh neu ngan xep rong
}

// Xoa phan tu tren dinh ngan xep
void pop(Stack *pS) {
    if (!emptyStack(*pS)) {
        pS->top--;
    }
}

// Ham khoi tao hang doi
void makenullQueue(Queue *pQ) {
    pQ->front = 0;
    pQ->rear = 0;
}

// Kiem tra hang doi rong
int emptyQueue(Queue Q) {
    return Q.front == Q.rear;
}

// Them phan tu vao hang doi
void enQueue(ElementType x, Queue *pQ) {
    if (pQ->rear < MAX_SIZE) {
        pQ->data[pQ->rear++] = x;
    }
}

// Lay phan tu o dau hang doi
ElementType front(Queue Q) {
    if (!emptyQueue(Q)) {
        return Q.data[Q.front];
    }
    return '\0'; // Tra ve gia tri mac dinh neu hang doi rong
}

// Xoa phan tu o dau hang doi
void deQueue(Queue *pQ) {
    if (!emptyQueue(*pQ)) {
        pQ->front++;
    }
}

// Ham kiem tra chuoi palindrome
void checkPalindrome(const char *input) {
    Stack s;
    Queue q;
    makenullStack(&s);
    makenullQueue(&q);

    // Hien thi chuoi vua nhap
    printf("\"%s\"", input);

    // Doc tung ky tu trong chuoi
    for (int i = 0; input[i] != '\0'; i++) {
        char ch = input[i];
        // Chi lay chu cai
        if (isalpha(ch)) {
            char lowerCh = tolower(ch); // Chuyen ve chu thuong
            push(lowerCh, &s);          // Dua vao ngan xep
            enQueue(lowerCh, &q);       // Dua vao hang doi
        }
    }

    // So sanh cac phan tu trong ngan xep va hang doi
    while (!emptyQueue(q)) {
        if (top(s) != front(q)) {
            printf(" doc xuoi khac doc nguoc\n");
            return;
        }
        pop(&s);
        deQueue(&q);
    }

    printf(" doc xuoi va doc nguoc nhu nhau\n");
}

int main() {
    char input[MAX_SIZE];
    // printf("Nhap chuoi: ");
    fgets(input, MAX_SIZE, stdin); // Doc chuoi tu nguoi dung
    input[strcspn(input, "\n")] = 0; // Loai bo ky tu newline

    checkPalindrome(input); // Kiem tra chuoi
    return 0;
}


Cay tim kiem nhi phan

1. Nguyen mau (Prototype)
Ten ham: printPath()
Tham so: 
        - x - int
        - T - Tree
Kieu tra ve: khong
Than ham (Body)
Ap dung giai thuat tim kiem tren cay tim kiem nhi phan, moi khi di toi mot nut tren theo giai thuat tim, in gia tri khoa tai nut do len man hinh
void printPath(int x, Tree T) {
    while (T != NULL) {
        printf("%d ", T->Key);
        if (T->Key == x) {
            printf("-> Tim thay\n");
            return;
        }
        T = (x < T->Key) ? T->Left : T->Right;
    }
    printf("-> Khong thay\n");
}
2. Nguyen mau (Prototype)
Ten ham: insertNode()
Tham so:
          - X - int
          - pT - con tro Tree
Kieu tra ve: khong
Than ham (Body)
Them khoa X vao cay tim kiem nhi phan chi boi con tro pT (xem lai giai thuat trong phan ly thuyet)
void insertNode(int x, Tree *pT) {
    if (*pT == NULL) {
        *pT = (Tree)malloc(sizeof(struct Node));
        (*pT)->Key = x;
        (*pT)->Left = (*pT)->Right = NULL;
    } else if (x < (*pT)->Key) {
        insertNode(x, &(*pT)->Left);
    } else if (x > (*pT)->Key) {
        insertNode(x, &(*pT)->Right);
    }
}
3. Nguyen mau (Prototype)
Ten ham: rightSibling()
Tham so: 
        - x - int
        - T - Tree
Kieu tra ve: Tree
Than ham (Body)
Neu x co trong cay T, tra ve con tro chi den nut anh em ruot phai cua x (neu x khong co anh em ruot phai ket qua tra ve la NULL); nguoc lai (x khong co), ket qua tra ve la NULL
Tree rightSibling(int x, Tree T) {
    Tree parent = NULL;
    while (T != NULL && T->Key != x) {
        parent = T;
        T = (x < T->Key) ? T->Left : T->Right;
    }
    return (T == NULL || parent == NULL || parent->Left != T) ? NULL : parent->Right;
}
4. Nguyen mau (Prototype)
Ten ham: getParent()
Tham so: 
        - x - int
        - T - Tree
Kieu tra ve: Tree
Than ham (Body)
Neu x co trong cay T, tra ve con tro chi den nut cha cua x (neu x la goc ket qua tra ve la NULL); nguoc lai (x khong co), ket qua tra ve la NULL
Tree getParent(int x, Tree T) {
    Tree parent = NULL;
    while (T != NULL && T->Key != x) {
        parent = T;
        T = (x < T->Key) ? T->Left : T->Right;
    }
    return (T == NULL) ? NULL : parent;
}
5. Nguyen mau (Prototype)
Ten ham: getHeight()
Tham so: 
        - T -  Tree
Kieu tra ve: int
Than ham (Body)
Neu T rong ket qua tra ve la -1, nguoc lai ket qua tra ve la chieu cao cua nut goc cua cay

int getHeight(Tree T) {
    if (T == NULL) {
        return -1; // Neu cay rong, chieu cao la -1
    }

    // Tinh chieu cao cua nhanh trai va nhanh phai
    int leftHeight = getHeight(T->Left);
    int rightHeight = getHeight(T->Right);

    // Chieu cao cua cay la max chieu cao cua hai nhanh cong them 1
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}


6. Nguyen mau (Prototype)
Ten ham: inOrder()
Tham so: T - Tree
Kieu tra ve: khong
Than ham (Body)
Liet ke cac khoa tren cay T theo bieu thuc duyet tien tu

void inOrder(Tree T) {
    if (T == NULL) {
        return; // Neu cay rong, khong lam gi
    }
    // Duyet nhanh trai
    inOrder(T->Left);
    // In gia tri khoa tai nut hien tai
    printf("%d ", T->Key);
    // Duyet nhanh phai
    inOrder(T->Right);
}


7. Nguyen mau (Prototype)
Ten ham: getNext()
Tham so: 
        - x - int
        - T - Tree
Kieu tra ve: Tree
Than ham (Body)
Tra ve con tro cua nut dung sau nut co khoa x trong cay TKNP trong phep duyet trung tu; neu x la khoa phai nhat cua cay thi ket qua tra ve la NULL
Vi du                      27
                           /          \
                     12               40
                                      /
                                    30
          Nut  27 dung sau 12
          Nut  40 dung sau 30
          Nut 40 khong co nut dung sau

Tree getNext(int x, Tree T) {
    Tree successor = NULL;
    while (T != NULL) {
        if (x < T->Key) {
            successor = T;
            T = T->Left;
        } else if (x > T->Key) {
            T = T->Right;
        } else {
            if (T->Right != NULL) {
                T = T->Right;
                while (T->Left != NULL) T = T->Left;
                return T;
            }
            return successor;
        }
    }
    return NULL;
}

8. Nguyen mau (Prototype)
Ten ham: hNode()
Tham so: 
       - x - int
       - T -  Tree
Kieu tra ve: int
Than ham (Body)
Neu x khong co trong cay, ket qua tra ve la -1, nguoc lai ket qua tra ve la chieu cao cua nut co khoa la x

int getHeight(Tree T) {
    return (T == NULL) ? -1 : 1 + ((getHeight(T->Left) > getHeight(T->Right)) ? getHeight(T->Left) : getHeight(T->Right));
}
int hNode(int x, Tree T) {
    while (T != NULL) {
        if (x == T->Key) {
            return getHeight(T);
        } else if (x < T->Key) {
            T = T->Left;
        } else {
            T = T->Right;
        }
    }
    return -1; // Neu khong tim thay x
}

9. Nguyen mau (Prototype)
Ten ham: preOrder()
Tham so: T - Tree
Kieu tra ve: khong
Than ham (Body)
Liet ke cac khoa tren cay T theo bieu thuc duyet tien tu

void preOrder(Tree T) {
    // Neu cay rong, khong lam gi
    if (T == NULL) {
        return;
    }
    // In gia tri khoa tai nut hien tai
    printf("%d ", T->Key);
    // Duyet nhanh trai
    preOrder(T->Left);
    // Duyet nhanh phai
    preOrder(T->Right);
}

10. Nguyen mau (Prototype)
Ten ham: deleteNode()
Tham so: 
        - x - int
        - pT - con tro Tree
Kieu tra ve: khong
Than ham (Body)
Tien hanh xoa nut co khoa la x trong cay chi boi con tro pT

Tree findMin(Tree T) {
    while (T && T->Left) T = T->Left;
    return T;
}
void deleteNode(int x, Tree *pT) {
    if (*pT == NULL) return;
    if (x < (*pT)->Key) {
        deleteNode(x, &(*pT)->Left);
    } else if (x > (*pT)->Key) {
        deleteNode(x, &(*pT)->Right);
    } else {
        Tree temp = *pT;
        if (!(*pT)->Left) {
            *pT = (*pT)->Right;
        } else if (!(*pT)->Right) {
            *pT = (*pT)->Left;
        } else {
            temp = findMin((*pT)->Right);
            (*pT)->Key = temp->Key;
            deleteNode(temp->Key, &(*pT)->Right);
            return;
        }
        free(temp);
    }
}

11. Nguyen mau (Prototype)
Ten ham: getPrevious()
Tham so: 
        - x - int
        - T - Tree
Kieu tra ve: Tree
Than ham (Body)
Tra ve con tro cua nut dung truoc nut co khoa x trong cay TKNP; neu x la khoa trai nhat cua cay thi ket qua tra ve la NULL
Vi du                      27
                           /          \
                     12               40
                                      /
                                    30
          Nut 30 dung truoc 40
          Nut  27 dung truoc 30
          Nut 12 khong co nut dung truoc

Tree getPrevious(int x, Tree T) {
    Tree previous = NULL;
    while (T != NULL) {
        if (x > T->Key) {
            previous = T;
            T = T->Right;
        } else if (x < T->Key) {
            T = T->Left;
        } else {
            if (T->Left != NULL) {
                previous = T->Left;
                while (previous->Right != NULL) previous = previous->Right;
            }
            return previous;
        }
    }
    return NULL;
}

12. Nguyen mau (Prototype)
Ten ham: initTree()
Tham so: khong
Kieu tra ve: Tree
Than ham (Body)
Khai bao mot cay T, cho T tro ve NULL va tra ve ket qua cua ham la T
Tree initTree() {
    return NULL; // Tra ve NULL de bieu thi cay rong
}

13. Nguyen mau (Prototype)
Ten ham: searchNode()
Tham so: 
        - x - int
        - T - Tree
Kieu tra ve: Tree
Than ham (Body)
Neu x co trong cay T, tra ve con tro chi den khoa x; nguoc lai ket qua tra ve la NULL

Tree searchNode(int x, Tree T) {
    while (T != NULL) {
        if (x == T->Key) {
            return T; // Neu tim thay khoa x, tra ve con tro toi nut
        } else if (x < T->Key) {
            T = T->Left; // Tim trong nhanh trai
        } else {
            T = T->Right; // Tim trong nhanh phai
        }
    }
    return NULL; // Neu khong tim thay, tra ve NULL
}

14. Nguyen mau (Prototype)
Ten ham: isEmpty()
Tham so: T - Tree
Kieu tra ve: int
Than ham (Body)
Neu cay T rong, ket qua tra ve la 1, nguoc lai ket qua tra ve la 0
int isEmpty(Tree T) {
    return T == NULL; // Tra ve 1 neu cay rong, 0 neu khong
}
15. Nguyen mau (Prototype)
Ten ham: posOrder()
Tham so: T - Tree
Kieu tra ve: khong
Than ham (Body)
Liet ke cac khoa tren cay T theo bieu thuc duyet hau tu
void posOrder( T) {
    if (T == NULL) return; // Neu cay rong, khong lam gi ca
    posOrder(T->Left);  // Duyet nhanh trai
    posOrder(T->Right); // Duyet nhanh phai
    printf("%d ", T->Key); // In khoa cua nut hien tai
}









