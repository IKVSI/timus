#!/usr/bin/python3
import sys
N = int(input())
teams = []
players = {}
for i in range(N):
    # [team number, status, ]
    players[input()] = [None, 3]

M = int(input())
for i in range(M):
    log = input().split()
    if players[log[0]][1] < 2:
        break
    if log[1] == "HIT":
        hp = 1
        if log[4] == "HEAD":
            hp = 2
        players[log[2]][1] = max(0, players[log[2]][1] - hp)
    elif log[1] == "USES":
        players[log[0]][1] = 3
    elif log[1] == "REVIVE":
        if players[log[2]][1] != 1:
            break
        players[log[2]][1] = 2
        if players[log[0]][0] is None and players[log[2]][0] is None:
            t = set([log[0], log[2]])
            players[log[0]][0] = len(teams)
            players[log[2]][0] = len(teams)
            teams.append(t)
        elif players[log[0]][0] is None:
            teams[players[log[2]][0]].add(log[0])
            players[log[0]][0] = players[log[2]][0]
            if len(teams[players[log[2]][0]]) > 4:
                break
        elif players[log[2]][0] is None:
            teams[players[log[0]][0]].add(log[2])
            players[log[2]][0] = players[log[0]][0]
            if len(teams[players[log[2]][0]]) > 4:
                break
        elif players[log[2]][0] != players[log[0]][0]:
            if (len(teams[players[log[2]][0]]) + len(teams[players[log[0]][0]])) > 4:
                break
            teams[players[log[0]][0]] |= teams[players[log[2]][0]]
            t, teams[players[log[2]][0]] = teams[players[log[2]][0]], set()
            for i in t:
                teams[players[log[0]][0]].add(i)
                players[i][0] = players[log[0]][0]
else:
    noteams = [i for i in players if players[i][0] is None]
    j = 0
    teams2 = [i for i in range(len(teams)) if len(teams[i]) == 2]
    for i in range(0, len(teams2)&1022, 2):
        teams[teams2[i]] |= teams[teams2[i+1]]
        teams[teams2[i+1]] = set()
    for i in teams:
        if i:
            while len(i) < 4:
                if j >= len(noteams):
                    print("FAKE")
                    sys.exit()
                i.add(noteams[j])
                j += 1
    print("CORRECT")
    for i in teams:
        if i:
            print(' '.join(i))
    for k in range(j, len(noteams), 4):
        print(noteams[k], noteams[k+1], noteams[k+2], noteams[k+3])
    sys.exit()
print("FAKE")