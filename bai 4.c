#include<stdio.h>
#include<string.h>

struct Book{
	int code;
	char name[50];
	char author[50];  //tac gia
	float price;      //gia 
	char category[50];// the loai 
}; 
void displayBook(struct Book arr[], int size){
	for(int i=0; i<size; i++){
		printf("Ma: %d\n", arr[i].code);
		printf("Ten: %s\n", arr[i].name);
		printf("Tac gia: %s\n", arr[i].author);
		printf("Gia tien: %0.f.000VNÐ\n", arr[i].price);
		printf("The loai: %s\n", arr[i].category);
		printf("------------------\n");
	} 
} 
int searchBook(struct Book arr[], int size, char answer[50]){
	int index = -1; 
	for(int i=0; i<size; i++){
		if(strcmp(arr[i].name, answer)==0){
			index = i; 
		}
	}
	return index; 
}
int searchBookByAuthor(struct Book arr[], int size, char answer[50]);
int main(){ 
	
	struct Book book1 = {1, "Harry Potter", "JK Rowling", 20, "gia tuong" 
	}; 
	struct Book book2 = {2, "hanh trinh cua Elaina", "Azure", 50, "gia tuong" 
	}; 
	
	struct Book bookList[100] = {book1, book2 
	}; 
	int currentSize = 2; 
	
	int choice; 
	do{
	printf("**********MENU***********\n");
	printf("1. Thong tin sach trong cua hang\n");
	printf("2. Cap nhap thong tin sach (Them/Sua/Xoa)\n");
	printf("3. Sap xep sach theo gia (Tang/Giam)\n");
	printf("4. Tim kiem sach (Ten tac gia)\n");
	printf("5. Tim kiem sach (Ten sach)\n");
	printf("6. Ket thuc chuong trinh\n");
	printf("Lua chon cua ban la: ");
	
	scanf("%d", &choice);
	fflush(stdin); 
	switch(choice){
		case 1:
			displayBook(bookList, currentSize);
			break;
		case 2:
			{
			printf("**********Sub-Menu***********\n");
			printf("2.1. Them sach moi vao cua hang\n");
			printf("2.2. Sua thong tin sach\n");
			printf("2.3. Xoa sach khoi cua hang\n");
			float subChoice;
			scanf("%f", &subChoice);
			fflush(stdin); 
			if(subChoice==2.1f){
				struct Book newBook;
				
				printf("Nhap vao code cua sach: ");
				scanf("%d", &newBook.code);
				fflush(stdin); 
				
				printf("Nhap vao tên cua sach: ");
				gets(newBook.name);
				
				printf("Nhap vao tac gia cua sach: ");
				gets(newBook.author);
				
				printf("Nhap vao gia tien cua sach: ");
				scanf("%f", &newBook.price);
				fflush(stdin); 
				
				printf("Nhap vao the loai cua sach: ");
				gets(newBook.category);
				
				bookList[currentSize] = newBook;
				currentSize++;
				
				displayBook(bookList, currentSize);
			} else if(subChoice==2.2f){
				char answer[100];
				printf("Nhap vao quyen sach ban muon chinh sua: ");
				gets(answer);
				
				int updateIndex = searchBook(bookList, currentSize, answer);
				if(updateIndex !=-1){
					printf("Nhap vao tên cap nhap cua sach: ");
					gets(bookList[updateIndex].name);
				
					printf("Nhap vao tac gia moi cua sach: ");
					gets(bookList[updateIndex].author);
				
					printf("Nhap vao gia tien moi cua sach: ");
					scanf("%f", &bookList[updateIndex].price);
					fflush(stdin);
					
					displayBook(bookList, currentSize); 
				} 
			} else if(subChoice==2.3f){
				char answer[100];
				printf("Nhap vao ten quyen sach ban muon xoa: ");
				gets(answer);
				
				int deleteIndex = searchBook(bookList, currentSize, answer);
				if(deleteIndex != -1){
					for(int i= deleteIndex; i<currentSize; i++){
						bookList[i] = bookList[i+1]; 
					}
					currentSize--;
					displayBook(bookList, currentSize); 
				} 
			}
		}
			break;
		case 3:
			break;
		case 4:
//		{
//			char answer[50];
//			printf("Nhap vao quyen sach ban muon tim kiem: ");
//			gets(answer);
//			int searchIndex = searchBook(bookList, currentSize, answer);
//			if(searchIndex ==-1){
//				printf("Khong tim thay quyen sach nao ten nhu vay!\n"); 
//			} else{
//				struct Book fintBook = bookList[searchIndex]; 
//				printf("Ma: %d\n", findBook.code); 
//				printf("Ten: %s\n", findBook.name); 
//				printf("Tac gia: %s\n", findBook.author);
//				printf("Gia tien: %0.f.000VNÐ\n", findBook.price);
//				printf("The loai: %s\n", findBook.category);
//				printf("------------------\n");
//			} 
			break;
//		}
		case 5:
			break;
		case 6:
			printf("Thoat!");
			return 0;
		default:
		printf("Vui long nhap dung!\n");
	}
	} while( choice !=6); 
	return 0;
} 
