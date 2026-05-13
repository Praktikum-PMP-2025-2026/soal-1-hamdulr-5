/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 05 - Foundation of Algorithm
 *   Hari dan Tanggal    : Rabu, 13 Mei 2026
 *   Nama (NIM)          : Hamzah Abdul Rahim (13224066)
 *   Nama File           : Soal 1
 *   Deskripsi           : Soal mengenai kevalidan suatu string, dan mencari banyaknya
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct n{
    char kur;
    struct n* next;
}Node;



void addToStart(Node **head, char c){
    Node * newEl = (Node*)malloc(sizeof(Node));
    newEl->kur = c;
    newEl->next = *head;
    *head = newEl;
}

int power(int base, int exp){
    int res = 1;
    for(int i = 1; i<=exp;i++){
        res = res*base;
    }
    //printf("2^%d = %d\n", exp, res );
    return res;
}

void show(Node *head){
    if(head == NULL){
        printf("NO ELEMENTS\n");
        return;
    }
    Node * c;
    c = head;
    while(c!=NULL){
        char kurs;
        if(c->kur == '0'){
            kurs = ')';
        }
        else if(c->kur == '1'){
            kurs = '(';
        }
        printf("%c", kurs);
        c = c->next;
    }
    printf("\n");
    return;
}

void intToBin(int n, Node ** head){
    int c = n;
    while(c!=0){
        if(c%2 == 1){
            addToStart(head, '1');
        }
        else{
            addToStart(head, '0');
        }
        c = c/2;
    }
    //show(*head);
}

int checkvalid(int n, Node * head){
    Node * cur;
    cur = head;
    int ones, zeros;
    ones = 0;
    zeros = 0;
    //printf("masuk checkvalid\n");
    while(cur!=NULL){
        if(cur->kur == '0'){
            zeros++;
            if(zeros>ones){
                //printf("tdk valid\n");
                return 0;
            }
        }
        else{
            ones++;
        }
        cur = cur->next;
    }
    if(zeros == n/2 && ones == n/2){
        //printf("valid\n");
        return 1;
    }
    else{
        //printf("tdk valid\n");
        return 0;
    }
}

void findValids(int n){
    //printf("masuk findvalids\n");
    int banyak = 0;
    int first;
    first = 0;
    for(int i = 0;i<n/2;i++){
        first = first + power(2, (n/2)+i);
    }
    //printf("first = %d\n", first);
    int end;
    end = power(2, n-1);
    for(int i = 0;i<(n-2)/2;i++){
        end = end + power(2, 1+i);
    }
    //printf("end = %d\n", end);
    for(int i = first; i>=end;i--){
        Node * head = NULL;
        intToBin(i, &head);
        int val = checkvalid(n, head);
        if(val == 1){
            banyak++;
            show(head);
        }
    }
    if(n == 0){
        printf("TOTAL 1\n");
        return;
    }
    printf("TOTAL %d\n", banyak);
    return;

}



int main(){
    int n;
    scanf("%d", &n);

    findValids(n*2);

}
