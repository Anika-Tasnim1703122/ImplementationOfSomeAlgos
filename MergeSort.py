import random

randomlist = random.sample(range(1, 100), 10)

arr = [54, 26, 93, 17, 77, 31, 44, 55, 20, 88]
a = [1,3,5,2,4,6]

def MergeSort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2
        left = arr[:mid]
        right = arr[mid:]
        print('left : ',left)
        print('right : ',right)
        
        
        MergeSort(left)
        MergeSort(right)

        # left and right array traversal var i and j

        i = 0
        j = 0

        # main array manipulating var k

        k = 0

        while i < len(left) and j < len(right):
            if left[i] < right[j]:
                arr[k] = left[i]
                i = i + 1
            else:
                arr[k] = right[j]
                j = j + 1
            k = k + 1
        while i < len(left):
            arr[k] = left[i]
            i = i + 1
            k = k + 1
        while j < len(right):
            arr[k] = right[j]
            j = j + 1
            k = k + 1


MergeSort(a)
print(a)
