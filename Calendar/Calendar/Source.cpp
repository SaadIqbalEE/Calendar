//including libraries

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<iostream>

//universal identifers,variables
unsigned int Year;
int F_date, increment_days, month_days, month, names, ball, date = 33;
char *week, sweek[4];
char cursor = ' ';

//function for obtaing first date of the year i.e fri=0,sat=1.....
int FT_date(unsigned int Year){
	int semi_year, F_date;
	semi_year = Year % 28;
	for (int counter_1 = 0; counter_1<4; counter_1++){
		if (semi_year % 4 == counter_1){
			for (int counter_2 = 0; counter_2<7; counter_2++){
				if (semi_year / 4 == counter_2){
					if (counter_1 == 0)
						F_date = (7 + (counter_2 * 5)) % 7;
					else
						F_date = ((8 + counter_1) + (counter_2 * 5)) % 7;
					return F_date;
				}
			}
		}
	}
}

//for printing months
void month_a(int month)
{
	switch (month)
	{
	case 1:
		printf("\n\t\t\t \"JANUARY\"\n");
		break;
	case 2:
		printf("\n\t\t\t \"FEBRUARY\"\n");
		break;
	case 3:
		printf("\n\t\t\t \"MARCH\"\n");
		break;
	case 4:
		printf("\n\t\t\t \"APRIL\"\n");
		break;
	case 5:
		printf("\n\t\t\t \"MAY\"\n");
		break;
	case 6:
		printf("\n\t\t\t \"JUNE\"\n");
		break;
	case 7:
		printf("\n\t\t\t \"July\"\n");
		break;
	case 8:
		printf("\n\t\t\t \"AUGUST\"\n");
		break;
	case 9:
		printf("\n\t\t\t \"SEPTEMBER\"\n");
		break;
	case 10:
		printf("\n\t\t\t \"OCTOBER\"\n");
		break;
	case 11:
		printf("\n\t\t\t \"NOVEMBER\"\n");
		break;
	case 12:
		printf("\n\t\t\t \"DECEMBER\"\n");
		break;
	}
}

//sum of days to first of argument month
int incremental_days(unsigned int Year, int F_date, int month)
{
	int increment_days = F_date;
	for (int s_month = 2; s_month <= month; s_month++)
	{
		if (s_month == 3)
		{
			if (Year % 4 == 0)
				increment_days = increment_days + 29;
			else
				increment_days = increment_days + 28;
		}
		else
		{
			if (s_month == 5 || s_month == 7 || s_month == 10 || s_month == 12)
				increment_days = increment_days + 30;
			else
				increment_days = increment_days + 31;
		}
	}
	return increment_days;
}


//calendar of month with some specific need abilities
void month_calander(int increment_days, int month_days, int date)
{
	printf("\n\tFri\tSat\tSun\tMon\tTue\tWed\tThu\n");
	int days_counter = 0, over_all;
	over_all = month_days + (increment_days % 7);
	printf("\t");
	while (days_counter<over_all)
	{
		if ((increment_days % 7)>days_counter)
		{
			printf("\t");
		}
		else
		{
			if (date == (days_counter - (increment_days % 7) + 1))
			{
				printf("xx");
				printf("\t");
			}
			else
			{
				printf("%d", days_counter - (increment_days % 7) + 1);
				printf("\t");
			}
		}
		days_counter++;
		if (days_counter % 7 == 0)
		{
			printf("\n");
			printf("\t");
		}
	}
	printf("\n");
}



//for days of arg month
int Month_days(int month, unsigned int Year)
{
	int month_days;
	if (month == 2)
	{
		if (Year % 4 == 0)
			month_days = 29;
		else
			month_days = 28;
	}
	else
	{
		if (month == 4 || month == 6 || month == 9 || month == 11)
			month_days = 30;
		else
			month_days = 31;
	}
	return month_days;
}

//random generation of year from 1970 to 2050
unsigned int random_year(void)
{
	unsigned int Year = (rand() % 80) + 1970;
	return Year;
}

//random generation of month
int random_month(void)
{
	int month = (rand() % 12) + 1;
	return month;
}

//random generation of days of month
int random_date(int month_days)
{
	int date = (rand() % month_days) + 1;
	return date;
}

//writing in the memories.txt file
void write_r()
{
	char date[15], event_r[50];
	FILE * file_ptr;
	file_ptr = fopen("Memories.txt", "a+");
	gets_s(date);
	gets_s(event_r);
	fprintf(file_ptr, "\n    %s-------%s \n\t------------------\n", date, event_r);
	fclose(file_ptr);
}


//reading from the memories.txt file
void reading_r()
{
	FILE * file_ptr;
	int c;
	file_ptr = fopen("memories.txt", "a+");
	while (1)
	{
		c = fgetc(file_ptr);
		if (feof(file_ptr))
		{
			break;
		}
		printf("%c", c);
	}
	fclose(file_ptr);
}

//menu
void menu(){
	printf("\t\t\t\tMENU\n");
	printf("\t\t     \"Passed time never come again\"\n\n");
	printf("\t\t\t\"Calendar and much more\"\n\n");
	printf("Press 'C' to view the calander of your desired year:\n");
	printf("Press 'D' to use go to date option:\n");
	printf("Press 'G' to play friendly I.Q calendar game:\n");
	printf("Press 'M' to save the desired dates or events:\n");
	printf("Press 'V' to view the save events:\n");
	printf("Press 'Q' to quit the program:\n");
}

