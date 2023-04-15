#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <dos.h>
#include <string.h>
#include <windows.h>
#include <mylib.h>
using namespace std;

const int so_item = 10;
const int dong =5;
const int cot = 20 ;
const int Up = 72;
const int Down = 80;

const int MAXLIST =100;
char thucdon [so_item][50] = {"1. Nhap danh sach hoc vien",
			                  "2. Liet ke danh sach      ",
			                  "3. Tim kiem hoc vien      ",
			                  "4. Xoa mot hoc vien       ",
			                  "5. Ghi danh sach          ",
			                  "6. Mo  danh sach          ",
			                  "7. Them sv co thu tu      ",
			                  "8. Xoa sinh vien theo ten ",
			                  "9. Si so                  ",
			                  "10. Ket thuc chuong trinh "};

struct Sinhvien {
  int maso;
  char ho [50];
  char ten[10];
  char malop[15];
};

 struct list {
  int n=0;
  Sinhvien nodes [MAXLIST];
};

void Normal () {
	SetColor(15);
	SetBGColor(0);
}
void HighLight () {
	SetColor(15);
	SetBGColor(1);
}
int MenuDong(char td [so_item][50]){
  Normal();
  system("cls");   int chon =0;
  int i; 
  for ( i=0; i< so_item ; i++)
  { gotoxy(cot, dong +i);
    cout << td[i];
  }
  HighLight();
  gotoxy(cot,dong+chon);
  cout << td[chon];
  char kytu;
do {
  kytu = getch();
  if (kytu==0) kytu = getch();
  switch (kytu) {
    case Up :if (chon+1 >1)
  			  {
  		              	Normal();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
              	chon --;
              	HighLight();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
  				
  			  }
  			  break;
  	case Down :if (chon+1 <so_item)
  			  {
  		        Normal();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
              	chon ++;
              	HighLight();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
  				
  			  }
  			  break;
  	case 13 : return chon+1;
  }  // end switch
  } while (1);
}

int Search(list &ds, int x) {
  for (int i =0; i < ds.n ; i++)
     if (ds.nodes[i].maso == x) return i;
  return -1;
}

void BaoLoi (char *s){
  int x=wherex() , y=wherey();
  gotoxy (10,24);
  cout <<s;
  Sleep(4000);
  gotoxy(10,24);
  clreol();
  gotoxy(x,y);
}
void NhapChuoi (char *tieude, char *S) {
	cout << tieude ;  fflush(stdin);
    do
	  gets(S);
    while (strcmp(S,"")==0)  ;	
}
void NhapDSSV (list &ds, int m){
 Sinhvien sv;
 
 if (m==0) ds.n=0;
 while (ds.n <MAXLIST)
 {  
   cout << "Nhap ma so (<=0 la ket thuc) : " ; 
   cin >>sv.maso;
   if (sv.maso <=0) break;
   if (Search(ds, sv.maso)>=0){
       BaoLoi ("Ma so sinh vien bi trung");
       continue;
   }
    NhapChuoi (  "Nhap Ho: ", sv.ho);
    //cout << "Ho Sv :"; gets(sv.ho);
    NhapChuoi (  "Nhap ten:", sv.ten); fflush(stdin);
    cout << "Ma lop :"; gets(sv.malop);
    ds.nodes [ds.n]=sv;
    ds.n++;
 }
 if (ds.n==MAXLIST) BaoLoi ("Danh sach day");
}
void LietKe (list ds) {
 system("cls") ;
 printf ("                     DANH SACH SINH VIEN \n");
 printf ("   STT   Ma so       Ho   va ten     Ma lop\n");
 for (int i =0 ; i < ds.n ; i++)
  printf ("%5d %8d %-30s%-10s%-10s\n", i+1, ds.nodes[i].maso, 
     ds.nodes[i].ho, ds.nodes[i].ten, ds.nodes[i].malop);
  cout << "     Tong so :" << ds.n;
 getch();
}

