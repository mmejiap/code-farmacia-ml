#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <math.h>

#define NLINE 3819722
#define NVAL 7

using namespace std;


void LoadProcessedData();

void LoadProcessedData(){
	string line;
	static string arrstring[NLINE][NVAL];
	int sDataLine;

	//////////////////////////////////////
	ifstream datainp("ProcDatDataRows.txt",ifstream::in);
	int i=0;

	datainp>>sDataLine;

	cout<<"sDataLine:"<<sDataLine<<endl;

	double cpu0 = clock();

	if(datainp){
		string token;
		stringstream iss;
		while(getline(datainp,line)){
			iss<<line;
			int j=0;
			while(getline(iss,token,'|')){
				arrstring[i][j]=token;
				//if(i==1) cout<<"j: "<<j<<",a: "<<token<<", "<<arrstring[i][j]<<endl;
				j++;
			}
			i++;
			iss.clear();
		}
	}

	double cpu1=clock();

	cout<<"CPU Time 01 = "<<(cpu1-cpu0)/CLOCKS_PER_SEC<<endl;
	///////////////////////////////////////////////////////////
	//
	
	ifstream datainp02("ProdDatXTabRows.tzt",ifstream::in);	
	i=0;
	datainp02>>sDataLine;
	cout<<"sDataLine:"<<sDataLine<<endl;
	double cpu2 = clock();
	if(datainp02){
		string token;
		stringstream iss;
		while(getline(datainp02,line)){
			iss<<line;
			int j=0;
			while(getline(iss,token,'|')){
				arrstring[i][j]=token;
				j++;
			}
			i++;
			iss.clear();
		}
	}
	double cpu3=clock();
	cout<<"CPU Time 02 = "<<(cpu3-cp2)/CLOCKS_PER_SEC<<endl;
}

int main(){
	
	LoadProcessedData();

	return 0;
}
