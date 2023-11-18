// This project is to develop a system for online bus ticketing
// The developer of this project are
//		i. Moganesan a/l Veragu CB19095



#include <stdio.h>
#include <stdlib.h>

 // variable declaration
int i,num_of_tickets;
void front(void);
void login (void);
void indvdticket(void);
void multipletickets(void);
void ticketdetail(void);
float prices(int bus_num,int noSeats);
char print;

int main()
{
    int menuOption;

    system("cls");
    FILE *fp;
    fp=fopen("book.txt","w");
    front();
    login();
    start:
    system("cls");
	printf("\n=================================\n");
	printf("    BUS ONLINE BOOKING SYSTEM     ");
	printf("\n=================================");
	printf("\n1>> Book One Ticket");
	printf("\n------------------------");
	printf("\n2>> Book Multiple Tickets");
	printf("\n------------------------");
	printf("\n3>> View All Available Buses");
	printf("\n------------------------");
	printf("\n4>> Review All Booked Tickets");
	printf("\n------------------------");
	printf("\n5>> Exit");
	printf("\n------------------------");
	printf("\n\n-->");
	scanf("%d",&menuOption);

if(menuOption==1)
{
    indvdticket();
    goto start;
}else
if(menuOption==2)
{
    multipletickets();
    goto start;
}else
if(menuOption==3)
{
    ticketdetail();
    printf("\n\nPress Enter to return to Main Menu..");
    getch();
    goto start;
}else
if(menuOption==4)
{
    int c;
    system("cls");
    fopen("book.txt","r");
    fp = fopen("book.txt","r");
    if (fp)
    {
    while ((c = getc(fp)) != EOF)
        putchar(c);
    fclose(fp);
    }
    printf("\nPress Enter to return to Main Menu..");
    getch();
    goto start;
}

else
if(menuOption==5)
{
    system("cls");
    printf("Thank you for using our Bus Online Booking System!!");

    return 0;
}
else
{
    printf("\nInvalid choice");
    printf("\n\nPress Enter to return to Main Menu..");
    getch();
    goto start;
}
}
void front(void)//This is the main interface for the program
{
    printf("\t\t=================================================\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|           BUS ONLINE BOOKING SYSTEM           |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|        Login ID:book                          |\n");
	printf("\t\t|        Password:bus                           |\n");
	printf("\t\t=================================================\n\n\n");

    printf("Press Enter to continue...");
    getchar();
    system("cls");

    FILE *fp;
    fp=fopen("book.txt","a");
    fprintf(fp,"======================================================================================================================");
	fprintf(fp,"\nBus No  Company                 Journey                        Price      Departure Time       Features Available\n");
	fprintf(fp,"======================================================================================================================");
    fprintf(fp,"\n1011    LA Holidays             Sungai Petani to TBS           RM 45.10   8:00am               WiFi,Charger");
	fprintf(fp,"\n1012    SANI Express            Ipoh to Penang Sentral         RM 20.10   11.00pm              Charger");
	fprintf(fp,"\n1013    Utama Express           Kuantan to TBS                 RM 24.00   1:00pm               Charger");
	fprintf(fp,"\n1014    Maraliner               TBS To Cameron Highlands       RM 38.00   11:30am              WiFi,Charger");
	fprintf(fp,"\n1015    Transnasional Express   Melaka to Alor Setar           RM 58.00   4:00pm               WiFi,Charger");
	fprintf(fp,"\n1016    Cosmic Express          Gurun to Hentian Duta          RM 45.00   8.30pm               Charger");
    fprintf(fp,"\n1017    Plusliner Express       Butterworth to Kajang          RM 37.00   8.30pm               Charger");
    fprintf(fp,"\n1018    Cepat Express           Genting Highlands to Singapore RM 78.00   11:30pm              WiFi,Charger");
    fprintf(fp,"\n1019    Supernice Grassland     KL Sentral to Kangar           RM 55.00   7:00am               Charger");
    fprintf(fp,"\n1020    Alisan Golden Coach     Kangar to Kuantan              RM 67.00   1:00pm               Wifi,Charger\n\n");
    fclose(fp);

    return;
}
void login(void)//This will enable user to login and enable user to enter the interface
{
    char loginID[20],password[20];
    int count;
    do
{
    printf("\n  =======================  LOGIN FORM  =======================\n  ");
    printf(" \n                       ENTER LOGINID:-");
	scanf("%s", &loginID);
	printf(" \n                       ENTER PASSWORD:-");
	scanf("%s",&password);
if(strcmp(loginID,"book")==0 && strcmp(password,"bus")==0)
{
    printf("  \n\n\n            =============   WELCOME   ==============");
	printf("\n\n\n\t\t\t\tPress Enter to continue...");
	getch();
	count=0;
	system("cls");
	return;
}else
{
    printf("\n        SORRY,INVALID LOGINID/PASSWORD.");
    printf("\n        PLEASE TRY LOGIN AGAIN. (LOGINID:book    PASSWORD:bus)");
    count=1;
    getch();
    system("cls");
}
}while(count==1);
}

