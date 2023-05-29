# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""

NWK = [[0, 16, 12, 21, 0, 0, 0],
       [16, 0, 0, 17, 20, 0, 0],
       [12, 0, 0, 28, 0, 31, 0],
       [21, 17, 28, 0, 18, 19, 23],
       [0, 20, 0, 18, 0, 0, 11],
       [0, 0, 31, 19, 0, 0, 27],
       [0, 0, 0, 23, 11, 27]]

def printNetwork(network):
    for i in range(len(network)):
        for j in range(len(network[i])):
            print(network[i][j], end=' ')
        print()
        
printNetwork(NWK)