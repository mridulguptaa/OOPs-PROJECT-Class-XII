//#include<iostream>
//#include<conio.h>
//#include<stdio.h>
//#include<fstream.h>
//#include<string.h>
//#include<stdlib.h>
//#include<iomanip.h>
#include<bits/stdc++.h>


/****************************************************************************
*	              Structure for Details of Crime of Criminal                 *
****************************************************************************/
struct court
{
	char  crime[20];
	char  act[20];
	char cour[20];
	char state[20];
};

/****************************************************************************
*			    Structure for Physical Description of Criminal                 *
****************************************************************************/
struct Description
{
	char colour[20];
	char face[20];
	char imark[20];          //IDENTIFICATION MARKS(DEFORMITIES ETC.)
	char  height[6];
};

/****************************************************************************
*  					  Structure  for Details of F.I.R.                        *
****************************************************************************/
struct police
{
	char station[50];
	char fir_no[10];
	char date_arrest[9];
};

/****************************************************************************
*        Class  ' CRIMINAL '  for  getting  all  information  about         *
*        Convict  and                                                       *
****************************************************************************/
class Criminal
{
	char name[20];
	char sex;
	char conno[10];
	char age[4];
	char address[50];           //ADDRESS OF CRIMINAL BEFORE ARREST.
	court court;
	police police;
	Description des;

	public:
	void input(void);
	void output(void);
	void display();
	void remove();
	int  menu();
	void modify();
	void list();
	void empty();
	int concheck(char b[]);
};

// ====================> End of Class Criminal<=============================


/****************************************************************************
*             Function for getting Convicts Record                          *
****************************************************************************/
void Criminal::input(void)
{
	this->empty();
	Criminal x;
	int c = 0 ;
	fstream filin;
	filin.open("jail.txt",ios::app|ios::binary);
	do {
		cout<<"\n ENTER THE CONVICT CODE : ";
		gets(this->conno);
	} while(x.concheck(this->conno)==0);

	cout<<"\n ENTER NAME OF CONVICT : ";
	gets(this->name);

	cout<<"\n ENTER SEX(M/F) : ";
	cin>>sex;

	cout<<"\n Enter  Address : ";
	gets(this->address);

	cout<<"\n ENTER AGE : ";
	gets(this->age);

	clrscr();

	cout<<"\n ENTER DESCRIPTION : \n\n\t ";

	cout<<"\nENTER COLOUR: ";
	gets(this->des.colour);

	cout<<"\n FACE DESCRIPTION:  ";
	gets(this->des.face);

	cout<<"\n ENTER HEIGHT(in cm's) : ";
	gets(this->des.height);


	cout<<"\nENTER IDENTIFICATION MARKS(if no distinguishing marks,enter NONE):";
	gets(this->des.imark);

	clrscr();

	cout<<"ENTER  : \n\n\t\t ";
	cout<<"court (from which the prisonor convicted) : ";
	gets(this->court.cour);

	cout<<"\n\t\t STATE : ";
	gets(this->court.state);

	cout<<"\n\t\t CRIME : ";
	gets(this->court.crime);

	cout<<"\n\t\t ACT (under which convicted) : ";
	gets(this->court.act);

	clrscr();

	cout<<"\n ENTER : \n\n\t\t";
	cout<<"\n\t\t  COMPLETE ADDRESS OF police STATION : ";
	gets(this->police.station);

	cout<<"\n\t\t FIR NO. (under which convict was arressted): ";
	gets(this->police.fir_no);

	cout<<"\n\t\t ENTER DATE OF ARREST(dd/mm/yy) :";
	gets(this->police.date_arrest);

	char ch;
	do {
		cout<<"\n DO YOU WANT TO SAVE THIS INFORMATION(enter y or n)  ";
		cin>>ch;

		if(ch=='y'||ch=='Y')
		{
			cout<<"\n\n\t< RECORD HAS BEEN SAVED >";
			filin.write((char*)this,sizeof(Criminal));
		}
	} while((ch!='y')&&(ch!='Y')&&(ch!='n')&&(ch!='N'));
	filin.close();

}//End of input function


