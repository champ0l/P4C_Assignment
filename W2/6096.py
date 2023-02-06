{
 "cells": [
  {
   "cell_type": "code",
   "execution_count": null,
   "id": "b697e39c",
   "metadata": {},
   "outputs": [],
   "source": [
    "d = [list(map(int, input().split()))for _ in range(19)]\n",
    "\n",
    "n = int(input())\n",
    "for i in range(n) :\n",
    "  x, y = map(int, input().split())\n",
    "  for j in range(19) :\n",
    "    if d[j][int(y)-1]==0 :\n",
    "      d[j][int(y)-1]=1\n",
    "    else :\n",
    "      d[j][int(y)-1]=0\n",
    "\n",
    "    if d[int(x)-1][j]==0 :\n",
    "      d[int(x)-1][j]=1\n",
    "    else :\n",
    "      d[int(x)-1][j]=0\n",
    "\n",
    "for i in range(19):\n",
    "    for j in range(19):\n",
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
