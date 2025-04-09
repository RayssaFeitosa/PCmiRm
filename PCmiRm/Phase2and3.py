"""
Algorithm to compare two groups of cooperative modules of differentially expressed miRNAs and its targets (found by database retrieveing)

Inputs: Only .csv or .tsv files in a separated folder numerated in the order below as "File1" for item number 1 and so on...
        1- File1 = miRs upregulated group 1 (for ex case);
        2- File2 = miRs downregulated group 1;
        3- File3 = miRs upregulated group 2 (for ex control);
        4- File4 = miRs downregulated group 2,
        5- File5 = Tissue-Specific Genes (Desired set o genes)
        6- File6 = Corregulation modules (with at least 2 miRs)

Outputs: 1- Modules score (Which will rank the modules according to the amount of differentially expressed miRs and tissue-specific genes;
         2- Total amount of miRs in module
         3- Amount of Up regulated miRs per modules
         4- Amount of Down regulated miRs per modules
         5- Percentage of differentially expressed miRS;
         6- Total amount of targets;
         7- Percentage of tissue-specific targets in the modules;
         8- List of miRs followed by "not DE" for not Differentially Expressed, "is UP" for Upregulated and "is DOWN" for Downregulated;
         9- List of Targets followed by the values 0 or 1 in which 0= No tissue, 1= Tissue;
         10- Complete Module

"""
import math
import sys 
from glob import glob
import numpy as np

def readinput(): #read all and access the content of the tables transforming each in a list of modules and then deletes the blank spaces
    inputs = glob('./data/inputs/File*.csv') + glob('./data/inputs/File*.tsv') + glob('./data/inputs/File*.txt')
    inputs.sort()  # to put in order
    c = 1
    for a in inputs:
        archives = open(a)
        archive = archives.read()
        archives.close()
        if c == 1:
            upmiRsGroup1 = archive
        elif c == 2:
            downmiRsGroup1 = archive
        elif c == 3:
            upmiRsGroup2 = archive
        elif c == 4:
            downmiRsGroup2 = archive
        elif c == 5:
            tSpecificGenes = archive
        else:
            corregulationModules = archive
        c += 1

    modules = []
    modules1 = ''.join([str(e) for e in corregulationModules])
    modules1 = modules1.split(",")
    for s in modules1:  # take out all the empty elements in each module
        if (s != ''):
            modules.append(s)
    modules = ','.join([str(e) for e in modules])
    modules = modules.split('\n')
    modulesconverted = []
    for module in modules:
        module = module.split(",")
        for element in module:
            if element == '':
                module.remove(element)
        modulesconverted.append(module)

    return (upmiRsGroup1, downmiRsGroup1, upmiRsGroup2, downmiRsGroup2, tSpecificGenes, modulesconverted)

def createDicts(x):
    y = {}
    x = x.split('\n')
    for element in x:
        y[element] = 1
    return (y)

def selectmiRs(module, dicUP, dicDOWN):
    outputvariable = ""
    countvariableUP = 0
    countvariableDOWN = 0
    countvariablesame = 0
    micros = list(filter(lambda element: element.startswith("hsa-"), module))[0:]
    micros.sort() #putting the modules miRNA in alfa-numeric order for facilitating their identification

    for element in micros: #function for counting the DEs (Up and Down) and not DEs miRNAs
        if element == "":
            continue  #ignoring the empty elements in the list
        if outputvariable != "":
            outputvariable += ", "
        if element in dicUP:
            outputvariable += element
            outputvariable += " is UP"
            countvariableUP += 1
        elif element in dicDOWN:
            outputvariable += element
            outputvariable += " is DOWN"
            countvariableDOWN += 1
        else:
            outputvariable += element
            outputvariable += ' is not DE'
            countvariablesame += 1
    return (outputvariable, countvariableUP, countvariableDOWN, countvariablesame)

