#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>
#include <fstream>
#include "MiRNA.h"
#include "Target.h"
#include "MiRNATargetMap.h"
#include "ReadFiles.h"

using namespace std;

MiRNATargetMap mt_map;
string target_names = "";
string mir_names = "";
int minTargets = 0;

void identify_2mirs_modules();
void identify_3mirs_modules();
void identify_4mirs_modules();
void identify_5mirs_modules();
void identify_6mirs_modules();
void identify_7mirs_modules();
void identify_8mirs_modules();
void identify_9mirs_modules();
void identify_10mirs_modules();
void identify_11mirs_modules();
void identify_12mirs_modules();
void identify_13mirs_modules();
void identify_14mirs_modules();
void identify_15mirs_modules();
void identify_16mirs_modules();
void identify_17mirs_modules();
void identify_18mirs_modules();
void identify_19mirs_modules();
void identify_20mirs_modules();
void identify_21mirs_modules();
void identify_22mirs_modules();
void identify_23mirs_modules();
void identify_24mirs_modules();
void identify_25mirs_modules();
void identify_26mirs_modules();
void identify_27mirs_modules();
void identify_28mirs_modules();
void identify_29mirs_modules();
void identify_30mirs_modules();

int main (int argc, char **argv){

	//read input files and create the MiRNATargetMap (mt_map) 
	ReadFiles * r = new ReadFiles();
	r->read_mirs(argv[1], &mt_map);
	r->read_genes(argv[2], &mt_map);
	//Two column file: "target,miRNA"
	r->read_interactions(argv[3], &mt_map);
	
	// the fourth argument is the size of the modules to be generated (ie, the number of mirs in the module).
	// 0 means that modules with sizes from 2 to 30 will be generated
	int modSize = atoi(argv[4]);

	// the fifth argument is the minimum number of common target genes that should be present in the module.
	minTargets = atoi(argv[5]);

	// identify modules with several number of mirnas (2 to 30) 
	switch (modSize){
		case 0:
			cout << "Generating all...\n";
			identify_2mirs_modules();
			identify_3mirs_modules();
			identify_4mirs_modules();
			identify_5mirs_modules();
			identify_6mirs_modules();
			identify_7mirs_modules();
			identify_8mirs_modules();
			identify_9mirs_modules();
			identify_10mirs_modules();
			identify_11mirs_modules();
			identify_12mirs_modules();
			identify_13mirs_modules();
			identify_14mirs_modules();
			identify_15mirs_modules();
			identify_16mirs_modules();
			identify_17mirs_modules();
			identify_18mirs_modules();
			identify_19mirs_modules();
			identify_20mirs_modules();
			identify_21mirs_modules();
			identify_22mirs_modules();
			identify_23mirs_modules();
			identify_24mirs_modules();
			identify_25mirs_modules();
			identify_26mirs_modules();
			identify_27mirs_modules();
			identify_28mirs_modules();
			identify_29mirs_modules();
			identify_30mirs_modules();
			break;	
		case 2:
			cout << "Generating 2mirs modules...\n";
			identify_2mirs_modules();
			break;
		case 3:
			cout << "Generating 3mirs modules...\n";
			identify_3mirs_modules();
			break;
		case 4:
			cout << "Generating 4mirs modules...\n";
			identify_4mirs_modules();
			break;
		case 5:
			cout << "Generating 5mirs modules...\n";
			identify_5mirs_modules();
			break;
		case 6:
			cout << "Generating 6mirs modules...\n";
			identify_6mirs_modules();
			break;
		case 7:
			cout << "Generating 7mirs modules...\n";
			identify_7mirs_modules();
			break;
		case 8:
			cout << "Generating 8mirs modules...\n";
			identify_8mirs_modules();
			break;
		case 9:
			cout << "Generating 9mirs modules...\n";
			identify_9mirs_modules();
			break;
		case 10:
			cout << "Generating 10mirs modules...\n";
			identify_10mirs_modules();
			break;
		case 11:
			cout << "Generating 11mirs modules...\n";
			identify_11mirs_modules();
			break;
		case 12:
			cout << "Generating 12mirs modules...\n";
			identify_12mirs_modules();
			break;
		case 13:
			cout << "Generating 13mirs modules...\n";
			identify_13mirs_modules();
			break;
		case 14:
			cout << "Generating 14mirs modules...\n";
			identify_14mirs_modules();
			break;
		case 15:
			cout << "Generating 15mirs modules...\n";
			identify_15mirs_modules();
			break;
		case 16:
			cout << "Generating 16mirs modules...\n";
			identify_16mirs_modules();
			break;
		case 17:
			cout << "Generating 17mirs modules...\n";
			identify_17mirs_modules();
			break;
		case 18:
			cout << "Generating 18mirs modules...\n";
			identify_18mirs_modules();
			break;
		case 19:
			cout << "Generating 19mirs modules...\n";
			identify_19mirs_modules();
			break;
		case 20:
			cout << "Generating 20mirs modules...\n";
			identify_20mirs_modules();
			break;
		case 21:
			cout << "Generating 21mirs modules...\n";
			identify_21mirs_modules();
			break;
		case 22:
			cout << "Generating 22mirs modules...\n";
			identify_22mirs_modules();
			break;
		case 23:
			cout << "Generating 23mirs modules...\n";
			identify_23mirs_modules();
			break;
		case 24:
			cout << "Generating 24mirs modules...\n";
			identify_24mirs_modules();
			break;
		case 25:
			cout << "Generating 25mirs modules...\n";
			identify_25mirs_modules();
			break;
		case 26:
			cout << "Generating 26mirs modules...\n";
			identify_26mirs_modules();
			break;
		case 27:
			cout << "Generating 27mirs modules...\n";
			identify_27mirs_modules();
			break;
		case 28:
			cout << "Generating 28mirs modules...\n";
			identify_28mirs_modules();
			break;
		case 29:
			cout << "Generating 29mirs modules...\n";
			identify_29mirs_modules();
			break;
		case 30:
			cout << "Generating 30mirs modules...\n";
			identify_30mirs_modules();
			break;
		default:
			cout << "Invalid number of modules!\n";

	}
	cout << "DONE!\n";

}


//Print common targets of 2 mirs
void identify_2mirs_modules()
{
	ofstream fs2;
	fs2.open("./data/aux/modules_2mirs.csv");
	//fs2 << "Number of common targets, mir 1, mir 2, , Targets\n";
	for (int w1=0; w1< MAX_MIRS; w1++){
		for (int w2=w1+1; w2< MAX_MIRS; w2++){
			bitset<MAX_GENES> inter =  mt_map.map[w1] &  mt_map.map[w2]; 
			int nr_intersec = inter.count();	
			if (nr_intersec > minTargets){
				target_names = "";
			    mir_names = "";
				for (std::size_t b=0; b<inter.size(); ++b){
    				if (inter.test(b)){
						target_names +=  mt_map.targets[(MAX_GENES-1 - b)].get_refseq();
						target_names += ",";
					}
				}		
				fs2 << nr_intersec << "," ;
				mir_names +=  mt_map.mirs[w1].get_name();  mir_names += ",";
				mir_names +=  mt_map.mirs[w2].get_name();  mir_names += ",";
				fs2 << mir_names << "," << target_names << "\n";
			}
		}
	} 
	fs2.close();
}

//Print common targets of 3 mirs
void identify_3mirs_modules()
{
	ofstream fs3;
	fs3.open("./data/aux/modules_3mirs.csv");

	for (int w1=0; w1< MAX_MIRS; w1++){
		for (int w2=w1+1; w2< MAX_MIRS; w2++){
			for (int w3=w2+1; w3< MAX_MIRS; w3++){
				std::bitset<MAX_GENES> inter =  mt_map.map[w1] & mt_map.map[w2] & mt_map.map[w3]; 
				int nr_intersec = inter.count();	
				if (nr_intersec > minTargets){
					target_names = "";
			   		mir_names = "";
					for (std::size_t b=0; b<inter.size(); ++b){
    					if (inter.test(b)){
							target_names += mt_map.targets[(MAX_GENES-1 - b)].get_refseq();
							target_names += ",";
						}
					}			
					fs3 << nr_intersec << "," ;
					mir_names += mt_map.mirs[w1].get_name();  mir_names += ",";
					mir_names += mt_map.mirs[w2].get_name();  mir_names += ",";
					mir_names += mt_map.mirs[w3].get_name();  mir_names += ",";
					fs3 << mir_names << "," << target_names << "\n";
				}
			}
		}
	} 
	fs3.close();
}

//Print common targets of 4 mirs
void identify_4mirs_modules()
{
	ofstream fs4;
	fs4.open("./data/aux/modules_4mirs.csv");

	for (int w1=0; w1< MAX_MIRS; w1++){
		for (int w2=w1+1; w2< MAX_MIRS; w2++){
			std::bitset<MAX_GENES> inter = mt_map.map[w1] & mt_map.map[w2]; 
			if (inter.count() > 0){
			for (int w3=w2+1; w3< MAX_MIRS; w3++){
				inter = mt_map.map[w1] & mt_map.map[w2] & mt_map.map[w3];
				if (inter.count() > 0){
				for (int w4=w3+1; w4< MAX_MIRS; w4++){
					inter = mt_map.map[w1] & mt_map.map[w2] & mt_map.map[w3] & mt_map.map[w4];
					int nr_intersec = inter.count();
					if (nr_intersec > minTargets){
						target_names = "";
						mir_names = "";
						for (std::size_t b=0; b<inter.size(); ++b){
    						if (inter.test(b)){
							target_names += mt_map.targets[(MAX_GENES-1 - b)].get_refseq();
								target_names += ",";
							}
						}		
						fs4 << nr_intersec << ",";
					 	mir_names += mt_map.mirs[w1].get_name();  mir_names += ",";
					 	mir_names += mt_map.mirs[w2].get_name();  mir_names += ",";
					 	mir_names += mt_map.mirs[w3].get_name();  mir_names += ",";
					 	mir_names += mt_map.mirs[w4].get_name();  mir_names += ","; 
						fs4 << mir_names << target_names << "\n";
					}
				}}
			}}
		}
	}

	fs4.close();
}

//Print common targets of 5 mirs
void identify_5mirs_modules()
{
	ofstream fs5;
	fs5.open("./data/aux/modules_5mirs.csv");

	for (int w1=0; w1< MAX_MIRS; w1++){
		for (int w2=w1+1; w2< MAX_MIRS; w2++){
			std::bitset<MAX_GENES> inter = mt_map.map[w1] & mt_map.map[w2]; 
			if (inter.count() > 0){
			for (int w3=w2+1; w3< MAX_MIRS; w3++){
				inter = mt_map.map[w1] & mt_map.map[w2] & mt_map.map[w3];
				if (inter.count() > 0){
				for (int w4=w3+1; w4< MAX_MIRS; w4++){
					inter = mt_map.map[w1] & mt_map.map[w2] & mt_map.map[w3] & mt_map.map[w4];
					if (inter.count() > 0){
					for (int w5=w4+1; w5< MAX_MIRS; w5++){
						inter = mt_map.map[w1] & mt_map.map[w2] & mt_map.map[w3] & mt_map.map[w4]
						 & mt_map.map[w5];
						int nr_intersec = inter.count();
						if (nr_intersec > minTargets){
							target_names = "";
							mir_names = "";
							for (std::size_t b=0; b<inter.size(); ++b){
    							if (inter.test(b)){
								target_names += mt_map.targets[(MAX_GENES-1 - b)].get_refseq();
								target_names += ",";
								}
							}		
							fs5 << nr_intersec << ",";
					 		mir_names += mt_map.mirs[w1].get_name();  mir_names += ",";
					 		mir_names += mt_map.mirs[w2].get_name();  mir_names += ",";
					 		mir_names += mt_map.mirs[w3].get_name();  mir_names += ",";
					 		mir_names += mt_map.mirs[w4].get_name();  mir_names += ","; 
					 		mir_names += mt_map.mirs[w5].get_name();  mir_names += ","; 
							fs5 << mir_names << target_names << "\n";
						}
					}}
				}}
			}}
		}
	}

	fs5.close();
}

//Print common targets of 6 mirs
void identify_6mirs_modules()
{
	ofstream fs6;
	fs6.open("./data/aux/modules_6mirs.csv");

	std::bitset<MAX_GENES> inter2, inter3, inter4, inter5, inter6;
	for (int w1=0; w1< MAX_MIRS; w1++){
		for (int w2=w1+1; w2< MAX_MIRS; w2++){
			inter2 = mt_map.map[w1] & mt_map.map[w2]; 
			if (inter2.count() > 0){
			for (int w3=w2+1; w3< MAX_MIRS; w3++){
				inter3 = inter2 & mt_map.map[w3];
				if (inter3.count() > 0){
				for (int w4=w3+1; w4< MAX_MIRS; w4++){
					inter4 = inter3 & mt_map.map[w4];
					if (inter4.count() > 0){
					for (int w5=w4+1; w5< MAX_MIRS; w5++){
						inter5 = inter4 & mt_map.map[w5];
						if (inter5.count() > 0){
						for (int w6=w5+1; w6< MAX_MIRS; w6++){
							inter6 = inter5 & mt_map.map[w6];
											int nr_intersec = inter6.count();
											if (nr_intersec > minTargets){
												target_names = "";
												mir_names = "";
												for (std::size_t b=0; b<inter6.size(); ++b){ // *****
    												if (inter6.test(b)){ // *****
														target_names += mt_map.targets[(MAX_GENES-1 - b)].get_refseq();
														target_names += ",";
												}}		
												fs6 << nr_intersec << ",";
					 							mir_names += mt_map.mirs[w1].get_name();  mir_names += ",";
					 							mir_names += mt_map.mirs[w2].get_name();  mir_names += ",";
					 							mir_names += mt_map.mirs[w3].get_name();  mir_names += ",";
					 							mir_names += mt_map.mirs[w4].get_name();  mir_names += ","; 
					 							mir_names += mt_map.mirs[w5].get_name();  mir_names += ","; 
					 							mir_names += mt_map.mirs[w6].get_name();  mir_names += ",";
												fs6 << mir_names << target_names << "\n";
											}
						}}
					}}
				}}
			}}
		}
	}

	fs6.close();
}

//Print common targets of 7 mirs
void identify_7mirs_modules()
{
	ofstream fs7;
	fs7.open("./data/aux/modules_7mirs.csv");

	std::bitset<MAX_GENES> inter2, inter3, inter4, inter5, inter6, inter7;
	for (int w1=0; w1< MAX_MIRS; w1++){
		for (int w2=w1+1; w2< MAX_MIRS; w2++){
			inter2 = mt_map.map[w1] & mt_map.map[w2]; 
			if (inter2.count() > 0){
			for (int w3=w2+1; w3< MAX_MIRS; w3++){
				inter3 = inter2 & mt_map.map[w3];
				if (inter3.count() > 0){
				for (int w4=w3+1; w4< MAX_MIRS; w4++){
					inter4 = inter3 & mt_map.map[w4];
					if (inter4.count() > 0){
					for (int w5=w4+1; w5< MAX_MIRS; w5++){
						inter5 = inter4 & mt_map.map[w5];
						if (inter5.count() > 0){
						for (int w6=w5+1; w6< MAX_MIRS; w6++){
							inter6 = inter5 & mt_map.map[w6];
							if (inter6.count() > 0){
							for (int w7=w6+1; w7< MAX_MIRS; w7++){
								inter7 = inter6 & mt_map.map[w7];
											int nr_intersec = inter7.count();
											if (nr_intersec > minTargets){
												target_names = "";
												mir_names = "";
												for (std::size_t b=0; b<inter7.size(); ++b){ // *****
    												if (inter7.test(b)){ // *****
														target_names += mt_map.targets[(MAX_GENES-1 - b)].get_refseq();
														target_names += ",";
												}}		
												fs7 << nr_intersec << ",";
					 							mir_names += mt_map.mirs[w1].get_name();  mir_names += ",";
					 							mir_names += mt_map.mirs[w2].get_name();  mir_names += ",";
					 							mir_names += mt_map.mirs[w3].get_name();  mir_names += ",";
					 							mir_names += mt_map.mirs[w4].get_name();  mir_names += ","; 
					 							mir_names += mt_map.mirs[w5].get_name();  mir_names += ","; 
					 							mir_names += mt_map.mirs[w6].get_name();  mir_names += ",";
					 							mir_names += mt_map.mirs[w7].get_name();  mir_names += ",";
												fs7 << mir_names << target_names << "\n";
											}
							}}
						}}
					}}
				}}
			}}
		}
	}

	fs7.close();
}

