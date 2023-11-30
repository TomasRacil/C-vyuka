from os.path import realpath, dirname, join

with open(join(dirname(realpath(__file__)), "input.txt"), "r", encoding="utf_8") as file:
    maximum = max([sum([int(cal) for cal in elf.split('\n')]) for elf in file.read().split('\n\n')])

# Ma to hledat nejaky elfy a pocitat jim kalorie nebo co, nevim

