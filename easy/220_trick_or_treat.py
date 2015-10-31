import sys

for line in open(sys.argv[1]):
    vampires, zombies, witches, houses = [int(x) for x in
                                            line.replace(',','').split()[1::2]]
    print((vampires*3 + zombies*4 + witches*5) * houses // (vampires + zombies + witches))
