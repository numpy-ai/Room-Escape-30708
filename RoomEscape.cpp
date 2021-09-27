#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include<conio.h>

// ���� å ���� 
typedef struct bible { 
	char Bible_Vlaue[100];
} BIBLE;

typedef struct bible2 { 
	char Bible_Vlaue2[100];
} BIBLE2;
// ���� å ����

// Ż�� ��ȣ ���� 
typedef struct answer { 
	char Bible_answer[100];
} ANSWER;
// Ż�� ��ȣ ���� 


// ���� ���� ���� ����

	// 1�������� ��� �� 
	int has_bible = 0; 
	int can_skip = 0; 
	int broken_photo = 0;
	
	// 2�������� ��� ��
	int new_menu = 0;
	
	
	// ���� ���� 
	BIBLE bible[10] = {
		"������������ι���,�����������϶�",
		"�ڽ��̿Ǵٰ��Ͽ�,���ϴ¸�������������ϴ�",
		"����������������,�ǽ���������", 					//3�� ���� ���� ����
		"�Ų���ġ�°���,��νż��ϰԿ��ܶ�",
		"�Ų����¿츮�����ں�,������������ȸ���̴ּ�",
		"�츰��ΰ�����ϴ�,�׷��⿡������������ϴ�",
		"�츮���Ǵ½Ų�,�����ż������̴�",
		"��������ٷ���,�������ֿ��Ѵٰ�ã�ƿ����ʴ´�",
		"�װ��������ִ°�,�����̹Ͼ��",
	};
	
	BIBLE2 bible2[10] = {
		",�����������϶�",
		",���ϴ¸�������������ϴ�",
		",�ǽ���������", 					//3�� ���� ���� ����
		",��νż��ϰԿ��ܶ�",
		",������������ȸ���̴ּ�",
		",�׷��⿡������������ϴ�",
		",�����ż������̴�",
		",�������ֿ��Ѵٰ�ã�ƿ����ʴ´�",
		",�����̹Ͼ��",
	};
	
	ANSWER answer[10];
	
	// 1,2�� ���� ���� �ε��� 
		int x,y;
	
	// 1 or 2 ������� ���� 
		char choose;
	// ���� ���� ȹ�� ����
		int red_piece = 0;
	// �� ���� ����
		int has_shop = 0; 
		
	// �������� ���� 2��° ���� 
		char random_str[75];
// ���� ���� ���� ���� 	


// �Լ� ���� ���� 
	
	// ����
	void start(); 

	// �Է¹ޱ�
	void input(); 

	// ==== ��� 	
	void print_neun(); 	
	
	// ���� ���� �ʱ�ȭ 
	void create_bible();
	
	// �� ��° ���� �ڼ��� 
	void rand_str();
	
	// �� ��° ���� ����
	char answer_2[75]; 
	
	// �������� 1
		void print_1_1_1(); void print_1_1_2(); 
		void print_1_2_1(); void print_1_2_2();
	
	// �������� 2	
		void print_2_1_1(); void print_2_1_2();
		void print_2_2_1();	void print_2_2_2();
	
	// �������� 3	
		void print_3_1_1();
		void print_3_2_1(); void print_3_2_2(); void print_3_2_3();
		void killing_try(); 
		void deadEnd(); 	void notDead();
		
	// �������� 4
		void print_4_1_1();	
		void print_4_2_1(); void print_4_2_2(); void print_4_2_3(); void print_4_2_4();
		void print_4_3_1(); void print_4_3_2(); 
		void print_4_4_1(); void print_4_4_2(); void print_4_4_3(); void print_4_4_4();
	
	// �������� 1 ����	
		void stage_1_guess(); 
			void stage_1_newguess();
			void stage_1_1_guess();	
		
	// �������� 
		void stage_1(); 
		void stage_2();
		void stage_3(); 
		void stage_4();
		
	// �����Ĵٰ� ���
		void finaldeadEnd(); 
		
	// ������ ��� ���� 
		void finalStage();
		
// �Լ� ���� ���� 

// ���� ���� 3���� ���� 
void create_bible() {
	srand(time(NULL));
	while(1) {
		x = rand()%9;
		y = rand()%9;
		if(x == y || x == 2 || y == 2) continue;
		else break;
	}
	
	

	strcpy(answer[0].Bible_answer, bible[x].Bible_Vlaue);	
	strcpy(answer[1].Bible_answer, bible[y].Bible_Vlaue);
	strcpy(answer[2].Bible_answer, bible[2].Bible_Vlaue);
	
	strcpy(answer[3].Bible_answer, bible2[y].Bible_Vlaue2); // 2��° �� �κ� 
	
	strcpy(answer_2, bible[y].Bible_Vlaue);
} 
// ���� ���� 3���� ����
	

	
	
