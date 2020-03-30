#include<iostream> 
using namespace std;
#include<conio.h> 
float arr[10][6];  
void swap(int *x, int *y) 
{ 
    int temp = *x; 
    *x= *y; 
    *y = temp; 
} 
  
void Arrival(float num, float arr[][6]) 
{ 
    for(int i=0; i<num; i++) 
    { 
        for(int j=0; j<num-i-1; j++) 
        { 
            if(arr[j][1] > arr[j+1][1]) 
            { 
                for(int k=0; k<5; k++) 
                { 
                    swap(arr[j][k], arr[j+1][k]); 
                } 
            } 
        } 
    } 
}  
void CompTime(float num, float arr[][6]) 
{ 
    int temp, val; 
    arr[0][3] = arr[0][1] + arr[0][2]; 
    arr[0][5] = arr[0][3] - arr[0][1]; 
    arr[0][4] = arr[0][5] - arr[0][2];   
    for(int i=1; i<num; i++) 
    { 
        temp = arr[i-1][3]; 
        float low = arr[i][2]; 
        for(int j=i; j<num; j++) 
        { 
            if(temp >= arr[j][1] && low >= arr[j][2]) 
            { 
                low = arr[j][2]; 
                val = j; 
            } 
        } 
        arr[val][3] = temp + arr[val][2]; 
        arr[val][5] = arr[val][3] - arr[val][1]; 
    	arr[val][4] = arr[val][5] - arr[val][2]; 
        for(int k=0; k<6; k++) 
        { 
            swap(arr[val][k], arr[i][k]); 
        } 
    } 
}  
int main() 
{ 
    float num, temp; 
    cout<<"Enter number of Process: "; 
    cin>>num; 
    cout<<"Enter process ID\n"; 
    for(int i=0; i<num; i++) 
    { 
        cout<<"Process "<<i+1<<"\n"; 
        cout<<"Enter Process Id: "; 
        cin>>arr[i][0]; 
        cout<<"Enter Arrival Time: "; 
        cin>>arr[i][1]; 
        cout<<"Enter Burst Time: "; 
        cin>>arr[i][2]; 
    } 
    cout<<"Before Arrange\n"; 
    cout<<"Process ID\tArrival Time\tBurst Time\n"; 
    for(int i=0; i<num; i++) 
    { 
        cout<<arr[i][0]<<"\t\t"<<arr[i][1]<<"\t\t"<<arr[i][2]<<"\n"; 
    }   
    Arrival(num, arr); 
    CompTime(num, arr); 
    cout<<"Final Result\n"; 
    cout<<"Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n"; 
    for(int i=0; i<num; i++) 
    { 
        cout<<arr[i][0]<<"\t\t"<<arr[i][1]<<"\t\t"<<arr[i][2]<<"\t\t"<<arr[i][4]<<"\t\t"<<arr[i][5]<<"\n"; 
    }
	float total_wt = 0, total_tat = 0; 
    for (int i=0 ; i<num ; i++) 
    { 
        total_wt = total_wt + arr[i][4]; 
        total_tat = total_tat + arr[i][5]; 
    }
    cout << "Average waiting time = "<< (float)total_wt / (float)num; 
    cout << "\nAverage turn around time = "<< (float)total_tat / (float)num;
    getch();
} 
