###Call other codes

import os

def inputs():
    file1 = str(input("name of miRNA file "))
    file2 = str(input("name of the targets file "))
    file3 = str(input("name of the file with the interactions "))
    file4 = str(input("number max of miRNAs in the modules "))
    file5 = str(input("number min of targets in the modules "))
    file6 = str(input("number min of miRNAs in the modules "))

    return(file1, file2, file3, file4, file5, file6)

def main():

    file1, file2, file3, file4, file5, file6 = inputs()
    maxmiRs = int(file4)
    minmiRs = int(file6)

    if maxmiRs == 0:
        os.system("./modules_identification/identify_modules ./data/inputs/" + file1 + " ./data/inputs/" + file2 + " ./data/inputs/" + file3 + " " + file4 + " " + file5)
    else:
        for i in range(minmiRs, maxmiRs+1):
            os.system("./modules_identification/identify_modules ./data/inputs/" + file1 + " ./data/inputs/" + file2 + " ./data/inputs/" + file3 + " " + str(i) + " " + file5)

    #Sorting the modules and removing redundancy
    os.system("bash ./modules_identification/remove_redundance_many.sh " + file4 + " " + file6 ) 

    #putting all modules together
    os.system("cat ./data/aux/*mirs.csv.nre ./data/aux/*"+ file4 +"mirs.csv  > data/inputs/File6_allmodules.csv")
    
    #Second part - selecting modules
    import Phase2and3 
    Phase2and3

main() 

