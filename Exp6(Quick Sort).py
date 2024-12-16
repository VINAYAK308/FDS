"""
       Group B - Assignment 6
Write a python program to store first year percentage of students in array.
Write function for sorting array of floating point numbers in ascending order
using quick sort and display top five scores..

"""


def accept_array(A): 
   n = int(input("Enter the total no. of student : "))
   for i in range(n):
      x = float(input("Enter the  first year percentage of student %d : "%(i+1)))
      A.append(x)
   print("Array accepted successfully\n\n");

def display_array(A): 
   n = len(A)
   if(n == 0) :
      print("\nNo records in the database")
   else :
      print("Array of FE Marks : ",end=' ')
      for i in range(n) :
         print("%.2f  "%A[i],end=' ')
      print("\n");

def partition(A,s,l) :
   b=s+1
   e=l
   while(e>=b) :
      while(b<=l and A[s] >= A[b]) :
         b = b + 1
      while(A[s] <A[e]) :
         e = e - 1
      if(e>b) :
         temp = A[e]
         A[e] = A[b]
         A[b] = temp
   temp = A[s]
   A[s] = A[e]
   A[e] = temp
   return e

def Quicksort(A,s,l) :
   if(s<l) :
      mid = partition(A,s,l)
      Quicksort(A,s,mid-1)
      Quicksort(A,mid+1,l)


     
def Main() :   
   A = []
   while True :
      print ("\t1 : Accept & Display the FE Marks")      
      print ("\t2 : Quick sort ascending order and display top five scores")
      print ("\t3 : Exit")
      ch = int(input("Enter your choice : "))
      if (ch == 3):
         print ("End of Program")
         quit()
      elif (ch==1):
         A = []
         accept_array(A)
         display_array(A)
      elif (ch==2):
         print("Marks before sorting")
         display_array(A)
         n =len(A)
         Quicksort(A,0,n-1)
         print("Marks after sorting")
         display_array(A)         
         if(n >= 5) :
            print("Top Five Scores : ")
            for i in range(n-1,n-6,-1) :
               print("\t%.2f"%A[i])
         else :
            print("Top Scorers : ")
            for i in range(n-1,-1,-1) :
               print("\t%.2f"%A[i])                               
      else :
           print ("Wrong choice entered !! Try again")


Main()





# (base) trushantramdasjadhav@Trushants-MacBook-Air FDS % cd "/Users/trushantramdasjadhav/Desktop/TicketingSystem/FD
# S"
# (base) trushantramdasjadhav@Trushants-MacBook-Air FDS % python -u "/Users/trushantramdasjadhav/Desktop/TicketingSy
# stem/FDS/Exp5.py"
#         1 : Accept & Display the FE Marks
#         2 : Selection Sort Ascending order
#         3 : Bubble sort Descending order and display top five scores
#         4 : Exit
# Enter your choice : 1
# Enter the total no. of student : 3
# Enter the  first year percentage of student 1 : 84
# Enter the  first year percentage of student 2 : 90
# Enter the  first year percentage of student 3 : 87
# Array accepted successfully


# Array of FE Marks :  84.00   90.00   87.00   

#         1 : Accept & Display the FE Marks
#         2 : Selection Sort Ascending order
#         3 : Bubble sort Descending order and display top five scores
#         4 : Exit
# Enter your choice : 2
# Marks before sorting
# Array of FE Marks :  84.00   90.00   87.00   

# Marks after sorting
# Array of FE Marks :  84.00   87.00   90.00   

#         1 : Accept & Display the FE Marks
#         2 : Selection Sort Ascending order
#         3 : Bubble sort Descending order and display top five scores
#         4 : Exit
# Enter your choice : 3
# Marks before sorting
# Array of FE Marks :  84.00   87.00   90.00   

# Marks after sorting
# Array of FE Marks :  90.00   87.00   84.00   

# Top Scorers : 
#         90.00
#         87.00
#         84.00
#         1 : Accept & Display the FE Marks
#         2 : Selection Sort Ascending order
#         3 : Bubble sort Descending order and display top five scores
#         4 : Exit
# Enter your choice : 4
# End of Program
# (base) trushantramdasjadhav@Trushants-MacBook-Air FDS % 