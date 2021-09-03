import random

arr = [2,8,7,1,3,5,6,4]

def Partition(arr,low, high):
    
    PI = arr[high]
    pointer = low - 1

    for j in range(low,high):
        if arr[j] <= PI:
            pointer = pointer + 1
            arr[pointer],arr[j] = arr[j],arr[pointer]

    arr[pointer+1],arr[high] = arr[high],arr[pointer+1]
    
    return pointer+1


def RandomizedPartition(arr,low, high):
    
    i = random.randint(low,high)
    #print(i)
    arr[i],arr[high] = arr[high],arr[i]
    x = Partition(arr,low,high)
    return x


def QuickSort(arr,low,high):
   
    if low < high :
        
        pivot = RandomizedPartition(arr,low,high)
        QuickSort(arr,low,pivot-1)
        QuickSort(arr,pivot+1,high)


size = len(arr)

QuickSort(arr,0,size-1)
RandomizedPartition(arr,0,size-1)

print(arr)
