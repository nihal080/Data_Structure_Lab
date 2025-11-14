class Student:
    def __init__(self,name,age,marks):
        self.name=name
        self.age=age
        self.marks=marks
    def grade(self):
        if self.marks>=90:
            print(self.name,"with age ",self.age,"Got an A grade")
        elif self.marks>=75:
           print(self.name,"with age ",self.age,"Got an B grade")
        else:
           print(self.name,"with age ",self.age,"Got an C grade")
S1=Student("Nihal",21,92)
S2=Student("Arun",22,74)
S3=Student("Afthab",19,88)

S1.grade()
S2.grade()
S3.grade()