def main():
    upmiRsCase, downmiRsCase, upmiRsControl, downmiRsControl, TSGenes, modules = readinput()
    TSGenes = createDicts(TSGenes) 
    miRsCaseUp = createDicts(upmiRsCase)
    miRsControlUp = createDicts(upmiRsControl)
    miRsCaseDown = createDicts(downmiRsCase)
    miRsControlDown = createDicts(downmiRsControl)
    
    minm = int(input("What is the minimum of miRNAs with differential expression (DE) in case x control accepted in the modules? ")) #for the user to choose the min DE miRNAs
    minTSG = int(input("What is the minimum of tissue-specific (TS) genes accepted in the modules? "))
    minpescore = int(input("What is the percentage cutoff of the highest scores you want to use? "))
    if minm + minTSG < 1:
        print("Please insert at least the number 1 for one of the conditions: minimum DE miRNAs or TS genes")
        return
    onlyPhase2 = str(input("Do you want stop at phase 2 and get all modules for each groups without comparing them? "))

    pesomiRs = 4 #Default, number can be changed as desired
    pesoTS = 2 # The number can be changed as desired or select 0 as well if you do not want to consider TS genes
    emc = 0  # equal modules count
    dmc = 0  # different modules count
    tm = 0  # total modules
   
    #Calculating the min score based on the desired percentage
    scoresall = []
    for module in modules:
        if len(module) > 0:
            genes = list(filter(lambda element: element.startswith("hsa-") is False, module))[0:]
            genes.sort() 
            if module[0].isdigit():
                numdealvos = int(module[0])
                tm += 1
            outputTargets = ""
            TSgenescount = 0
            noTSgenescount = 0
            for element in genes:
                if element == "":   #if first element is empty
                    continue

                elif element in TSGenes.keys():
                    outputTargets += element
                    outputTargets += ",1; "
                    TSgenescount += 1

                else:
                    noTSgenescount += 1
        outputMirsCase, miUpCasecount, miDownCasecount, countmiRsSameCase = selectmiRs(module, miRsCaseUp, miRsCaseDown)
        outputMirsControl, miUpControlcount, miDownControlcount, countmiRsSameControl = selectmiRs(module, miRsControlUp, miRsControlDown)
                        
        if ((miUpCasecount + miDownCasecount) >= minm and TSgenescount >= minTSG): 
            scoreCase = (pesomiRs*math.log2(countmiRsSameCase + miUpCasecount + miDownCasecount)*(miUpCasecount + miDownCasecount)/(countmiRsSameCase + miUpCasecount + miDownCasecount)) + ((pesoTS*math.log((TSgenescount + noTSgenescount),(2))*TSgenescount) / (TSgenescount + noTSgenescount))
            scoresall.append(scoreCase)
        if (miUpControlcount + miDownControlcount) >= minm and TSgenescount >= minTSG:
            scoreControl = (pesomiRs*math.log2(countmiRsSameControl + miUpControlcount + miDownControlcount)*(miUpControlcount + miDownControlcount)/(countmiRsSameControl + miUpControlcount + miDownControlcount)) + ((pesoTS*math.log((TSgenescount + noTSgenescount),(2))*TSgenescount) / (TSgenescount + noTSgenescount))         
            scoresall.append(scoreControl)  

    minscore = np.percentile(scoresall, 100-minpescore)

    DEinboth = []
    DEinboth.append('\t' + "Score_Control" + '\t'+ "miRsControl" + '\t'+ "DEmiRNAcontrolPercentage"+ '\t'+ "Score_Case" + '\t'+ "miRsCase"+ '\t'+ "DEmiRNAcasePercentage"+ '\t'+ "TS_Genes" + '\t' +"TSgenesPercentage" + '\t' + "Module")
    original_stdout = sys.stdout
    with open('./data/finaloutputs/output_DEinonegroup_min{}DEmiRNAsand{}TSGs.tsv'. format(minm, minTSG), 'w') as f:
        sys.stdout = f
        print('\t', "Score", '\t', "miRNAs", '\t', "DEmiRNAPercentage", '\t', "Total_miRNAs", '\t', "TS_Genes", '\t', "TSgenesPercentage", '\t', "Module")
        for module in modules:
            if len(module) > 0:
                genes = list(filter(lambda element: element.startswith("hsa-") is False, module))[1:]
                genes.sort()
                if module[0].isdigit():
                    numdealvos = int(module[0])
                    tm += 1
                outputTargets = ""
                TSgenescount = 0
                noTSgenescount = 0
                for element in genes:
                    if element == "":  #if first element is empty do not do anything, just continue
                        continue


                    elif element in TSGenes.keys():
                        if outputTargets != "":
                            outputTargets += ","
                        outputTargets += element
                        TSgenescount += 1

                    else:
                        noTSgenescount += 1

                if module[0] != "" and '':
                    if (TSgenescount + noTSgenescount) != numdealvos:
                        print("Erro:", noTSgenescount, TSgenescount, numdealvos, outputTargets, module) #internal check

                outputMirsCase, miUpCasecount, miDownCasecount, countmiRsSameCase = selectmiRs(module, miRsCaseUp, miRsCaseDown)
                outputMirsControl, miUpControlcount, miDownControlcount, countmiRsSameControl = selectmiRs(module, miRsControlUp, miRsControlDown)
                            

                if module[0] != '':  #another internal check for empty modules
                    if (countmiRsSameCase + miUpCasecount + miDownCasecount) != (countmiRsSameControl + miUpControlcount + miDownControlcount):
                        print("Error miRs Quantity:", countmiRsSameCase, miUpCasecount, miDownCasecount, countmiRsSameControl + miUpControlcount + miDownControlcount, outputMirsCase, module)
                    
                    #now the score calculations and final output
                    varcase = ()
                    varcontrol = ()
                    scoreCase = 0
                    scoreControl = 0
                    if TSgenescount >= minTSG:
                        if TSgenescount > minTSG:
                            percentTSgenes = '{0:.2f}'.format((TSgenescount / (noTSgenescount + TSgenescount)) * 100)
                        if (miUpCasecount + miDownCasecount) >= minm: 
                            scoreCase = (pesomiRs*math.log2(countmiRsSameCase + miUpCasecount + miDownCasecount)*(miUpCasecount + miDownCasecount)/(countmiRsSameCase + miUpCasecount + miDownCasecount)) + ((pesoTS*math.log((TSgenescount + noTSgenescount),(2))*TSgenescount) / (TSgenescount + noTSgenescount))
                            percentDEmiCase = ((miUpCasecount + miDownCasecount) / (countmiRsSameCase + miUpCasecount + miDownCasecount)) * 100
                            percentDEmiCase = '{0:.2f}'.format(percentDEmiCase)
                            scoreCase = '{0:.3f}'.format(scoreCase)
                            varcase = (scoreCase, miUpCasecount, miDownCasecount,
                                    countmiRsSameCase + miUpCasecount + miDownCasecount, outputMirsCase, TSgenescount,
                                    noTSgenescount, outputTargets, module)
                        if (miUpControlcount + miDownControlcount) >= minm:
                            scoreControl = (pesomiRs*math.log2(countmiRsSameControl + miUpControlcount + miDownControlcount)*(miUpControlcount + miDownControlcount)/(countmiRsSameControl + miUpControlcount + miDownControlcount)) + ((pesoTS*math.log((TSgenescount + noTSgenescount),(2))*TSgenescount) / (TSgenescount + noTSgenescount))
                            percentDEmiControl = ((miUpControlcount + miDownControlcount) / (countmiRsSameControl + miUpControlcount + miDownControlcount)) * 100
                            percentDEmiControl = '{0:.2f}'.format(percentDEmiControl)
                            scoreControl = '{0:.3f}'.format(scoreControl)
                            varcontrol = (scoreControl, miUpControlcount, miDownControlcount,
                                        countmiRsSameControl + miUpControlcount + miDownControlcount, outputMirsControl,
                                        TSgenescount, noTSgenescount, outputTargets, module)

                        if ((miUpCasecount + miDownCasecount) >= minm) or (miUpControlcount + miDownControlcount) >= minm:   
                            if varcase == varcontrol:
                                if float(scoreCase) >= minscore or float(scoreControl) >= minscore:
                                    emc += 1
                                    if onlyPhase2 == "yes":   
                                        if (miUpCasecount + miDownCasecount) >= max(1,minm) and (miUpControlcount + miDownControlcount) >= max(1,minm):
                                            DEinboth.append("DE in both: "+ '\t' + scoreControl + '\t'+ outputMirsControl+ '\t' + str(percentDEmiControl)+ '\t'+ scoreCase + '\t'+ outputMirsCase + 
                                                    '\t'+ str(percentDEmiCase)+ '\t'+ outputTargets+ '\t' + str(percentTSgenes) + '\t'+ str(module))
                                        elif (miUpCasecount + miDownCasecount) >= max(1,minm):
                                            print("Only in Case: ",'\t', scoreCase, '\t', outputMirsCase, '\t', percentDEmiCase, '\t', countmiRsSameControl + miUpControlcount + miDownControlcount, '\t', outputTargets, '\t', percentTSgenes, '\t', module)
                                        elif (miUpControlcount + miDownControlcount) >= max(1,minm):
                                            print("Only in Control: ",'\t', scoreControl, '\t', outputMirsControl, '\t', percentDEmiControl, '\t', countmiRsSameControl + miUpControlcount + miDownControlcount, '\t', outputTargets, '\t', percentTSgenes, '\t', module)
                            elif varcase != varcontrol:
                                if float(scoreCase) >= minscore or float(scoreControl) >= minscore:
                                    dmc += 1    
                                    if (miUpCasecount + miDownCasecount) >= max(0,minm) and (miUpControlcount + miDownControlcount) >= max(0,minm):
                                        DEinboth.append("DE in both: "+ '\t' + scoreControl + '\t'+ outputMirsControl+ '\t' + str(percentDEmiControl)+ '\t'+ scoreCase + '\t'+ outputMirsCase + 
                                                    '\t'+ str(percentDEmiCase)+ '\t'+ outputTargets+ '\t' + str(percentTSgenes) + '\t'+ str(module))
                                    elif (miUpCasecount + miDownCasecount) >= max(1,minm):
                                            print("Only in Case: ",'\t', scoreCase, '\t', outputMirsCase, '\t', percentDEmiCase, '\t', countmiRsSameControl + miUpControlcount + miDownControlcount, '\t', outputTargets, '\t', percentTSgenes, '\t', module)
                                    elif (miUpControlcount + miDownControlcount) >= max(1,minm):
                                            print("Only in Control: ",'\t', scoreControl, '\t', outputMirsControl, '\t', percentDEmiControl, '\t', countmiRsSameControl + miUpControlcount + miDownControlcount, '\t', outputTargets, '\t', percentTSgenes, '\t', module)
        sys.stdout = original_stdout
    
    original_stdout2 = sys.stdout
    with open('./data/finaloutputs/output_DEinboth_min{}DEmiRNAsand{}TSGs.tsv'. format(minm, minTSG), 'w') as g:
        sys.stdout = g
        for line in DEinboth:
            print(line)
        sys.stdout = original_stdout2
    
    print(len(DEinboth))
    if emc + dmc == 0:
        print ("All modules has lower score than minimum required in input")
    
    print("In a total of {} maximal corregulation modules, {} modules are equal for cases and control and {} are different when considering {} DE miRNAs and {} Tissue-specific genes.".format(tm, emc, dmc, minm, minTSG))

main()