arr=[]

FRONT = 0
REAR = 0

N = int(input())

i=0
while(REAR<N):
    arr.append(REAR+1)
    REAR+=1




while REAR-FRONT != 1:
    FRONT+=1
    arr.append(arr[FRONT])
    REAR+=1
    FRONT+=1

print(arr[FRONT])