//Print common targets of 8 mirs
void identify_8mirs_modules()
{
	ofstream fs8;
	fs8.open("./data/aux/modules_8mirs.csv");

	std::bitset<MAX_GENES> inter2, inter3, inter4, inter5, inter6, inter7, inter8;
	for (int w1=0; w1< MAX_MIRS; w1++){
		for (int w2=w1+1; w2< MAX_MIRS; w2++){
			inter2 = mt_map.map[w1] & mt_map.map[w2]; 
			if (inter2.count() > 0){
			for (int w3=w2+1; w3< MAX_MIRS; w3++){
				inter3 = inter2 & mt_map.map[w3];
				if (inter3.count() > 0){
				for (int w4=w3+1; w4< MAX_MIRS; w4++){
					inter4 = inter3 & mt_map.map[w4];
					if (inter4.count() > 0){
					for (int w5=w4+1; w5< MAX_MIRS; w5++){
						inter5 = inter4 & mt_map.map[w5];
						if (inter5.count() > 0){
						for (int w6=w5+1; w6< MAX_MIRS; w6++){
							inter6 = inter5 & mt_map.map[w6];
							if (inter6.count() > 0){
							for (int w7=w6+1; w7< MAX_MIRS; w7++){
								inter7 = inter6 & mt_map.map[w7];
								if (inter7.count() > 0){
								for (int w8=w7+1; w8< MAX_MIRS; w8++){
									inter8 = inter7 & mt_map.map[w8];
											int nr_intersec = inter8.count();
											if (nr_intersec > minTargets){
												target_names = "";
												mir_names = "";
												for (std::size_t b=0; b<inter8.size(); ++b){ // *****
    												if (inter8.test(b)){ // *****
														target_names += mt_map.targets[(MAX_GENES-1 - b)].get_refseq();
														target_names += ",";
												}}		
												fs8 << nr_intersec << ",";
					 							mir_names += mt_map.mirs[w1].get_name();  mir_names += ",";
					 							mir_names += mt_map.mirs[w2].get_name();  mir_names += ",";
					 							mir_names += mt_map.mirs[w3].get_name();  mir_names += ",";
					 							mir_names += mt_map.mirs[w4].get_name();  mir_names += ","; 
					 							mir_names += mt_map.mirs[w5].get_name();  mir_names += ","; 
					 							mir_names += mt_map.mirs[w6].get_name();  mir_names += ",";
					 							mir_names += mt_map.mirs[w7].get_name();  mir_names += ",";
					 							mir_names += mt_map.mirs[w8].get_name();  mir_names += ",";
												fs8 << mir_names << target_names << "\n";
											}
								}}
							}}
						}}
					}}
				}}
			}}
		}
	}

	fs8.close();
}

//Print common targets of 9 mirs
void identify_9mirs_modules()
{
	ofstream fs9;
	fs9.open("./data/aux/modules_9mirs.csv");

	std::bitset<MAX_GENES> inter2, inter3, inter4, inter5, inter6, inter7, inter8, inter9;
	for (int w1=0; w1< MAX_MIRS; w1++){
		for (int w2=w1+1; w2< MAX_MIRS; w2++){
			inter2 = mt_map.map[w1] & mt_map.map[w2]; 
			if (inter2.count() > 0){
			for (int w3=w2+1; w3< MAX_MIRS; w3++){
				inter3 = inter2 & mt_map.map[w3];
				if (inter3.count() > 0){
				for (int w4=w3+1; w4< MAX_MIRS; w4++){
					inter4 = inter3 & mt_map.map[w4];
					if (inter4.count() > 0){
					for (int w5=w4+1; w5< MAX_MIRS; w5++){
						inter5 = inter4 & mt_map.map[w5];
						if (inter5.count() > 0){
						for (int w6=w5+1; w6< MAX_MIRS; w6++){
							inter6 = inter5 & mt_map.map[w6];
							if (inter6.count() > 0){
							for (int w7=w6+1; w7< MAX_MIRS; w7++){
								inter7 = inter6 & mt_map.map[w7];
								if (inter7.count() > 0){
								for (int w8=w7+1; w8< MAX_MIRS; w8++){
									inter8 = inter7 & mt_map.map[w8];
									if (inter8.count() > 0){
									for (int w9=w8+1; w9< MAX_MIRS; w9++){
										inter9 = inter8 & mt_map.map[w9];
											int nr_intersec = inter9.count();
											if (nr_intersec > minTargets){
												target_names = "";
												mir_names = "";
												for (std::size_t b=0; b<inter9.size(); ++b){ // *****
    												if (inter9.test(b)){ // *****
														target_names += mt_map.targets[(MAX_GENES-1 - b)].get_refseq();
														target_names += ",";
												}}		
												fs9 << nr_intersec << ",";
					 							mir_names += mt_map.mirs[w1].get_name();  mir_names += ",";
					 							mir_names += mt_map.mirs[w2].get_name();  mir_names += ",";
					 							mir_names += mt_map.mirs[w3].get_name();  mir_names += ",";
					 							mir_names += mt_map.mirs[w4].get_name();  mir_names += ","; 
					 							mir_names += mt_map.mirs[w5].get_name();  mir_names += ","; 
					 							mir_names += mt_map.mirs[w6].get_name();  mir_names += ",";
					 							mir_names += mt_map.mirs[w7].get_name();  mir_names += ",";
					 							mir_names += mt_map.mirs[w8].get_name();  mir_names += ",";
					 							mir_names += mt_map.mirs[w9].get_name();  mir_names += ","; 
												fs9 << mir_names << target_names << "\n";
											}
									}}
								}}
							}}
						}}
					}}
				}}
			}}
		}
	}

	fs9.close();
}

//Print common targets of 10 mirs
void identify_10mirs_modules()
{
	ofstream fs10;
	fs10.open("./data/aux/modules_10mirs.csv");

	std::bitset<MAX_GENES> inter2, inter3, inter4, inter5, inter6, inter7, inter8, inter9, inter10;
	for (int w1=0; w1< MAX_MIRS; w1++){
		for (int w2=w1+1; w2< MAX_MIRS; w2++){
			inter2 = mt_map.map[w1] & mt_map.map[w2]; 
			if (inter2.count() > 0){
			for (int w3=w2+1; w3< MAX_MIRS; w3++){
				inter3 = inter2 & mt_map.map[w3];
				if (inter3.count() > 0){
				for (int w4=w3+1; w4< MAX_MIRS; w4++){
					inter4 = inter3 & mt_map.map[w4];
					if (inter4.count() > 0){
					for (int w5=w4+1; w5< MAX_MIRS; w5++){
						inter5 = inter4 & mt_map.map[w5];
						if (inter5.count() > 0){
						for (int w6=w5+1; w6< MAX_MIRS; w6++){
							inter6 = inter5 & mt_map.map[w6];
							if (inter6.count() > 0){
							for (int w7=w6+1; w7< MAX_MIRS; w7++){
								inter7 = inter6 & mt_map.map[w7];
								if (inter7.count() > 0){
								for (int w8=w7+1; w8< MAX_MIRS; w8++){
									inter8 = inter7 & mt_map.map[w8];
									if (inter8.count() > 0){
									for (int w9=w8+1; w9< MAX_MIRS; w9++){
										inter9 = inter8 & mt_map.map[w9];
										if (inter9.count() > 0){
										for (int w10=w9+1; w10< MAX_MIRS; w10++){
											inter10 = inter9 & mt_map.map[w10];
											int nr_intersec = inter10.count();
											if (nr_intersec > minTargets){
												target_names = "";
												mir_names = "";
												for (std::size_t b=0; b<inter10.size(); ++b){ // *****
    												if (inter10.test(b)){ // *****
														target_names += mt_map.targets[(MAX_GENES-1 - b)].get_refseq();
														target_names += ",";
												}}		
												fs10 << nr_intersec << ",";
					 							mir_names += mt_map.mirs[w1].get_name();  mir_names += ",";
					 							mir_names += mt_map.mirs[w2].get_name();  mir_names += ",";
					 							mir_names += mt_map.mirs[w3].get_name();  mir_names += ",";
					 							mir_names += mt_map.mirs[w4].get_name();  mir_names += ","; 
					 							mir_names += mt_map.mirs[w5].get_name();  mir_names += ","; 
					 							mir_names += mt_map.mirs[w6].get_name();  mir_names += ",";
					 							mir_names += mt_map.mirs[w7].get_name();  mir_names += ",";
					 							mir_names += mt_map.mirs[w8].get_name();  mir_names += ",";
					 							mir_names += mt_map.mirs[w9].get_name();  mir_names += ","; 
					 							mir_names += mt_map.mirs[w10].get_name();  mir_names += ","; 
												fs10 << mir_names << target_names << "\n";
											}
										}}
									}}
								}}
							}}
						}}
					}}
				}}
			}}
		}
	}

	fs10.close();
}

//Print common targets of 11 mirs
void identify_11mirs_modules()
{
	ofstream fs11;
	fs11.open("./data/aux/modules_11mirs.csv");

	std::bitset<MAX_GENES> inter2, inter3, inter4, inter5, inter6, inter7, inter8, inter9, inter10, inter11;
	for (int w1=0; w1< MAX_MIRS; w1++){
		for (int w2=w1+1; w2< MAX_MIRS; w2++){
			inter2 = mt_map.map[w1] & mt_map.map[w2]; 
			if (inter2.count() > 0){
			for (int w3=w2+1; w3< MAX_MIRS; w3++){
				inter3 = inter2 & mt_map.map[w3];
				if (inter3.count() > 0){
				for (int w4=w3+1; w4< MAX_MIRS; w4++){
					inter4 = inter3 & mt_map.map[w4];
					if (inter4.count() > 0){
					for (int w5=w4+1; w5< MAX_MIRS; w5++){
						inter5 = inter4 & mt_map.map[w5];
						if (inter5.count() > 0){
						for (int w6=w5+1; w6< MAX_MIRS; w6++){
							inter6 = inter5 & mt_map.map[w6];
							if (inter6.count() > 0){
							for (int w7=w6+1; w7< MAX_MIRS; w7++){
								inter7 = inter6 & mt_map.map[w7];
								if (inter7.count() > 0){
								for (int w8=w7+1; w8< MAX_MIRS; w8++){
									inter8 = inter7 & mt_map.map[w8];
									if (inter8.count() > 0){
									for (int w9=w8+1; w9< MAX_MIRS; w9++){
										inter9 = inter8 & mt_map.map[w9];
										if (inter9.count() > 0){
										for (int w10=w9+1; w10< MAX_MIRS; w10++){
											inter10 = inter9 & mt_map.map[w10];
											if (inter10.count() > 0){
											for (int w11=w10+1; w11< MAX_MIRS; w11++){
												inter11 = inter10 & mt_map.map[w11];
																					int nr_intersec = inter11.count();
																					if (nr_intersec > minTargets){
																						target_names = "";
																						mir_names = "";
																						for (std::size_t b=0; b<inter11.size(); ++b){ // ****
    																					if (inter11.test(b)){ //  *****
																							target_names += mt_map.targets[(MAX_GENES-1 - b)].get_refseq();
																							target_names += ",";
																						}}		
																						fs11 << nr_intersec << ",";
					 																	mir_names += mt_map.mirs[w1].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w2].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w3].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w4].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w5].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w6].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w7].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w8].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w9].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w10].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w11].get_name();  mir_names += ",";
																						fs11 << mir_names << target_names << "\n";
																					}
											}}
										}}
									}}
								}}
							}}
						}}
					}}
				}}
			}}
		}
	}

	fs11.close();
}

//Print common targets of 12 mirs
void identify_12mirs_modules()
{
	ofstream fs12;
	fs12.open("./data/aux/modules_12mirs.csv");

	std::bitset<MAX_GENES> inter2, inter3, inter4, inter5, inter6, inter7, inter8, inter9, inter10, inter11, inter12;
	for (int w1=0; w1< MAX_MIRS; w1++){
		for (int w2=w1+1; w2< MAX_MIRS; w2++){
			inter2 = mt_map.map[w1] & mt_map.map[w2]; 
			if (inter2.count() > 0){
			for (int w3=w2+1; w3< MAX_MIRS; w3++){
				inter3 = inter2 & mt_map.map[w3];
				if (inter3.count() > 0){
				for (int w4=w3+1; w4< MAX_MIRS; w4++){
					inter4 = inter3 & mt_map.map[w4];
					if (inter4.count() > 0){
					for (int w5=w4+1; w5< MAX_MIRS; w5++){
						inter5 = inter4 & mt_map.map[w5];
						if (inter5.count() > 0){
						for (int w6=w5+1; w6< MAX_MIRS; w6++){
							inter6 = inter5 & mt_map.map[w6];
							if (inter6.count() > 0){
							for (int w7=w6+1; w7< MAX_MIRS; w7++){
								inter7 = inter6 & mt_map.map[w7];
								if (inter7.count() > 0){
								for (int w8=w7+1; w8< MAX_MIRS; w8++){
									inter8 = inter7 & mt_map.map[w8];
									if (inter8.count() > 0){
									for (int w9=w8+1; w9< MAX_MIRS; w9++){
										inter9 = inter8 & mt_map.map[w9];
										if (inter9.count() > 0){
										for (int w10=w9+1; w10< MAX_MIRS; w10++){
											inter10 = inter9 & mt_map.map[w10];
											if (inter10.count() > 0){
											for (int w11=w10+1; w11< MAX_MIRS; w11++){
												inter11 = inter10 & mt_map.map[w11];
												if (inter11.count() > 0){
												for (int w12=w11+1; w12< MAX_MIRS; w12++){
													inter12 = inter11 & mt_map.map[w12];
																					int nr_intersec = inter12.count();
																					if (nr_intersec > minTargets){
																						target_names = "";
																						mir_names = "";
																						for (std::size_t b=0; b<inter12.size(); ++b){ // ****
    																					if (inter12.test(b)){ //  *****
																							target_names += mt_map.targets[(MAX_GENES-1 - b)].get_refseq();
																							target_names += ",";
																						}}		
																						fs12 << nr_intersec << ",";
					 																	mir_names += mt_map.mirs[w1].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w2].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w3].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w4].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w5].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w6].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w7].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w8].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w9].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w10].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w11].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w12].get_name();  mir_names += ",";
																						fs12 << mir_names << target_names << "\n";
																					}
												}}
											}}
										}}
									}}
								}}
							}}
						}}
					}}
				}}
			}}
		}
	}

	fs12.close();
}