void SapxepTenHo(list &ds) {
 int imin,j ; Sinhvien sv;   char key1 [50], keymin[50];
 for( int i=0 ; i < ds.n-1 ; i++)
 { imin =i ;
   strcpy(keymin, ds.nodes[imin].ten);
   strcat(keymin, ds.nodes[imin].ho);
   for (j = i+1; j< ds.n ; j++)
   { strcpy(key1, ds.nodes[j].ten);
     strcat(key1, ds.nodes[j].ho);
     if (stricmp(key1, keymin) < 0) {
	     imin =j;
	     strcpy(keymin, ds.nodes[imin].ten);
         strcat(keymin, ds.nodes[imin].ho);
	 }
   }
   sv=ds.nodes[i];
   ds.nodes[i]=ds.nodes[imin];
   ds.nodes[imin]=sv;
 }
}
void ThongTinSv ( list ds, int maso ) {
  int i = Search (ds,maso ) ;
  if (i==-1) BaoLoi("Ma so sinh vien khong co trong danh sach");
  else { printf( " Ho ten sv : %30s%10s", ds.nodes[i].ho, ds.nodes[i].ten); 
         getch () ; }
}
void SaveFile(list ds,char *filename) {
 FILE * f;
 if ((f=fopen(filename,"wb"))==NULL)
 {  BaoLoi ("Loi mo file de ghi"); return ;
 }
 for (int i=0; i < ds.n; i++)
   fwrite (&ds.nodes[i], sizeof (Sinhvien), 1, f);
 fclose(f);
 BaoLoi ("Da ghi xong danh sach vao file");

}
void OpenFile(list &ds, char *filename) {
 FILE * f;
 if ((f=fopen(filename,"rb"))==NULL)
 {  BaoLoi ("Loi mo file de doc"); return ;
 }
 ds.n =0;
 while  (fread (&ds.nodes[ds.n], sizeof (Sinhvien), 1, f)!=0)
    ds.n ++;
 fclose(f);
 BaoLoi ("Da load xong danh sach vao bo nho");

}
void XoaSv(list &ds, int maso){
   int i = Search (ds,maso ) ;
   if (i==-1) BaoLoi("Ma so sinh vien khong co trong danh sach");
   else  
   {
     for (int j=i+1; j <ds.n; j++)
       ds.nodes[j-1]=ds.nodes[j];
     ds.n--;  
	}
}
int XoaSvTheoTen(list &ds, char *ten){
	int sosv=ds.n;
   for(int i = 0; i < ds.n; ) 
        if (stricmp (ds.nodes[i].ten, ten) ==0) {
          for (int j=i+1; j <ds.n; j++) 
             ds.nodes[j-1]=ds.nodes[j];
          ds.n--;  
	    }
	    else i++;
   
   return sosv-ds.n;
}
int InsertOrder (list &ds, Sinhvien sv){
	int j, k;
	if (ds.n ==MAXLIST ) return 0;
	for (j=0; j < ds.n && ds.nodes[j].maso < sv.maso ; j++ );
	for ( k = ds.n-1; k >=j  ; k--) ds.nodes[k+1]= ds.nodes[k];
	ds.nodes[j]= sv; ds.n++;
	return 1;
	
}
void SapXep(char dslop[][15], int n) {
 int imin,j ; char temp[15];   char malopmin[15] ;
 for( int i=0 ; i < n ; i++)
 { imin =i ;
   strcpy(malopmin, dslop[imin]);
   
   for (j = i+1; j< n ; j++)
  
     if (stricmp(dslop[j], malopmin) < 0) {
	     imin =j;
	     strcpy(malopmin, dslop[j]);
	 }
   strcpy(temp,dslop[i]);
   strcpy(dslop[i],dslop[imin]);
   strcpy(dslop[imin], temp);
 }
}

void ThongKeSiSo(list &ds){
	if (ds.n==0){cout << "Danh sach sinh vien rong" ; return ; getch(); }
	char dslop [ds.n][15]; 
	for (int i=0; i < ds.n; i++)
	  strcpy(dslop[i],ds.nodes [i].malop);
	SapXep(dslop, ds.n);
	char mltam [15]; strcpy(mltam,dslop[0]); int dem =0;
	for (int i=0; i<ds.n ; i++)
		if (stricmp(dslop[i], mltam)==0) dem++;
		else {
			cout << mltam << "  " << dem << endl;
			strcpy(mltam,dslop[i]); dem=1;
		}
	cout << mltam << "  " << dem << endl;	
	getch();
}

void DemSiSo(list &ds)
{
    bool dadem[ds.n] ; 
	for (int i = 0; i < ds.n; i++) 	dadem[i]=  false ; 
	int siso;
    for (int i = 0; i < ds.n; i++) {

        if (dadem[i] == true)
            continue;

         siso = 1;
        for (int j = i + 1; j < ds.n; j++) 
		  if (stricmp(ds.nodes[j].malop,  ds.nodes[i].malop)==0) {
                dadem[j] = true;
                siso++;
         }
        
        cout << ds.nodes[i].malop << ": " << siso << endl;
    }
}
int main (){ system ("cls");
  char filename[80]="D:\\DSSV.TXT";
  char tensv[16];	
  int chon;  list ds; ds.n=0; int maso; Sinhvien sv; 
  do
  {
    chon = MenuDong (thucdon);
    system ("cls");
    switch (chon ){
    case 1: NhapDSSV(ds,1) ; break;
    case 2: LietKe(ds); break;
    case 3: { printf ("\n Ban nhap ma so sinh vien : ") ;
	      cin >> maso ;
	      ThongTinSv(ds,maso); break;
	    };
	case 4: { printf ("\n Ban nhap ma so sinh vien muon xoa : ") ;
	      cin >> maso ;
	      XoaSv(ds,maso); break;
	    };    
    case 5: SaveFile(ds,filename); break;
    case 6: OpenFile(ds,filename); break;
    case 7:  break;
    case 8: printf ("\n Ban nhap ten sinh vien : ") ; fflush(stdin);
	        gets(tensv); 
			XoaSvTheoTen(ds,tensv);
			break;
	case 9: DemSiSo(ds); break;	
    case so_item : return 0;
   }
  } while (1);
  return 0;
  }
