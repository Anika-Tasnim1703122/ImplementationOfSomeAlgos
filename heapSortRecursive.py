arr = [40,80,35,90,45,50,70]
print("Initial Array : ",arr)

def Heapify(arr, n, i):
    
    largest = i
    left = 2*i + 1
    right = 2*i + 2

    if left < n and arr[largest] < arr[left]:
        
        largest = left

    if right < n and arr[largest] < arr[right]:

        largest = right

    if i != largest :

        arr[i], arr[largest] = arr[largest], arr[i]
        Heapify(arr,n,largest)


def HeapSort(arr):

    n = len(arr)

    #Build Heap

    for i in range(n//2,-1,-1):
        Heapify(arr,n,i)
    
    #Sorting

    for i in range(n-1,-1,-1):
        arr[i],arr[0] = arr[0],arr[i]
        Heapify(arr,i,0)


HeapSort(arr)

print("Final Array : ",arr)