void ticketdetail(void)//This  is the details of the bus information
{
    system("cls");
	printf("======================================================================================================================");
	printf("\nBus No  Company                 Journey                        Price      Departure Time       Features Available\n");
	printf("======================================================================================================================");
    printf("\n1011    LA Holidays             Sungai Petani to TBS           RM 45.10   8:00am               WiFi,Charger");
	printf("\n1012    SANI Express            Ipoh to Penang Sentral         RM 20.10   11.00pm              Charger");
	printf("\n1013    Utama Express           Kuantan to TBS                 RM 24.00   1:00pm               Charger");
	printf("\n1014    Maraliner               TBS To Cameron Highlands       RM 38.00   11:30am              WiFi,Charger");
	printf("\n1015    Transnasional Express   Melaka to Alor Setar           RM 58.00   4:00pm               WiFi,Charger");
	printf("\n1016    Cosmic Express          Gurun to Hentian Duta          RM 45.00   8.30pm               Charger");
    printf("\n1017    Plusliner Express       Butterworth to Kajang          RM 37.00   8.30pm               Charger");
    printf("\n1018    Cepat Express           Genting Highlands to Singapore RM 78.00   11:30pm              WiFi,Charger");
    printf("\n1019    Supernice Grassland     KL Sentral to Kangar           RM 55.00   7:00am               Charger");
    printf("\n1020    Alisan Golden Coach     Kangar to Kuantan              RM 67.00   1:00pm               Wifi,Charger\n\n");
}

