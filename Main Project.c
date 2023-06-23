#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct passenger {
	char name[10];
	char TicNum[10];
	char FlTy[20];
	char pay[20];
	int cost;
} p[96];

int booking();
void CancelBooking();
void PassDetail();
void SearchRecord();

int main()
{
	char opt;
	while (1) {
		system("color FD");
		printf("\n\n\t\t   *******************************************************************");
		printf("\n\t\t                   Welcome to ABC International Airline Seat Reservation System                 ");
		printf("\n\t\t   *******************************************************************");
		printf("\n\n\t\t\t Please enter your choice from below (A-E):\t\t\n\n");

		printf("\tA.Book Seat   \t\tB.Cancel Seat   \t\tC.Details of the passenger  \n\tD.Search Passenger Record \tE.Exit");

		printf("\n\n\t\t********************* Great People to fly with PIA********************* ");
		printf("\n\n\t\t Enter your choice please: ");

		fflush(stdin);
		scanf(" %c", &opt);

		switch (opt) {
		case 'a':
		case 'A':
			system("CLS");
			booking();
			break;
		case 'b':
		case 'B':
			CancelBooking();
			system("pause");
			break;
		case 'c':
		case 'C':
			system("cls");
			printf("\n\t\t\t\t\t\tDETAILS OF PASSENGER\n\n");
			PassDetail();
			system("pause");
			break;
		case 'd':
		case 'D':
			SearchRecord();
			system("pause");
			break;
		case 'e':
		case 'E':
			exit(1);
			break;
		default:
			printf("Select a right option!\n");
		}
		system("CLS");
	}
}

int booking()
{
	int i, Popt, fl, x = 0, travel_class, j, row = 1, price;
	int gate_no = 1, passenger_no = 0, seat_no;
	char a[20] = { 'C','a','s','h','\0' }, b[20] = { 'C','h','e','c','k','\0' }, c[20] = { 'C','r','e','d','i','t','/','D','e','b','i','t',' ','c','a','r','d','\0' };
	char a1[20] = "Business Class", a2[20] = "Economy Class", req;
	char ch = 'A';

	FILE* fp;
	fp = fopen("detail.dat", "a");
	if (fp == NULL) {
		printf("\nFile does not exist.");
		printf("\nExiting.....");
		getchar();
		exit(1);
	}

	printf("\nEnter the details of passenger.\n");
	for (i = 0;; i++) {
		printf("Passenger Name: ");
		fflush(stdin);
		gets(p[i].name);
		printf("Payment Method:\n1.Via Cash\n2.Via Check\n3.Via Credit/Debit card\n");
		jump1:
		fflush(stdin);
		scanf("%d", &Popt);
		switch (Popt) {
		case 1:
			strcpy(p[i].pay, a);
			break;
		case 2:
			strcpy(p[i].pay, b);
			break;
		case 3:
			strcpy(p[i].pay, c);
			break;
		default:
			printf("Select a right option!");
			goto jump1;
		}
		printf("\nFlight Type:\n1.Business Class\n2.Economy Class\n");
		jump2:
		fflush(stdin);
		scanf("%d", &fl);
		switch (fl) {
		case 1:
			strcpy(p[i].FlTy, a1);
			break;
		case 2:
			strcpy(p[i].FlTy, a2);
			break;
		default:
			printf("Select the right option!\n");
			goto jump2;
		}

		if (fl == 1) {
			travel_class = 1;
			x++;
		}
		else if (fl == 2) {
			travel_class = 2;
			x++;
		}

		if (travel_class == 1) {
			passenger_no++;

			if (passenger_no % 3 == 0) {
				row++;
			}

			printf("\nBooking ID for passenger %d\n", passenger_no);

			printf("BUSS/HOT-069/%d/%d/(%d/%c)\n", gate_no, passenger_no, row, ch);
			ch++;
			if (ch == 'D') {
				ch = 'A';
			}

			gate_no++;
		}
		else {
			passenger_no++;

			if (passenger_no % 3 == 0) {
				row++;
			}

			printf("Booking ID for passenger %d\n", passenger_no);

			printf("ECO/HOT-069/%d/%d/(%d/%c)\n", gate_no, passenger_no, row, ch);
			ch++;
			if (ch == 'D') {
				ch = 'A';
			}

			gate_no++;
		}

		if (Popt == 3 && fl == 1) {  //tax/discount start
			price = 80000 - 80000 * 10 / 100;
			printf("Enjoy the 15 percent discount on credit cards!\n");
			p[i].cost = price;
			printf("Price: %d", p[i].cost = price);
		}
		else if (Popt == 3 && fl == 2) {

			price = 60000 - 60000 * 10 / 100;
			printf("Enjoy the 15 percent discount on credit cards!\n");
			p[i].cost = price;
			printf("Price: %d", p[i].cost = price);
		}
		else if (Popt == 1 && fl == 1) {
			price = 80000 + 80000 * 10 / 100;
			printf("You will have to pay an additional 10 percent civil aviation tax\n");
			p[i].cost = price;
			printf("Price: %d", p[i].cost = price);
		}
		else if (Popt == 1 && fl == 2) {
			price = 60000 + 60000 * 10 / 100;
			printf("You will have to pay an additional 10 percent civil aviation tax\n");
			p[i].cost = price;
			printf("Price: %d", p[i].cost = price);
		}
		else if (fl == 1) {
			price = 80000;
			p[i].cost = price;
			printf("Price: %d", p[i].cost = price);
		}
		else {
			price = 60000;
		}  //tax/discount end

		printf("\nThe total cost of the flight= %d\n", price);  //tax/discount

		fwrite(&p[i], sizeof(struct passenger), 1, fp);
		printf("\nAnother passenger?\nY for Yes OR N for No\n");
		jump3:
		fflush(stdin);
		scanf(" %c", &req);
		if (req == 'n' || req == 'N') {
			break;
		}
		else if (req != 'n' && req != 'N' && req != 'y' && req != 'Y') {
			printf("Select a right option!\n");
			goto jump3;
		}
		printf("\n\n");
	}
	fclose(fp);
}