// ����	
// ����	
// ����	
int main() {
	create_bible();
	//start();

	stage_1();
	stage_2();
	stage_3();
//	stage_4();
}
// ����	
// ����	
// ����	



// �Է� �ޱ�
void input() {
	choose = getch();
	if(choose == '1' || choose == '2' || choose == '3' || choose == '4')
		printf("[%c]\n\n",choose);
	else {
	}
	system("cls");
} 
// �Է� �ޱ� 

// ù ��° �������� 
void stage_1() {
	system("cls");
	can_skip = 0; 
	while(1) {
		
		
		if(can_skip == 1 && has_bible == 0) {
			printf("\n���ڸ� �����ϴ� ������ �߰��ߴ�.\n\n");
			has_bible = 1;
		}
		 
		printf("\n[�������� 1]\n");
		// ���� ���캸��, �ı� 	
		if(can_skip == 0) {
			stage_1_guess();
		} else if(can_skip == 1) {
			stage_1_newguess();
		}
		
		input();
		
		// ���캸�� 
		if(choose == '1') { can_skip = 1; 
			printf("\n[�������� 1-1]\n");
			stage_1_1_guess();		
			input();
		
			// ���ڸ� �ڼ��� ���캻��
			if(choose == '1') {
				if(red_piece == 0) 		print_1_1_1();
				else if(red_piece == 1) print_1_2_2();
			}
			// �Ű� ���� ���� �ٸ� ���� Ž���Ѵ�.
			else if(choose == '2') {
				print_1_1_2();
				continue;
			}		 
				
		} 
		
		// ���ڸ� �μ���.
		else if(choose == '2') { can_skip = 1; 
			if(red_piece == 0)		print_1_2_1();   
			else if(red_piece == 1) print_1_2_2();
		} 
		
		// ������ �д´� �߰�
		else if(choose == '3' && can_skip == 1) {
			
			// ��������2�� �̵� 
			break;
		} 
	}
}
// ù ��° ��������

// �� ��° �������� 
void stage_2() {
	system("cls");
	void create_bible();
	printf("\n[�������� 2]\n");
	while(1) {
		if(new_menu == 0) {
			print_2_1_1();
		} else if (new_menu == 1) {
			print_2_1_2();
		}
		
		input();
		
		// ������ ��� �д´�. 
		if(choose == '1') {
			print_2_2_1();
		}
		// ������ ���������. 
		else if(choose == '2') {
			print_2_2_2();
		}
		// �ŵ����� ��ȣ�ۿ��ϱ�.
		else if(choose == '3' && new_menu == 1) {
			// �������� 3 
			break;
		}
	}
}
// �� ��° �������� 

// �� ��° �������� 
void stage_3() {
	system("cls");
	printf("\n[�������� 3]\n");
	
	printf("���� �����ϴ� ���̺� ���� �ŵ� : �������� �����ϰ� �ִ� ���̺� ������ �ŵ���.\n\n") ;
	
	while(1) {
		print_3_1_1();
			
		input();
		
		if(choose == '1') {
			print_3_2_1();
		} else if(choose == '2') {
			print_3_2_2();
		} else if(choose == '3') {
			print_3_2_3();		
		} 
	}
}
// �� ��° �������� 

// �� ��° ��������
void stage_4() {
	system("cls");
	while(1) {
		printf("\n[�������� 4]\n");
		print_4_1_1();
		input();
		
		stage_4_1:
		// ��ü ������ 
		if(choose == '1') {
			printf("\n[�������� 4-1]\n");
			print_4_2_1();
			input();
			
			// ��ü�� ���캻��. 
			if(choose == '1') {
				print_4_3_1();
				goto stage_4_1;
			}
			
			// ��ü �������� Ž���Ѵ�. 
			else if(choose == '2') {
				stage_4_1_1: 
				printf("\n[�������� 4-1-1]\n");
				print_4_3_2();
				if(has_shop == 1) {
					printf("(�� ���� Ž���Ѵ�: 4)\n");
				}
				input();
				
				if(choose == '1') {
					print_4_4_1();
				} else if(choose == '2') {
					print_4_4_2();
				} else if(choose == '3') {
					print_4_4_3();
				} else if(choose == '4' && has_shop == 1) {
					print_4_4_4();
				} goto stage_4_1_1;
			}
			
			else if(choose = '3') {
				stage_4();
			} 
			
		} 
		
		// ���Ա� 
		else if(choose == '2') {
			printf("\n[�������� 4-2]\n");
			print_4_2_2();
			input();
			
			if(choose == '1') {
				finalStage();
			} else if(choose == '2') {
				printf("������ �ŵ� - ��������� �ض�.��\n");
				stage_4();
			}
		}
	}
}
// �� ��° �������� 



