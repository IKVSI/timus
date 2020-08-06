from heapq import heapify, heappush, heappop
S = input()
# (cell0, cell1, cell2, cell3, cursor, parent)
i = ord(S[0])
V = [
    (i, 0, 0, 0, 0, None),
    (0, i, 0, 0, 1, None),
]
HEAP = []
heapify(HEAP)
# heap (steps in brainfuck, distance to end of string, number of V)
heappush(HEAP, (i, len(S)-1, 0))
heappush(HEAP, (i, len(S)-1, 1))
curent = heappop(HEAP)
while curent[1]:
    print(curent)
    v = V[curent[2]]
    i = ord(S[len(S) - curent[1]])
    cursor = v[4]

    v0 = (i, v[1], v[2], v[3], 0, v)
    heappush(HEAP, (curent[0]+abs(cursor-0)+abs(i-v[0])+1, curent[1]-1, len(V)))
    V.append(v0)

    v1 = (v[0], i, v[2], v[3], 1, v)
    heappush(HEAP, (curent[0]+abs(cursor-1)+abs(i-v[1])+1, curent[1]-1, len(V)))
    V.append(v1)

    v2 = (v[0], v[1], i, v[3], 2, v)
    heappush(HEAP, (curent[0]+abs(cursor-2)+abs(i-v[2])+1, curent[1]-1, len(V)))
    V.append(v2)

    v3 = (v[0], v[1], v[2], i, 3, v)
    heappush(HEAP, (curent[0]+abs(cursor-3)+abs(i-v[3])+1, curent[1]-1, len(V)))
    V.append(v3)

    curent = heappop(HEAP)

print(curent)
curent = V[curent[2]]
RS = []
while not (curent[5] is None):
    parent = curent[5]
    RS.append('.')
    dcell = curent[curent[4]] - parent[curent[4]]
    RS.append('+' * dcell if dcell > 0 else '-' * abs(dcell))
    dcur = curent[4] - parent[4]
    RS.append('>' * dcur if dcur > 0 else '<' * abs(dcur))
    curent = parent
RS.append('.')
RS.append('+' * max(curent[0], curent[1], curent[2], curent[3]))
RS.reverse()
print(''.join(RS))