# PCmiRm
When using this code, please cite the paper: Prioritization of Coregulatory miRNA-mRNA Modules (PCmiRm): An Innovative Tool for Comparing Groups Using miRNA-mRNA Coregulation Modules Based on miRNA Differential Expression and Tissue-Specific Targets.  Feitosa, Rayssa et al.


READ ME

PCmiRm guidelines.

When you run PCmiRm.py, the whole tool runs as a whole from the first until the third phase, but each phase has an output that can be used for any desired analysis.
Attention: After the end of the first phase (modules identification), the input for the second and third phase is required.

The first phase:
The first phase of the tool is a C++ code that presents the output as all possible coregulation modules (or bicliques) given a list of miRNAs, target genes, and their interactions as input. This part also asks for two parameters that represents the maximum number of miRNAs in the modules and the minimum number of genes in the modules.
The inputs for the first phase are: 

				1- The name of the miRNA list file
				2- the name of the target genes list file
				3- the name of the interactions/network file
				4- An integer representing the maximum number of miRNAs (the default is 29, if no number is added)
				5- An integer representing the minimum number of genes in the modules
				6- An integer representing the minimum number of miRNAs (min 2)

note: The output from this phase is written inside PCmiRm/data/inputs entitled "File6_allmodules.csv" has all possible non-redundant bicliques given the input network and can be used for further analysis if desired.

The second and third phases:
The second (Module Selection) and third (Module Comparison) phases of PCmiRm are Python algorithms.
6 Inputs: Only .csv, .txt, or .tsv files in a folder numerated necessarily in the order below, and named as "File1" for item number 1 and so on. P.S.: You can add any character after "File1", e.g., "File1miRsUPCase.tsv".

	1- File1 = miRs upregulated group 1 (for example, case);
	2- File2 = miRs downregulated group 1;
        3- File3 = miRs upregulated group 2 (for example, control);
        4- File4 = miRs downregulated group 2,
        5- File5 = Tissue-Specific Genes (Desired set of genes)
        6- File6 = Corregulation modules (with at least 2 miRs)


The outputs for the second and third phases are:

Final outputs: 

	1- Modules score (Which will rank the modules according to the amount of differentially expressed miRs and tissue-specific genes;
        2- List of miRs followed by "not DE" for not Differentially Expressed, "is UP" for Upregulated, and "is DOWN" for Downregulated;
        3- Percentage of differentially expressed miRs; 
        4- Total number of miRs per module;
        5- List of Tissue-Specific Targets
        6- Percentage of tissue-specific targets in the modules;
        7- Total amount of targets;
        10- Complete Module