// ù ��° �̾߱� 
					void print_1_1_1() {
						printf("���ڸ� �ڼ��� ���캻��.\n");
						printf("���� �ȿ��� ���� ������ ���Դ�.\n");
						printf("�� ������ ����� ��ġ�� �ϴ� ȯ�����̴�. ��ü �̰� ��� ���� �ɱ�?\n\n");
						printf("(���� ���� �� �� ȹ��)\n");
						print_neun();
						
						Sleep(500);
						// ���� ���� ȹ�� 
						can_skip = 1;
						red_piece = 1; 
					} 
					
					void print_1_1_2() {
						printf("�Ű� ���� ���� �ٸ� ���� Ž���Ѵ�.\n"); 
						print_neun();
						
						Sleep(500);
					} 
					
					void print_1_2_1() {
						printf("���ڸ� �μ��� ���̺� ���� �ŵ����� ������ �� ���ϱ⿡ �μ��� �ʴ� �� �����ϴ�.\n");
						print_neun();
						
						Sleep(500);
					} 
					
					void print_1_2_2() {
						printf("�� �̻� �ƹ��͵� ������ �ʴ´�.\n");
						print_neun();
						
						Sleep(500);
					}
// ù ��° �̾߱� 

// �� ��° �̾߱� 
					void print_2_1_1() {
						printf("(������ ���캻��: 1)\n"); 
						printf("(������ ���������: 2)\n"); 
						new_menu = 1;
						print_neun();
					}
					
					void print_2_1_2() {
						printf("(������ ���캻��: 1)\n"); 
						printf("(������ ���������: 2)\n"); 
						printf("(�ŵ����� ��ȣ�ۿ��ϱ�: 3)\n");
						
						print_neun();
					}
					
					void print_2_2_1() {
						char *ptr = strtok(answer[1].Bible_answer, ",");
						
						
						printf("������ ���ĺ���. '�� �̷� ������ �����̡�'\n\n");
						Sleep(500);
						
						// 1
						printf("%s\n", answer[0].Bible_answer); 
						Sleep(1000);
						// 2
						printf("%s....�� �κ��� �߷��ִ�.\n", ptr);
						Sleep(1000);
						// 3
						printf("(����° �κ��� ������ �־ Ȯ���� �� ����.)\n"); 
						Sleep(1000);
						
						print_neun();
					}
					
					void print_2_2_2() {
						printf("�����̽ÿ�, �ε� ���� �����ּҼ�����\n");
						print_neun();
					}
					
// �� ��° �̾߱� 

