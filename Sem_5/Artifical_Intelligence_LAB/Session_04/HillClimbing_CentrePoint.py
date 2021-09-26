import math

def find_ManhattanDistance(current_point, points):
    total_distance = 0
    for point in points:
        total_distance += abs(current_point[0] - point[0]) + abs(current_point[1] - point[1])
        
    return total_distance

def get_Min_Distance(current, points):
    
    x, y = current[0], current[1]

    adds = [-1, 0, 1]
    min_distance = math.inf
    
    for i in adds:
        for j in adds:
            if (x+i >= 0 and x+i < 10) and (y+j >= 0 and y+j < 7) and (x+i != x or y+j != y):               
                distance = find_ManhattanDistance((x+i, y+j), points)
                if distance < min_distance:
                    min_distance = distance
                    min_x, min_y = x+i, y+j
                    
    return min_distance, (min_x, min_y)

def centre_HillClimbing(points):
    current = (0, 0)
    current_distance = math.inf
    
    new_distance, new = get_Min_Distance(current, points)
    
    while(new_distance < current_distance):
        print("Point : ", new, "Distance : ", new_distance)
        current, current_distance = new, new_distance
        new_distance, new = get_Min_Distance(current, points)
        
    return current, current_distance
    
    

if __name__ == "__main__":
    points = [(1,1), (5, 2), (6, 4), (7, 7), (4, 9)]
    centre, distance = centre_HillClimbing(points)
    
    print("Centre Point : ", centre, "Distance : ", distance)
    
# Output:
    
# Point :  (1, 1) Distance :  36
# Point :  (2, 2) Distance :  30
# Point :  (3, 3) Distance :  26
# Point :  (4, 4) Distance :  22
# Point :  (5, 4) Distance :  21
# Centre Point :  (5, 4) Distance :  21

    
    