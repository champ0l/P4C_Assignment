#!/usr/bin/env python
# coding: utf-8

# In[ ]:


arr=[]
for i in range(10):
    arr.append([])
    for j in range(10):
        arr[i].append(0)
        
for i in range(10):
    arr[i] = list(map(int,input().split()))
        
x = y = 1        
if arr[1][1]!=2:
    for i in range(20):
        arr[1][1] = 9
        if arr[x][y+1]==0:
            y += 1
            arr[x][y] = 9
            continue
        elif (arr[x][y+1]==1) and (arr[x+1][y]==0):
            x += 1
            arr[x][y] = 9
            continue
        elif (arr[x+1][y]==1) and (arr[x][y+1]==1) or (arr[x+1][y]==2):
            arr[x+1][y] = 9
            break
        elif arr[x][y+1]==2:
            arr[x][y+1] = 9
            break
else:
    arr[1][1] = 9
arr[9][8] = 1
    
    
for i in range(10):
    for j in range(10):
        print(arr[i][j], end=' ')
    print()

