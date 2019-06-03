#include "rock_scissors_paper.h"

void cursorView(char show) // Ŀ�������
{
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    ConsoleCursor.bVisible = show;
    ConsoleCursor.dwSize = 1;

    SetConsoleCursorInfo(hConsole , &ConsoleCursor);
}

void wait(float a) // 1�ʸ� ��ٸ��� �Լ� 
{
	clock_t end;
	end = clock() + CLOCKS_PER_SEC * a;
	while(end > clock()){}
}

void gotoxy(int x, int y) // Ŀ�� ��ǥ �̵��� �Լ� 
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void showExit() // ����ȭ�� ǥ�ÿ� �Լ� 
{
	int i, moveCnt;
	char key;
	gotoxy(12, 5);
	for(i = 0; i < 22; ++i)
	{
		if(i == 0) printf("��");
		else if(i < 21) printf("��");
		else printf("��\n");
	}
	gotoxy(12, 6);
	for(i = 0; i < 22; ++i)
	{
		if(i == 0) printf("��");
		else if(i < 21) printf(" ");
		else printf("��\n");
	}
	gotoxy(12, 7);
	for(i = 0; i < 22; ++i)
	{
		if(i == 0) printf("��");
		else if(i < 21) printf(" ");
		else printf("��\n");
	}
	gotoxy(12, 8);	
	for(i = 0; i < 22; ++i)
	{
		if(i == 0) printf("��");
		else if(i < 21) printf("��");
		else printf("��\n");
	}
	gotoxy(13, 6);
	printf("  ������ �����ұ��?");
	gotoxy(13, 7);
	printf("    Yes   /   No   ");
	sleep(100);
} 

void showScore(int userScore, int comScore)
{
	gotoxy(18, 4);
	printf("%d", userScore);
	gotoxy(22, 4);
	printf(":");
	gotoxy(26, 4);
	printf("%d", comScore);
}

void winScreen(int user_win, int com_win)
{
	gotoxy(0,0);
	puts("�������������������������");
	puts("��                                            ��");
	puts("��           ----- ��� ��� -----            ��");
	puts("��                                            ��");					
	puts("��      [��]                    [��ǻ��]      ��");
	puts("��                                            ��");		
	puts("��                                            ��");
	puts("��                                            ��");
	puts("��                                            ��");				
	puts("��                                            ��");							
	puts("��                                            ��");
	puts("��                                            ��");				
	puts("�������������������������"); 
	showScore(user_win, com_win);
	gotoxy(13, 7); 
	printf("�ڡ١� �� ��! �ڡ١�");
	wait(2);
} 

void defeatScreen(int user_win, int com_win)
{
	gotoxy(0,0);
	puts("�������������������������");
	puts("��                                            ��");
	puts("��           ----- ��� ��� -----            ��");
	puts("��                                            ��");					
	puts("��      [��]                    [��ǻ��]      ��");
	puts("��                                            ��");		
	puts("��                                            ��");
	puts("��                                            ��");
	puts("��                                            ��");				
	puts("��                                            ��");							
	puts("��                                            ��");
	puts("��                                            ��");				
	puts("�������������������������"); 
	showScore(user_win, com_win);
	gotoxy(20, 7); 
	printf("�� ��!");
	wait(2);
}

void sys(char select) // ���θ޴� �鿣�� �Լ� 
{	
	switch(select)
	{
		case '1':
			play();
			break;
		case '2':
			statistics();
			break;
		case '3':
			settings();
			break;
		case '4':
			ranking();
			break;
		case '5':
			showExit();
			break;
		default:
			main_menu();
	}
}

int main_menu() // ���θ޴� ��� �Լ� 
{
	char select;
	//  ���� 28ĭ , ���� 13ĭ 
	gotoxy(0,0);
	puts("�������������������������");  
	puts("������                            ������");	
	puts("������ ���� ���� �� ���� v.1.0.0  ������");
	puts("������                            ������");	
	puts("������         [ ��  �� ]         ������");
	puts("������                            ������");
	puts("������ 1. �÷���                  ������");
	puts("������ 2. �� ��                   ������");
	puts("������ 3. �� ��                   ������");
	puts("������ 4. �� ŷ                   ������");	
	puts("������ 5. ���� ����               ������");	
	puts("������                            ������");		
	puts("�������������������������");
	cursorView(0);	
	select = getch(); // �Է¹޾� �޴� ����  
	return select;
}

