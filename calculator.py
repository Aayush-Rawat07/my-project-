#this is my first program to create a calculator 
x=int(input("enter a no "))
y=input('enter the arthematic oprator ')
z=int(input('enter a no'))
if y=='+':
    print (x ,"+" ,z ,"=" ,x+z)
elif y== "-":
    print ( x , "-",z ,"=", x-z)
elif y=="*":
    print (x , "*", z , "= ", x*z)
elif y=="/":
    print (x , "/" , z ,"=", x/ z)
elif y=="**":
    print (x , "**" , z ,"=", x**z)    
