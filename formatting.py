def write_in_temp_file(f,lines):
    for line in lines:
        for char in line:
           # print(char)
            if char=='{' or char=='}':
                f.write("\n")
                f.write(char)
                f.write("\n")
           
            else :
                f.write(char)



def write_in_file(f,spaces,lines):
    for i in range(0,len(lines)):
        space=""
        for j in range(0,spaces[i]):
            space=space+" "
        words=lines[i].split()

        if len(words)==0:
            continue
        line=space

        for j in words:
            line=line+" "+j
        
        f.write(line+"\n")
        
        if check_for_closing(line)==1:
            f.write("\n")

       
       

def check_for_opening(line):
    words=line.split()
    if len(words)==0:
        return 0

    for word in words:
        for char in word:
            if char=='{':
                return 1
    return 0

def check_for_closing(line):
    words=line.split()

    if len(words)==0:
        return 0

    if words[0][0]=='}':
        return 1
    return 0

file1 = open('test.cpp', 'r')
lines = file1.readlines()
f=open('myfile.cpp','w')
write_in_temp_file(f,lines)
f=open('myfile.cpp','r')

lines=f.readlines()



spaces=[]
stack=[1]

for line in lines:
    a=stack.pop()
    stack.append(a)

    if check_for_opening(line)==1:
       spaces.append(a)
       stack.append(a+3)
    else  :
        if check_for_closing(line)==1:
            stack.pop()
            a=stack.pop()
            stack.append(a)
            spaces.append(a)
        else :
            spaces.append(a)


f=open('my_file2.cpp','w')

write_in_file(f,spaces,lines)
f.close()


