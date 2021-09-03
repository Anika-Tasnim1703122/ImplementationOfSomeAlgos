import math

arr = [40,80,35,90,45,50,70]
print("Initial Array : ",arr)

a = list()

def Insert(arr, n):
    
    i = n
    item = arr[n]
    while i > 0 and arr[math.floor(i/2)] > item :
        arr[i] = arr[math.floor(i/2)]
        i = math.floor(i/2)
    arr[i] = item


def Adjust(arr, i, n):

    j = 2*i
    item = arr[i]

    while j <= n:
        if j < n and (arr[j] > arr[j+1]):
            j = j + 1
        if item <= arr[j]:
            break
        arr[math.floor(j/2)] = arr[j]
        j = 2 * j

    arr[math.floor(j/2)] = item


def DelMax(arr,n):

    if n < 0 :
        print("Empty Heap!!!")

    x = arr[0]
    arr[0] = arr[n]
    Adjust(arr, 0, n-1)
    
    return x


def HeapSort(arr):
    for i in range (len(arr)):
        Insert(arr,i)

    for j in range(len(arr)-1,-1,-1):
        #print(j)
        x = DelMax(arr, j)
        a.append(x)
    return a

print("Sorted Array : ",HeapSort(arr))