//Print common targets of 13 mirs
void identify_13mirs_modules()
{
	ofstream fs13;
	fs13.open("./data/aux/modules_13mirs.csv");

	std::bitset<MAX_GENES> inter2, inter3, inter4, inter5, inter6, inter7, inter8, inter9, inter10, inter11, inter12, inter13;
	for (int w1=0; w1< MAX_MIRS; w1++){
		for (int w2=w1+1; w2< MAX_MIRS; w2++){
			inter2 = mt_map.map[w1] & mt_map.map[w2]; 
			if (inter2.count() > 0){
			for (int w3=w2+1; w3< MAX_MIRS; w3++){
				inter3 = inter2 & mt_map.map[w3];
				if (inter3.count() > 0){
				for (int w4=w3+1; w4< MAX_MIRS; w4++){
					inter4 = inter3 & mt_map.map[w4];
					if (inter4.count() > 0){
					for (int w5=w4+1; w5< MAX_MIRS; w5++){
						inter5 = inter4 & mt_map.map[w5];
						if (inter5.count() > 0){
						for (int w6=w5+1; w6< MAX_MIRS; w6++){
							inter6 = inter5 & mt_map.map[w6];
							if (inter6.count() > 0){
							for (int w7=w6+1; w7< MAX_MIRS; w7++){
								inter7 = inter6 & mt_map.map[w7];
								if (inter7.count() > 0){
								for (int w8=w7+1; w8< MAX_MIRS; w8++){
									inter8 = inter7 & mt_map.map[w8];
									if (inter8.count() > 0){
									for (int w9=w8+1; w9< MAX_MIRS; w9++){
										inter9 = inter8 & mt_map.map[w9];
										if (inter9.count() > 0){
										for (int w10=w9+1; w10< MAX_MIRS; w10++){
											inter10 = inter9 & mt_map.map[w10];
											if (inter10.count() > 0){
											for (int w11=w10+1; w11< MAX_MIRS; w11++){
												inter11 = inter10 & mt_map.map[w11];
												if (inter11.count() > 0){
												for (int w12=w11+1; w12< MAX_MIRS; w12++){
													inter12 = inter11 & mt_map.map[w12];
													if (inter12.count() > 0){
													for (int w13=w12+1; w13< MAX_MIRS; w13++){
														inter13 = inter12 & mt_map.map[w13];
																					int nr_intersec = inter13.count();
																					if (nr_intersec > minTargets){
																						target_names = "";
																						mir_names = "";
																						for (std::size_t b=0; b<inter13.size(); ++b){ // ****
    																					if (inter13.test(b)){ //  *****
																							target_names += mt_map.targets[(MAX_GENES-1 - b)].get_refseq();
																							target_names += ",";
																						}}		
																						fs13 << nr_intersec << ",";
					 																	mir_names += mt_map.mirs[w1].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w2].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w3].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w4].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w5].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w6].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w7].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w8].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w9].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w10].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w11].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w12].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w13].get_name();  mir_names += ",";
																						fs13 << mir_names << target_names << "\n";
																					}
													}}
												}}
											}}
										}}
									}}
								}}
							}}
						}}
					}}
				}}
			}}
		}
	}

	fs13.close();
}

//Print common targets of 14 mirs
void identify_14mirs_modules()
{
	ofstream fs14;
	fs14.open("./data/aux/modules_14mirs.csv");

	std::bitset<MAX_GENES> inter2, inter3, inter4, inter5, inter6, inter7, inter8, inter9, inter10, inter11, inter12, inter13, inter14;
	for (int w1=0; w1< MAX_MIRS; w1++){
		for (int w2=w1+1; w2< MAX_MIRS; w2++){
			inter2 = mt_map.map[w1] & mt_map.map[w2]; 
			if (inter2.count() > 0){
			for (int w3=w2+1; w3< MAX_MIRS; w3++){
				inter3 = inter2 & mt_map.map[w3];
				if (inter3.count() > 0){
				for (int w4=w3+1; w4< MAX_MIRS; w4++){
					inter4 = inter3 & mt_map.map[w4];
					if (inter4.count() > 0){
					for (int w5=w4+1; w5< MAX_MIRS; w5++){
						inter5 = inter4 & mt_map.map[w5];
						if (inter5.count() > 0){
						for (int w6=w5+1; w6< MAX_MIRS; w6++){
							inter6 = inter5 & mt_map.map[w6];
							if (inter6.count() > 0){
							for (int w7=w6+1; w7< MAX_MIRS; w7++){
								inter7 = inter6 & mt_map.map[w7];
								if (inter7.count() > 0){
								for (int w8=w7+1; w8< MAX_MIRS; w8++){
									inter8 = inter7 & mt_map.map[w8];
									if (inter8.count() > 0){
									for (int w9=w8+1; w9< MAX_MIRS; w9++){
										inter9 = inter8 & mt_map.map[w9];
										if (inter9.count() > 0){
										for (int w10=w9+1; w10< MAX_MIRS; w10++){
											inter10 = inter9 & mt_map.map[w10];
											if (inter10.count() > 0){
											for (int w11=w10+1; w11< MAX_MIRS; w11++){
												inter11 = inter10 & mt_map.map[w11];
												if (inter11.count() > 0){
												for (int w12=w11+1; w12< MAX_MIRS; w12++){
													inter12 = inter11 & mt_map.map[w12];
													if (inter12.count() > 0){
													for (int w13=w12+1; w13< MAX_MIRS; w13++){
														inter13 = inter12 & mt_map.map[w13];
														if (inter13.count() > 0){
														for (int w14=w13+1; w14< MAX_MIRS; w14++){
															inter14 = inter13 & mt_map.map[w14];
																					int nr_intersec = inter14.count();
																					if (nr_intersec > minTargets){
																						target_names = "";
																						mir_names = "";
																						for (std::size_t b=0; b<inter14.size(); ++b){ // ****
    																					if (inter14.test(b)){ //  *****
																							target_names += mt_map.targets[(MAX_GENES-1 - b)].get_refseq();
																							target_names += ",";
																						}}		
																						fs14 << nr_intersec << ",";
					 																	mir_names += mt_map.mirs[w1].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w2].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w3].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w4].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w5].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w6].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w7].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w8].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w9].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w10].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w11].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w12].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w13].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w14].get_name();  mir_names += ","; 
																						fs14 << mir_names << target_names << "\n";
																					}
														}}
													}}
												}}
											}}
										}}
									}}
								}}
							}}
						}}
					}}
				}}
			}}
		}
	}

	fs14.close();
}

//Print common targets of 15 mirs
void identify_15mirs_modules()
{
	ofstream fs15;
	fs15.open("./data/aux/modules_15mirs.csv");

	std::bitset<MAX_GENES> inter2, inter3, inter4, inter5, inter6, inter7, inter8, inter9, inter10, inter11, inter12, inter13, inter14, inter15;
	for (int w1=0; w1< MAX_MIRS; w1++){
		for (int w2=w1+1; w2< MAX_MIRS; w2++){
			inter2 = mt_map.map[w1] & mt_map.map[w2]; 
			if (inter2.count() > 0){
			for (int w3=w2+1; w3< MAX_MIRS; w3++){
				inter3 = inter2 & mt_map.map[w3];
				if (inter3.count() > 0){
				for (int w4=w3+1; w4< MAX_MIRS; w4++){
					inter4 = inter3 & mt_map.map[w4];
					if (inter4.count() > 0){
					for (int w5=w4+1; w5< MAX_MIRS; w5++){
						inter5 = inter4 & mt_map.map[w5];
						if (inter5.count() > 0){
						for (int w6=w5+1; w6< MAX_MIRS; w6++){
							inter6 = inter5 & mt_map.map[w6];
							if (inter6.count() > 0){
							for (int w7=w6+1; w7< MAX_MIRS; w7++){
								inter7 = inter6 & mt_map.map[w7];
								if (inter7.count() > 0){
								for (int w8=w7+1; w8< MAX_MIRS; w8++){
									inter8 = inter7 & mt_map.map[w8];
									if (inter8.count() > 0){
									for (int w9=w8+1; w9< MAX_MIRS; w9++){
										inter9 = inter8 & mt_map.map[w9];
										if (inter9.count() > 0){
										for (int w10=w9+1; w10< MAX_MIRS; w10++){
											inter10 = inter9 & mt_map.map[w10];
											if (inter10.count() > 0){
											for (int w11=w10+1; w11< MAX_MIRS; w11++){
												inter11 = inter10 & mt_map.map[w11];
												if (inter11.count() > 0){
												for (int w12=w11+1; w12< MAX_MIRS; w12++){
													inter12 = inter11 & mt_map.map[w12];
													if (inter12.count() > 0){
													for (int w13=w12+1; w13< MAX_MIRS; w13++){
														inter13 = inter12 & mt_map.map[w13];
														if (inter13.count() > 0){
														for (int w14=w13+1; w14< MAX_MIRS; w14++){
															inter14 = inter13 & mt_map.map[w14];
															if (inter14.count() > 0){
															for (int w15=w14+1; w15< MAX_MIRS; w15++){
																inter15 = inter14 & mt_map.map[w15];
																					int nr_intersec = inter15.count();
																					if (nr_intersec > minTargets){
																						target_names = "";
																						mir_names = "";
																						for (std::size_t b=0; b<inter15.size(); ++b){ // ****
    																					if (inter15.test(b)){ //  *****
																							target_names += mt_map.targets[(MAX_GENES-1 - b)].get_refseq();
																							target_names += ",";
																						}}		
																						fs15 << nr_intersec << ",";
					 																	mir_names += mt_map.mirs[w1].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w2].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w3].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w4].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w5].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w6].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w7].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w8].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w9].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w10].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w11].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w12].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w13].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w14].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w15].get_name();  mir_names += ","; 
																						fs15 << mir_names << target_names << "\n";
																					}
															}}
														}}
													}}
												}}
											}}
										}}
									}}
								}}
							}}
						}}
					}}
				}}
			}}
		}
	}


	fs15.close();
}

//Print common targets of 16 mirs
void identify_16mirs_modules()
{
	ofstream fs16;
	fs16.open("./data/aux/modules_16mirs.csv");

	std::bitset<MAX_GENES> inter2, inter3, inter4, inter5, inter6, inter7, inter8, inter9, inter10, inter11, inter12, inter13, inter14, inter15, inter16;
	for (int w1=0; w1< MAX_MIRS; w1++){
		for (int w2=w1+1; w2< MAX_MIRS; w2++){
			inter2 = mt_map.map[w1] & mt_map.map[w2]; 
			if (inter2.count() > 0){
			for (int w3=w2+1; w3< MAX_MIRS; w3++){
				inter3 = inter2 & mt_map.map[w3];
				if (inter3.count() > 0){
				for (int w4=w3+1; w4< MAX_MIRS; w4++){
					inter4 = inter3 & mt_map.map[w4];
					if (inter4.count() > 0){
					for (int w5=w4+1; w5< MAX_MIRS; w5++){
						inter5 = inter4 & mt_map.map[w5];
						if (inter5.count() > 0){
						for (int w6=w5+1; w6< MAX_MIRS; w6++){
							inter6 = inter5 & mt_map.map[w6];
							if (inter6.count() > 0){
							for (int w7=w6+1; w7< MAX_MIRS; w7++){
								inter7 = inter6 & mt_map.map[w7];
								if (inter7.count() > 0){
								for (int w8=w7+1; w8< MAX_MIRS; w8++){
									inter8 = inter7 & mt_map.map[w8];
									if (inter8.count() > 0){
									for (int w9=w8+1; w9< MAX_MIRS; w9++){
										inter9 = inter8 & mt_map.map[w9];
										if (inter9.count() > 0){
										for (int w10=w9+1; w10< MAX_MIRS; w10++){
											inter10 = inter9 & mt_map.map[w10];
											if (inter10.count() > 0){
											for (int w11=w10+1; w11< MAX_MIRS; w11++){
												inter11 = inter10 & mt_map.map[w11];
												if (inter11.count() > 0){
												for (int w12=w11+1; w12< MAX_MIRS; w12++){
													inter12 = inter11 & mt_map.map[w12];
													if (inter12.count() > 0){
													for (int w13=w12+1; w13< MAX_MIRS; w13++){
														inter13 = inter12 & mt_map.map[w13];
														if (inter13.count() > 0){
														for (int w14=w13+1; w14< MAX_MIRS; w14++){
															inter14 = inter13 & mt_map.map[w14];
															if (inter14.count() > 0){
															for (int w15=w14+1; w15< MAX_MIRS; w15++){
																inter15 = inter14 & mt_map.map[w15];
																if (inter15.count() > 0){
																for (int w16=w15+1; w16< MAX_MIRS; w16++){
																	inter16 = inter15 & mt_map.map[w16];
																					int nr_intersec = inter16.count();
																					if (nr_intersec > minTargets){
																						target_names = "";
																						mir_names = "";
																						for (std::size_t b=0; b<inter16.size(); ++b){ // ****
    																					if (inter16.test(b)){ //  *****
																							target_names += mt_map.targets[(MAX_GENES-1 - b)].get_refseq();
																							target_names += ",";
																						}}		
																						fs16 << nr_intersec << ",";
					 																	mir_names += mt_map.mirs[w1].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w2].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w3].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w4].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w5].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w6].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w7].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w8].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w9].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w10].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w11].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w12].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w13].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w14].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w15].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w16].get_name();  mir_names += ",";
																						fs16 << mir_names << target_names << "\n";
																					}
																}}
															}}
														}}
													}}
												}}
											}}
										}}
									}}
								}}
							}}
						}}
					}}
				}}
			}}
		}
	}

	fs16.close();
}

