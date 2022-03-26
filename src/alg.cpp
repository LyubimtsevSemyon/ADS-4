// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
int count = 0;
for (int i = 0; i < len; i++) {
for (int j = i + 1; j < len; j++) {
if (arr[i] + arr[j] == value)
count += 1;
}
}
return count;
}
int countPairs2(int *arr, int len, int value) {
int count = 0, left = 0, right = len - 1;
while (left < right - 1) {//до схождения границ
int middle = (left + right) / 2;//средний элемент
if (arr[middle] <= value)//сужение массива
left = middle;
else
right = middle;
}
len = right - 1;
for (int i = len; i >=0; i--) {
for (int j = 0; j < i; j++) {
if (arr[i] + arr[j] == value)
count++;
if (arr[i] + arr[j] > value)
break;
}
}
return count;
}
int countPairs3(int *arr, int len, int value) {
int sym = 0;
for (int i = 0; i < len - 1; i++) {
int left = i, right = len;
while (left < right - 1) {
int mid = (left + right) / 2;
if (arr[i] + arr[mid] == value) {
sym++;
int k = mid + 1;
while (arr[i] + arr[k] == value && k < right) {
sym++;
k++;
}
k = mid - 1;
while (arr[i] + arr[k] == value && k > left) {
sym++;
k--;
}
break;
}
if (arr[i] + arr[mid] > value)
right = mid;
else
left = mid;
}
}
return sym;
}