/***************************************************************************
*                Function for showing Convict's Record                     *
***************************************************************************/
void Criminal::output()
{
	clrscr();
	cout<<"@@@@@@@@@@@@@PERSONAL RECORD OF CONVICT NO@@@@@@@@@@@@@@@@@@@@@@@@@@";
	cout<<"\n\nCONVICT NO             :\t";
	puts(conno);
	cout<<"\nNAME                   :\t";
	puts(this->name);
	cout<<"\nSEX                    :\t"<<this->sex;
	cout<<"\n\nADDRESS                :\t";
	puts(this->address);
	cout<<"\nAGE                    :\t";
	puts(this->age);
	cout<<"\n\nDESCRIPTION\n";
	cout<<"\n1. COLOUR              :\t";
	puts(this->des.colour);
	cout<<"\n2. FACE                :\t";
	puts(this->des.face);
	cout<<"\n3. IDENTIFICATION MARK :\t";
	puts(this->des.imark);
	cout<<"\n4. HEIGHT              :\t";
	puts(this->des.height);

	cout<<"\n\n\n\n\n\t\t\t\t\t\t press a key to continue....";
	getche();
	clrscr();

	cout<<"@@@@@@@@@@@@ CRIMINAL RECORD @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	cout<<"\n\ncourt INFORMATION\n\n ";
	cout<<"\n1. court FROM WHICH CONVICTED :\t";
	puts(this->court.cour);
	cout<<"\n2. STATE                      :\t";
	puts(this->court.state);
	cout<<"\n3. CRIME                      :\t";
	puts(this->court.crime);
	cout<<"\n4. ACT UNDER WHICH CONVICTED  :\t";
	puts(this->court.act);

	cout<<"\n\n\n\n\n\t\t\t\t\t\t press a key to continue....";
	getche();
	clrscr();

	cout<<"@@@@@@@@@@@@ CRIMINAL RECORD @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	cout<<"\n\n\npolice INFORMATION \n\n";
	cout<<"\n1. FIR NO.                              :\t";
	puts(this->police.fir_no);
	cout<<"\n2. DATE OF ARREST                       :\t";
	puts(this->police.date_arrest);
	cout<<"\n\n3. police STATION(where fir was lodged) :\t";
	puts(this->police.station);
	cout<<"\n\n\n\n\n\t\t\t\t\t\t press a key to continue....";
	getche();
	clrscr();
}//end of output function


/***************************************************************************
*              Function for Deleting The Record OF A Convict               *
***************************************************************************/


//----------------------------------------------------------------------------------
void Criminal::display()
{
	clrscr();
	char N[10];
	int rec;
	int loc;
	cout<<"\n ENTER THE CONVICT CODE OF CONVICT ";
	cout<<" WHOSE INFORMATION YOU WANT  :";
	gets(N);
	fstream file;
	file.open("jail.txt",ios::in|ios::binary);
	while(file.read((char*)this,sizeof(Criminal)))
	{
		if(strcmp(N,conno)==0)
		{
			this->output();
			break;
		}
	}
	file.close();
}

//-------------------------------------------------------------------------------------------------------------------------
void Criminal::remove()
{
	clrscr();
	char cno[10];
	int s;
	cout<<"\n ENTER THE CONVICT NO. OF THE CONVICT WHOSE RECORD YOU WISH TO DELETE";
	gets(cno);

	fstream filin;
	filin.open("jail.txt",ios::in);

	fstream temp;
	temp.open("temp.dat",ios::out);
	while(filin.read((char*)this,sizeof(Criminal)))
	{
		if(strcmp(cno,conno)!=0)
		{
			temp.write((char*)this,sizeof(Criminal));
		}
	}
	filin.close();
	temp.close();

	filin.open("jail.txt",ios::out);
	temp.open("temp.dat",ios::in);
	while(temp.read((char*)this,sizeof(Criminal)))
	{
		filin.write((char*)this,sizeof(Criminal));
	}
	filin.close();
	temp.close();
	cout<<"\n\n  < THE RECORD HAS BEEN DELETED >";
}

//---------------------------------------------------------------------------------------------------------------------------
int Criminal::menu()
{
	int ch;
	do{
		clrscr();
		cout<<"\n @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ MAIN MENU @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
		cout<<"\n PRESS :\n\n";
		cout<<"\n\t\t\t1. TO ADD RECORD/RECORDS  ";
		cout<<"\n\t\t\t2. TO MODIFY RECORD/RECORDS  ";
		cout<<"\n\t\t\t3. TO DISPLAY RECORD  ";
		cout<<"\n\t\t\t4. TO DELETE RECORD  ";
		cout<<"\n\t\t\t5. TO LIST  ";
		cout<<"\n\t\t\t6. TO QUIT \n ";
		cin>>ch;
	} while((ch!=1)&&(ch!=2)&&(ch!=3)&&(ch!=4)&&(ch!=5)&&(ch!=6));
	return(ch);
}

