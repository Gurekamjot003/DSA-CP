#include<stdio.h>
#include<stdlib.h>

int k = 5;
int MAXN = 5; // will check this

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

int min(int a, int b){
    if(a<b) return a;
    return b;
}

int rth_element_brute(int* arr, int sz, int r){
    int copy_arr[sz];
    for(int i = 0; i<sz; i++) copy_arr[i] = arr[i];
    insertion_sort(copy_arr, 0, sz-1);
    return copy_arr[r-1];
}

int partition(int* arr, int target, int size){
    int left = 0, right = size-1;
    
    while(left<=right){
        while(left<=right && arr[left]<=target) left++;
        while(left<=right && arr[right]>target) right--;
        if(left<=right) swap(&arr[left++], &arr[right--]);
        
    }
    for(int i = size-1; i>=0; i--){
        if(arr[i] == target){
            swap(&arr[right], &arr[i]);
            return right;
        }
    }
    return -1;
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
        int end = min(i+4, sz-1);
        insertion_sort(arr, i, end);
        medians_arr[i/5] = arr[(end-i)/2 + i];
    }
    int median_of_medians = rth_element(medians_arr, medians_sz, medians_sz/2);
    
    int idx = partition(arr, median_of_medians, sz);    

    if(r == idx+1) return median_of_medians;
    if(r <= idx){
        return rth_element(&arr[0], idx, r);
    }
    return rth_element(&arr[idx+1], sz-idx-1, r-idx-1);
}



int main(){
    int sz = 1000;
    int arr[sz], og_arr[sz];
    srand(0);
    int t = 100;
    while(t--){

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
                rth_element_brute(arr, sz, random_rank);
                rth_element(arr, sz, random_rank);
                for(int i = 0; i<sz; i++) printf("%d ", og_arr[i]);
                printf("\n%d\n\n", random_rank);
                return 0;
            }
            // printf("%d\n ",rth_element(arr,sz, random_rank));
            
        }
        printf("Testcase %d passed\n" , t+1);
    }
    printf("All testcases passed");
    return 0;
}