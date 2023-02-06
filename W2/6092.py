{
 "cells": [
  {
   "cell_type": "code",
   "execution_count": null,
   "id": "2ac907d4",
   "metadata": {},
   "outputs": [],
   "source": [
    "n = int(input())\n",
    "a = input().split()\n",
    "\n",
    "for i in range(n):\n",
    "    a[i] = int(a[i])\n",
    "d=[]\n",
    "for i in range(24):\n",
    "    d.append(0)\n",
    "for i in range(n):\n",
    "    d[a[i]]+=1\n",
    "    \n",
    "for i in range(1, 24):\n",
    "    print(d[i], end=' ')"
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