void play() // 1�� �÷��� �޴� 
{	
	int i;
	char computer, user;
	char select;
	system("cls"); // ȭ�� �ʱ�ȭ�� �Լ� 
	puts("�������������������������");
	puts("��                                            ��");
	puts("��      --------    ��� ����   --------      ��");		
	puts("��                                            ��");	
	puts("�� 1. ���� ���������� ����! - �＼�� ���     ��");
	puts("��                                            ��");
	puts("�� 2. ��ǻ�Ϳ��� ������  �º�! - ���� ���    ��");
	puts("��                                            ��");
	puts("�� 3. ������ �Ƿ´��! - �ϳ� ���� �� ���    ��");					
	puts("��                                            ��");							
	puts("�� 4. �ڷ� ����                               ��");	
	puts("��                                            ��");			
	puts("�������������������������");
	cursorView(0);	
	select = getch();
	system("cls");
	switch(select)
	{
		case '1':	
			threeRound();
			break;
		case '2':
			printf("����");
			break;
		case '3':
			printf("�ϳ�������");
			break;
		default:
			main_menu();
			break;
	}
}

void statistics()
{
	puts("�������������������������");
	puts("��                                            ��");
	puts("��                                            ��");	
	puts("��                                            ��");
	puts("��                                            ��");
	puts("��                                            ��");
	puts("��                                            ��");
	puts("��                                            ��");					
	puts("��                                            ��");
	puts("��                                            ��");				
	puts("��                                            ��");			
	puts("��                                            ��");			
	puts("�������������������������");
	sleep(100);	
}

void settings()
{
	puts("�������������������������");
	puts("��                                            ��");
	puts("��                                            ��");	
	puts("��                                            ��");
	puts("��                                            ��");
	puts("��                                            ��");
	puts("��                                            ��");
	puts("��                                            ��");					
	puts("��                                            ��");
	puts("��                                            ��");				
	puts("��                                            ��");			
	puts("��                                            ��");			
	puts("�������������������������");
	sleep(100);	
}

void ranking()
{
	puts("�������������������������");
	puts("��                                            ��");
	puts("��                                            ��");	
	puts("��                                            ��");
	puts("��                                            ��");
	puts("��                                            ��");
	puts("��                                            ��");
	puts("��                                            ��");					
	puts("��                                            ��");
	puts("��                                            ��");				
	puts("��                                            ��");			
	puts("��                                            ��");			
	puts("�������������������������");
	sleep(100);	
}

