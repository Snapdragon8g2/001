#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r) {
for (int i = 0; i < m - l + 1; i++)
L[i] = arr[l + i];
for (int j = 0; j < r - m; j++)
R[j] = arr[m + 1 + j];

i = 0;
j = 0;
k = l;
while (i < m - l + 1 && j < r - m) {
if (L[i] <= R[j]) {
arr[k] = L[i];
i++;
} else {
arr[k] = R[j];
j++;
}
k++;
}

while (i < m - l + 1) {
arr[k] = L[i];
i++;
k++;
}

while (j < r - m) {
arr[k] = R[j];
j++;
k++;
}
}

void mergeSort(int arr[], int l, int r) {
if (l < r) {
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
}
}

int main() {
int n;
printf("Enter the number of elements: ");
scanf("%d", &n);
int arr[n];
srand(time(NULL));
for (int i = 0; i < n; i++) {
arr[i] = rand() % 10000;
}
clock_t start, end;
double cpu_time_used;
start = clock();
mergeSort(arr, 0, n - 1);
end = clock();
cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
printf("Time taken to sort %d elements: %f seconds\n", n, cpu_time_used);
return 0;
}