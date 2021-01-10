学习笔记

## 选择排序

```
void Sort(vector<int> &numArray) {
    if (numArray.size() < 2) {
        return;
    }
    
    for (int i = 0; i < numArray.size() - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < numArray.size(); j++) {
            if (numArray[j] < numArray[minIndex]) {
                minIndex = j;
            }
        }
        
        int temp = numArray[i];
        numArray[i] = numArray[minIndex];
        numArray[minIndex] = temp;
    }
}
```

## 插入排序

```
void Sort(vector<int> &numArray) {
    if (numArray.size() < 2) {
        return;
    }
    
    int preIndex = 0;
    int currentNum = numArray[0];
    for (int i = 1; i < numArray.size(); i++) {
        preIndex = i - 1;
        currentNum = numArray[i];
        while ((preIndex >= 0) && (numArray[preIndex] > currentNum)) {
            numArray[preIndex + 1] = numArray[preIndex];
            preIndex--;
        }
        numArray[preIndex + 1] = currentNum;
    }
}
```

## 冒泡排序

```
void Sort(vector<int> &numArray) {
    if (numArray.size() < 2) {
        return;
    }
    
    for (int i = 0; i < numArray.size(); i++) {
        int currentIndex = 0;
        int currentNum = numArray[0];
        while ((currentIndex < numArray.size() - 1)) {
            currentNum = numArray[currentIndex];
            if (currentNum > numArray[currentIndex + 1]) {
                numArray[currentIndex] = numArray[currentIndex + 1];
                numArray[currentIndex + 1] = currentNum;
            }
            currentIndex++;
        }
    }
}
```