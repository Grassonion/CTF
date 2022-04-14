f = open("output","r")

arr =[]
for line in f:
    arr.append(line.replace("\n",""))

# Get rid of second half of all rows
arr2 = []
for x in range(0,len(arr)):
    arr2.append(arr[x][:int(len(arr[x])/2)])

# Get rid of every other row
arr3 = []
for x in range(0,len(arr2)):
    if x%2==0:
        arr3.append(arr2[x])


# For every fourth row make sure that row swaps a letter with the first row
# The swapped character should be the at the position 'counter' == the rows number 1-200


counter =0
for y in range(1,len(arr3),4):
    if counter < 44:
        temp = list(arr3[0])
        temp2 = list(arr3[y])
        
        temp[counter] = arr3[y][counter]
        temp2[counter] = arr3[0][counter]

        arr3[0] = "".join(temp)
        arr3[y] = "".join(temp2)
        counter += 1
        print(y)

for x in arr3:
    print(x)
    break


