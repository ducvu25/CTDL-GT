
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

int n, w,*B, *A, count=0, OK=1;

void Init(void){
	FILE *fp;
	fp=fopen("D:/DAYSO.IN","rt");
	fscanf(fp,"%d %d",&n, &w);
	printf("\n n=%d  w= %d:",n, w);
	B= new int [n+1];
	A= new int [n+1];
	printf("\n Day so:    ");
	for(int i=1; i<=n; i++){
		fscanf(fp,"%d ",&A[i]);
		B[i]=0;
        printf("%5d",A[i]);
	}
	
	fclose(fp);
}
void Next_Bit_String(void){
	int i=n;
	while(i>0 && B[i]) { B[i]=0; i--;};
	if(i>0) B[i]=1;
	else OK=0;
}

int Result(void){
	int s=0;int i;
	for( i=1; i<=n; i++)
		s = s + A[i]*B[i];
	if(s==w){
        count++; printf("\n Ket qua %d:",count);
		fprintf(fp,"\n");
		for(i=1; i<=n; i++)
		  if (B[i]==1)
		   {	printf("%5d",A[i]);
			    fprintf(fp,"%5d",A[i]);
		   }
	}
}
int Process(void){
	Init(); FILE *fp;
	fp=fopen("D:/KETQUA.out","wt");
	fprintf(fp, "         ");
	while(OK){
		Result();
		Next_Bit_String();
	}
	rewind(fp);
	fprintf(fp,"%d\n",count);
	fclose(fp);
}

int main(void){
	Process();
	getch();
}
