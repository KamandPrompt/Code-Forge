import numpy as np
import matplotlib.pyplot as plt
import time

n = int(input("Enter n: "))
store1 = []

for i in range(n):
    l, k = map(int, input().split())
    store1.append([l, k])
cnt  = 0
store=[]
for i in range(len(store1)):
    if(store1[i] in store):
        store.pop()
    store.append(store1[i])
# print(store)
store = sorted(store)
min_ele = min(store)

angles = []
for i in range(len(store)):
    if store[i] != min_ele:
        num = store[i][1] - min_ele[1]
        den = store[i][0] - min_ele[0]
        m = np.arctan2(num, den)
        angles.append([m, i])

angles.sort()
# print(angles)

sorted_list = [min_ele] + [store[angle[1]] for angle in angles]
print(sorted_list)
# same process as used in convex hull algo done in cpp
plt.ion()
fig, ax = plt.subplots()
# initialize the graph
main = []
temp = []

x_coords = [point[0] for point in sorted_list]
y_coords = [point[1] for point in sorted_list]

initial_x = [point[0] for point in store]
initial_y = [point[1] for point in store]
# storing original coordinates and sorted ones
i = 0
while i < len(sorted_list):
    main.append([sorted_list[i][0], sorted_list[i][1]])
    if len(main) >= 3:
        area = (
        (sorted_list[i - 1][0] - sorted_list[i - 2][0]) * (sorted_list[i][1] - sorted_list[i - 2][1]) - (sorted_list[i - 1][1] - sorted_list[i - 2][1]) * (sorted_list[i][0] - sorted_list[i - 2][0])
        )
        if area > 0:
            color1 = 'green'
            color2 = 'red'
        elif area < 0:
            color1 = 'red'
            color2 = 'green'
            main.pop(-2)
            sorted_list.remove(sorted_list[i-1])
            i=i-2

        else:
            temp.append(main[i])
            main.pop(-2)
            main.append(temp[0])
            temp.pop()

    convex_hull_x = [point[0] for point in main]
    convex_hull_y = [point[1] for point in main]
    # storing points of stack such that we can make line for every element
    # and show the application
    color1 = 'orange'
    color2 = 'green'

    ax.cla()
    # clearing current axes
    ax.scatter(initial_x, initial_y, color='blue', label='Points')
    ax.plot(convex_hull_x, convex_hull_y, color=color1, linestyle='-')
    ax.scatter(convex_hull_x, convex_hull_y, color=color1,)
    ax.scatter(x_coords[i], y_coords[i], color=color2)
    ax.legend()
    # planning and plotting 
    plt.pause(1)
    i += 1

convex_hull_x.append(min_ele[0])
convex_hull_y.append(min_ele[1])
ax.plot(convex_hull_x, convex_hull_y, color=color1, linestyle='-')
plt.ioff()
# turn off matplotlib mode to change a single graph
plt.show()
time.sleep(3)
# time to show the end graph and then 3[1]s to end the program

