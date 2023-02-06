{
 "cells": [
  {
   "cell_type": "code",
   "execution_count": null,
   "id": "0d7921c0",
   "metadata": {},
   "outputs": [],
   "source": [
    "d=[]\n",
    "for i in range(20):\n",
    "    d.append([])\n",
    "    for j in range(20):\n",
    "        d[i].append(0)\n",
    "n = int(input())\n",
    "for i in range(n):\n",
    "    x, y = input().split()\n",
    "    d[int(x)][int(y)]=1\n",
    "for i in range(1, 20):\n",
    "    for j in range(1, 20):\n",
    "        print(d[i][j], end=' ')\n",
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
