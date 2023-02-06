{
 "cells": [
  {
   "cell_type": "code",
   "execution_count": null,
   "id": "d2a25d56",
   "metadata": {},
   "outputs": [],
   "source": [
    "arr=[]\n",
    "for i in range(10):\n",
    "    arr.append([])\n",
    "    for j in range(10):\n",
    "        arr[i].append(0)\n",
    "        \n",
    "for i in range(10):\n",
    "    arr[i] = list(map(int,input().split()))\n",
    "        \n",
    "x = y = 1        \n",
    "if arr[1][1]!=2:\n",
    "    for i in range(20):\n",
    "        arr[1][1] = 9\n",
    "        if arr[x][y+1]==0:\n",
    "            y += 1\n",
    "            arr[x][y] = 9\n",
    "            continue\n",
    "        elif (arr[x][y+1]==1) and (arr[x+1][y]==0):\n",
    "            x += 1\n",
    "            arr[x][y] = 9\n",
    "            continue\n",
    "        elif (arr[x+1][y]==1) and (arr[x][y+1]==1) or (arr[x+1][y]==2):\n",
    "            arr[x+1][y] = 9\n",
    "            break\n",
    "        elif arr[x][y+1]==2:\n",
    "            arr[x][y+1] = 9\n",
    "            break\n",
    "else:\n",
    "    arr[1][1] = 9\n",
    "arr[9][8] = 1\n",
    "    \n",
    "    \n",
    "for i in range(10):\n",
    "    for j in range(10):\n",
    "        print(arr[i][j], end=' ')\n",
    "    print()"
   ]
  }
 ],
 "metadata": {
  "kernelspec": {
   "display_name": "Python 3 (ipykernel)",
   "language": "python",
   "name": "python3"
  },
  "language_info": {
   "codemirror_mode": {
    "name": "ipython",
    "version": 3
   },
   "file_extension": ".py",
   "mimetype": "text/x-python",
   "name": "python",
   "nbconvert_exporter": "python",
   "pygments_lexer": "ipython3",
   "version": "3.9.13"
  }
 },
 "nbformat": 4,
 "nbformat_minor": 5
}
