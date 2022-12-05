import array as arr
import matplotlib.pyplot as plt

f = open('out.txt', 'r')

fig = plt.subplots()

time = []
position = [[], [], []]
velocity = [[], [], []]

lines = f.readlines()

for line in lines:
    a = line.split()

    time.append(float(a[0]))

    p = arr.array('f', map(float, a[1].split(':'))); 
    for i in range(0, 3):
        position[i].append(p[i])

    v = arr.array('f', map(float, a[2].split(':'))); 
    for i in range(0, 3):
        velocity[i].append(v[i])

plt.plot(time, velocity[0])
plt.show()

f.close()