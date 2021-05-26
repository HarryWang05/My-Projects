#Author: Harry Wang
#Date: May 10, 2021
#Description: Binary search function that inputs the integer that needs to be found, and the list that needs ot be searched. All elements of the list will be inputed with a space between each element and no commas. All elements will be integers. It will output the index of the searched integer.

def binary_search(search, data):
  begin_index = 0
  end_index = len(data)-1
  while begin_index <= end_index:
    midpoint = begin_index+(end_index-begin_index)//2
    midpoint_value = data[midpoint]
    if midpoint_value == search:
      return midpoint
    elif midpoint_value < search:
      #Beginning index is to the right of midpoint
      begin_index = midpoint+1
    else:
      #Ending index is to the left of midpoint
      end_index = midpoint-1
  return str(search)+" is not in this list"
print("Input integer to search for, then input sorted list with integers, from lowest to greatest, all elements seperated by a space")
print(binary_search(int(input()),list(map(int,input().split()))))