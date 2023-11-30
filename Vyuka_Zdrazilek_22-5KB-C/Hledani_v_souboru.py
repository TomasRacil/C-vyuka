from os.path import realpath, dirname, join

with open(join(dirname(realpath(__file__)), "2000.txt"),
          "r", encoding = "utf_8") as file:
    data = [int(radek) for radek in file.read().split('\n')]        # hodi do listu a rozdeli podle radku ('\n')

for index, cislo1 in enumerate(data):           # enumerate, bude to prochazet jen jednou
    for cislo2 in data[index: ]:
        if cislo1 + cislo2 == 2020: print(cislo1, cislo2)
#print(data)