//Print common targets of 17 mirs
void identify_17mirs_modules()
{
	ofstream fs17;
	fs17.open("./data/aux/modules_17mirs.csv");

	//Imprime intersecção de 17 mirs
	std::bitset<MAX_GENES> inter2, inter3, inter4, inter5, inter6, inter7, inter8, inter9, inter10, inter11, inter12, inter13, inter14, inter15, inter16, inter17;
	for (int w1=0; w1< MAX_MIRS; w1++){
		for (int w2=w1+1; w2< MAX_MIRS; w2++){
			inter2 = mt_map.map[w1] & mt_map.map[w2]; 
			if (inter2.count() > 0){
			for (int w3=w2+1; w3< MAX_MIRS; w3++){
				inter3 = inter2 & mt_map.map[w3];
				if (inter3.count() > 0){
				for (int w4=w3+1; w4< MAX_MIRS; w4++){
					inter4 = inter3 & mt_map.map[w4];
					if (inter4.count() > 0){
					for (int w5=w4+1; w5< MAX_MIRS; w5++){
						inter5 = inter4 & mt_map.map[w5];
						if (inter5.count() > 0){
						for (int w6=w5+1; w6< MAX_MIRS; w6++){
							inter6 = inter5 & mt_map.map[w6];
							if (inter6.count() > 0){
							for (int w7=w6+1; w7< MAX_MIRS; w7++){
								inter7 = inter6 & mt_map.map[w7];
								if (inter7.count() > 0){
								for (int w8=w7+1; w8< MAX_MIRS; w8++){
									inter8 = inter7 & mt_map.map[w8];
									if (inter8.count() > 0){
									for (int w9=w8+1; w9< MAX_MIRS; w9++){
										inter9 = inter8 & mt_map.map[w9];
										if (inter9.count() > 0){
										for (int w10=w9+1; w10< MAX_MIRS; w10++){
											inter10 = inter9 & mt_map.map[w10];
											if (inter10.count() > 0){
											for (int w11=w10+1; w11< MAX_MIRS; w11++){
												inter11 = inter10 & mt_map.map[w11];
												if (inter11.count() > 0){
												for (int w12=w11+1; w12< MAX_MIRS; w12++){
													inter12 = inter11 & mt_map.map[w12];
													if (inter12.count() > 0){
													for (int w13=w12+1; w13< MAX_MIRS; w13++){
														inter13 = inter12 & mt_map.map[w13];
														if (inter13.count() > 0){
														for (int w14=w13+1; w14< MAX_MIRS; w14++){
															inter14 = inter13 & mt_map.map[w14];
															if (inter14.count() > 0){
															for (int w15=w14+1; w15< MAX_MIRS; w15++){
																inter15 = inter14 & mt_map.map[w15];
																if (inter15.count() > 0){
																for (int w16=w15+1; w16< MAX_MIRS; w16++){
																	inter16 = inter15 & mt_map.map[w16];
																	if (inter16.count() > 0){
																	for (int w17=w16+1; w17< MAX_MIRS; w17++){
																		inter17 = inter16 & mt_map.map[w17];
																					int nr_intersec = inter17.count();
																					if (nr_intersec > minTargets){
																						target_names = "";
																						mir_names = "";
																						for (std::size_t b=0; b<inter17.size(); ++b){ // ****
    																					if (inter17.test(b)){ //  *****
																							target_names += mt_map.targets[(MAX_GENES-1 - b)].get_refseq();
																							target_names += ",";
																						}}		
																						fs17 << nr_intersec << ",";
					 																	mir_names += mt_map.mirs[w1].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w2].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w3].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w4].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w5].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w6].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w7].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w8].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w9].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w10].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w11].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w12].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w13].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w14].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w15].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w16].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w17].get_name();  mir_names += ",";
																						fs17 << mir_names << target_names << "\n";
																					}
																	}}
																}}
															}}
														}}
													}}
												}}
											}}
										}}
									}}
								}}
							}}
						}}
					}}
				}}
			}}
		}
	}

	fs17.close();
}

//Print common targets of 18 mirs
void identify_18mirs_modules()
{
	ofstream fs18;
	fs18.open("./data/aux/modules_18mirs.csv");

	std::bitset<MAX_GENES> inter2, inter3, inter4, inter5, inter6, inter7, inter8, inter9, inter10, inter11, inter12, inter13, inter14, inter15, inter16, inter17, inter18;
	for (int w1=0; w1< MAX_MIRS; w1++){
		for (int w2=w1+1; w2< MAX_MIRS; w2++){
			inter2 = mt_map.map[w1] & mt_map.map[w2]; 
			if (inter2.count() > 0){
			for (int w3=w2+1; w3< MAX_MIRS; w3++){
				inter3 = inter2 & mt_map.map[w3];
				if (inter3.count() > 0){
				for (int w4=w3+1; w4< MAX_MIRS; w4++){
					inter4 = inter3 & mt_map.map[w4];
					if (inter4.count() > 0){
					for (int w5=w4+1; w5< MAX_MIRS; w5++){
						inter5 = inter4 & mt_map.map[w5];
						if (inter5.count() > 0){
						for (int w6=w5+1; w6< MAX_MIRS; w6++){
							inter6 = inter5 & mt_map.map[w6];
							if (inter6.count() > 0){
							for (int w7=w6+1; w7< MAX_MIRS; w7++){
								inter7 = inter6 & mt_map.map[w7];
								if (inter7.count() > 0){
								for (int w8=w7+1; w8< MAX_MIRS; w8++){
									inter8 = inter7 & mt_map.map[w8];
									if (inter8.count() > 0){
									for (int w9=w8+1; w9< MAX_MIRS; w9++){
										inter9 = inter8 & mt_map.map[w9];
										if (inter9.count() > 0){
										for (int w10=w9+1; w10< MAX_MIRS; w10++){
											inter10 = inter9 & mt_map.map[w10];
											if (inter10.count() > 0){
											for (int w11=w10+1; w11< MAX_MIRS; w11++){
												inter11 = inter10 & mt_map.map[w11];
												if (inter11.count() > 0){
												for (int w12=w11+1; w12< MAX_MIRS; w12++){
													inter12 = inter11 & mt_map.map[w12];
													if (inter12.count() > 0){
													for (int w13=w12+1; w13< MAX_MIRS; w13++){
														inter13 = inter12 & mt_map.map[w13];
														if (inter13.count() > 0){
														for (int w14=w13+1; w14< MAX_MIRS; w14++){
															inter14 = inter13 & mt_map.map[w14];
															if (inter14.count() > 0){
															for (int w15=w14+1; w15< MAX_MIRS; w15++){
																inter15 = inter14 & mt_map.map[w15];
																if (inter15.count() > 0){
																for (int w16=w15+1; w16< MAX_MIRS; w16++){
																	inter16 = inter15 & mt_map.map[w16];
																	if (inter16.count() > 0){
																	for (int w17=w16+1; w17< MAX_MIRS; w17++){
																		inter17 = inter16 & mt_map.map[w17];
																		if (inter17.count() > 0){
																		for (int w18=w17+1; w18< MAX_MIRS; w18++){
																			inter18 = inter17 & mt_map.map[w18];
																					int nr_intersec = inter18.count();
																					if (nr_intersec > minTargets){
																						target_names = "";
																						mir_names = "";
																						for (std::size_t b=0; b<inter18.size(); ++b){ // ****
    																					if (inter18.test(b)){ //  *****
																							target_names += mt_map.targets[(MAX_GENES-1 - b)].get_refseq();
																							target_names += ",";
																						}}		
																						fs18 << nr_intersec << ",";
					 																	mir_names += mt_map.mirs[w1].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w2].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w3].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w4].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w5].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w6].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w7].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w8].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w9].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w10].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w11].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w12].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w13].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w14].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w15].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w16].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w17].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w18].get_name();  mir_names += ",";
																						fs18 << mir_names << target_names << "\n";
																					}
																		}}
																	}}
																}}
															}}
														}}
													}}
												}}
											}}
										}}
									}}
								}}
							}}
						}}
					}}
				}}
			}}
		}
	}

	fs18.close();
}

//Print common targets of 19 mirs
void identify_19mirs_modules()
{
	ofstream fs19;
	fs19.open("./data/aux/modules_19mirs.csv");

	std::bitset<MAX_GENES> inter2, inter3, inter4, inter5, inter6, inter7, inter8, inter9, inter10, inter11, inter12, inter13, inter14, inter15, inter16, inter17, inter18, inter19;
	for (int w1=0; w1< MAX_MIRS; w1++){
		for (int w2=w1+1; w2< MAX_MIRS; w2++){
			inter2 = mt_map.map[w1] & mt_map.map[w2]; 
			if (inter2.count() > 0){
			for (int w3=w2+1; w3< MAX_MIRS; w3++){
				inter3 = inter2 & mt_map.map[w3];
				if (inter3.count() > 0){
				for (int w4=w3+1; w4< MAX_MIRS; w4++){
					inter4 = inter3 & mt_map.map[w4];
					if (inter4.count() > 0){
					for (int w5=w4+1; w5< MAX_MIRS; w5++){
						inter5 = inter4 & mt_map.map[w5];
						if (inter5.count() > 0){
						for (int w6=w5+1; w6< MAX_MIRS; w6++){
							inter6 = inter5 & mt_map.map[w6];
							if (inter6.count() > 0){
							for (int w7=w6+1; w7< MAX_MIRS; w7++){
								inter7 = inter6 & mt_map.map[w7];
								if (inter7.count() > 0){
								for (int w8=w7+1; w8< MAX_MIRS; w8++){
									inter8 = inter7 & mt_map.map[w8];
									if (inter8.count() > 0){
									for (int w9=w8+1; w9< MAX_MIRS; w9++){
										inter9 = inter8 & mt_map.map[w9];
										if (inter9.count() > 0){
										for (int w10=w9+1; w10< MAX_MIRS; w10++){
											inter10 = inter9 & mt_map.map[w10];
											if (inter10.count() > 0){
											for (int w11=w10+1; w11< MAX_MIRS; w11++){
												inter11 = inter10 & mt_map.map[w11];
												if (inter11.count() > 0){
												for (int w12=w11+1; w12< MAX_MIRS; w12++){
													inter12 = inter11 & mt_map.map[w12];
													if (inter12.count() > 0){
													for (int w13=w12+1; w13< MAX_MIRS; w13++){
														inter13 = inter12 & mt_map.map[w13];
														if (inter13.count() > 0){
														for (int w14=w13+1; w14< MAX_MIRS; w14++){
															inter14 = inter13 & mt_map.map[w14];
															if (inter14.count() > 0){
															for (int w15=w14+1; w15< MAX_MIRS; w15++){
																inter15 = inter14 & mt_map.map[w15];
																if (inter15.count() > 0){
																for (int w16=w15+1; w16< MAX_MIRS; w16++){
																	inter16 = inter15 & mt_map.map[w16];
																	if (inter16.count() > 0){
																	for (int w17=w16+1; w17< MAX_MIRS; w17++){
																		inter17 = inter16 & mt_map.map[w17];
																		if (inter17.count() > 0){
																		for (int w18=w17+1; w18< MAX_MIRS; w18++){
																			inter18 = inter17 & mt_map.map[w18];
																			if (inter18.count() > 0){
																			for (int w19=w18+1; w19< MAX_MIRS; w19++){
																				inter19 = inter18 & mt_map.map[w19];
																					int nr_intersec = inter19.count();
																					if (nr_intersec > minTargets){
																						target_names = "";
																						mir_names = "";
																						for (std::size_t b=0; b<inter19.size(); ++b){ // ****
    																					if (inter19.test(b)){ //  *****
																							target_names += mt_map.targets[(MAX_GENES-1 - b)].get_refseq();
																							target_names += ",";
																						}}		
																						fs19 << nr_intersec << ",";
					 																	mir_names += mt_map.mirs[w1].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w2].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w3].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w4].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w5].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w6].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w7].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w8].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w9].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w10].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w11].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w12].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w13].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w14].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w15].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w16].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w17].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w18].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w19].get_name();  mir_names += ","; 
																						fs19 << mir_names << target_names << "\n";
																					}
																			}}
																		}}
																	}}
																}}
															}}
														}}
													}}
												}}
											}}
										}}
									}}
								}}
							}}
						}}
					}}
				}}
			}}
		}
	}

	fs19.close();
}

//Print common targets of 20 mirs
void identify_20mirs_modules()
{
	ofstream fs20;
	fs20.open("./data/aux/modules_20mirs.csv");

	std::bitset<MAX_GENES> inter2, inter3, inter4, inter5, inter6, inter7, inter8, inter9, inter10, inter11, inter12, inter13, inter14, inter15, inter16, inter17, inter18, inter19, inter20;
	for (int w1=0; w1< MAX_MIRS; w1++){
		for (int w2=w1+1; w2< MAX_MIRS; w2++){
			inter2 = mt_map.map[w1] & mt_map.map[w2]; 
			if (inter2.count() > 0){
			for (int w3=w2+1; w3< MAX_MIRS; w3++){
				inter3 = inter2 & mt_map.map[w3];
				if (inter3.count() > 0){
				for (int w4=w3+1; w4< MAX_MIRS; w4++){
					inter4 = inter3 & mt_map.map[w4];
					if (inter4.count() > 0){
					for (int w5=w4+1; w5< MAX_MIRS; w5++){
						inter5 = inter4 & mt_map.map[w5];
						if (inter5.count() > 0){
						for (int w6=w5+1; w6< MAX_MIRS; w6++){
							inter6 = inter5 & mt_map.map[w6];
							if (inter6.count() > 0){
							for (int w7=w6+1; w7< MAX_MIRS; w7++){
								inter7 = inter6 & mt_map.map[w7];
								if (inter7.count() > 0){
								for (int w8=w7+1; w8< MAX_MIRS; w8++){
									inter8 = inter7 & mt_map.map[w8];
									if (inter8.count() > 0){
									for (int w9=w8+1; w9< MAX_MIRS; w9++){
										inter9 = inter8 & mt_map.map[w9];
										if (inter9.count() > 0){
										for (int w10=w9+1; w10< MAX_MIRS; w10++){
											inter10 = inter9 & mt_map.map[w10];
											if (inter10.count() > 0){
											for (int w11=w10+1; w11< MAX_MIRS; w11++){
												inter11 = inter10 & mt_map.map[w11];
												if (inter11.count() > 0){
												for (int w12=w11+1; w12< MAX_MIRS; w12++){
													inter12 = inter11 & mt_map.map[w12];
													if (inter12.count() > 0){
													for (int w13=w12+1; w13< MAX_MIRS; w13++){
														inter13 = inter12 & mt_map.map[w13];
														if (inter13.count() > 0){
														for (int w14=w13+1; w14< MAX_MIRS; w14++){
															inter14 = inter13 & mt_map.map[w14];
															if (inter14.count() > 0){
															for (int w15=w14+1; w15< MAX_MIRS; w15++){
																inter15 = inter14 & mt_map.map[w15];
																if (inter15.count() > 0){
																for (int w16=w15+1; w16< MAX_MIRS; w16++){
																	inter16 = inter15 & mt_map.map[w16];
																	if (inter16.count() > 0){
																	for (int w17=w16+1; w17< MAX_MIRS; w17++){
																		inter17 = inter16 & mt_map.map[w17];
																		if (inter17.count() > 0){
																		for (int w18=w17+1; w18< MAX_MIRS; w18++){
																			inter18 = inter17 & mt_map.map[w18];
																			if (inter18.count() > 0){
																			for (int w19=w18+1; w19< MAX_MIRS; w19++){
																				inter19 = inter18 & mt_map.map[w19];
																				if (inter19.count() > 0){
																				for (int w20=w19+1; w20< MAX_MIRS; w20++){
																					inter20 = inter19 & mt_map.map[w20];
																					int nr_intersec = inter20.count();
																					if (nr_intersec > minTargets){
																						target_names = "";
																						mir_names = "";
																						for (std::size_t b=0; b<inter20.size(); ++b){ // ****
    																					if (inter20.test(b)){ //  *****
																							target_names += mt_map.targets[(MAX_GENES-1 - b)].get_refseq();
																							target_names += ",";
																						}}		
																						fs20 << nr_intersec << ",";
					 																	mir_names += mt_map.mirs[w1].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w2].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w3].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w4].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w5].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w6].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w7].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w8].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w9].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w10].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w11].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w12].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w13].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w14].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w15].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w16].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w17].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w18].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w19].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w20].get_name();  mir_names += ","; 
																						fs20 << mir_names << target_names << "\n";
																					}
																				}}
																			}}
																		}}
																	}}
																}}
															}}
														}}
													}}
												}}
											}}
										}}
									}}
								}}
							}}
						}}
					}}
				}}
			}}
		}
	}

	fs20.close();
}

