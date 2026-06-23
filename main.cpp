#include <iostream>
#include <cmath>
using namespace std;
char arr[3][3]= {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char position ;
char player='x';
int xcounter=0;
int ocounter=0;

void show ()
{
    cout<<"\n\n\t\t\t_________________________"<<endl;
    cout<<"\t\t\t|       |"<<"       |"<<"       |"<<endl;
    cout<<"\t\t\t|   "<<arr[0][0]<<"   |"<<"   "<<arr[0][1]<<"   |"<<"   "<<arr[0][2]<<"   |"<<endl;
    cout<<"\t\t\t|       |"<<"       |"<<"       |"<<endl;
    cout<<"\t\t\t_________________________"<<endl;
    cout<<"\t\t\t|       |"<<"       |"<<"       |"<<endl;
    cout<<"\t\t\t|   "<<arr[1][0]<<"   |"<<"   "<<arr[1][1]<<"   |"<<"   "<<arr[1][2]<<"   |"<<endl;
    cout<<"\t\t\t|       |"<<"       |"<<"       |"<<endl;
    cout<<"\t\t\t_________________________"<<endl;
    cout<<"\t\t\t|       |"<<"       |"<<"       |"<<endl;
    cout<<"\t\t\t|   "<<arr[2][0]<<"   |"<<"   "<<arr[2][1]<<"   |"<<"   "<<arr[2][2]<<"   |"<<endl;
    cout<<"\t\t\t|       |"<<"       |"<<"       |"<<endl;
    cout<<"\t\t\t_________________________"<<endl;

}
void play ()
{
    cout<<"enter number from 1 : 9  for player : "<<player<<endl;
    cin>>position;
    for(int i =0; i<3; i++)
    {
        for(int j =0; j<3; j++)
        {
            if(position==arr[i][j])
            {
                arr[i][j]=player;
                break;
            }

        }

    }
    if(player=='x')
    {
        player='o';
    }
    else
    {
        player='x';
    }
}
char winner ()
{
    int test=0;
    for(int i=0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            if (arr[i][j]!='x'&&arr[i][j]!='o'){
                test = 1;
            }
            if(arr[i][j]=='x')
            {
                xcounter++;
            }
            else if (arr[i][j]=='o')
            {
                ocounter++;
            }
        }
        if (xcounter == 3)
        {
            return 'x';
        }
        else if(ocounter==3)
        {
            return 'o';
        }
        xcounter=ocounter=0;
    }


    for(int i=0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            if(arr[j][i]=='x')
            {
                xcounter++;
            }
            else if (arr[j][i]=='o')
            {
                ocounter++;
            }
        }
        if (xcounter == 3)
        {
            return 'x';
        }
        else if(ocounter==3)
        {
            return 'o';
        }
        xcounter=ocounter=0;
    }
    if(arr[0][0]=='x'&&arr[1][1]=='x'&&arr[2][2]=='x'){

        return 'x';
    }else if(arr[0][0]=='o'&&arr[1][1]=='o'&&arr[2][2]=='o'){

        return 'o';
    }else if(arr[0][2]=='x'&&arr[1][1]=='x'&&arr[2][0]=='x'){

        return 'x';
    }else if(arr[0][2]=='o'&&arr[1][1]=='o'&&arr[2][0]=='o'){

        return 'o';
    }
if (test == 0){
    return 'z';
}

return '.';
}
int main()
{

while(winner()=='.'){
    show();
        play();
        system("cls");
}
show();
if (winner()=='z'){

    cout<<"No winner in this Game "<<endl;

}else{
cout<<"The  winner in this Game : "<<winner()<<endl;
}




    return 0;

}
