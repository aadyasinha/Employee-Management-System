#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct employee{
	char name[100];
	int id;
	float salary;
	int age;
	struct doj{
		int day,month,year;
	}d;
};
int insert(struct employee e[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("Enter employee %d name : ",i+1);
		scanf("%s",e[i].name);
		printf("Enter employee %d id : ",i+1);
		scanf("%d",&e[i].id);
		printf("Enter employee %d salary : ",i+1);
		scanf("%f",&e[i].salary);
		printf("Enter employee %d age : ",i+1);
		scanf("%d",&e[i].age);
		printf("Enter employee %d date of joining : ",i+1);
		scanf("%d %d %d",&e[i].d.day,&e[i].d.month,&e[i].d.year);
	}
}
int display(struct employee e[],int n){
	int i;
	printf("Employee details are : \n");
	printf("S.No.\tName\tAge\tID\tSalary\tDate of Joining\n");
	for(i=0;i<n;i++){
		if(e[i].id != 0){
		printf("%d\t%s\t%d\t%d\t%.2f\t%d/%d/%d\n",i+1,e[i].name,e[i].age,e[i].id,e[i].salary,e[i].d.day,e[i].d.month,e[i].d.year);
	}
}
}
int search(struct employee e[],int n){
	int i,k,flag=0;
	printf("Enter employee id to be searched : ");
	scanf("%d",&k);
	for(i=0;i<n;i++){
		if(e[i].id==k){
			printf("Employee found\n");
			printf("The details are :\nName : %s\nAge : %d\nID : %d\nSalary : %.2f\nDate of Joining : %d/%d/%d\n",e[i].name,e[i].age,e[i].id,e[i].salary,e[i].d.day,e[i].d.month,e[i].d.year);
			flag=1;
			break;
		}
	}
	if(flag==0){
		printf("Employee not found\n");
	}
}
int deletion(struct employee e[],int n){
	int i,del,flag=0;
	printf("Enter employee id to be deleted : ");
	scanf("%d",&del);
	for(i=0;i<n;i++){
		if(del==e[i].id){
			e[i].name[0]=0;
			e[i].age=0;
			e[i].salary=0;
			e[i].id=0;
			e[i].d.day=0;
			e[i].d.month=0;
			e[i].d.year=0;
			flag=1;
		}
	}
	if(flag==0){
		printf("Employee id does not exist\n");
	}
	display(e,n);
}
int main(){
	int n;
	printf("Enter number of employees : ");
	scanf("%d",&n);
	struct employee e[n];
	insert(e,n);
	display(e,n);
	search(e,n);
	deletion(e,n);
}
