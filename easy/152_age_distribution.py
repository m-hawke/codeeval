import sys

for line in open(sys.argv[1]):
    age = int(line)

    if 0 <= age <= 2:
        print( "Still in Mama's arms")
    elif 3 <= age <= 4:
        print( 'Preschool Maniac')
    elif 5 <= age <= 11:
        print( 'Elementary school')
    elif 12 <= age <= 14:
        print( 'Middle school')
    elif 15 <= age <= 18:
        print( 'High school')
    elif 19 <= age <= 22:
        print( "College")
    elif 23 <= age <= 65:
        print( 'Working for the man')
    elif 66 <= age <= 100:
        print( 'The Golden Years')
    else:
        print( 'This program is for humans')
