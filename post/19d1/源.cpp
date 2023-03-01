#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<math.h>
#include<ctype.h>
#include<time.h>
#define ma 50
struct kehu {
	char number[ma];//编号
	char name[ma];//姓名
	char passwod[ma];//密码
	char phone[ma];//电话
	char money[ma];//余额
	char age[ma];//年龄
	char sex[ma];//性别
	char dizhi[ma];//地址
	char birth[ma];//出生日期
	char jiguan[ma];//籍贯
	char status[ma];//状态
	kehu* next;
};
struct caozuo {
	char bianhao[ma];//编号
	char date[ma];//日期
	char leibie[ma];//类别
	char caozuoren[ma];//经办人
	caozuo* next;
};
struct admin {
	char name[ma];
	char zhanghao[ma];
	char password[ma];
	char status[ma];
	admin* next;
};
kehu* duqushuju();//录入文件信息
admin* duquadmin();//录入管理员信息
caozuo* duqucaozuo();//录入操作信息
void cunchushuju(kehu*head,caozuo*bhead);//存入信息
void xuanze(kehu *head,admin*ahead,caozuo*bhead);//选择界面
int denglujiemian();//登录界面
kehu* kaihu(kehu *head);//开户
void yonghu(kehu *head);//用户界面
int yonghucaidan();//用户菜单
caozuo* guanliyuan(admin* ahead, caozuo* bhead,kehu*head);//管理员界面
int guanliyuancaidan();//管理员菜单
kehu* zhanghaodenglu(kehu *head);//账号登录
admin* guanliyuandenglu(admin*ahead);//管理员登录
void qukuan(kehu*current);//取款
void cunkuan(kehu*current);//存款
void kehuchaxun(kehu*current);//客户查询余额
void zhuanzhang(kehu* current,kehu*head);//转账功能
void caozuochaxun(caozuo*bhead);//操作查询
caozuo* chaxunzhanghu(kehu*head,caozuo*bhead,admin*ahead);//查询账户
caozuo* dongjiezhanghu(kehu*head,caozuo*bhead,admin*ahead);//冻结账户
caozuo* jiedongzhanghu(kehu* head,caozuo*bhead,admin*ahead);//解冻账户
caozuo* xiaohu(kehu*head,caozuo*bhead,admin*ahead);//销户
char* shijian();//求当前时间

