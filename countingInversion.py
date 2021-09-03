count = 0

def inversionInLeftAndRight(arr, start, end):


    global count
    leftcount = 0
    rightcount = 0
    di = {}    
    tup = tuple()
    left = []
    right = []
    count = 0
    mid = (start+end)//2
    if start == end:
        tup = (count,arr[start:start+1])
        return tup
    elif start+1 == end:
        if arr[start] > arr[end]:
            count = count+1
        tup = (count,arr[start:end+1])
        print(count)
        #print('{}-{}'.format(arr[start],arr[end]))
        #print(sorted(arr[start:end+1]))
        return(tup)
    
    else:
        x = inversionInLeftAndRight(arr,start,mid)
        if x != None:
            leftcount = leftcount + x[0]
            left = x[1]
        #print('leftCount : ',count)
        #print('leftArr : ',leftArr)
        y = inversionInLeftAndRight(arr,mid+1,end)
        if y != None:
            rightcount = rightcount + y[0]
            right = y[1]
   
        #print('rightCount : ',count)
        #print('rightArr : ',rightArr)
    #val = splitInversion(sorted(leftArr),sorted(rightArr))
    #global count
    #arr = list()
    k = 0
    i = 0
    j = 0
    trackB = 0
    count = 0
    
    while i < len(left) and j < len(right):
            if left[i] < right[j]:
                arr[k] = left[i]
                i = i + 1
                count = count+1
                print('lefC : ',count)
            else:
                arr[k] = right[j]
                j = j + 1
                count += count - trackB
            k = k + 1
    
    while i < len(left):
            arr[k] = left[i]
            i = i + 1
            k = k + 1
    while j < len(right):
            arr[k] = right[j]
            j = j + 1
            k = k + 1
    print(arr)
'''def splitInversion(left, right):
    global count
    arr = list()
    k = 0
    i = 0
    j = 0
    trackB = 0
    count = 0
    
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
            k = k + 1'''


a = [5,3,1,2,4,6,0,-1,2,7]
#print(len(a))
print(inversionInLeftAndRight(a,0,len(a)-1))

