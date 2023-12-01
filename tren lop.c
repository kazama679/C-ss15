#include<stdio.h>
#include<string.h>


//	struct Book{
//		int id;
//		char name[50];
//		char author[20];
//		int price; 
//	};

//	struct Book book1 = {1/* stt */, "Harry Potter"/*ten sach*/,
//	 			"J.K. Rowling"/*ten tac gia*/, 100/*gia tien*/};
//	struct Book book2 = {2, "Dac nhan tam", "Ai ko bt", 130};
//	struct Book book3 = {3, "May bt bo m la ai k?", "bo m deo bt", 150 };
//	struct Book book4 = {4, "Het cuu roi", "ao that day", 200 };
//	struct Student{
//		int id;
//		char name[50];
//		int age;
//		char phone[20];
//		char address[50];
//	}; 
//	struct Student sv1 = {1, "Nguyen Van A", 20, "111111116", "Ha Noi"};
//	struct Student sv2 = {2, "Nguyen Van B", 21, "111111117", "HCM"};
//	struct Student sv3 = {3, "Nguyen Van C", 22, "666666661", "Hue"};
//	printf("Id sv1 = %d\n", sv1.id);
//	printf("ten sv2 la: %s\n", sv2.name);
//	printf("std cua sv3 là: %s\n", sv3.phone);
//	
//	sv3.age = 30;
//	printf("tuoi cua sv3 = %d\n", sv3.age); 
//	
//	strcpy(sv3.address, "Hai Phong");
//	printf("sv3 dang o %s\n", sv3.address);
	
//	struct Book book1 = {
//		4,
//		"Eragon",
//		"CHristopher Paolini",
//		140
//	}; 
//	struct Book book2, book3;
//	book2 = book1;
//	memcpy(&book3, &book1, sizeof(struct Book));
//	printf("Book 2's name = %s\n", book2.name);
//	printf("Book 3's name = %s\n", book3.name);

//	struct address{
//		int so_nha[5];
//		char phuong_xa[20];
//		char quan_huyen[20];
//		char thanh_pho[20];
//	}; 
//	
//	struct address address1 = {
//		5,
//		"Lien ha",
//		"Dan Phuong",
//		"Ha Noi"
//	}; 
//	struct Student sv100;
//	sv100.id =1;
//	strcpy(sv100.name, "Sac Don");
//	sv100.age = 67;
//	strcpy(sv100.phone, "0977777777777");
//	struct Address address = {"8", "ABC", "NML", "XYZ"};
//	sv100.address = address;
//	
//	printf("ward nam trong address nam trong sv100 = %s", sv100.address.ward; // ABC 
//	}; 

	struct student{
		char name[50];
		int age; 
	};
	void display(struct student s);
	int main(){
		struct student s1;
		
		printf("Enter name: ");
		gets(s1.name);
		
		printf("Endter age: ");
		scanf("%d", &s1.age);
		
		display(s1);
		
		return 0; 
	}
	void display(struct student s){
		printf("\nDisplaying infnormation");
		printf("Name: %s", s.name);
		printf("\nAge: %d", s.age); 
	}  