int main() {
	struct kehu* head = duqushuju();
	struct admin* ahead = duquadmin();
	struct caozuo* bhead = duqucaozuo();
	xuanze(head,ahead,bhead);
	return 0;
}
kehu* duqushuju() {//创建链表，读取文件信息，并存入链表
	struct kehu* head = NULL;
	struct kehu* prev = nullptr;
	struct kehu* current = nullptr;
	FILE* fp;
	fp = fopen("客户信息.txt", "r+");
	if (fp == NULL) {
		printf("打开文件失败!");
		exit(0);
	}
	char input[100];
	while (fgets(input, 100, fp) != NULL) {
		char gexiang[ma];
		int  ppp = 0, kai = 0, qqq = 0;
		int len = strlen(input);
		input[len] = '\n';
		for (int i = 0; i <= len; i++) {
			if (input[i] == ' ') {
				strncpy(gexiang, input + kai, i - kai);
				gexiang[i - kai] = '\0';
				kai = i + 1;
				qqq++;
				ppp = qqq;
			}
			if (input[i] == '\n') {
				strncpy(gexiang, input + kai, i - kai);
				gexiang[i - kai] = '\0';
				kai = i + 1;
				qqq++;
				ppp = qqq;
			}
			switch (ppp) {
			case 1:
				current = (struct kehu*)malloc(sizeof(struct kehu));
				if (head == NULL) {
					head = current;
				}
				else {
					prev->next = current;
				}
				current->next = NULL;
				strcpy(current->number, gexiang);
				ppp = 0;
				break;
			case 2:
				strcpy(current->name, gexiang);
				ppp = 0;
				break;
			case 3:
				strcpy(current->passwod, gexiang);
				ppp = 0;
				break;
			case 4:
				strcpy(current->phone, gexiang);
				ppp = 0;
				break;
			case 5:
				strcpy(current->money, gexiang);
				ppp = 0;
				break;
			case 6:
				strcpy(current->age, gexiang);
				ppp = 0;
				break;
			case 7:
				strcpy(current->sex, gexiang);
				ppp = 0;
				break;
			case 8:
				strcpy(current->dizhi, gexiang);
				ppp = 0;
				break;
			case 9:
				strcpy(current->birth, gexiang);
				ppp = 0;
				break;
			case 10:
				strcpy(current->jiguan, gexiang);
				ppp = 0;
				break;
			case 11:
				strcpy(current->status, gexiang);
				ppp = 0;
				prev = current;
				break;
			default:
				break;
			}
		}
	}
	if (fclose(fp) != NULL) {
		exit(0);
	}
	return head;//返回链表的头结点地址
}
admin* duquadmin() {
	struct admin* ahead = NULL;
	struct admin* current=nullptr, * prev = nullptr;
	FILE* fp = fopen("管理员信息.txt", "r+");
	if (fp == NULL) {
		printf("打开文件失败!");
		exit(0);
	}
	char input[100];
	while (fgets(input, 100, fp) != NULL) {
		char gexiang[ma];
		int  ppp = 0, kai = 0, qqq = 0;
		int len = strlen(input);
		input[len] = '\n';
		for (int i = 0; i <= len; i++) {
			if (input[i] == ' ') {
				strncpy(gexiang, input + kai, i - kai);
				gexiang[i - kai] = '\0';
				kai = i + 1;
				qqq++;
				ppp = qqq;
			}
			if (input[i] == '\n') {
				strncpy(gexiang, input + kai, i - kai);
				gexiang[i - kai] = '\0';
				kai = i + 1;
				qqq++;
				ppp = qqq;
			}
			switch (ppp) {
			case 1:
				current = (struct admin*)malloc(sizeof(struct admin));
				if (ahead == NULL) {
					ahead = current;
				}
				else {
					prev->next = current;
				}
				current->next = NULL;
				strcpy(current->name, gexiang);
				ppp = 0;
				break;
			case 2:
				strcpy(current->zhanghao, gexiang);
				ppp = 0;
				break;
			case 3:
				strcpy(current->password, gexiang);
				ppp = 0;
				break;
			case 4:
				strcpy(current->status, gexiang);
				ppp = 0;
				prev = current;
				break;
			default:
				break;
			}
		}
	}
	if (fclose(fp) != NULL) {
		exit(0);
	}
	return ahead;
}
caozuo* duqucaozuo() {
	struct caozuo* bhead = NULL;
	struct caozuo* current = nullptr, * prev = nullptr;
	FILE* fp = fopen("操作记录.txt", "r+");
	if (fp == NULL) {
		printf("打开文件失败!");
		exit(0);
	}
	char input[100];
	while (fgets(input, 100, fp) != NULL) {
		char gexiang[ma];
		int  ppp = 0, kai = 0, qqq = 0,tem=0;
		int len = strlen(input);
		input[len] = '\n';
		for (int i = 0; i <= len; i++) {
			if (qqq == 1) {
				if (input[i] == ' ') {
					if (tem==4) {
						strncpy(gexiang, input + kai, i - kai);
						gexiang[i - kai] = '\0';
						kai = i + 1;
						qqq++;
						ppp = qqq;
					}
					else {
						tem++;
					}
				}
			}
			else {
				if (input[i] == ' ') {
					strncpy(gexiang, input + kai, i - kai);
					gexiang[i - kai] = '\0';
					kai = i + 1;
					qqq++;
					ppp = qqq;
				}
				if (input[i] == '\n') {
					strncpy(gexiang, input + kai, i - kai);
					gexiang[i - kai] = '\0';
					kai = i + 1;
					qqq++;
					ppp = qqq;
				}
			}
			switch (ppp) {
			case 1:
				current = (struct caozuo*)malloc(sizeof(struct caozuo));
				if (bhead == NULL) {
					bhead = current;
				}
				else {
					prev->next = current;
				}
				current->next = NULL;
				strcpy(current->bianhao, gexiang);
				ppp = 0;
				break;
			case 2:
				strcpy(current->date, gexiang);
				ppp = 0;
				break;
			case 3:
				strcpy(current->leibie, gexiang);
				ppp = 0;
				break;
			case 4:
				strcpy(current->caozuoren, gexiang);
				ppp = 0;
				prev = current;
				break;
			default:
				break;
			}
		}
	}
	if (fclose(fp) != NULL) {
		exit(0);
	}
	return bhead;
}
void cunchushuju(kehu* head, caozuo* bhead) {
	struct kehu* current = head;
	FILE* fp = fopen("客户信息.txt", "w");
	if (fp == NULL) {
		printf("打开文件失败！");
		exit(0);
	}
	while (current != NULL) {
		fprintf(fp, "%s %s %s %s %s %s %s %s %s %s %s\n", current->number, current->name, current->passwod, current->phone, current->money, current->age, current->sex, current->dizhi, current->birth, current->jiguan, current->status);
		current = current->next;
	}
	if (fclose(fp) != NULL) {
		printf("关闭文件失败!");
		exit(0);
	}
	struct caozuo* now = bhead;
	FILE* op = fopen("操作记录.txt", "w");
	if (op == NULL) {
		printf("打开文件失败！");
		exit(0);
	}
	while (now != NULL) {
		fprintf(op, "%s %s %s %s\n", now->bianhao, now->date, now->leibie, now->caozuoren);
		now = now->next;
	}
	if (fclose(op) != NULL) {
		printf("关闭文件失败!");
		exit(0);
	}
	return;
}
void xuanze(kehu *head,admin*ahead,caozuo*bhead) {
	struct kehu* tem = head;
	struct kehu* current = head;
	struct caozuo* now = bhead;
	int chose = 0;
	do {
		chose = denglujiemian();
		switch (chose)
		{
		case 1:
			if (tem == NULL) {
				tem = kaihu(head);
				head = tem;
			}
			else {
				current = tem;
				while (current->next != NULL) {
					current = current->next;
				}
				current->next = kaihu(head);
			}
			break;
		case 2:
			yonghu(head);
			break;
		case 3:
			now= guanliyuan(ahead, bhead, head);
			break;
		default:
			break;
		}
	} while (chose);
	if (!chose) {
		cunchushuju(tem, now);
		printf("感谢您的使用！\n");
		printf("欢迎下次光临！\n");
		return;
	}
}
int denglujiemian() {
	int flag = 0;
	while (true) {
		system("cls");
		printf("====================================================\n");
		printf("++                                                ++\n");
		printf("++                                                ++\n");
		printf("++          欢迎使用银行账户信息管理系统          ++\n");
		printf("++                                                ++\n");
		printf("++                    1:开户                      ++\n");
		printf("++                                                ++\n");
		printf("++                  2:账户登录                    ++\n");
		printf("++                                                ++\n");
		printf("++                 3:管理员登录                   ++\n");
		printf("++                                                ++\n");
		printf("++                    0:退出                      ++\n");
		printf("++                                                ++\n");
		printf("++                                                ++\n");
		printf("====================================================\n");
		printf("             请输入你想进行的操作的号码：");
		scanf("%d", &flag);
		if (0 <= flag && flag <= 3) {
			break;
		}
		else {
			printf("抱歉，您的输入有误，请参照界面输入号码！\n");
			getchar();
			getchar();
		}
	}
	return flag;
}
kehu* kaihu(kehu* head) {//开户
	system("cls");
	struct kehu* current = head, * prev = nullptr;
	while (current != NULL) {//找到最后一个节点
		prev = current;
		current = current->next;
	}
	current = (struct kehu*)malloc(sizeof(struct kehu));//申请空间
	current->next = NULL;
	for (int i = 1; i <= 11; i++) {//增加新的信息
		char input[ma];
		if (i == 1) {//新增编号
			if (prev == NULL) {
				int bian = 1111;
				itoa(bian, input, 10);
				strcpy(current->number, input);
			}
			else {
				int bian = atoi(prev->number);//将编号变为整型。
				bian++;//再加一变为新的编号。
				itoa(bian, input, 10);//再将其变为字符串
				strcpy(current->number, input);//最后复制回去
			}
		}
		else if (i == 2) {
			printf("请输入您的姓名：");
			scanf("%s", input);
			strcpy(current->name, input);
		}
		else if (i == 3) {
			printf("请输入您的密码：");
			scanf("%s", input);
			strcpy(current->passwod, input);
		}
		else if (i == 4) {
			printf("请输入您的电话号码：");
			scanf("%s", input);
			strcpy(current->phone, input);
		}
		else if (i == 5) {
			double yue = 0.00;
			sprintf(input, "%.2lf", yue);
			strcpy(current->money, input);
		}
		else if (i == 6) {
			printf("请输入您的年龄：");
			scanf("%s", input);
			strcpy(current->age, input);
		}
		else if (i == 7) {
			printf("请输入您的性别：");
			scanf("%s", input);
			strcpy(current->sex, input);
		}
		else if (i == 8) {
			printf("请输入您的家庭地址：");
			scanf("%s", input);
			strcpy(current->dizhi, input);
		}
		else if (i == 9) {
			printf("请输入您的出生日期：");
			scanf("%s", input);
			strcpy(current->birth, input);
		}
		else if (i == 10) {
			printf("请输入您的籍贯：");
			scanf("%s", input);
			strcpy(current->jiguan, input);
		}
		else if (i == 11) {
			strcpy(current->status, "正常");
			break;
		}
	}
	current->next = NULL;
	printf("恭喜您！开户成功！\n");
	printf("您的账号为：%s   请您牢记账号与密码！", current->number);
	getchar();
	getchar();
	return current;//返回新结点地址，增加结点。
}
void yonghu(kehu *head) {
	struct kehu* current = zhanghaodenglu(head);
	if (current!=NULL) {	
		int chose = 0;
		do {
			chose = yonghucaidan();
			switch (chose)
			{
			case 1:
				kehuchaxun(current);
				break;
			case 2:
				qukuan(current);
				break;
			case 3:
				cunkuan(current);
				break;
			case 4:
				zhuanzhang(current,head);
				break;
			default:
				break;
			}
		} while (chose);
	}
	return;
}
kehu* zhanghaodenglu(kehu*head) {
	system("cls");
	struct kehu* current = head;
	char input[ma],shuru[ma];
	bool find = false;
	printf("请您输入您的账号：");
	scanf("%s", input);
	while (current != NULL) {
		if (strcmp(current->number, input) == 0&&strcmp("正常", current->status)==0) {
			find = true;
			break;
		}
		else if(strcmp(current->number, input) == 0 && strcmp("正常", current->status) != 0){
			printf("抱歉，您的账号已被冻结！若有问题请向相关人员寻求帮助！");
			getchar();
			getchar();
			return NULL;
		}
		else {
			current = current->next;
		}
	}
	if (!find) {
		printf("抱歉！您的账号不存在。");
		getchar();
		getchar();
	}
	else {
		for (int i = 1; i <= 5; i++) {
			system("cls");
			printf("请您输入密码：");
			scanf("%s", shuru);
			if (strcmp(shuru, current->passwod)==0) {
				printf("密码正确！登陆成功！");
				getchar();
				getchar();
				return current;
			}
			else {
				printf("您的密码错误！请您从新输入！\n");
				printf("您已输入错误%d次，还有%d次机会！若次数用完仍然错误，您的账号将被冻结！", i, 5 - i);
				getchar();
				getchar();
			}
			if (i == 5) {
				printf("登录失败！该账号已被冻结！如果遗忘密码，请联系相关人员进行修改与找回！");
				strcpy(current->status, "冻结");
				getchar();
				getchar();
				return NULL;
			}
		}

	}
	return NULL;
}
int yonghucaidan() {
	int flag = 0;
	while (true) {
		system("cls");
		printf("====================================================\n");
		printf("++                                                ++\n");
		printf("++                                                ++\n");
		printf("++             尊敬的客户欢迎您的使用             ++\n");
		printf("++                                                ++\n");
		printf("++                  1:查询余额                    ++\n");
		printf("++                                                ++\n");
		printf("++                    2:取款                      ++\n");
		printf("++                                                ++\n");
		printf("++                    3:存款                      ++\n");
		printf("++                                                ++\n");
		printf("++                    4:转账                      ++\n");
		printf("++                                                ++\n");
		printf("++                    0:退出                      ++\n");
		printf("++                                                ++\n");
		printf("++                                                ++\n");
		printf("====================================================\n");
		printf("             请输入你想进行的操作的号码：");
		scanf("%d", &flag);
		if (0 <= flag && flag <= 4) {
			break;
		}
		else {
			printf("抱歉，您的输入有误，请参照界面输入号码！\n");
			getchar();
			getchar();
		}
	}
	return flag;
}
void kehuchaxun(kehu*current) {
	system("cls");
	printf("当前您的余额为；%s",current->money);
	getchar();
	getchar();
	return;
}
void qukuan(kehu*current) {
	system("cls");
	double yue = atof(current->money);
	double qu = 0;
	char input[ma];
	printf("请输入取款数目：");
	scanf("%lf", &qu);
	if (qu > yue) {
		printf("余额不足！无法取款！");
		getchar();
		getchar();
	}
	else {
		yue -= qu;
		sprintf(input, "%.2lf", yue);
		strcpy(current->money, input);
		printf("恭喜您！取款成功！");
		getchar();
		getchar();
	}
	return;
}
void cunkuan(kehu*current) {
	system("cls");
	double yue = atof(current->money);
	double cun = 0;
	char input[ma];
	printf("请输入存款数目：");
	scanf("%lf", &cun);
	yue += cun;
	sprintf(input, "%.2lf", yue);
	strcpy(current->money, input);
	printf("恭喜您！存款成功！");
	getchar();
	getchar();
	return;
}
void zhuanzhang(kehu* current,kehu*head) {
	system("cls");
	struct kehu* now=head;
	char input[ma], shuru[ma];
	bool find = false;
	printf("请您输入您想转入的账号：");
	scanf("%s", input);
	while (now != NULL) {
		if (strcmp(now->number, input) == 0 && strcmp("正常", now->status) == 0) {
			find = true;
			break;
		}
		else if (strcmp(current->number, input) == 0 && strcmp("正常", now->status) != 0) {
			printf("抱歉，您的账号已被冻结！若有问题请向相关人员寻求帮助！");
			getchar();
			getchar();
		}
		else {
			now = now->next;
		}
	}
	if (!find) {
		printf("抱歉！您的账号不存在。");
		getchar();
		getchar();
	}
	else {
		double yue = atof(current->money);
		double yuee = atof(now->money);
		double qu = 0;
		char innput[ma],shu[ma];
		printf("请输入取款数目：");
		scanf("%lf", &qu);
		if (qu > yue) {
			printf("余额不足！无法转账！");
			getchar();
			getchar();
		}
		else {
			int ok = 0;
			printf("在此提醒您转账有风险！谨防上当受骗！\n");
			printf("\'是\'则输入1，\'否\'则输入0。\n");
			scanf("%d", &ok);
			if (ok) {
				yue -= qu;
				yuee += qu;
				sprintf(shu, "%.2lf", yuee);
				sprintf(innput, "%.2lf", yue);
				strcpy(current->money, innput);
				strcpy(now->money, shu);
				printf("恭喜您！转账成功！");
				getchar();
				getchar();
			}
			else {
				getchar();
				return;
			}
		}
	}
	return;
}
caozuo* guanliyuan(admin*ahead,caozuo*bhead,kehu*head) {
	int chose;
	struct admin* current = guanliyuandenglu(ahead);
	struct caozuo* tem = bhead;
	struct caozuo* now = NULL;
	if (current!=NULL) {
		do {
			chose = guanliyuancaidan();
			switch (chose)
			{
			case 1:
				caozuochaxun(tem);
				break;
			case 2:
				if (tem == NULL) {
					tem = chaxunzhanghu(head, bhead, current);
					bhead = now;
				}
				else {
					now = tem;
					while (now->next != NULL) {
						now = now->next;
					}
					now->next = chaxunzhanghu(head, bhead, current);
				}
				break;
			case 3:
				if (tem == NULL) {
					tem = dongjiezhanghu(head, bhead, current);
					bhead = now;
				}
				else {
					now = tem;
					while (now->next != NULL) {
						now = now->next;
					}
					now->next = dongjiezhanghu(head, bhead, current);
				}
				break;
			case 4:
				if (tem == NULL) {
					tem = jiedongzhanghu(head, bhead, current);
					bhead = now;
				}
				else {
					now = tem;
					while (now->next != NULL) {
						now = now->next;
					}
					now->next = jiedongzhanghu(head, bhead, current);
				}
				break;
			case 5:
				if (tem == NULL) {
					tem = xiaohu(head, bhead, current);
					bhead = now;
				}
				else {
					now = tem;
					while (now->next != NULL) {
						now = now->next;
					}
					now->next = xiaohu(head, bhead, current);
				}
				break;
			default:
				break;
			}
		} while (chose);
	}
	return tem;
}
admin* guanliyuandenglu(admin*ahead) {
	system("cls");
	struct admin* current = ahead;
	char input[ma], shuru[ma];
	bool find = false;
	printf("请您输入您的账号：");
	scanf("%s", input);
	while (current != NULL) {
		if (strcmp(current->zhanghao, input) == 0 && strcmp("正常", current->status) == 0) {
			find = true;
			break;
		}
		else if (strcmp(current->zhanghao, input) == 0 && strcmp("正常", current->status) != 0) {
			printf("抱歉，您的账号已被冻结！若有问题请向相关人员寻求帮助！");
			getchar();
			getchar();
			return NULL;
		}
		else {
			current = current->next;
		}
	}
	if (!find) {
		printf("抱歉！您的账号不存在。");
		getchar();
		getchar();
	}
	else {
		for (int i = 1; i <= 5; i++) {
			system("cls");
			printf("请您输入密码：");
			scanf("%s", shuru);
			if (strcmp(shuru, current->password) == 0) {
				printf("密码正确！登陆成功！");
				getchar();
				getchar();
				return current;
			}
			else {
				printf("您的密码错误！请您从新输入！\n");
				printf("您已输入错误%d次，还有%d次机会！若次数用完仍然错误，您的账号将被冻结！", i, 5 - i);
				getchar();
				getchar();
			}
			if (i == 5) {
				printf("登录失败！该账号已被冻结！如果遗忘密码，请联系相关人员进行修改与找回！");
				strcpy(current->status, "冻结");
				getchar();
				getchar();
				return NULL;
			}
		}

	}
	return NULL;
}
int guanliyuancaidan() {
	int flag = 0;
	while (true) {
		system("cls");
		printf("====================================================\n");
		printf("++                                                ++\n");
		printf("++                                                ++\n");
		printf("++           尊敬的管理员欢迎您的使用             ++\n");
		printf("++                                                ++\n");
		printf("++                  1:操作查询                    ++\n");
		printf("++                                                ++\n");
		printf("++                  2:账户查询                    ++\n");
		printf("++                                                ++\n");
		printf("++                  3:冻结账户                    ++\n");
		printf("++                                                ++\n");
		printf("++                  4:解冻账户                    ++\n");
		printf("++                                                ++\n");
		printf("++                    5:销户                      ++\n");
		printf("++                                                ++\n");
		printf("++                    0:退出                      ++\n");
		printf("++                                                ++\n");
		printf("++                                                ++\n");
		printf("====================================================\n");
		printf("             请输入你想进行的操作的号码：");
		scanf("%d", &flag);
		if (0 <= flag && flag <= 5) {
			break;
		}
		else {
			printf("抱歉，您的输入有误，请参照界面输入号码！\n");
			getchar();
			getchar();
		}
	}
	return flag;
}
void caozuochaxun(caozuo* bhead){
	system("cls");
	struct caozuo* current = bhead;
	char input[ma];
	bool find = false;
	printf("请您输入要查询操作的账号：");
	scanf("%s", input);
	while (current != NULL) {
		if (strcmp(current->bianhao, input) == 0) {
			find = true;
			break;
		}
		else {
			current = current->next;
		}
	}
	if (!find) {
		printf("抱歉！并未查询到该账号的任何操作记录！");
		getchar();
		getchar();
		return;
	}
	else {
		printf("账号                    日期                         类别                      经办人\n");
		while (current != NULL) {
			if (strcmp(current->bianhao, input) == 0) {
				printf("%s            %s               %s                     %s\n",current->bianhao,current->date,current->leibie,current->caozuoren);
				current = current->next;
			}
			else {
				current = current->next;
			}
		}
		getchar();
		getchar();
		return;
	}
}
caozuo* chaxunzhanghu(kehu* head,caozuo*bhead,admin*ahead){
	system("cls");
	struct kehu* current = head;
	char input[ma];
	bool find = false;
	printf("请您输入要查询信息的账户的账号：");
	scanf("%s", input);
	while (current != NULL) {
		if (strcmp(current->number, input) == 0) {
			find = true;
			break;
		}
		else {
			current = current->next;
		}
	}
	if (!find) {
		printf("抱歉！并未查询到该账号！");
		getchar();
		getchar();
		return NULL;
	}
	else {
		printf("账号       姓名       电话      余额       年龄       性别       住址       出身日期       籍贯       状态\n");
		printf("%s     %s     %s     %s     %s     %s     %s     %s     %s     %s\n", current->number, current->name, current->phone, current->money, current->age, current->sex, current->dizhi, current->birth, current->jiguan, current->status);
		getchar();
		getchar();
	}
	char* timep = shijian();
	char timeq[ma];
	strcpy(timeq, timep);
	int len = strlen(timeq);
	timeq[len-1] = '\0';
	struct caozuo* now = bhead;
	while (now != NULL) {
		now = now->next;
	}
	now = (struct caozuo*)malloc(sizeof(struct caozuo));
	now->next = NULL;
	strcpy(now->bianhao, current->number);
	strcpy(now->date, timeq);
	strcpy(now->leibie, "查询");
	strcpy(now->caozuoren, ahead->name);
	return now;
}
caozuo*dongjiezhanghu(kehu* head,caozuo*bhead,admin*ahead){
	system("cls");
	struct kehu* current = head;
	char input[ma];
	bool find = false;
	printf("请您输入要冻结的账号：");
	scanf("%s", input);
	while (current != NULL) {
		if (strcmp(current->number, input) == 0) {
			find = true;
			break;
		}
		else {
			current = current->next;
		}
	}
	if (!find) {
		printf("抱歉！并未查询到该账号！");
		getchar();
		getchar();
		return NULL;
	}
	else {
		if (strcmp(current->status, "冻结") == 0) {
			printf("此账户已被冻结！");
			getchar();
			getchar();
			return NULL;
		}
		else {
			int ok = 0;
			printf("是否确定冻结此账户？\n");
			printf("\'是\'则输入1，\'否\'则输入0。\n");
			scanf("%d", &ok);
			if (ok) {
				strcpy(current->status, "冻结");
				printf("冻结成功！");
				getchar();
				getchar();
			}
			else {
				return NULL;
			}
		}
	}
	char* timep = shijian();
	char timeq[ma];
	strcpy(timeq, timep);
	int len = strlen(timeq);
	timeq[len - 1] = '\0';
	struct caozuo* now = bhead;
	while (now != NULL) {
		now = now->next;
	}
	now = (struct caozuo*)malloc(sizeof(struct caozuo));
	now->next = NULL;
	strcpy(now->bianhao, current->number);
	strcpy(now->date, timeq);
	strcpy(now->leibie, "冻结");
	strcpy(now->caozuoren, ahead->name);
	return now;
}
caozuo* jiedongzhanghu(kehu* head,caozuo*bhead,admin*ahead) {
	system("cls");
	struct kehu* current = head;
	char input[ma];
	bool find = false;
	printf("请您输入要解冻的账号：");
	scanf("%s", input);
	while (current != NULL) {
		if (strcmp(current->number, input) == 0) {
			find = true;
			break;
		}
		else {
			current = current->next;
		}
	}
	if (!find) {
		printf("抱歉！并未查询到该账号！");
		getchar();
		getchar();
		return NULL;
	}
	else {
		if (strcmp(current->status, "冻结") != 0) {
			printf("此账户并未冻结！");
			getchar();
			getchar();
			return NULL;
		}
		else {
			int ok = 0;
			printf("是否确定解冻此账户？\n");
			printf("\'是\'则输入1，\'否\'则输入0。\n");
			scanf("%d", &ok);
			if (ok) {
				strcpy(current->status, "正常");
				printf("解冻成功！");
				getchar();
				getchar();
			}
			else {
				return NULL;
			}
		}
	}
	char* timep = shijian();
	char timeq[ma];
	strcpy(timeq, timep);
	int len = strlen(timeq);
	timeq[len - 1] = '\0';
	struct caozuo* now = bhead;
	while (now != NULL) {
		now = now->next;
	}
	now = (struct caozuo*)malloc(sizeof(struct caozuo));
	now->next = NULL;
	strcpy(now->bianhao, current->number);
	strcpy(now->date, timeq);
	strcpy(now->leibie, "解冻");
	strcpy(now->caozuoren, ahead->name);
	return now;
}
caozuo* xiaohu(kehu* head,caozuo*bhead,admin*ahead) {
	system("cls");
	struct kehu* current = head;
	struct kehu* prev = nullptr;
	char input[ma];
	bool find = false;
	printf("请您输入要进行销户操作的账号：");
	scanf("%s", input);
	while (current != NULL) {
		if (strcmp(current->number, input) == 0) {
			find = true;
			break;
		}
		else {
			prev = current;
			current = current->next;
		}
	}
	if (!find) {
		printf("抱歉！并未查询到该账号！");
		getchar();
		getchar();
		return NULL;
	}
	else {
		int ok = 0;
		printf("是否确定消除此账户？\n");
		printf("\'是\'则输入1，\'否\'则输入0。\n");
		scanf("%d", &ok);
		if (ok) {
			double yue = atof(current->money);
			if (yue != 0) {
				printf("抱歉，账户余额不为0元，无法进行销户！\n");
				printf("请让户主将余额全部取出后再进行销户！\n");
				getchar();
				getchar();
				return NULL;
			}
			else {
				if (prev != NULL) {
					prev->next = current->next;
					free(current);
				}
				else {
					char tem[ma];
					char temp[ma];
					for (int i = 1; i <= 11; i++) {
						if (i == 1) {
							strcpy(tem, current->number);
							strcpy(temp, current->next->number);
							strcpy(current->number, temp);
							strcpy(current->next->number, tem);
						}
						if (i == 2) {
							strcpy(tem, current->name);
							strcpy(temp, current->next->name);
							strcpy(current->name, temp);
							strcpy(current->next->name, tem);
						}
						if (i == 3) {
							strcpy(tem, current->passwod);
							strcpy(temp, current->next->passwod);
							strcpy(current->passwod, temp);
							strcpy(current->next->passwod, tem);
						}
						if (i == 4) {
							strcpy(tem, current->phone);
							strcpy(temp, current->next->phone);
							strcpy(current->phone, temp);
							strcpy(current->next->phone, tem);
						}
						if (i == 5) {
							strcpy(tem, current->money);
							strcpy(temp, current->next->money);
							strcpy(current->money, temp);
							strcpy(current->next->money, tem);
						}
						if (i == 6) {
							strcpy(tem, current->age);
							strcpy(temp, current->next->age);
							strcpy(current->age, temp);
							strcpy(current->next->age, tem);
						}
						if (i == 7) {
							strcpy(tem, current->sex);
							strcpy(temp, current->next->sex);
							strcpy(current->sex, temp);
							strcpy(current->next->sex, tem);
						}
						if (i == 8) {
							strcpy(tem, current->dizhi);
							strcpy(temp, current->next->dizhi);
							strcpy(current->dizhi, temp);
							strcpy(current->next->dizhi, tem);
						}
						if (i == 9) {
							strcpy(tem, current->birth);
							strcpy(temp, current->next->birth);
							strcpy(current->birth, temp);
							strcpy(current->next->birth, tem);
						}
						if (i == 10) {
							strcpy(tem, current->jiguan);
							strcpy(temp, current->next->jiguan);
							strcpy(current->jiguan, temp);
							strcpy(current->next->jiguan, tem);
						}
						if (i == 11) {
							strcpy(tem, current->status);
							strcpy(temp, current->next->status);
							strcpy(current->status, temp);
							strcpy(current->next->status, tem);
						}
					}
					prev = current;
					current = current->next;
					prev->next = current->next;
					free(current);
				}
				printf("恭喜你销户成功！");
				getchar();
				getchar();
			}
		}
		else {
			return NULL;
		}
	}
	char* timep = shijian();
	char timeq[ma];
	strcpy(timeq, timep);
	int len = strlen(timeq);
	timeq[len - 1] = '\0';
	struct caozuo* now = bhead;
	while (now != NULL) {
		now = now->next;
	}
	now = (struct caozuo*)malloc(sizeof(struct caozuo));
	now->next = NULL;
	strcpy(now->bianhao, input);
	strcpy(now->date, timeq);
	strcpy(now->leibie, "销户");
	strcpy(now->caozuoren, ahead->name);
	return now;
}
char* shijian() {
	time_t timep;
	struct tm* p;
	time(&timep);
	p = localtime(&timep);
	return asctime(p);
}