//for case Cc
void caseCc(){
	date = 32;
	printf("\n\n\tInsert the Year.....(0 to 65500)\nEnter:");
	scanf_s("%d", &Year);
	if (Year >= 0 && Year <= 65500){
		printf("\n");
		printf("\tYEAR:%d\n", Year);
		F_date = FT_date(Year);
		for (month = 1; month <= 12; month++){
			month_a(month);
			increment_days = incremental_days(Year, F_date, month);
			month_days = Month_days(month, Year);
			month_calander(increment_days, month_days, date);
		}
		printf("\n");
	}
	else
		printf("\n\tOut of range....\n");
}

//for case Dd
void caseDd(){
	printf("\n\n\tInsert the Year.....(0 to 65500)\nEnter:");
	scanf_s("%d", &Year);
	if (Year >= 0 && Year <= 65500){
		printf("\n\tInsert the month.....(1 to 12)\nEnter:");
		scanf_s("%d", &month);
		if (month>0 && month <= 12){
			printf("\n\tInsert the date.....(1 to 28..29..30..31)\nEnter:");
			scanf_s("%d", &date);
			printf("\n");
			F_date = FT_date(Year);
			increment_days = incremental_days(Year, F_date, month);
			month_days = Month_days(month, Year);
			if (date>0 && date <= month_days){
				month_a(month);
				month_calander(increment_days, month_days, date);
				printf("\nDay of the year:%d\n", ((increment_days - F_date) + date));
				int week_year;
				if (((increment_days - F_date) + date) % 7 == 0)
					week_year = ((increment_days - F_date) + date) / 7;
				else
					week_year = (((increment_days - F_date) + date) / 7) + 1;
				printf("Week of the year:%d\n", week_year);
				names = (increment_days + date - 1) % 7;
				week = "AAA";
				switch (names){
				case 0:
					week = "FRI";
					break;
				case 1:
					week = "SAT";
					break;
				case 2:
					week = "SUN";
					break;
				case 3:
					week = "MON";
					break;
				case 4:
					week = "TUE";
					break;
				case 5:
					week = "WED";
					break;
				case 6:
					week = "THU";
					break;
				}
				printf("Crossponding date:%s", week);
				printf("\n");
			}
			else
				printf("Error in date input....");
		}
		else
			printf("Error in month input....");
	}
	else
		printf("Error in year input....");
}

//for caseGg
void caseGg()
{
	printf("\n\nARE YOU READY....press any key to continue....\n");
	_getch();
	Year = random_year();
	F_date = FT_date(Year);
	month = random_month();
	increment_days = incremental_days(Year, F_date, month);
	month_days = Month_days(month, Year);
	date = random_date(month_days);
	printf("\n\n\t\tFORMAT:\tDD:MM:YY\n");
	printf("\t\t\t%d:%d:%d", date, month, Year);
	names = (increment_days + date - 1) % 7;
	switch (names)
	{
	case 0:
		week = "FRI";
		break;
	case 1:
		week = "SAT";
		break;
	case 2:
		week = "SUN";
		break;
	case 3:
		week = "MON";
		break;
	case 4:
		week = "TUE";
		break;
	case 5:
		week = "WED";
		break;
	case 6:
		week = "THU";
		break;
	}
	printf("\n\n\t ENTER the day name:");
	printf("\nDay names like: MON,TUE,WED,THU,FRI,SAT,SUN\n");
	for (ball = 1; ball <= 3; ball++)
	{
		printf("\n\tEnter:");
		gets_s(sweek);
		if (strcmp(sweek, week) == 0)
		{
			printf("\n\tYou enter correct...\n");
			break;
		}
		else
		{
			if (ball<3)
				printf("\n\tNot correct...Try again\n");
		}
	}
	if (ball == 4)
		printf("\n\"Better luck nxt time\"...Crossponding date:%s", week);
	else
		printf("\n\"Congratzzz\nNo. of Tries are: %d\n\"...Crossponding date:%s", ball, week);
	printf("\n");
}

//for caseMm
void caseMm(){
	printf("\nFirst enter the date and then press enter\n");
	printf("Nxt enter the event and then press enter\n\n");
	write_r();
	printf("\n\n");
}

//for caseVv
void caseVv(){
	printf("\n\tHere is tour beloved memories\n\n");
	reading_r();
	printf("\n\n");
}

//for caseQq
void caseQq(){
	printf("Are you sure:.....(Y/N)");
	while (cursor != 'Y'&& cursor != 'N'&& cursor != 'y'&& cursor != 'n'){
		cursor = _getch();
	}
	if (cursor == 'N' || cursor == 'n')
		cursor = ' ';
	else
		cursor = 'q';
}

//for check weather user continue or quit
void loopLl()
{
	if (cursor != 'q'&& cursor != 'Q'){
		printf("\n\nPress 'Y' to continue and 'N' to quit.....\n\n");
		cursor = 'A';
		while (cursor != 'Y'&& cursor != 'N'&& cursor != 'y'&& cursor != 'n'){
			cursor = _getch();
		}
		if (cursor == 'Y' || cursor == 'y'){
			system("cls");
			cursor = ' ';
		}
		else
			cursor = 'q';
	}
}


//main
void main()
{
	srand(time(NULL));
	while (cursor != 'Q'&& cursor != 'q'){
		menu();
		while (cursor == ' ' || cursor == '\n' || cursor == '\t'){
			cursor = _getch();
		}
		switch (cursor){
		case'C':
		case'c':
			caseCc();
			break;
		case'D':
		case'd':
			caseDd();
			break;
		case'G':
		case'g':
			caseGg();
			break;
		case'M':
		case'm':
			caseMm();
			break;
		case'V':
		case'v':
			caseVv();
			break;
		case'Q':
		case'q':
			caseQq();
			break;
		default:
			printf("\n\tERROR............You enter wrong\n\n");
			break;
		}
		loopLl();
	}
}