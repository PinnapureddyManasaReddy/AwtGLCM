#include<iostream>
#include<stdlib.h>
#include<time.h>

int main()
{
  int a[3][3], i,j,r,c,maxval,temp,d,angle;
 
 std::cout<<" This program is to print GLCM";
 std::cout<<'\n';
 std::cout << "Enter row dimension: ";
  std::cin >> r;
   std::cout << "Enter coloumn dimension: ";
  std::cin >> c;
   
  // int b[r][c];
 //std::cin>>;
 
//Generate input matrix;

 for(i=1;i<=r;i++)
 {
    for(j=1; j<=c;j++)
    {
    a[i][j]=rand()%10;
    }
  }
   for(i=1;i<=r; i++)
 {
    for(j=1;j<=c;j++)
    {
    std::cout<<a[i][j]<<'\t';
   
    }
    std::cout<<'\n';
  }
 
//Get max value

   maxval=a[1][1];
    for(i=1;i<=r; i++)
    {
       for(j=1;j<=c;j++)
       {
          if(a[i][j]>maxval)
          {
            maxval=a[i][j];
          }
   
        }
         
    }
     std::cout<<"max val is "<<maxval;
          std::cout<<'\n';
 //temp=maxval;
 int b[maxval][maxval];
 std::cout<<"output matrix is ready";
  std::cout<<'\n';
 //int[][] arr = new int[][];
//generate empty output matrix;

 for(i=1;i<=maxval;i++)
 {
    for(j=1; j<=maxval;j++)
    {
    b[i][j]=0;
    }
  }
   
for(i=1;i<=maxval; i++)
    {
       for(j=1;j<=maxval;j++)
       {
           std::cout<<b[i][j]<<'\t';
         
        }
       
          std::cout<<'\n';
    }

std::cout<<"enter offset distance: ";
std::cin >> d;
std::cout<<'\n';
std::cout<<"enter offset angle: ";
std::cin >> angle;
std::cout<<"enter two values to search: ";
int x, y,count=0;
std::cin >> x >>y;
std::cout<<x <<'\t' <<y;
std::cout<<'\n';

//this is to print co occurence in output matrix;

for(j=1;j<=c;j++)
{
   for(i=1;i<=r;i++)
   {
      if(a[j][i]==x)
      {
          //std::cout<<a[j][i]<<x<<angle;
          //if angle is 0;
          if(angle==0)
          {
             //std::cout<<a[i][j+d]<<d;
             if(a[j][i+d]==y)
             {
               //std::cout<<a[i+d][j]<<d;
                count++;
                b[x][y]=count;
              }
          }
          //if angle is 45;
          if(angle==45)
          {
             if(a[j-d][i+d]==y)
             {
               
                count++;
                b[x][y]=count;
              }
          }
          //if angle is 90;
          if(angle==90)
          {
             if(a[j-d][i]==y)
             {
               
                count++;
                b[x][y]=count;
              }
          }
          //if angle is 135;
          if(angle==135)
          {
             if(a[j-d][i-d]==y)
             {
               
                count++;
                b[x][y]=count;
              }
          }
      }
   }
}  
std::cout<<'\n';
std::cout<<count;
std::cout<<'\n';
for(i=1;i<=maxval; i++)
    {
       for(j=1;j<=maxval;j++)
       {
           std::cout<<b[i][j]<<'\t';
         
        }
       
          std::cout<<'\n';
    }

}
