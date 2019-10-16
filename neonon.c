//=====================================================================================// libraries

#include <stdio.h>
#include <windows.h>
#include <string.h>

//=====================================================================================// global usable

  char buf[100];
  char *temp;
  char *temp1;
  char *temp2;
  char name[100][30];
  char number[100][30];
  char group[100][30];
  char entry[100];
  int count, j, flag, tbd;

//=====================================================================================// prototype fungsi
void header();
void header_help();
void header_menu();
void add_contact();
void search_contact();
void delete_contact();
void delete_all();
void view_all_contact();
void refresh();
void help();
void help_add_contact();
void help_search_contact();
void help_delete_contact();
void help_delete_all();
void help_view_all_contact();
void search(char param[100][30]);
void printd(char* x, int y);
void arrow(int urutan,int posisi);
//=====================================================================================// main
int main()
{
	system("COLOR CF");
	Sleep(50);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("                                         ");
	printd("MyCon Phonebook Initializing...",30);
	Sleep(900);
	menu();
	
}

//=====================================================================================// void header

void header(){
	
printf("\t\t\t\n\n");                   
printf("\t\t\t                                   __                 __             __  \n");
printf("\t\t\t  __ _  __ _________  ___    ___  / /  ___  ___  ___ / /  ___  ___  / /__\n");
printf("\t\t\t /  ' \\/ // / __/ _ \\/ _ \\  / _ \\/ _ \\/ _ \\/ _ \\/ -_) _ \\/ _ \\/ _ \\/  '_/\n");
printf("\t\t\t/_/_/_/\\_, /\\__/\\___/_//_/ / .__/_//_/\\___/_//_/\\__/_.__/\\___/\\___/_/\\_\\ \n");
printf("\t\t\t      /___/               /_/                                            V2\n\n\n");
//printf("\t\t\t---------------------------------------------------------------------------\n\n");
}

//=====================================================================================// void header_help
void header_menu()
{
	printf("\t\t\t\t      =================================\n");
    printf("\t\t\t\t      |           Main Menu           |\n");
    printf("\t\t\t\t      =================================\n\n");
}

//=====================================================================================// void header_help
void header_help()
{
	printf("\t\t\t\t================================\n");
    printf("\t\t\t\t|       Menu Pertolongan        |\n");
    printf("\t\t\t\t================================\n\n");
}

//=====================================================================================// menu
int menu()
{	
	int key=0;
	int posisi=1;
													
	while(key!=13){
	system("cls");
	header();
    printf("\n\t\t\t\t\t    ==============================\n\n");
    arrow(1,posisi);printf("1. Daftar Kontak\n");
	arrow(2,posisi);printf("2. Tambah Kontak\n");
	arrow(3,posisi);printf("3. Hapus Kontak\n");
	arrow(4,posisi);printf("4. Pencarian\n");
	arrow(5,posisi);printf("5. Hapus Semua\n");
	arrow(6,posisi);printf("6. Pertolongan\n");
	arrow(7,posisi);printf("7. Exit\n\n");
    printf("\t\t\t\t\t    =============================\n");
    key=getch();
	if(key == 80 && posisi != 7){
	    posisi++;
	}
		else if(key == 72 && posisi !=1){
		  posisi--;
		}
		else if(key ==72 && posisi ==1){
		  posisi =7;
		}
		else if(key ==80 && posisi ==7){
		  posisi =1;
		}
		else if(key ==27){
		  exit(0);
		}
		else{
		  posisi=posisi;}
		  
		}
	
	
	if(posisi==1){
		  view_all_contact();
		}
	if(posisi==2){
		  add_contact();
		}
	if(posisi==3){
		  delete_contact();
		}
	if(posisi==4){
		  search_contact();
		  }
	if(posisi==5){
		  delete_all();
		  }
	if(posisi==6){
		  help();
		  }
	if(posisi==7){
		  exit(0);
		  }    

}
//=====================================================================================// void refresh
void refresh(){

system("cls");
FILE *a;
    a=fopen("contacts.csv","r");
	count = 0;
  
  while (fgets(buf, 1000, a)) {
    temp= strtok(buf, ",");
    strcpy(name[count], temp);
    temp1 = strtok(NULL, ",");
    strcpy(number[count], temp1);
    temp2 = strtok(NULL, ",");
    strcpy(group[count], temp2);
    count++;
	}
	
	fclose(a);
}

//=====================================================================================// void view_all_contact

