	
#include <stdio.h>

struct s_book
{
	char	title[50];
	char	author[50];
	char	subject[100];
	int		book_id;
}	typedef t_book;


void structer(void)
{
	static t_book book1 = {"aa", "bb", "cc", 40};
	t_book book2;

	printf("%d\n", book1.book_id);
	book1.book_id++;
}


int main(void)
{
	structer();
	structer();
	structer();

	return (0);
}
	