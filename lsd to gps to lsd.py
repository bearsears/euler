# -*- coding: utf-8 -*-
"""
Created on Fri Mar 29 13:14:35 2019

@author: ssuh
"""
import math

def lsd_to_gps(lsd, sec, twp, rge, m):
    lat_factor = 0.087365
    
    #for lng factor first two twp is bundled, and subsequent for are bundled.
    #below equation is found after line fitting the data of lsds in maps as well
    #as measuring thousands of wells
    
    lng_factor = 0.0055119590 * math.exp(0.0077395262 * ((twp + 2) / 4 + 1))
    
    latitude = (twp - 1) * lat_factor + \
                math.floor((sec - 1) / 6) / 6 * lat_factor + \
                (math.floor((lsd - 1) / 4) / 24 + 0.5) / 24 * lat_factor + 49
    print(math.floor((sec - 1) / 6) / 6)
    vsection = [[1, 12, 13, 24, 25, 36], [2, 11, 14, 23, 26, 35],
                [3, 10, 15, 22, 27, 34], [4, 9, 16, 21, 28, 33],
                [5, 8, 17, 20, 29, 32], [6, 7, 18, 19, 30, 31]] 
    
    vlsd = [[1, 8, 9, 16], [2, 7, 10, 15], [3, 6, 11, 14], [4, 5, 12, 13]]

    meridian = [0.0, -97.45777777, -102.0, -106.0, -110.0]
    isec, ilsd = 0, 0
    for i in range(0, len(vsection)):
        for j in range(0, len(vsection[i])):
            if vsection[i][j] == sec:
                isec = i
                break
        if vsection[i][j] == sec:
            break
        
    for i in range(0, len(vlsd)):
        for j in range(0, len(vlsd[i])):
            if vlsd[i][j] == lsd:
                ilsd = i
                break
        if vlsd[i][j] == lsd:
            break
    print(meridian[m])        
    longitude = meridian[m] - (rge - 1) * 24 * lng_factor - \
                isec * 4 * lng_factor - (ilsd + 0.5) * lng_factor
    
    print(latitude, longitude)

#lsd, sec, twp, rge, m = 1, 2, 1, 10, 2
    #12	24	1	7	2
    #11	11	47	27	3

lsd_to_gps(7, 29, 18, 16, 2)
