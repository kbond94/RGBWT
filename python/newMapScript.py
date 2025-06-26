from global_land_mask import globe
import numpy as np


def genMap(LaMa, LaMi, LoMa, LoMi):
    LatMax =  LaMa             
    LatMin =  LaMi               
    LatDiff = LatMax - LatMin      
    LatInc = (LatDiff) / 33        
    LonMax = LoMa          
    LonMin = LoMi          
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
    return map

def printMap(ma):
    for i in ma:
        for j in i:
            print(j, end=", ")
        print()
  
def main():
    lama = float(input("Enter maximum latitude: "))
    lami = float(input("Enter minimum latitude: "))

    loma = float(input("Enter maximum longitude: "))
    lomi = float(input("Enter minimum longitude: "))
    print("Generating map...")
    m = genMap(lama, lami, loma, lomi)
    print("Map generated")
    print("Printing map")
    printMap(m)

main()