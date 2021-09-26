from hello import hello
class Main(object):
    
    def __init__(self):
        self.array = [hello]
    
    def insert(self,object,i):
        self.array[i].name = object.name
        self.array[i].no = object.no
    
    def printHello(self,i):
        print("name : ",self.array[i].name)
        print("Num :",self.array[i].no)
        

hell = [Main()]  


for i in range(5):
    hell.insert(hello("rahul",18),i)
    hell.printHello(i)        
        