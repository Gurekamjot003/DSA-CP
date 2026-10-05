#include<stdio.h>
#include "../dynamic_array.c"
void swap(int* a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}

int get_face_value_at_pos(int n, int pos){
    return (n/pos)%10;
}

void sort(int*nums, int n){

    for(int pos = 1; pos<1<<30; pos*=10){
        vector* buckets[10];
        for(int i = 0; i<10; i++){
            buckets[i] = init_vector(0, 0);
        }
        
        for(int i = 0; i<n; i++){
            int face_val = get_face_value_at_pos(nums[i], pos);
            push_back(buckets[face_val], nums[i]);
        }

        int i = 0;
        for(int j = 0; j<10; j++){
            for(int k = 0; k<buckets[j]->size; k++){
                nums[i++] = buckets[j]->arr[k];
            }
        }
        for(int j = 0; j<10; j++) free_vector(buckets[j]);
    }
}

int main(){
    int arr[] = {10, 20, 54, 21, 2, 101};
    int n = 6;
    
    sort(arr, n);
    printf("\n");
    for(int i = 0; i<n;  i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}