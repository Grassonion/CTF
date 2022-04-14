import string
import random
import secrets

rows = 200
flag="BTH_CTF{W3LL_C0Oked_frI3nD_Addd_G4Rlic_N3xT}"
print(len(flag))
secret_row_interval = 4

def random_char(y):
       return ''.join(random.choice(string.ascii_letters+"_{[]}") for x in range(y))

#f = open("output","wb")
#for x in range(0,200):
#    if x == secret_row:
#        f.write(flag.encode())
#    else:
#        for y in range(0,len(flag)):
#            f.write(secrets.token_bytes(1))
#    f.write('\n'.encode())


# Start flag as row one and then append random rows
arr = []
arr.append(flag)
for x in range(1,rows):
    arr.append(random_char(len(flag)))


# For every 'something' row swap one character with the flag-row
# The swapped character is at the position 'counter' == the rows number 1-200
counter =0
for y in range(1,rows,secret_row_interval):
    if counter < len(flag):
        temp = list(arr[0])
        temp2 = list(arr[y])
        temp[counter] = arr[y][counter]
        temp2[counter] = arr[0][counter]

        arr[0] = "".join(temp)
        arr[y] = "".join(temp2)
        counter += 1

# Double the number of rows, every second row is just random characters
newarr = []
for x in range(0,rows):
    newarr.append(arr[x])
    newarr.append(random_char(len(flag)))


# Double the length of each row, second half is random characters
for x in range(0,len(newarr)):
    newarr[x] = newarr[x] + random_char(len(flag))


# newarr.reverse

f = open("output","w")
for x in newarr:
    f.write(x+"\n")

print("done")
