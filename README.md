# PCmiRm
When using this code, please cite the paper: Prioritization of Coregulatory miRNA-mRNA Modules (PCmiRm): An Innovative Tool for Comparing Groups Using miRNA-mRNA Coregulation Modules Based on miRNA Differential Expression and Tissue-Specific Targets.  Feitosa, Rayssa et al.

Compatible with Linux and IOS systems.

READ ME

PCmiRm guidelines.

Before running the tool "PCmiRm.py", you need to compile the C++ part by running "make" (remember to run "make clean" before "make" whenever you alter the code) inside the "modules_identification" folder.
Test files are provided in the "input" folder. Also, "data/finaloutputs" has some examples of how the outputs should look.

When you run PCmiRm.py, the whole tool runs as a whole from the first until the third phase, but each phase has an output that can be used for any desired analysis.
Attention: After the end of the first phase (modules identification), the input for the second and third phase is required.

The first phase:
The first phase of the tool is a C++ code that presents the output as all possible coregulation, and non redundant modules (or bicliques) given a list of miRNAs, target genes, and their interactions as input. This part also asks for three parameters that represent the maximum number of miRNAs in the modules, the minimum number of genes in the modules, and the minimum number of miRNAs in the modules (which needs to be at least 2).
The inputs for the first phase are: 

				1- The name of the miRNA list file
				2- the name of the target genes list file
				3- the name of the interactions/network file
				4- An integer representing the maximum number of miRNAs (the default is 29, if no number is added)
				5- An integer representing the minimum number of genes in the modules
				6- An integer representing the minimum number of miRNAs (min 2)

note: The output from this phase is automatically written inside PCmiRm/data/inputs entitled "File6_allmodules.csv" has all possible non-redundant bicliques given the input network and can be used for further analysis if desired. This output is used for the next phases.

The second and third phases:
The second (Module Selection) and third (Module Comparison) phases of PCmiRm are Python algorithms.
The 6 Inputs are only .csv, .txt, or .tsv files in a folder numerated **necessarily** in the order below, and named as "File1" for item number 1 and so on. P.S.: You can add any character after "File1", e.g., "File1miRsUPCase.tsv".

	1- File1 = miRs upregulated group 1 (for example, case);
	2- File2 = miRs downregulated group 1;
        3- File3 = miRs upregulated group 2 (for example, control);
        4- File4 = miRs downregulated group 2,
        5- File5 = Tissue-Specific Genes (Desired set of genes)
        6- File6 = Corregulation modules (with at least 2 miRs)


The outputs from the second and third phases are grouped by modules with the same number of miRNAs. For each group (e.g., all modules with 3 miRNAs), there will be up to two output files. So, if the input in the first phase includes modules with 6 different miRNA counts, you could have up to 12 output files in total — two for each group.
One of those two files contains tissue-specific modules present in only one group and not in the other, and another contains modules that are present in both groups but their miRNA direction differs for one or more miRs (such as the same miRNA is upregulated in cases and downregulated in controls). If all modules are different in gene or miRNA content for both groups, the file containing modules present in both groups are not generated.
P.S.: If no differences are found between the two groups for modules with a specific number of miRNAs (e.g., modules containing 4 miRNAs), then no output files will be generated for that group.

The final outputs are .tsv files containing the information below: 

	1- Modules score (Which will rank the modules according to the amount of differentially expressed miRs and tissue-specific genes;
        2- List of miRs followed by "not DE" for not Differentially Expressed, "is UP" for Upregulated, and "is DOWN" for Downregulated;
        3- Percentage of differentially expressed miRs in the module; 
        4- Total number of miRs per module;
        5- List of Tissue-Specific Targets;
        6- Percentage of tissue-specific targets in the modules;
        7- Complete Module (initial input from Phase 1)

ps: Test files are in data/inputs.

