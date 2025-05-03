// Program to calculate the area of a square, cube, rectangle and cuboid

#include <cstdio>

class Area
{

int l, b, h;

public:

Area(){
l=1;
b=1;
h=1;
}

void len(int);
void hei(int);
void bre(int);

int Square(int);
int Cube(int);
int Rec(int, int);
int Cuboid(int, int, int);

};


int main(){

while(1){

Area obj;
int len, bre, hei;

printf("MENU: \n 1. Square \n 2. Cube \n 3. Rectangle\n 4. Cuboid\n 5. Exit\n");
int choice;
printf("Enter your choice: \n");
scanf("%d", &choice);

switch(choice){

case 1:
printf("Enter the length of the square: ");
scanf("%d", &len);
obj.len(len);
printf("The area of the square is : %d \n", obj.Square(len));
break;

case 2:
printf("Enter the length of the cube: ");
scanf("%d", &len);
obj.len(len);
printf("The area of the cube is : %d \n", obj.Cube(len));
break;

case 3:
printf("Enter the length and breadth of the rectangle: ");
scanf("%d %d", &len, &bre);
obj.len(len);
obj.bre(bre);
printf("The area of the rectangle is : %d \n", obj.Rec(len,bre));
break;

case 4:
printf("Enter the length, breadth and height of the cuboid: ");
scanf("%d %d %d", &len, &bre, &hei);
obj.len(len);
obj.bre(bre);
obj.hei(hei);
printf("The area of the cuboid is : %d \n", obj.Cuboid(len,bre,hei));
break;

case 5:
printf("Exiting the program....\n");
return 0;
break;

default:
printf("Invalid input.");

}
}

return 0;

}
void Area :: len(int temp1){

l = temp1;
}

void Area :: bre(int temp2){

b = temp2;
}

void Area :: hei(int temp3){

h = temp3;
}

int Area :: Square(int l){
return l*l;
}

int Area :: Cube(int l){
return l*l*l;
}

int Area :: Rec(int l, int b){
return l*b;
}

int Area :: Cuboid(int l, int b, int h){


int area = 2*(l*b + b*h + h*l);
return area;
}