// �� ��° �̾߱�
					void print_3_1_1() {
						printf("(�ŵ����� ���� �Ǵ�.): 1\n");
						printf("(�ŵ��� ������ ���� �ִ´�.): 2\n");
						printf("(�ŵ��� ������Ų��. ): 3\n");
						print_neun();
					}
					
					void print_3_2_1() {
						printf("�ŵ� - ���������� �� ���� ����.��\n");
						printf("������ �� �Ŵ� �� ���� �� ����.��\n");
						print_neun();
					}
					
					void print_3_2_2() {
						printf("���ŵ��� ���� �̰����� ������ �� ���� ���� �����ϰ� �ִ�.��\n");
						print_neun();
					}
					
					void print_3_2_3() {
						printf("���ƹ��� �غ� ���� �׷� ���� �ߴٰ��� ������ ���Ͽ� ū�ϳ� ���̴�.��\n\n");
						
						
						printf("�õ� �Ͻðڽ��ϱ�?\n(�Ѵ�: 1)\n(�� �Ѵ�: 2)\n"); 
						input();
						
						if(choose == '1') 
							killing_try();
						else {
							print_neun();
						}
					}
					
					void killing_try() {
						print_neun();
						
						printf("������ �ڷ� �ٰ����� ������ �ŵ��� �� ���� �ŵ��� �������״�.\n\n");
						
						// ���� ������ ����� ���			
						Sleep(1800);
						if(red_piece == 1) {
							printf("�׸��� ���� ������ �ŵ����� �Կ���.\n\n");
							Sleep(1500);
						}

						printf("\n");
						
						printf("���� �ŵ��� ô �ϱ����� �ŵ��� ���� �����Ծ���.\n\n");
						Sleep(1500);
						
						printf("���� �ִ� ������ ���� �������� �ŵ��� ���� ���� ������ �� �˾ƺ��� �ߴ�.\n\n");
						Sleep(1500);
						
						printf("���� �� �ŵ��� �ڷ��ϰ�, �ڸ��� ������.\n\n");
						Sleep(1500);
						
						
						
						if(red_piece == 0) {
							Sleep(1700);
							deadEnd();
						} else if(red_piece == 1) {
							notDead();
						}
					}
					
					void deadEnd() {
						
						printf("�װ��� �������� ���� �� ���� ����ϰ� �ִ� ���� �������ִ� �ŵ��� �����.\n\n");
						Sleep(1500);
						printf("���� ��Ȳ�Ͽ� ���������� �ŵ��� ��� �ִ� ���� ������ ���� ��ȴ�.\n\n");
						Sleep(1500);
						 
						
						printf("��..");
						Sleep(500);
						printf("Ŀ��..");
						Sleep(700);
						printf("����..\n\n");
						Sleep(1200);
						
						
						printf("���� ����� ���� ���ٰ� ���������� �װ� ����.\n\n");
						Sleep(2000);
						
						printf("DEAD\n\n");
						Sleep(3000);
						
						exit(0);
					}
					
					void notDead() {
						printf("���� ������ ���� �ŵ��� ���Ĺ��Ȱ�, ���� �ŵ��� ���� �԰� �䳻�� ���� �����Ѵ�.\n\n");
						Sleep(1000);	
						
						// �������� 4 
						stage_4();				
					}
// �� ��° �̾߱�

// �� ��° �̾߱�
					void print_4_1_1() {
						printf("��� ���캼���?\n\n");

						printf("(��ü ������: 1)\n");
						printf("(���Ա�: 2)\n");
						print_neun();
					}
					
					void print_4_2_1() {
						printf("(��ü�� ���캻��.: 1)\n");
						printf("(��ü �������� Ž���Ѵ�.: 2)\n");
						printf("(������.: 3)\n");
						print_neun();
					}
					
					void print_4_2_2() {
						printf("���̺� ���� ��ü ���� �ü��� �峪��� ������ ���Ա��̴�.\n");
						Sleep(1000);
						
						printf("�տ��� �峪��� �ŵ��鿡�� ������ ������ �����ϴ� �ŵ��� �� ��,\n");
						Sleep(1000);
						
						printf("�װ��� ��Ű�� �ٸ� �ŵ����� �����ؼ� �� 4�� �ִ�.\n\n");
						Sleep(1000);
						
						printf("���� ��Ű�� �ŵ����� ���� �Ǵ�.\n");
						Sleep(1000);
						
						printf("������ ���� �ǰ�?\n");
						printf("(������: 1)\n");
						printf("(�� ������: 2)\n");
						
						print_neun();
					}
					
					void print_4_3_1()  {
						printf("��ü�� ���캻��\n\n");
						Sleep(1500); 
						
						printf("���濡�� ���� ������ ���� ������ �̰� �����ΰ�?��\n");
						Sleep(500);
						print_neun();
					}
					
					void print_4_3_2()  {
						printf("(��ü�� �����Ѵ�.: 1)\n");
						printf("(ö���� �����Ѵ�.: 2)\n");
						printf("(Ž�縦 �׸��д�.: 3)\n");
					}
					
					void print_4_4_1() {
						printf("������ ���δ�. ��ü�� �ű� �� ���� �� �������� �����ϰ� �� �� ���� �� ����.��\n( �� ȹ�� )\n");
						Sleep(1000); 
						has_shop = 1;
						print_neun();
					}
					
					void print_4_4_2() {
						printf("öâ�� �����Ѵ�. (öâ�� �����ִ� ���� ���)\n");
					 	
						//rand_str();
					 	
						printf("[%s]\n", answer[3].Bible_answer); 
					}
					
					void print_4_4_3() {
						printf("Ž�縦 �׸��д�.\n");
						printf("�� �̻��� ������ �� ���� ������ ���.\n");
						print_neun();
						stage_4();
					}
					
					void print_4_4_4() {
						printf("���� �� ���� �� ���� ����� ���.\n");
						Sleep(500);
						
						printf("������ �ĳ��� ���� ���ϴ� ������ ���δ�.\n");
						Sleep(500);
						
						printf("������ ������ �ļ� ���� �� ���� ������?\n\n");
						Sleep(500);
						
						printf("(������ �Ǵ�.: 1)\n");
						printf("(�����ϴϱ� ���� �ʴ´�.: 2)\n");
						
						input();
						if(choose == '1') {
							finaldeadEnd();
						} else if (choose == '2') {
							stage_4();
						}
					}
			
					void finalStage() {
											
						char input_1[75];
						char input_2[75];
						char input_3[75];
						int cnt = 0;
						
//						printf("[���� ���ڿ��� �������� ���ÿ�.]\n\n");
						printf("���� ������� �׻� , �� ���ԵǾ��־�� �մϴ�.\n\n"); 
						Sleep(500);
						while(cnt < 3) {				
							Sleep(1000);
							
							print_neun();
							
							printf("������ ���� ��� ������ �����ϰڴ�.\n\n"); 
							
							// ��
							 
//							printf("%s\n%s\n%s\n", 
//								answer[0].Bible_answer, 
//								answer_2,
//								answer[2].Bible_answer
//								);
							
							printf("ù ��° ������ ������?: ");
							gets(input_1);
													
							Sleep(100);
							
							printf("�� ��° ������ ������?: ");
							gets(input_2);
							
							Sleep(100);
							
							printf("������ ������ ������?: ");
							gets(input_3);
							
							// ���� 
							if( !strcmp(input_1, answer[0].Bible_answer) &&
								!strcmp(input_2, answer_2) &&
								!strcmp(input_3, answer[2].Bible_answer)
							) {
								printf("\n�����̴�. ���� ���ϳ��� ���ƿͶ�. ���� ��ȣ�� �״븦 �����ֱ⸦.\n\n");
								
								printf("Ż�⿡ �����߽��ϴ�.\n");
								
								Sleep(3000);
								exit(0); // Ż�� 
							} 
							
							// ���� 
							else {
								printf("�����̴�.\n");
								printf("%d���� ��ȸ�� ���ҽ��ϴ�.\n\n",2-cnt);
								cnt++;
							}
							
									
								
						}
						
						Sleep(2000);
						printf("������ ���뵵 �𸣸鼭 �ż��� ���� �ŵ��� ��ó�ϴٴ� �ż� ���̴�!\n");
						// ���� 
						printf("�� �ڸ� ���� ���� �Ų� ���� �뿩���� Ǯ��� �Ѵ�!\n");
						Sleep(2000);
						printf("�׸��� �� �׵鿡�� ������ ��������.\n");
						Sleep(2000);
						printf("ó�����߽��ϴ�.\n");
						Sleep(5000);
						
						exit(0);
					} 
					
					
					
// �� ��° �̾߱� 

// 1�������� ���� �Լ� 
					void stage_1_guess() {
						printf("(���ڸ� ���캻��: 1)\n");
						printf("(���ڸ� �μ���: 2)\n");
						print_neun();
					} 
					
					void stage_1_newguess() {
					
						printf("(���ڸ� ���캻��: 1)\n");
						printf("(���ڸ� �μ���: 2)\n");
						printf("(������ ���캻��: 3)\n");
						print_neun();
					}
					
					void stage_1_1_guess() {
						printf("���̺� ���� ��ü�� �ϴ� ���� �ΰ�ȭ�� �׸��� �׷����ִ�.\n");
						printf("�̰��� ������ ������� ������ �ǹ̷�  ���ڸ� �Ѽս��Ѽ��ΰ� ������ �����ִ�.\n\n\n\n");
						
						printf("(���ڸ� �ڼ��� ���캻��: 1)\n");
						printf("(�Ű� ���� ���� �ٸ� ���� Ž���Ѵ�: 2)\n");
						print_neun();
					}