void view_all_contact()
{
    system("cls");
    refresh();
    header();
    printf("\t\t\t\t=============================\n");
    printf("\t\t\t\t|       Daftar Kontak       |\n");
    printf("\t\t\t\t=============================\n");

  for (j = 0; j < count; j++) {
    printf("\n\t\t\t\t\%d.",j+1);
        printf("\n\t\t\t\tName		: %s\n",name[j]);
        printf("\t\t\t\tMobile no. 	: %s\n",number[j]);
        printf("\t\t\t\tGroup		: %s\n",group[j]);
	}
	
    printf("\n\n\t\t\t\t\t");
    system("pause");
    menu();
}

//=====================================================================================// void add_contact
void add_contact()
{
    refresh();
	FILE *fp;												
    fp=fopen("contacts.csv","a");														
    header();												
    char nama[100];
	char nomer[100];
	char grup[100];
    printf("\t\t\t\t==============================\n");		
    printf("\t\t\t\t|         Tambah Kontak      |\n");
    printf("\t\t\t\t==============================\n\n");
    
	printf("\t\t\t\tNama		: ");						
    scanf("%s",nama);
       
	for (j = 0; j < count; j++) {
    if (strcmp(nama,name[j])==0){
        	printf("\n\t\t\t\tPeringatan: Nama yang sama sudah ada di dalam kontak.\n\n");
        	printf("\t\t\t\t");system("pause"); 
			system("cls");
			header();
			printf("\t\t\t\t==============================\n");		
		    printf("\t\t\t\t|         Tambah Kontak      |\n");
		    printf("\t\t\t\t==============================\n\n");   	
		}
	}
	printf("\t\t\t\tNama		: %s\n",nama);
    printf("\t\t\t\tMobile No.	: ");
    scanf("%s",nomer);
     
	 for (j = 0; j < count; j++) {
     if (strcmp(nama,name[j])==0 && strcmp(nomer,number[j])==0){
    		fclose(fp);
        	printf("\n\t\t\t\tNama dan nomer tidak boleh sama. Silahkan coba lagi.\n\n");
        	printf("\t\t\t\t");system("pause");
        	add_contact();        	
		}
	}
		
    printf("\t\t\t\tGroup 		: ");
    scanf("%s",grup);
    
    fprintf(fp,"%s,%s,%s,\n",nama,nomer,grup); 	
    fclose(fp);
    
	printf("\n\n\t\t\t\tSukses Menambahkan..");
    printf("\n\n\n\n\t\t\t\t");
    system("pause");
    refresh();
    menu();
    
}
//=====================================================================================// void search_contact
void search_contact()
{
	refresh();
	int key=0;
	int posisi=1;
													
	while(key!=13){
	system("cls");
    header();
    printf("\t\t\t\t=============================\n");
    printf("\t\t\t\t|         Pencarian         |\n");
    printf("\t\t\t\t=============================\n\n");
    
    arrow(1,posisi);printf("1. Cari berdasarkan Nama\n\n");
	arrow(2,posisi);printf("2. Cari berdasarkan Nomer\n\n");
	arrow(3,posisi);printf("3. Cari berdasarkan Grup\n");

    key=getch();
	if(key == 80 && posisi != 3){
	    posisi++;
	}
		else if(key == 72 && posisi !=1){
		  posisi--;
		}
		else if(key ==72 && posisi ==1){
		  posisi =3;
		}
		else if(key ==80 && posisi ==3){
		  posisi =1;
		}
		else if(key ==27){
		  menu();
		}
		else{
		  posisi=posisi;}		  
		}
	
	system("cls");
    header();
    printf("\t\t\t\t=============================\n");
    printf("\t\t\t\t|         Pencarian         |\n");
    printf("\t\t\t\t=============================\n\n");
    
	if(posisi==1){
		  search(&name);
		}
	if(posisi==2){
		  search(&number);
		}
	if(posisi==3){
		  search(&group);
	}

    printf("\n\n\n\t\t\t\t\t");
    system("pause");
    menu();
}

//=====================================================================================// void search();

void search(char param[100][30]){
	
	j=0;
	flag=0;
    tbd = 0;
    
  printf("\t\t\t\tSilahkan masukkan input: ");
  scanf("%s", entry);
  printf("\n\t\t\t\tHasil untuk %s:\n", entry);

	for (j = 0; j < count; j++) {
    if (strcmp(entry,param[j])==0){
        flag=1;tbd=j;
        printf("\n\t\t\t\t  Entry Kontak No. %d.\n",j+1);
    	printf("\n\t\t\t\t\t Name		: %s\n",name[j]);
	    printf("\t\t\t\t\t Mobile no.	: %s\n",number[j]);
	    printf("\t\t\t\t\t Group		: %s\n",group[j]);
		}
	}	
	
	if (!flag) {
		printf("\n\t\t\t\t Kontak tidak ditemukan untuk keyword: %s", entry);
	}		
	
}

//=====================================================================================// void delete_contact

