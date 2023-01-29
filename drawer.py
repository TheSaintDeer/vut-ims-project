import array as arr
import matplotlib.pyplot as plt

f = open('out.txt', 'r')

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

f.close()

fig = plt.figure()

ax1 = fig.add_subplot(211)
# ax1.set_title('Project IMS (flight path)')
ax1.plot(position[0], position[2])
ax1.set_title('Dráha letu')
ax1.set_xlabel('x (m)')
ax1.set_ylabel('y (m)')
max = max(position[0]) if max(position[0]) > max(position[2]) else max(position[2])
ax1.set_xlim([0, max])
ax1.set_ylim([0, max])

ax2 = fig.add_subplot(223)
ax2.set_title('Graf rychlosty x')
ax2.plot(time, velocity[0])
ax2.set_xlabel('t (s)')
ax2.set_ylabel('x (m/s)')

ax3 = fig.add_subplot(224)
ax3.set_title('Graf rychlosty y')
ax3.plot(time, velocity[2])
ax3.set_xlabel('t (s)')
ax3.set_ylabel('y (m/s)')

plt.show()