/*
개발자 : 30707 김학성, 30708 박민성
개발일 : 2021.09.13.
문의 : numpy.ai@gmail.com 
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include<conio.h>

// 성경 책 내용 
typedef struct bible { 
	char Bible_Vlaue[100];
} BIBLE;

typedef struct bible2 { 
	char Bible_Vlaue2[100];
} BIBLE2;
// 성경 책 내용

// 탈출 암호 설정 
typedef struct answer { 
	char Bible_answer[100];
} ANSWER;
// 탈출 암호 설정 


// 전역 변수 선언 공간

	// 1스테이지 통과 비교 
	int has_bible = 0; 
	int can_skip = 0; 
	int broken_photo = 0;
	
	// 2스테이지 통과 비교
	int new_menu = 0;
	
	
	// 성경 내용 
	BIBLE bible[10] = {
		"몸과마음을모두바쳐,믿음을전파하라",
		"자신이옳다고하여,행하는모든행위는정당하다",
		"믿음에대한행위에,의심하지마라", 					//3번 질문 고정 정답
		"신께바치는것은,모두신성하게여겨라",
		"신께서는우리에게자비를,주진않으나기회를주셨다",
		"우린모두가평등하다,그렇기에목숨은모두평등하다",
		"우리의피는신께,받은신성한피이다",
		"구원을기다려라,구원은애원한다고찾아오지않는다",
		"네가믿을수있는걸,끝없이믿어라",
	};
	
	BIBLE2 bible2[10] = {
		",믿음을전파하라",
		",행하는모든행위는정당하다",
		",의심하지마라", 					//3번 질문 고정 정답
		",모두신성하게여겨라",
		",주진않으나기회를주셨다",
		",그렇기에목숨은모두평등하다",
		",받은신성한피이다",
		",구원은애원한다고찾아오지않는다",
		",끝없이믿어라",
	};
	
	ANSWER answer[10];
	
	// 1,2번 문장 랜덤 인덱스 
		int x,y;
	
	// 1 or 2 사용자의 선택 
		char choose;
	// 빨간 조각 획득 유무
		int red_piece = 0;
	// 삽 소지 유무
		int has_shop = 0; 
		
	// 랜덤으로 섞인 2번째 문장 
		char random_str[75];
// 전역 변수 선언 공간 	


// 함수 선언 공간 
	
	// 시작
	void start(); 

	// 입력받기
	void input(); 

	// ==== 출력 	
	void print_neun(); 	
	
	// 성경 내용 초기화 
	void create_bible();
	
	// 두 번째 문장 뒤섞기 
	void rand_str();
	
	// 두 번째 문장 원본
	char answer_2[75]; 
	
	// 스테이지 1
		void print_1_1_1(); void print_1_1_2(); 
		void print_1_2_1(); void print_1_2_2();
	
	// 스테이지 2	
		void print_2_1_1(); void print_2_1_2();
		void print_2_2_1();	void print_2_2_2();
	
	// 스테이지 3	
		void print_3_1_1();
		void print_3_2_1(); void print_3_2_2(); void print_3_2_3();
		void killing_try(); 
		void deadEnd(); 	void notDead();
		
	// 스테이지 4
		void print_4_1_1();	
		void print_4_2_1(); void print_4_2_2(); void print_4_2_3(); void print_4_2_4();
		void print_4_3_1(); void print_4_3_2(); 
		void print_4_4_1(); void print_4_4_2(); void print_4_4_3(); void print_4_4_4();
	
	// 스테이지 1 질문	
		void stage_1_guess(); 
			void stage_1_newguess();
			void stage_1_1_guess();	
		
	// 스테이지 
		void stage_1(); 
		void stage_2();
		void stage_3(); 
		void stage_4();
		
	// 구멍파다가 사망
		void finaldeadEnd(); 
		
	// 마지막 사상 검증 
		void finalStage();
		
// 함수 선언 공간 

// 성경 내용 3가지 설정 
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
	
	strcpy(answer[3].Bible_answer, bible2[y].Bible_Vlaue2); // 2번째 뒷 부분 
	
	strcpy(answer_2, bible[y].Bible_Vlaue);
} 
// 성경 내용 3가지 설정
	

	
	
// 메인	
// 메인	
// 메인	
int main() {
	create_bible();
	//start();

	stage_1();
	stage_2();
	stage_3();
//	stage_4();
}
// 메인	
// 메인	
// 메인	



// 입력 받기
void input() {
	choose = getch();
	if(choose == '1' || choose == '2' || choose == '3' || choose == '4')
		printf("[%c]\n\n",choose);
	else {
	}
	system("cls");
} 
// 입력 받기 

// 첫 번째 스테이지 
void stage_1() {
	system("cls");
	can_skip = 0; 
	while(1) {
		
		
		if(can_skip == 1 && has_bible == 0) {
			printf("\n액자를 조사하다 성경을 발견했다.\n\n");
			has_bible = 1;
		}
		 
		printf("\n[스테이지 1]\n");
		// 액자 살펴보기, 파괴 	
		if(can_skip == 0) {
			stage_1_guess();
		} else if(can_skip == 1) {
			stage_1_newguess();
		}
		
		input();
		
		// 살펴보기 
		if(choose == '1') { can_skip = 1; 
			printf("\n[스테이지 1-1]\n");
			stage_1_1_guess();		
			input();
		
			// 액자를 자세히 살펴본다
			if(choose == '1') {
				if(red_piece == 0) 		print_1_1_1();
				else if(red_piece == 1) print_1_2_2();
			}
			// 신경 쓰지 말고 다른 곳을 탐색한다.
			else if(choose == '2') {
				print_1_1_2();
				continue;
			}		 
				
		} 
		
		// 액자를 부순다.
		else if(choose == '2') { can_skip = 1; 
			if(red_piece == 0)		print_1_2_1();   
			else if(red_piece == 1) print_1_2_2();
		} 
		
		// 성경을 읽는다 추가
		else if(choose == '3' && can_skip == 1) {
			
			// 스테이지2로 이동 
			break;
		} 
	}
}
// 첫 번째 스테이지

// 두 번째 스테이지 
void stage_2() {
	system("cls");
	void create_bible();
	printf("\n[스테이지 2]\n");
	while(1) {
		if(new_menu == 0) {
			print_2_1_1();
		} else if (new_menu == 1) {
			print_2_1_2();
		}
		
		input();
		
		// 성경을 계속 읽는다. 
		if(choose == '1') {
			print_2_2_1();
		}
		// 성경을 덮어버린다. 
		else if(choose == '2') {
			print_2_2_2();
		}
		// 신도에게 상호작용하기.
		else if(choose == '3' && new_menu == 1) {
			// 스테이지 3 
			break;
		}
	}
}
// 두 번째 스테이지 

// 세 번째 스테이지 
void stage_3() {
	system("cls");
	printf("\n[스테이지 3]\n");
	
	printf("나를 감시하는 사이비 종교 신도 : ‘나’를 감시하고 있는 사이비 종교의 신도다.\n\n") ;
	
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
// 세 번째 스테이지 

// 네 번째 스테이지
void stage_4() {
	system("cls");
	while(1) {
		printf("\n[스테이지 4]\n");
		print_4_1_1();
		input();
		
		stage_4_1:
		// 시체 보관실 
		if(choose == '1') {
			printf("\n[스테이지 4-1]\n");
			print_4_2_1();
			input();
			
			// 시체를 살펴본다. 
			if(choose == '1') {
				print_4_3_1();
				goto stage_4_1;
			}
			
			// 시체 보관실을 탐사한다. 
			else if(choose == '2') {
				stage_4_1_1: 
				printf("\n[스테이지 4-1-1]\n");
				print_4_3_2();
				if(has_shop == 1) {
					printf("(더 깊이 탐사한다: 4)\n");
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
		
		// 출입구 
		else if(choose == '2') {
			printf("\n[스테이지 4-2]\n");
			print_4_2_2();
			input();
			
			if(choose == '1') {
				finalStage();
			} else if(choose == '2') {
				printf("문지기 신도 - “마음대로 해라.”\n");
				stage_4();
			}
		}
	}
}
// 네 번째 스테이지 



// 첫 번째 이야기 
					void print_1_1_1() {
						printf("액자를 자세히 살펴본다.\n");
						printf("액자 안에서 빨간 조각이 나왔다.\n");
						printf("이 조각은 사람을 미치게 하는 환각제이다. 대체 이걸 어디에 쓰는 걸까?\n\n");
						printf("(빨간 조각 한 개 획득)\n");
						print_neun();
						
						Sleep(500);
						// 빨간 조각 획득 
						can_skip = 1;
						red_piece = 1; 
					} 
					
					void print_1_1_2() {
						printf("신경 쓰지 말고 다른 곳을 탐색한다.\n"); 
						print_neun();
						
						Sleep(500);
					} 
					
					void print_1_2_1() {
						printf("액자를 부수면 사이비 종교 신도들이 몰려올 게 뻔하기에 부수지 않는 게 적절하다.\n");
						print_neun();
						
						Sleep(500);
					} 
					
					void print_1_2_2() {
						printf("더 이상 아무것도 보이지 않는다.\n");
						print_neun();
						
						Sleep(500);
					}
// 첫 번째 이야기 

// 두 번째 이야기 
					void print_2_1_1() {
						printf("(성경을 살펴본다: 1)\n"); 
						printf("(성경을 덮어버린다: 2)\n"); 
						new_menu = 1;
						print_neun();
					}
					
					void print_2_1_2() {
						printf("(성경을 살펴본다: 1)\n"); 
						printf("(성경을 덮어버린다: 2)\n"); 
						printf("(신도에게 상호작용하기: 3)\n");
						
						print_neun();
					}
					
					void print_2_2_1() {
						char *ptr = strtok(answer[1].Bible_answer, ",");
						
						
						printf("성경을 펼쳐본다. '뭐 이런 끔찍한 내용이…'\n\n");
						Sleep(500);
						
						// 1
						printf("%s\n", answer[0].Bible_answer); 
						Sleep(1000);
						// 2
						printf("%s....뒷 부분은 잘려있다.\n", ptr);
						Sleep(1000);
						// 3
						printf("(세번째 부분은 찢어져 있어서 확인할 수 없다.)\n"); 
						Sleep(1000);
						
						print_neun();
					}
					
					void print_2_2_2() {
						printf("“신이시여, 부디 저를 지켜주소서…”\n");
						print_neun();
					}
					
// 두 번째 이야기 

// 세 번째 이야기
					void print_3_1_1() {
						printf("(신도에게 말을 건다.): 1\n");
						printf("(신도를 가만히 보고 있는다.): 2\n");
						printf("(신도를 기절시킨다. ): 3\n");
						print_neun();
					}
					
					void print_3_2_1() {
						printf("신도 - “쓸데없는 말 하지 마라.”\n");
						printf("‘말을 안 거는 게 좋을 거 같다.’\n");
						print_neun();
					}
					
					void print_3_2_2() {
						printf("‘신도가 내가 이곳에서 나가는 걸 막기 위해 감시하고 있다.’\n");
						print_neun();
					}
					
					void print_3_2_3() {
						printf("‘아무런 준비도 없이 그런 짓을 했다가는 역으로 당하여 큰일날 것이다.’\n\n");
						
						
						printf("시도 하시겠습니까?\n(한다: 1)\n(안 한다: 2)\n"); 
						input();
						
						if(choose == '1') 
							killing_try();
						else {
							print_neun();
						}
					}
					
					void killing_try() {
						print_neun();
						
						printf("조용히 뒤로 다가가서 밧줄을 신도의 목에 감아 신도를 기절시켰다.\n\n");
						
						// 빨간 조각을 얻었을 경우			
						Sleep(1800);
						if(red_piece == 1) {
							printf("그리고 빨간 조각을 신도에게 먹였다.\n\n");
							Sleep(1500);
						}

						printf("\n");
						
						printf("나는 신도인 척 하기위해 신도의 옷을 뺏어입었다.\n\n");
						Sleep(1500);
						
						printf("깨져 있던 액자의 유리 조각으로 신도의 얼굴을 찢어 누군지 못 알아보게 했다.\n\n");
						Sleep(1500);
						
						printf("나는 그 신도를 뒤로하고, 자리를 떠났다.\n\n");
						Sleep(1500);
						
						
						
						if(red_piece == 0) {
							Sleep(1700);
							deadEnd();
						} else if(red_piece == 1) {
							notDead();
						}
					}
					
					void deadEnd() {
						
						printf("그곳을 떠나려고 했을 때 내가 방심하고 있던 사이 기절해있던 신도가 깨어났다.\n\n");
						Sleep(1500);
						printf("나는 당황하여 저항했지만 신도가 들고 있던 유리 조각에 목이 찔렸다.\n\n");
						Sleep(1500);
						 
						
						printf("컥..");
						Sleep(500);
						printf("커억..");
						Sleep(700);
						printf("젠장..\n\n");
						Sleep(1200);
						
						
						printf("나는 힘겹게 숨을 쉬다가 과다출혈로 죽고 만다.\n\n");
						Sleep(2000);
						
						printf("DEAD\n\n");
						Sleep(3000);
						
						exit(0);
					}
					
					void notDead() {
						printf("빨간 조각을 먹은 신도는 미쳐버렸고, 나는 신도의 옷을 입고 흉내를 내기 시작한다.\n\n");
						Sleep(1000);	
						
						// 스테이지 4 
						stage_4();				
					}
// 세 번째 이야기

// 네 번째 이야기
					void print_4_1_1() {
						printf("어디를 살펴볼까요?\n\n");

						printf("(시체 보관실: 1)\n");
						printf("(출입구: 2)\n");
						print_neun();
					}
					
					void print_4_2_1() {
						printf("(시체를 살펴본다.: 1)\n");
						printf("(시체 보관실을 탐사한다.: 2)\n");
						printf("(나간다.: 3)\n");
						print_neun();
					}
					
					void print_4_2_2() {
						printf("사이비 종교 단체 지하 시설을 드나드는 유일한 출입구이다.\n");
						Sleep(1000);
						
						printf("앞에는 드나드는 신도들에게 성경의 내용을 질문하는 신도가 한 명,\n");
						Sleep(1000);
						
						printf("그곳을 지키는 다른 신도들을 포함해서 총 4명 있다.\n\n");
						Sleep(1000);
						
						printf("문을 지키는 신도에게 말을 건다.\n");
						Sleep(1000);
						
						printf("밖으로 나갈 건가?\n");
						printf("(나간다: 1)\n");
						printf("(안 나간다: 2)\n");
						
						print_neun();
					}
					
					void print_4_3_1()  {
						printf("시체를 살펴본다\n\n");
						Sleep(1500); 
						
						printf("‘방에서 썩은 냄새가 나는 이유가 이것 때문인가?”\n");
						Sleep(500);
						print_neun();
					}
					
					void print_4_3_2()  {
						printf("(시체를 조사한다.: 1)\n");
						printf("(철장을 조사한다.: 2)\n");
						printf("(탐사를 그만둔다.: 3)\n");
					}
					
					void print_4_4_1() {
						printf("‘삽이 보인다. 시체를 옮길 때 쓰던 거 같은데… 유용하게 쓸 수 있을 거 같다.”\n( 삽 획득 )\n");
						Sleep(1000); 
						has_shop = 1;
						print_neun();
					}
					
					void print_4_4_2() {
						printf("철창을 조사한다. (철창에 적혀있는 문자 출력)\n");
					 	
						//rand_str();
					 	
						printf("[%s]\n", answer[3].Bible_answer); 
					}
					
					void print_4_4_3() {
						printf("탐사를 그만둔다.\n");
						printf("더 이상은 위험할 거 같은 느낌이 든다.\n");
						print_neun();
						stage_4();
					}
					
					void print_4_4_4() {
						printf("뭔가 더 있을 거 같은 기분이 든다.\n");
						Sleep(500);
						
						printf("누군가 파놓은 위로 향하는 구멍이 보인다.\n");
						Sleep(500);
						
						printf("삽으로 구멍을 파서 나갈 수 있지 않을까?\n\n");
						Sleep(500);
						
						printf("(구멍을 판다.: 1)\n");
						printf("(위험하니까 파지 않는다.: 2)\n");
						
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
						
//						printf("[주의 문자열을 붙혀넣지 마시오.]\n\n");
						printf("문장 가운데에는 항상 , 이 포함되어있어야 합니다.\n\n"); 
						Sleep(500);
						while(cnt < 3) {				
							Sleep(1000);
							
							print_neun();
							
							printf("나가기 전에 사상 검증을 시작하겠다.\n\n"); 
							
							// 답
							 
//							printf("%s\n%s\n%s\n", 
//								answer[0].Bible_answer, 
//								answer_2,
//								answer[2].Bible_answer
//								);
							
							printf("첫 번째 성경의 내용은?: ");
							gets(input_1);
													
							Sleep(100);
							
							printf("두 번째 성경의 내용은?: ");
							gets(input_2);
							
							Sleep(100);
							
							printf("성경의 마지막 내용은?: ");
							gets(input_3);
							
							// 정답 
							if( !strcmp(input_1, answer[0].Bible_answer) &&
								!strcmp(input_2, answer_2) &&
								!strcmp(input_3, answer[2].Bible_answer)
							) {
								printf("\n정답이다. 빠른 시일내로 돌아와라. 신의 가호가 그대를 지켜주기를.\n\n");
								
								printf("탈출에 성공했습니다.\n");
								
								Sleep(3000);
								exit(0); // 탈출 
							} 
							
							// 오답 
							else {
								printf("오답이다.\n");
								printf("%d번의 기회가 남았습니다.\n\n",2-cnt);
								cnt++;
							}
							
									
								
						}
						
						Sleep(2000);
						printf("성경의 내용도 모르면서 신성한 신의 신도를 자처하다니 신성 모독이다!\n");
						// 수정 
						printf("이 자를 끌고 가서 신께 바쳐 노여움을 풀어야 한다!\n");
						Sleep(2000);
						printf("그리고 난 그들에게 붙잡혀 끌려갔다.\n");
						Sleep(2000);
						printf("처형당했습니다.\n");
						Sleep(5000);
						
						exit(0);
					} 
					
					
					
// 네 번째 이야기 

// 1스테이지 질문 함수 
					void stage_1_guess() {
						printf("(액자를 살펴본다: 1)\n");
						printf("(액자를 부순다: 2)\n");
						print_neun();
					} 
					
					void stage_1_newguess() {
					
						printf("(액자를 살펴본다: 1)\n");
						printf("(액자를 부순다: 2)\n");
						printf("(성경을 살펴본다: 3)\n");
						print_neun();
					}
					
					void stage_1_1_guess() {
						printf("사이비 종교 단체가 믿는 신을 인간화한 그림이 그려져있다.\n");
						printf("이곳에 끌려온 사람들이 저항의 의미로  액자를 훼손시켜서인가 유리가 깨져있다.\n\n\n\n");
						
						printf("(액자를 자세히 살펴본다: 1)\n");
						printf("(신경 쓰지 말고 다른 곳을 탐색한다: 2)\n");
						print_neun();
					}
// 1스테이지 질문 함수 

					void finaldeadEnd() {
						printf("시체 보관실의 감시자가 쉬러가기 위해 감시를 대신 해줄 때를 노려서 시체 보관실에 들어간다.\n"); 
						Sleep(2000);
						
						printf("산더미로 쌓인 시체를 밟고 올라가\n");
						Sleep(2000);
						
						printf("나는 빛이 들어오는 작은 구멍에 다가갔다.\n");
						Sleep(2000);
						
						printf("오랜만에 보는 빛은 매우 따뜻하고 눈물이 나올 정도로 감동을 안겨주었다.\n");
						Sleep(2000);
						
						printf("그 빛을 쫓아가며 삽으로 계속 구멍을 팠다.\n");
						Sleep(2000);
						
						printf("어느 샌가 빛에 가까워지고 있을 때쯤 갑자기 위에서 돌이 쏟아지더니 큰 소리가 들렸다.\n");
						Sleep(2000);
						
						printf("쿠쿵..");
						Sleep(500); 
						
						printf("쿵..");
						Sleep(400);
						
						printf(".....");
						Sleep(3000);
						
						printf("그 소리와 함께 다른 신도들이 무기를 들고 나를 잡으러 찾아왔다.\n");
						Sleep(2000);
						
						printf("그들은 심판대로 잡아가서 불을 지피며 화형을 준비했다.\n");
						Sleep(2000);
						
						printf("그들은 내가 신도라고 믿고 있지만 빛을 보기 위해 구멍을 파던 행위를 신에 대한 저항이라고 생각하였다.\n");
						Sleep(2000);
						
						printf("죽기 전 마지막으로 그들이 나에게 한 말은\n");
						Sleep(1500);
						
						printf("\n[“믿음에대한행위에,의심하지마라”]\n");
						Sleep(2000);
						
						printf("이다.");
						Sleep(1500);
						
						printf("한 번만 기회를 준다면..\n");
						Sleep(1000);
						
						printf("나갈 수 있을탠데..\n");
						Sleep(2500);
						
						printf("DEAD\n\n");
						Sleep(3000);
						
						exit(0);
					}

// === 출력 
					void print_neun() {
						printf("================================================================\n\n\n\n\n\n\n\n\n");
						Sleep(500);
					}
// === 출력 

// 시작 
					void start() {
						printf("제"); Sleep(150);
						printf("작"); Sleep(150);
						printf("자 "); Sleep(750);
						
						printf("김"); Sleep(150);
						printf("학"); Sleep(150);
						printf("성, "); Sleep(1000);
						
						printf("박"); Sleep(200);
						printf("민"); Sleep(200);
						printf("성\n\n"); Sleep(1000);
						
						printf("게임을 새로 실행할 때마다 정답 일부가 랜덤으로 바뀝니다.\n\n"); 
						printf("화면을 클릭하면 게임이 멈춥니다. 그럴 시 [Enter]를 눌러주세요.\n\n\n\n"); 
						Sleep(1000);
						
						print_neun();
						
						printf("나는 신을 믿는 독실한 신자로서 여느 때와 다름 없이 기도를 올리고 있었다.\n\n");
						Sleep(1500);
						
						printf("그러던 중 괴한들이 쳐들어와 사람들을 끌고 가기 시작했고 나도 괴한들에게 잡혀 어딘지도 모르는 곳에 밧줄로 묶여 끌려갔다.\n\n");
						Sleep(1500);
						
						printf("이곳은 매우 감시가 심했으며 그들은 종종 이상한 말을 하여 이곳의 분위기는 매우 음산하다.\n\n");
						Sleep(1500);
						
						printf("사람들이 고통스러워 하는 소리가 여기까지 들리며, 나는 밧줄로 손을 결박 당하고 있었다.\n\n");
						Sleep(1500);
						
						printf("내가 가진 건 나무로 만든 십자가 하나뿐이지만 이곳에서 포기할 수는 없다.\n\n");
						Sleep(1500);
						
						printf("그렇기에 나는 신도들의 눈을 속여 밖으로 나가기로 마음을 먹고\n\n");
						Sleep(1000);
						
						printf("십자가를 꽉 쥐고 기도를 올린 후 정신을 차리고 느슨하게 묶여있던 밧줄을 풀었다.\n\n");
						Sleep(1500);
						
						printf("신도들의 눈을 속여 종교시설에서 탈출하시오\n\n"); 
						Sleep(1000);
						
						print_neun();
					}
// 시작 

// 두 번째 성경 내용 섞기
void rand_str() {
	strcpy(random_str, answer_2);
		
	char a = ' ';
	int i;
	
	for(i=0; i<3; i++) {
		random_str[i] = a; 
	}
	
	

}
// 두 번째 성경 내용 섞기 