// 1�������� ���� �Լ� 

					void finaldeadEnd() {
						printf("��ü �������� �����ڰ� �������� ���� ���ø� ��� ���� ���� ����� ��ü �����ǿ� ����.\n"); 
						Sleep(2000);
						
						printf("����̷� ���� ��ü�� ��� �ö�\n");
						Sleep(2000);
						
						printf("���� ���� ������ ���� ���ۿ� �ٰ�����.\n");
						Sleep(2000);
						
						printf("�������� ���� ���� �ſ� �����ϰ� ������ ���� ������ ������ �Ȱ��־���.\n");
						Sleep(2000);
						
						printf("�� ���� �Ѿư��� ������ ��� ������ �ʹ�.\n");
						Sleep(2000);
						
						printf("��� ���� ���� ��������� ���� ���� ���ڱ� ������ ���� ��������� ū �Ҹ��� ��ȴ�.\n");
						Sleep(2000);
						
						printf("����..");
						Sleep(500); 
						
						printf("��..");
						Sleep(400);
						
						printf(".....");
						Sleep(3000);
						
						printf("�� �Ҹ��� �Բ� �ٸ� �ŵ����� ���⸦ ��� ���� ������ ã�ƿԴ�.\n");
						Sleep(2000);
						
						printf("�׵��� ���Ǵ�� ��ư��� ���� ���Ǹ� ȭ���� �غ��ߴ�.\n");
						Sleep(2000);
						
						printf("�׵��� ���� �ŵ���� �ϰ� ������ ���� ���� ���� ������ �Ĵ� ������ �ſ� ���� �����̶�� �����Ͽ���.\n");
						Sleep(2000);
						
						printf("�ױ� �� ���������� �׵��� ������ �� ����\n");
						Sleep(1500);
						
						printf("\n[������������������,�ǽ���������]\n");
						Sleep(2000);
						
						printf("�̴�.");
						Sleep(1500);
						
						printf("�� ���� ��ȸ�� �شٸ�..\n");
						Sleep(1000);
						
						printf("���� �� �����ĵ�..\n");
						Sleep(2500);
						
						printf("DEAD\n\n");
						Sleep(3000);
						
						exit(0);
					}

// === ��� 
					void print_neun() {
						printf("================================================================\n\n\n\n\n\n\n\n\n");
						Sleep(500);
					}
// === ��� 

// ���� 
					void start() {
						printf("��"); Sleep(150);
						printf("��"); Sleep(150);
						printf("�� "); Sleep(750);
						
						printf("��"); Sleep(150);
						printf("��"); Sleep(150);
						printf("��, "); Sleep(1000);
						
						printf("��"); Sleep(200);
						printf("��"); Sleep(200);
						printf("��\n\n"); Sleep(1000);
						
						printf("������ ���� ������ ������ ���� �Ϻΰ� �������� �ٲ�ϴ�.\n\n"); 
						printf("ȭ���� Ŭ���ϸ� ������ ����ϴ�. �׷� �� [Enter]�� �����ּ���.\n\n\n\n"); 
						Sleep(1000);
						
						print_neun();
						
						printf("���� ���� �ϴ� ������ ���ڷμ� ���� ���� �ٸ� ���� �⵵�� �ø��� �־���.\n\n");
						Sleep(1500);
						
						printf("�׷��� �� ���ѵ��� �ĵ��� ������� ���� ���� �����߰� ���� ���ѵ鿡�� ���� ������� �𸣴� ���� ���ٷ� ���� ��������.\n\n");
						Sleep(1500);
						
						printf("�̰��� �ſ� ���ð� �������� �׵��� ���� �̻��� ���� �Ͽ� �̰��� ������� �ſ� �����ϴ�.\n\n");
						Sleep(1500);
						
						printf("������� ���뽺���� �ϴ� �Ҹ��� ������� �鸮��, ���� ���ٷ� ���� ��� ���ϰ� �־���.\n\n");
						Sleep(1500);
						
						printf("���� ���� �� ������ ���� ���ڰ� �ϳ��������� �̰����� ������ ���� ����.\n\n");
						Sleep(1500);
						
						printf("�׷��⿡ ���� �ŵ����� ���� �ӿ� ������ ������� ������ �԰�\n\n");
						Sleep(1000);
						
						printf("���ڰ��� �� ��� �⵵�� �ø� �� ������ ������ �����ϰ� �����ִ� ������ Ǯ����.\n\n");
						Sleep(1500);
						
						printf("�ŵ����� ���� �ӿ� �����ü����� Ż���Ͻÿ�\n\n"); 
						Sleep(1000);
						
						print_neun();
					}
// ���� 

// �� ��° ���� ���� ����
void rand_str() {
	strcpy(random_str, answer_2);
		
	char a = ' ';
	int i;
	
	for(i=0; i<3; i++) {
		random_str[i] = a; 
	}
	
	

}
// �� ��° ���� ���� ���� 