void indvdticket(void)//Ticket for individual user booked through this
{
    char passengerName[30];
    int bus_num, noSeats;
    float charges,*totalcharges;
    char confirm;
    FILE *fp;
    fp=fopen("book.txt","a");
    fprintf(fp,"\n----------------------------------------\n");
    fprintf(fp,"Individual Ticket Booking\n");
    fprintf(fp,"----------------------------------------\n");

    system("cls");
	noSeats=1;
	printf("\n\n>>Press Enter To View All Buses<< ");
	getch();
	system("cls");
	ticketdetail();
    printf("\nEnter Your Name:> ");
	fflush(stdin);
	gets(passengerName);
	fprintf(fp,"Passenger Name: %s",passengerName);
	printf("\n\nEnter bus number:> ");
	fprintf(fp,"\nNumber of seat: 1");
	start1:
	scanf("%d",&bus_num);
	fprintf(fp,"\nBus Number: %d",bus_num);

	if(bus_num>=1011 && bus_num<=1020)
	{
		charges=prices(bus_num,noSeats);
        totalcharges=&charges;
        fprintf(fp,"\nTicket price: RM %.2f\n\n",*totalcharges);
	}
	else
	{
		printf("\nInvalid Bus Number!Please Enter again--> ");
		fprintf(fp,"\n**Correction! Bus number %d are invalid.\nLatest bus number are below:",bus_num);
		fclose(fp);
		goto start1;
	}

	printf("\n\nConfirm Ticket (y/n):>");
	start:
	scanf(" %c",&confirm);
	if(confirm == 'y')
	{
		printf("Passenger Name:%s\t\tNumber of seats: %d\t\Bus Number: %d\t\t%Price: RM%.2f\n",passengerName,noSeats,bus_num,charges);
        printf("\nTotal Price: \t\t\t\t\t\t RM%.2f",*totalcharges);
		printf("\n==============================================================================");
		printf("                             \n Booking Done\n");
		printf("==============================================================================");
		printf("\nDo you wish to print your tickets?: (y/n): ");
		fflush(stdin);
		scanf("%c",&print);
		if(print=='y')
        {
            system("cls");
            printf("-----------------------------------------\n");
            printf("\tTICKET\n");
            printf("-----------------------------------------\n\n");
            printf("Name:\t\t\t%s",passengerName);
            printf("\nNumber Of Seats:\t%d",noSeats);
            printf("\nBus Number:\t\t%d",bus_num);
            printf("\nCharges:\t\t%RM %.2f\n",charges);
            printf("\n\n-----------------------------------------");
            printf("\nTotal price:\t\tRM %.2f\n",charges);
            printf("\-----------------------------------------");
            printf("\nPress any key to return to Main menu");
            getch();
            fclose(fp);
            return;
        }else
        {
            fclose(fp);
            return;
        }}
	else
	{
		if(confirm=='n')
		{
			printf("\nBooking Not Done!\nPress any key to return to  Main menu!");
			fprintf(fp,"**CORRECTION! This multiple booking ticket is ABORTED! (You didn't confirm the ticket!)");
			fclose(fp);
			getch();
            return;
		}
		else
		{
			printf("\nInvalid choice entered! Enter again-----> ");
			goto start;
		}
	}
}
float prices(int bus_num,int noSeats)//calculation of the prices of the tickets
{
    if (bus_num==1011)
	{
		return(45.10*noSeats);
	}else
	if (bus_num==1012)
	{
		return(20.10*noSeats);
	}else
	if (bus_num==1013)
	{
		return(24.00*noSeats);
	}else
	if (bus_num==1014)
	{
		return(38.00*noSeats);
	}else
	if (bus_num==1015)
	{
		return(58.00*noSeats);
	}else
	if (bus_num==1016)
	{
		return(45.00*noSeats);
	}else
	if (bus_num==1017)
	{
		return(37.00*noSeats);
	}else
	if (bus_num==1018)
	{
		return(78.00*noSeats);
	}else
	if (bus_num==1019)
	{
		return(55.00*noSeats);
	}else
	if (bus_num==1020)
    {
        return(67.00*noSeats);
    }
}
void multipletickets(void)//multiple booking of the tickets are calculated through this
{
    char passengerName[100][30];
    int bus_num[50],noSeats[50];
    float totalcharges=0,price[i],*pprice[i],charges;
    char confirm;

    FILE *fp;
	fp=fopen("book.txt","a");

    system("cls");
    printf("How many tickets you wish to purchase?: ");
    scanf("%d",&num_of_tickets);
    fprintf(fp,"\n---------------------------------------------------------------------");
for(i=0;i<num_of_tickets;i++)
{
	noSeats[i]=1;
	printf("\n>>Press Enter To View All Buses<< ");
	getch();
    fprintf(fp,"\n----------------------------------------\n");
    fprintf(fp,"Multiple Ticket booking\n");
    fprintf(fp,"----------------------------------------\n");

	system("cls");
	ticketdetail();
    printf("\nPassenger Name %d:> ",i+1);
	fflush(stdin);
	gets(passengerName[i]);
	fprintf(fp,"Passenger Name %d: %s",i+1,passengerName[i]);
	printf("\n\nEnter bus number %d:> ",i+1);
	start1:
	scanf("%d",&bus_num[i]);
	fprintf(fp,"\nBus Number %d: %d",i+1,bus_num[i]);
	if(bus_num[i]>=1011 && bus_num[i]<=1020)
	{
		charges=prices(bus_num[i],noSeats[i]);
		price[i]=charges;
		pprice[i]=&price[i];
        totalcharges=totalcharges+charges;
        fprintf(fp,"\nTicket price: RM %.2f\n\n",*pprice[i]);
	}
	else
	{
		printf("\nInvalid bus Number! Enter again--> ");
		fprintf(fp,"\n**Correction! Bus number %d are invalid.\nLatest bus number are below:",bus_num[i]);
		goto start1;
	}
}
	printf("\n\nConfirm Ticket (y/n):>");
	start:
	scanf(" %c",&confirm);
	if(confirm == 'y')
	{
    for(i=0;i<num_of_tickets;i++)
    {
		printf("Passenger Name %d:%s\t\tNumber of seats: %d\t\Bus Number %d: %d\t\t%Price: RM%.2f\n",i+1,passengerName[i],noSeats[i],i+1,bus_num[i],price[i],*pprice[i]);
    }
        printf("\nTotal Price: \t\t\t\t\t\t RM%.2f",totalcharges);
        fprintf(fp,"\n---------------------------------------------------------------------\n");
        fprintf(fp,"Total Ticket Price: RM %.2f",totalcharges);
        fprintf(fp,"\n---------------------------------------------------------------------\n");
        fprintf(fp,"---------------------------------------------------------------------\n\n");
		printf("\n==============================================================================");
		printf("                             \n Booking Done\n");
		printf("==============================================================================");
		printf("\nDo you wish to print your tickets?: (y/n): ");
		fflush(stdin);
		scanf("%c",&print);
		if(print=='y')
        {
            system("cls");
            for(i=0;i<num_of_tickets;i++)
            {
            printf("-------------------\n");
            printf("\tTICKET %d\n",i+1);
            printf("-------------------\n\n");
            printf("Name:\t\t\t%s",passengerName[i]);
            printf("\nNumber Of Seats:\t%d",noSeats[i]);
            printf("\nBus Number:\t\t%d",bus_num[i]);
            printf("\nCharges:\t\t%RM %.2f\n",price[i]);
            }
            printf("\n\n-----------------------------------------");
            printf("\nTotal price:\t\tRM %.2f\n",totalcharges);
            printf("\-----------------------------------------");
            printf("\nPress any key to return to Main menu");
            getch();
            fclose(fp);
            return;
        }else
        {
        printf("\nPress any key to go back to Main menu");
		getch();
		fclose(fp);
		return;
        }
	}else
	{
		if(confirm=='n')
		{
			printf("\nBooking Not Done!\nPress any key to return to  Main menu!");
			fprintf(fp,"\n**Correction! This ticket is ABORTED! (You didn't confirm the ticket!)");
			fclose(fp);
			getch();
            return;
		}
		else
		{
			printf("\nInvalid choice entered! Enter again-----> ");
			goto start;
		}
	}
}
