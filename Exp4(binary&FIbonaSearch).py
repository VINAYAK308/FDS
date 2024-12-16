"""
       Group B - Assignment 4
a)	Write a python program to store names and mobile numbers of your friends
in sorted order on names. Search your friend from list using binary search
(recursive and non-recursive). Insert friend if not present in phonebook
b)	Write a python program to store names and mobile numbers of your friends
in sorted order on names. Search your friend from list using Fibonacci search.
Insert friend if not present in phonebook.

"""

def accept_array(A): 
   n = int(input("Enter the total no. of student : "))
   print("Input Friends information  in sorted order of names ")
   for i in range(n):
      print("\tInput Details of Friend %d : "%(i+1))
      name  = input("\t\tEnter the  name : ")
      Mob  = input("\t\tEnter the  mobile number : ")
      x = [name, Mob]
      A.append(x)
   print("Friends Info accepted successfully\n\n")
   return n

def display_array(A,n): 
   if(n == 0) :
      print("\nNo records in the database")
   else :
      print("Friends Information : ")
      for i in range(n) :
         print("\tFriend %d  : %10s %s  "%((i+1),A[i][0],A[i][1]))
      print("\n");


def Recursive_Binary_Search(A,s,l,X) :
   if(s <= l ) :
      mid = int((s + l) / 2)
      if(A[mid][0] == X) :
         return mid      # Found
      else :
         if(X < A[mid][0] ) :
            return Recursive_Binary_Search(A,s,mid-1,X)
         else :
            return Recursive_Binary_Search(A,mid+1,l,X)
   return -1 # NOT FOUND



def Iterative_Binary_Search(A,n,X) :
   s = 0
   l = n-1
   while(s <= l ) :
      mid = int((s + l) / 2)
      if(A[mid][0] == X) :
         return mid       # Found
      else :
         if (X < A[mid][0] )  :
            l = mid-1
         else :
            s = mid+1
   return -1; #NOT FOUND


#Returns index of x if present,  else returns -1 
def Fibonacci_Search(A,n,X) :
   f1 = 0
   f2 = 1
   f3 = f1 + f2
   offset = -1
   while (f3 < n) :
      f1 = f2
      f2 = f3
      f3  = f1 + f2
   while (f3 > 1) :
      i = min(offset+f1, n-1)
      if(A[i][0] == X) :
         return i        #Found
      else :
         if (X < A[i][0] ) :   # left substudent (66 % or 2/3 student)
            f3  = f1
            f2 = f2 - f1
            f1 = f3 - f2
         else :     # right substudent ( 33 % or 1/3 student)
            f3  = f2
            f2 = f1
            f1 = f3 - f2
            offset = i
   if(f2 == 1 and (offset+1) < n and A[offset + 1][0] == X) :      
      return offset+1      # Found
   return -1    #NOT FOUND

def Insert_the_friend(A,n,name) :
   Mob  = input("Enter the  mobile number of the friend  : ")
   X = [name, Mob]
   A.append(X)
   j  = n-1
   while( j >= 0) :
      if (A[j][0] <= name) :
         break
      else :
         A[j+1] = A[j]
      j = j - 1
   A[j+1] = X
   print("\nFriend info added in the database")
   display_array(A,n+1)

      
def Main() :   
   A = []
   while True :
      print ("\t1 : Accept & Display Students info ")      
      print ("\t2 : Recursive Binary Search")
      print ("\t3 : Iterative Binary Search")
      print ("\t4 : Fibonacci Search")
      print ("\t5 : Exit")
      ch = int(input("Enter your choice : "))
      if (ch == 5):
         print ("End of Program")
         quit()
      elif (ch==1):
         A = []
         n = accept_array(A)
         display_array(A,n)
      elif (ch==2):
         X = input("Enter the name of the friend to be searched : ")
         flag  = Recursive_Binary_Search(A,0,n-1,X)
         if(flag == -1) :
            print("\tFriend to be Searched not Found\n")
            Insert_the_friend(A,n,X)
            n = n + 1
         else :
            print("\tFriend found at location %d"%(flag + 1))
      elif (ch==3):
         X = input("Enter the name of the friend to be searched : ")
         flag  = Iterative_Binary_Search(A,n,X)
         if(flag == -1) :
            print("\tFriend to be Searched not Found\n")
            Insert_the_friend(A,n,X)
            n = n + 1
         else :
            print("\tFriend found at location %d"%(flag + 1))            
      elif (ch==4):
         X = input("Enter the name of the friend to be searched : ")
         flag  = Fibonacci_Search(A,n,X)
         if(flag == -1) :
            print("\tFriend to be Searched not Found\n")
            Insert_the_friend(A,n,X)
            n = n + 1
         else :
            print("\tFriend found at location %d"%(flag + 1))            
      else :
           print ("Wrong choice entered !! Try again")


Main()



# Time : O(1)
# Binary Search: 11 22 33 44 55 66 77 88
# Target ; 88


# Time : O(log n)
# Fibonacci Search: 10 22 35 40 45 50 80 82 85 90 100
# Target : 85
# length of array : 11


# cd "/Users/trushantramdasjadhav/Desktop/TicketingSystem/FDS"
# python -u "/Users/trushantramdasjadhav/Desktop/TicketingSystem/FDS/Exp4.py"
# (base) trushantramdasjadhav@Trushants-MacBook-Air FDS % cd "/Users/trushantramdasjadhav/Desktop/TicketingSystem/FD
# S"
# (base) trushantramdasjadhav@Trushants-MacBook-Air FDS % python -u "/Users/trushantramdasjadhav/Desktop/TicketingSy
# stem/FDS/Exp4.py"
#         1 : Accept & Display Students info 
#         2 : Recursive Binary Search
#         3 : Iterative Binary Search
#         4 : Fibonacci Search
#         5 : Exit
# Enter your choice : 1
# Enter the total no. of student : 2
# Input Friends information  in sorted order of names 
#         Input Details of Friend 1 : 
#                 Enter the  name : V    
#                 Enter the  mobile number : 7498564907
#         Input Details of Friend 2 : 
#                 Enter the  name : T
#                 Enter the  mobile number : 9175047953
# Friends Info accepted successfully


# Friends Information : 
#         Friend 1  :          V 7498564907  
#         Friend 2  :          T 9175047953  


#         1 : Accept & Display Students info 
#         2 : Recursive Binary Search
#         3 : Iterative Binary Search
#         4 : Fibonacci Search
#         5 : Exit
# Enter your choice : 4
# Enter the name of the friend to be searched : V
#         Friend found at location 1
#         1 : Accept & Display Students info 
#         2 : Recursive Binary Search
#         3 : Iterative Binary Search
#         4 : Fibonacci Search
#         5 : Exit
# Enter your choice : 2
# Enter the name of the friend to be searched : V
#         Friend found at location 1
#         1 : Accept & Display Students info 
#         2 : Recursive Binary Search
#         3 : Iterative Binary Search
#         4 : Fibonacci Search
#         5 : Exit
# Enter your choice : 3
# Enter the name of the friend to be searched : V
#         Friend found at location 1
#         1 : Accept & Display Students info 
#         2 : Recursive Binary Search
#         3 : Iterative Binary Search
#         4 : Fibonacci Search
#         5 : Exit
# Enter your choice : 5
# End of Program
# (base) trushantramdasjadhav@Trushants-MacBook-Air FDS % 
