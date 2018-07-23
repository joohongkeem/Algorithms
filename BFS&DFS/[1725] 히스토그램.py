arr=[]
MAX=[]

N = int(input())
i=0
while(i<N):
    temp=int(input())
    arr.append(temp)
    MAX.append(0)
    i+=1



i=0
while i<N:
    if(arr[i]==0):
        i+=1
        continue
    MAX[i]+=arr[i]
    temp = arr[i]
    j=i+1
    while True:
        if (j>=N or arr[i]>arr[j] ) :   # j>=N을 반드시 먼저 써야한다!!!(index error 방지)
            break
        MAX[i]+=temp
        j+=1
    j=i-1
    while True:
        if(j<0 or arr[i]>arr[j]):
            break
        MAX[i]+=temp
        j-=1
    i+=1


i=1
ANS=0
while(i<N):
    if(ANS<MAX[i]):
        ANS = MAX[i]
    i+=1

print(ANS)
