#include <iostream>
using namespace std;
 
struct Date {
    int d, m, y;
};
// 
//enum DaysOfWeek ={
//	SUN,MON,TUE,WED,THUR,FRI,SAT
//};
const int monthDays[12]
    = { 31, 28, 31, 30, 31, 30,
       31, 31, 30, 31, 30, 31 };
 
int countLeapYears(Date d)
{
    int years = d.y;
    if (d.m <= 2)
        years--;
    return years / 4 - years / 100 + years / 400;
}

int getDifference(Date dt1, Date dt2)
{
    long int n1 = dt1.y * 365 + dt1.d;
    for (int i = 0; i < dt1.m - 1; i++)
        n1 += monthDays[i];
    n1 += countLeapYears(dt1);
 
    long int n2 = dt2.y * 365 + dt2.d;
    for (int i = 0; i < dt2.m - 1; i++)
        n2 += monthDays[i];
    n2 += countLeapYears(dt2);

    return (n2 - n1)+1;
}
//Function to get the day of the week given the date;
int getWeekDay(int dd,int mm,int yy) 
{
	//formula to get weekday number
	int rst =                                                     
		dd                                                      
		+ ((153 * (mm + 12 * ((14 - mm) / 12) - 3) + 2) / 5) 
		+ (365 * (yy + 4800 - ((14 - mm) / 12)))
		+ ((yy + 4800 - ((14 - mm) / 12)) / 4)
		- ((yy + 4800 - ((14 - mm) / 12)) / 100)
		+ ((yy + 4800 - ((14 - mm) / 12)) / 400)
		- 32045;

	return (rst+1)%7 ;
}

double calculatePrice(int arr[], int carTypeIndex) {
	  	int parkingPrices[][7] ={
		{10000, 5000, 15000, 9350, 8400, 8400},
		{12000, 8500, 13500, 7460, 8400, 8000}, 
		{7500, 350, 11000, 5600, 8400, 8000}
								  };
        double price = 0.00;
        int i=0;
         int n =sizeof(arr) /sizeof(arr[0]);
        while (i< n) {
            double vat = arr[i] == 3 ? 0.05 : 0.18;

            int bill = parkingPrices[carTypeIndex][arr[i] == 0 ? 5 : arr[i] - 1];
            if (arr[i] == 3) {
                bill = carTypeIndex == 0 ? 5000 :carTypeIndex == 1 ? 7460 : 350;
            }
            price += bill + bill*vat;
            i++;
        }

        return price;
    }


int main() {
	Date from;
	Date to;
	string  Names;
	int numberOfDaysBtnDates =0;
	int choosedCartype;
    int times;
    char slashDummy;
    string carTypes[] ={"SEDAN", "COUPE", "MINIVAN"};

	const char *Days[] = {"Sunday","Monday", "Tuesday","Wednesday", "Thursday", "Friday", "Saturday"};      
	int day = 0;
	
	
	cout<<"WARM WELCOME TO Car Rental Program !"<<endl;
	cout<<"Enter Your Names"<<endl;
	getline( cin, Names);
	cout<<"Enter check-in date (dd/mm/yy) ex (9/12/2021):"<<endl;
	cin>>from.d>>slashDummy>>from.m>>slashDummy>>from.y;
    cout<<"Enter check-out date (dd/mm/yy) ex (9/12/2021):"<<endl;
	cin>>to.d>>slashDummy>>to.m>>slashDummy>>to.y;
	
	 numberOfDaysBtnDates =getDifference(from,to);
	 cout<<endl<<"numberOfDaysBtnDates"<<numberOfDaysBtnDates<<endl;
     int  allDaysOfRent[numberOfDaysBtnDates];
 
     day= getWeekDay(from.d,from.m,from.y);//starting day of rent 
	int i =day;
	for(int j=0; j<numberOfDaysBtnDates; j++){
	  	
	  	while(i <=6){
			allDaysOfRent[j] =i; 
	  		i++;
	  		if(i >6) { i=0;}
	  		break;
		  }
}	  
  			 int continueSelectingCars = 1;
             double total_price =0.00;
            while(continueSelectingCars == 1) {

              	cout<<"Choose Car Types You want "<<endl;
              	
					int n=sizeof(carTypes)/sizeof(carTypes[0]);
					for(int i =0; i<n; i++){
						cout<<i+1<<") "<<carTypes[i]<<"\t";
					}
				                
				cout<<"Enter your choice:"<<endl;
				 cin>>choosedCartype; 
                choosedCartype--;
                cout<<"Enter the number of times you want to borrow the " + carTypes[choosedCartype] + " for this rental period:"<<endl;
                cin>>times;
                double price = calculatePrice(allDaysOfRent, choosedCartype);
                price *=times;
                total_price += price;
                cout<<carTypes[choosedCartype]<<"Price-------\t"<<price<<" RWF"<<endl;
                cout<<"Do you want to add another car type ?"<<endl;
                cout<<" 1. yes"<<endl;
                cout<<" 2. no"<<endl;
                cin>>continueSelectingCars;
            }

       
	  cout<<"\nThank you for using Car Rental App !! "<<Names<<" Your total Price is =\t"<<total_price<<" RWF"<<endl;; 
	  cout<<"\n\n\t\t\t\tSEE YOU SOON!!"<<endl;
	  
	  
//	  int x;
//	  for(int i=0;i<numberOfDaysBtnDates;i++){
//	  	x =allDaysOfRent[i];
//	  	cout<<"Day--: "<<Days[x]<<endl;
//	  }
	
	return 0;
}

