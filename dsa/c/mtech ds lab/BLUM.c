#include<stdio.h>
#include<stdlib.h>

int k = 5;
int MAXN = 72; // will check this

void swap(int *a, int* b){
    int c = *a;
    *a = *b;
    *b = c;
}

void insertion_sort(int* arr, int start, int end){
    for(int i = start+1; i<=end; i++){
        for(int j = i-1; j>=start; j--){
            if(arr[j]>arr[j+1]) swap(&arr[j], &arr[j+1]);
            else break;
        }
    }
}

int max(int a, int b){
    if(a>b) return a;
    return b;
}

int rth_element_brute(int* arr, int sz, int r){
    int copy_arr[sz];
    for(int i = 0; i<sz; i++) copy_arr[i] = arr[i];
    insertion_sort(copy_arr, 0, sz-1);
    return copy_arr[r-1];
}

// constraints are 0<n<1000000, 0<r<=n
int rth_element(int *arr, int sz, int r){
    if(sz<=MAXN){
        insertion_sort(arr, 0, sz-1);
        return arr[r-1];
    }
    int medians_sz = (sz+4)/5; // upper bound
    int medians_arr[medians_sz];
    for(int i = 0; i<sz; i+=5){
        insertion_sort(arr, i, max(i+4, sz-1));
        medians_arr[i/5] = arr[i+2];
    }
    int median_of_medians = rth_element(medians_arr, medians_sz, medians_sz/2);
    
    int smaller[sz], larger[sz];
    int ptr1 = 0, ptr2 = 0;
    int med_count = 0;
    for(int i = 0; i<sz; i++){          // missed edge case => have put median_of_medians too into smaller array
        if(arr[i] == median_of_medians){
            if(med_count) smaller[ptr1++] = arr[i];
            med_count++;
        }
        else if(arr[i]<median_of_medians) smaller[ptr1++] = arr[i];
        else larger[ptr2++] = arr[i];
    }

    if(r == ptr1+1) return median_of_medians;
    if(r <= ptr1){
        return rth_element(smaller, ptr1, r);
    }
    return rth_element(larger, ptr2, r-ptr1-1);
}



int main(){
    int sz = 200;
    int arr[sz], og_arr[sz];
    srand(0);
    for(int i = 0; i<sz; i++){
        og_arr[i] = arr[i] = rand()%500;

    } 
    for(int t = 0; t<100; t++){

        int random_rank = rand()%sz + 1;
        int brute = rth_element_brute(arr, sz, random_rank);
        int blum = rth_element(arr, sz, random_rank);
        if(blum != brute){
            printf("WA on test case %d\n", t+1);
            printf("Correct ans: %d\n", brute);
            printf("My ans: %d\n", blum);

            for(int i = 0; i<sz; i++) printf("%d ", og_arr[i]);
            printf("\n%d\n\n", random_rank);
            // return 0;
        }
        printf("%d\n ",rth_element(arr,sz, random_rank));
    }
    return 0;
}