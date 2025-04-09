#!/usr/bin/python3

# Input: file B (having sets of b mirs) and file A (having sets of a mirs), b > a 
# Output: file with all mir sets of file A that are subsets of a mir set of file B with the same target set 

import sys


fileB = sys.argv[1]                      # file B name (bigger mirsets)
bigger_mirset_size  = int(sys.argv[2])   # size of the mir sets in file B
header_bigger = sys.argv[3]              # 1 if file B has a header or 0 otherwise  
fileA = sys.argv[4]                      # file A name (smaller mirsets)
smaller_mirset_size  = int(sys.argv[5])  # size of the mir sets in file A 
header_smaller = sys.argv[6]             # 1 if file A has a header or 0 otherwise 
output_file = fileA + ".nre"             # output filename
redundant_file = fileA + ".redundant"    # file with the redundances

f_bigger = open(fileB, 'r')
if header_bigger == "1":
    f_bigger.readline() #ignore header
# all_bigger_mirsets will be a Dictionary with key = nr of targets and value = an array of the mirsets Sets
# and all_bigger_mirset_targets the same for the targets  
all_bigger_mirsets = {}    
all_bigger_mirset_targets = {}    
while f_bigger:
    big_line = f_bigger.readline()
    if big_line == "":
        break
    # separate the fields and get the number of targets (and pop the first field)
    big_fields = big_line.split(',')
    big_nr_targets = big_fields[0]
    big_fields.pop(0)
    # if there is no key "big_nr_targets" in the dictionaries, create them with an empty array
    if not big_nr_targets in all_bigger_mirsets:
        all_bigger_mirsets[big_nr_targets] = []
        all_bigger_mirset_targets[big_nr_targets] = []
    # create a Set with the mirs from the bigger mirset (and pop the correpondent fields)
    big_mirset = set()
    for i in range(bigger_mirset_size):
        big_mirset.add(big_fields[0])     #print(i)
        big_fields.pop(0)
    all_bigger_mirsets[big_nr_targets].append(big_mirset)
    # create a Set of the targets
    big_targets = set(big_fields)
    all_bigger_mirset_targets[big_nr_targets].append(big_targets)

f_bigger.close()   

#keys = sorted(all_bigger_mirsets.keys())
#for k in keys:
#    print("Nr targets = ", k)
#    for i in range(len(all_bigger_mirsets[k])):
#        print(all_bigger_mirsets[k][i])
#        print(all_bigger_mirset_targets[k][i])
#        print(" ")




f_smaller = open(fileA, 'r')
if header_smaller == "1":
    f_smaller.readline() #descarta header
f_out = open(output_file, 'w')
f_red = open(redundant_file, 'w')

# read line by line of smaller mirset file comparing to the bigger mirsets with the same nr of targets
while f_smaller:   # that is the file being cleaned 
    sm_line = f_smaller.readline()
    if sm_line == "":
        break

    # separate the fields  
    sm_fields = sm_line.split(',')
    # get the number of targets of the smaller mirset (and pop this field)
    sm_nr_targets = sm_fields[0]
    sm_fields.pop(0)

    # if there is no bigger mirset with the same nr of targets, this smaller mirset is not redundant
    if not sm_nr_targets in all_bigger_mirsets:
        f_out.write(sm_line)
        continue

    # create a set for this mirset (and pop these fields)
    sm_mirset = set()
    for i in range(smaller_mirset_size):
        sm_mirset.add(sm_fields[0]) 
        sm_fields.pop(0)
    # create a set for the targets (the rest in sm_fields)
    sm_targets = set(sm_fields)

    # check all mirsets with the same nr of targets, stop if one is redundant
    redundant = False
    i = 0
    while not redundant and i < len(all_bigger_mirsets[sm_nr_targets]):
        # if the whole smaller mirset is inside the bigger mirset, compare the targets
        if all_bigger_mirsets[sm_nr_targets][i].issuperset(sm_mirset):
            if all_bigger_mirset_targets[sm_nr_targets][i] == sm_targets: #sm_mirset is redundant
                f_red.write(sm_line)      # print this mirset in the file of redundances  
                redundant = True      
        i = i+1

    # if not redundant with any bigger mirset, print it
    if not redundant:
        f_out.write(sm_line)

f_smaller.close()
f_out.close()
f_red.close()