//Print common targets of 21 mirs
void identify_21mirs_modules()
{
	ofstream fs21;
	fs21.open("./data/aux/modules_21mirs.csv");

	std::bitset<MAX_GENES> inter2, inter3, inter4, inter5, inter6, inter7, inter8, inter9, inter10, inter11, inter12, inter13, inter14, inter15, inter16, inter17, inter18, inter19, inter20,
		inter21;
	for (int w1=0; w1< MAX_MIRS; w1++){
		for (int w2=w1+1; w2< MAX_MIRS; w2++){
			inter2 = mt_map.map[w1] & mt_map.map[w2]; 
			if (inter2.count() > 0){
			for (int w3=w2+1; w3< MAX_MIRS; w3++){
				inter3 = inter2 & mt_map.map[w3];
				if (inter3.count() > 0){
				for (int w4=w3+1; w4< MAX_MIRS; w4++){
					inter4 = inter3 & mt_map.map[w4];
					if (inter4.count() > 0){
					for (int w5=w4+1; w5< MAX_MIRS; w5++){
						inter5 = inter4 & mt_map.map[w5];
						if (inter5.count() > 0){
						for (int w6=w5+1; w6< MAX_MIRS; w6++){
							inter6 = inter5 & mt_map.map[w6];
							if (inter6.count() > 0){
							for (int w7=w6+1; w7< MAX_MIRS; w7++){
								inter7 = inter6 & mt_map.map[w7];
								if (inter7.count() > 0){
								for (int w8=w7+1; w8< MAX_MIRS; w8++){
									inter8 = inter7 & mt_map.map[w8];
									if (inter8.count() > 0){
									for (int w9=w8+1; w9< MAX_MIRS; w9++){
										inter9 = inter8 & mt_map.map[w9];
										if (inter9.count() > 0){
										for (int w10=w9+1; w10< MAX_MIRS; w10++){
											inter10 = inter9 & mt_map.map[w10];
											if (inter10.count() > 0){
											for (int w11=w10+1; w11< MAX_MIRS; w11++){
												inter11 = inter10 & mt_map.map[w11];
												if (inter11.count() > 0){
												for (int w12=w11+1; w12< MAX_MIRS; w12++){
													inter12 = inter11 & mt_map.map[w12];
													if (inter12.count() > 0){
													for (int w13=w12+1; w13< MAX_MIRS; w13++){
														inter13 = inter12 & mt_map.map[w13];
														if (inter13.count() > 0){
														for (int w14=w13+1; w14< MAX_MIRS; w14++){
															inter14 = inter13 & mt_map.map[w14];
															if (inter14.count() > 0){
															for (int w15=w14+1; w15< MAX_MIRS; w15++){
																inter15 = inter14 & mt_map.map[w15];
																if (inter15.count() > 0){
																for (int w16=w15+1; w16< MAX_MIRS; w16++){
																	inter16 = inter15 & mt_map.map[w16];
																	if (inter16.count() > 0){
																	for (int w17=w16+1; w17< MAX_MIRS; w17++){
																		inter17 = inter16 & mt_map.map[w17];
																		if (inter17.count() > 0){
																		for (int w18=w17+1; w18< MAX_MIRS; w18++){
																			inter18 = inter17 & mt_map.map[w18];
																			if (inter18.count() > 0){
																			for (int w19=w18+1; w19< MAX_MIRS; w19++){
																				inter19 = inter18 & mt_map.map[w19];
																				if (inter19.count() > 0){
																				for (int w20=w19+1; w20< MAX_MIRS; w20++){
																					inter20 = inter19 & mt_map.map[w20];
											if (inter20.count() > 0){
											for (int w21=w20+1; w21< MAX_MIRS; w21++){
												inter21 = inter20 & mt_map.map[w21];
															int nr_intersec = inter21.count();
															if (nr_intersec > minTargets){
																target_names = "";
																mir_names = "";
																for (std::size_t b=0; b<inter21.size(); ++b){ // ****
    															if (inter21.test(b)){ //  *****
																	target_names += mt_map.targets[(MAX_GENES-1 - b)].get_refseq();
																	target_names += ",";
																}}		
																fs21 << nr_intersec << ",";
					 											mir_names += mt_map.mirs[w1].get_name();  mir_names += ",";
					 											mir_names += mt_map.mirs[w2].get_name();  mir_names += ",";
					 											mir_names += mt_map.mirs[w3].get_name();  mir_names += ",";
					 											mir_names += mt_map.mirs[w4].get_name();  mir_names += ","; 
					 											mir_names += mt_map.mirs[w5].get_name();  mir_names += ","; 
					 											mir_names += mt_map.mirs[w6].get_name();  mir_names += ",";
					 											mir_names += mt_map.mirs[w7].get_name();  mir_names += ",";
					 											mir_names += mt_map.mirs[w8].get_name();  mir_names += ",";
					 											mir_names += mt_map.mirs[w9].get_name();  mir_names += ","; 
					 											mir_names += mt_map.mirs[w10].get_name();  mir_names += ","; 
					 											mir_names += mt_map.mirs[w11].get_name();  mir_names += ",";
					 											mir_names += mt_map.mirs[w12].get_name();  mir_names += ",";
					 											mir_names += mt_map.mirs[w13].get_name();  mir_names += ",";
					 											mir_names += mt_map.mirs[w14].get_name();  mir_names += ","; 
					 											mir_names += mt_map.mirs[w15].get_name();  mir_names += ","; 
					 											mir_names += mt_map.mirs[w16].get_name();  mir_names += ",";
					 											mir_names += mt_map.mirs[w17].get_name();  mir_names += ",";
					 											mir_names += mt_map.mirs[w18].get_name();  mir_names += ",";
					 											mir_names += mt_map.mirs[w19].get_name();  mir_names += ","; 
					 											mir_names += mt_map.mirs[w20].get_name();  mir_names += ","; 
					 											mir_names += mt_map.mirs[w21].get_name();  mir_names += ",";
																fs21 << mir_names << target_names << "\n";
															}
											}}
																				}}
																			}}
																		}}
																	}}
																}}
															}}
														}}
													}}
												}}
											}}
										}}
									}}
								}}
							}}
						}}
					}}
				}}
			}}
		}
	}

	fs21.close();
}

//Print common targets of 22 mirs
void identify_22mirs_modules()
{
	ofstream fs22;
	fs22.open("./data/aux/modules_22mirs.csv");

	std::bitset<MAX_GENES> inter2, inter3, inter4, inter5, inter6, inter7, inter8, inter9, inter10, inter11, inter12, inter13, inter14, inter15, inter16, inter17, inter18, inter19, inter20,
		inter21, inter22;
	for (int w1=0; w1< MAX_MIRS; w1++){
		for (int w2=w1+1; w2< MAX_MIRS; w2++){
			inter2 = mt_map.map[w1] & mt_map.map[w2]; 
			if (inter2.count() > 0){
			for (int w3=w2+1; w3< MAX_MIRS; w3++){
				inter3 = inter2 & mt_map.map[w3];
				if (inter3.count() > 0){
				for (int w4=w3+1; w4< MAX_MIRS; w4++){
					inter4 = inter3 & mt_map.map[w4];
					if (inter4.count() > 0){
					for (int w5=w4+1; w5< MAX_MIRS; w5++){
						inter5 = inter4 & mt_map.map[w5];
						if (inter5.count() > 0){
						for (int w6=w5+1; w6< MAX_MIRS; w6++){
							inter6 = inter5 & mt_map.map[w6];
							if (inter6.count() > 0){
							for (int w7=w6+1; w7< MAX_MIRS; w7++){
								inter7 = inter6 & mt_map.map[w7];
								if (inter7.count() > 0){
								for (int w8=w7+1; w8< MAX_MIRS; w8++){
									inter8 = inter7 & mt_map.map[w8];
									if (inter8.count() > 0){
									for (int w9=w8+1; w9< MAX_MIRS; w9++){
										inter9 = inter8 & mt_map.map[w9];
										if (inter9.count() > 0){
										for (int w10=w9+1; w10< MAX_MIRS; w10++){
											inter10 = inter9 & mt_map.map[w10];
											if (inter10.count() > 0){
											for (int w11=w10+1; w11< MAX_MIRS; w11++){
												inter11 = inter10 & mt_map.map[w11];
												if (inter11.count() > 0){
												for (int w12=w11+1; w12< MAX_MIRS; w12++){
													inter12 = inter11 & mt_map.map[w12];
													if (inter12.count() > 0){
													for (int w13=w12+1; w13< MAX_MIRS; w13++){
														inter13 = inter12 & mt_map.map[w13];
														if (inter13.count() > 0){
														for (int w14=w13+1; w14< MAX_MIRS; w14++){
															inter14 = inter13 & mt_map.map[w14];
															if (inter14.count() > 0){
															for (int w15=w14+1; w15< MAX_MIRS; w15++){
																inter15 = inter14 & mt_map.map[w15];
																if (inter15.count() > 0){
																for (int w16=w15+1; w16< MAX_MIRS; w16++){
																	inter16 = inter15 & mt_map.map[w16];
																	if (inter16.count() > 0){
																	for (int w17=w16+1; w17< MAX_MIRS; w17++){
																		inter17 = inter16 & mt_map.map[w17];
																		if (inter17.count() > 0){
																		for (int w18=w17+1; w18< MAX_MIRS; w18++){
																			inter18 = inter17 & mt_map.map[w18];
																			if (inter18.count() > 0){
																			for (int w19=w18+1; w19< MAX_MIRS; w19++){
																				inter19 = inter18 & mt_map.map[w19];
																				if (inter19.count() > 0){
																				for (int w20=w19+1; w20< MAX_MIRS; w20++){
																					inter20 = inter19 & mt_map.map[w20];
											if (inter20.count() > 0){
											for (int w21=w20+1; w21< MAX_MIRS; w21++){
												inter21 = inter20 & mt_map.map[w21];
												if (inter21.count() > 0){
												for (int w22=w21+1; w22< MAX_MIRS; w22++){
													inter22 = inter21 & mt_map.map[w22];
															int nr_intersec = inter22.count();
															if (nr_intersec > minTargets){
																target_names = "";
																mir_names = "";
																for (std::size_t b=0; b<inter22.size(); ++b){ // ****
    															if (inter22.test(b)){ //  *****
																	target_names += mt_map.targets[(MAX_GENES-1 - b)].get_refseq();
																	target_names += ",";
																}}		
																fs22 << nr_intersec << ",";
					 											mir_names += mt_map.mirs[w1].get_name();  mir_names += ",";
					 											mir_names += mt_map.mirs[w2].get_name();  mir_names += ",";
					 											mir_names += mt_map.mirs[w3].get_name();  mir_names += ",";
					 											mir_names += mt_map.mirs[w4].get_name();  mir_names += ","; 
					 											mir_names += mt_map.mirs[w5].get_name();  mir_names += ","; 
					 											mir_names += mt_map.mirs[w6].get_name();  mir_names += ",";
					 											mir_names += mt_map.mirs[w7].get_name();  mir_names += ",";
					 											mir_names += mt_map.mirs[w8].get_name();  mir_names += ",";
					 											mir_names += mt_map.mirs[w9].get_name();  mir_names += ","; 
					 											mir_names += mt_map.mirs[w10].get_name();  mir_names += ","; 
					 											mir_names += mt_map.mirs[w11].get_name();  mir_names += ",";
					 											mir_names += mt_map.mirs[w12].get_name();  mir_names += ",";
					 											mir_names += mt_map.mirs[w13].get_name();  mir_names += ",";
					 											mir_names += mt_map.mirs[w14].get_name();  mir_names += ","; 
					 											mir_names += mt_map.mirs[w15].get_name();  mir_names += ","; 
					 											mir_names += mt_map.mirs[w16].get_name();  mir_names += ",";
					 											mir_names += mt_map.mirs[w17].get_name();  mir_names += ",";
					 											mir_names += mt_map.mirs[w18].get_name();  mir_names += ",";
					 											mir_names += mt_map.mirs[w19].get_name();  mir_names += ","; 
					 											mir_names += mt_map.mirs[w20].get_name();  mir_names += ","; 
					 											mir_names += mt_map.mirs[w21].get_name();  mir_names += ",";
					 											mir_names += mt_map.mirs[w22].get_name();  mir_names += ",";
																fs22 << mir_names << target_names << "\n";
															}
												}}
											}}
																				}}
																			}}
																		}}
																	}}
																}}
															}}
														}}
													}}
												}}
											}}
										}}
									}}
								}}
							}}
						}}
					}}
				}}
			}}
		}
	}

	fs22.close();
}

