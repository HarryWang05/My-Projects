#Author: Harry Wang
#Date: May 9, 2021
#Description: Quick sort function in python. Inputs a list of integers and sorts them lowest to greatest. Learned from: https://www.youtube.com/watch?v=kFeXwkgnQ9U
def quick_sort(data):
    l = len(data)
    if l <= 1:
        return data
    else:
        pivot = data.pop()
    greater_list = []
    lower_list = []
    for item in data:
        if item > pivot:
            greater_list.append(item)
        else:
            lower_list.append(item)
    return quick_sort(lower_list) + [pivot] + quick_sort(greater_list)
print("Input list with integers, all elements seperated by a space")
print(quick_sort(list(map(int,input().split()))))