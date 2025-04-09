# PCmiRm
When using this code please cite the paper: Prioritization of Coregulatory miRNA-mRNA Modules (PCmiRm): An Innovative Tool for Comparing Groups Using miRNA-mRNA Coregulation Modules Based on miRNA Differential Expression and Tissue-Specific Targets.  Feitosa, Rayssa et al.


READ ME

PCmiRm guidelines.

When you run PCmiRm.py, the whole tool run as a whole from first until third phase, but each output from each phase has an output that can be used by the user for desired analysis.
Attention: After the end of the first phase (modules identification), the input for the second and third phase is required.

The first phase:
The first phase of the tool is a C++ code that present the output as all possible coregulation modules (or bicliques) give a list of miRNAs, target genes and their interactions as input. This part also asks for two parameters that represents the maximum number of miRNAs in the modules and the minimum number of genes in the modules.
The inputs for first phase are: 1- the name of the miRNA list file
			       2- the name of the target genes list file
			       3- the name of the interactions/network file
			       4- A number representing the max number of miRNAs (the default is 29, if no number is added)
			       5- A number representing the minimun number of genes in the modules

The outputs for second phase are:


note: The output from this phase is written inside PCmiRm/data/inputs entitled "File6_allmodules.csv" has all possible bicliques given the inputed network and can be used for further analysis if desired.

The second and third phase:
The second (Module Selection) and third (Module Comparison) phase of PCmiRm is a python algorithm.
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