//------------------------------------------------------------------------------------------
void Criminal::modify()
{
	clrscr();
	char cno[10];
	cout<<"\nENTER THE CONVICT NUMBER OF THE CONVICT ,TO BE MODIFIED: ";
	gets(cno);

	fstream file ;
	file.open("jail.txt",ios::in|ios::binary|ios::out);
	int pos = 0;
	while(file.read((char*)this,sizeof(Criminal)))
	{
		if(strcmp(cno,this->conno)==0)
		{
			file.seekp(pos,ios::beg);
			cout<<"\n ENTER THE MODIFIED COURT RECORD:  ";
			cout<<"\n ACT  :";
			gets(court.act);

			cout<<"\nSTATE : ";
			gets(court.state);

			cout<<"\ncourt : ";
			gets(court.cour);

			cout<<"\n ENTER THE MODIFIED CRIME      :";
			gets(court.crime);

			clrscr();
			cout<<"\n ENTER THE  MODIFIED POLICE RECORD  ";
			cout<<"\n STATION : ";
			gets(police.station);

			cout<<"\nFIR NO   : ";
			gets(police.fir_no);

			cout<<police.station;
			cout<<"\n DATE OF ARREST(dd/mm/yy)  ";
			gets(police.date_arrest);

			file.write((char*)this,sizeof(Criminal));
			break;
		}
		pos = file.tellg();
	}
	file.close();
}

//---------------------------------------------------------------------------------------------
void Criminal::list()
{
	clrscr();
	int j ;
	fstream file;
	file.open("jail.txt",ios::in|ios::binary);
	cout<<"                            "<<endl;
	cout<<"		                                 "<<endl;
	cout<<"                                CONVICT  LIST    "<<endl;
	cout<<"			                         "<<endl;
	cout<<"                            "<<endl;
	cout<<"\n================================================================================"<<endl;
	cout<<"NAME\t\t\tCONVICT NO.\t\t\tCRIME"<<endl;
	cout<<"================================================================================"<<endl;
	while(file.read((char*)this,sizeof(Criminal)))
	{
		cout<<this->name<<"\t\t\t    "<<this->conno<<"\t\t\t        "<<this->court.crime;
		cout<<"\n--------------------------------------------------------------------------------\n";
	}
	file.close();
}

//---------------------------------------------------------------------------------------------------
void Criminal::empty()
{
	int i;
	name[0]='\0';
	conno[0]='\0';
	sex=' ';
	age[0]='\0';
	address[0]='\0';
	court.cour[0]='\0';
	court.crime[0]='\0';
	court.act[0]='\0';
	court.state[0]='\0';
	des.colour[0]='\0';
	des.imark[0]='\0';
	des.face[0]='\0';
	des.height[0]='\0';
	police.station[0]='\0';
	police.fir_no[0]='\0';
	police.date_arrest[0]='\0';
}
//----------------------------------------------------------------------------------------------------------

int Criminal::concheck(char b[])
{
	fstream  file;char a[10];
	int check=0;
	file.open("jail.txt",ios::in|ios::ate);
	int q=file.tellg();
	int size=q/sizeof(Criminal);
	file.seekg(0,ios::beg);
	for(int i=0;i<size;i++)
	{
		file.read((char*)this,sizeof(Criminal));
		if(strcmp(b,conno)==0)
		{
			cout<<"\n GIVEN CONVICT CODE ALREADY EXISTS!! "<<endl;
			file.close();
			return(0);
		}
	}
	return(1);
}


void main()
{
	clrscr();
	cout<<"\nCRIMINAL RECORD .\n\n\t\t\t< by MRIDUL GUPTA>\n\n\n\n\n\n\n\n\t\t\t\t";
	for(int i=2;i>=0;i--)
	{
		cout<<"ENTER PASSWORD..";
		char *pass;
		cin>>pass;
		if(strcmp(pass,"123")==0)
		{
			break;
		} else
		{
			cout<<"\nYou have "<< i << " chance remaining.\n";
			if(i==0)
			{
				exit(0);
			}
		}
	}
	Criminal criminal;
	char ans;
	do {
		int choice = criminal.menu();
		switch(choice)
		{
			case 1:
				criminal.input();
				break;
			case 2:
				criminal.modify();
				break;
			case 3:
				criminal.display();
				break;
			case 4:
				criminal.remove() ;
				break;
			case 5:
				criminal.list();
				break;
			case 6:
				exit(0);
		}
		cout<<"\n\n\nDO YOU WANT TO CONTINUE(press y to continue)..";
		ans=getch();
	} while((ans=='y'|| ans=='Y'));
}
