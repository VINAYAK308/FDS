# Exp2. Write a Python program to store marks scored in subject “Fundamental of 
# Data Structure” by N students in the class. Write functions to compute following: 
# a) The average score of class 
# b) Highest score and lowest score of class 
# c) Count of students who were absent for the test
# d) Display mark with highest frequency
 
 
 
 
def accept_marks(a):
    n=int(input("Enter the strength of class: "))
    for i in range(n):
       while True: 
          x=input("Marks of student %d:"%(i+1))
          if(x=="AB"):
             x=-1
             break;
          x=int(x)
          if(x>=0 and x<=30):
             break;
          else:
             print("Enter the valid number!")
       a.append(x)
def display_marks(a):
    n=len(a)
    for i in range(n):
         if(a[i]==-1):
            print("Student %d is absent"%(i+1))
         elif(a[i]>=0 and a[i]<=30):
            print("Marks of Student is :%d "%a[i])
def average_score(a):
    n=len(a)
    count =0
    sum=0
    for i in range(n):
        if(a[i]>=0 and a[i]<=30):
            sum=sum+a[i]
            count=count+1
    avg=sum/count
    print("Average of %d Students who are present is: %f"%(count,avg))    
def max_min(a):
    max=-1
    min=31
    for i in range(len(a)):
        if(a[i]>max):
           max=a[i]
           index=i
        if(a[i]<min and a[i]!=-1):
           min=a[i]
    print("Maximum number is %d"%max)
    print("Minimum number is %d"%min)
def absent(a):
    s=0;
    for i in range(len(a)):
         if(a[i]==-1):
            s=s+1;
    print("Total absent students are: ",s)

def frequency(a):
   i=0
   x=0
   n=len(a)
   while(i<n):
      count=0
      for j in range(n):
         if(a[i]==a[j] and a[i]!=-1):
            count=count+1
      if(count>x):
         x=count
         index=i
      i=i+1
   print("The maximum frequency is of %d" %a[index])                                
def main():
    
    fds=[]

    while True:
        print("\nOptions:")
        print("\t1 : Accept the Information")
        print("\t2 : The average score of class ")
        print("\t3 : Highest score and lowest score of class ")
        print("\t4 : Count of students who were absent for the test")
        print("\t5 : Display mark with highest frequency")
        print("\t6 : Exit")

        ch = int(input("Enter your choice: "))

        if ch == 6:
            print("End of Program")
            break
        elif ch == 1:
              accept_marks(fds)
              display_marks(fds)
           
        elif ch == 2:
            average_score(fds)
            
        elif ch == 3:
            max_min(fds)
           
        elif ch == 4:
             absent(fds)
           
        elif ch == 5:
            frequency(fds)
        else:
            print("Invalid choice! Please try again.")

    
main()



# (base) trushantramdasjadhav@Trushants-MacBook-Air FDS % python -u "/Users/trushantramdasja
# dhav/Desktop/TicketingSystem/FDS/Exp2.py"

# Options:
#         1 : Accept the Information
#         2 : The average score of class 
#         3 : Highest score and lowest score of class 
#         4 : Count of students who were absent for the test
#         5 : Display mark with highest frequency
#         6 : Exit
# Enter your choice: 1
# Enter the strength of class: 3
# Marks of student 1:28
# Marks of student 2:24
# Marks of student 3:26
# Marks of Student is :28 
# Marks of Student is :24 
# Marks of Student is :26 

# Options:
#         1 : Accept the Information
#         2 : The average score of class 
#         3 : Highest score and lowest score of class 
#         4 : Count of students who were absent for the test
#         5 : Display mark with highest frequency
#         6 : Exit
# Enter your choice: 2
# Average of 3 Students who are present is: 26.000000

# Options:
#         1 : Accept the Information
#         2 : The average score of class 
#         3 : Highest score and lowest score of class 
#         4 : Count of students who were absent for the test
#         5 : Display mark with highest frequency
#         6 : Exit
# Enter your choice: 3
# Maximum number is 28
# Minimum number is 24

# Options:
#         1 : Accept the Information
#         2 : The average score of class 
#         3 : Highest score and lowest score of class 
#         4 : Count of students who were absent for the test
#         5 : Display mark with highest frequency
#         6 : Exit
# Enter your choice: 4
# Total absent students are:  0

# Options:
#         1 : Accept the Information
#         2 : The average score of class 
#         3 : Highest score and lowest score of class 
#         4 : Count of students who were absent for the test
#         5 : Display mark with highest frequency
#         6 : Exit
# Enter your choice: 5
# The maximum frequency is of 28

# Options:
#         1 : Accept the Information
#         2 : The average score of class 
#         3 : Highest score and lowest score of class 
#         4 : Count of students who were absent for the test
#         5 : Display mark with highest frequency
#         6 : Exit
# Enter your choice: 6
# End of Program
# (base) trushantramdasjadhav@Trushants-MacBook-Air FDS % 