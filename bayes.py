# -*- coding: utf-8 -*-
"""
Created on Tue Mar  5 20:39:56 2019

@author: ssuh
"""

from thinkbayes2 import Pmf
from thinkbayes2 import Suite

pmf = Pmf()
"""
for x in [1, 2, 3, 4, 5, 6]:
    pmf.Set(x, 1/6.00)
"""
"""
pmf.Set('Bowl 1', 0.5)
pmf.Set('Bowl 2', 0.5)
pmf.Mult('Bowl 1', 0.75)
pmf.Mult('Bowl 2', 0.5)
pmf.Normalize()
print(pmf.Prob('Bowl 1'))
"""
#2.3
class Cookie(Pmf):
    
    def __init__(self, hypos):
        Pmf.__init__(self)
        for hypo in hypos:
            self.Set(hypo, 1)
        self.Normalize()
    def Update(self, data):
        for hypo in self.Values():
            like = self.Likelihood(data, hypo)
            self.Mult(hypo, like)
        self.Normalize()
    mixes = { 
            'Bowl 1': dict(vanilla=0.75, chocolate=0.25),
            'Bowl 2': dict(vanilla=0.5, chocolate=0.5),
            }
    def Likelihood(self, data, hypo):
        mix = self.mixes[hypo]
        like = mix[data]
        return like

class Monty(Suite):
    def __init__(self, hypos):
        Pmf.__init__(self)
        for hypo in hypos:
            self.Set(hypo, 1)
        self.Normalize()
    def Update(self, data):
        for hypo in self.Values():
            like = self.Likelihood(data, hypo)
            self.Mult(hypo, like)
        self.Normalize
    def Likelihood(self, data, hypo):
        if hypo == data:
            return 0
        elif hypo == 'A':
            return 0.5
        else:
            return 1

class M_and_M(Suite):
  
    mix94 = dict(brown=30, yellow=20, red=20, green=10, orange=10, tan=10)
    mix96 = dict(blue=24, green=20, orange=16,  yellow=14, red=13, brown=13)
    
    hypoA = dict(bag1=mix94, bag2=mix96)
    hypoB = dict(bag1=mix96, bag2=mix94)
    
    hypotheses = dict(A=hypoA, B=hypoB)

        
    def Likelihood(self, data, hypo):
        bag, color = data
        mix = self.hypotheses[hypo][bag]
        like = mix[color]
        return like
    
#class Dice(Suite):
#    def Likelihood(self, data, hypo):
#        if hypo < data:
#            return 0
#        else:
#            return 1.0/hypo
#suite = Dice([4,6,8,12,20])     
#suite.Update(6)
#for roll in [6,8,7,7,5,4]:
#    suite.Update(roll)
#print()

#the euro problem
class Euro(Suite):
    def Likelihood(self, data, hypo):
        x = hypo
        if data == 'H':
            return x / 100.0
        else:
            return 1 - x / 100.0
        
suite = Euro(range(0, 101))
dataset = 'H' * 140 + 'T' * 110
for data in dataset:
    #print(data, end=' ')
    suite.Update(data)

print(suite.MaximumLikelihood())
print(suite.Prob(50))  
print(suite.Mean(), ' -- mean')
print(suite.Median(), ' -- median')
print(suite.CredibleInterval(80), ' -- CI')
    


suite = Monty('ABC')
suite.Update('B')
suite.Print()  

print()

suite = M_and_M('AB')
suite.Update(('bag1', 'yellow'))
suite.Update(('bag2', 'green'))
suite.Print()


#hypos = ['Bowl 1', 'Bowl 2']
#pmf = Cookie(hypos)
#pmf.Update('vanilla')
#
#for hypo, prob in pmf.Items():
#    print(hypo, prob)