void threeRound()
{	
	int userHand = 0, computerHand = 0; // ��ǻ�Ϳ� �÷��̾��� �� ���
	// �÷��̾�� 1, 0, -1 �� �ϳ��� ���� ������, ���� ���� / ���� / ���� �ǹ���. 
	// ��ǻ�ʹ� 0, 1, 2 �� �ϳ���  ���� ������, ���� ���� / ���� / ���� �ǹ���. 
	int x = 15, y = 8;
	int input = 0;
	int com_win = 0, user_win = 0;
	int i = 0;
	
	puts("�������������������������");
	puts("��                                            ��");
	puts("��      --------   ��Ģ ����   --------       ��");
	puts("��                                            ��");					
	puts("��   �＼�� ���� ���� �⺻���� ����Դϴ�.  ��");
	puts("��                                            ��");		
	puts("�� �� �÷��̾ �� ���� �̱� ��, �¸��մϴ�! ��");
	puts("��                                            ��");
	puts("��                                            ��");				
	puts("��                                            ��");							
	puts("��                                            ��");	
	puts("��                                            ��");			
	puts("�������������������������");
	cursorView(0);		
	for(i = 3; i >= 1; --i)
	{
		gotoxy(10, 10);
		printf("%d �� �� ��Ⱑ ���۵˴ϴ�.", i);
		cursorView(0);			
		wait(1);
	}
	system("cls");
	puts("�������������������������");
	puts("��                                            ��");
	puts("��                                            ��");
	puts("��                                            ��");					
	puts("��                                            ��");
	puts("��                                            ��");		
	puts("��                 ��� ���� !                ��");
	puts("��                                            ��");
	puts("��                                            ��");				
	puts("��                                            ��");							
	puts("��                                            ��");	
	puts("��                                            ��");			
	puts("�������������������������"); 
	wait(1);
	
	while(com_win < 3 && user_win < 3) 
	{
		i++;	// ���� ǥ�ÿ�  
		srand(time(NULL));
		computerHand = rand() % 3; // ��ǻ���� �ո�� ���� (0, 1, 2 -> ����, ����, ��) 
		
		while(input != 13)
		{	
		
			input = getch();
			switch(input)
			{
				case UP:
					if(userHand == 1) continue;
					userHand++;
					gotoxy(0,0);
					puts("�������������������������");
					puts("��                                            ��");
					puts("��           -----  Round    -----            ��");
					puts("��                                            ��");					
					puts("��      [��]                    [��ǻ��]      ��");
					puts("��                                            ��");		
					puts("��      ����                                  ��");
					puts("��                                            ��");
					puts("��      ����                      ???         ��");				
					puts("��                                            ��");							
					puts("��       ��                                   ��");	
					puts("��                                            ��");				
					puts("�������������������������");
					gotoxy(27, 2);
					printf("%d", i);											
					gotoxy(x, y);
					printf("  ");
					gotoxy(x, y-2);
					y -= 2;
					printf("��");
					break;
				case DOWN:
					if(userHand == -1) continue;
					userHand--;
					gotoxy(0,0);
					puts("�������������������������");
					puts("��                                            ��");
					puts("��           -----  Round    -----            ��");
					puts("��                                            ��");					
					puts("��      [��]                    [��ǻ��]      ��");
					puts("��                                            ��");		
					puts("��      ����                                  ��");
					puts("��                                            ��");
					puts("��      ����                      ???         ��");				
					puts("��                                            ��");							
					puts("��       ��                                   ��");	// 17, 25, 4
					puts("��                                            ��");				
					puts("�������������������������");
					gotoxy(27, 2);
					printf("%d", i);											
					gotoxy(x, y);
					printf("  ");
					gotoxy(x, y+2);
					y += 2;
					printf("��");
					break;
			} 	
		}
		switch(userHand)
		{
			case 1: // ���� : ���� 
				switch(computerHand)
				{
					case 0: // ��ǻ�� : ����  
					gotoxy(33, 8);
					printf(" ����!");
					cursorView(0);
					showScore(user_win, com_win);					
					wait(1);
					
					break;
					
					case 1: // ��ǻ�� : ���� 
					gotoxy(33, 8);
					printf(" ����!");
					cursorView(0);
					com_win++;
					showScore(user_win, com_win);						
					wait(1);
					break;
					
					case 2: // ��ǻ�� : �� 
					gotoxy(33, 8);
					printf(" ��!");
					cursorView(0);
					user_win++;
					showScore(user_win, com_win);						
					wait(1);
				}
			break;
			
			case 0: // ���� : ���� 
				switch(computerHand)
				{
					case 0: // ��ǻ�� : ����  
					gotoxy(33, 8);
					printf(" ����!");
					cursorView(0);
					user_win++; 
					showScore(user_win, com_win);					
					wait(1);
					break;
					
					case 1: // ��ǻ�� : ���� 
					gotoxy(33, 8);
					printf(" ����!");
					cursorView(0);
					showScore(user_win, com_win);					
					wait(1);
					break;
					
					case 2: // ��ǻ�� : �� 
					gotoxy(33, 8);
					printf(" ��!");
					cursorView(0);
					com_win++;
					showScore(user_win, com_win);					
					wait(1);
				}
			break;
			
			case -1: // ���� : �� 
				switch(computerHand)
				{
					case 0: // ��ǻ�� : ����  
					gotoxy(33, 8);
					printf(" ����!");
					cursorView(0);
					com_win++;
					showScore(user_win, com_win);					 	
					wait(1);
					break;
					
					case 1: // ��ǻ�� : ���� 
					gotoxy(33, 8);
					printf(" ����!");
					cursorView(0);
					user_win++;
					showScore(user_win, com_win);					
					wait(1);
					break;
					
					case 2: // ��ǻ�� : �� 
					gotoxy(33, 8);
					printf(" ��!");
					cursorView(0);
					showScore(user_win, com_win);					
					wait(1);
				}
			break;					
		}
		
		if(user_win >= 3) winScreen(user_win, com_win);
		else if (com_win >= 3)defeatScreen(user_win, com_win);		
		
		input = 0;
		x = 15;
		y = 8;
		userHand = 0;
		computerHand = 0;
	}
	user_win = 0, com_win = 0;
}
