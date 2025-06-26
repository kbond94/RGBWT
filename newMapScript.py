from global_land_mask import globe
import numpy as np

LatMax =  55.37210             
LatMin =  51.45317               
LatDiff = LatMax - LatMin      
LatInc = (LatDiff) / 33        
LonMax = -5.46974          
LonMin = -10.08949          
LonDiff = LonMax - LonMin       
LonInc = (LonDiff) / 17
Latf = LatMax
Lonf = LonMin;


lat = np.array([0.0]*32)
lon = np.array([0.0]*16)

for i in range(32):
      Latf = Latf - LatInc
      Lat = str(round(Latf, 5))
      lat[i] = Lat

for o in range (16):
    Lonf = Lonf + LonInc;
    Lon = str(round(Lonf, 5));
    lon[o] = Lon

row = 16
column = 32

map = np.array([[0]*row]*column)

x = 0
y = 0

xcoord = 0.0
ycoord = 0.0
#print(map)

for x in range(32):
    xcoord = lat[x]
    for y in range(16):
        ycoord = lon[y]
        land = globe.is_land(xcoord,ycoord)
        #print(land)
        if land == 1:
            map[x,y] = 1
        elif land == 0:
             map[x,y] = 0


for i in map:
    for j in i:
        print(j, end=", ")
    print()


    
"""index = 0;
for i in lat:
    if index == 0:
        print("{")
    if index == 31:
        print(i)
    else:
        print(i,end = ", ")
    index = index + 1
print("};")
print()
print()

index = 0;
for i in lon:
    if index == 0:
        print("{")
    if index == 15:
        print(i)
    else:
        print(i,end = ", ")
    index = index + 1    
print("};")"""




