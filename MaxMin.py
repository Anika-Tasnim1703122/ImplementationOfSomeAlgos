arr = [5,4,8,7,2,6,3,99,-1,1000]
maxT = 0
minT = 0
storeMax = 0
storeMin = 0
def MaxMin(low,high):
        if high == low:
            maxT = arr[high]
            minT = arr[high]
            return maxT, minT
        elif low == high - 1 :
            maxT = max(arr[low],arr[high])
            minT = min(arr[low],arr[high])
            return maxT,minT
        else :
            mid = (low+high) // 2
            a,b = MaxMin(low,mid)
            c,d = MaxMin(mid+1,high)

            return (max(a,c),min(b,d))
        
    
print(MaxMin(0,len(arr)-1))
