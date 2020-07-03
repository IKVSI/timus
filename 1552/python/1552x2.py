from heapq import heappush, heappop

S = input()
i = ord(S[0])

# KEY=(cell0, cell1, cell2, cell3/cell-1, cell3/cell-1 flag, cursor, pointer in string) : parent, number of V ,steps
zero = (i, 0, 0, 0, 0, 0, 1)
D = { zero: (None, 0, i) }
V = [zero]

HEAP = []
# heap (steps in brainfuck, distance to end of string, number of V)
heappush(HEAP, (i, len(S)-zero[6], 0))
curent = heappop(HEAP)
while curent[1]:
    steps, dstr, v = curent
    v = V[v]
    cursor = v[5]
    i = ord(S[v[6]])
    v0, v1, v2, v3, v_1 = None, None, None, None, None
    v0 = (i, v[1], v[2], v[3], v[4], 0, v[6]+1)
    v0steps = (steps + abs(cursor - 0) + abs(i - v[0]) + 1)
    if not (v0 in D):
        D[v0] = (v, len(V), v0steps)
        heappush(HEAP, (
            v0steps,
            dstr - 1,
            len(V)
            ))
        V.append(v0)
    else:
        if D[v0][2] > v0steps:
            D[v0] = (v, D[v0][1], v0steps)
            heappush(HEAP, (
                v0steps,
                dstr - 1,
                D[v0][1]
            ))

    v1 = (v[0], i, v[2], v[3], v[4], 1, v[6]+1)
    v1steps = (steps + abs(cursor - 1) + abs(i - v[1]) + 1)
    if not (v1 in D):
        D[v1] = (v, len(V), v1steps)
        heappush(HEAP, (
            v1steps,
            dstr - 1,
            len(V)
            ))
        V.append(v1)
    else:
        if D[v1][2] > v1steps:
            D[v1] = (v, D[v1][1], v1steps)
            heappush(HEAP, (
                v1steps,
                dstr - 1,
                D[v1][1]
            ))

    v2 = (v[0], v[1], i, v[3], v[4], 2, v[6]+1)
    v2steps = (steps + abs(cursor - 2) + abs(i - v[2]) + 1)
    if not (v2 in D):
        D[v2] = (v, len(V), v2steps)
        heappush(HEAP, (
            v2steps,
            dstr - 1,
            len(V)
            ))
        V.append(v2)
    else:
        if D[v2][2] > v2steps:
            D[v2] = (v, D[v2][1], v2steps)
            heappush(HEAP, (
                v2steps,
                dstr - 1,
                D[v2][1]
            ))
    
    if v[4]:
        v3 = (v[0], v[1], v[2], i, v[4], v[4], v[6]+1)
        v3steps = (steps + abs(cursor - v[4]) + abs(i - v[3]) + 1)
        if not (v3 in D):
            D[v3] = (v, len(V), v3steps)
            heappush(HEAP, (
                v3steps,
                dstr - 1,
                len(V)
                ))
            V.append(v3)
        else:
            if D[v3][2] > v3steps:
                D[v3] = (v, D[v3][1], v3steps)
                heappush(HEAP, (
                    v3steps,
                    dstr - 1,
                    D[v3][1]
                ))
    else:
        v3 = (v[0], v[1], v[2], i, 3, 3, v[6]+1)
        v3steps = (steps + abs(cursor - 3) + abs(i - v[3]) + 1)
        if not (v3 in D):
            D[v3] = (v, len(V), v3steps)
            heappush(HEAP, (
                v3steps,
                dstr - 1,
                len(V)
                ))
            V.append(v3)
        else:
            if D[v3][2] > v3steps:
                D[v3] = (v, D[v3][1], v3steps)
                heappush(HEAP, (
                    v3steps,
                    dstr - 1,
                    D[v3][1]
                ))

        v_1 = (v[0], v[1], v[2], i, -1, -1, v[6]+1)
        v_1steps = (steps + abs(cursor + 1) + abs(i - v[3]) + 1)
        if not (v_1 in D):
            D[v_1] = (v, len(V), v_1steps)
            heappush(HEAP, (
                v_1steps,
                dstr - 1,
                len(V)
                ))
            V.append(v_1)
        else:
            if D[v_1][2] > v_1steps:
                D[v_1] = (v, D[v_1][1], v_1steps)
                heappush(HEAP, (
                    v_1steps,
                    dstr - 1,
                    D[v_1][1]
                ))
    curent = heappop(HEAP)

curent = V[curent[2]]
RS = []
while not (D[curent][0] is None):
    parent = D[curent][0]
    RS.append('.')
    cc = curent[5]
    if cc == -1:
        cc = 3
    dcell = curent[cc] - parent[cc]
    RS.append('+' * dcell if dcell > 0 else '-' * abs(dcell))
    dcur = curent[5] - parent[5]
    RS.append('>' * dcur if dcur > 0 else '<' * abs(dcur))
    curent = parent
RS.append('.')
RS.append('+' * max(curent[0], curent[1], curent[2], curent[3]))
RS.reverse()
print(''.join(RS))