{
 "cells": [
  {
   "cell_type": "code",
   "execution_count": null,
   "id": "3812ac38",
   "metadata": {},
   "outputs": [],
   "source": [
    "h, w = map(int, input().split())\n",
    "a=[]\n",
    "for i in range(h+1):\n",
    "    a.append([])\n",
    "    for j in range(w+1):\n",
    "        a[i].append(0)\n",
    "\n",
    "n = int(input())\n",
    "\n",
    "for i in range(n):\n",
    "    l, d, x, y = map(int, input().split())\n",
    "    if d==0:\n",
    "        for j in range(y, l+y):\n",
    "            a[x][j]=1\n",
    "    else:\n",
    "        for j in range(x, l+x):\n",
    "            a[j][y]=1\n",
    "\n",
    "for i in range(1, h+1):\n",
    "    for j in range(1, w+1):\n",
    "        print(a[i][j], end=' ')\n",
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
