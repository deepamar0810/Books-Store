#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
void add_new_book();
void add_stock();
int search_book(char[]);
void sort_struct();
void book_detail(int);
void addition_stock(int);
void remove_stock(int);
struct books
{
	char author[100];
	char title[100];
	float price;
	int stock;
	char publisher[100];
};
static int count;
struct books A[100];
int main()
{
	int x;
	int s;
	char title[50];
	do
	{
		 
		printf("WELCOME TO BOOK STORE");
		printf("\n\n1 for Add new books");
		printf("\n2 for Add stock");
		printf("\n3 for search book");
		printf("\n4 for quit");
		printf("\n\nEnter your choice ? ");
		scanf("%d",&x);
		switch(x)
		{
			case 1:
				add_new_book();
				break;
			case 2:
				add_stock();
			    break;
			case 3:
				fflush(stdin);
				printf("\nEnter Title of the book");
				gets(title);
			   s=search_book(title);
				break;
		    default:
		    	printf("Enter valid task");
			
					
		}
	}while(4!=x);
	return 1;
}
void add_new_book()
{
	FILE *books_pointer;
	books_pointer=fopen("BookStore","a");
	char book_author[50];
	char book_title[50];
	char book_publisher[50];
	float book_price;
	int book_stock;
	
	int n;
	printf("\nEnter number of books you wants to add");
	scanf("%d",&n);

	int i;
	for(int i=count;i<n; i++)
	{
	    fflush(stdin);
		printf("\nEnter Author name\n");
	//	gets(A[count].author);
		gets(book_author);
		fflush(stdin);
		
		
		
		printf("Enter title of book\n");
		//gets(A[count].title);
		gets(book_title);
		fflush(stdin);
		
	    printf("Enter price of book\n");
	    //scanf("%f",&A[count].price);
	    scanf("%f",&book_price);
	    fflush(stdin);
	    
	    printf("Enter stock of book\n");
	    //scanf("%d",&A[count].stock);
	    scanf("%d",&book_stock);
	    fflush(stdin);
	    
	    printf("Enter publisher name\n");
	   // gets(A[count].publisher);
	    gets(book_publisher);
	    
	    
	    fprintf(books_pointer,"%s %s %f %d %s ",book_author,book_title,book_price,book_stock,book_publisher);
	    
	    printf("\n\nBook Details Enterd sucessfully");
	    printf("\nEnter any key to continue...");
	    getch();	    
	    count++;
	    
	}
	 
	 fclose(books_pointer);
	//  
	//sort_struct();
	
}
void sort_struct()
{

		int i,j;
		struct books temp;
		for(i=0; i<count; i++)
	{
		for(j=i+1; j<count; j++)
		{
			if(1==(strcmp(A[i].title,A[j].title)))
			{
				temp=A[i];
				A[i]=A[j];
				A[j]=temp;				
			}
		}
	}
}
 
int search_book(char title[])
{
	int mid,low,high;
	
	 low=0;
	 high=count-1;
	 while(low<=high)
	 {
	 	mid=(low+high)/2;
	 	if((strcmp(title,A[mid].title))==0)
	 	{

	 	 goto book;	
		}
		else if(1==(strcmp(title,A[mid].title)))
		{
		
			low=mid+1;
		}
		else
		{
			high=mid-1;
			
		}
		
		
	 }
	 book:
	 	{
	 		book_detail(mid);
		 }
	
	 return(mid);
}
void book_detail(int posi)
{
	printf("\nDetails of Book");
	printf("\n\nAuther of Book %s",A[posi].author);
	printf("\nTitle of Book %s",A[posi].title);
	printf("\nPrice of Book %f",A[posi].price);
	printf("\nStock Available %d",A[posi].stock);
	printf("\nPublisher of Book %s",A[posi].publisher);
	getch();
	
		
	
}
 void add_stock()
{
	int mid;
 //	mid=search_book();
	char title[50];
	int x;
	
	
	do
	{
		printf("\n\n1 for add stock");
		printf("\n2 for remove stock");
 		printf("\n3 for back to menu");
 		printf("\n\nEnter your choice? ");
 		scanf("%d",&x);
 		printf("\n\nEnter Book Title");
     gets(title);
     mid=search_book(title);
 		switch(x)
 		{
 			case 1:
 				addition_stock(mid);
 	            break;
			case 2:
			    remove_stock(mid);	 		
				break;
			case 3:
			     break;
			default:
			     printf("Enter valid number");	  	
		 }
		 
	}while(3!=x);
		
}
void addition_stock(int m)
{
	int add;
	printf("\nEnter quantity of books you add");
	scanf("%d",&add);
	
	A[m].stock=A[m].stock+add;
}
void remove_stock(int m)
{
	int remove;
	printf("\nEnter quantity of books you remove");
	scanf("%d",&remove);
	A[m].stock=A[m].stock-remove;
}
