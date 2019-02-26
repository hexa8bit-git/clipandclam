#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<windows.h>

using namespace std;

void gotoxy(int x, int y)
{
  	static HANDLE h = NULL;  
  	if(!h)
    	h = GetStdHandle(STD_OUTPUT_HANDLE);
  	COORD c = { x, y };  
  	SetConsoleCursorPosition(h,c);
}

void clip(float vin, float bias, float vdiode){
	int op;
	cout<<"Select from the following options of clipper circuit:\n1) Positive Clipper with negative bias.\n2) Positive Clipper with positive bias.\n3) Negative Clipper with positive bias.\n4) Negative Clipper with negative bias.\n5) Combination Clipper.\n";
	cin>>op;
	switch(op){
		case 1:cout<<"V(max)= -"<<bias-vdiode<<"\nV(min)= -"<<vin/2<<"\nAmplitude= "<<(vin/2)-(bias-vdiode)<<"\n";
				break;
		case 2:cout<<"V(max)= "<<bias+vdiode<<"\nV(min)= -"<<vin/2<<"\nAmplitude= "<<(vin/2)+(bias+vdiode)<<"\n";
				break;
		case 3:cout<<"V(max)= "<<vin/2<<"\nV(min)= "<<bias-vdiode<<"\nAmplitude= "<<(vin/2)-(bias-vdiode)<<"\n";
				break;
		case 4:cout<<"V(max)= "<<vin/2<<"\nV(min)= -"<<bias+vdiode<<"\nAmplitude= "<<(vin/2)+(bias+vdiode)<<"\n";
				break;
		case 5:cout<<"V(max)= "<<bias+vdiode<<"\nV(min)= -"<<bias+vdiode<<"\nAmplitude= "<<2*(bias+vdiode)<<"\n";
				break;
		default:cout<<"Oops wrong option please try again\n";
				break;
	}
}

void clam(float vin, float bias){
	int op;
	cout<<"Select from the following options of clamper circuit:\n1) Simple positive clamper.\n2) Simple negative clamper.\n3) Positive clamper with negative bias.\n4) Negative Clamper with positive bias.\n";
	cin>>op;
	switch(op){
		case 1:cout<<"V(out)= "<<vin/2<<"\n";
				break;
		case 2:cout<<"V(out)= -"<<vin/2<<"\n";
				break;
		case 3:cout<<"V(max)= "<<(vin/2)-bias<<"\nV(min)= -"<<bias<<"\nAmplitude= "<<vin/2<<"\n";
				break;
		case 4:cout<<"V(max)= "<<bias<<"\nV(min)= -"<<(vin/2)-bias<<"\nAmplitude= "<<vin/2<<"\n";
				break;
		default:cout<<"Oops wrong option please try again\n";
				break;
	}
}

int main(){
	gotoxy(8,0);
	cout<<"Welcome to the output generator of Clipper and Clamper circuits\n\n";
	char ch;
	do{
		cout<<"Select the type of circuit you want to perform on:\n1)Clipper.\n2)Clamper.\n";
		float vin,vdiode,bias;
		int op;
		cin>>op;
		system("cls");
		cout<<"Enter the Input Voltage, the diode voltage and the bias voltage\n";
		cin>>vin>>vdiode>>bias;
		switch(op){
			case 1:clip(vin,bias,vdiode);
					break;
			case 2:clam(vin,bias);
					break;
			default:cout<<"Ohoo wrong input\n";
					break;
		}
		cout<<"Do you want to continue?(y/n)\n";
		cin>>ch;
		system("cls");
	}while(ch=='Y'||ch=='y');
}

