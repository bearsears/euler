# -*- coding: utf-8 -*-
"""
Created on Sun Apr 28 18:50:20 2019

@author: ssuh
"""

# Parent class
class Dog:

    # Class attribute
    species = 'mammal'

    # Initializer / Instance attributes
    def __init__(self, name, age):
        self.name = name
        self.age = age

    # instance method
    def description(self):
        return "{} is {} years old".format(self.name, self.age)

    # instance method
    def speak(self, sound):
        return "{} says {}".format(self.name, sound)

# Child class (inherits from Dog class)
class RussellTerrier(Dog):
    def run(self, speed):
        return "{} runs {}".format(self.name, speed)

# Child class (inherits from Dog class)
class Bulldog(Dog):
    def run(self, speed):
        return "{} runs {}".format(self.name, speed)
    
# Parent class,
class Pet:
    def total(*args):
        length = 0
        for i in args:
            length += 1
        print('working?', length)
        if length == 1:
            print("I have {} dog.".format(length))
        elif length == 0:
            print("I have no dog.")
        else:
            print("I have {} dogs.".format(length))
        
        for i in args:
            print("{} is {}".format(i.name, i.age))
        return print("They are all {}s, of course".format(i.species))

Tom = Dog('Tom', 6)
Fletcher = Dog('Fletcher', 7)
Larry = Dog('Larry', 9)
Me = Pet
Me.total(Tom, Fletcher, Larry)

