#include <cstdio>
#include <windows.h>
#include <conio.h>
//8*12
char a[50][50]={"############",
				"#O#    #   #",
				"#   ## # # #",
				"#####    # #",
				"#     #### #",
				"# #####  # #",
				"#       ##  ",
				"############"};

int main()
{
	int x=1,y=1;
	char ch;
	for(int i=0;i<=7;i++)
		puts(a[i]);
	while(1)
	{
		ch=getch();
        if(ch=='s')//下
        {
			if(a[x+1][y]==' ')
            {
				a[x][y]=' ';
                x++;
                a[x][y]='O';
            }
        }
        else if(ch=='w')//上
        {
			if(a[x-1][y]==' ')
            {
				a[x][y]=' ';
                x--;
                a[x][y]='O';
            }
        }
		else if(ch=='a')//左
        {
			if(a[x][y-1]==' ')
            {
				a[x][y]=' ';
                y--;
                a[x][y]='O';
            }
        }
        else if(ch=='d')//右
        {
			if(a[x][y+1]==' ')
            {
				a[x][y]=' ';
                y++;
                a[x][y]='O';
            }
        }
        system("cls");
		for(int i=0;i<=7;i++)
			puts(a[i]);
        if(x==6 && y==11)
        	break;
	}
	printf("你赢了！");
	Sleep(10000);
	return 0;
}
