#include <stdio.h>
#include <stdlib.h>
#include "rock_scissors_paper.h" 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int highScore; // ���Ѹ��� ���̽��ھ� 
int winWithR, winWithS, winWithP; // ���� / ���� / �� �� �̱� Ƚ���� 

int main(int argc, char *argv[]) {
	system("mode con: cols=50 lines=14"); // â ũ������ 
	while(1)
	{
		sys(main_menu());
	}
}