void delete_contact()
{
	refresh();
    FILE *b;
    
	int key=0;
	int posisi=1;
													
	while(key!=13){
	system("cls");
    header();
    printf("\t\t\t\t=============================\n");
    printf("\t\t\t\t|        Hapus Kontak       |\n");
    printf("\t\t\t\t=============================\n\n");
    
    arrow(1,posisi);printf("\b1.Hapus kontak berdasarkan nama\n\n");
	arrow(2,posisi);printf("\b2.Hapus grup\n");

    key=getch();
	if(key == 80 && posisi != 2){
	    posisi++;
	}
		else if(key == 72 && posisi !=1){
		  posisi--;
		}
		else if(key ==72 && posisi ==1){
		  posisi =2;
		}
		else if(key ==80 && posisi ==2){
		  posisi =1;
		}
		else if(key ==27){
		  menu();
		}
		else{
		  posisi=posisi;}		  
		}
	    
	system("cls");
    header();
    printf("\t\t\t\t=============================\n");
    printf("\t\t\t\t|        Hapus Kontak       |\n");
    printf("\t\t\t\t=============================\n\n");
    
	if(posisi==1){
		  search(&name);
		}
	if(posisi==2){
		  search(&group);
		}
	    
	if (flag)
    {
	    printf("\n\t\t\t\tYakin ingin menghapus?[Y/N]");
	    switch(getch())
	    {
	    	case 'Y':
	    	case 'y':
	    	case 13:
	    		remove("contacts.csv");
			    b=fopen("contacts.csv","a+");
			    if (posisi==2){
					for (j = 0; j < count; j++) {
					    if (strcmp(entry,group[j])!=0){
						fprintf(b,"%s,%s,%s,\n",name[j],number[j],group[j]);
			        	}
					}
				}
				else {
					for (j = 0; j < count; j++) {
		        		if (j!=tbd){
							fprintf(b,"%s,%s,%s,\n",name[j],number[j],group[j]);
	        			}
					}
				}
			    fclose(b);
			    printf("\n\t\t\t\tDelete success!");
			    printf("\n\t\t\t\t");
    			system("pause");
    			menu();
			case 'n':
			case 'N':
				menu();
			default:
				printf("\n\t\t\t\tWrong input!");
				printf("\n\t\t\t\t");
    			system("pause");
				menu();
		}
	}
	
    printf("\n\t\t\t\t");
    system("pause");
    menu();
}

//=====================================================================================// void delete_all
void delete_all()
{
    system("cls");
    header();
    printf("\t\t\t\t==============================\n");
    printf("\t\t\t\t|      Hapus Semua           |\n");
    printf("\t\t\t\t==============================\n\n");
   printf("\n\t\t\t\tYakin menghapus semua kontak?[Y/N]");
	switch(getch())
	    {
	    	case 'Y':
	    	case 'y':
	    	case 13:
	    		printf("\n\t\t\t\tApakah anda benar benar yakin? Hal ini akan menghapus semuanya![Y/N]");
				switch(getch()){
					case 'Y':
	    			case 'y':
					case 13:		
			    		remove("contacts.csv");
					    printf("\n\t\t\t\tDelete success!");
					    printf("\n\t\t\t\t");
		    			system("pause");
		    			menu();
		    		case 'n':
					case 'N':
					case  27:
						menu();
					default:
					printf("\n\t\t\t\tHanya menerima input Y atau N");
					printf("\n\t\t\t\t");
	    			system("pause");
					delete_all();}
			case 'n':
			case 'N':
			case  27:
				menu();
			default:
				printf("\n\t\t\t\tHanya menerima input Y atau N");
				printf("\n\t\t\t\t");
    			system("pause");
				delete_all();}
}

//=====================================================================================// void help
void help()
{
	int key=0;
	int posisi=1;	
	system("cls");
	header();
	header_help();
    printf("\t\t\t\t");
    printd("Ada yang bisa dibantu ?",20);   
											
	while(key!=13){
	system("cls");
	header();
	header_help();
    printf("\t\t\t\t");
    printf("Ada yang bisa dibantu ?\n");
    printf("\n\t\t\t\t\t    ============================\n\n");
    arrow(1,posisi);printf("1. Daftar Kontak\n");
	arrow(2,posisi);printf("2. Tambah Kontak\n");
	arrow(3,posisi);printf("3. Hapus Kontak\n");
	arrow(4,posisi);printf("4. Pencarian\n");
	arrow(5,posisi);printf("5. Hapus Semua\n");
	arrow(6,posisi);printf("6. Kembali ke menu\n\n");
    printf("\t\t\t\t\t    ============================\n");
    key=getch();
  if(key == 80 && posisi != 6){
    posisi++;
  }
else if(key == 72 && posisi !=1){
  posisi--;
}
else if(key ==72 && posisi ==1){
  posisi =6;
}
else if(key ==80 && posisi ==6){
  posisi =1;
}
else if(key ==27){
  menu();
}

else{
  posisi=posisi;}}
if(posisi==1){
  help_view_all_contact();
}
if(posisi==2){
  help_add_contact();	
}
if(posisi==3){
  help_delete_contact();
}
if(posisi==4){
  help_search_contact();
  }
if(posisi==5){
  help_delete_all();
  }
if(posisi==6){
  menu();
  }
}