//Print common targets of 23 mirs
void identify_23mirs_modules()
{
	ofstream fs23;
	fs23.open("./data/aux/modules_23mirs.csv");

	std::bitset<MAX_GENES> inter2, inter3, inter4, inter5, inter6, inter7, inter8, inter9, inter10, inter11, inter12, inter13, inter14, inter15, inter16, inter17, inter18, inter19, inter20,
		inter21, inter22, inter23;
	for (int w1=0; w1< MAX_MIRS; w1++){
		for (int w2=w1+1; w2< MAX_MIRS; w2++){
			inter2 = mt_map.map[w1] & mt_map.map[w2]; 
			if (inter2.count() > 0){
			for (int w3=w2+1; w3< MAX_MIRS; w3++){
				inter3 = inter2 & mt_map.map[w3];
				if (inter3.count() > 0){
				for (int w4=w3+1; w4< MAX_MIRS; w4++){
					inter4 = inter3 & mt_map.map[w4];
					if (inter4.count() > 0){
					for (int w5=w4+1; w5< MAX_MIRS; w5++){
						inter5 = inter4 & mt_map.map[w5];
						if (inter5.count() > 0){
						for (int w6=w5+1; w6< MAX_MIRS; w6++){
							inter6 = inter5 & mt_map.map[w6];
							if (inter6.count() > 0){
							for (int w7=w6+1; w7< MAX_MIRS; w7++){
								inter7 = inter6 & mt_map.map[w7];
								if (inter7.count() > 0){
								for (int w8=w7+1; w8< MAX_MIRS; w8++){
									inter8 = inter7 & mt_map.map[w8];
									if (inter8.count() > 0){
									for (int w9=w8+1; w9< MAX_MIRS; w9++){
										inter9 = inter8 & mt_map.map[w9];
										if (inter9.count() > 0){
										for (int w10=w9+1; w10< MAX_MIRS; w10++){
											inter10 = inter9 & mt_map.map[w10];
											if (inter10.count() > 0){
											for (int w11=w10+1; w11< MAX_MIRS; w11++){
												inter11 = inter10 & mt_map.map[w11];
												if (inter11.count() > 0){
												for (int w12=w11+1; w12< MAX_MIRS; w12++){
													inter12 = inter11 & mt_map.map[w12];
													if (inter12.count() > 0){
													for (int w13=w12+1; w13< MAX_MIRS; w13++){
														inter13 = inter12 & mt_map.map[w13];
														if (inter13.count() > 0){
														for (int w14=w13+1; w14< MAX_MIRS; w14++){
															inter14 = inter13 & mt_map.map[w14];
															if (inter14.count() > 0){
															for (int w15=w14+1; w15< MAX_MIRS; w15++){
																inter15 = inter14 & mt_map.map[w15];
																if (inter15.count() > 0){
																for (int w16=w15+1; w16< MAX_MIRS; w16++){
																	inter16 = inter15 & mt_map.map[w16];
																	if (inter16.count() > 0){
																	for (int w17=w16+1; w17< MAX_MIRS; w17++){
																		inter17 = inter16 & mt_map.map[w17];
																		if (inter17.count() > 0){
																		for (int w18=w17+1; w18< MAX_MIRS; w18++){
																			inter18 = inter17 & mt_map.map[w18];
																			if (inter18.count() > 0){
																			for (int w19=w18+1; w19< MAX_MIRS; w19++){
																				inter19 = inter18 & mt_map.map[w19];
																				if (inter19.count() > 0){
																				for (int w20=w19+1; w20< MAX_MIRS; w20++){
																					inter20 = inter19 & mt_map.map[w20];
											if (inter20.count() > 0){
											for (int w21=w20+1; w21< MAX_MIRS; w21++){
												inter21 = inter20 & mt_map.map[w21];
												if (inter21.count() > 0){
												for (int w22=w21+1; w22< MAX_MIRS; w22++){
													inter22 = inter21 & mt_map.map[w22];
													if (inter22.count() > 0){
													for (int w23=w22+1; w23< MAX_MIRS; w23++){
														inter23 = inter22 & mt_map.map[w23];
															int nr_intersec = inter23.count();
															if (nr_intersec > minTargets){
																target_names = "";
																mir_names = "";
																for (std::size_t b=0; b<inter23.size(); ++b){ // ****
    															if (inter23.test(b)){ //  *****
																	target_names += mt_map.targets[(MAX_GENES-1 - b)].get_refseq();
																	target_names += ",";
																}}		
																fs23 << nr_intersec << ",";
					 											mir_names += mt_map.mirs[w1].get_name();  mir_names += ",";
					 											mir_names += mt_map.mirs[w2].get_name();  mir_names += ",";
					 											mir_names += mt_map.mirs[w3].get_name();  mir_names += ",";
					 											mir_names += mt_map.mirs[w4].get_name();  mir_names += ","; 
					 											mir_names += mt_map.mirs[w5].get_name();  mir_names += ","; 
					 											mir_names += mt_map.mirs[w6].get_name();  mir_names += ",";
					 											mir_names += mt_map.mirs[w7].get_name();  mir_names += ",";
					 											mir_names += mt_map.mirs[w8].get_name();  mir_names += ",";
					 											mir_names += mt_map.mirs[w9].get_name();  mir_names += ","; 
					 											mir_names += mt_map.mirs[w10].get_name();  mir_names += ","; 
					 											mir_names += mt_map.mirs[w11].get_name();  mir_names += ",";
					 											mir_names += mt_map.mirs[w12].get_name();  mir_names += ",";
					 											mir_names += mt_map.mirs[w13].get_name();  mir_names += ",";
					 											mir_names += mt_map.mirs[w14].get_name();  mir_names += ","; 
					 											mir_names += mt_map.mirs[w15].get_name();  mir_names += ","; 
					 											mir_names += mt_map.mirs[w16].get_name();  mir_names += ",";
					 											mir_names += mt_map.mirs[w17].get_name();  mir_names += ",";
					 											mir_names += mt_map.mirs[w18].get_name();  mir_names += ",";
					 											mir_names += mt_map.mirs[w19].get_name();  mir_names += ","; 
					 											mir_names += mt_map.mirs[w20].get_name();  mir_names += ","; 
					 											mir_names += mt_map.mirs[w21].get_name();  mir_names += ",";
					 											mir_names += mt_map.mirs[w22].get_name();  mir_names += ",";
					 											mir_names += mt_map.mirs[w23].get_name();  mir_names += ",";
																fs23 << mir_names << target_names << "\n";
															}
													}}
												}}
											}}
																				}}
																			}}
																		}}
																	}}
																}}
															}}
														}}
													}}
												}}
											}}
										}}
									}}
								}}
							}}
						}}
					}}
				}}
			}}
		}
	}

	fs23.close();
}

//Print common targets of 24 mirs
void identify_24mirs_modules()
{
	ofstream fs24;
	fs24.open("./data/aux/modules_24mirs.csv");

	std::bitset<MAX_GENES> inter2, inter3, inter4, inter5, inter6, inter7, inter8, inter9, inter10, inter11, inter12, inter13, inter14, inter15, inter16, inter17, inter18, inter19, inter20,
		inter21, inter22, inter23, inter24;
	for (int w1=0; w1< MAX_MIRS; w1++){
		for (int w2=w1+1; w2< MAX_MIRS; w2++){
			inter2 = mt_map.map[w1] & mt_map.map[w2]; 
			if (inter2.count() > 0){
			for (int w3=w2+1; w3< MAX_MIRS; w3++){
				inter3 = inter2 & mt_map.map[w3];
				if (inter3.count() > 0){
				for (int w4=w3+1; w4< MAX_MIRS; w4++){
					inter4 = inter3 & mt_map.map[w4];
					if (inter4.count() > 0){
					for (int w5=w4+1; w5< MAX_MIRS; w5++){
						inter5 = inter4 & mt_map.map[w5];
						if (inter5.count() > 0){
						for (int w6=w5+1; w6< MAX_MIRS; w6++){
							inter6 = inter5 & mt_map.map[w6];
							if (inter6.count() > 0){
							for (int w7=w6+1; w7< MAX_MIRS; w7++){
								inter7 = inter6 & mt_map.map[w7];
								if (inter7.count() > 0){
								for (int w8=w7+1; w8< MAX_MIRS; w8++){
									inter8 = inter7 & mt_map.map[w8];
									if (inter8.count() > 0){
									for (int w9=w8+1; w9< MAX_MIRS; w9++){
										inter9 = inter8 & mt_map.map[w9];
										if (inter9.count() > 0){
										for (int w10=w9+1; w10< MAX_MIRS; w10++){
											inter10 = inter9 & mt_map.map[w10];
											if (inter10.count() > 0){
											for (int w11=w10+1; w11< MAX_MIRS; w11++){
												inter11 = inter10 & mt_map.map[w11];
												if (inter11.count() > 0){
												for (int w12=w11+1; w12< MAX_MIRS; w12++){
													inter12 = inter11 & mt_map.map[w12];
													if (inter12.count() > 0){
													for (int w13=w12+1; w13< MAX_MIRS; w13++){
														inter13 = inter12 & mt_map.map[w13];
														if (inter13.count() > 0){
														for (int w14=w13+1; w14< MAX_MIRS; w14++){
															inter14 = inter13 & mt_map.map[w14];
															if (inter14.count() > 0){
															for (int w15=w14+1; w15< MAX_MIRS; w15++){
																inter15 = inter14 & mt_map.map[w15];
																if (inter15.count() > 0){
																for (int w16=w15+1; w16< MAX_MIRS; w16++){
																	inter16 = inter15 & mt_map.map[w16];
																	if (inter16.count() > 0){
																	for (int w17=w16+1; w17< MAX_MIRS; w17++){
																		inter17 = inter16 & mt_map.map[w17];
																		if (inter17.count() > 0){
																		for (int w18=w17+1; w18< MAX_MIRS; w18++){
																			inter18 = inter17 & mt_map.map[w18];
																			if (inter18.count() > 0){
																			for (int w19=w18+1; w19< MAX_MIRS; w19++){
																				inter19 = inter18 & mt_map.map[w19];
																				if (inter19.count() > 0){
																				for (int w20=w19+1; w20< MAX_MIRS; w20++){
																					inter20 = inter19 & mt_map.map[w20];
											if (inter20.count() > 0){
											for (int w21=w20+1; w21< MAX_MIRS; w21++){
												inter21 = inter20 & mt_map.map[w21];
												if (inter21.count() > 0){
												for (int w22=w21+1; w22< MAX_MIRS; w22++){
													inter22 = inter21 & mt_map.map[w22];
													if (inter22.count() > 0){
													for (int w23=w22+1; w23< MAX_MIRS; w23++){
														inter23 = inter22 & mt_map.map[w23];
														if (inter23.count() > 0){
														for (int w24=w23+1; w24< MAX_MIRS; w24++){
															inter24 = inter23 & mt_map.map[w24];
															int nr_intersec = inter24.count();
															if (nr_intersec > minTargets){
																target_names = "";
																mir_names = "";
																for (std::size_t b=0; b<inter24.size(); ++b){ // ****
    															if (inter24.test(b)){ //  *****
																	target_names += mt_map.targets[(MAX_GENES-1 - b)].get_refseq();
																	target_names += ",";
																}}		
																fs24 << nr_intersec << ",";
					 											mir_names += mt_map.mirs[w1].get_name();  mir_names += ",";
					 											mir_names += mt_map.mirs[w2].get_name();  mir_names += ",";
					 											mir_names += mt_map.mirs[w3].get_name();  mir_names += ",";
					 											mir_names += mt_map.mirs[w4].get_name();  mir_names += ","; 
					 											mir_names += mt_map.mirs[w5].get_name();  mir_names += ","; 
					 											mir_names += mt_map.mirs[w6].get_name();  mir_names += ",";
					 											mir_names += mt_map.mirs[w7].get_name();  mir_names += ",";
					 											mir_names += mt_map.mirs[w8].get_name();  mir_names += ",";
					 											mir_names += mt_map.mirs[w9].get_name();  mir_names += ","; 
					 											mir_names += mt_map.mirs[w10].get_name();  mir_names += ","; 
					 											mir_names += mt_map.mirs[w11].get_name();  mir_names += ",";
					 											mir_names += mt_map.mirs[w12].get_name();  mir_names += ",";
					 											mir_names += mt_map.mirs[w13].get_name();  mir_names += ",";
					 											mir_names += mt_map.mirs[w14].get_name();  mir_names += ","; 
					 											mir_names += mt_map.mirs[w15].get_name();  mir_names += ","; 
					 											mir_names += mt_map.mirs[w16].get_name();  mir_names += ",";
					 											mir_names += mt_map.mirs[w17].get_name();  mir_names += ",";
					 											mir_names += mt_map.mirs[w18].get_name();  mir_names += ",";
					 											mir_names += mt_map.mirs[w19].get_name();  mir_names += ","; 
					 											mir_names += mt_map.mirs[w20].get_name();  mir_names += ","; 
					 											mir_names += mt_map.mirs[w21].get_name();  mir_names += ",";
					 											mir_names += mt_map.mirs[w22].get_name();  mir_names += ",";
					 											mir_names += mt_map.mirs[w23].get_name();  mir_names += ",";
					 											mir_names += mt_map.mirs[w24].get_name();  mir_names += ","; 
																fs24 << mir_names << target_names << "\n";
															}
														}}
													}}
												}}
											}}
																				}}
																			}}
																		}}
																	}}
																}}
															}}
														}}
													}}
												}}
											}}
										}}
									}}
								}}
							}}
						}}
					}}
				}}
			}}
		}
	}

	fs24.close();
}

//Print common targets of 25 mirs
void identify_25mirs_modules()
{
	ofstream fs25;
	fs25.open("./data/aux/modules_25mirs.csv");

	std::bitset<MAX_GENES> inter2, inter3, inter4, inter5, inter6, inter7, inter8, inter9, inter10, inter11, inter12, inter13, inter14, inter15, inter16, inter17, inter18, inter19, inter20,
		inter21, inter22, inter23, inter24, inter25;
	for (int w1=0; w1< MAX_MIRS; w1++){
		for (int w2=w1+1; w2< MAX_MIRS; w2++){
			inter2 = mt_map.map[w1] & mt_map.map[w2]; 
			if (inter2.count() > 0){
			for (int w3=w2+1; w3< MAX_MIRS; w3++){
				inter3 = inter2 & mt_map.map[w3];
				if (inter3.count() > 0){
				for (int w4=w3+1; w4< MAX_MIRS; w4++){
					inter4 = inter3 & mt_map.map[w4];
					if (inter4.count() > 0){
					for (int w5=w4+1; w5< MAX_MIRS; w5++){
						inter5 = inter4 & mt_map.map[w5];
						if (inter5.count() > 0){
						for (int w6=w5+1; w6< MAX_MIRS; w6++){
							inter6 = inter5 & mt_map.map[w6];
							if (inter6.count() > 0){
							for (int w7=w6+1; w7< MAX_MIRS; w7++){
								inter7 = inter6 & mt_map.map[w7];
								if (inter7.count() > 0){
								for (int w8=w7+1; w8< MAX_MIRS; w8++){
									inter8 = inter7 & mt_map.map[w8];
									if (inter8.count() > 0){
									for (int w9=w8+1; w9< MAX_MIRS; w9++){
										inter9 = inter8 & mt_map.map[w9];
										if (inter9.count() > 0){
										for (int w10=w9+1; w10< MAX_MIRS; w10++){
											inter10 = inter9 & mt_map.map[w10];
											if (inter10.count() > 0){
											for (int w11=w10+1; w11< MAX_MIRS; w11++){
												inter11 = inter10 & mt_map.map[w11];
												if (inter11.count() > 0){
												for (int w12=w11+1; w12< MAX_MIRS; w12++){
													inter12 = inter11 & mt_map.map[w12];
													if (inter12.count() > 0){
													for (int w13=w12+1; w13< MAX_MIRS; w13++){
														inter13 = inter12 & mt_map.map[w13];
														if (inter13.count() > 0){
														for (int w14=w13+1; w14< MAX_MIRS; w14++){
															inter14 = inter13 & mt_map.map[w14];
															if (inter14.count() > 0){
															for (int w15=w14+1; w15< MAX_MIRS; w15++){
																inter15 = inter14 & mt_map.map[w15];
																if (inter15.count() > 0){
																for (int w16=w15+1; w16< MAX_MIRS; w16++){
																	inter16 = inter15 & mt_map.map[w16];
																	if (inter16.count() > 0){
																	for (int w17=w16+1; w17< MAX_MIRS; w17++){
																		inter17 = inter16 & mt_map.map[w17];
																		if (inter17.count() > 0){
																		for (int w18=w17+1; w18< MAX_MIRS; w18++){
																			inter18 = inter17 & mt_map.map[w18];
																			if (inter18.count() > 0){
																			for (int w19=w18+1; w19< MAX_MIRS; w19++){
																				inter19 = inter18 & mt_map.map[w19];
																				if (inter19.count() > 0){
																				for (int w20=w19+1; w20< MAX_MIRS; w20++){
																					inter20 = inter19 & mt_map.map[w20];
											if (inter20.count() > 0){
											for (int w21=w20+1; w21< MAX_MIRS; w21++){
												inter21 = inter20 & mt_map.map[w21];
												if (inter21.count() > 0){
												for (int w22=w21+1; w22< MAX_MIRS; w22++){
													inter22 = inter21 & mt_map.map[w22];
													if (inter22.count() > 0){
													for (int w23=w22+1; w23< MAX_MIRS; w23++){
														inter23 = inter22 & mt_map.map[w23];
														if (inter23.count() > 0){
														for (int w24=w23+1; w24< MAX_MIRS; w24++){
															inter24 = inter23 & mt_map.map[w24];
															if (inter24.count() > 0){
															for (int w25=w24+1; w25< MAX_MIRS; w25++){
																inter25 = inter24 & mt_map.map[w25];
																					int nr_intersec = inter25.count();
																					if (nr_intersec > minTargets){
																						target_names = "";
																						mir_names = "";
																						for (std::size_t b=0; b<inter25.size(); ++b){ // ****
    																					if (inter25.test(b)){ //  *****
																							target_names += mt_map.targets[(MAX_GENES-1 - b)].get_refseq();
																							target_names += ",";
																						}}		
																						fs25 << nr_intersec << ",";
					 																	mir_names += mt_map.mirs[w1].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w2].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w3].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w4].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w5].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w6].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w7].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w8].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w9].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w10].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w11].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w12].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w13].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w14].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w15].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w16].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w17].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w18].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w19].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w20].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w21].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w22].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w23].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w24].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w25].get_name();  mir_names += ","; 
																						fs25 << mir_names << target_names << "\n";
																					}
															}}
														}}
													}}
												}}
											}}
																				}}
																			}}
																		}}
																	}}
																}}
															}}
														}}
													}}
												}}
											}}
										}}
									}}
								}}
							}}
						}}
					}}
				}}
			}}
		}
	}

	fs25.close();
}

