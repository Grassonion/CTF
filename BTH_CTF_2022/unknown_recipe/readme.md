# Unknown Recipe

### Challenge description:
Can you follow the recipe? - Only the very best can.
```
Ingridients needed:
  * One textfile of characters

Delicious end result:
  * A 44 character long flag


Cooking instructions:
  1. Gather all the rows
  2. Cut every row in half. Keep the first half.
  4. Delete every other row - Start with the very first one.
  5. For every fourth row starting at row one you should swap a character with row zero.
  6. Keep count of those rows - start counting at zero and do not count any longer than the length of the flag.
  7. The character to swap between the two rows are at the position that you currently have counted to.
  ```
____________________
### Walkthrough: 

Together with this recipe we get a 400 lines long textfile with 35600 characters.

This python code follows the recipe:  
```
f = open("output","r")

arr = []
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

```