void help_add_contact()
{
	system("cls");
	header();
	header_help();
	printf("\t\t\t\t");
	printd("Melalui pilihan ini, kamu dapat menambahkan kontak dengan menginput data .",20);
	printf("\n\t\t\t\t");
	printd("Contoh : ",20);
	Sleep(200);
	printf("\n\t\t\t\t");
	printd("Name		: Noname00",20);
	printf("\n\t\t\t\t");
	printd("Mobile No.	: 0822020928390",20);
	Sleep(200);
	printf("\n\t\t\t\t");
	printd("Group		: Family",20);
	Sleep(500);
	printf("\n\n\t\t\t\t");
	printd("Note : Tidak bisa menggunakan spasi.",20);
	Sleep(500);
	printf("\n\n\t\t\t\t");
    system("pause");
	help();
}

void help_search_contact()
{
	system("cls");
	header();
	header_help();
	printf("\t\t\t\t");
	printd("Melalui pilihan ini, kamu bisa mencari kontak yang tersimpan.",20);
	Sleep(200);
	printf("\n\t\t\t\t");
	printd("Kamu dapat mencarinya dengan mengetikkan nama.",20);
	Sleep(200);
	printf("\n\t\t\t\t");
	printd("Contoh : ",20);
	Sleep(200);
	printf("\n\t\t\t\t");
	printd("Masukkan Nama : Noname00",20);
	Sleep(50);
	printf("\n\n\t\t\t\t");
	printf("Hasil untuk Noname00:");
	printf("\n\n\t\t\t\t");
	printf("Nama		: Noname00");
	printf("\n\t\t\t\t");
	printf("Mobile No.	: 082201928390");
	printf("\n\t\t\t\t");
	printf("Group		: Family");
	printf("\n\n\t\t\t\t");
    system("pause");
	help();
}

void help_delete_contact()
{
	system("cls");
	header();
	header_help();
	printf("\t\t\t\t");
	printd("Melalui pilihan ini, kamu dapat menghapus kontak dengan",20);
	printf("\n\t\t\t\t");
	printd("keyword nama",20);
	Sleep(200);
	printf("\n\t\t\t\t");
	printd("Contoh : ",20);
	Sleep(200);
	printf("\n\t\t\t\t");
	printd("Masukkan Nama: Noname00",20);
	Sleep(50);
	printf("\n\n\t\t\t\t");
	printf("Nama		: Noname00");
	printf("\n\t\t\t\t");
	printf("Mobile No.	: 082201928390");
	printf("\n\t\t\t\t");
	printf("Group		: Family");
	printf("\n\t\t\t\t");
	printd("Apakah kamu yakin menghapus kontak ?[Y/N]",20);
	Sleep(500);
	printf("Y");
	Sleep(200);
	printf("\n\t\t\t\t");
	printf("Hapus Kontak Berhasil!");
	printf("\n\n\t\t\t\t");
    system("pause");
	help();
}

void help_view_all_contact()
{
	system("cls");
	header();
	header_help();
	printf("\t\t\t\t");
	printd("Melalui pilihan ini kamu dapat melihat kontak yang tersimpan.",20);
	Sleep(200);
	printf("\n\t\t\t\t");
	printd("Kontak diurutkan berdasarkan waktu input.",20);
	Sleep(500);
	printf("\n\n\t\t\t\t");
    system("pause");
	help();
}

void help_delete_all()
{
	system("cls");
	header();
	header_help();
	printf("\t\t\t\t");
	printd("Melalui pilihan ini, kamu dapat menghapus semua kontak",20);
	printf("\n\t\t\t\t");
	printd("Dengan konfirmasi Ya(Y) atau Tidak(N).",20);
	Sleep(500);
	printf("\n\n\t\t\t\t");
    system("pause");
	help();
}

//================================================================
void printd(char* x, int y)
{
	int i;
	for(i=0;i<strlen(x);i++)
	{
		printf("%c",x[i]);
		Sleep(y);
	}
}

void arrow(int urutan,int posisi){

	if(urutan==posisi){
		printf("\t\t\t\t\t       -=> ");
  }
    else{
       printf("\t\t\t\t\t\t  ");
  }
}