//Print common targets of 26 mirs
void identify_26mirs_modules()
{
	ofstream fs26;
	fs26.open("./data/aux/modules_26mirs.csv");

	std::bitset<MAX_GENES> inter2, inter3, inter4, inter5, inter6, inter7, inter8, inter9, inter10, inter11, inter12, inter13, inter14, inter15, inter16, inter17, inter18, inter19, inter20,
		inter21, inter22, inter23, inter24, inter25, inter26;
	for (int w1=0; w1< MAX_MIRS; w1++){
		for (int w2=w1+1; w2< MAX_MIRS; w2++){
			inter2 = mt_map.map[w1] & mt_map.map[w2]; 
			if (inter2.count() > 0){
			for (int w3=w2+1; w3< MAX_MIRS; w3++){
				inter3 = inter2 & mt_map.map[w3];
				if (inter3.count() > 0){
				for (int w4=w3+1; w4< MAX_MIRS; w4++){
					inter4 = inter3 & mt_map.map[w4];
					if (inter4.count() > 0){
					for (int w5=w4+1; w5< MAX_MIRS; w5++){
						inter5 = inter4 & mt_map.map[w5];
						if (inter5.count() > 0){
						for (int w6=w5+1; w6< MAX_MIRS; w6++){
							inter6 = inter5 & mt_map.map[w6];
							if (inter6.count() > 0){
							for (int w7=w6+1; w7< MAX_MIRS; w7++){
								inter7 = inter6 & mt_map.map[w7];
								if (inter7.count() > 0){
								for (int w8=w7+1; w8< MAX_MIRS; w8++){
									inter8 = inter7 & mt_map.map[w8];
									if (inter8.count() > 0){
									for (int w9=w8+1; w9< MAX_MIRS; w9++){
										inter9 = inter8 & mt_map.map[w9];
										if (inter9.count() > 0){
										for (int w10=w9+1; w10< MAX_MIRS; w10++){
											inter10 = inter9 & mt_map.map[w10];
											if (inter10.count() > 0){
											for (int w11=w10+1; w11< MAX_MIRS; w11++){
												inter11 = inter10 & mt_map.map[w11];
												if (inter11.count() > 0){
												for (int w12=w11+1; w12< MAX_MIRS; w12++){
													inter12 = inter11 & mt_map.map[w12];
													if (inter12.count() > 0){
													for (int w13=w12+1; w13< MAX_MIRS; w13++){
														inter13 = inter12 & mt_map.map[w13];
														if (inter13.count() > 0){
														for (int w14=w13+1; w14< MAX_MIRS; w14++){
															inter14 = inter13 & mt_map.map[w14];
															if (inter14.count() > 0){
															for (int w15=w14+1; w15< MAX_MIRS; w15++){
																inter15 = inter14 & mt_map.map[w15];
																if (inter15.count() > 0){
																for (int w16=w15+1; w16< MAX_MIRS; w16++){
																	inter16 = inter15 & mt_map.map[w16];
																	if (inter16.count() > 0){
																	for (int w17=w16+1; w17< MAX_MIRS; w17++){
																		inter17 = inter16 & mt_map.map[w17];
																		if (inter17.count() > 0){
																		for (int w18=w17+1; w18< MAX_MIRS; w18++){
																			inter18 = inter17 & mt_map.map[w18];
																			if (inter18.count() > 0){
																			for (int w19=w18+1; w19< MAX_MIRS; w19++){
																				inter19 = inter18 & mt_map.map[w19];
																				if (inter19.count() > 0){
																				for (int w20=w19+1; w20< MAX_MIRS; w20++){
																					inter20 = inter19 & mt_map.map[w20];
											if (inter20.count() > 0){
											for (int w21=w20+1; w21< MAX_MIRS; w21++){
												inter21 = inter20 & mt_map.map[w21];
												if (inter21.count() > 0){
												for (int w22=w21+1; w22< MAX_MIRS; w22++){
													inter22 = inter21 & mt_map.map[w22];
													if (inter22.count() > 0){
													for (int w23=w22+1; w23< MAX_MIRS; w23++){
														inter23 = inter22 & mt_map.map[w23];
														if (inter23.count() > 0){
														for (int w24=w23+1; w24< MAX_MIRS; w24++){
															inter24 = inter23 & mt_map.map[w24];
															if (inter24.count() > 0){
															for (int w25=w24+1; w25< MAX_MIRS; w25++){
																inter25 = inter24 & mt_map.map[w25];
																if (inter25.count() > 0){
																for (int w26=w25+1; w26< MAX_MIRS; w26++){
																	inter26 = inter25 & mt_map.map[w26];
																					int nr_intersec = inter26.count();
																					if (nr_intersec > minTargets){
																						target_names = "";
																						mir_names = "";
																						for (std::size_t b=0; b<inter26.size(); ++b){ // ****
    																					if (inter26.test(b)){ //  *****
																							target_names += mt_map.targets[(MAX_GENES-1 - b)].get_refseq();
																							target_names += ",";
																						}}		
																						fs26 << nr_intersec << ",";
					 																	mir_names += mt_map.mirs[w1].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w2].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w3].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w4].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w5].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w6].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w7].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w8].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w9].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w10].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w11].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w12].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w13].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w14].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w15].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w16].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w17].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w18].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w19].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w20].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w21].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w22].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w23].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w24].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w25].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w26].get_name();  mir_names += ",";
																						fs26 << mir_names << target_names << "\n";
																	}
																}}
															}}
														}}
													}}
												}}
											}}
																				}}
																			}}
																		}}
																	}}
																}}
															}}
														}}
													}}
												}}
											}}
										}}
									}}
								}}
							}}
						}}
					}}
				}}
			}}
		}
	}

	fs26.close();
}

//Print common targets of 27 mirs
void identify_27mirs_modules()
{
	ofstream fs27;
	fs27.open("./data/aux/modules_27mirs.csv");

	std::bitset<MAX_GENES> inter2, inter3, inter4, inter5, inter6, inter7, inter8, inter9, inter10, inter11, inter12, inter13, inter14, inter15, inter16, inter17, inter18, inter19, inter20,
		inter21, inter22, inter23, inter24, inter25, inter26, inter27;
	for (int w1=0; w1< MAX_MIRS; w1++){
		for (int w2=w1+1; w2< MAX_MIRS; w2++){
			inter2 = mt_map.map[w1] & mt_map.map[w2]; 
			if (inter2.count() > 0){
			for (int w3=w2+1; w3< MAX_MIRS; w3++){
				inter3 = inter2 & mt_map.map[w3];
				if (inter3.count() > 0){
				for (int w4=w3+1; w4< MAX_MIRS; w4++){
					inter4 = inter3 & mt_map.map[w4];
					if (inter4.count() > 0){
					for (int w5=w4+1; w5< MAX_MIRS; w5++){
						inter5 = inter4 & mt_map.map[w5];
						if (inter5.count() > 0){
						for (int w6=w5+1; w6< MAX_MIRS; w6++){
							inter6 = inter5 & mt_map.map[w6];
							if (inter6.count() > 0){
							for (int w7=w6+1; w7< MAX_MIRS; w7++){
								inter7 = inter6 & mt_map.map[w7];
								if (inter7.count() > 0){
								for (int w8=w7+1; w8< MAX_MIRS; w8++){
									inter8 = inter7 & mt_map.map[w8];
									if (inter8.count() > 0){
									for (int w9=w8+1; w9< MAX_MIRS; w9++){
										inter9 = inter8 & mt_map.map[w9];
										if (inter9.count() > 0){
										for (int w10=w9+1; w10< MAX_MIRS; w10++){
											inter10 = inter9 & mt_map.map[w10];
											if (inter10.count() > 0){
											for (int w11=w10+1; w11< MAX_MIRS; w11++){
												inter11 = inter10 & mt_map.map[w11];
												if (inter11.count() > 0){
												for (int w12=w11+1; w12< MAX_MIRS; w12++){
													inter12 = inter11 & mt_map.map[w12];
													if (inter12.count() > 0){
													for (int w13=w12+1; w13< MAX_MIRS; w13++){
														inter13 = inter12 & mt_map.map[w13];
														if (inter13.count() > 0){
														for (int w14=w13+1; w14< MAX_MIRS; w14++){
															inter14 = inter13 & mt_map.map[w14];
															if (inter14.count() > 0){
															for (int w15=w14+1; w15< MAX_MIRS; w15++){
																inter15 = inter14 & mt_map.map[w15];
																if (inter15.count() > 0){
																for (int w16=w15+1; w16< MAX_MIRS; w16++){
																	inter16 = inter15 & mt_map.map[w16];
																	if (inter16.count() > 0){
																	for (int w17=w16+1; w17< MAX_MIRS; w17++){
																		inter17 = inter16 & mt_map.map[w17];
																		if (inter17.count() > 0){
																		for (int w18=w17+1; w18< MAX_MIRS; w18++){
																			inter18 = inter17 & mt_map.map[w18];
																			if (inter18.count() > 0){
																			for (int w19=w18+1; w19< MAX_MIRS; w19++){
																				inter19 = inter18 & mt_map.map[w19];
																				if (inter19.count() > 0){
																				for (int w20=w19+1; w20< MAX_MIRS; w20++){
																					inter20 = inter19 & mt_map.map[w20];
											if (inter20.count() > 0){
											for (int w21=w20+1; w21< MAX_MIRS; w21++){
												inter21 = inter20 & mt_map.map[w21];
												if (inter21.count() > 0){
												for (int w22=w21+1; w22< MAX_MIRS; w22++){
													inter22 = inter21 & mt_map.map[w22];
													if (inter22.count() > 0){
													for (int w23=w22+1; w23< MAX_MIRS; w23++){
														inter23 = inter22 & mt_map.map[w23];
														if (inter23.count() > 0){
														for (int w24=w23+1; w24< MAX_MIRS; w24++){
															inter24 = inter23 & mt_map.map[w24];
															if (inter24.count() > 0){
															for (int w25=w24+1; w25< MAX_MIRS; w25++){
																inter25 = inter24 & mt_map.map[w25];
																if (inter25.count() > 0){
																for (int w26=w25+1; w26< MAX_MIRS; w26++){
																	inter26 = inter25 & mt_map.map[w26];
																	if (inter26.count() > 0){
																	for (int w27=w26+1; w27< MAX_MIRS; w27++){
																		inter27 = inter26 & mt_map.map[w27];
																					int nr_intersec = inter27.count();
																					if (nr_intersec > minTargets){
																						target_names = "";
																						mir_names = "";
																						for (std::size_t b=0; b<inter27.size(); ++b){ // ****
    																					if (inter27.test(b)){ //  *****
																							target_names += mt_map.targets[(MAX_GENES-1 - b)].get_refseq();
																							target_names += ",";
																						}}		
																						fs27 << nr_intersec << ",";
					 																	mir_names += mt_map.mirs[w1].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w2].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w3].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w4].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w5].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w6].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w7].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w8].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w9].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w10].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w11].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w12].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w13].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w14].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w15].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w16].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w17].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w18].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w19].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w20].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w21].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w22].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w23].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w24].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w25].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w26].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w27].get_name();  mir_names += ",";
																						fs27 << mir_names << target_names << "\n";
																					}
																	}}
																}}
															}}
														}}
													}}
												}}
											}}
																				}}
																			}}
																		}}
																	}}
																}}
															}}
														}}
													}}
												}}
											}}
										}}
									}}
								}}
							}}
						}}
					}}
				}}
			}}
		}
	}

	fs27.close();
}

//Print common targets of 28 mirs
void identify_28mirs_modules()
{
	ofstream fs28;
	fs28.open("./data/aux/modules_28mirs.csv");

	std::bitset<MAX_GENES> inter2, inter3, inter4, inter5, inter6, inter7, inter8, inter9, inter10, inter11, inter12, inter13, inter14, inter15, inter16, inter17, inter18, inter19, inter20,
		inter21, inter22, inter23, inter24, inter25, inter26, inter27, inter28;
	for (int w1=0; w1< MAX_MIRS; w1++){
		for (int w2=w1+1; w2< MAX_MIRS; w2++){
			inter2 = mt_map.map[w1] & mt_map.map[w2]; 
			if (inter2.count() > 0){
			for (int w3=w2+1; w3< MAX_MIRS; w3++){
				inter3 = inter2 & mt_map.map[w3];
				if (inter3.count() > 0){
				for (int w4=w3+1; w4< MAX_MIRS; w4++){
					inter4 = inter3 & mt_map.map[w4];
					if (inter4.count() > 0){
					for (int w5=w4+1; w5< MAX_MIRS; w5++){
						inter5 = inter4 & mt_map.map[w5];
						if (inter5.count() > 0){
						for (int w6=w5+1; w6< MAX_MIRS; w6++){
							inter6 = inter5 & mt_map.map[w6];
							if (inter6.count() > 0){
							for (int w7=w6+1; w7< MAX_MIRS; w7++){
								inter7 = inter6 & mt_map.map[w7];
								if (inter7.count() > 0){
								for (int w8=w7+1; w8< MAX_MIRS; w8++){
									inter8 = inter7 & mt_map.map[w8];
									if (inter8.count() > 0){
									for (int w9=w8+1; w9< MAX_MIRS; w9++){
										inter9 = inter8 & mt_map.map[w9];
										if (inter9.count() > 0){
										for (int w10=w9+1; w10< MAX_MIRS; w10++){
											inter10 = inter9 & mt_map.map[w10];
											if (inter10.count() > 0){
											for (int w11=w10+1; w11< MAX_MIRS; w11++){
												inter11 = inter10 & mt_map.map[w11];
												if (inter11.count() > 0){
												for (int w12=w11+1; w12< MAX_MIRS; w12++){
													inter12 = inter11 & mt_map.map[w12];
													if (inter12.count() > 0){
													for (int w13=w12+1; w13< MAX_MIRS; w13++){
														inter13 = inter12 & mt_map.map[w13];
														if (inter13.count() > 0){
														for (int w14=w13+1; w14< MAX_MIRS; w14++){
															inter14 = inter13 & mt_map.map[w14];
															if (inter14.count() > 0){
															for (int w15=w14+1; w15< MAX_MIRS; w15++){
																inter15 = inter14 & mt_map.map[w15];
																if (inter15.count() > 0){
																for (int w16=w15+1; w16< MAX_MIRS; w16++){
																	inter16 = inter15 & mt_map.map[w16];
																	if (inter16.count() > 0){
																	for (int w17=w16+1; w17< MAX_MIRS; w17++){
																		inter17 = inter16 & mt_map.map[w17];
																		if (inter17.count() > 0){
																		for (int w18=w17+1; w18< MAX_MIRS; w18++){
																			inter18 = inter17 & mt_map.map[w18];
																			if (inter18.count() > 0){
																			for (int w19=w18+1; w19< MAX_MIRS; w19++){
																				inter19 = inter18 & mt_map.map[w19];
																				if (inter19.count() > 0){
																				for (int w20=w19+1; w20< MAX_MIRS; w20++){
																					inter20 = inter19 & mt_map.map[w20];
											if (inter20.count() > 0){
											for (int w21=w20+1; w21< MAX_MIRS; w21++){
												inter21 = inter20 & mt_map.map[w21];
												if (inter21.count() > 0){
												for (int w22=w21+1; w22< MAX_MIRS; w22++){
													inter22 = inter21 & mt_map.map[w22];
													if (inter22.count() > 0){
													for (int w23=w22+1; w23< MAX_MIRS; w23++){
														inter23 = inter22 & mt_map.map[w23];
														if (inter23.count() > 0){
														for (int w24=w23+1; w24< MAX_MIRS; w24++){
															inter24 = inter23 & mt_map.map[w24];
															if (inter24.count() > 0){
															for (int w25=w24+1; w25< MAX_MIRS; w25++){
																inter25 = inter24 & mt_map.map[w25];
																if (inter25.count() > 0){
																for (int w26=w25+1; w26< MAX_MIRS; w26++){
																	inter26 = inter25 & mt_map.map[w26];
																	if (inter26.count() > 0){
																	for (int w27=w26+1; w27< MAX_MIRS; w27++){
																		inter27 = inter26 & mt_map.map[w27];
																		if (inter27.count() > 0){
																		for (int w28=w27+1; w28< MAX_MIRS; w28++){
																			inter28 = inter27 & mt_map.map[w28];
																					int nr_intersec = inter28.count();
																					if (nr_intersec > minTargets){
																						target_names = "";
																						mir_names = "";
																						for (std::size_t b=0; b<inter28.size(); ++b){ // ****
    																					if (inter28.test(b)){ //  *****
																							target_names += mt_map.targets[(MAX_GENES-1 - b)].get_refseq();
																							target_names += ",";
																						}}		
																						fs28 << nr_intersec << ",";
					 																	mir_names += mt_map.mirs[w1].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w2].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w3].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w4].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w5].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w6].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w7].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w8].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w9].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w10].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w11].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w12].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w13].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w14].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w15].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w16].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w17].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w18].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w19].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w20].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w21].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w22].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w23].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w24].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w25].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w26].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w27].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w28].get_name();  mir_names += ",";
																						fs28 << mir_names << target_names << "\n";
																					}
																		}}
																	}}
																}}
															}}
														}}
													}}
												}}
											}}
																				}}
																			}}
																		}}
																	}}
																}}
															}}
														}}
													}}
												}}
											}}
										}}
									}}
								}}
							}}
						}}
					}}
				}}
			}}
		}
	}

	fs28.close();
}