void PassDetail() {
	FILE* fp;
	fp = fopen("detail.dat", "r");
	struct passenger reader;
	if (fp == NULL) {
		printf("\nFile does not exist.");
		printf("\nExiting.....");
		getchar();
		exit(1);
	}

	while (fread(&reader, sizeof(struct passenger), 1, fp)) {
		printf("\nPassenger Name: ");
		puts(reader.name);
		printf("\n");
		printf("Payment Method: ");
		puts(reader.pay);
		printf("\n");
		printf("Flight Type: ");
		puts(reader.FlTy);
		printf("\n");
		printf("Cost: %d", reader.cost);
		printf("\n");
	}

	fclose(fp);
}

void CancelBooking() {
	int i;
	FILE* fp, * f;
	int flag;
	char name[10];

	fp = fopen("detail.dat", "rb");
	if (fp == NULL) {
		printf("\n Data Not Added Yet");
	}
	else {
		f = fopen("temp.dat", "wb+");
		if (f == NULL) {
			printf("\n Error Opening File");
		}
		else {
			fflush(stdin);

			printf("\n Enter Name:");
			gets(name);
			fflush(stdin);
			flag = 0;
			while (fread(&p[i], sizeof(struct passenger), 1, fp) == 1) {
				if (strcmp(p[i].name, name) != 0) {
					fwrite(&p[i], sizeof(struct passenger), 1, f);
				}
				else {
					flag = 1;
				}
			}
			fclose(f);
			fclose(fp);

			if (flag != 1) {
				printf("\n No Record Found");
				remove("temp.dat");
			}
			else {
				remove("detail.dat");
				rename("temp.dat", "detail.dat");
				printf("\n Booking canceled successfully\n");
			}
		}
	}
}

void SearchRecord() {
	FILE* fp;
	int i;
	char name[10];
	fp = fopen("detail.dat", "r");
	if (fp == NULL) {
		printf("\n Error Opening File");
		exit(1);
	}

	printf("\n Enter Name to Search: ");
	fflush(stdin);
	gets(name);

	int found = 0;
	while (fread(&p[i], sizeof(struct passenger), 1, fp) == 1) {
		if (strcmp(p[i].name, name) == 0) {
			printf("\n Passenger Name:%s \n Payment method:%s \n Flight Type:%s \n Ticket number:%s \n", p[i].name, p[i].pay, p[i].FlTy, p[i].TicNum);
			found = 1;
			break;
		}
	}

	if (!found) {
		printf("\n Not Found");
	}

	fclose(fp);
}

