// Copyright 2021 NNTU-CS

int firstEnter(int *arr, int l, int r, int x) {
  if (l <= r) {
    int mid = l + (r - l) / 2;
    if ((x > arr[mid - 1] || mid == 0) && arr[mid] == x) {
      return mid;
    } else if (x > arr[mid]) {
      return firstEnter(arr, mid + 1, r, x);
    }
    return firstEnter(arr, l, mid - 1, x);
  }
  return -1;
}

int lastEnter(int *arr, int l, int r, int x, int size) {
  if (l <= r) {
    int mid = l + (r - l) / 2;
    if ((x < arr[mid + 1] || mid == size - 1) && arr[mid] == x) {
      return mid;
    } else if (x < arr[mid]) {
      return lastEnter(arr, l, mid - 1, x, size);
    }
    return lastEnter(arr, mid + 1, r, x, size);
  }
  return -1;
}

int cbinsearch(int *arr, int size, int value) {
  int first = firstEnter(arr, 0, size - 1, value);

  if (first == -1) {
    return 0;
  }

  int last = lastEnter(arr, 0, size - 1, value, size);
  return last - first + 1;
}