//Print common targets of 29 mirs
void identify_29mirs_modules()
{
	ofstream fs29;
	fs29.open("./data/aux/modules_29mirs.csv");

	std::bitset<MAX_GENES> inter2, inter3, inter4, inter5, inter6, inter7, inter8, inter9, inter10, inter11, inter12, inter13, inter14, inter15, inter16, inter17, inter18, inter19, inter20,
		inter21, inter22, inter23, inter24, inter25, inter26, inter27, inter28, inter29;
	for (int w1=0; w1< MAX_MIRS; w1++){
		for (int w2=w1+1; w2< MAX_MIRS; w2++){
			inter2 = mt_map.map[w1] & mt_map.map[w2]; 
			if (inter2.count() > 0){
			for (int w3=w2+1; w3< MAX_MIRS; w3++){
				inter3 = inter2 & mt_map.map[w3];
				if (inter3.count() > 0){
				for (int w4=w3+1; w4< MAX_MIRS; w4++){
					inter4 = inter3 & mt_map.map[w4];
					if (inter4.count() > 0){
					for (int w5=w4+1; w5< MAX_MIRS; w5++){
						inter5 = inter4 & mt_map.map[w5];
						if (inter5.count() > 0){
						for (int w6=w5+1; w6< MAX_MIRS; w6++){
							inter6 = inter5 & mt_map.map[w6];
							if (inter6.count() > 0){
							for (int w7=w6+1; w7< MAX_MIRS; w7++){
								inter7 = inter6 & mt_map.map[w7];
								if (inter7.count() > 0){
								for (int w8=w7+1; w8< MAX_MIRS; w8++){
									inter8 = inter7 & mt_map.map[w8];
									if (inter8.count() > 0){
									for (int w9=w8+1; w9< MAX_MIRS; w9++){
										inter9 = inter8 & mt_map.map[w9];
										if (inter9.count() > 0){
										for (int w10=w9+1; w10< MAX_MIRS; w10++){
											inter10 = inter9 & mt_map.map[w10];
											if (inter10.count() > 0){
											for (int w11=w10+1; w11< MAX_MIRS; w11++){
												inter11 = inter10 & mt_map.map[w11];
												if (inter11.count() > 0){
												for (int w12=w11+1; w12< MAX_MIRS; w12++){
													inter12 = inter11 & mt_map.map[w12];
													if (inter12.count() > 0){
													for (int w13=w12+1; w13< MAX_MIRS; w13++){
														inter13 = inter12 & mt_map.map[w13];
														if (inter13.count() > 0){
														for (int w14=w13+1; w14< MAX_MIRS; w14++){
															inter14 = inter13 & mt_map.map[w14];
															if (inter14.count() > 0){
															for (int w15=w14+1; w15< MAX_MIRS; w15++){
																inter15 = inter14 & mt_map.map[w15];
																if (inter15.count() > 0){
																for (int w16=w15+1; w16< MAX_MIRS; w16++){
																	inter16 = inter15 & mt_map.map[w16];
																	if (inter16.count() > 0){
																	for (int w17=w16+1; w17< MAX_MIRS; w17++){
																		inter17 = inter16 & mt_map.map[w17];
																		if (inter17.count() > 0){
																		for (int w18=w17+1; w18< MAX_MIRS; w18++){
																			inter18 = inter17 & mt_map.map[w18];
																			if (inter18.count() > 0){
																			for (int w19=w18+1; w19< MAX_MIRS; w19++){
																				inter19 = inter18 & mt_map.map[w19];
																				if (inter19.count() > 0){
																				for (int w20=w19+1; w20< MAX_MIRS; w20++){
																					inter20 = inter19 & mt_map.map[w20];
											if (inter20.count() > 0){
											for (int w21=w20+1; w21< MAX_MIRS; w21++){
												inter21 = inter20 & mt_map.map[w21];
												if (inter21.count() > 0){
												for (int w22=w21+1; w22< MAX_MIRS; w22++){
													inter22 = inter21 & mt_map.map[w22];
													if (inter22.count() > 0){
													for (int w23=w22+1; w23< MAX_MIRS; w23++){
														inter23 = inter22 & mt_map.map[w23];
														if (inter23.count() > 0){
														for (int w24=w23+1; w24< MAX_MIRS; w24++){
															inter24 = inter23 & mt_map.map[w24];
															if (inter24.count() > 0){
															for (int w25=w24+1; w25< MAX_MIRS; w25++){
																inter25 = inter24 & mt_map.map[w25];
																if (inter25.count() > 0){
																for (int w26=w25+1; w26< MAX_MIRS; w26++){
																	inter26 = inter25 & mt_map.map[w26];
																	if (inter26.count() > 0){
																	for (int w27=w26+1; w27< MAX_MIRS; w27++){
																		inter27 = inter26 & mt_map.map[w27];
																		if (inter27.count() > 0){
																		for (int w28=w27+1; w28< MAX_MIRS; w28++){
																			inter28 = inter27 & mt_map.map[w28];
																			if (inter28.count() > 0){
																			for (int w29=w28+1; w29< MAX_MIRS; w29++){
																				inter29 = inter28 & mt_map.map[w29];
																					int nr_intersec = inter29.count();
																					if (nr_intersec > minTargets){
																						target_names = "";
																						mir_names = "";
																						for (std::size_t b=0; b<inter29.size(); ++b){ // ****
    																					if (inter29.test(b)){ //  *****
																							target_names += mt_map.targets[(MAX_GENES-1 - b)].get_refseq();
																							target_names += ",";
																						}}		
																						fs29 << nr_intersec << ",";
					 																	mir_names += mt_map.mirs[w1].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w2].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w3].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w4].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w5].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w6].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w7].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w8].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w9].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w10].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w11].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w12].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w13].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w14].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w15].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w16].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w17].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w18].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w19].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w20].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w21].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w22].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w23].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w24].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w25].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w26].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w27].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w28].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w29].get_name();  mir_names += ","; 
																						fs29 << mir_names << target_names << "\n";
																					}
																			}}
																		}}
																	}}
																}}
															}}
														}}
													}}
												}}
											}}
																				}}
																			}}
																		}}
																	}}
																}}
															}}
														}}
													}}
												}}
											}}
										}}
									}}
								}}
							}}
						}}
					}}
				}}
			}}
		}
	}

	fs29.close();
}

//Print common targets of 30 mirs
void identify_30mirs_modules()
{
	ofstream fs30;
	fs30.open("./data/aux/modules_30mirs.csv");

	std::bitset<MAX_GENES> inter2, inter3, inter4, inter5, inter6, inter7, inter8, inter9, inter10, inter11, inter12, inter13, inter14, inter15, inter16, inter17, inter18, inter19, inter20,
		inter21, inter22, inter23, inter24, inter25, inter26, inter27, inter28, inter29, inter30;
	for (int w1=0; w1< MAX_MIRS; w1++){
		for (int w2=w1+1; w2< MAX_MIRS; w2++){
			inter2 = mt_map.map[w1] & mt_map.map[w2]; 
			if (inter2.count() > 0){
			for (int w3=w2+1; w3< MAX_MIRS; w3++){
				inter3 = inter2 & mt_map.map[w3];
				if (inter3.count() > 0){
				for (int w4=w3+1; w4< MAX_MIRS; w4++){
					inter4 = inter3 & mt_map.map[w4];
					if (inter4.count() > 0){
					for (int w5=w4+1; w5< MAX_MIRS; w5++){
						inter5 = inter4 & mt_map.map[w5];
						if (inter5.count() > 0){
						for (int w6=w5+1; w6< MAX_MIRS; w6++){
							inter6 = inter5 & mt_map.map[w6];
							if (inter6.count() > 0){
							for (int w7=w6+1; w7< MAX_MIRS; w7++){
								inter7 = inter6 & mt_map.map[w7];
								if (inter7.count() > 0){
								for (int w8=w7+1; w8< MAX_MIRS; w8++){
									inter8 = inter7 & mt_map.map[w8];
									if (inter8.count() > 0){
									for (int w9=w8+1; w9< MAX_MIRS; w9++){
										inter9 = inter8 & mt_map.map[w9];
										if (inter9.count() > 0){
										for (int w10=w9+1; w10< MAX_MIRS; w10++){
											inter10 = inter9 & mt_map.map[w10];
											if (inter10.count() > 0){
											for (int w11=w10+1; w11< MAX_MIRS; w11++){
												inter11 = inter10 & mt_map.map[w11];
												if (inter11.count() > 0){
												for (int w12=w11+1; w12< MAX_MIRS; w12++){
													inter12 = inter11 & mt_map.map[w12];
													if (inter12.count() > 0){
													for (int w13=w12+1; w13< MAX_MIRS; w13++){
														inter13 = inter12 & mt_map.map[w13];
														if (inter13.count() > 0){
														for (int w14=w13+1; w14< MAX_MIRS; w14++){
															inter14 = inter13 & mt_map.map[w14];
															if (inter14.count() > 0){
															for (int w15=w14+1; w15< MAX_MIRS; w15++){
																inter15 = inter14 & mt_map.map[w15];
																if (inter15.count() > 0){
																for (int w16=w15+1; w16< MAX_MIRS; w16++){
																	inter16 = inter15 & mt_map.map[w16];
																	if (inter16.count() > 0){
																	for (int w17=w16+1; w17< MAX_MIRS; w17++){
																		inter17 = inter16 & mt_map.map[w17];
																		if (inter17.count() > 0){
																		for (int w18=w17+1; w18< MAX_MIRS; w18++){
																			inter18 = inter17 & mt_map.map[w18];
																			if (inter18.count() > 0){
																			for (int w19=w18+1; w19< MAX_MIRS; w19++){
																				inter19 = inter18 & mt_map.map[w19];
																				if (inter19.count() > 0){
																				for (int w20=w19+1; w20< MAX_MIRS; w20++){
																					inter20 = inter19 & mt_map.map[w20];
											if (inter20.count() > 0){
											for (int w21=w20+1; w21< MAX_MIRS; w21++){
												inter21 = inter20 & mt_map.map[w21];
												if (inter21.count() > 0){
												for (int w22=w21+1; w22< MAX_MIRS; w22++){
													inter22 = inter21 & mt_map.map[w22];
													if (inter22.count() > 0){
													for (int w23=w22+1; w23< MAX_MIRS; w23++){
														inter23 = inter22 & mt_map.map[w23];
														if (inter23.count() > 0){
														for (int w24=w23+1; w24< MAX_MIRS; w24++){
															inter24 = inter23 & mt_map.map[w24];
															if (inter24.count() > 0){
															for (int w25=w24+1; w25< MAX_MIRS; w25++){
																inter25 = inter24 & mt_map.map[w25];
																if (inter25.count() > 0){
																for (int w26=w25+1; w26< MAX_MIRS; w26++){
																	inter26 = inter25 & mt_map.map[w26];
																	if (inter26.count() > 0){
																	for (int w27=w26+1; w27< MAX_MIRS; w27++){
																		inter27 = inter26 & mt_map.map[w27];
																		if (inter27.count() > 0){
																		for (int w28=w27+1; w28< MAX_MIRS; w28++){
																			inter28 = inter27 & mt_map.map[w28];
																			if (inter28.count() > 0){
																			for (int w29=w28+1; w29< MAX_MIRS; w29++){
																				inter29 = inter28 & mt_map.map[w29];
																				if (inter29.count() > 0){
																				for (int w30=w29+1; w30< MAX_MIRS; w30++){
																					inter30 = inter29 & mt_map.map[w30];
																					int nr_intersec = inter30.count();
																					if (nr_intersec > minTargets){
																						target_names = "";
																						mir_names = "";
																						for (std::size_t b=0; b<inter30.size(); ++b){ // ****
    																					if (inter30.test(b)){ //  *****
																							target_names += mt_map.targets[(MAX_GENES-1 - b)].get_refseq();
																							target_names += ",";
																						}}		
																						fs30 << nr_intersec << ",";
					 																	mir_names += mt_map.mirs[w1].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w2].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w3].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w4].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w5].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w6].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w7].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w8].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w9].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w10].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w11].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w12].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w13].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w14].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w15].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w16].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w17].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w18].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w19].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w20].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w21].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w22].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w23].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w24].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w25].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w26].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w27].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w28].get_name();  mir_names += ",";
					 																	mir_names += mt_map.mirs[w29].get_name();  mir_names += ","; 
					 																	mir_names += mt_map.mirs[w30].get_name();  mir_names += ","; 
																						fs30 << mir_names << target_names << "\n";
																					}
																				}}
																			}}
																		}}
																	}}
																}}
															}}
														}}
													}}
												}}
											}}
																				}}
																			}}
																		}}
																	}}
																}}
															}}
														}}
													}}
												}}
											}}
										}}
									}}
								}}
							}}
						}}
					}}
				}}
			}}
		}
	}

	fs30.close();
}

