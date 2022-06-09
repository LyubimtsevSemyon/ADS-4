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
  int count = 0;
  for (int i = 0; i < len; i++)
    for (int j = len - 1; j > i; j--)
      if (arr[i] + arr[j] == value)
      count++;
  return count;
}
int binar(int *arr, int l, int r, int x) {
  int lft = l, rht = r, mid = 0; bool f = 0;
  while (lft <= rht) {
    mid = (lft + rht) / 2;
    if (arr[mid] == x) {
      return binar(arr, l, mid - 1, x) + binar(arr, mid + 1, r, x) + 1;
    }
    if (x < arr[mid])
      rht = mid - 1;
    else
      lft = mid + 1;
  }
  return 0;
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
